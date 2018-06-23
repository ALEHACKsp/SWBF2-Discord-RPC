#include "Objects.h"

char* TranslateMode(char* inchar) {
	for (int i = 0; i < modeList.size(); i++) {
		if (strcmp(inchar, modeList[i].baseName.c_str()) == 0) {
			return (char*)modeList[i].gameName.c_str();
		}
	}
	return (char*)"\0";
}


char* TranslateLevel(char* inchar) {
	for (int i = 0; i < maplist.size(); i++) {
		if (strcmp(inchar, maplist[i].baseName.c_str()) == 0) {
			return (char*)maplist[i].mapTitle.c_str();
		}
	}
	return (char*)"\0";
}

char* TranslateClass(char* inchar) {
	for (int i = 0; i < playerList.size(); i++) {
		if (strcmp(inchar, playerList[i].baseName.c_str()) == 0) {
			return (char*)playerList[i].playerName.c_str();
		}
	}
	//	return (char*)"\0";
	return inchar;
}

char* TranslateImage(char* map, int TeamID, char* inchar) {
	for (int i = 0; i < playerList.size(); i++) {
		char* str = new char[128];
		for (int w = 0; w < maplist.size(); w++) {
			if (strcmp(TranslateClass(inchar), "Soldier") == 0) {
				if (maplist[w].baseName != map) continue;
				if (maplist[w].trilogy == Trilogy::Prequil) {
					strcpy(str, (TeamID == 1) ? "republic" : "cis");
					return str;
				}
				if (maplist[w].trilogy == Trilogy::Original) {
					strcpy(str, (TeamID == 1) ? "rebels" : "empire");
					return str;
				}
				if (maplist[w].trilogy == Trilogy::NewEra) {
					strcpy(str, (TeamID == 1) ? "rebels" : "firstorder");
					return str;
				}
			}
		}
		if (strcmp(inchar, playerList[i].baseName.c_str()) == 0) {
			strcpy(str, playerList[i].imageName.c_str());
			return str;
		}
	}
	return (char*)"default";
}

char* GetFaction(char* map, int TeamID, char* classname) {
	if (TeamID == 0) return (char*)"\0";
	for (int i = 0; i < maplist.size(); i++) {
		if (strcmp(map, maplist[i].baseName.c_str()) == 0) {
			char* str = new char[128];
			if (strcmp(TranslateClass(classname), "Soldier") == 0) {

				if (maplist[i].trilogy == Trilogy::Prequil) {
					strcpy(str, (TeamID == 1) ? (char*)"Galactic Republic" : (char*)"Confederacy");
				}
				if (maplist[i].trilogy == Trilogy::Original) {
					strcpy(str, (TeamID == 1) ? (char*)"rebels" : (char*)"rebels");
				}
				if (maplist[i].trilogy == Trilogy::NewEra) {
					strcpy(str, (TeamID == 1) ? (char*)"Resistance" : (char*)"First Order");
				}
			}
			else {
				strcpy(str, TranslateClass(classname));
			}
			return str;
		}
		else {
			return TranslateClass(classname);
		}
	}
	return (char*)"\0";
}

char* TranslateLevelImage(const char* inchar) {
	for (int i = 0; i < maplist.size(); i++) {
		if (strcmp(inchar, maplist[i].mapTitle.c_str()) == 0) {
			if (strcmp(maplist[i].mapTitle.c_str(), "none") == 0) return(char*)"\0";
			return (char*)maplist[i].imageName.c_str();
		}
	}	return (char*)"\0";
}