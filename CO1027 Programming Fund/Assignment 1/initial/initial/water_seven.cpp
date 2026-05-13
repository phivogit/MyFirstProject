#include "water_seven.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
//Task 0
bool readInput(
    const string &filename,
    char character[FIXED_CHARACTER][MAX_NAME], int hp[FIXED_CHARACTER], 
    int skill[FIXED_CHARACTER], int &shipHP, int &repairCost){
        ifstream opw_input(filename);
        if (!opw_input.is_open()) return false;
        int currentCharacterIndex = 0;
        while(opw_input >> character[currentCharacterIndex] >> hp[currentCharacterIndex] >> skill[currentCharacterIndex]) {
            if (hp[currentCharacterIndex] < 0) hp[currentCharacterIndex] = 0;
            if (skill[currentCharacterIndex] < 0) skill[currentCharacterIndex] = 0;
            if (strcmp(character[currentCharacterIndex], "GOING_MERRY") == 0) { 
                shipHP = hp[currentCharacterIndex];
                repairCost = skill[currentCharacterIndex];
            } else {
                bool found = 0;
                for (int i = 0; i < currentCharacterIndex; i++) {
                    if (strcmp(character[i], character[currentCharacterIndex]) == 0)
                    {
                        hp[i] = hp[currentCharacterIndex];
                        skill[i] = skill[currentCharacterIndex];
                        found = 1;
                        break;
                    }
                }
                if(!found) currentCharacterIndex++;
            }
        }
        return true;
}

// Task 1
int damageEvaluation(int shipHP, int repairCost){
    if (shipHP < 455) {
        int num = shipHP;
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        int sumPerfectNumber = 0;
        for (int i = 1; i <= (int)(sum/2); i++) {
            if (sum%i == 0) {
                sumPerfectNumber += i;
                if (sumPerfectNumber > sum) return repairCost;
            }
        }
        if (sumPerfectNumber==sum) return ceil((double)repairCost*1.5);
    }
    return repairCost;
}

// Task 2
int conflictSimulation(
    char character[FIXED_CHARACTER][MAX_NAME], int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER],
    int shipHP, int repairCost){
        int maxSteps = 10;
        int luffyIndex, usoppIndex;
        for (int i = 0; i < FIXED_CHARACTER; i++) {
            if (strcmp(character[i], "LUFFY")==0) luffyIndex = i;
            if (strcmp(character[i], "USOPP")==0) usoppIndex = i;
        }
        int conflictIndex = ceil(skill[luffyIndex] - skill[usoppIndex] + repairCost / 100.0 + (500 - shipHP) / 50.0);
        for (int rep = 0; rep < maxSteps; rep++) {
            int id = conflictIndex%6;
            if (id == 0) conflictIndex += 255;
            if (id == 1) conflictIndex += 20;
            if (id == 2) conflictIndex += 50;
            if (id == 3) conflictIndex += 70;
            if (id == 4) conflictIndex += 90;
            if (id == 5) conflictIndex += 100;
            if (conflictIndex >= 255) break;
        }
        return conflictIndex;
    }

// Task 3
void resolveDuel(
    char character[FIXED_CHARACTER][MAX_NAME], int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER],
    int conflictIndex, int repairCost, char duel[FIXED_CHARACTER][MAX_NAME]){
        int interventionCost[FIXED_CHARACTER-2];
        int crewMemberIndex[FIXED_CHARACTER-2];
        int U = 0;
        int luffyIndex;
        for (int member = 0, index = 0; member < FIXED_CHARACTER; member++) {
            if (strcmp(character[member], "USOPP") == 0) {
                U = skill[member] + conflictIndex/20 + repairCost/500;
            } else if (strcmp(character[member], "LUFFY") == 0) {
                luffyIndex = member;
            } else if (strcmp(character[member], "LUFFY") == 0 || strcmp(character[member], "USOPP") == 0 || strcmp(character[member], "GOING_MERRY") != 0) {
                interventionCost[index] = (hp[member] % 10) + 1;
                crewMemberIndex[index] = member;
                index++;
            }
        }
        int tempListIndex[FIXED_CHARACTER-2] = {-1, -1, -1, -1, -1};
        int tempListIndex2[FIXED_CHARACTER-2] = {-1, -1, -1, -1, -1};
        int tempSupportLevel = 0;
        int tempSupportLevel2 = 0;
        int tempIntCost= INT_MAX;
        int tempIntCost2 = 0;
        for (int caseNumber = 1; caseNumber < pow(2, 5); caseNumber++) {
            for (int extract = caseNumber, realIndex = 0, tempIndex = 0; extract > 0; extract /= 2, realIndex++) {
                while (strcmp(character[realIndex], "USOPP") == 0 || strcmp(character[realIndex], "LUFFY") == 0 || strcmp(character[realIndex], "GOING_MERRY") == 0) {
                    realIndex++;
                    if (realIndex >= FIXED_CHARACTER) break;
                }
                int extracted = extract % 2;
                if (extracted == 1) {
                    tempListIndex2[tempIndex] = realIndex;
                    tempSupportLevel2 += skill[realIndex];
                    tempIntCost2 += (hp[realIndex] % 10) +1;
                    tempIndex++;
                }
            }
            if (caseNumber == 1 && (skill[luffyIndex] + tempSupportLevel2) >= U) {
                tempIntCost = tempIntCost2;
                tempSupportLevel = tempSupportLevel2;
                for (int i = 0, index = 0; i < FIXED_CHARACTER - 2; i++) {
                    if (tempListIndex2[i] != -1)
                    {
                        tempListIndex[index] = tempListIndex2[i];
                        index++;
                    }
                }
            }
            else if ((skill[luffyIndex] + tempSupportLevel2) >= U && tempIntCost2 < tempIntCost) {
                tempIntCost = tempIntCost2;
                tempSupportLevel = tempSupportLevel2;
                for (int i = 0, index = 0; i < FIXED_CHARACTER - 2; i++) {
                    if (tempListIndex2[i] != -1)
                    {
                        tempListIndex[index] = tempListIndex2[i];
                        index++;
                    }
                }
            }
            tempIntCost2 = 0;
            tempSupportLevel2 = 0;
            for (int i = 0; i < FIXED_CHARACTER - 2; i++) {
                tempListIndex2[i] = -1;
            }
        }
        for (int i = 0, index = 0; i < FIXED_CHARACTER - 2; i++) {
            if (tempListIndex[i] != -1) {
                strcpy(duel[index], character[tempListIndex[i]]);
                index++;
            }
        }
    }

