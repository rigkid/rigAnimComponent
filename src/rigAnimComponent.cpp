#include "rigAnimComponent.h"

#include "core/RigKitEngine.h"
#include "core/pack/PackRegistry.h"
#include "ecs/MEcs.h"
#include "CAnimBind.h"
#include "CAnimClip.h"
#include "CAnimSkeleton.h"
#include "CAnimSkin.h"
#include "CAnimTrack.h"
#include "CModBinding.h"
#include "CModLfo.h"
#include "CTween.h"

#include <spdlog/spdlog.h>

namespace rigkit {

rigAnimComponent::rigAnimComponent() : IPack("rigAnimComponent") {}

bool rigAnimComponent::init() {
	spdlog::info("[rigAnimComponent] init (data-only)");
	return true;
}

void rigAnimComponent::setup() {
	auto* engine = getEngine();
	if (!engine) {
		return;
	}
	auto* ecs = engine->getECSManager();
	if (!ecs) {
		return;
	}

	ecs->registerComponent<ecs::CModLfo>("ModLfo", true);
	ecs->registerComponent<ecs::CModBinding>("ModBinding", true);
	ecs->registerComponent<ecs::CTween>("Tween", true);
	ecs->registerComponent<ecs::CAnimSkeleton>("AnimSkeleton", true);
	ecs->registerComponent<ecs::CAnimBind>("AnimBind", true);
	ecs->registerComponent<ecs::CAnimSkin>("AnimSkin", true);
	ecs->registerComponent<ecs::CAnimClip>("AnimClip", true);
	ecs->registerComponent<ecs::CAnimTrack>("AnimTrack", true);
	spdlog::info("[rigAnimComponent] announced anim PODs");
}

} // namespace rigkit

namespace {
struct rigAnimComponentRegistrar {
	rigAnimComponentRegistrar() {
		rigkit::PackRegistry::instance().addFactory("rigAnimComponent", []() {
			return std::shared_ptr<rigkit::IPack>(std::make_shared<rigkit::rigAnimComponent>());
		});
	}
};
static rigAnimComponentRegistrar rigAnimComponent_auto_reg;
} // namespace
