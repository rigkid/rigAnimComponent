#pragma once

#include <entt/entt.hpp>
#include <vector>

#include "ecs/PropertyReflection.h"

namespace rigkit {
namespace ecs {

/**
 * @brief Ordered bones. Speaks `rig.anim.skeleton`.
 * @details Each bone is its own entity (`CTransform` pose, optional `CAnimBind` rest).
 */
struct CAnimSkeleton {
	entt::entity root{entt::null};
	std::vector<entt::entity> bones;

	static constexpr bool kNoProperties = true;
};

} // namespace ecs
} // namespace rigkit
