#include<iostream>
using namespace std;

// shared_ptr
// unique_ptr
// auto_ptr
// weak_ptr


class NewObj
{
	public:
	int x;
	NewObj(){std::cout << "Constructor NewObj " << std::endl;}
	~NewObj(){std::cout << "Destructor NewObj " << std::endl;}
};


class Test
{
	public:
	int x;
	std::unique_ptr<NewObj> y;
	~Test();
	Test();
};

Test::Test()
{
	std::cout << "Constructor Test " << std::endl;
	y = std::unique_ptr<NewObj>(new NewObj);
	//throw 10.0;
	x = 0;
}

Test::~Test()
{
	std::cout << "Destructor Test " << std::endl;
}

class B;

// Cyclical problem using shared_ptr
class A
{

	public:
	std::shared_ptr<B> b_ptr;
	A();
	~A();

};

class B
{

	public:
	B();
	std::shared_ptr<A> a_ptr;
	~B();
};

A::A()
{
	std::cout << "Constructor A" << std::endl;
}

A::~A()
{
	std::cout << "Destructor A" << std::endl;
}

B::B()
{
	std::cout << "Constructor B" << std::endl;
}

B::~B()
{
	std::cout << "Destructor B" << std::endl;
}


void CyclicalProblemIllustration()
{
	std::cout << "CyclicalProblemIllustration Start " << std::endl;
	// Shared_ptr cyclical problem illustration
	std::shared_ptr<A> a_obj_ptr(new A());
	std::shared_ptr<B> b_obj_ptr(new B());
	
	a_obj_ptr->b_ptr = b_obj_ptr;
	b_obj_ptr->a_ptr = a_obj_ptr;
	std::cout << "CyclicalProblemIllustration End" << std::endl;
}

void SharedPtrWeakPtrUseCount()
{
	
	std::cout << "SharedPtrWeakPtrUseCount Start " << std::endl;
	std::shared_ptr<Test> obj(new Test);
	std::shared_ptr<Test> obj3(obj);
	std::shared_ptr<Test> obj4(obj3);
	std::weak_ptr<Test> obj2(obj);
	obj->x  = 10;
	std::cout << "obj x = " << obj->x << std::endl;
	std::cout << "obj use_count = " << obj.use_count() << std::endl;
	std::cout << "obj3 use_count = " << obj3.use_count() << std::endl;
	std::cout << "obj4 use_count = " << obj4.use_count() << std::endl;
	//obj.reset();
	std::cout << "obj2 use_count = " << obj2.use_count() << std::endl;
	obj.reset();
	obj3.reset();
	obj4.reset();
	std::cout << "obj2 use_count = " << obj2.use_count() << std::endl;
	if(!obj2.expired())
	{
		std::cout << "obj2 x = " << obj2.lock()->x << std::endl;
		std::cout << "obj2 use_count = " << obj2.use_count() << std::endl;
	}
	//std::cout << "obj2 x = " << obj2.lock()->x << std::endl;

	std::cout << "SharedPtrWeakPtrUseCount End" << std::endl;
}

void UniquePtrIllustration()
{
	std::cout << "Unique Ptr Start "  << std::endl;

	std::unique_ptr<Test> obj_ptr(new Test);
	std::unique_ptr<Test[]> obj_ptr_array(new Test[5]);
        //std::unique_ptr<Test> obj2_ptr = obj_ptr; // compilation error
	std::cout << "obj_ptr " << obj_ptr->x << std::endl;
        std::unique_ptr<Test> obj2_ptr = std::move(obj_ptr);
	if(!obj_ptr)
	{
		std::cout << "obj_ptr is null after move" << std::endl;
	}
	std::cout << "obj2_ptr " << obj2_ptr->x << std::endl;

	std::cout << "Unique Ptr End "  << std::endl;
}

// As long as exception is caught and program exits gracefully, smart pointers will delete the memory address they are pointing to.
//i.e the destructor will get called

void SmartPtrExceptionHandling()
{
	std::cout << "SmartPtrExceptionHandling Start"<< std::endl;
	std::unique_ptr<Test> smart_pointer(new Test);
	throw 10.0;
	/*
	try
	{
		std::unique_ptr<Test> smart_pointer(new Test);
		throw 10.0;
	}
	catch(...)
	{
		std::cout << "Exception caught locally"<< std::endl;
		
	}
	*/
	std::cout << "SmartPtrExceptionHandling End"<< std::endl;
}

class Deleter
{
	public:
	Deleter()
	{
		cout << "Deleter Constructor" << endl;
	}
	
	void operator()(Test *ptr)
	{
		cout << "Custom deleter " << endl;
		delete[] ptr;
	}
};

void DeleteFunc(Test *ptr)
{
		cout << "Custom DeleteFunc " << endl;
		delete[] ptr;
}

void SharedPtrCustomDeleteFunction()
{
	cout << "SharedPtrCustomDeleteFunction Start" << endl;
	shared_ptr<Test> obj(new Test[5],&DeleteFunc);
	cout << "use count = " << obj.use_count() << endl;
	cout << "SharedPtrCustomDeleteFunction End" << endl;
}

void autoPtrIllustration()
{
	std::auto_ptr<Test> obj_ptr(new Test);
	obj_ptr->x = 10;
        std::cout << "obj_ptr : " << obj_ptr.get() << "x = " << obj_ptr->x  << std::endl;
        std::auto_ptr<Test> obj2_ptr  = obj_ptr;
	
	if(obj_ptr.get() == NULL)		
	{
		std::cout << "obj_ptr is null " << std::endl;
	}

        std::cout << "obj_ptr : " << obj_ptr.get()  << std::endl;
        std::cout << "obj2_ptr : " << obj2_ptr.get()  << std::endl;
}

int main()
{
	//autoPtrIllustration();
	//SharedPtrCustomDeleteFunction();
	
	CyclicalProblemIllustration();
	//SharedPtrWeakPtrUseCount();
	//UniquePtrIllustration();

	//SmartPtrExceptionHandling();
		
	/*try
	{
		SmartPtrExceptionHandling();
	}
	catch(...)
	{	
		std::cout << "Caught Exception thrown by SmartPtrExceptionHandling"<< std::endl;
        }*/
	

	// shared_ptr 
	//std::shared_ptr<Test> obj(new Test);// not preferred way of creating shared_ptr. 2 Heap Allocation,  one for data (i.e Test) and other for Control Block ( i.e the shared Pointer)
	//std::shared_ptr<Test> obj(new Test[5],[](Test *ptr){delete[] ptr;});
	//std::shared_ptr<Test> obj = std::make_shared<Test>(); // best way to create a shared pointer. Only one Heap Allocation constructor called for data, control Block.

}
