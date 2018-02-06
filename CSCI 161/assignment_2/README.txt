README


1. Introduction:

	An Image object is a container that holds the data necessary to represent a greyscale 
image. This includes the title of the image, the number of rows and columns that represent
the pixel resolution of the image, and an array of integers between 0 and 255 that represent
the colour (shade of grey) of each pixel (0 means black, 255 means white). Image objects also
possess some methods and overloaded operators that allow for some manipulation and retrieval
of data.


2. Design:

	The Image class can be initialized using a default constructor that initializes all 
fields to 0; using a parametrized constructor that takes in the image name, the number of 
rows and columns in the image array, and a pointer to the image array, and uses these values 
to initialize the Image; or using a copy constructor that initializes the Image as a deep 
copy of another Image object.

	The get_name(), get_rows(), get_cols(), and get_size() methods can be called to retrieve 
the rows, columns, and size values respectively. The histogram() method can be called to run 
a histogram on the Image's pixel array and will output the histogram results to the screen.

	The + operator can be used to combine two Image objects of the same size, returning a 
new Image object. The name of the new object will be the name of both operands separated 
by " + ". The value of each index in the array will the average value of the corresponding
index in the arrays of the operands.

	The = operator will replace the contents of the left operand's data fields with a deep
copy of the right operand's data fields.

	The == and != operators will compare to Image objects. They compare the values of rows, 
cols, and size, as well as the values of each index in the array. They do not compare the 
name fields of the Images. If all values are equal, == returns true and != returns false.
If any of the values are different, == returns false and != returns true.

	The ostream << operator will stream the information stored in the Image in a formatted
way, including headers. The istream >> operator will prompt the user to input Image data, 
and then will stream the data into an Image object. 


3. Implementation:

	The name in Image is stored as a std::string. This allows the name to be any length and
to contain spaces. The rows, cols, and size variables are integers. The storage space of int
is sufficient because the values of rows and cols range from 0 to 1024, and size = rows*cols,
so it ranges from 0 to 1048576. These three values are needed to take the 1 dimensional pixel
array and output its stored values as a 2 dimensional array.

	int * img_array is a pointer that is used to track the pixel data that is stored in a 
1 dimensional array. When Image needs to store an array, the current array is deleted, and 
a new array of size "size" is generated on the heap with img_array pointing at it. Then the
value of each index in the input array is copied into the corresponding index of img_array.
Copying the values instead of the locations of the input array means manipulating one array
will not influence the other.

	name, rows, cols, size, and img_array are all declared as private, that way the data 
cannot be manipulated from outside of the class. The values of name, rows, cols, and size 
can still be retrieved from outside of the class by calling the methods get_name, get_rows,
get_cols, and get_size.


4. Accomplishment:

	My Image class includes a default constructor, a constructor with the arguments 
(string name, int rows, int cols, int * array), and a copy constructor. The destructor
deletes the array that img_array points to when the Image object is destroyed.

	The operators +, =, and == have been overloaded as described in the Assignment 2 Problem
Description. The != operator has been overloaded to mirror the logic of ==. If the operands
have different sized rows or columns, the + operator will throw a string stating 
"Incompatible size".

	The histogram(int) method can be called to run a histogram and outputs the 
results to screen.  

	The ostream << operator has been overloaded to stream the information stored in the 
Image object in a formatted way. The istream >> operator has been overloaded to prompt the 
user to input Image data, and stream the data into an Image object.

	The .h and .cpp files all include there own comments and documentation, as well as the 
documentation included in this README. There is also a Makefile that will compile the source
files into an executable file called "pex2" when the "make" command is used in the directory
containing these files. The "make clean" command can be used to delete "pex2" and all .o
files in the directory. 


5. Testing:

	My main() function tests all of the methods outlined in the Problem Description of the 
Assignment 2 document. First the default constructor and destructor are tested by generating
a pointer to a "new" Image, displaying its contents, then deleting the Image object. Then 
three Image objects are created using using the parametrized constructor to be used in later
tests. 

	The copy constructor is tested by declaring an Image and instantiating in the 
same statement by setting it equal to an existing Image object (e.g. Image img_1 = img_alf;),
then displaying the contents.

	The assignment operator = is tested by setting an existing Image object to be equal to
a different existing Image object (e.g. img_1 = img_cat;), then displaying the contents. 

	The + operator is tested twice. The first time, the two operands have the same rows and
cols, so the operation is completed correctly and returns an Image object; then the contents
of the returned Image are displayed. The second time, the operands have different sized rows 
and cols, so a string containing "Incompatible size" is thrown. The string is caught in
main() and states "Could not + images due to exception: Incompatible size".

	The == operator is tested twice. First it compares two Images with the same contents but 
different names, and returns true. It then tests two Images with different contents and 
returns false. Then the != operator is tested on two Images with the same content, and 
returns false, followed by a test on two Images with different contents, and returns true. 

	The histogram(int) method is called on an Image using the input value 4, and the correct 
results are displayed.

	To test the istream >> operator, a default Image object is created and "cin >>" is used 
on it. The user is prompted to input the name, rows, cols, and pixel array contents for the
Image object. To confirm the >> operator functioned properly, as well as to test the ostream
<< operator, "cout <<" is used on the image. This will display the contents of the Image in
a formatted fashion with headers.  


6. Known Bugs:

	The only known bug is the >> operator expects the user inputs to be of the correct type.
If incorrect data is input, the program will probably get stuck and be unable to recover. 

