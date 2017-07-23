#ifndef ASH_GLRESOURCE_INL
#define ASH_GLRESOURCE_INL

#include "glresource.hpp"

#include <utility>
#include "../util/debug.hpp"
#include "../util/logger.hpp"

namespace ash
{
	template<class Manager>
	template<class... Types>
	GLResource<Manager>::GLResource(Types&&... args)
	{
		Manager::alloc(id, std::forward<Types>(args)...);
		cdebug() << "Allocated GL resource, ID #" << id << " with " << pretty_name<Manager>();
	}

	template<class Manager>
	GLResource<Manager>::GLResource(GLResource&& other)
	{
		id = other.id;
		other.id = 0;
	}

	template<class Manager>
	GLResource<Manager>& GLResource<Manager>::operator=(GLResource&& other)
	{
		if (this != &other)
		{
			id = other.id;
			other.id = 0;
		}

		return *this;
	}

	template<class Manager>
	GLResource<Manager>::~GLResource()
	{
		Manager::free(id);
		cdebug() << "Freed GL resource, ID #" << id << " with " << pretty_name<Manager>();
	}

	template<class Manager>
	GLResource<Manager>::operator GLuint() const
	{
		return id;
	}
}

#endif // GLRESOURCE_INL
