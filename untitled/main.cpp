#include <iostream>

using namespace std;

#include <vector>

#include <memory>


class SuperClass{

public:
    string name = "SCname";


};


class Class : public SuperClass{

public:

    string lol = "lll";
};




int main()
{

    Class a;

    vector<SuperClass*> vec;

    vec.push_back(new Class());

    cout << static_cast<Class*>(vec[0])->lol << endl;
    return 0;
}
