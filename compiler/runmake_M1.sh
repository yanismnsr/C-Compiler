# required packages (fedora 34): antlr4 and antlr4-cpp-runtime-devel
rm -r build generated
make ANTLRJAR=/opt/homebrew/Cellar/antlr/4.10.1/antlr-4.10.1-complete.jar ANTLRINC=/opt/homebrew/Cellar/antlr4-cpp-runtime/4.10.1/include/antlr4-runtime ANTLRLIB=/opt/homebrew/Cellar/antlr4-cpp-runtime/4.10.1/lib/libantlr4-runtime.a "$@"