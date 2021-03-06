.PHONY : build clean rebuild

SRC_ROOT = src

SUBDIRS := \
./ \
jsoncpp/ \

# Get all source dirs.
SRCDIRS := $(foreach c, $(SUBDIRS), $(subst $(c), $(SRC_ROOT)/$(c), $(c)))
SRCFILES := $(foreach srcdir, $(SRCDIRS), $(wildcard $(srcdir)*.cpp))

DIR_LIB = ../../libs

# All the include pathes.
INCS += ../../include/

# The output file name.
TARGET = demo

# The C program compiler.
CC = g++ -m32

# The pre-processor and compiler options.
# Users can override those variables from the command line.
CFLAGS := $(foreach inc, $(INCS), -I$(inc))
CFLAGS +=  -fPIC -g -D_GLIBCXX_USE_CXX11_ABI=0 -D_LINUX_

# The options used in linking as well as in any direct use of ld.
ifdef LINUX64
LDFLAGS := -L$(DIR_LIB)/x64
else
LDFLAGS := -L$(DIR_LIB)/x86 
endif
LDFLAGS += -fPIC -pthread -laiui -lLogApi -lHsc3Api -lCommApi -lboost_atomic -lboost_chrono -lboost_system -lboost_thread -lasound -lboost_regex

## Stable Section: usually no need to be changed. But you can add more.
##==========================================================================
SOURCEDIR  = $(sort  $(foreach subdir, $(dir $(SRCFILES)), $(patsubst %/, %, $(subdir))))
VPATH      = $(SOURCEDIR)
OBJS       = $(patsubst %.cpp, %.o, $(SRCFILES))
BUILDDIR   = ./build
OBJECTDIR  = $(BUILDDIR)/objs
BUILDOBJS  = $(foreach obj, $(OBJS), $(subst $(dir $(obj)), $(OBJECTDIR)/, $(obj)))
BUILDDEPS  = $(BUILDOBJS:.o=.d)

test:
	@echo ${PWD}

# Build target
#----------------------------------------
build : prepare $(TARGET)

prepare :
	mkdir -p $(BUILDDIR)
	mkdir -p $(OBJECTDIR)

# Rules for generating object files (.o).
#----------------------------------------
$(OBJECTDIR)/%.o : %.cpp
	@$(CC) $(CFLAGS) -o $@  -c $< -MD -MF $(patsubst %.o, %.d, $@)

# Rules for generating the executable.
#-------------------------------------
$(TARGET) : $(BUILDOBJS)
	$(CC) -o $(BUILDDIR)/$@ $^ $(LDFLAGS)
	@echo "build success."

# Clean target
#----------------------------------------
clean :
	rm -f $(BUILDOBJS) $(BUILDDEPS) $(BUILDDIR)/$(TARGET)

# Rebuild target
#----------------------------------------
rebuild : clean build
