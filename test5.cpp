// test5.cpp

#include "mystring.h"
#include <cassert>

int main(){
	cout << "2(a)" << endl;
	MyString x("asdfds");
	MyString y("bfdsafd");
	assert((x<y) == 1);
	assert((x>y) == 0);
	assert((x==y) == 0);
	assert((x!=y) == 1);
	assert((x<=y) == 1);
	assert((x>=y) == 0);
	assert((x<"asdfdt") == 1);
	assert(("asdfdt"<x) == 0);
	
	cout << "2(b)" << endl;
	MyString s("hello"); 
	s += " world";
	cout << s << endl;

	// test op+=() and op+()
	MyString sp(" "); 
	MyString period("."); 
	MyString str;

	str += "This" + sp + "should" + sp 
	+= "work" + sp + "without"
	+= sp + "any" + sp + "memory" 
	+= sp + "leak"
	+= period;

	cout << str << endl;
	
	return 0;
}
