#include<string>
#include<map>
#include<iostream>
#include<functional>


void funcA(int a, int d){
    std::cout << a   << "\t" << d << std::endl;
}

class Object {
  public:
    template <typename _Fx, typename... Args>
    void handle(_Fx&& _Func, Args... args) {
        auto handleFunction = std::bind(_Func, args...);
    m_factory["funcA"] = handleFunction; 
    }

   void call(const std::string& fcName){
       auto func = m_factory[fcName];
    func(1,2);
   }
   private:
   std::map<std::string, std::function<void(int,int)>> m_factory;
};
int main() {
    Object object;
    int a = 100;
    int b = 200;
    object.handle(funcA, a, b);
    a = 1000;
    object.call("funcA");
}
