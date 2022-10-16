#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS

#include "restricted_ref_counter.hpp"
#include <iostream>

/*
    Implement a class RestrictedPtr that holds a pointer of any type with at least the following members:
        - default constructor (takes no parameters)
        - constructor with a raw pointer parameter
        - copy constructor
        - destructor
        - copy assignment operator
        - function GetData that takes no parameters and returns the data the raw pointer refers to.
            The data returned should be such that modifying it modifies the data the pointer refers to.
        - function GetPointer that takes no parameters and returns the raw pointer
        - function GetRefCount that takes no parameters and returns an int with the reference count
    
    At any time the objects should keep track of how many references there are to a pointer
    and not allow more than 3 references. If the reference count drops to 0, the referenced
    pointer's memory should be released. If the reference count is already 3 when copying,
    the copier should set it's pointer to nullptr and reference count to 1.
    NOTE: GetPointer, GetData and GetRefCount are needed for the tests to run
*/

template <typename T>
class RestrictedPtr {
public:
    explicit RestrictedPtr() : obj_(nullptr), use_count_(0) {
        use_count_ = new Restricted_Ref_Counter();
        use_count_->IncreaseCounter();
    }

    RestrictedPtr(T *ptr) : obj_(ptr), use_count_(0) {
        use_count_ = new Restricted_Ref_Counter();
        if (obj_) {
            use_count_->IncreaseCounter();
        }
    }

    RestrictedPtr(RestrictedPtr<T>& ptr) 
            : obj_(ptr.obj_), use_count_(ptr.use_count_) {
                if (GetRefCount() == 3) {
                    obj_ = nullptr;
                    use_count_ = new Restricted_Ref_Counter();
                    use_count_->IncreaseCounter();
                } else {
                    use_count_->IncreaseCounter();
                }
    }

    ~RestrictedPtr<T>() {
        use_count_->DecreaseCounter();
        if (GetRefCount() == 0)
        {
            delete obj_;
            delete use_count_;
        }
    }

    RestrictedPtr& operator= (const RestrictedPtr<T>& ptr){
        if (this != &ptr) {
            use_count_->DecreaseCounter();
            if (GetRefCount() == 0) {
                delete obj_;
                delete use_count_;
            }

            if (GetRefCount() == 3) {
                obj_ = nullptr;
                use_count_ = new Restricted_Ref_Counter();
                use_count_->IncreaseCounter();
            } else {
                obj_ = ptr.obj_;
                use_count_ = ptr.use_count_;
                use_count_->IncreaseCounter();
            }
        }

        return *this;
    }

    T& operator*() const {
        return *obj_;
    }

    T* operator->() const {
       return obj_;
    }

    T& GetData() const {
        return *obj_;
    }

    T* GetPointer() const {
        return obj_;
    }

    int GetRefCount() const {
        return use_count_->GetCounter();
    }

private:
    T* obj_;
    Restricted_Ref_Counter* use_count_;
};

#endif