#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(AutoDecorMenu, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        auto button = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName(
                "GJ_createBtn_001.png"
            ),
            this,
            menu_selector(AutoDecorMenu::onAutoDecor)
        );

        auto menu = this->getChildByID("bottom-menu");

        if (menu && button) {
            button->setID("auto-decor-button"_spr);
            menu->addChild(button);
            menu->updateLayout();
        }

        return true;
    }

    void onAutoDecor(CCObject*) {
        FLAlertLayer::create(
            "Auto Decor",
            "Auto Decor is loaded! Decoration features are coming soon.",
            "OK"
        )->show();
    }
};
