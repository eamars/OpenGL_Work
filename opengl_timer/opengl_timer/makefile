#
# Make for Game:five_in_row
#
# Compiler: LLVM
# 
# Author: Ran Bao
#

# default compiler
COMP=cc
ARGU=
ARGU_GL=-framework GLUT -framework OpenGL
#




# output name
OUTPUT=opengl_timer
BuildNO=build_beta
#





objects=clock1.o font_driver.o get_fps.o main.o

$(OUTPUT):$(objects)
	$(COMP) -o $(OUTPUT) $(objects) $(ARGU_GL)
	@echo "*** Compile Done ***"
	zip -q -r $(OUTPUT)_$(BuildNO).zip $(OUTPUT)

clock1.o:clock1.c define_graph.h
	$(COMP) -c clock1.c $(ARGU)
       
font_driver.o:font_driver.c define_graph.h font_8x16.h
	$(COMP) -c font_driver.c $(ARGU)

get_fps.o:get_fps.c define_graph.h
	$(COMP) -c get_fps.c $(ARGU)

main.o:main.c define_graph.h
	$(COMP) -c main.c $(ARGU)




clean:
	rm -rf *.o *.zip $(OUTPUT)
	@echo "*** Clean Done ***"


