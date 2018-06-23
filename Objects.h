#include "SDK.h"

enum Trilogy {
	Prequil,
	Original,
	NewEra,
	None
};

class MapObject {
public:
	MapObject(std::string m_baseName, std::string m_mapTitle, Trilogy m_trilogy, std::string m_imageName)
		: baseName(m_baseName), mapTitle(m_mapTitle), trilogy(m_trilogy), imageName(m_imageName) {}
	std::string baseName;
	std::string mapTitle;
	Trilogy trilogy;
	std::string imageName;
};

class PlayerObject {
public:
	std::string baseName;
	std::string playerName;
	std::string imageName;
	PlayerObject(std::string m_baseName, std::string m_playerName, std::string m_imageName)
		: baseName(m_baseName), playerName(m_playerName), imageName(m_imageName) {}
};


class ModeObject {
public:
	std::string baseName;
	std::string gameName;
	ModeObject(std::string m_baseName, std::string m_gameName)
		: baseName(m_baseName), gameName(m_gameName) {}
};

std::vector<MapObject> maplist = {
	//Menus
	MapObject("Levels/FrontEnd/FrontEnd", "In Main Menu", Trilogy::None, "\0"),
	MapObject("\0", "In Loading Screen", Trilogy::None, "\0"),

	//galactic assault
	MapObject("Levels/MP/Tatooine_01/Tatooine_01", "Mos Eisley, Tatooine", Trilogy::Original, "tatooine"),
	MapObject("S2_2/Levels/JabbasPalace_01/JabbasPalace_01", "Jabbas Palace, Tatooine", Trilogy::Original, "tatooine"),
	MapObject("Levels/MP/Yavin_01/Yavin_01", "The Greate Temple, Yavin IV", Trilogy::Original, "yavin4"),
	MapObject("Levels/MP/Kamino_01/Kamino_01", "Cloning Facility, Kamino", Trilogy::Prequil, "kamino"),
	MapObject("Levels/MP/Naboo_01/Naboo_01", "Theed, Naboo", Trilogy::Prequil, "naboo"),
	MapObject("Levels/MP/StarKiller_01/StarKiller_01", "Command Center, Starkiller Base", Trilogy::NewEra, "starkillerbase"),
	MapObject("Levels/MP/Takodana_01/Takodana_01", "Maz's Castle, Takodana", Trilogy::NewEra, "takodana"),
	MapObject("Levels/MP/Endor_01/Endor_01", "Research Station 9, Endor", Trilogy::Original, "endor"),
	MapObject("Levels/MP/Kashyyyk_01/Kashyyyk_01", "Kachirho Beach, Kashyyyk", Trilogy::Prequil, "kashyyyk"),
	MapObject("Levels/MP/Jakku_01/Jakku_01", "The Graveyard, Jakku", Trilogy::NewEra, "jakku"),
	MapObject("Levels/MP/DeathStar02_01/DeathStar02_01", "Command Sector North, Death Star II", Trilogy::Original, "deathstar2"),
	MapObject("Levels/MP/Hoth_01/Hoth_01", "Outpost Delta, Hoth", Trilogy::Original, "hoth"),
	MapObject("S1/Levels/Crait_01/Crait_01", "Abandoned Rebel Outpost, Crait", Trilogy::NewEra, "crait"),
	MapObject("S2/Levels/CloudCity_01/CloudCity_01", "Administrator's Palace, Bespin", Trilogy::Original , "bespin"),
	MapObject("S3/Levels/Kessel_01/Kessel_01", "Coaxium Mine, Kessel", Trilogy::Original , "kessel"),

	//starfighter assault
	MapObject("Levels/Space/SB_Kamino_01/SB_Kamino_01", "Kamino - Research Outpost", Trilogy::Prequil, "kamino"),
	MapObject("Levels/Space/SB_DroidBattleShip_01/SB_DroidBattleShip_01", "Ryloth - Lucrehulk-Class Battleship", Trilogy::Prequil, "ryloth"),
	MapObject("Levels/Space/SB_Resurgent_01/SB_Resurgent_01", "Unknown Regions - Resurgent-Class Star Destroyer", Trilogy::NewEra, "unknown"),
	MapObject("Levels/Space/SB_Fondor_01/SB_Fondor_01", "Fondor - Imperial Shipyard", Trilogy::Original, "fondor"),
	MapObject("S1/Levels/Space/SB_SpaceBear_01/SB_SpaceBear_01", "D'Qar - Resistance Base Evacuation", Trilogy::NewEra, "yavin4"),
	MapObject("Levels/Space/SB_Endor_01/SB_Endor_01", "Endor - Death Star Debris", Trilogy::Original, "endor")
};

