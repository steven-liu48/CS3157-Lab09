#include <cstring>
#include <cstdio>

#include "mystring.h"

// default constructor

MyString::MyString() 
{
#ifdef BASIC4TRACE
    fprintf(stderr, "BASIC4TRACE: (%p)->MyString()\n", this);
#endif

    data = new char[1];
    data[0] = '\0';
    
    len = 0;
}

// constructor

MyString::MyString(const char* p)
{
#ifdef BASIC4TRACE
    fprintf(stderr, "BASIC4TRACE: (%p)->MyString(const char *)\n", this);
	//printf("%s\n", p);
#endif

    if (p) {
	len = strlen(p);
	data = new char[len+1];
	strcpy(data, p);
    } else {
	data = new char[1];
	data[0] = '\0';
	len = 0;
    }
}

// destructor

MyString::~MyString() 
{
#ifdef BASIC4TRACE
    fprintf(stderr, "BASIC4TRACE: (%p)->~MyString()\n", this);
	//printf("%s\n", data);
#endif

    delete[] data;
}

// copy constructor 

MyString::MyString(const MyString& s) 
{
#ifdef BASIC4TRACE
    fprintf(stderr, "BASIC4TRACE: (%p)->MyString(const MyString&)\n", this);
	//cout << s << endl;
#endif

    len = s.len;
    
    data = new char[len+1];
    strcpy(data, s.data);
}

// copy assignment

MyString& MyString::operator=(const MyString& rhs)
{
#ifdef BASIC4TRACE
    fprintf(stderr, "BASIC4TRACE: (%p)->op=(const MyString&)\n", this);
#endif

    if (this == &rhs) {
	return *this;
    }

    // first, deallocate memory that 'this' used to hold

    delete[] data;

    // now copy from rhs
    
    len = rhs.len;

    data = new char[len+1];
    strcpy(data, rhs.data);

    return *this;
}

// operator+
MyString operator+(const MyString& s1, const MyString& s2)
{
	MyString temp;
    temp += s1;
	temp += s2;
	return temp;
}

/*
MyString operator+(const MyString& s1, const MyString& s2)
{
#ifdef BASIC4TRACE
    fprintf(stderr, 
	    "BASIC4TRACE: op+(const MyString&, const MyString&)\n");
#endif

    MyString temp;

    delete[] temp.data;

    temp.len = s1.len + s2.len;

    temp.data = new char[temp.len+1];
    strcpy(temp.data, s1.data);
    strcat(temp.data, s2.data);

    return temp;
}
*/

// operator <

int operator<(const MyString& s1, const MyString& s2)
{
	//printf("%s %s\n", s1.data, s2.data);
	if (strcmp(s1.data, s2.data) < 0){
		return 1;
	} else {
		return 0;
	}
}

// operator >

int operator>(const MyString& s1, const MyString& s2)
{
	if (strcmp(s1.data, s2.data) > 0){
		return 1;
    } else {
        return 0;
    }
}

// operator ==

int operator==(const MyString& s1, const MyString& s2)
{
	if (strcmp(s1.data, s2.data) == 0){
		return 1;
	} else {
		return 0;
	}
}

// operator !=

int operator!=(const MyString& s1, const MyString& s2)
{
	if (s1 == s2){
		return 0;
	} else {
		return 1;
	}
}

// operator <=

int operator<=(const MyString& s1, const MyString& s2)
{
	if (s1 > s2){
		return 0;
	} else {
		return 1;
	}
}

//operator >=

int operator>=(const MyString& s1, const MyString& s2)
{
	if (s1 < s2){
		return 0;
	} else {
		return 1;
	}
}

// operator +=
/*
MyString& operator+=(MyString& s1, const MyString& s2)
{
	MyString temp(s1);
	s1.len += s2.length();
	delete[] s1.data;
    s1.data = new char[s1.len+1];
	//cout << temp.data << endl;
    strcpy(s1.data, temp.data);
    strcat(s1.data, s2.data);
	return s1;
}
*/
MyString& MyString::operator+=(const MyString& rhs)
{
    MyString temp(this->data);
    this->len += rhs.length();
    delete[] this->data;
    this->data = new char[this->len+1];
    //cout << temp.data << endl;
    strcpy(this->data, temp.data);
    strcat(this->data, rhs.data);
    return *this;
}

// put-to operator

ostream& operator<<(ostream& os, const MyString& s)
{
    os << s.data;
    return os;
}

// get-from operator

istream& operator>>(istream& is, MyString& s)
{
    // this is kinda cheating, but this is just to illustrate how this
    // function can work.
    
    string temp;
    is >> temp;

    delete[] s.data;

    s.len = strlen(temp.c_str());
    s.data = new char[s.len+1];
    strcpy(s.data, temp.c_str());

    return is;
}

// operator[] - in real life this function should be declared inline

char& MyString::operator[](int i) 
{
    return data[i];
}

// operator[] const - in real life this should be inline

const char& MyString::operator[](int i) const
{
    // illustration of casting away constness
    return ((MyString&)*this)[i];
}

