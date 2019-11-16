Before compiling, include these files to your project:
- Project -> Options -> General Options -> Target -> Choose your Device
- Project -> Options -> C/C++ Compiler -> Preprocessor -> Additional include directories -> Include all .h files in these directions:
      ...\Libraries\inc\
      ...\
- Project -> Add files... -> Add all .c files in ...\Libraries\src\, then add all .c files and .h files in ...\