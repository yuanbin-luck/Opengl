#include "GLNode.h"

GL::GLNode::GLNode(GLObject* parent):GLObject(parent), m_geometry(nullptr), m_material(nullptr)
{
}

GL::GLNode::GLNode(GLGeometry* geometry, GLMaterial* material, GLObject* parent): GLNode(parent)
{
	m_geometry = geometry;
	m_material = material;
}

GL::GLNode::~GLNode()
{

}

GL::GLGeometry* GL::GLNode::getGeometry()
{
	return m_geometry;
}

GL::GLMaterial* GL::GLNode::getMaterial()
{
	return m_material;
}
