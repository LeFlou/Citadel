#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

#include "HumanPlayer.h" // for static_assert
#include "RobotPlayer.h" // for static_assert
#include "CharacterDeck.h"
#include "DistrictDeck.h"

namespace Citadel
{
    class Boardgame
    {
    public:
        Boardgame() = default;
        ~Boardgame() = default;

        const Edition GetEdition() const
        {
            return edition_;
        }

        void StartGame(const Edition edition);

        template <typename PlayerType>
        void AddPlayer(const std::string& name)
        {
            static_assert(std::is_same<PlayerType, HumanPlayer>::value ||
                std::is_same<PlayerType, RobotPlayer>::value,
                "PlayerType must be HumanPlayer or RobotPlayer");
            auto newPlayer = std::unique_ptr<PlayerType>(new PlayerType(name));
            playerById_.insert(std::make_pair(newPlayer->GetID(), std::move(newPlayer)));
        }

    private:
        void SetEdition(const Edition edition)
        {
            edition_ = edition;
        }

        // Build a vector of readonly players
        std::vector<const Player*> GetOpponentPlayers(const int playerID);

        bool TakeGoldCoins(Player* player);
        bool WatchPickDistrict(Player* player);
        bool BuildDistrict(Player* player);
        bool UseMagicPower(Player* player);
        bool EarnDistrictIncome(Player* player);

        void ActionStepTransition(Player* player);
        void BuildStepTransition(Player* player);
        void MagicPowerStepTransition(Player* player);
        void DistrictIncomeStepTransition(Player* player);

        // Transfer district cards to specific player
        void TransferDistrictCards(const size_t numberOfCards, Player* player);

        // Returns player id
        int DecideWhoStarts();

        void StartRound(const Edition edition);

        // Round Step 1
        void RemoveCharactersStep(const Edition edition);

        // Round Step 2
        void ChooseCharactersStep(const Edition edition);

        // Round Step 3
        void PlayerTurnsStep(const Edition edition);
        // Sub functions
        bool CanUseMagicPower(const Character character) const;
        bool AskCharacterTarget(Player* player, Character& victim);
        bool AssassinMagicPower(Player* player);
        bool ThiefMagicPower(Player* player);
        bool MagicianMagicPower(Player* player);
        bool MagicianExchangeFromPlayer(Player* player);
        bool MagicianExchangeFromDistrictDeck(Player* player);
        bool WarlordMagicPower(Player* player);
        void PlayerTurn(Player* player);

        bool IsGameEnded() const;
        void ComputeScores();

        Edition edition_ = Edition::UNINITIALIZED;
        size_t currentRound_ = 0;
        int startingPlayer_ = 0;
        int currentPlayer_ = 0;
        int nextStartingPlayer_ = 0;
        int firstPlayerEndingGame = -1;

        Character murderedCharacter_ = Character::UNINITIALIZED;
        Character stolenCharacter_ = Character::UNINITIALIZED;

        size_t numberOfDistrictsToWin_ = 8;

        CharacterDeck characterDeck_;
        DistrictDeck districtDeck_;
        std::unordered_map<int, std::unique_ptr<Player>> playerById_;
        std::map<Character, Player*> playerByCharacter_;
    };
}