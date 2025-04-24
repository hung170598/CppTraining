#include <fcntl.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#if defined(_WIN32) || defined(_WIN64)
#include <io.h>
#endif

#define MAX 100
#define MAX_LINE 256
#define INPUT_FILE "data/members.txt"
#define OUTPUT_FILE "data3/members_out.txt"

typedef struct {
  wchar_t name[100];
  int birthYear;
  wchar_t major[100];
  wchar_t phone[20];
  wchar_t spoj[50];
} Member;

void _fgetws(wchar_t *str, int size, FILE *stream) {
  char c;
  fgetws(str, size, stream);
  size_t len = wcslen(str);
  if (len > 0 && str[len - 1] == L'\n') {
    str[len - 1] = L'\0';
  } else {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
  }
}

int readFromFile(const char *filename, Member members[]) {
  FILE *fp = fopen(filename, "r, ccs=UTF-8");
  if (!fp) {
    wprintf(L"Không thể đọc file %hs\n", filename);
    return 0;
  }

  wchar_t line[MAX_LINE];
  int count = 0;

  while (fgetws(line, sizeof(line) / sizeof(wchar_t), fp)) {
    size_t len = wcslen(line);
    if (wcslen(line) == 0)
      continue;
    if (line[len - 1] == L'\n')
      line[len - 1] = L'\0';
    if (line[len - 2] == L'\r')
      line[len - 2] = L'\0';

    wchar_t *saveptr;                              // State pointer for wcstok
    wchar_t *token = wcstok(line, L"#", &saveptr); // First token
    if (token != NULL)
      wcscpy(members[count].name, token);

    token = wcstok(NULL, L"#", &saveptr);
    if (token != NULL)
      members[count].birthYear = wcstol(token, NULL, 10);

    token = wcstok(NULL, L"#", &saveptr);
    if (token != NULL)
      wcscpy(members[count].major, token);

    token = wcstok(NULL, L"#", &saveptr);
    if (token != NULL)
      wcscpy(members[count].phone, token);

    token = wcstok(NULL, L"#", &saveptr);
    if (token != NULL)
      wcscpy(members[count].spoj, token);

    count++;
  }
  fclose(fp);
  return count;
}

void saveToFile(const char *filename, Member members[], int count) {
  FILE *fp = fopen(filename, "w, ccs=UTF-8");
  if (!fp) {
    wprintf(L"Không thể ghi file %hs\n", filename);
    return;
  }
  for (int i = 0; i < count; i++) {
    fwprintf(fp, L"%ls#%d#%ls#%ls#%ls\n", members[i].name, members[i].birthYear,
             members[i].major, members[i].phone, members[i].spoj);
  }
  fflush(fp);
  fclose(fp);
  wprintf(L"Đã lưu dữ liệu thành công vào '%hs'\n", filename);
}

void printMembers(Member members[], int count) {
  wprintf(L"\n=== Danh sách thành viên ===\n");
  wprintf(
      L"-----------------------------------------------------------------------"
      L"--------------------------\n");
  wprintf(L"| %-16ls | %-8ls | %-33ls | %-10ls | %-15ls|\n", L"Họ và tên",
          L"Năm sinh", L"Chuyên ngành", L"Điện thoại", L"SPOJ");
  wprintf(
      L"|----------------------------------------------------------------------"
      L"-------------------------|\n");
  for (int i = 0; i < count; i++) {
    wprintf(L"| %-16ls |   %-4d   | %-33ls | %-10ls | %-15ls|\n",
            members[i].name, members[i].birthYear, members[i].major,
            members[i].phone, members[i].spoj);
  }
  wprintf(
      L"-----------------------------------------------------------------------"
      L"--------------------------\n");
  wprintf(L"Tổng số thành viên: %d\n", count);
}

bool ascending(int a, int b) { return a > b; }
bool descending(int a, int b) { return a < b; }
typedef bool (*CompareFunc)(int, int);

void sortMembers(Member members[], int count, CompareFunc cmp) {
  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (cmp(members[i].birthYear, members[j].birthYear)) {
        Member temp = members[i];
        members[i] = members[j];
        members[j] = temp;
      }
    }
  }
}

