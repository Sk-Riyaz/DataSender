include ../../path.mk

OBJS=	$(OBJDIR)/MsgBasePool.o\
		$(OBJDIR)/LogMsgPool.o \
		$(OBJDIR)/MsgPoolInterface.o \
		$(OBJDIR)/DataMsgPool.o


all: 	current

obj:	$(OBJS)

current:	obj
		$(AR) $(LIB)/libMsgPool.a $(OBJDIR)/*.o

$(OBJDIR)/%.o:%.cc %.hh
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o
