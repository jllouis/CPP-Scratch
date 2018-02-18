#include <iostream>
#include <map>
//#include <boost/any.hpp>
#include <any>

using namespace std;

int main() {
    map<string, any> mappie;
    map<string, map<string, string>> nested{{"key0", {{"key1", "key2"}}}};
    map<string, string> val{{"first.a", "value.a"}};
    mappie["first"] = val;
    mappie["second"] = "second_val";

    cout << nested["key0"]["key1"] << endl;

    cout << val["first.a"] << endl;
    cout << any_cast<const char *>(mappie["second"]) << endl;
    cout << any_cast<map<string, string>>(mappie["first"])["first.a"] << endl;

    return 0;
}