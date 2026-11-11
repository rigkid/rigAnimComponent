#pragma once

#include <string>
#include <vector>

#include "ecs/PropertyReflection.h"

namespace rigkit {
namespace ecs {

/**
 * @brief A span of sampled motion. Speaks `rig.anim.clip`.
 * @details Samples live on `CAnimTrack` entities. `elapsed` is host playback cache.
 */
struct CAnimClip {
	float duration = 1.f;
	std::string wrap = "once"; ///< once | loop | ping-pong
	float elapsed = 0.f;
	bool playing = true;

	std::vector<sProp> GetProperties() {
		return {{0, "Duration", EPT_FLOAT, &duration},
				{1, "Wrap", EPT_STRING, &wrap},
				{2, "Elapsed", EPT_FLOAT, &elapsed},
				{3, "Playing", EPT_BOOL, &playing}};
	}
};

} // namespace ecs
} // namespace rigkit