std::vector<PlayerObject> playerList = {
	//shared
	PlayerObject("Gameplay/Characters/StormTrooperShared", "Soldier", "orig"),
	PlayerObject("Gameplay/Characters/StormTrooperShared_B1", "Soldier", "preq"),

	//enforcer
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_WookieWarrior", "Wookie Warrior", "wookiewarrior"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_Flametrooper", "Flame Trooper", "flametrooper"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_B2", "B2 Battle Droid", "b2"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_DeathTrooper", "Death Trooper", "deathtrooper"),

	//aerial
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_Clone_JumpTrooper", "Jet Trooper", "clonejettrooper"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_RebelJumpTrooper", "Jump Trooper", "rebelrockettrooper"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_FirstOrder_JumpTrooper", "Jump Trooper", "firstorderrockettrooper"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_Special_JumpTrooper", "Rocket Trooper", "skytrooper"),
	PlayerObject("Gameplay/Characters/heroes/Specializations/Hero_Weapon_B2RP", "B2-RP Rocket Droid", "b2rprocketdroid"),

	//heroes
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Luke", "Luke Skywalker", "lukeskywalker"),	// note the difference in capitolization...
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Lando", "Lando Calrissian", "landocalrissian"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Leia", "Leia Organa", "leiaorgana"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Rey", "Rey", "rey"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Hansolo", "Han Solo", "hansolo"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Yoda", "Yoda", "yoda"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Chewbacca", "Chewbacca", "chewbacca"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Finn", "Finn" , "finn"),

	//villians
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_BobaFett", "Boba Fett" , "bobafett"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_KyloRen", "Kylo Ren", "kyloren"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Maul", "Darth Maul", "darthmaul"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Bossk", "Bossk", "bossk"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_DarthVader", "Darth Vader", "darthvader"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Iden", "Iden Versio", "idenversio"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Lightsaber_Emperor", "Emperor Palpatine", "palpatine"),
	PlayerObject("Gameplay/Characters/Heroes/Specializations/Hero_Weapon_Phasma", "Captain Phasma", "phasma"),

	//vehicles
	PlayerObject("Gameplay/Vehicles/Air/AirSpeeder/Vehicle_Air_AirSpeeder", "Air Speeder",  "airspeeder"),
	PlayerObject("Gameplay/Vehicles/Air/AWing/Vehicle_Air_AWing", "A-Wing",  "awing"),
	PlayerObject("Gameplay/Vehicles/Air/AWingRZ3/Vehicle_Air_AWingRZ3", "A-Wing RZ-2",  "honeybee"),
	PlayerObject("Gameplay/Vehicles/Air/BTLYwing/Vehicle_Air_BTLYWing", "BTL-B Y-Wing",  "btlbywing"),
	PlayerObject("Gameplay/Vehicles/Air/Ywing/Vehicle_Air_YWing", "Y-Wing",  "btlaywing"),
	PlayerObject("Gameplay/Vehicles/Air/XWing_T65/Vehicle_Air_XWing_T65", "X-Wing",  "xwingt65"),
	PlayerObject("Gameplay/Vehicles/Air/DroidTriFighter/Vehicle_Air_DroidTriFighter", "Tri-Fighter",  "trifighter"),
	PlayerObject("Gameplay/Vehicles/Air/VultureDroid/Vehicle_Air_VultureDroid", "Vulture Droid",  "vulturedroid"),
	PlayerObject("Gameplay/Vehicles/Air/HyeneBomber/Vehicle_Air_HyeneBomber", "Hyene Bomber",  "hyenabomber"),
	PlayerObject("Gameplay/Vehicles/Air/HyenaBomber/Vehicle_Air_HyenaBomber", "Hyene Bomber",  "hyenabomber"), //excelent naming conventions DICE
	PlayerObject("Gameplay/Vehicles/Air/ARC170/Vehicle_Air_ARC170", "ARC170",  "arc170"),
	PlayerObject("Gameplay/Vehicles/Air/Vwing/Vehicle_Air_Vwing", "V-Wing",  "vwing"),
	PlayerObject("Gameplay/Vehicles/Air/TieFighterSpecialForces/Vehicle_Air_TieFighterSpecialForces", "Special Forces Tie Fighter",  "tiefightersf"),
	PlayerObject("Gameplay/Vehicles/Air/TieFighterFirstOrder/Vehicle_Air_TieFighterFirstOrder", "First Order Tie Fighter",  "tiefighterfo"),
	PlayerObject("Gameplay/Vehicles/Air/XWing_T70/Vehicle_Air_XWing_T70", "T70 X-Wing",  "xwingt70"),
	PlayerObject("Gameplay/Vehicles/Air/TieFighter/Vehicle_Air_TieFighter", "Tie Fighter",  "tiefighter"),
	PlayerObject("Gameplay/Vehicles/Air/TieInterceptor/Vehicle_Air_TieInterceptor", "Tie Interceptor",  "tieinterceptor"),
	PlayerObject("Gameplay/Vehicles/Air/TieBomber/Vehicle_Air_TieBomber", "Tie Bomber",  "tiebomber"),

	//hero vehicles
	PlayerObject("Gameplay/Vehicles/Air/YodasStarfighter/Vehicle_Air_YodasStarfighter", "Yoda's Starfighter", "yodastarfighter"),
	PlayerObject("Gameplay/Vehicles/Air/Scimitar/Vehicle_Air_Scimitar", "Darth Maul's Scimitar", "scimitar"),
	PlayerObject("Gameplay/Vehicles/Air/Slave1/Vehicle_Air_Slave1", "Boba Fett's Slave 1", "slave1"),
	PlayerObject("Gameplay/Vehicles/Air/TieAdvancedX1/Vehicle_Air_TieAdvancedX1", "Darth Vader's Tie Advanced X1", "tieadvanced"),
	PlayerObject("Gameplay/Vehicles/Air/GrizzlyBoat/Vehicle_Air_GrizzlyBoat", "Kylo Ren's Tie Silencer", "grizzlyboat"),
	PlayerObject("S1/Gameplay/Vehicles/Air/IdensTIE/Vehicle_Air_IdensTIE", "Iden Versio's Tie Fighter", "tiefighterfo")
};

std::vector<ModeObject> modeList = {
	ModeObject("SkirmishOnslaught", "Arcade Onslaught"),
	ModeObject("SkirmishBlast", "Arcade Blast"),
	ModeObject("SkirmishSpaceBlast", "Arcade Starfighter Blast"),
	ModeObject("SkirmishSpaceOnslaught", "Arcade Starfighter Onslaught"),
	ModeObject("PlanetaryBattles", "Galactic Assault"),
	ModeObject("SpaceBattle", "Starfighter Assault"),
	ModeObject("PlanetaryMissions", "Strike"),
	ModeObject("HeroesVersusVillains", "Heroes VS Villains"),
	ModeObject("Mode6", "Hero Showdown"),
	ModeObject("Blast", "Blast"),
	ModeObject("Mode5", "Extraction"),
	ModeObject("ModeC", "Jetpack Cargo")
}; 
