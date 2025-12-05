#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int slayerLevel, hp, hasTalisman, demonPresence, demonRank, allyCount, bossHP, totalDamage, specialMoveReady;
    double breathingMastery, swordSharpness;
    char timeOfDay;
    cin >> slayerLevel >> hp >> breathingMastery >> hasTalisman >> timeOfDay >> demonPresence >> demonRank >> swordSharpness >> allyCount >> bossHP >> totalDamage >> specialMoveReady;
    
    double power = slayerLevel*10 + hp/10 + breathingMastery*50;
    string rank = (power<80)? "Novice" : (power<120)? "Elite" : "Hashira";
    cout << "[Scene 1] Rank: " << rank << " (power = " << fixed << setprecision(1) << power << ")\n";

    cout << "[Scene 2] ";
    if (hasTalisman) {
        if (timeOfDay == 'N' && demonPresence == 1) {
            cout << "Open silently.\n";
        } else if (timeOfDay != 'D' && timeOfDay != 'N') {
            cout << "Warning: invalid timeOfDay.\n";
        } else {
            cout << "Open cautiously.\n";
        }
    } else cout << "Denied: No talisman.\n";

    cout << "[Scene 3] ";
    double adv = (101 - demonRank*15) + swordSharpness*0.4 + allyCount*5;
    if (adv >= 100) cout << "Engage head-on ";
    else if (adv > 60) cout << "Harass and probe ";
    else cout << "Retreat and regroup ";
    cout << "(adv = " << fixed << setprecision(1) << adv << ")\n";

    cout << "[Scene 4] ";
    double finalHP = bossHP - totalDamage;
    if (finalHP <= 0) cout << "Boss defeated! (finalHP = 0)\n";
    else if (specialMoveReady == 1 && finalHP <=50)
        cout << "Use special move to finish! (finalHP = " << fixed << setprecision(0) << finalHP << ")\n";
    else
        cout << "Withdraw to heal. " << "(finalHP = " << fixed << setprecision(0) << finalHP << ")";
}