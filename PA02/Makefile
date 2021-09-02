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
# I cheated. Let's see if anyone is going to spot it...
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
TEST_CHAR_TO_NUM_SRC_FILES := $(TSTDIR)/test_char_to_num.c $(SRCDIR)/convert.c
TEST_CHAR_TO_NUM_OBJ_FILES := $(BLDDIR)/test_char_to_num.o $(BLDDIR)/convert.o

TEST_NUM_TO_CHAR_SRC_FILES := $(TSTDIR)/test_num_to_char.c $(SRCDIR)/convert.c
TEST_NUM_TO_CHAR_OBJ_FILES := $(BLDDIR)/test_num_to_char.o $(BLDDIR)/convert.o

TEST_CONVERT_BASE_SRC_FILES := $(TSTDIR)/test_convert_base.c $(SRCDIR)/convert.c
TEST_CONVERT_BASE_OBJ_FILES := $(BLDDIR)/test_convert_base.o $(BLDDIR)/convert.o

TEST_HDR_FILES := $(wildcard $(TSTDIR)/*.h)


.PHONY: help clean run-debug run-test-factorial
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

test-char-to-num: $(TEST_CHAR_TO_NUM_OBJ_FILES) $(HDRFILES) $(TEST_HDR_FILES) \
					| $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_CHAR_TO_NUM_OBJ_FILES) into $@..." \
		"$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_CHAR_TO_NUM_OBJ_FILES) -o $(BLDDIR)/$@

test-num-to-char: $(TEST_NUM_TO_CHAR_OBJ_FILES) $(HDRFILES) $(TEST_HDR_FILES) \
					| $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_NUM_TO_CHAR_OBJ_FILES) into $@..." \
		"$(NOCOLR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_NUM_TO_CHAR_OBJ_FILES) -o $(BLDDIR)/$@

test-convert-base: $(TEST_CONVERT_BASE_OBJ_FILES) $(HDRFILES) \
					$(TEST_HDR_FILES) | $(BLDDIR)
	@echo -e "$(GOLD)Linking $(TEST_CONVERT_BASE_OBJ_FILES) into $@..." \
		"$(NOCOLOR)"
	@$(CC) $(STDFLAG) $(DBGFLAG) $(WRNFLAGS) $(ERRFLAG) \
		$(TEST_CONVERT_BASE_OBJ_FILES) -o $(BLDDIR)/$@

################################################################################
#		              Execution Targets	       	       	               #
################################################################################
run-test-char-to-num: test-char-to-num
	@echo -e "$(GOLD)Running unit tests for the char to num conversion" \
		" function...$(NOCOLOR)"
	@echo -e ""
	@./$(BLDDIR)/test-char-to-num

run-test-num-to-char: test-num-to-char
	@echo -e "$(GOLD)Running unit tests for the num to char conversion" \
		" function...$(NOCOLOR)"
	@echo -e ""
	@./$(BLDDIR)/test-num-to-char

run-test-convert-base: test-convert-base
	@echo -e "$(GOLD)Running unit tests for the base conversion" \
		" function...$(NOCOLOR)"
	@echo -e ""
	@./$(BLDDIR)/test-convert-base
