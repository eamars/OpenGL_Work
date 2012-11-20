#
# Make for Game:five_in_row
#
# Compiler: LLVM
# 
# Author: Ran Bao
#

# default compiler
COMP=cc
ARGU=-std=c99
#




# output name
OUTPUT=five_in_row
#





objects=main.o functions.o ai_function.o steps.o versus.o save_log.c

$(OUTPUT):$(objects)
	$(COMP) -o $(OUTPUT) $(objects)
	@echo "*** Compile Done ***"

functions.o:functions.c define.h
	$(COMP) -c functions.c $(ARGU)
       
ai_function.o:ai_function.c define.h
	$(COMP) -c ai_function.c $(ARGU)
       
steps.o:steps.c define.h
	$(COMP) -c steps.c $(ARGU)
       
versus.o:versus.c define.h
	$(COMP) -c versus.c $(ARGU)
    
save_log.o:save_log.c define.h
	$(COMP) -c save_log.c $(ARGU)
    
main.o:main.c define.h
	$(COMP) -c main.c $(ARGU)

clean:
	rm -rf $(OUTPUT) \
$(objects)
	@echo "*** Clean Done ***"

