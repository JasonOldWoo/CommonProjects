CC := gcc
INCLUDE_DIR := \
		-I$(TOP_DIR)/src/include	\
		-I$(TOP_DIR)/app/include

G_CFLAGS :=
G_LDFLAGS :=

%.o : %.c
	$(CC)  -c $< -o $(TOP_DIR)/obj/$@ $(G_CFLAGS) $(INCLUDE_DIR)  $(G_LDFLAGS) -lpthread
