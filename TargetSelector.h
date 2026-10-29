#pragma once
#include <cstddef>
#include <limits>
#include <vector>

struct Vec2 { float x{}; float y{}; };
struct Enemy { Vec2 position; bool active{true}; }

// Returns the closest active enemy index, or -1 if none exists.
inline int findNearestEnemy(const Vec2& player, const std::vector<Enemy>& enemies) {
    float bestDistanceSquared = std::numeric_limits<float>::infinity();
    int bestIndex = -1;

    for (std::size_t i = 0; i < enemies.size(); ++i) {
        const Enemy& enemy = enemies[i];
        if (!enemy.active) continue;

        const float dx = enemy.position.x - player.x;
        const float dy = enemy.position.y - player.y;
        const float distanceSquared = dx * dx + dy * dy;

        if (distanceSquared < bestDistanceSquared) {
            bestDistanceSquared = distanceSquared;
            bestIndex = static_cast<int>(i);
        }
    }
    return bestIndex;
}
