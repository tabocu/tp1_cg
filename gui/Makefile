QDIR    = /home/tabocu/Qt/5.7/gcc_64

CC  = g++
MOC = $(QDIR)/bin/moc

CFLAGS  = -c -pipe -std=c++11 -Wall -W -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB

TARGET  = main

INC = \
	-I. \
	-I$(QDIR) \
	-I$(QDIR)/include \
	-I$(QDIR)/include/QtGui \
	-I$(QDIR)/include/QtCore \
	-I$(QDIR)/include/QtWidgets


LIBS = $(SUBLIBS) -L$(QDIR)/lib -lQt5Gui -lQt5Core -lQt5Widgets -lpthread -lGL

# find all file names of headers with Q_OBJECT without recursion
MOC_HEADERS = $(shell find ./ -type f -name '*.h' | xargs grep -l 'Q_OBJECT' | sed -e 's,^\./,,')
MOC_SOURCES = $(patsubst %.h, moc_%.cpp, $(MOC_HEADERS))
MOC_OBJECTS = $(patsubst %.cpp, %.o, $(MOC_SOURCES))

# find all file names of cpp's without recursion
SOURCES := $(shell find ./ -type f -name '*.cpp' | sed -e 's,^\./,,')
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))

SOURCES += $(MOC_SOURCES)
OBJECTS += $(MOC_OBJECTS)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "\n--------Linking---------------------------\n"
	$(CC) -Wl,-rpath,$(QDIR)/lib -o $(TARGET) $(OBJECTS) $(LIBS)

moc_%.cpp: %.h
	@echo "\n--------Generating moc's------------------\n"
	$(MOC) $(INC) $< -o $@

%.o: %.cpp
	@echo "\n--------Generating objects----------------\n"
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "\n--------Cleaning objects and mocs---------\n"
	rm -f moc_*
	rm -f *.o
	rm -f *~core *.core
