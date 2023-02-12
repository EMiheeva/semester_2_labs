#include <string>

class LangBase {
public:
    std::string generateCode() {
        return someCodeRelatedThing();
    }

    virtual std::string someCodeRelatedThing() {
        return "Base language related thing";
    }
};

class JavaLangImplementation : public LangBase { //inherited functions from a class

public:

    std::string someCodeRelatedThing() override //polymorphism
    {
        return "Java related thing";
    }
};

class CppLangImplementation : public LangBase {

public:
    std::string someCodeRelatedThing() override 
    {
        return "C++ related thing";
    }
};

class PythonLangImplementation : public LangBase {

public:
    std::string someCodeRelatedThing() override 
    {
        return "Python related thing";
    }
};

class CodeGenerator {
public:

    CodeGenerator(LangBase* language) {
        _language = language;
    }

    std::string generateCode() {
        return _language -> generateCode();
    }

    std::string someCodeRelatedThing() 
    {
        return _language -> someCodeRelatedThing();
    }

protected:
    LangBase* _language;
};






