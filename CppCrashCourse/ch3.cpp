#include <cstdio>
#include <string>
#include <cstddef>

struct Tracer {
 Tracer(const char* name) : name{ name } {
    printf("%s constructed.\n", name);
 }

 ~Tracer() {
     printf("%s destructed.\n", name);
 }
private:
 const char* const name;
};

struct Point {
  float x, y, z;
};

struct Person {
  std::string name;
  int age;
  bool married;
};

static Point origin{0, 0, 0};

thread_local Tracer t1{ "static var" };
thread_local Tracer t2{ "Thread-local variable" };

void tracer_garbage() {
  const auto t2_ptr = &t2;
  printf("A\n");
  Tracer t3{ "Automatic variable" };
  printf("B\n");
  const auto* t4 = new Tracer{ "Dynamic variable" };
  printf("C\n");
}

struct superTracer : Tracer {
  int balls() {
    printf("showing balls"); 
  }
};

int main() {
  int* ptr = new int[100]; 
  try {
    printf("sdljfi"); 
  } catch (...) {
    
  }


  delete[] ptr; 

}