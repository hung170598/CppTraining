CC = gcc
CFLAGS = -Wall -Wextra -I./include

DEF_OBJ_DIR = obj/

# Detect OS
ifeq ($(OS),Windows_NT)
	EXE = .exe
	WIN_DEF_OBJ_DIR = $(subst /,\,$(DEF_OBJ_DIR))
	OBJ_DIR = $(WIN_DEF_OBJ_DIR)$(subst /,\,$(patsubst ./%,%,$(dir $@)))
	MKDIR = if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	RM = if exist $(WIN_DEF_OBJ_DIR) rmdir /S /Q $(WIN_DEF_OBJ_DIR) & if exist *$(EXE) del /Q *$(EXE)
else
	EXE = .run
	OBJ_DIR = $(DEF_OBJ_DIR)$(patsubst ./%,%,$(dir $@))
	MKDIR = mkdir -p $(OBJ_DIR);
	RM = rm -r $(DEF_OBJ_DIR) 2>/dev/null; rm -f *$(EXE)
endif

pointer: pointer.o
	$(CC) $(CFLAGS) -o $@$(EXE) $(DEF_OBJ_DIR)/$<

struct: struct.o
	$(CC) $(CFLAGS) -o $@$(EXE) $(DEF_OBJ_DIR)/$<

ds-linked-list: ds-linked-list.o include/linked-list.o
	$(CC) $(CFLAGS) -o $@$(EXE) $(addprefix $(DEF_OBJ_DIR),$^)

ds-stack: ds-stack.o include/stack.o
	$(CC) $(CFLAGS) -o $@$(EXE) $(addprefix $(DEF_OBJ_DIR),$^)

ds-queue: ds-queue.o include/queue.o
	$(CC) $(CFLAGS) -o $@$(EXE) $(addprefix $(DEF_OBJ_DIR),$^)

%.o: %.c
	@$(MKDIR)
	$(CC) $(CFLAGS) -c $< -o $(DEF_OBJ_DIR)/$@

.PHONY: clean
clean:
	$(RM)