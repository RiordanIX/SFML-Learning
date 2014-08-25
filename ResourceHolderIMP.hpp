#ifndef RESOURCEHOLDER_IMP_HPP
#define RESOURCEHOLDER_IMP_HPP

#include "ResourceHolder.hpp"



template <typename Resource, typename Identifier>
ResourceHolder<Resource, Identifier>::
	ResourceHolder(Identifier id, const std::string& filename)
{
	load(id, filename);
}



template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::
	load(Identifier id, const std::string& filename)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename)) {
		throw std::runtime_error("ResourceHolder::load - Failed to load "
								+ filename);
	}
	insertResource(resource, id);
}



template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::
	insertResource(std::unique_ptr<Resource>& resource, Identifier id)
{
	auto inserted = m_ResourceMap.insert(std::make_pair(id,
								std::move(resource)));
	assert (inserted.second);
}



template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::
	load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename, secondParam)){
		throw std::runtime_error("ResourceHolder::load - Failed to load "
								+ filename);
	}
	insertResource(resource, id);
}


template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::
	get(Identifier id) const
{
	auto found = m_ResourceMap.find(id);
	assert(found != m_ResourceMap.end());
	return *found->second;
}

#endif // RESOURCEHOLDER_IMP_HPP
