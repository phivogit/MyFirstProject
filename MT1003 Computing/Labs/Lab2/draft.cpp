#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    int slayerLevel, hp, hasTalisman, demonPresence, demonRank, allyCount, bossHp, totalDamage, specialMoveReady;
    double swordSharpness, power, adv, finalHp, breathingMastery;
    char timeOfDay;
    cin >> slayerLevel >> hp >> breathingMastery >> hasTalisman >> timeOfDay >> demonPresence >> demonRank >> swordSharpness >> allyCount >> bossHp >> totalDamage >> specialMoveReady;
    power = slayerLevel * 10 + hp / 10 + breathingMastery * 50;
    if (power >= 120)
    {
        cout << setprecision(1) << fixed << "[Scene 1] Rank: Hashira (power = " << power << ")" << '\n';
    }
    else if (power >= 80 && power < 120)
    {
        cout << setprecision(1) << fixed << "[Scene 1] Rank: Elite (power = " << power << ")" << '\n';
    }
    else
    {
        cout << setprecision(1) << fixed << "[Scene 1] Rank: Novice (power = " << power << ")" << '\n';
    }

    if (hasTalisman)
    {
        if (timeOfDay != 'D' && timeOfDay != 'N')
        {
            cout << "[Scene 2] Warning: invalid timeOfDay." << '\n';
        }
        else if (timeOfDay == 'N' && demonPresence == 1)
        {
            cout << "[Scene 2] Open silently." << '\n';
        } else {
            cout << "[Scene 2] Open cautiously." << '\n';
        }
    }
    else
    {
        cout << "[Scene 2] Denied: No talisman." << '\n';
    }

    adv = (101 - demonRank * 15) + swordSharpness * 0.4 + allyCount * 5;
    if (adv >= 100)
    {
        cout << setprecision(1) << fixed << "[Scene 3] Engage head-on (adv = " << adv << ")" << '\n';
    }
    else if (adv >= 60 && adv < 100)
    {
        cout << setprecision(1) << fixed << "[Scene 3] Harass and probe (adv = " << adv << ")" << '\n';
    }
    else
    {
        cout << setprecision(1) << fixed << "[Scene 3] Retreat and regroup (adv = " << adv << ")" << '\n';
    }
    finalHp = bossHp - totalDamage;
    if (finalHp <= 0)
    {
        cout << "[Scene 4] Boss defeated! (finalHP = 0)";
    }
    else if (finalHp > 0 && specialMoveReady == 1 && finalHp <= 50)
    {
        cout << "[Scene 4] Use special move to finish! (finalHP = " << setprecision(0) << fixed << finalHp << ")";
    }
    else
    {
        cout << "[Scene 4] Withdraw to heal. (finalHP = " << fixed << setprecision(0) << finalHp << ")";
    }
    return 0;
}
