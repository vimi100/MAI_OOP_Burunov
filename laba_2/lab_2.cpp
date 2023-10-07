#include "four.h"

int main () {
    cout << "TEST SOME CONSTRUCTORS:" << endl;
    cout << "Default constructor:" << endl;
    Four a;
    cout << "Something created..." << endl;
    cout << "Second constructor:" << endl;
    Four second(5, '11');
    second.print(cout);
    cout << endl;
    cout << "Third constructor:" << endl;
    Four third {'1', '1', '1', '2', '3'};
    third.print(cout);
    cout << endl;
    cout << "Fourth costructor:" << endl;
    Four fourth("332");
    fourth.print(cout);
    cout << endl;
    cout << "Fifth constructor:" << endl;
    Four fifth("33");
    Four fifth_alternative(fifth);
    fifth_alternative.print(cout);
    cout << endl;
    cout << "Sixth constructor:" << endl;
    Four sixth(move(fifth_alternative));
    sixth.print(cout);

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "TEST SOME COMPARE FUNCTIONS:" << endl;
    cout << endl;

    cout << "1) Bigger than:" << endl;
    Four l_1("333"), r_1("331");
    cout << "left:";
    l_1.print(cout);
    cout << endl;
    cout << "right:";
    r_1.print(cout);
    cout << endl;
    try {
        bool result_2 = l_1.bigger(r_1);
        if (result_2) {
            cout << "left is bigger than right" << endl; 
        }
        else {
            cout << "left is not bigger than right" << endl;
        }
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
    cout << endl;

    cout << "2) Smaller than:" << endl;
    Four l_2("AAa819"), r_2("AAaaA99");
    cout << "left:";
    l_2.print(cout);
    cout << endl;
    cout << "right:";
    r_2.print(cout);
    cout << endl;
    try {
        bool result_1 = l_2.smaller(r_2);
        if (result_1) {
            cout << "left is smaller than right" << endl; 
        }
        else {
            cout << "left is not smaller than right" << endl;
        }
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
    cout << endl;

    cout << "3) Equal:" << endl;
    Four l_3("57291"), r_3("57291");
    cout << "left:";
    l_3.print(cout);
    cout << endl;
    cout << "right:";
    r_3.print(cout);
    cout << endl;
    try {
        bool result_3 = l_3.equal(r_3);
        if (result_3) {
            cout << "left and right are equal" << endl; 
        }
        else {
            cout << "left and right are not equal" << endl;
        }
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
    cout << endl;
    cout << endl;

    cout << "TEST SOME ARITHMETICS FUNCTIONS:" << endl;
    cout << endl;

    cout << "1) Addition:" << endl;
    Four l_4("A841A"), r_4("A7193");
    cout << "left:";
    l_4.print(cout);
    cout << endl;
    cout << "right:";
    r_4.print(cout);
    cout << endl;
    try {
        cout << "Result: ";
        l_4.addition(r_4).print(cout);
        cout << endl;
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
    cout << endl;
    cout << endl;

    cout << "2) Subtraction:" << endl;
    Four l_5("A8492"), r_5("88979");
    cout << "left:";
    l_5.print(cout);
    cout << endl;
    cout << "right:";
    r_5.print(cout);
    cout << endl;
    try {
        cout << "Result: ";
        l_5.subtraction(r_5).print(cout);
        cout << endl;
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
    cout << endl;

}