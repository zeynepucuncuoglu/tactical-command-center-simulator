#include "Target.h"
#include <stdexcept>

Target::Target(
    const std::string& id,
    double x,
    double y,
    double speed,
    TargetType type)
    : m_id(id),
      m_x(x),
      m_y(y),
      m_speed(speed),
      m_type(type)
{
    if (id.empty())
    {
        throw std::invalid_argument("Target id cannot be empty");
    }
}
std::string Target::getId() const
{
    return m_id;
}
double Target::getX() const
{
    return m_x;
}
double Target::getY() const
{
    return m_y;
}
double Target::getSpeed() const
{
    return m_speed;
}
TargetType Target::getType() const
{
    return m_type;
}