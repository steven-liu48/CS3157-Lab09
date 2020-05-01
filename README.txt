  - Steven Liu
  - xl2948
  - lab9

Part1:
(a)

[1] 13,constructor,x
[2] 14,constructor,y
[3] 5,copy constructor,b
[4] 5,copy constructor,a
[5] 7,constructor,t
[6] entering operator+
[7] 8,default constructor,temp
[8] 8,copy constructor,u1 from return temp
[9] 8,destructor,temp
[10] entering operator+
[11] 8,default constructor,temp
[12] 8,copy constructor,u2 from return temp
[13] 8,destructor,temp
[14] 16,copy constructor,u3 from return a + t + b
[15] 8,destructor,u2
[16] 8,destructor,u1
[17] 8,destructor,t
[18] 16,copy constructor,z
[19] 16,destructor,u3
[20] 16,destructor,a
[21] 16,destructor,b
[22] cout << z << endl;
[23] 18,destructor,z
[24] 18,destructor,y
[25] 18,destructor,x

(b)
[3][4][20][21] are not shown after changing the add() function. Since the
parameters are references to a and b, no temporary objects are constructed/destructed.

(c)
It allows an implementation to omit creating a temporary which is only used to initialize another object of the same type.
The temporary objects (i.e., the uN objects) returned by add() are not
constructed/destructed.

Part2:
(a) Works as required.
(b) Works as required.
