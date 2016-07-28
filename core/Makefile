include ../path.mk

OBJS=	$(OBJDIR)/LogHandler.o \
		$(OBJDIR)/ProcessHandler.o \
		$(OBJDIR)/DataHandler.o

all:	current bin

obj:	$(OBJS)

current:	obj
		$(AR) $(LIB)/libCore.a $(OBJDIR)/*.o

bin:	obj
	$(CC) $(DEFINES) $(CFLAGS) Main.cc $(INCLUDES) $(LIBRARIES) -o $(BUILD_DIR)/bin/dataserver

$(OBJDIR)/%.o:%.cc %.hh
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJDIR)/*.o;
