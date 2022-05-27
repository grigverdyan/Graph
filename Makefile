.PHONY: all re clean fclean debug gcov lcov clean_gcda clean_gcno fclean_glcov

FOLDER		=	sources
SOURCES		=	$(wildcard $(FOLDER)/*.cpp)
OBJECTS		=	$(SOURCES:.cpp=.o)
CC			=	g++
FLAGS		=	-Wall -Werror -Wextra
STANDARD	=	-std=c++17
EXECUTABLE	=	graph.exe
RM			=	rm -f
LCOVTEST	=	$(EXECUTABLE:.exe=.info)
BROWSER		=	google-chrome

all : $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(STANDARD) $(FLAGS) -c $< -o $@

re : fclean all

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(EXECUTABLE)

debug :
	gdb $(EXECUTABLE) input.txt core

gcov :
	$(CC) $(SOURCES) --coverage -o $(EXECUTABLE)
	./$(EXECUTABLE) input.txt

lcov :
	lcov -t "program" -o $(LCOVTEST) -c -d .
	genhtml -o report $(LCOVTEST)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) $(LCOVTEST)
	$(RM) $(EXECUTABLE)
	$(BROWSER) report/index.html

clean_gcda :
	$(RM) *.gcda

clean_gcno :
	$(RM) *.gcno

fclean_glcov : clean_gcda clean_gcno
	$(RM) $(LCOVTEST)
	$(RM) -fr report
	$(RM) $(EXECUTABLE)