void findByName(Member members[], int count, const wchar_t *name) {
  int found = 0;
  int res[count];
  for (int i = 0; i < count; i++) {
    if (wcsstr(members[i].name, name)) {
      res[found] = i;
      found++;
    }
  }
  if (found == 0) {
    wprintf(L"Không tìm thấy kết quả cho '%ls'\n", name);
    return;
  }
  wprintf(L"\nKết quả tìm kiếm cho '%ls':\n", name);
  wprintf(
      L"-----------------------------------------------------------------------"
      L"--------------------------\n");
  wprintf(L"| %-16ls | %-8ls | %-33ls | %-10ls | %-15ls|\n", L"Họ và tên",
          L"Năm sinh", L"Chuyên ngành", L"Điện thoại", L"SPOJ");
  wprintf(
      L"|----------------------------------------------------------------------"
      L"-------------------------|\n");
  for (int i = 0; i < found; i++) {
    wprintf(L"| %-16ls |   %-4d   | %-33ls | %-10ls | %-15ls|\n",
            members[res[i]].name, members[res[i]].birthYear,
            members[res[i]].major, members[res[i]].phone, members[res[i]].spoj);
  }
  wprintf(
      L"-----------------------------------------------------------------------"
      L"--------------------------\n");
  wprintf(L"Count = %d\n", found);
}

void addMember(Member members[], int count) {
  if (count >= MAX) {
    wprintf(L"Danh sách đầy, không thể thêm thành viên mới.\n");
    return;
  }

  wprintf(L"Nhập họ tên: ");
  _fgetws(members[count].name, sizeof(members[count].name) / sizeof(wchar_t),
          stdin);

  wprintf(L"Nhập năm sinh: ");
  wchar_t birthYearStr[10];
  _fgetws(birthYearStr, sizeof(birthYearStr) / sizeof(wchar_t), stdin);
  members[count].birthYear = wcstol(birthYearStr, NULL, 10);
  getchar();

  wprintf(L"Nhập chuyên ngành: ");
  _fgetws(members[count].major, sizeof(members[count].major) / sizeof(wchar_t),
          stdin);

  wprintf(L"Nhập số điện thoại: ");
  _fgetws(members[count].phone, sizeof(members[count].phone) / sizeof(wchar_t),
          stdin);

  wprintf(L"Nhập tên tài khoản SPOJ: ");
  _fgetws(members[count].spoj, sizeof(members[count].spoj) / sizeof(wchar_t),
          stdin);
  wprintf(L"Đã thêm thành viên thành công!\n");
}

int main() {
#if defined(_WIN32) || defined(_WIN64)
  _setmode(_fileno(stdout), _O_U8TEXT);
  _setmode(_fileno(stdin), _O_U16TEXT);
#else
  setlocale(LC_ALL, "");
#endif
  Member members[MAX];
  int count = 0;
  wchar_t choice[5];
  int option;

  count = readFromFile(INPUT_FILE, members);
  printMembers(members, count);

  while (1) {
    wprintf(L"\n========== MENU ==========");
    wprintf(L"\n1. In danh sách thành viên");
    wprintf(L"\n2. Sắp xếp theo năm sinh (tăng dần)");
    wprintf(L"\n3. Sắp xếp theo năm sinh (giảm dần)");
    wprintf(L"\n4. Tìm kiếm theo tên");
    wprintf(L"\n5. Thêm thành viên mới");
    wprintf(L"\n6. Lưu danh sách ra file\n");
    while (1) {
      wprintf(L"Chọn: ");

      _fgetws(choice, sizeof(choice) / sizeof(wchar_t), stdin);
      if (choice[0] == L'\0') {
        printf("\r");
        continue;
      }

      if (choice[1] != L'\0') {
        wprintf(L"Lựa chọn không hợp lệ. Thoát chương trình.\n");
        return 0;
      }
      break;
    }

    option = choice[0] - L'0';

    switch (option) {
    case 1:
      printMembers(members, count);
      break;
    case 2:
      sortMembers(members, count, ascending);
      wprintf(L"\n=== Danh sách sau khi sắp xếp (tăng dần) ===\n");
      printMembers(members, count);
      break;
    case 3:
      sortMembers(members, count, descending);
      wprintf(L"\n=== Danh sách sau khi sắp xếp (giảm dần) ===\n");
      printMembers(members, count);
      break;
    case 4: {
      wchar_t searchName[100];
      wprintf(L"Nhập tên để tìm kiếm: ");
      _fgetws(searchName, sizeof(searchName) / sizeof(wchar_t), stdin);
      findByName(members, count, searchName);
      break;
    }
    case 5:
      addMember(members, count);
      count++;
      break;
    case 6:
      saveToFile(OUTPUT_FILE, members, count);
      break;
    default:
      wprintf(L"Lựa chọn không hợp lệ. Thoát chương trình.\n");
      return 0;
    }
    choice[0] = L'\0';
  }

  return 0;
}
