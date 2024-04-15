
/*
================================================================================#=
FILE: appl/main_test.cpp

Test application for the Sorted List.
================================================================================#=
*/
#include "Sorted3DPoint.cpp"
#include "SortedListArray.cpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>

bool array_smoke_test(void)
{
    using namespace std;
    string output;
    Sorted3Dpoint  point_a, point_b, point_c, point_d, point_e, point_f;
    int max = 5;


    point_a.SetName("A");
    point_b.SetName("B");
    point_c.SetName("C");
    point_d.SetName("D");
    point_e.SetName("E");
    point_f.SetName("F");

    point_a.SetXYZ(1.23, 4.56, 7.89);
    point_b.SetXYZ(1.23, 6.78, 9.01);
    point_c.SetXYZ(1.23, 4.56, 9.89);
    point_d.SetXYZ(1.23, 4.56, 9.89);
    point_e.SetXYZ(1.11, 7.33, 1.89);
    point_f.SetXYZ(6.84, 3.14, 1.22);

    //Constructing default list

    ArrayOfRecords array_b;
    cout << "Constructor Test for default: " << endl; 
    cout << "Size: " << to_string(array_b.Size()) << endl;
    cout << "MaxSize: " << to_string(array_b.MaxSize()) << endl;
    
    //Constructing dynamic list

    ArrayOfRecords array_a(max);
    cout << "Constructor Test for size of 5: " << endl; 
    cout << "Size: " << to_string(array_a.Size()) << endl;
    cout << "MaxSize: " << to_string(array_a.MaxSize()) << endl;
    
    //Putting Items into list

    cout << "PutItem begin : results should be A, B and B. " << endl;
    cout << "Since A will be the first item, B is larger than A moving B to the Top, and B is larger than C but C is larger than A. Then the Middle of list will be C, and End of list will be A" << endl;
    cout << "List Before PutItem:" << endl;

    output = array_a.ToString(output);
    cout << output;
    output.clear();

    std::cout << "List After Puting point A: " <<  endl;

    array_a.PutItem(point_a);
    
    output = array_a.ToString(output);
    cout << output;
    output.clear();

    std::cout << "List After Puting point B: " <<  endl;

    array_a.PutItem(point_b);

    output = array_a.ToString(output);
    cout << output;
    output.clear();
    
    
    std::cout << "List After Puting point C: " << endl;

    array_a.PutItem(point_c);

    output = array_a.ToString(output);
    cout << output;
    output.clear();
    /*
    std::cout << "Trying to put too many items in the list:" <<  endl;

    try
    {
        array_a.PutItem(point_d);
        array_a.PutItem(point_e);
        array_a.PutItem(point_f);  

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    */

    std::cout << "PutItem Test done" << endl;

    //Deleting Test

    cout << " DeleteItem begin: results should be B, B, and A" << endl << endl;
    cout << " List before deleting: " << endl;
    
    output = array_a.ToString(output);
    cout << output;
    output.clear();

    cout << " List After Deleting C: " << endl;

    array_a.DeleteItem("C");

    output = array_a.ToString(output);
    cout << output;
    output.clear();
   
    cout << " List After Deleting B: " << endl;

    array_a.DeleteItem("B");

    output = array_a.ToString(output);
    cout << output;
    output.clear();

    cout << " List After Deleting A: " << endl;
    
    array_a.DeleteItem("A");

    output = array_a.ToString(output);
    cout << output;
    output.clear();

    std::cout << "Results done" << endl << endl;

    //Testing overridden Operators

    cout << " Test for operator += and []:" << endl;
    cout << " List Before operator +=: " << endl;

    output = array_a.ToString(output);
    cout << output;
    output.clear();

    array_a += point_c;

    cout << " List After operator +=: " << endl;
    
    output = array_a.ToString(output);
    cout << output;
    output.clear();

    cout << " Get point at array_a[0]" << endl;

    Sorted3Dpoint temp = array_a[0];
    temp.ToString(output);
    cout << output << endl;
    output.clear();

    std::cout << "Results done" << endl << endl;

    //Testing Copy Constructor

    cout << "Copy Test:" << endl;

    cout << "Oringinal List:" << endl;

    array_a.PutItem(point_b);
    array_a.PutItem(point_a);
    array_a += point_c;

    output = array_a.ToString(output);
    cout << output;
    output.clear();


    ArrayOfRecords copy(array_a);

    cout << "Copy List2:" << endl;

    output = copy.ToString(output);
    cout << output;
    output.clear();

    cout << "Oringinal List2:" << endl;

    array_a.DeleteItem("A");
    array_a.DeleteItem("B");
    array_a.DeleteItem("C");

    output = array_a.ToString(output);
    cout << output;
    output.clear();


    ArrayOfRecords copy2(array_a);

    cout << "Copy List2:" << endl;

    output = copy2.ToString(output);
    cout << output;
    output.clear();

    cout << "Copy Test Complete:" << endl;

    cout << "Testing GetItem by Putting he results of GetItem inside PutItem. Example: copy.PutItem(array_a.GetItem(A))" << endl;
    copy.PutItem(array_a.GetItem("A"));

    output = copy.ToString(output);
    cout << output;
    output.clear();

    cout << "GetItem Test Complete:" << endl;

    

    for(Sorted3Dpoint e : array_a)
    {
        e.ToString(output);
        cout << output;
        output.clear();
    }
    
    return true;
};
bool point_smoke_test(void)
{
    using namespace std;
    string output;
    string name = "Bob";
    double one = 1.23;
    double two = 4.65;
    double three = 9.89;

    cout << "TESTING CONSTRUCTOR: ";
    Sorted3Dpoint  point_a, point_b, point_c, point_d(name, one, two, three);
    cout << "PASSED! " << endl;

    point_a.SetName("A");
    point_b.SetName("B");
    point_c.SetName("C");
    //point_d.SetName("D");

    point_a.SetXYZ(1.23, 4.56, 7.89);
    point_b.SetXYZ(1.23, 6.78, 9.01);
    point_c.SetXYZ(1.23, 4.56, 9.89);
    //point_d.SetXYZ(1.23, 4.56, 9.89);

    cout << "TESTING OPERATORS: " << endl;

    cout << "point_a: " << point_a << endl;
    cout << "point_b: " << point_b << endl;
    cout << "point_c: " << point_c << endl;
    cout << "point_d: " << point_d << endl;

    cout << std::boolalpha;
    cout << endl;
    cout << "point_a  < point_b ? : " << (point_a  < point_b) << endl;
    cout << "point_a  > point_b ? : " << (point_a  > point_b) << endl;
    cout << "point_a == point_b ? : " << (point_a == point_b) << endl;
    cout << "point_a <= point_b ? : " << (point_a <= point_b) << endl;
    cout << "point_a >= point_b ? : " << (point_a >= point_b) << endl;

    cout << endl;
    cout << "point_b  < point_a ? : " << (point_b  < point_a) << endl;
    cout << "point_b  > point_a ? : " << (point_b  > point_a) << endl;
    cout << "point_b == point_a ? : " << (point_b == point_a) << endl;
    cout << "point_b <= point_a ? : " << (point_b <= point_a) << endl;
    cout << "point_b >= point_a ? : " << (point_b >= point_a) << endl;

    cout << endl;
    cout << "point_a  < point_c ? : " << (point_a  < point_c) << endl;
    cout << "point_a  > point_c ? : " << (point_a  > point_c) << endl;
    cout << "point_a == point_c ? : " << (point_a == point_c) << endl;
    cout << "point_a <= point_c ? : " << (point_a <= point_c) << endl;
    cout << "point_a >= point_c ? : " << (point_a >= point_c) << endl;

    cout << endl;
    cout << "point_c  < point_d ? : " << (point_c  < point_d) << endl;
    cout << "point_c  > point_d ? : " << (point_c  > point_d) << endl;
    cout << "point_c == point_d ? : " << (point_c == point_d) << endl;
    cout << "point_c <= point_d ? : " << (point_c <= point_d) << endl;
    cout << "point_c >= point_d ? : " << (point_c >= point_d) << endl << endl;

    cout << "TESTING OPERATORS: PASSED!" << endl;

    cout << "TESTING POINT A: " << endl;

    cout << "GetName Results: " << point_a.GetName() << endl;

    cout << "GetXYZ Results for Y value: ";
    vector<double> temp  = point_a.GetXYZ();
    cout << to_string(temp[1]) << endl;

    cout << "ToString results:";
    point_a.ToString(output);
    cout << output << endl;
    return true;
    
};
int main() {

    using namespace std;
    // Get the current time and
    // Print a small "banner" to announce that we are starting the test;
    std::time_t start_time = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now()
    );
    cout << endl;
    cout << endl;
    cout << "Test Run - begins at: " << std::ctime(&start_time) << endl;

    if(point_smoke_test() == true)
    {
        cout << "Sorted3DPoint Test Complete" << endl << endl;
    }
    else
    {
        return EXIT_FAILURE;
    }
    if(array_smoke_test() == true)
    {
        cout << "SortedListArray Test Complete" << endl;
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
};
