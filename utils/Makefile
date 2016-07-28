include ../path.mk

OBJS=	$(OBJDIR)/LogDefine.o 

all:	current

obj:	$(OBJS)

current:	obj
		$(AR) $(LIB)/libUtils.a $(OBJDIR)/*.o

$(OBJDIR)/%.o:%.cc %.hh
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o;
