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
OUTPUT=md5hash
BuildNO=v1.1
#





objects=main.o md5_hash.o md5.o

$(OUTPUT):$(objects)
	$(COMP) -o $(OUTPUT) $(objects) $(ARGU)
	@echo "*** Compile Done ***"
	zip -q -r $(OUTPUT)_$(BuildNO).zip $(OUTPUT)

main.o:main.c md5_hash.h
	$(COMP) -c main.c $(ARGU)
       
md5_hash.o:md5_hash.c md5_hash.h
	$(COMP) -c md5_hash.c $(ARGU)

md5.o:md5.c md5.h
	$(COMP) -c md5.c $(ARGU)

clean:
	rm -rf *.o *.zip $(OUTPUT)
	@echo "*** Clean Done ***"


