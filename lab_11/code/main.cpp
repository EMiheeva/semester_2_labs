#include <iostream>
#include <CodeGenerator.hpp>

int main() {

    JavaLangImplementation javaLang;
    CppLangImplementation cppLang;
    PythonLangImplementation pythonLang;

    CodeGenerator generatorJava = CodeGenerator( &javaLang );
    std::cout << generatorJava.generateCode() << std::endl;

    CodeGenerator generatorCpp = CodeGenerator( &cppLang );
    std::cout << generatorCpp.generateCode() << std::endl;

    CodeGenerator generatorPython = CodeGenerator( &pythonLang );
    std::cout << generatorPython.generateCode() << std::endl;

    return 0;
}
