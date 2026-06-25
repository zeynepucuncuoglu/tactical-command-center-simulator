#pragma once
#include <string>

enum class TargetType
{
    AIRCRAFT,
    SHIP,
    DRONE,
    UNKNOWN
};

class Target 
{
    public:
        Target(
            const std::string& id,
            double x,
            double y,
            double speed,
            TargetType type
        );

        std::string getId() const;
        double getX() const;
        double getY() const;
        double getSpeed() const;
        TargetType getType() const;
        
    private:
        std::string m_id;
        double m_x;
        double m_y;
        double m_speed;
        TargetType m_type;
};

