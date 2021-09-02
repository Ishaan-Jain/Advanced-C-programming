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
TEST_COUNT_INT_SRC_FILES := $(SRCDIR)/qsort.c $(TSTDIR)/test_count_int.c
TEST_READ_INT_SRC_FILES := $(SRCDIR)/qsort.c $(TSTDIR)/test_read_int.c
TEST_WRITE_INT_SRC_FILES := $(SRCDIR)/qsort.c $(TSTDIR)/test_write_int.c
TEST_COMPARE_INT_SRC_FILES := $(SRCDIR)/qsort.c $(TSTDIR)/test_compare_int.c
TEST_SORT_INT_SRC_FILES := $(SRCDIR)/qsort.c $(TSTDIR)/test_sort_int.c

TEST_COUNT_INT_OBJ_FILES := $(BLDDIR)/qsort.o $(BLDDIR)/test_count_int.o
TEST_READ_INT_OBJ_FILES := $(BLDDIR)/qsort.o $(BLDDIR)/test_read_int.o
TEST_WRITE_INT_OBJ_FILES := $(BLDDIR)/qsort.o $(BLDDIR)/test_write_int.o
TEST_COMPARE_INT_OBJ_FILES := $(BLDDIR)/qsort.o $(BLDDIR)/test_compare_int.o
TEST_SORT_INT_OBJ_FILES := $(BLDDIR)/qsort.o $(BLDDIR)/test_sort_int.o

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

test-count-int: $(TEST_COUNT_INT_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_COUNT_INT_OBJ_FILES) into $@... \
			$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_COUNT_INT_OBJ_FILES) -o $(BLDDIR)/$@

test-read-int: $(TEST_READ_INT_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_READ_INT_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_READ_INT_OBJ_FILES) -o $(BLDDIR)/$@

test-write-int: $(TEST_WRITE_INT_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_WRITE_INT_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_WRITE_INT_OBJ_FILES) -o $(BLDDIR)/$@

test-compare-int: $(TEST_COMPARE_INT_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_COMPARE_INT_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_COMPARE_INT_OBJ_FILES) -o $(BLDDIR)/$@

test-sort-int: $(TEST_SORT_INT_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_SORT_INT_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_SORT_INT_OBJ_FILES) -o $(BLDDIR)/$@

################################################################################
#		              Execution Targets	       	       	               #
################################################################################
run-debug: debug
	@echo -e "Running debug...\n"
	@./$(BLDDIR)/$@

run-test-count-int: test-count-int
	@echo -e "Running the unit tests for the count int function...\n"
	@./$(BLDDIR)/test-count-int

run-test-read-int: test-read-int
	@echo -e "Running the unit test for the read int function...\n"
	@./$(BLDDIR)/test-read-int

run-test-write-int: test-write-int
	@echo -e "Running the unit test for the write int function...\n"
	@./$(BLDDIR)/test-write-int

run-test-compare-int: test-compare-int
	@echo -e "Running the unit test for the compare int function...\n"
	@./$(BLDDIR)/test-compare-int

run-test-sort-int: test-sort-int
	@echo -e "Running the unit test for the sort int function...\n"
	@./$(BLDDIR)/test-sort-int