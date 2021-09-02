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
TEST_ALLOC_WORDS_SRC_FILES := $(SRCDIR)/count.c $(TSTDIR)/test_alloc_words.c
TEST_COUNT_WORDS_FILES := $(SRCDIR)/count.c $(TSTDIR)/test_count_words.c
TEST_PRINT_WORDS_FILES := $(SRCDIR)/count.c $(TSTDIR)/test_print_words.c


TEST_ALLOC_WORDS_OBJ_FILES := $(BLDDIR)/count.o $(BLDDIR)/test_alloc_words.o
TEST_COUNT_WORDS_OBJ_FILES := $(BLDDIR)/count.o $(BLDDIR)/test_count_words.o
TEST_PRINT_WORDS_OBJ_FILES := $(BLDDIR)/count.o $(BLDDIR)/test_print_words.o

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

test-alloc-words: $(TEST_ALLOC_WORDS_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_ALLOC_WORDS_OBJ_FILES) into $@... \
			$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_ALLOC_WORDS_OBJ_FILES) -o $(BLDDIR)/$@

test-count-words: $(TEST_COUNT_WORDS_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_COUNT_WORDS_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_COUNT_WORDS_OBJ_FILES) -o $(BLDDIR)/$@

test-print-words: $(TEST_PRINT_WORDS_OBJ_FILES) $(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_PRINT_WORDS_OBJ_FILES) into $@... \
		$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_PRINT_WORDS_OBJ_FILES) -o $(BLDDIR)/$@


################################################################################
#		              Execution Targets	       	       	               #
################################################################################
run-debug: debug
	@echo -e "Running debug...\n"
	@./$(BLDDIR)/$@

run-test-alloc-words: test-alloc-words
	@echo -e "Running the unit tests for the count int function...\n"
	@./$(BLDDIR)/test-alloc-words

run-test-count-words: test-count-words
	@echo -e "Running the unit test for the read int function...\n"
	@./$(BLDDIR)/test-count-words

run-test-print-words: test-print-words
	@echo -e "Running the unit test for the write int function...\n"
	@./$(BLDDIR)/test-print-words

