#include <iostream>
#include <string>
using namespace std;
int computeStamina(string moves, int hp, double breathingMastery)
{
    double totalReduction = 0.0;
    for (unsigned int i = 0; i < moves.length(); i++) {
        if (moves[i] == 'A') totalReduction += 1.0 - breathingMastery;
        else if (moves[i] == 'B') totalReduction += 2.0 - breathingMastery;
        else if (moves[i] == 'C') totalReduction += 3.0 - breathingMastery;
    }
    double remaining = hp - totalReduction;
    if (remaining > 0) return remaining;
    else return 0;
}
int main() {
    cout << computeStamina("ABCAAC", 100, 0.5) << '\n';
    cout << computeStamina("ABCABCABC", 99, 0.5) << '\n';
    cout << computeStamina("B", 1000, 0.0);
    // 1. Example Cases
    cout << computeStamina("ABCAAC", 100, 0.5) << endl;   // Expected: 92
    cout << computeStamina("ABCABCABC", 99, 0.5) << endl; // Expected: 85
    cout << computeStamina("B", 1000, 0.0) << endl;       // Expected: 998

    // 2. Edge Case: No Mastery (Full Cost)
    cout << computeStamina("ABC", 10, 0.0) << endl; // Expected: 4 (10 - 6)

    // 3. Edge Case: Max Mastery (Zero Cost for 'A')
    cout << computeStamina("AAAA", 10, 1.0) << endl; // Expected: 10 (10 - 0)

    // 4. Edge Case: Negative Stamina (Should return 0)
    cout << computeStamina("C", 2, 0.0) << endl; // Expected: 0 (2 - 3 = -1 -> 0)

    // 5. Edge Case: Exact Zero Stamina
    cout << computeStamina("B", 2, 0.0) << endl; // Expected: 0 (2 - 2 = 0)

    // 6. Edge Case: Fractional Result (Truncation Check)
    cout << computeStamina("A", 5, 0.1) << endl; // Expected: 4 (5 - 0.9 = 4.1 -> 4)

    // 7. Edge Case: Rounding Logic
    // Costs: A(0.7) + B(1.7) + C(2.7) = 5.1
    // Rem: 10 - 5.1 = 4.9 -> Truncates to 4
    cout << computeStamina("ABC", 10, 0.3) << endl; // Expected: 4
}