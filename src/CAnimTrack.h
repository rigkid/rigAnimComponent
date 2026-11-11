#pragma once

#include <cstdint>
#include <entt/entt.hpp>
#include <string>
#include <vector>

#include "ecs/PropertyReflection.h"

namespace rigkit {
namespace ecs {

/**
 * @brief Sampled keys for one property on one clip. Speaks `rig.anim.track`.
 * @details Stride 1 = float, 3 = vec3, 4 = quaternion (x,y,z,w). Evaluation is the host.
 */
struct CAnimTrack {
	entt::entity clip{entt::null};
	entt::entity target{entt::null};
	std::string propertyKey;
	std::vector<float> times;
	std::vector<float> values;
	int stride = 1;

	static constexpr bool kNoProperties = true;
};

} // namespace ecs
} // namespace rigkit
