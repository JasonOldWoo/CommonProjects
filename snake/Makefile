export TOP_DIR:=$(shell pwd)
BIN_DIR:=$(TOP_DIR)/bin
TARGET:=snake
BIN_TARGET:=$(BIN_DIR)/$(TARGET)
SRC_DIR:=src app

include $(TOP_DIR)/project.mk

define build_obj
for SubDir in $(SRC_DIR); \
do \
	if ! [ -d $$SubDir ]; then \
		echo "The $$SubDir is not exist !" ; \
			exit 11; \
	fi; \
	echo "Building $$SubDir ..."; \
	make -C $$SubDir; \
	if [ $$? -ne 0 ]; then \
		echo "Building $$SubDir is failed!"; \
		exit 12 ; \
	fi;	\
done

endef


all:
	@$(call build_obj)
	gcc $(TOP_DIR)/obj/*.o -o $(BIN_TARGET) $(G_CFLAGS) $(INCLUDE_DIR)  $(G_LDFLAGS) -lpthread

.PHONY:clean
clean:
	-rm -f $(TOP_DIR)/obj/*.o $(BIN_TARGET)
