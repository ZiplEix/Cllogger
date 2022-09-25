echo "Create cllogger folder ..."
echo "Create include folder ..."
mkdir -p cllogger/include
echo "Copy header files ..."
cp -r include/cllogger.h cllogger/include
echo "Create src folder ..."
mkdir -p cllogger/src
echo "Compiling source files ..."
gcc -c src/*.c
echo "Compiling lib ..."
ar -rc cllogger/src/cllogger.a cllogger.o logger_reset.o write_log.o
echo "Delete useless file ..."
rm *.o