// Task 4
void decodeCP9Message(char character[FIXED_CHARACTER][MAX_NAME], 
    int hp[FIXED_CHARACTER], int skill[FIXED_CHARACTER], int conflictIndex, 
    int repairCost, char cipherText[], char resultText[]){
        int length = strlen(cipherText);
        int separatorIndex = 0;
        int abc = 0;
        while (abc >= 0) {
            if (cipherText[abc] == '#') {
                if (cipherText[abc+1] == '#') continue;
                else {
                    separatorIndex = abc;
                    break;
                }
                
            }
            abc++;
        }

        char message[200];
        for (int i = 0; i < separatorIndex; i++) {
            message[i] = cipherText[i];
        }
        message[separatorIndex] = '\0';

        int checkSum1 = (cipherText[separatorIndex + 1] - 48) * 10 + (cipherText[separatorIndex + 2] - 48);

        int checkSum2 = 0;
        for (int i = 0; i < separatorIndex; i++) {
            checkSum2 += message[i];
        }
        checkSum2 %= 100;

        if (checkSum1 != checkSum2) {
            strcpy(resultText, "");
            return;
        }
        int key = (conflictIndex + repairCost) % 26;
        int B = (key % 5) + 4;
        int msgLen = strlen(message);

        for (int i = 0; i < msgLen; i += B)
        {
            int left = i;
            int right = i + B - 1;
            if (right >= msgLen) {
                right = msgLen - 1;
            }
            while (left < right) {
                char temp = message[left];
                message[left] = message[right];
                message[right] = temp;
                left++;
                right--;
            }
        }

        for (int i = 0; i < strlen(message); i++) {
            if (message[i] >= 'A' && message[i] <= 'Z') {
                if (message[i] - 'A' - key < 0) message[i] = message[i] - key + 26;
                else message[i] = message[i] - key;
            }
            else if (message[i] >= 'a' && message[i] <= 'z') {
                if (message[i] - 'a' - key < 0) message[i] = message[i] - key + 26;
                else message[i] = message[i] - key;
            }
            else if (message[i] >= '0' && message[i] <= '9') {
                if (message[i] - '0' - (key % 10) < 0) message[i] = message[i] - (key % 10) + 10;
                else message[i] -= (key % 10);
            }
        }

        strcpy(resultText, message);
        if (strstr(message, "CP9") != nullptr || strstr(message, "ENIESLOBBY") != nullptr) {
            strcat(resultText, "_TRUE");
        } else {
            strcat(resultText, "_FALSE");
        }
    }

// Task 5
int analyzeDangerLimit(int grid[MAX_GRID][MAX_GRID], int rows, int cols) {
    int maxRowSum = -1;
    int maxCell = -1;
    for (int i = 0; i < rows; ++i) {
        int currentRowSum = 0;
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] > maxCell) {
                maxCell = grid[i][j];
            }
            if (grid[i][j] != -1) {
                currentRowSum += grid[i][j];
            }
        }
        if (currentRowSum > maxRowSum) {
            maxRowSum = currentRowSum;
        }
    }
    return maxRowSum + maxCell;
}


bool evaluateRoute(int grid[MAX_GRID][MAX_GRID], int rows, int cols, int dangerLimit){
    if (grid[0][0] == -1 || grid[rows - 1][cols - 1] == -1) {
        return false;
    }
    int dp[MAX_GRID][MAX_GRID];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = grid[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == -1 || dp[i][j] == INT_MAX) {
                continue;
            }
            if (i + 1 < rows && grid[i + 1][j] != -1) {
                if (dp[i][j] + grid[i + 1][j] < dp[i + 1][j]) {
                    dp[i + 1][j] = dp[i][j] + grid[i + 1][j];
                }
            }
            if (j + 1 < cols && grid[i][j + 1] != -1) {
                if (dp[i][j] + grid[i][j + 1] < dp[i][j + 1]) {
                    dp[i][j + 1] = dp[i][j] + grid[i][j + 1];
                }
            }
        }
    }
    if (dp[rows - 1][cols - 1] != INT_MAX && dp[rows - 1][cols - 1] <= dangerLimit) {
        return true;
    }
    return false;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
