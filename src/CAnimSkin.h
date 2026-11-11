#pragma once

#include <cstdint>
#include <entt/entt.hpp>
#include <vector>

#include "ecs/PropertyReflection.h"

namespace rigkit {
namespace ecs {

/**
 * @brief Skin binding on a mesh entity. Speaks `rig.anim.skin`.
 * @details Four influences per vertex. Pose evaluation is host cache - do not
 * serialize a baked posed mesh beside the bind pose on `CMesh`.
 */
struct CAnimSkin {
	entt::entity skeleton{entt::null};
	std::vector<entt::entity> joints;
	/// Column-major 4x4 per joint (mesh space to joint space), 16 floats each.
	std::vector<float> inverseBind;
	std::vector<uint32_t> jointIndices;
	std::vector<float> jointWeights;

	static constexpr bool kNoProperties = true;
};

} // namespace ecs
} // namespace rigkit
