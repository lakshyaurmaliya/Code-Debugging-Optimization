#include <cassert>
#include <iostream>
#include <vector>
#include "TargetSelector.h"

int main() {
    const Vec2 player{0.0f, 0.0f};
    const std::vector<Enemy> enemies{
        {{5.0f, 0.0f}, true}, {{0.0f, 2.0f}, true}, {{1.0f, 0.0f}, false}
    };
    assert(findNearestEnemy(player, enemies) == 1);

    const std::vector<Enemy> inactive{{{1.0f, 1.0f}, false}};
    assert(findNearestEnemy(player, inactive) == -1);

    const std::vector<Enemy> empty;
    assert(findNearestEnemy(player, empty) == -1);

    const std::vector<Enemy> one{{{3.0f, 4.0f}, true}};
    assert(findNearestEnemy(player, one) == 0);

    std::cout << "All target-selector tests passed.\\n";
}
