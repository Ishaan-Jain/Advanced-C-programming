################################################################################
#                              Terminal Colors                                 #
################################################################################
RED := \033[0;31m
GREEN := \033[0;32m
GOLD := \033[0;33m
BLUE := \033[0;34m
NOCOLOR := \033[0m

################################################################################
#                            Compilation Options                               #
################################################################################
CC := gcc
STDFLAG := -std=c11
DBGFLAG := -g
WRNFLAGS := -Wall -Wextra
ERRFLAG := -Werror

################################################################################
#                           Directory Organization                             #
################################################################################
SRCDIR := src
TSTDIR := tests
BLDDIR := build

################################################################################
#                                Source Files                                  #
################################################################################
SRCFILES := $(wildcard $(SRCDIR)/*.c)
HDRFILES := $(wildcard $(SRCDIR)/*.h)
OBJFILES := $(patsubst $(SRCDIR)/%.c,$(BLDDIR)/%.o,$(SRCFILES))

################################################################################
#                                 Test Files                                   #
################################################################################
# Header files
TSTHDRFILES := $(wildcard $(TSTDIR)/*.h)
# Unit test files for the sorting function
TEST_SORT_SRC_FILES := $(TSTDIR)/test_sort_lexicographically.c
TEST_SORT_SRC_FILES += $(SRCDIR)/sort.c
TEST_SORT_OBJ_FILES := $(BLDDIR)/test_sort_lexicographically.o
TEST_SORT_OBJ_FILES += $(BLDDIR)/sort.o
# Unit test files for the checking function
TEST_CHECK_SRC_FILES := $(TSTDIR)/test_check_lexicographical_order.c
TEST_CHECK_SRC_FILES += $(SRCDIR)/sort.c
TEST_CHECK_OBJ_FILES := $(BLDDIR)/test_check_lexicographical_order.o
TEST_CHECK_OBJ_FILES += $(BLDDIR)/sort.o


.PHONY: help clean run-debug run-test-factorial
################################################################################
#                                Help Message                                  #
################################################################################
help:
	@echo -e "Available targets:											"
	@echo -e "																"
	@echo -e "clean:\tRemoves all object files, temporary files,			"
	@echo -e "      \texecutables, etc.										"
	@echo -e "																"
	@echo -e "debug:\tCompiles and links source files into the debug		"
	@echo -e "      \texecutable.											"
	@echo -e "																"
	@echo -e "test-sort:\tCompiles and links the unit test for the			"
	@echo -e "          \tsorting function.									"
	@echo -e "																"
	@echo -e "test-check:\tComiles and links the unit test for the			"
	@echo -e "           \tchecking function.								"
	@echo -e "																"
	@echo -e "run-debug:\tRuns the debug executable.						"
	@echo -e "																"
	@echo -e "run-test-sort:\tRuns the unit test for the sort function.		"
	@echo -e "                   											"
	@echo -e "run-test-check:\tRuns the unit test for the check function.	"
	@echo -e "																"

################################################################################
#                                  Cleaning                                    #
################################################################################
clean:
	@echo -e "$(GOLD)Cleaning...$(NOCOLOR)"
	@rm -rf $(BLDDIR) *.o ~*

################################################################################
#                               Build Directory                                #
################################################################################
$(BLDDIR):
	@mkdir -p $@

################################################################################
#                            Compilation Targets                               #
################################################################################
$(BLDDIR)/%.o: $(SRCDIR)/%.c $(HDRFILES) | $(BLDDIR)
	@echo -e "$(GOLD)Compiling $< into $@...$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAGS) -c $< -o $@

$(BLDDIR)/%.o: $(TSTDIR)/%.c $(HDRFILES) $(TSTHDRFILES) | $(BLDDIR)
	@echo -e "$(GOLD)Compiling $< into $@...$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) -c $< -o $@

################################################################################
#                              Linkage Targets                                 #
################################################################################
debug: $(OBJFILES) $(HDRFILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(OBJFILES) into $@...$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAG) $(ERRFLAG) $(OBJFILES) \
		-o $(BLDDIR)/$@

test-sort: $(TEST_SORT_OBJ_FILES) $(HDRFILES) $(TSTHDRFILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_SORT_OBJ_FILES) into $@...$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAG) $(ERRFLAG) $(TEST_SORT_OBJ_FILES) \
		-o $(BLDDIR)/$@

test-check: $(TEST_CHECK_SRC_FILES) $(HDRFILES) $(TSTHDRFILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_CHECK_SRC_FILES) into $@...$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAG) $(ERRFLAG) $(TEST_CHECK_SRC_FILES) \
		-o $(BLDDIR)/$@

################################################################################
#                             Execution Targets                                #
################################################################################
run-debug: debug
	@echo -e "$(GOLD)Running debug...$(NOCOLOR)"
	@echo -e ""
	@./$(BLDDIR)/debug

run-test-sort: test-sort
	@echo -e "$(RED)[WARNING] the unit test for the sort function requires the"
	@echo -e "implementation of the check function to be correct. If not,"
	@echo -e "the test results will be inaccurate.$(NOCOLOR)"
	@echo -e "$(GOLD)Running unit tests for the sorting function...$(NOCOLOR)"
	@echo -e ""
	@./$(BLDDIR)/test-sort

run-test-check: test-check
	@echo -e "$(GOLD)Running unit tests for the checking function...$(NOCOLOR)"
	@echo -e ""
	@./$(BLDDIR)/test-check
