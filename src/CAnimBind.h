#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <vector>

#include "ecs/PropertyReflection.h"

namespace rigkit {
namespace ecs {

/**
 * @brief Rest pose of one bone. Speaks `rig.anim.bind`.
 * @details Absent channels match the bone's `CTransform` at save.
 */
struct CAnimBind {
	bool hasPosition = false;
	bool hasRotation = false;
	bool hasScale = false;
	glm::vec3 position{0.f};
	glm::quat rotation{1.f, 0.f, 0.f, 0.f};
	glm::vec3 scale{1.f};

	std::vector<sProp> GetProperties() {
		return {{0, "Has position", EPT_BOOL, &hasPosition},
				{1, "Has rotation", EPT_BOOL, &hasRotation},
				{2, "Has scale", EPT_BOOL, &hasScale}};
	}
};

} // namespace ecs
} // namespace rigkit
