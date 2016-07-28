include ../path.mk

OBJS=	$(OBJDIR)/MsgBase.o \
		$(OBJDIR)/LogMsg.o \
		$(OBJDIR)/DataMsg.o

all:	msgpool current

msgpool:	
	cd msgPool;\
	make

obj:	$(OBJS)

current:	obj
		$(AR) $(LIB)/libMsgs.a $(OBJDIR)/*.o

$(OBJDIR)/%.o:%.cc %.hh
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o;\
	cd msgPool;\
	make clean
