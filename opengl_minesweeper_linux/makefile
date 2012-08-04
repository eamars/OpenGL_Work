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
OUTPUT=opengl_minesweeper
#





objects=board_data.o board_UI.o letters.o main.o MouseAction.o \
	piece.o numbers.o generate_mine.o

$(OUTPUT):$(objects)
	$(COMP) -o $(OUTPUT) $(objects) $(ARGU)
	@echo "*** Compile Done ***"

board_data.o:board_data.c define_data.h define_UI.h
	$(COMP) -c board_data.c $(ARGU)
       
board_UI.o:board_UI.c define_data.h define_UI.h
	$(COMP) -c board_UI.c $(ARGU)

letters.o:letters.c define_data.h define_UI.h font_8x16.h
	$(COMP) -c letters.c $(ARGU)

main.o:main.c define_data.h define_UI.h
	$(COMP) -c main.c $(ARGU)

MouseAction.o:MouseAction.c define_data.h define_UI.h
	$(COMP) -c MouseAction.c $(ARGU)

piece.o:piece.c define_data.h define_UI.h
	$(COMP) -c piece.c $(ARGU)

numbers.o:numbers.c define_data.h define_UI.h
	$(COMP) -c numbers.c $(ARGU)

generate_mine.o:generate_mine.c define_data.h define_UI.h
	$(COMP) -c generate_mine.c $(ARGU)

clean:
	rm -rf $(OUTPUT) \
$(objects)
	@echo "*** Clean Done ***"


