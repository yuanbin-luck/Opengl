#include "GLObject.h"

GL::GLObject::GLObject(GLObject* parent): m_scale(1.0, 1.0, 1.0)
    , m_rotate(0.0,0.0,0.0) , m_location(0.0, 0.0, 0.0) , m_parent(parent)
{

}

GL::GLObject::~GLObject()
{
}

GL::GLObject* GL::GLObject::parent()
{
    return nullptr;
}

glm::vec3 GL::GLObject::location()
{
    return m_location;
}

glm::vec3 GL::GLObject::rotate()
{
    return m_rotate;
}

float GL::GLObject::rotateX()
{
    return m_rotate.x;
}

float GL::GLObject::rotateY()
{
    return m_rotate.y;
}

float GL::GLObject::rotateZ()
{
    return m_rotate.z;
}

glm::vec3 GL::GLObject::scale()
{
    return m_scale;
}

std::list<GL::GLObject*> GL::GLObject::getChilds()
{
    return m_childs;
}

void GL::GLObject::setParent(GLObject* parent)
{
    m_parent = parent;
}

void GL::GLObject::setLocation(const glm::vec3& loca)
{
    m_location = loca;
}

void GL::GLObject::setLocation(float x, float y, float z)
{
    m_location = glm::vec3(x, y, z);
}

void GL::GLObject::setRotate(const glm::vec3& rotate)
{
    m_rotate = rotate;
}

void GL::GLObject::setRotateX(float angle)
{
    m_rotate.x = angle;
}

void GL::GLObject::setRotateY(float angle)
{
    m_rotate.y = angle;
}

void GL::GLObject::setRotateZ(float angle)
{
    m_rotate.z = angle;
}

void GL::GLObject::setScale(const glm::vec3& scale)
{
    m_scale = scale;
}

void GL::GLObject::addChild(GLObject* child)
{
    auto ret = std::find(m_childs.begin(), m_childs.end(), child);
    if (ret != m_childs.end())
    {
        return;
    }
    child->setParent(this);
    m_childs.push_back(child);
}

GL::GLGeometry* GL::GLObject::getGeometry()
{
    return nullptr;
}

GL::GLMaterial* GL::GLObject::getMaterial()
{
    return nullptr;
}
