#
# Make for Game:five_in_row
#
# Compiler: LLVM
# 
# Author: Ran Bao
#

# default compiler
COMP=cc
ARGU=-std=c99 -lglut
#




# output name
OUTPUT=opengl_five_in_row
#





objects=board_data.o board_UI.o letters.o main.o mouse.o \
	piece_UI.o steps.o win_check.o

$(OUTPUT):$(objects)
	$(COMP) -o $(OUTPUT) $(objects) $(ARGU)
	@echo "*** Compile Done ***"

board_data.o:board_data.c define_data.h define_UI.h
	$(COMP) -c board_data.c $(ARGU)
       
board_UI.o:board_UI.c define_data.h define_UI.h
	$(COMP) -c board_UI.c $(ARGU)

letters.o:letters.c define_data.h define_UI.h
	$(COMP) -c letters.c $(ARGU)

main.o:main.c define_data.h define_UI.h
	$(COMP) -c main.c $(ARGU)

mouse.o:mouse.c define_data.h define_UI.h
	$(COMP) -c mouse.c $(ARGU)

piece_UI.o:piece_UI.c define_data.h define_UI.h
	$(COMP) -c piece_UI.c $(ARGU)

steps.o:steps.c define_data.h define_UI.h
	$(COMP) -c steps.c $(ARGU)

win_check.o:win_check.c define_data.h define_UI.h
	$(COMP) -c win_check.c $(ARGU)

clean:
	rm -rf $(OUTPUT) \
$(objects)
	@echo "*** Clean Done ***"


