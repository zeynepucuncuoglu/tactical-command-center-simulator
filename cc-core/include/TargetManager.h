#pragma once

#include "Target.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <optional>

class TargetManager{
    public:
        void addTarget(const Target& target);
        std::optional<Target> findTargetById(const std::string& id) const;
        std::vector<Target> getAllTargets() const;
        bool removeTargetById(const std::string& id);
    
    private:
        std::unordered_map<std::string, Target> m_targets;

};