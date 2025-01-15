#include <Geode/modify/AppDelegate.hpp>

using namespace geode::prelude;

class $modify(MyAppDelegate, AppDelegate) {
	static PauseLayer* getPauseLayer() {
		return CCDirector::get()->getRunningScene()->getChildByType<PauseLayer>(0);
	}
	void applicationWillResignActive() {
		if (getPauseLayer()) return AppDelegate::applicationWillResignActive();
		AppDelegate::applicationWillResignActive();
		if (!Mod::get()->getSettingValue<bool>("enabled")) return;
		if (const auto pauseLayer = getPauseLayer()) return pauseLayer->onResume(nullptr);
	}
	void applicationDidEnterBackground() {
		if (getPauseLayer()) return AppDelegate::applicationWillResignActive();
		AppDelegate::applicationDidEnterBackground();
		if (!Mod::get()->getSettingValue<bool>("enabled")) return;
		if (const auto pauseLayer = getPauseLayer()) return pauseLayer->onResume(nullptr);
	}
};