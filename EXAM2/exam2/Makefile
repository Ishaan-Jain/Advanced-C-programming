################################################################################
#				Terminal Colors		       	       	       #
################################################################################
RED := \033[0;31m
GREEN := \033[0;32m
GOLD := \033[0;33m
BLUE := \033[0;34m
NOCOLOR := \033[0m

################################################################################
#				Compilation Options		       	       #
################################################################################
CC := gcc
STDFLAG := -std=c11
DBGFLAG := -g
WRNFLAGS := -Wall -Wextra
ERRFLAG := -Werror

################################################################################
#		             Directory Organization			       #
################################################################################
SRCDIR := src
TSTDIR := tests
BLDDIR := build

################################################################################
#		             	Source Files			       	       #
################################################################################
SRCFILES := $(wildcard $(SRCDIR)/*.c)
HDRFILES := $(wildcard $(SRCDIR)/*.h)
OBJFILES := $(patsubst $(SRCDIR)/%.c,$(BLDDIR)/%.o,$(SRCFILES))

################################################################################
#		             	  Test Files			       	       #
################################################################################
TEST_ALLOC_NODE_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_alloc_node.c
TEST_GET_LENGTH_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_get_length.c
TEST_POP_NODE_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_pop_node.c
TEST_PRINT_LIST_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_print_list.c
TEST_PUSH_NODE_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_push_node.c
TEST_REMOVE_NODE_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_remove_node.c
TEST_SEARCH_NODE_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_search_node.c

TEST_ALLOC_NODE_OBJ_FILES := $(SRCDIR)/list.c $(BLDDIR)/test_alloc_node.o
TEST_GET_LENGTH_OBJ_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_get_length.o
TEST_POP_NODE_OBJ_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_pop_node.o
TEST_PRINT_LIST_OBJ_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_print_list.o
TEST_PUSH_NODE_OBJ_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_push_node.o
TEST_REMOVE_NODE_OBJ_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_remove_node.o
TEST_SEARCH_NODE_OBJ_FILES := $(SRCDIR)/list.c $(TSTDIR)/test_search_node.o

TEST_HDR_FILES := $(wildcard $(TSTDIR)/*.h) $(wildcard $(SRCDIR)/*.h)


.PHONY: help clean run-debug
################################################################################
#		             	  Help message			       	       #
################################################################################
help:
	@echo -e "Available targets:"
	@echo -e ""
	@echo -e "clean:\tRemoves all object files, temporary files,"
	@echo -e "      \texecutables, etc."
	@echo -e ""
	@echo -e "debug:\tCompiles and links source files into the debug"
	@echo -e "      \texecutable."
	@echo -e ""

################################################################################
#		             	Cleaning Recipe		       	       	       #
################################################################################
clean:
	@echo -e "$(GOLD)Cleaning...$(NOCOLOR)"
	@rm -rf $(BLDDIR) *.o ~*

################################################################################
#		          Create the build directory		       	       #
################################################################################
$(BLDDIR):
	@mkdir -p $@

################################################################################
#		              Compilation Targets	       	       	       #
################################################################################
$(BLDDIR)/%.o: $(SRCDIR)/%.c $(HDRFILES) | $(BLDDIR)
	@echo -e "$(GOLD)Compiling $< into $@...$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) -c $< -o $@

$(BLDDIR)/%.o: $(TSTDIR)/%.c $(HDRFILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Compiling $< into $@...$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) -c $< -o $@

################################################################################
#		              	Linkage Targets	       	       	       	       #
################################################################################
debug: $(OBJFILES) $(HDRFILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(OBJFILES) into $@...$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) $(OBJFILES) \
		-o $(BLDDIR)/$@

test-alloc-node: $(TEST_ALLOC_NODE_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_ALLOC_NODE_OBJ_FILES) into $@... \
			$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_ALLOC_NODE_OBJ_FILES) -o $(BLDDIR)/$@

test-get-length: $(TEST_GET_LENGTH_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_GET_LENGTH_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_GET_LENGTH_OBJ_FILES) -o $(BLDDIR)/$@

test-pop-node: $(TEST_POP_NODE_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_POP_NODE_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_POP_NODE_OBJ_FILES) -o $(BLDDIR)/$@

test-print-list: $(TEST_PRINT_LIST_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_PRINT_LIST_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_PRINT_LIST_OBJ_FILES) -o $(BLDDIR)/$@		

test-push-node: $(TEST_PUSH_NODE_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_PUSH_NODE_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_PUSH_NODE_OBJ_FILES) -o $(BLDDIR)/$@		

test-remove-node: $(TEST_REMOVE_NODE_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_REMOVE_NODE_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_REMOVE_NODE_OBJ_FILES) -o $(BLDDIR)/$@		

test-search-node: $(TEST_SEARCH_NODE_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_SEARCH_NODE_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_SEARCH_NODE_OBJ_FILES) -o $(BLDDIR)/$@		



################################################################################
#		              Execution Targets	       	       	               #
################################################################################
run-debug: debug
	@echo -e "Running debug...\n"
	@./$(BLDDIR)/$@

run-test-alloc-node: test-alloc-node
	@echo -e "Running the unit tests for the count int function...\n"
	@./$(BLDDIR)/test-alloc-node

run-test-print-list: test-print-list
	@echo -e "Running the unit test for the read int function...\n"
	@./$(BLDDIR)/test-print-list

run-test-pop-node: test-pop-node
	@echo -e "Running the unit test for the write int function...\n"
	@./$(BLDDIR)/test-pop-node

run-test-get-length: test-get-length
	@echo -e "Running the unit tests for the count int function...\n"
	@./$(BLDDIR)/test-get-length

run-test-push-node: test-push-node
	@echo -e "Running the unit test for the read int function...\n"
	@./$(BLDDIR)/test-push-node

run-test-remove-node: test-remove-node
	@echo -e "Running the unit test for the write int function...\n"
	@./$(BLDDIR)/test-remove-node

run-test-search-node: test-search-node
	@echo -e "Running the unit test for the write int function...\n"
	@./$(BLDDIR)/test-search-node
