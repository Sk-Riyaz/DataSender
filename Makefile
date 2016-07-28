include path.mk

all:	message cmns util cores

message:	
	cd messages;\
	make

cmns:		
	cd common;\
	make

util:		
	cd utils;\
	make

cores:
	cd core;\
	make

clean:	
	cd messages;\
	make clean;\
	cd ../;\
	\
	cd common;\
	make clean;\
	cd ../;\
	\
	cd utils;\
	make clean;\
	cd ../;\
	\
	cd core;\
	make clean;\
	cd ../;\
	$(RM) $(BUILD_DIR)/lib/*.a;\
	$(RM) $(BUILD_DIR)/bin/*

