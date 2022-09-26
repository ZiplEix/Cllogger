echo "Create sulogger folder ..."
echo "Create include folder ..."
mkdir -p sulogger/include
echo "Copy header files ..."
cp -r include/sulogger.h sulogger/include
echo "Create src folder ..."
mkdir -p sulogger/src
echo "Compiling source files ..."
gcc -c src/*.c
echo "Compiling lib ..."
ar -rc sulogger/src/sulogger.a sulogger.o logger_reset.o write_log.o
echo "Delete useless file ..."
rm *.o
