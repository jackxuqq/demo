#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include <sstream>

//base func def
std::string trimNumber(const std::string& str);
std::string lowFirst(const std::string& str);
std::string cuteName(const std::string& str);

//geometry def
class Geometry
{
public:
    virtual void foo() = 0;
};

class Line :public Geometry
{
public:
    virtual void foo(){std::cout << "i am line" << std::endl;}
};

class Circle :public Geometry
{
public:
    virtual void foo(){std::cout << "i am line" << std::endl;}
};

class Torus :public Geometry
{
public:
    virtual void foo(){std::cout << "i am line" << std::endl;}
};

#define DECLARE_FUNC(name) m_supportedGeometry.push_back(std::make_pair(#name, name));

class DistanceComputation;
using DistFuncPtr = void (DistanceComputation::*) ();

//compute def
class DistanceComputation
{

public:
    DistanceComputation(Geometry* g1, Geometry* g2)
    :m_g1(g1), m_g2(g2)
    {
    }

    double getResult(){return m_result;}

    void calc();

    static void init();

private:
    Geometry* m_g1;
    Geometry* m_g2;
    double m_result;
    static std::vector<std::pair<std::string,DistFuncPtr> > m_supportedGeometry;
    static std::unordered_map<std::string, DistFuncPtr> m_factory;
    static void autoRegister();

private:
    //never inline
    void lineDistLine();
    void lineDistCircle();
    void lineDistTorus();
    void circleDistLine();
    void circleDistCircle();
    void circleDistTorus();
    void torusDistLine();
    void torusDistCircle();
    void torusDistTorus();
    //add new geometry func here

    static void declareFunc();
};

//compute impl
std::vector<std::pair<std::string,DistFuncPtr> > DistanceComputation::m_supportedGeometry{};
std::unordered_map<std::string, DistFuncPtr> DistanceComputation::m_factory{};
void DistanceComputation::lineDistLine(){ std::cout << "Call:" << __FUNCTION__ << std::endl;}
void DistanceComputation::lineDistCircle(){ std::cout << "Call:" << __FUNCTION__ << std::endl;}
void DistanceComputation::lineDistTorus(){ std::cout << "Call:" << __FUNCTION__ << std::endl;}
void DistanceComputation::circleDistLine(){ std::cout << "Call:" << __FUNCTION__ << std::endl;}
void DistanceComputation::circleDistCircle(){ std::cout << "Call:" << __FUNCTION__ << std::endl;}
void DistanceComputation::circleDistTorus(){ std::cout << "Call:" << __FUNCTION__ << std::endl;}
void DistanceComputation::torusDistLine(){ std::cout << "Call:" << __FUNCTION__ << std::endl;}
void DistanceComputation::torusDistCircle(){ std::cout << "Call:" << __FUNCTION__ << std::endl;}
void DistanceComputation::torusDistTorus(){ std::cout << "Call:" << __FUNCTION__ << std::endl;}
void DistanceComputation::calc()
{
    auto prefix = typeid(*(this->m_g1)).name();
    auto mid = "Dist";
    auto suffix = typeid(*(this->m_g2)).name();
    auto name = lowFirst(trimNumber(prefix)) + mid + trimNumber(suffix);

    if (auto itr = m_factory.find(name); itr != m_factory.end())
    {
        auto funcPtr = itr->second;
        (this->*funcPtr)();
    }
    else
    {
        std::cout << "func_name[" << name << "] not found!" << std::endl;
    }
}

void DistanceComputation::init()
{
    declareFunc();
    autoRegister();
}

void DistanceComputation::autoRegister()
{
    for (auto& curr: m_supportedGeometry)
    {
        auto name = cuteName(curr.first);
        //std::cout << "name:" << name << std::endl;
        m_factory[name] = curr.second;
    }
}
void DistanceComputation::declareFunc()
{
    DECLARE_FUNC(&DistanceComputation::lineDistLine);
    DECLARE_FUNC(&DistanceComputation::lineDistCircle);
    DECLARE_FUNC(&DistanceComputation::lineDistTorus);
    DECLARE_FUNC(&DistanceComputation::circleDistLine);
    DECLARE_FUNC(&DistanceComputation::circleDistCircle);
    DECLARE_FUNC(&DistanceComputation::circleDistTorus);
    DECLARE_FUNC(&DistanceComputation::torusDistLine);
    DECLARE_FUNC(&DistanceComputation::torusDistCircle);
    DECLARE_FUNC(&DistanceComputation::torusDistTorus);
    //declare here after add new geometry func
}

//base func impl
std::string trimNumber(const std::string& str)
{
    bool flag = false;
    std::stringstream ss;
    for (auto i = 0; i < str.length(); ++i)
    {
        if (str[i] >= '0' && str[i] <= '9' && !flag)
        {
            continue;
        }
        else
        {
            flag = true;
            ss << str[i];
        }
    }
    return ss.str();
}

std::string lowFirst(const std::string& str)
{
    if (str.length() == 0)
    {
        return "";
    }
    std::stringstream ss;
    if (str[0] >= 'A' && str[0] <= 'Z')
    {
        ss << char(str[0] - ('A' - 'a'));
        ss << str.substr(1);
        return ss.str();
    }
    return str;
}


std::vector<std::string> split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> res;
    if("" == str)
    {
        return res;
    }
    char * strs = new char[str.length() + 1] ;
    strcpy(strs, str.c_str());

    char * d = new char[delim.length() + 1];
    strcpy(d, delim.c_str());

    char *p = strtok(strs, d);
    while(p)
    {
        std::string s = p;
        res.push_back(s);
        p = strtok(NULL, d);
    }

    delete[] strs;
    delete[] d;
    return res;
}

std::string cuteName(const std::string& str)
{
    auto v = split(str, "::");

    if (v.size() <=  1)
    {
        return "";
    }

    return v[1];
}

int main()
{
    DistanceComputation::init();
    Line l1,l2;
    Circle c1,c2;
    Torus t1,t2;

    //line dist line
    DistanceComputation dc(&l1, &l2);
    dc.calc();

    //circle dist line
    DistanceComputation dc2(&c1, &l1);
    dc2.calc();

    return 0;
}
