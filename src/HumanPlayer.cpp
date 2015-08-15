#include "HumanPlayer.h"

namespace Citadel
{
    HumanPlayer::HumanPlayer()
    {
    }

    HumanPlayer::HumanPlayer(const std::string& name)
        : Player(name)
    {
    }

    // Returns character picked to play
    Character HumanPlayer::PickCharacter(const std::set<Character>& remainingCards)
    {
        assert(remainingCards.size() > 0);
        return *std::begin(remainingCards);
    }

    // Returns action to be taken
    PlayerAction HumanPlayer::ChooseAction()
    {
        assert(!"Boom");
        return PlayerAction::UNITIALIZED;
    }

    District HumanPlayer::WatchAndChooseDistrictCard(const std::vector<District>& districts)
    {
        assert(!"Boom");
        return District::UNINITIALIZED;
    }

    // Returns district card id player wants to build
    std::vector<District> HumanPlayer::ChooseDistrictCardsToBuild(const size_t authorizedBuilds)
    {
        assert(!"Boom");
        return std::vector<District>();
    }

    // Returns character targeted by assassination or theft
    Character HumanPlayer::ChooseCharacterTarget(const std::set<Character>& opponents)
    {
        assert(!"Boom");
        return Character::UNINITIALIZED;
    }

    // Returns opponent player id, current player wants to target
    int HumanPlayer::ChoosePlayerTarget(std::vector<const Player*> opponents)
    {
        assert(!"Boom");
        return -1;
    }

    // Returns a pair containing player id (self district destroy is tolerated) as key and destroyed district as value
    std::pair<int, District> HumanPlayer::ChoosePlayerDistrictTarget(std::vector<const Player*> players)
    {
        assert(!"Boom");
        return std::pair<int, District>(-1, District::UNINITIALIZED);
    }

    // Returns a choice specific to Magician character
    MagicianChoice HumanPlayer::MagicianDecision()
    {
        assert(!"Boom");
        return MagicianChoice::DO_NOTHING;
    }

    // Returns discarded districts to be replaced by equivalent number of cards from district deck
    std::vector<District> HumanPlayer::ChooseDistrictsCardsToSwap()
    {
        assert(!"Boom");
        return std::vector<District>();
    }
}