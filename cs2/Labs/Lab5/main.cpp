#include <iostream>
#include <stdexcept>

using namespace std;

struct Regular_type{
  Regular_type() {std::cout << "default ctor: " << this << endl; }
  ~Regular_type() { std::cout << this << endl; }
	void test_default_1(){
	Regular_type a[3];

}
	void test_default_2(){
	Regular_type a[3];
}
Regular_type(Regular_type const&x) {
	cout << "copy ctor" << this << endl; 
}

Regular_type& operator=(Regular_type const& x){
	cout << "copy assign" << this << endl;
}
void test_copy_1(){
	Regular_type a;
	Regular_type b = a;
	Regular_type c(a);
	Regular_type d(a);
}
void test_assign_1(){
	Regular_type x;
	Regular_type a[3];
	for(int i = 0; i < 3; ++i)
	a[i] = x;
}
void test_temporary(){
	Regular_type a = Regular_type();
	Regular_type b = Regular_type(a);
	b = Regular_type(a);

}
};

void input_1(Regular_type a, Regular_type const& b)
{
  std::cout << "input_1\n";
}

void test_input_1()
{
  Regular_type x, y;
  std::cout << "before input_1\n";
  input_1(x, y);
  std::cout << "after input_1\n";
}



struct Pair{
	Regular_type first;
	Regular_type second; 
void test_composite(){
	cout << "inside composite";	
	Pair p1;
	Pair p2;
	cout << "created p1 and p2, now doing p2 = p1 twice";
	p2 = p1;
	p2 = p1;
	cout << "finished assignments, leavng test ocmposite";
}
};
Regular_type output_1()
{
  std::cout << "output_1\n";
  return Regular_type();
}


Regular_type output_2()
{
  std::cout << "output_2\n";
  static Regular_type r;
  return r;
}

void test_output_1()
{
  std::cout << "before output_1\n";
  Regular_type r1 = output_1();
  std::cout << "after output_1\n";
 
  std::cout << "before output_2\n";
  Regular_type r2 = output_2();
  std::cout << "after output_2\n";

  std::cout << "before output_2\n";
  r2 = output_2();
  std::cout << "after output_2\n";
}

void except_1()
{
  std::cout << "except_1\n";
  Regular_type a;
  Regular_type b = a;
  throw std::runtime_error("oops");
  std::cout << "except_1\n";
}

void test_catch_1()
{
  try {
    except_1();
  } catch (std::runtime_error& e) {
    std::cerr << "error: " << e.what() << '\n';
  }
}

struct Resource
{
  static int count;

  Resource() {
    if (count++ == 3){
      std::cout << "failure: " << this << '\n';
      throw std::runtime_error("insufficient resources");
    } else {
      std::cout << "acquired: " << this << '\n';
    }
  }

  ~Resource() {
    std::cout << "released: " << this << '\n';
  }
};

int Resource::count = 0;

void except_2()
{
  std::cout << "except_2\n";
  Resource r[10];
}

void test_catch_2()
{
  try {
    except_2();
  } catch (std::runtime_error& e) {
    std::cerr << "error: " << e.what() << '\n';
  }
}

int main (){
//	test_input_1();
//	test_output_1();	
//	test_catch_1();
	test_catch_2();
//	Regular_type object;
	//Pair pair;
//	pair.test_composite();
//	cout << "initialized the first object" << endl;
//	object.test_default_1();
//	object.test_default_2();



}
