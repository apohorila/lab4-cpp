#include "struct.h"

#include <mutex>
#include <sstream>

int DataStructure::get0() const {
    std::shared_lock l(mu0);
    return field0;
}

void DataStructure::set0(int value){
    std::unique_lock l(mu0);
    field0 = value;
}

int DataStructure::get1() const {
    std::shared_lock l(mu1);
    return field1;
}

void DataStructure::set1(int value){
    std::unique_lock l(mu1);
    field1 = value;
}
int DataStructure::get2() const {
    std::shared_lock l(mu2);
    return field2;
}

void DataStructure::set2(int value){
    std::unique_lock l(mu2);
    field2 = value;
}

DataStructure::operator std::string() const {
    std::shared_lock<std::shared_mutex> l0(mu0);
    std::shared_lock<std::shared_mutex> l1(mu1);
    std::shared_lock<std::shared_mutex> l2(mu2);

    std::ostringstream ss;
    ss << "field0=" << field0 << "\n" 
       << "field1=" << field1 << "\n" 
       << "field2=" << field2; 
    return ss.str();
}