#include "SceneNode.hpp"
#include <assert.h>




SceneNode::SceneNode()
{
}



void SceneNode::attachChild(Ptr child)
{
	child->m_Parent = this; // "child"s Parent Pointer points to this.
	m_Children.push_back(std::move(child));// Ptr to child is added to
										   // parent's list of children
}



SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(m_Children.begin(), m_Children.end(),
//	Lambda captures by Reference
//		 |		return type syntax for Lambdas
//		 |			 |	 |	  If is in list,returns true.
//		 V			 V	 V		V
		[&] (Ptr& p) -> bool {return p.get() == &node; });
	assert(found != m_Children.end());// Asserts "found" is in the list

	Ptr result = std::move(*found);	// "result" is child of this one,
	result->m_Parent = nullptr;		// "m_Parent" of 'result' is
	m_Children.erase(found);
	return result;
}



void SceneNode::draw(sf::RenderTarget& target,
					sf::RenderStates states) const
{
	states.transform *= getTransform();
	drawCurrent(target, states);

	for (const Ptr& child : m_Children)
	{
		child->draw(target, states);
	}
}



void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}



void SceneNode::updateChildren(sf::Time dt)
{
	for(Ptr& child : m_Children)
		child->update(dt);
}



sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;
	for (const SceneNode* node = this; node != nullptr; node = node->m_Parent)
		transform = node->getTransform() * transform;

	return transform;
}



sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}
