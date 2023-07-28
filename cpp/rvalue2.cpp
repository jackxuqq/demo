#include <iostream>
#include <string>
#include <string.h>


class Object
{
public:
    Object(const std::string& data)
    {
        std::cout << "call constuct" << std::endl;
        m_data = data;
    }

    Object(Object& o)
    {
        std::cout << "call copy construct" << std::endl;
    }

    Object& operator=(Object&& o)
    {
        std::cout << "call move assign" << std::endl;
        this->m_data = o.m_data;
        o.m_data = "";
        return *this;
    }

    Object(Object&& o)
    {
        std::cout << "call move construct" << std::endl;
        this->m_data = o.m_data;
        o.m_data = "";
    }

    void append(const std::string& s)
    {
        this->m_data += s;
    }

    void print()
    {
        if (this->m_data.length() > 0)
        {
            std::cout << this->m_data << std::endl;
        }
        else
        {
            std::cout << "empty object" << std::endl;
        }
    }
private:
    std::string m_data;
};


Object createObject(const std::string& s)
{
    Object ret(s);
    return ret;
}

void process(Object&& o) {
    o.print();
    o.append(" append");
    o.print();
}


// rval ref to a lval, do not change zhe  lval's life
void case1()
{
    std::cout << "------------case1------------------" << std::endl;
    Object o("Init");
    process(std::move(o));  // 传入左值
    o.print();
}

// rval ref to a rval, contine rval's life avoid copy
void case2()
{
    std::cout << "------------case2------------------" << std::endl;
    process(createObject("Init"));
    //Object tmp =  std::move(createObject("Init2"));
    Object tmp =  createObject("Init2");
    tmp.print();
}

int main()
{
    case1();
    case2();
    return 0;
}
