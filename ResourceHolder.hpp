#ifndef RESOURCEHOLDER_HPP
#define RESOURCEHOLDER_HPP

#include <exception>
#include <assert.h>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>

namespace Textures
{
	enum ID
	{
		Airplane,
		Raptor
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
private:
	std::map<Identifier,
			std::unique_ptr<Resource>> m_ResourceMap;

public:
	ResourceHolder(Identifier id, const std::string& filename);
	void 			load(Identifier id, const std::string& filename);

	template <typename Parameter>
	void 			load(Identifier id, const std::string& filename,
						 const Parameter& secondParam);

//	sf::Texture& 	get(Identifier id);
	const Resource&	get(Identifier id) const;
	void insertResource(std::unique_ptr<Resource>& resource, Identifier id);

};

#include "ResourceHolderIMP.hpp"
#endif // RESOURCEHOLDER_HPP
