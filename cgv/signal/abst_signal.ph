#pragma once
@exclude <cgv/config/ppp.ppp>
#include <vector>
#include <map>
#include <cgv/type/invalid_type.h>
#include <cgv/type/func/make_argument.h>

#include <cgv/signal/lib_begin.h>

namespace cgv {
	namespace signal {

class CGV_API functor_base;
class CGV_API tacker;

/// base functionality of all signals that allows connection and disconnection of abst_functors also to instances derived from the tacker class
class CGV_API signal_base
{
protected:
	std::vector<functor_base*> functors;
	void link(functor_base* fp);
	void unlink(functor_base* fp);
	void connect(functor_base* fp);
	void disconnect(const functor_base* fp);
public:
	/// return the number of connected functors
	unsigned get_nr_functors() const;
	/// only use this if you exactly know what to do!
	void connect_abst(functor_base* fp);
	/// virtual destructor
	virtual ~signal_base();
	/// disconnect all connections to the given tacker
	void disconnect(const tacker* t);
	/// disconnect all connections
	void disconnect_all();
};

/// base class for all functor classes which provides access to the tacker interface of an involved instance
class CGV_API functor_base
{
protected:
	/// place characteristic pointers into the two passed references, which serve as basis for the comparison of two functors
	virtual void put_pointers(const void* &p1, const void* &p2) const = 0;
public:
	/// virtual desctructor
	virtual ~functor_base();
	/// return the tacker interface of an involved instance or 0 if this is a function functor
	virtual const tacker* get_tacker() const;
	/// construct a copy of the functor on the heap
	virtual functor_base* clone() const = 0;
	/// compare this functor to another functor based on the pointers
	bool operator == (const functor_base& f) const;
};

/** derive your classes that are attached to signals from this tacker class. 
    It will automatically disconnect from all signals on destruction such that
	no signal can call a method of an instance of your class after the instance
	has been destroyed. */
class CGV_API tacker
{
private:
	typedef std::map<signal_base*, int> map_type;
	mutable map_type signals;
public:
	/// implement to allow reimplementation of copy constructor
	tacker();
	/// overload to avoid copying of signals
	tacker(const tacker&);
	/// keep track of the given signal
	void tack(signal_base* s) const;
	/// forget the given signal
	void untack(signal_base* s) const;
	/// forget all signals
	void untack_all() const;
	/// disconnect from all tacked signals on destruction
	virtual ~tacker();
};

template <int i, @["typename T1 = type::invalid_type"; ", "; "typename T".N_ARG." = type::invalid_type"]>
struct signature;

@for (i=0; i<=N_ARG; i=i+1) @{

template <@["typename T1"; ", "; "typename T".N_ARG]>
struct signature<@(i),@["T1"; ", "; "T".N_ARG]>
{
@for (j=1; j<=i; j=j+1) @{
	typedef typename type::func::make_argument<T@(j)>::type A@(j);
@}
};

@}

	}
}

#include <cgv/config/lib_end.h>
