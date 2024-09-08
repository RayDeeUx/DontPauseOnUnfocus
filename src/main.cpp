#include <Geode/modify/AppDelegate.hpp>

using namespace geode::prelude;

class $modify(MyAppDelegate, AppDelegate) {
	auto getPauseLayer() {
		return getChildOfType<PauseLayer>(CCDirector::get()->getRunningScene(), 0);
	}
	void applicationWillResignActive() {
		AppDelegate::applicationWillResignActive();
		if (!Mod::get()->getSettingValue<bool>("enabled")) return;
		if (const auto pauseLayer = getPauseLayer()) return pauseLayer->onResume(nullptr);
	}
	void applicationDidEnterBackground() {
		AppDelegate::applicationDidEnterBackground();
		if (!Mod::get()->getSettingValue<bool>("enabled")) return;
		if (const auto pauseLayer = getPauseLayer()) return pauseLayer->onResume(nullptr);
	}
};