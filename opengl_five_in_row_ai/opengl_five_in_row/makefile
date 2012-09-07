#
# Make for Game:five_in_row
#
# Compiler: LLVM
# 
# Author: Ran Bao
#

# default compiler
COMP=gcc
ARGU=-std=c99 -O2
ARGL=-framework GLUT -framework OpenGL
#




# output name
OUTPUT=opengl_five_in_row
BuildNO=Build_Release
#





objects=board_data.o board_UI.o font_driver.o main.o mouse.o \
	piece_UI.o steps.o win_check.o ai_brain.o savelog.o

$(OUTPUT):$(objects)
	$(COMP) -o $(OUTPUT) $(objects) $(ARGU) $(ARGL)
	@echo "*** Compile Done ***"
	zip -q -r $(OUTPUT)_$(BuildNO).zip $(OUTPUT)

board_data.o:board_data.c define_data.h define_UI.h
	$(COMP) -c board_data.c $(ARGU)
       
board_UI.o:board_UI.c define_data.h define_UI.h
	$(COMP) -c board_UI.c $(ARGU)

font_driver.o:font_driver.c define_data.h define_UI.h font_8x16.h
	$(COMP) -c font_driver.c $(ARGU)

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

ai_brain.o:ai_brain.c define_data.h define_UI.h
	$(COMP) -c ai_brain.c $(ARGU)

savelog.o:savelog.c define_data.h
	$(COMP) -c savelog.c $(ARGU)

clean:
	rm -rf *.o *.zip $(OUTPUT)
	@echo "*** Clean Done ***"


