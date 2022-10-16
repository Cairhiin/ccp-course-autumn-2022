#ifndef AALTO_ELEC_CPP_COUNTER_CLASS
#define AALTO_ELEC_CPP_COUNTER_CLASS

#include <iostream>
// implement a reference counter helper class if you want to
class Restricted_Ref_Counter {
public:
    Restricted_Ref_Counter() : count_(0) {
    }

    Restricted_Ref_Counter(const Restricted_Ref_Counter&) = delete;
    Restricted_Ref_Counter& operator=(const Restricted_Ref_Counter&) = delete;
    ~Restricted_Ref_Counter() {}

    void IncreaseCounter() {
         ++count_;
    }

    void DecreaseCounter() {
         --count_;
    }

    int GetCounter() {
        return count_;
    }

private:
    int count_{};
};

#endif