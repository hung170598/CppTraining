#include <iostream>
using namespace std;

/* Prototype */
void Normal_Array(const int array[],const int size_array);
void Pointer_Array(const int *array,const int size_array);
void DynamicPointer();
void Quick_Sort(int array[], int low, int high, int(*f_SapXep)(const int &value_array,const int &midNumber));
int Partition(int array[],int low, int high, int(*f_SapXep)(const int &value_array,const int &midNumber));
int Tang_dan(const int &value_array,const int &midNumber);
int Giam_dan(const int &value_array,const int &midNumber);

int main(){
    int array[8] = {1,5,7,9,3,4,7,8};
    int size_array = sizeof(array)/sizeof(array[0]);

    /* In mảng bình thường */
    Normal_Array(array,size_array);

    /* In mảng bằng con trỏ */
    Pointer_Array(array,size_array);

    /* Thực hiện mảng 2 chiều */
    DynamicPointer();

    /* Sắp xếp giảm dần */
    Quick_Sort(array,0,size_array-1,Giam_dan);
    Pointer_Array(array,size_array);

    /* Sắp xếp tăng dần */
    Quick_Sort(array,0,size_array-1,Tang_dan);
    Pointer_Array(array,size_array);
}

/* In ra Array bang Variable */
void Normal_Array(const int array[],const int size_array){
    cout <<"Normal Array: ";
    for(int i = 0; i<size_array; i++){
        cout << array[i]<<" ";
    }
    cout<<""<<endl;
}

/*In ra Array bang Pointer*/
void Pointer_Array(const int *array,const int size_array){
    cout << "Pointer Array: ";
    for(int i = 0; i<size_array;i++){
        cout<<*(array+i)<<" ";
    }
    cout<<""<<endl;
}

/* Con tro cap 2 */
void DynamicPointer(){
    int iFirst;
    int iSecond;
    cout<< "Nhap mang 2 chieu"<<endl;
    cout<<"First: ";cin>>iFirst;
    cout<<"Second: ";cin>>iSecond;

    /* Khoi tao con tro cap 2 */
    int **pToPointer = (int**)malloc(iFirst*sizeof(int*));
    for(int i = 0; i<iFirst;i++){
        pToPointer[i] = (int *)malloc(iSecond * sizeof(int));
    }

    /* Nhap du lieu */
    cout<<"Nhap du lieu ";
    for(int i = 0;i<iFirst;i++){
        for(int j=0;j<iSecond;j++){
            cout<<"array "<<j<<" "<<i<<": ";cin>>pToPointer[j][i];
        }
    }

    /* In ra mang*/
    cout<<"In mang 2 chieu"<<endl;
    for(int i = 0;i<iFirst;i++){
        for(int j=0;j<iSecond;j++){
            cout<<"array "<<j<<" "<<i<<": "<<pToPointer[j][i]<<endl;
        }
    }

    /* Giai phong bo nho */
    for(int i = 0;i<iFirst;i++){
        free(pToPointer[i]);
    }
    free(pToPointer);
}


/* Sap xep */
void Swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* partition array */
int Partition(int array[],int low, int high,int(*f_SapXep)(const int &value_array,const int &midNumber)){
	int midNumber = array[high];
	int varSavePosition = low-1;
	for(int j = low; j<high; j++){
		/* idea: i la bien luu vi tri cua so nho hon so midNumber
		neu gia tri o bien i ma lon hon noi duyet thi minh se doi
		so sanh phan tu duyet voi gia tri midNumber
		neu array[j] nho hon thi doi  */
		if(f_SapXep(array[j],midNumber)){
			varSavePosition++;
			Swap(&array[j],&array[varSavePosition]);
		}
	}
	Swap(&array[high], &array[varSavePosition+1]);
	return varSavePosition+1;
}

/* sort array*/
void Quick_Sort(int array[], int low, int high,int(*f_SapXep)(const int &value_array,const int &midNumber)){
	if(low<high){
		int midNumber = Partition(array,low,high,f_SapXep);
		/* ss phai (lon hon) */
		Quick_Sort(array,midNumber+1,high,f_SapXep);
		/* ss trai (nho hon)*/
		Quick_Sort(array,low,midNumber-1,f_SapXep);
	}
}

int Tang_dan(const int &value_array,const int &midNumber){
    return value_array<midNumber;
}
int Giam_dan(const int &value_array,const int &midNumber){
    return value_array>midNumber;
}