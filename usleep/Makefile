#
# Makefile of the program 
#

USLEEP=usleep
CC=gcc -O2 -o
PERMS=755
PROGRAM_PATH=/usr/local/bin

$(USLEEP):	Makefile
	@echo "$(CC) $(USLEEP) $(USLEEP).c"
	@$(CC) $(USLEEP) $(USLEEP).c

clean:	
	@echo "Deleting the binary file of this program "
	@echo "rm -rf $(USLEEP)"
	@rm -rf $(USLEEP)

install:
	@echo "Installing the $(USLEEP) program"
	@echo "cp $(USLEEP) $(PROGRAM_PATH)"
	@cp $(USLEEP) $(PROGRAM_PATH)
	@echo "chmod $(PERMS) $(PROGRAM_PATH)/$(USLEEP)"
	@chmod $(PERMS) $(PROGRAM_PATH)/$(USLEEP)

uninstall:
	@echo "Uninstalling the $(USLEEP) program"
	@echo "rm -rf $(PROGRAM_PATH)/$(USLEEP)" 
	@rm -rf $(PROGRAM_PATH)/$(USLEEP)



