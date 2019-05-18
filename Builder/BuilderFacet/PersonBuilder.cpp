#include "PersonBuilder.hpp"
#include "PersonJobBuilder.hpp"
#include "PersonAddrBuilder.hpp"

PersonJobBuilder PersonBuilderBase::works()
{
	return PersonJobBuilder{person};
}

PersonAddrBuilder PersonBuilderBase::lives()
{
	return PersonAddrBuilder{person};
}