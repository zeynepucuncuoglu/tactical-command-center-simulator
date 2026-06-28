#include "TargetManager.h"

void TargetManager::addTarget(const Target& target)
{
    m_targets.insert_or_assign(target.getId(), target);
}

std::optional<Target> TargetManager::findTargetById(const std::string& id) const
{
    auto it = m_targets.find(id);

    if (it == m_targets.end())
    {
        return std::nullopt;
    }

    return it->second;
}

std::vector<Target> TargetManager::getAllTargets() const
{
    std::vector<Target> targets;

    for (const auto& [id, target] : m_targets)
    {
        targets.push_back(target);
    }

    return targets;
}

bool TargetManager::removeTargetById(const std::string& id)
{
    return m_targets.erase(id) > 0;
}