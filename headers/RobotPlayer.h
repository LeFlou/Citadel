#pragma once

#include "Player.h"

namespace Citadel
{
    class RobotPlayer : public Player
    {
    public:
        RobotPlayer();
        RobotPlayer(const std::string& name);

#pragma region PURE VIRTUAL METHODS
        // Returns character picked to play
        virtual Character PickCharacter(const std::set<Character>& remainingCards) override;

        // Returns action to be taken
        virtual PlayerAction ChooseAction() override;

        // Watch proposed district cards and return selected card
        virtual District WatchAndChooseDistrictCard(const std::vector<District>& districts) override;

        // Returns district card id player wants to build
        virtual std::vector<District> ChooseDistrictCardsToBuild(const size_t authorizedBuilds) override;

        // Returns character targeted by assassination or theft
        virtual Character ChooseCharacterTarget(const std::set<Character>& opponents) override;

        // Returns opponent player id, current player wants to target
        virtual int ChoosePlayerTarget(std::vector<const Player*> opponents) override;

        // Returns a choice specific to Magician character
        virtual MagicianChoice MagicianDecision() override;
#pragma endregion
    };
}