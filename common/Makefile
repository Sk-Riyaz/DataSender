include ../path.mk

OBJS=	$(OBJDIR)/CommonDefines.o 

all:	current

obj:	$(OBJS)

current:	obj
		$(AR) $(LIB)/libCommon.a $(OBJDIR)/*.o

$(OBJDIR)/%.o:%.cc %.hh
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o;

