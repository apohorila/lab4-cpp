#pragma once 
#include <shared_mutex>
#include <string>


class DataStructure {
    private:
        mutable std::shared_mutex mu0;
        mutable std::shared_mutex mu1;
        mutable std::shared_mutex mu2;

        int field0 = 0;
        int field1 = 0;
        int field2 = 0;
    public:
        DataStructure()=default;
        
        int get0() const;
        void set0(int value);

        int get1() const;
        void set1(int value);

        int get2() const;
        void set2(int value);
        
        operator std::string() const;

};
