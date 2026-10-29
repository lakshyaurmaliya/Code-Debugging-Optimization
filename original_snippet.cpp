#include <cmath>
#include <vector>
struct Vec2 { float x, y; };
struct Enemy { Vec2 position; bool active; };

int findNearestEnemy(const Vec2& player, const std::vector<Enemy>& enemies) {
    float nearestDistance = 0.0f; // BUG: distances cannot be less than zero
    int nearestIndex = -1;
    for (int i = 0; i < static_cast<int>(enemies.size()); ++i) {
        if (!enemies[i].active) continue;
        float dx = enemies[i].position.x - player.x;
        float dy = enemies[i].position.y - player.y;
        float distance = std::sqrt(dx * dx + dy * dy); // unnecessary sqrt
        if (distance < nearestDistance) {
            nearestDistance = distance;
            nearestIndex = i;
        }
    }
    return nearestIndex;
}
