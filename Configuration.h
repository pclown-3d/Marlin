/**
 * Micrologiciel Marlin pour imprimante 3D 
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Basé sur Sprinter et grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * Ce programme est un logiciel libre: vous pouvez le redistribuer et / 
 * ou le modifier selon les termes de la licence publique générale GNU 
 * telle que publiée par la Free Software Foundation, soit la version 3 
 * de la licence, ou (à votre choix) toute version ultérieure.
 *
 * Ce programme est distribué dans l'espoir qu'il sera utile, mais 
 * SANS AUCUNE GARANTIE; sans même la garantie implicite de QUALITÉ 
 * MARCHANDE ou D'ADÉQUATION À UN USAGE PARTICULIER. Voir la Licence 
 * Publique Générale GNU pour plus de détails.
 *
 * Vous devriez avoir reçu une copie de la licence publique générale 
 * GNU avec ce programme. Sinon, voir <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Configuration.h
 *
 * Paramètres de base tels que:
 *
 * - Type d'électronique
 * - Type de capteur de température
 * - Géométrie de l'imprimante
 * - Configuration de fin de course
 * - Contrôleur LCD
 * - Fonctionnalités supplémentaires
 *
 * Les paramètres avancés se trouvent dans Configuration_adv.h
 *
 */
#define CONFIGURATION_H_VERSION 020004

//===========================================================================
//================================ commençons ===============================
//===========================================================================

/**
 * Voici quelques liens standard pour calibrer votre machine:
 *
 * http://reprap.org/wiki/Calibration
 * http://youtu.be/wAL9d7FgInk
 * http://calculator.josefprusa.cz
 * http://reprap.org/wiki/Triffid_Hunter%27s_Calibration_Guide
 * http://www.thingiverse.com/thing:5573
 * https://sites.google.com/site/repraplogphase/calibration-of-your-reprap
 * http://www.thingiverse.com/thing:298812
 */

//===========================================================================
//=========================== Imprimante DELTA ==============================
//===========================================================================
// Pour une imprimante Delta, commencez avec l'un des fichiers de configuration 
// dans le répertoire config / examples / delta et personnalisez pour votre machine.
//

//===========================================================================
//=========================== Imprimante SCARA ==============================
//===========================================================================
// Pour une imprimante SCARA, commencez avec les fichiers de configuration 
// dans config / examples / SCARA et personnalisez pour votre machine.
//

// @section info

// Informations sur l'auteur de cette version imprimées à l'hôte lors du démarrage et du M115
#define STRING_CONFIG_H_AUTHOR "(none, default config)" // Qui a fait les changements (Traduit par Pclown).
//#define CUSTOM_VERSION_FILE Version.h // Chemin depuis le répertoire racine (sans guillemets)

/**
 * *** VENDEURS VEUILLEZ LIRE ***
 *
 * Marlin vous permet d'ajouter une image de démarrage personnalisée pour les écrans
 * LCD graphiques. Avec cette option, Marlin affichera d'abord votre écran personnalisé, 
 * suivi du logo Marlin standard avec le numéro de version et l'URL Web.
 *
 * Nous vous encourageons à profiter de cette nouvelle fonctionnalité et nous 
 * vous demandons respectueusement de conserver l'écran de démarrage Marlin non modifié.
 */

// Affichez l'écran de démarrage Marlin au démarrage. ** ENABLE FOR PRODUCTION **
#define SHOW_BOOTSCREEN

// Affichez le bitmap dans Marlin / _Bootscreen.h au démarrage.
//#define SHOW_CUSTOM_BOOTSCREEN

// Affichez le bitmap dans Marlin / _Statusscreen.h sur l'écran d'état.
//#define CUSTOM_STATUS_SCREEN_IMAGE

// @section machine

/**
 * Sélectionnez le port série sur la carte à utiliser pour la communication avec l'hôte.
 * Cela permet la connexion d'adaptateurs sans fil (par exemple) à des broches de port autres que celles par défaut.
 * Remarque: Le premier port série (-1 ou 0) sera toujours utilisé par le chargeur de démarrage Arduino.
 *
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
#define SERIAL_PORT 0

/**
 * Sélectionnez un port série secondaire sur la carte à utiliser pour la communication avec l'hôte.
 * Cela permet la connexion d'adaptateurs sans fil (par exemple) à des broches de port autres que celles par défaut.
 * Le port série -1 est le port série émulé USB, s'il est disponible.
 *
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
//#define SERIAL_PORT_2 -1

/**
 * Ce paramètre détermine la vitesse de communication de l'imprimante.
 *
 * 250000 fonctionne dans la plupart des cas, mais vous pouvez essayer une vitesse 
 * inférieure si vous rencontrez fréquemment des abandons lors de l'impression.
 * Vous pouvez essayer jusqu'à 1000000 pour accélérer le transfert de fichiers SD.
 *
 * :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
 */
#define BAUDRATE 250000

// Activer l'interface série Bluetooth sur les appareils AT90USB
//#define BLUETOOTH

// Choisissez le nom de boards.h qui correspond à votre configuration
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_RAMPS_14_EFB
#endif

// Nom affiché dans le message LCD "Prêt" et le menu Info
//#define CUSTOM_MACHINE_NAME "3D Printer"

// ID unique de l'imprimante, utilisé par certains programmes pour différencier les machines.
// Choisissez le vôtre ou utilisez un service comme http://www.uuidgenerator.net/version4
//#define MACHINE_UUID "00000000-0000-0000-0000-000000000000"

// @section extrudeur

// Ceci définit le nombre d'extrudeurs
// :[1, 2, 3, 4, 5, 6, 7, 8]
#define EXTRUDERS 1

// Diamètre de filament généralement attendu (1,75, 2,85, 3,0, ...). Utilisé pour le capteur volumétrique, de largeur de filament, etc.
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

// Pour Cyclope ou tout "multi-extrudeuse" qui partage une seule buse.
//#define SINGLENOZZLE

/**
 * Multiplexeur multi-matériaux à buse unique Průša MK2 et variantes.
 *
 * Ce dispositif permet à un pilote pas à pas sur une carte de commande 
 * de piloter deux à huit moteurs pas à pas, un à la fois, d'une manière 
 * adaptée aux extrudeurs.
 *
 * Cette option permet uniquement au multiplexeur d'activer le changement d'outil.
 * Des options supplémentaires pour configurer les déplacements E personnalisés sont en attente.
 */
//#define MK2_MULTIPLEXER
#if ENABLED(MK2_MULTIPLEXER)
  // Remplacez ici les pins du sélecteur DIO par défaut, si nécessaire.
  // Certains fichiers de pins peuvent fournir des valeurs par défaut pour ces pins.
  //#define E_MUX0_PIN 40  // Toujours requis
  //#define E_MUX1_PIN 42  // Nécessaire pour 3 à 8 entrées
  //#define E_MUX2_PIN 44  // Nécessaire pour 5 à 8 entrées
#endif

/**
 * Unité multi-matériaux Prusa v2
 *
 * Nécessite NOZZLE_PARK_FEATURE pour garer la tête d'impression en cas de défaillance de l'unité MMU.
 * Nécessite extrudeurs = 5
 *
 * Pour une configuration supplémentaire, voir Configuration_adv.h
 */
//#define PRUSA_MMU2

// Un double extrudeur qui utilise un seul moteur pas à pas
//#define SWITCHING_EXTRUDER
#if ENABLED(SWITCHING_EXTRUDER)
  #define SWITCHING_EXTRUDER_SERVO_NR 0
  #define SWITCHING_EXTRUDER_SERVO_ANGLES { 0, 90 } // Angles pour E0, E1 [, E2, E3]
  #if EXTRUDERS > 3
    #define SWITCHING_EXTRUDER_E23_SERVO_NR 1
  #endif
#endif

// Une buse double qui utilise un servomoteur pour soulever / abaisser l'une (ou les deux) des buses
//#define SWITCHING_NOZZLE
#if ENABLED(SWITCHING_NOZZLE)
  #define SWITCHING_NOZZLE_SERVO_NR 0
  //#define SWITCHING_NOZZLE_E1_SERVO_NR 1          // Si deux servos sont utilisés, l'indice du second
  #define SWITCHING_NOZZLE_SERVO_ANGLES { 0, 90 }   // Angles pour E0, E1 (servo simple) ou abaissé / relevé (servo double)
#endif

/**
 * Deux chariots X séparés avec extrudeurs qui se connectent à une partie mobile 
 * via un mécanisme d'amarrage à solénoïde. Nécessite SOL1_PIN et SOL2_PIN.
 */
//#define PARKING_EXTRUDER

/**
 * Deux chariots X séparés avec extrudeurs qui se connectent à une partie mobile via 
 * un mécanisme d'amarrage magnétique utilisant des mouvements et sans solénoïde
 *
 * projet   : https://www.thingiverse.com/thing:3080893
 * mouvements : https://youtu.be/0xCEiG9VS3k
 *             https://youtu.be/Bqbcs0CU2FE
 */
//#define MAGNETIC_PARKING_EXTRUDER

#if EITHER(PARKING_EXTRUDER, MAGNETIC_PARKING_EXTRUDER)

  #define PARKING_EXTRUDER_PARKING_X { -78, 184 }     // positions X pour garer les extrudeurs
  #define PARKING_EXTRUDER_GRAB_DISTANCE 1            // (mm) Distance pour se déplacer au-delà du point de stationnement pour saisir l'extrudeur
  //#define MANUAL_SOLENOID_CONTROL                   // Contrôle manuel des solénoïdes d'amarrage avec M380 S / M381

  #if ENABLED(PARKING_EXTRUDER)

    #define PARKING_EXTRUDER_SOLENOIDS_INVERT           // S'il est activé, le solénoïde n'est PAS magnétisé avec la tension appliquée
    #define PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE LOW  // Le signal de pin LOW ou HIGH active la bobine
    #define PARKING_EXTRUDER_SOLENOIDS_DELAY 250        // (ms) Délai pour le champ magnétique. Aucun délai si 0 ou non défini.
    //#define MANUAL_SOLENOID_CONTROL                   // Contrôle manuel des solénoïdes d'amarrage avec M380 S / M381

  #elif ENABLED(MAGNETIC_PARKING_EXTRUDER)

    #define MPE_FAST_SPEED      9000      // (mm/m) Vitesse de déplacement avant le dernier point de distance
    #define MPE_SLOW_SPEED      4500      // (mm/m) Vitesse pour la dernière distance parcourue pour se garer et s'accoupler
    #define MPE_TRAVEL_DISTANCE   10      // (mm) Distance du dernier point
    #define MPE_COMPENSATION       0      // Compensation de décalage -1, 0, 1 (multiplicateur) uniquement pour l'accouplage

  #endif

#endif

/**
 * Changement de tête ou d'outil
 *
 * Prise en charge des têtes d'outils interchangeables et ancrables, telles que le 
 * changeur d'outils E3D. Les têtes d'outils sont verrouillées avec un servo.
 */
//#define SWITCHING_TOOLHEAD

/**
 * Tête d'outil de commutation magnétique
 *
 * Prend en charge les têtes d'outils interchangeables et ancrables avec un mécanisme 
 * un mécanisme  d'ancrage magnétique utilisant le mouvement et aucun servo.
 */
//#define MAGNETIC_SWITCHING_TOOLHEAD

/**
 * Tête d'outils de commutation électromagnétique
 *
 * Parking pour la cinématique CoreXY / HBot.
 * Les têtes d'outils sont garées sur un bord et maintenues avec un électro-aimant.
 * Pour prendre en charge plus de 2 têtes d'outils. Voir https://youtu.be/JolbsAKTKf4
 */
//#define ELECTROMAGNETIC_SWITCHING_TOOLHEAD

#if ANY(SWITCHING_TOOLHEAD, MAGNETIC_SWITCHING_TOOLHEAD, ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
  #define SWITCHING_TOOLHEAD_Y_POS          235         // (mm) Position Y du dock de la tête d'outils
  #define SWITCHING_TOOLHEAD_Y_SECURITY      10         // (mm) Distance de sécurité axe Y
  #define SWITCHING_TOOLHEAD_Y_CLEAR         60         // (mm) Distance minimale du dock pour libérer l'axe X 
  #define SWITCHING_TOOLHEAD_X_POS          { 215, 0 }  // (mm) positions X pour garer les extrudeurs
  #if ENABLED(SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_SERVO_NR       2         // Index du connecteur servo
    #define SWITCHING_TOOLHEAD_SERVO_ANGLES { 0, 180 }  // (degrés) Angles pour verrouiller, déverrouiller
  #elif ENABLED(MAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Y_RELEASE      5         // (mm) Distance de sécurité axe Y
    #define SWITCHING_TOOLHEAD_X_SECURITY   { 90, 150 } // (mm) Distance de sécurité axe X (T0, T1)
    //#define PRIME_BEFORE_REMOVE                       // Amorcez la buse avant de la libérer du dock
    #if ENABLED(PRIME_BEFORE_REMOVE)
      #define SWITCHING_TOOLHEAD_PRIME_MM           20  // (mm)   Longueur d'amorçage d'extrusion
      #define SWITCHING_TOOLHEAD_RETRACT_MM         10  // (mm)   Retracter après la longueur d'amorçage
      #define SWITCHING_TOOLHEAD_PRIME_FEEDRATE    300  // (mm/m) Vitesse d'extrusion
      #define SWITCHING_TOOLHEAD_RETRACT_FEEDRATE 2400  // (mm/m) Vitesse rétraction
    #endif
  #elif ENABLED(ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Z_HOP          2         // (mm) Relevé Z pour la commutation
  #endif
#endif

/**
 * "Mixing Extruder"
 *   - Ajoute les codes G M163 et M164 pour définir et "valider" les facteurs de mixage actuels.
 *   - Prolonge les routines de moteur d'extrudeur pour déplacer plusieurs extrudeurs proportionnellement au mélange.
 *   - Prise en charge facultative des outils virtuels prenant en charge le «M164 S <index>» du micrologiciel Repetier.
 *   - Cette implémentation prend en charge jusqu'à deux extrudeurs de mélange.
 *   - Activez DIRECT_MIXING_IN_G1 pour M165 et le mixage dans G1 (à partir de l'implémentation de référence de Pia Taubert).
 */
//#define MIXING_EXTRUDER
#if ENABLED(MIXING_EXTRUDER)
  #define MIXING_STEPPERS 2        // Nombre d'extrudeurs dans votre tête mélangeuse
  #define MIXING_VIRTUAL_TOOLS 16  // Utilisez la méthode Virtual Tool avec M163 et M164
  //#define DIRECT_MIXING_IN_G1    // Autoriser les facteurs de mélange ABCDHI dans les commandes de mouvement G1
  //#define GRADIENT_MIX           // Prise en charge du mélange de dégradé avec M166 et LCD
  #if ENABLED(GRADIENT_MIX)
    //#define GRADIENT_VTOOL       // Ajoutez M166 T pour utiliser un index V-tool comme alias de dégradé
  #endif
#endif

// Décalage des buses (décommenter si vous en utilisez plusieurs et si vous comptez sur le micrologiciel pour le positionner lors du changement).
// Le décalage doit être X = 0, Y = 0 pour la buse de l'extrudeur 0 (extrudeur par défaut).
// Pour les autres tetes, c'est leur distance par rapport à la buse 0 hotend.
//#define HOTEND_OFFSET_X { 0.0, 20.00 } // (mm) relative X-offset for each nozzle
//#define HOTEND_OFFSET_Y { 0.0, 5.00 }  // (mm) relative Y-offset for each nozzle
//#define HOTEND_OFFSET_Z { 0.0, 0.00 }  // (mm) relative Z-offset for each nozzle

// @section machine

/**
 * Contrôle de l'alimentation
 *
 * Activez et connectez l'alimentation au PS_ON_PIN.
 * Spécifiez si l'alimentation est active HIGH ou active LOW.
 */
//#define PSU_CONTROL
//#define PSU_NAME "Power Supply"

#if ENABLED(PSU_CONTROL)
  #define PSU_ACTIVE_HIGH false     // Définissez «false» pour ATX, «true» pour X-Box

  //#define PSU_DEFAULT_OFF         // Gardez l'appareil hors tension jusqu'à ce qu'il soit activé directement avec le M80
  //#define PSU_POWERUP_DELAY 100   // (ms) Délai pour que le bloc d'alimentation délivre sa pleine puissance

  //#define AUTO_POWER_CONTROL      // Activer le contrôle automatique de la broche PS_ON
  #if ENABLED(AUTO_POWER_CONTROL)
    #define AUTO_POWER_FANS         // Allumez le bloc d'alimentation si les ventilateurs ont besoin d'alimentation
    #define AUTO_POWER_E_FANS
    #define AUTO_POWER_CONTROLLERFAN
    #define AUTO_POWER_CHAMBER_FAN
    //#define AUTO_POWER_E_TEMP        50 // (°C) Allumez le bloc d'alimentation au-dessus de cette température
    //#define AUTO_POWER_CHAMBER_TEMP  30 // (°C) Allumez le bloc d'alimentation au-dessus de cette température
    #define POWER_TIMEOUT 30
  #endif
#endif

// @section temperature

//===========================================================================
//=========================== Paramètres thermiques =========================
//===========================================================================

/**
 * --NORMAL IS 4.7kohm PULLUP!-- 1kohm pullup peut être utilisé sur le capteur hotend, en utilisant une résistance et un tableau corrects
 *
 * Capteurs de température disponibles:
 *
 *    -5 : PT100 / PT1000 avec MAX31865 (uniquement pour les capteurs 0-1)
 *    -3 : thermocouple avec MAX31855 (uniquement pour les capteurs 0-1)
 *    -2 : thermocouple avec MAX6675 (uniquement pour les capteurs 0-1)
 *    -4 : thermocouple avec AD8495
 *    -1 : thermocouple avec AD595
 *     0 : non utilisé
 *     1 : 100k thermistor - meilleur choix pour EPCOS 100k (pullup 4,7k)
 *   331 : (3.3V table de thermistance à l'échelle 1 pour MEGA)
 *   332 : (3.3V table de thermistance à l'échelle 1 pour DUE)
 *     2 : 200k thermistor - ATC Semitec 204GT-2 (4.7k pullup)
 *     3 : Mendel-parts thermistor (4.7k pullup)
 *     4 : 10k thermistor !! ne l'utilisez pas pour un hotend. Il donne une mauvaise résolution à haute température. !!
 *     5 : 100K thermistor - ATC Semitec 104GT-2/104NT-4-R025H42G (Utilisé dans ParCan et J-Head) (4.7k pullup)
 *   501 : 100K Zonestar (Tronxy X3A) Thermistor
 *   512 : 100k RPW-Ultra hotend thermistor (4.7k pullup)
 *     6 : 100k EPCOS - Pas aussi précis que le tableau 1 (créé à l'aide d'un thermocouple Fluke) (4.7k pullup)
 *     7 : 100k Honeywell thermistor 135-104LAG-J01 (4.7k pullup)
 *    71 : 100k Honeywell thermistor 135-104LAF-J01 (4.7k pullup)
 *     8 : 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup)
 *     9 : 100k GE Sensing AL03006-58.2K-97-G1 (4.7k pullup)
 *    10 : 100k RS thermistor 198-961 (4.7k pullup)
 *    11 : 100k beta 3950 1% thermistor (4.7k pullup)
 *    12 : 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup) (calibré pour plateau chauffant Makibox)
 *    13 : 100k Hisens 3950  1% up to 300°C for hotend "Simple ONE " & "Hotend "All In ONE"
 *    15 : 100k thermistor calibration for JGAurora A5 hotend
 *    18 : ATC Semitec 204GT-2 (4.7k pullup) Dagoma.Fr - MKS_Base_DKU001327
 *    20 : Pt100 avec circuit dans l'Ultimainboard V2.x avec excitation 5v (AVR)
 *    21 : Pt100 avec circuit dans l'Ultimainboard V2.x avec une excitation de 3,3 V (STM32 \ LPC176x....)
 *   201 : Pt100 avec circuit en Overlord, similaire à Ultimainboard V2.x
 *    60 : 100k Maker's Tool Works Kapton Bed Thermistor beta=3950
 *    61 : 100k Formbot / Vivedino 3950 350C thermistor 4.7k pullup
 *    66 : 4.7M Thermistance haute température de Dyze Design
 *    67 : 450C thermistance de SliceEngineering
 *    70 : the 100K thermistance trouvée dans le bq Hephestos 2
 *    75 : 100k Coussin chauffant en silicone générique avec thermistance NTC 100K MGB18-104F39050L32
 *    99 : 100k thermistance avec résistance de rappel 10K (présente sur certaines machines Wanhao i3)
 *
 *       1k ohm pullup tables - Ceci est atypique et nécessite de changer le pullup de 4,7 k pour 1 k.
 *                              (mais donne une plus grande précision et un PID plus stable)
 *    51 : 100k thermistor - EPCOS (1k pullup)
 *    52 : 200k thermistor - ATC Semitec 204GT-2 (1k pullup)
 *    55 : 100k thermistor - ATC Semitec 104GT-2 (Used in ParCan & J-Head) (1k pullup)
 *
 *  1047 : Pt1000 with 4k7 pullup
 *  1010 : Pt1000 with 1k pullup (non standard)
 *   147 : Pt100 with 4k7 pullup
 *   110 : Pt100 with 1k pullup (non standard)
 *
 *  1000 : Custom - Spécifiez les paramètres dans Configuration_adv.h
 *
 *         Utilisez-les à des fins de test ou de développement. JAMAIS pour machine de production.
 *   998 : Tableau factice qui lit TOUJOURS 25 ° C ou la température définie ci-dessous.
 *   999 : Tableau factice indiquant TOUJOURS 100 ° C ou la température définie ci-dessous.
 */
#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_6 0
#define TEMP_SENSOR_7 0
#define TEMP_SENSOR_BED 0
#define TEMP_SENSOR_PROBE 0
#define TEMP_SENSOR_CHAMBER 0

// Lectures factices de température constante de thermistance, pour une utilisation avec 998 et 999
#define DUMMY_THERMISTOR_998_VALUE 25
#define DUMMY_THERMISTOR_999_VALUE 100

// Utilisez le capteur de température 1 comme capteur redondant avec le capteur 0. 
// Si les lectures des deux capteurs diffèrent trop, l'impression sera abandonnée.
//#define TEMP_SENSOR_1_AS_REDUNDANT
#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10

#define TEMP_RESIDENCY_TIME     10  // (secondes) Temps d'attente pour que le hotend se "stabilise" dans M109
#define TEMP_WINDOW              1  // (°C) Différence de température pour la temporisation "température atteinte"
#define TEMP_HYSTERESIS          3  // (°C) Différence de température considérée comme "suffisamment proche" de la cible

#define TEMP_BED_RESIDENCY_TIME 10  // (secondes) Temps d'attente pour que le lit "se stabilise" dans M190
#define TEMP_BED_WINDOW          1  // (°C) Différence de température pour la temporisation "température atteinte"
#define TEMP_BED_HYSTERESIS      3  // (°C) Différence de température considérée comme "suffisamment proche" de la cible

// En dessous de cette température, le chauffage sera éteint car 
// il indique probablement un fil de thermistance cassé.
#define HEATER_0_MINTEMP   5
#define HEATER_1_MINTEMP   5
#define HEATER_2_MINTEMP   5
#define HEATER_3_MINTEMP   5
#define HEATER_4_MINTEMP   5
#define HEATER_5_MINTEMP   5
#define HEATER_6_MINTEMP   5
#define HEATER_7_MINTEMP   5
#define BED_MINTEMP        5

// Au-dessus de cette température, le chauffage sera éteint.
// Cela peut protéger les composants contre la surchauffe, mais PAS contre les courts-circuits et les pannes.
//(Utilisez MINTEMP pour la protection contre les courts-circuits / défaillances des thermistances.)
#define HEATER_0_MAXTEMP 275
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define HEATER_5_MAXTEMP 275
#define HEATER_6_MAXTEMP 275
#define HEATER_7_MAXTEMP 275
#define BED_MAXTEMP      150

//===========================================================================
//============================ Paramètres PID ===============================
//===========================================================================
// Guide de réglage PID ici: https://3dprinting.forumactif.org/t226-reglage-du-pid-aux-petis-oignons

// Commentez la ligne suivante pour désactiver le PID et activer le bang-bang.
#define PIDTEMP
#define BANG_MAX 255     // Limite le courant de chauffage à la buse en mode bang-bang; 255 = plein courant
#define PID_MAX BANG_MAX // Limite le courant de chauffage à la buse lorsque le PID est actif (voir PID_FUNCTIONAL_RANGE ci-dessous); 255 = plein courant
#define PID_K1 0.95      // Facteur de lissage dans n'importe quelle boucle PID
#if ENABLED(PIDTEMP)
  #define PID_EDIT_MENU         // Ajoutez l'édition PID au menu "Paramètres avancés". (~ 700 octets de PROGMEM)
  //#define PID_AUTOTUNE_MENU     // Ajoutez l'autoréglage PID au menu "Paramètres avancés". (~ 250 octets de PROGMEM)
  //#define PID_DEBUG             // Envoie des données de débogage au port série.
  //#define PID_OPENLOOP 1        // Met PID en boucle ouverte. M104 / M140 définit la puissance de sortie de 0 à PID_MAX
  //#define SLOW_PWM_HEATERS      // PWM avec une fréquence très basse (environ 0,125 Hz = 8 s) et un temps d'état minimum d'environ 1s utile pour les chauffages entraînés par un relais
  //#define PID_PARAMS_PER_HOTEND // Utilise des paramètres PID distincts pour chaque extrudeur (utile pour les extrudeurs dépareillées)
                                  // Définir / obtenir avec gcode: M301 E [numéro d'extrudeur, 0-2]
  #define PID_FUNCTIONAL_RANGE 10 // Si la différence de température entre la température cible et la température réelle est supérieure 
                                  // supérieure à PID_FUNCTIONAL_RANGE, le PID sera arrêté et le chauffage sera réglé sur min / max.
// PID à 235°C
  #define  DEFAULT_Kp 17.02
  #define  DEFAULT_Ki 1.19
  #define  DEFAULT_Kd 60.65

  // Si vous utilisez un hotend préconfiguré, vous pouvez utiliser l'un des ensembles de valeurs en le décommentant

  // Ultimaker
  #define DEFAULT_Kp 22.2
  #define DEFAULT_Ki 1.08
  #define DEFAULT_Kd 114
  
  // MakerGear
  //#define DEFAULT_Kp 7.0
  //#define DEFAULT_Ki 0.1
  //#define DEFAULT_Kd 12

  // Mendel Parts V9 on 12V
  //#define DEFAULT_Kp 63.0
  //#define DEFAULT_Ki 2.25
  //#define DEFAULT_Kd 440

#endif // PIDTEMP

//===========================================================================
//================= PID> Contrôle de la température du lit ==================
//===========================================================================

/**
 * PID  du chauffage de plateau
 *
 * Si cette option est activée, définissez les constantes PID ci-dessous.
 * Si cette option est désactivée, bang-bang sera utilisé et BED_LIMIT_SWITCHING activera l'hystérésis.
 *
 * La fréquence PID sera la même que celle de l'extrudeur PWM.
 * Si PID_dT est la valeur par défaut et correcte pour le matériel / la configuration, cela signifie 7,689 Hz, ce qui
 * est bien pour entraîner une onde carrée dans une charge résistive et n'a pas d'impact significatif sur le chauffage FET.
 * Cela fonctionne également très bien sur un relais à semi-conducteurs Fotek SSR-10DA avec un chauffage de
 * 250 W. Si votre configuration est considérablement différente de celle-ci et que vous ne comprenez pas les 
 * problèmes impliqués, n'utilisez pas le PID de lit jusqu'à ce que quelqu'un d'autre vérifie que votre matériel fonctionne.
 */
//#define PIDTEMPBED

//#define BED_LIMIT_SWITCHING

/**
 * Puissance maximale du plateau
 * S'applique à toutes les formes de contrôle du lit (PID, bang-bang et bang-bang avec hystérésis).
 * Lorsqu'il est défini sur une valeur inférieure à 255, active une forme de PWM sur le lit qui agit comme un diviseur, 
 * donc ne l'utilisez pas sauf si vous êtes OK avec PWM sur votre lit. (Voir le commentaire sur l'activation de PIDTEMPBED)
 */
#define MAX_BED_POWER 255 // limite le cycle de service au lit; 255 = courant maximum

#if ENABLED(PIDTEMPBED)
  //#define MIN_BED_POWER 0
  //#define PID_BED_DEBUG // Envoie des données de débogage au port série.

 // PID à 60°C
  

  
  //Chauffage en silicone 120V 250W avec plaque en borosilicate de 4mm (MendelMax 1.5+)
  //du modèle FOPDT - kp = 0,39 Tp = 405 Tdead = 66, Tc réglé à 79,2, facteur agressif de 0,15 (vs .1, 1, 10)
  //#define DEFAULT_bedKp 97.1
  //#define DEFAULT_bedKi 1.41
  //#define DEFAULT_bedKd 1675.16

  //Chauffage en silicone 120V 250W avec plaque en borosilicate de 4mm (MendelMax 1.5+)
  //De pidautotune
  //#define DEFAULT_bed_Kp 97.1
  //#define DEFAULT_bed_Ki 1.41
  //#define DEFAULT_bed_Kd 1675.16

  // TROUVEZ VOTRE PROPRE: "M303 E-1 C8 S90" pour exécuter le réglage automatique sur le lit à 90 degrés C pendant 8 cycles.
#endif // PIDTEMPBED

// @section extruder

/**
 * Empêchez l'extrusion si la température est inférieure à EXTRUDE_MINTEMP.
 * Ajoutez M302 pour régler la température d'extrusion minimale 
 * et / ou activer et désactiver la prévention d'extrusion à froid.
 *
 * *** IL EST FORTEMENT RECOMMANDÉ DE LAISSER CETTE OPTION ACTIVÉE!***
 */
#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170

/**
 * Empêchez une extrusion unique plus longue que EXTRUDE_MAXLENGTH.
 * Remarque: pour les extrudeurs en Bowden, regler un longueur suffisante pour permettre le chargement / déchargement.
 */
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 200

//===========================================================================
//================= Protection contre les fuites thermiques =================
//===========================================================================

/**
 * La protection thermique offre une protection supplémentaire à votre imprimante contre 
 * les dommages et les incendies. Marlin comprend  toujours des plages de températures 
 * minimales et maximales sûres qui protègent contre un fil de thermistance cassé ou déconnecté.
 *
 * Le problème: si une thermistance tombe, elle signalera la 
 * température beaucoup plus basse de l'air dans la pièce et 
 * le micrologiciel gardera le chauffage allumé.
 *
 * Si vous obtenez des erreurs "Thermal Runaway" ou "Heating failed",
 * les détails peuvent être réglés dans Configuration_adv.h
 */

#define THERMAL_PROTECTION_HOTENDS // Activer la protection thermique pour tous les extrudeurs
#define THERMAL_PROTECTION_BED     // Activer la protection thermique du plateau chauffant
#define THERMAL_PROTECTION_CHAMBER // Activer la protection thermique du caisson chauffé

//===========================================================================
//============================ Paramètres mécaniques ========================
//===========================================================================

// @section machine

// Décommentez l'une de ces options pour activer la cinématique CoreXY, 
// CoreXZ ou CoreYZ dans l'ordre habituel ou inversé
//#define COREXY
//#define COREXZ
//#define COREYZ
//#define COREYX
//#define COREZX
//#define COREZY

//===========================================================================
//============================= Paramètres Delta ============================
//===========================================================================
// Activer la cinématique DELTA et la plupart de la configuration par défaut pour Deltas
//#define DELTA

#if ENABLED(DELTA)

  // Créez des courbes delta à partir de nombreuses lignes droites (interpolation linéaire).
  // Il s'agit d'un compromis entre les coins visibles (pas assez de segments) 
  // et la surcharge du processeur (trop d'appels sqrt coûteux).
  #define DELTA_SEGMENTS_PER_SECOND 160

  // Après le retour, descendez à une hauteur où le mouvement XY n'est pas contraint
  //#define DELTA_HOME_TO_SAFE_ZONE 

  // Menu de calibration Delta
  // décommenter pour ajouter l'option de menu d'étalonnage à trois points.
  // voir http://minow.blogspot.com/index.html#4918805519571907051
  #define DELTA_CALIBRATION_MENU

  // décommenter pour ajouter G33 Delta Auto-Calibration (Activer EEPROM_SETTINGS pour stocker les résultats)
  #define DELTA_AUTO_CALIBRATION

  // REMARQUE NB toutes les valeurs des valeurs DELTA_ * DOIVENT être à virgule flottante, 
  // donc toujours mettre un point décimal entre chacune d'entre elles
  #if ENABLED(DELTA_AUTO_CALIBRATION)
    // définir le nombre par défaut de points de sonde: n * n (1 -> 7)
    #define DELTA_CALIBRATION_DEFAULT_POINTS 7
  #endif

  #if ENABLED(DELTA_AUTO_CALIBRATION) || ENABLED(DELTA_CALIBRATION_MENU)
    // Définir le rayon pour les points de sonde d'étalonnage - max DELTA_PRINTABLE_RADIUS pour les sondes non excentriques
    #define MIN_PROBE_EDGE 63 //DELTA_CALIBRATION_RADIUS 63   // (mm)
    // Définissez l'interpréteur pour le test Papertest
    #define PROBE_MANUALLY_STEP 0.05      // (mm)
  #endif

  // Diamètre de la surface d'impression / 2 moins d'espace inaccessible (évitez les collisions avec les tours verticales).
  #define DELTA_PRINTABLE_RADIUS 70.0     // (mm)

  // Distance de centre à centre des trous dans les tiges de poussée diagonales.
  #define DELTA_DIAGONAL_ROD 218.0        // (mm)

  // Distance entre le lit et la position initiale de la buse Z
  #define DELTA_HEIGHT 250         // (mm) Obtenez cette valeur du calibrage automatique G33

  #define DELTA_ENDSTOP_ADJ { 0.0, 0.0, 0.0 } // Obtenez ces valeurs du calibrage automatique G33

  // Distance horizontale entre les trous des tiges de poussée diagonales lorsque la tête est au centre
  #define DELTA_RADIUS 100.0          // (mm) Obtenez ces valeurs du calibrage automatique G33

  // Ajustements de garniture pour les tours individuelles
  // corrections d'angle de tour pour X et Y tour / rotation XYZ donc angle de tour Z = 0
  // mesuré en degrés dans le sens antihoraire en regardant par dessus l'imprimante
  #define DELTA_TOWER_ANGLE_TRIM { 0.0, 0.0, 0.0 } // Obtenez ces valeurs du calibrage automatique G33

  // Réglages du rayon delta et de la tige diagonale (mm)
  //#define DELTA_RADIUS_TRIM_TOWER { 0.0, 0.0, 0.0 }
  //#define DELTA_DIAGONAL_ROD_TRIM_TOWER { 0.0, 0.0, 0.0 }

#endif
//===========================================================================
//======================== Paramètres de fin de course ======================
//===========================================================================

// @section homing

// Spécifiez ici tous les connecteurs de fin de course ou sonde raccordés.
// Presque toutes les imprimantes en utiliseront un par axe. Les sondes utiliseront un ou plusieurs des 
// connecteurs supplémentaires. Laissez indéfini tout connecteur non utilisé par des fin de course ou sonde.
#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG
//#define USE_XMAX_PLUG
//#define USE_YMAX_PLUG
//#define USE_ZMAX_PLUG

// Activer le pullup pour tous les fin de course pour empêcher un état flottant
#define ENDSTOPPULLUPS
#if DISABLED(ENDSTOPPULLUPS)
  // Désactivez ENDSTOPPULLUPS pour définir des pullups individuellement
  //#define ENDSTOPPULLUP_XMAX
  //#define ENDSTOPPULLUP_YMAX
  //#define ENDSTOPPULLUP_ZMAX
  //#define ENDSTOPPULLUP_XMIN
  //#define ENDSTOPPULLUP_YMIN
  //#define ENDSTOPPULLUP_ZMIN
  //#define ENDSTOPPULLUP_ZMIN_PROBE
#endif

// Activer le pulldown our tous les fin de course pour empêcher un état flottant
//#define ENDSTOPPULLDOWNS
#if DISABLED(ENDSTOPPULLDOWNS)
  // Désactivez ENDSTOPPULLDOWNS pour définir des pulldowns individuellement
  //#define ENDSTOPPULLDOWN_XMAX
  //#define ENDSTOPPULLDOWN_YMAX
  //#define ENDSTOPPULLDOWN_ZMAX
  //#define ENDSTOPPULLDOWN_XMIN
  //#define ENDSTOPPULLDOWN_YMIN
  //#define ENDSTOPPULLDOWN_ZMIN
  //#define ENDSTOPPULLDOWN_ZMIN_PROBE
#endif

// L'arrêt mécanique avec COM à la masse et NC au signal utilise ici «faux» (configuration la plus courante).
#define X_MIN_ENDSTOP_INVERTING false // Définissez sur true pour inverser la logique de l'arrêt final.
#define Y_MIN_ENDSTOP_INVERTING false // Définissez sur true pour inverser la logique de l'arrêt final.
#define Z_MIN_ENDSTOP_INVERTING false  // Définissez sur true pour inverser la logique de l'arrêt final.
#define X_MAX_ENDSTOP_INVERTING false // Définissez sur true pour inverser la logique de l'arrêt final.
#define Y_MAX_ENDSTOP_INVERTING false // Définissez sur true pour inverser la logique de l'arrêt final.
#define Z_MAX_ENDSTOP_INVERTING false // Définissez sur true pour inverser la logique de l'arrêt final.
#define Z_MIN_PROBE_ENDSTOP_INVERTING false // Définissez sur true pour inverser la logique de l'arrêt final.

/**
 * Pilotes pas à pas
 *
 * Ces paramètres permettent à Marlin de régler la synchronisation des pilotes pas à pas et d'activer des options avancées pour les pilotes  
 * pas à pas qui les prennent en charge. Vous pouvez également remplacer les options de synchronisation dans Configuration_adv.h.
 *
 * A4988 est supposé pour les pilotes non spécifiés.
 *
 * Options: A4988, A5984, DRV8825, LV8729, L6470, L6474, POWERSTEP01,
 *          TB6560, TB6600, TMC2100,
 *          TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
 *          TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
 *          TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
 *          TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
 * :['A4988', 'A5984', 'DRV8825', 'LV8729', 'L6470', 'L6474', 'POWERSTEP01', 'TB6560', 'TB6600', 'TMC2100', 'TMC2130', 'TMC2130_STANDALONE', 'TMC2160', 'TMC2160_STANDALONE', 'TMC2208', 'TMC2208_STANDALONE', 'TMC2209', 'TMC2209_STANDALONE', 'TMC26X', 'TMC26X_STANDALONE', 'TMC2660', 'TMC2660_STANDALONE', 'TMC5130', 'TMC5130_STANDALONE', 'TMC5160', 'TMC5160_STANDALONE']
 */
//#define X_DRIVER_TYPE  A4988
//#define Y_DRIVER_TYPE  A4988
//#define Z_DRIVER_TYPE  A4988
//#define X2_DRIVER_TYPE A4988
//#define Y2_DRIVER_TYPE A4988
//#define Z2_DRIVER_TYPE A4988
//#define Z3_DRIVER_TYPE A4988
//#define Z4_DRIVER_TYPE A4988
//#define E0_DRIVER_TYPE A4988
//#define E1_DRIVER_TYPE A4988
//#define E2_DRIVER_TYPE A4988
//#define E3_DRIVER_TYPE A4988
//#define E4_DRIVER_TYPE A4988
//#define E5_DRIVER_TYPE A4988
//#define E6_DRIVER_TYPE A4988
//#define E7_DRIVER_TYPE A4988

// Activez cette fonction si toutes les broches d'arrêt activées sont capables d'interruption.
// Cela supprimera la nécessité d'interroger les broches d'interruption, économisant ainsi de nombreux cycles CPU.
//#define ENDSTOP_INTERRUPTS_FEATURE

/**
 * Seuil de bruit de fin de course
 *
 * Activez cette option si votre sonde ou vos butées se déclenchent à cause du bruit.
 *
 * - Des valeurs plus élevées peuvent affecter la répétabilité ou la précision de certaines sondes de lit.
 * - Pour corriger le bruit, installez un condensateur en céramique 100nF en ligne avec le commutateur.
 * - Cette fonctionnalité n'est pas requise pour les micro-commutateurs courants montés sur des PCB 
 *   basés sur la conception Makerbot, qui ont déjà le condensateur 100nF.
 *
 * :[2,3,4,5,6,7]
 */
//#define ENDSTOP_NOISE_THRESHOLD 2

//=============================================================================
//=========================== Paramètres de mouvement =========================
//=============================================================================
// @section mouvement

/**
 * Paramètres par défaut
 *
 * Ces paramètres peuvent être réinitialisés par M502
 *
 * Notez que si l'EEPROM est activée, ces valeurs remplaceront celles enregistrées .
 */

/**
 * Avec cette option, chaque stepper E peut avoir ses propres facteurs 
 * pour les paramètres de mouvement suivants. Si moins de facteurs sont 
 * donnés que le nombre total d'extrudeurs, la dernière valeur s'applique au reste des extrudeurs.
 */
//#define DISTINCT_E_FACTORS

/**
 * Pas d'axe par défaut par unité (pas / mm)
 * Remplacer avec M92
 *                                      X, Y, Z, E0 [, E1[, E2...]]
 */
// variables pour calculer les steps
#define XYZ_FULL_STEPS_PER_ROTATION 80
#define XYZ_MICROSTEPS 16
#define XYZ_BELT_PITCH 2
#define XYZ_PULLEY_TEETH 16

// les vitesses delta doivent être les mêmes sur xyz
#define DEFAULT_XYZ_STEPS_PER_UNIT ((XYZ_FULL_STEPS_PER_ROTATION) * (XYZ_MICROSTEPS) / double(XYZ_BELT_PITCH) / double(XYZ_PULLEY_TEETH))
#define DEFAULT_AXIS_STEPS_PER_UNIT   { DEFAULT_XYZ_STEPS_PER_UNIT, DEFAULT_XYZ_STEPS_PER_UNIT, DEFAULT_XYZ_STEPS_PER_UNIT, 100 }  // pas par défaut par unité pour Kossel (GT2, 20 dents)

/**
 * Vitesse d'avance maximale par défaut (mm / s)
 * Remplacer avec M203
 *                                      X, Y, Z, E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }

//#define LIMITED_MAX_FR_EDITING        // Modifier la limite via M203 ou sur le LCD à DEFAULT_MAX_FEEDRATE * 2
#if ENABLED(LIMITED_MAX_FR_EDITING)
  #define MAX_FEEDRATE_EDIT_VALUES    { 600, 600, 10, 50 } // ...ou, définissez vos propres limites.
#endif

/**
 * Accélération max par défaut (changement / s) changement = mm / s
 * (Vitesse de démarrage maximale pour les mouvements accélérés)
 * Remplacer avec M201
 *                                      X, Y, Z, E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_ACCELERATION      { 3000, 3000, 100, 10000 }

//#define LIMITED_MAX_ACCEL_EDITING     // Modifier la limite via M201 ou LCD à DEFAULT_MAX_ACCELERATION * 2
#if ENABLED(LIMITED_MAX_ACCEL_EDITING)
  #define MAX_ACCEL_EDIT_VALUES       { 6000, 6000, 200, 20000 } // ...ou, définissez vos propres limites.
#endif

/**
 * Accélération par défaut (changement / s) changement = mm / s
 * Remplacer avec M204
 *
 *   M204 P    Accélération
 *   M204 R    Accelération de rétraction
 *   M204 T    Accélération du déplacement (sans impression)
 */
#define DEFAULT_ACCELERATION          3000    // Accélération X, Y, Z et E pour les mouvements d'impression
#define DEFAULT_RETRACT_ACCELERATION  3000    // Accélération E pour les rétractations
#define DEFAULT_TRAVEL_ACCELERATION   3000    // Accélération X, Y, Z pour les déplacements (sans impression)

/**
 * Limites de secousse (Jerk) par défaut (mm / s)
 * Remplacer avec M205 X Y Z E
 *
 * "Jerk" spécifie le changement de vitesse minimum qui nécessite une accélération.
 * Lorsque vous changez de vitesse et de direction, si la différence est inférieure 
 * à la valeur définie ici, cela peut se produire instantanément.
 */
#define CLASSIC_JERK
#if ENABLED(CLASSIC_JERK)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK 10.0
  #define DEFAULT_ZJERK .3

  //#define TRAVEL_EXTRA_XYJERK 0.0     // Unité de secousse supplémentaire pour tous les déplacements

  //#define LIMITED_JERK_EDITING        // Modifier la limite via M205 ou LCD à DEFAULT_aJERK * 2
  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ...ou, définissez vos propres limites.
  #endif
#endif

#define DEFAULT_EJERK    5.0  // Peut être utilisé par Linear Advance 

/**
 * Facteur de déviation de jonction
 *
 * Voir:
 *   https://reprap.org/forum/read.php?1,739819
 *   http://blog.kyneticcnc.com/2018/10/computing-junction-deviation-for-marlin.html
 */
#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.013 // (mm) Distance from real junction edge
#endif

/**
 * Accélération de la courbe en S (S-Curve Acceleration)
 *
 * Cette option élimine les vibrations lors de l'impression en ajustant une courbe de Bézier pour 
 * déplacer l'accélération, produisant des changements de direction beaucoup plus fluides.
 *
 * Voir: https://github.com/synthetos/TinyG/wiki/Jerk-Controlled-Motion-Explained
 */
//#define S_CURVE_ACCELERATION

//===========================================================================
//============================= Z Probe Options =============================
//===========================================================================
// @section sondes de plateau

//
// Voir: http://marlinfw.org/docs/configuration/probes.html
//

/**
 * Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
 *
 * Activez cette option pour une sonde connectée à la broche de butée Z Min.
 */
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

/**
 * Z_MIN_PROBE_PIN
 *
 * Définissez cette broche si la sonde n'est pas connectée à Z_MIN_PIN.
 * Si elle n'est pas définie, la broche par défaut pour la CARTE MÈRE sélectionnée sera 
 * utilisée. La plupart du temps, la valeur par défaut est ce que vous voulez.
 *
 *  - L'option la plus simple consiste à utiliser un connecteur de butée libre.
 *  - Utilisez 5 V pour les capteurs alimentés (généralement inductifs).
 *
 *  - Les cartes RAMPS 1.3 / 1.4 peuvent utiliser les broches 5V, GND et Aux4-> D32:
 *    - Pour les commutateurs simples, connectez ...
 *      - commutateurs normalement fermés sur GND et D32.
 *      - commutateurs normalement ouverts sur 5V et D32.
 *
 */
//#define Z_MIN_PROBE_PIN 32 // La broche 32 est la valeur RAMPS par défaut

/**
 * Type de sonde
 *
 * Sondes Allen Key, sondes servo, sondes Z-Sled, FIX_MOUNTED_PROBE, etc.
 * Activez l'une d'entre elles ci-dessous pour utiliser la mise à niveau automatique du lit.
 */

/**
 * La «sonde manuelle» fournit un moyen de faire la mise à niveau du lit «automatique» sans sonde.
 * Use G29 repeatedly, adjusting the Z height at each point with movement commands
 *Utilisez G29 à plusieurs reprises, en ajustant la hauteur Z à chaque point avec les commandes de mouvement ou (avec LCD_BED_LEVELING) sur le contrôleur LCD.
 */
//#define PROBE_MANUALLY
//#define MANUAL_PROBE_START_Z 0.2

/**
 * Une sonde à montage fixe (Fix-Mounted Probe) ne se déploie pas ou nécessite un déploiement manuel.
 *   (par exemple, une sonde inductive ou un commutateur de sonde basé sur une buse.)
 */
//#define FIX_MOUNTED_PROBE

/**
 * Utilisez la buse comme sonde, comme avec un système de buse 
 * conducteur ou un effecteur intelligent piézo-électrique.
 */
//#define NOZZLE_AS_PROBE

/**
 * Sonde servo Z, comme un interrupteur de fin de course sur un bras rotatif.
 */
//#define Z_PROBE_SERVO_NR 0       // Par défaut sur le connecteur SERVO 0.
//#define Z_SERVO_ANGLES { 70, 0 } // Z Servo Deploy et Stow angles

/**
 * La sonde BLTouch utilise un capteur à effet Hall et émule un servo.
 */
//#define BLTOUCH

/**
 * Sonde Touch-MI par hotends.fr
 *
 * Cette sonde est déployée et activée en déplaçant l'axe X vers un aimant au bord du plateau.
 * Par défaut, l'aimant est supposé être à gauche et activé par un "home". Si l'aimant 
 * est à droite, activez et réglez TOUCH_MI_DEPLOY_XPOS sur la position de déploiement.
 *
 * Nécessite également: BABYSTEPPING, BABYSTEP_ZPROBE_OFFSET, Z_SAFE_HOMING,
 *                et un Z_HOMING_HEIGHT d'au moins 10.
 */
//#define TOUCH_MI_PROBE
#if ENABLED(TOUCH_MI_PROBE)
  #define TOUCH_MI_RETRACT_Z 0.5                  // Hauteur à laquelle la sonde se rétracte
  //#define TOUCH_MI_DEPLOY_XPOS (X_MAX_BED + 2)  // Pour un aimant sur le côté droit du lit
  //#define TOUCH_MI_MANUAL_DEPLOY                // Pour un déploiement manuel (menu LCD)
#endif

// Une sonde qui est déployée et rangée avec une broche de solénoïde (SOL1_PIN)
//#define SOLENOID_PROBE

// Une sonde montée sur un traîneau comme celles conçues par Charles Bell.
//#define Z_PROBE_SLED
//#define SLED_DOCKING_OFFSET 5  // La distance supplémentaire que l'axe X doit parcourir pour ramasser le traîneau. 0 devrait convenir, mais vous pouvez pousser plus loin si vous le souhaitez.

// Une sonde déployée en déplaçant l'axe des x, comme la sonde à crémaillère du Wilson II conçue par Marty Rice.
//#define RACK_AND_PINION_PROBE
#if ENABLED(RACK_AND_PINION_PROBE)
  #define Z_PROBE_DEPLOY_X  X_MIN_POS
  #define Z_PROBE_RETRACT_X X_MAX_POS
#endif

// Duet Smart Effector (pour les imprimantes delta) - https://bit.ly/2ul5U7J
// Lorsque la broche est définie, vous pouvez utiliser M672 pour régler / réinitialiser la sensibilité de la sonde.
//#define DUET_SMART_EFFECTOR
#if ENABLED(DUET_SMART_EFFECTOR)
  #define SMART_EFFECTOR_MOD_PIN  -1  // Connectez une broche GPIO à la broche MOD du Smart Effector
#endif

//
// Pour Z_PROBE_ALLEN_KEY, voir les exemples de configurations Delta.
//

/**
 * Z Décalage sonde-buse (X, Y), par rapport à (0, 0).
 *
 * Dans l'exemple suivant, les décalages X et Y sont tous deux positifs:
 *
 *   #define NOZZLE_TO_PROBE_OFFSET { 10, 10, 0 }
 *
 *     +--Arriere--+
 *   G |           | D
 *   A |    (+) P  | R <-- probe (20,20)
 *   U |           | O
 *   C | (-) N (+) | I <-- nozzle (10,10)
 *   H |           | T
 *   E |    (-)    | E
 *     |           |
 *     O-- AVANT --+
 *   (0,0)
 *
 * Spécifiez une position de sonde comme { X, Y, Z }
 */
#define NOZZLE_TO_PROBE_OFFSET { 0, 0, 0 }

// La plupart des sondes doivent rester éloignées des bords du lit, mais avec NOZZLE_AS_PROBE, cela peut être négatif pour une zone de sondage plus large.
// cela peut être néfaste pour une zone de sondage plus large.
#define MIN_PROBE_EDGE 10

// Vitesse de déplacement des axes X et Y (mm / m) entre les sondes
#define XY_PROBE_SPEED 8000

// Avance (mm / m) pour la première approche en double palpage (MULTIPLE_PROBING == 2)
#define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z

// Avance (mm / m) pour la sonde "précise" de chaque point
#define Z_PROBE_SPEED_SLOW (Z_PROBE_SPEED_FAST / 2)

/**
 * Sondage multiple
 *
 * Vous pouvez obtenir de meilleurs résultats en sondant 2 fois ou plus.
 * Avec EXTRA_PROBING, les lectures les plus atypiques seront ignorées.
 *
 * Un total de 2 sondes rapides / lentes avec une moyenne pondérée.
 * Un total de 3 ou plus ajoute des sondes plus lentes, en prenant la moyenne.
 */
//#define MULTIPLE_PROBING 2
//#define EXTRA_PROBING    1

/**
 * Les sondes Z nécessitent un dégagement lors du déploiement, de l'arrimage et du déplacement 
 * entre les points de sonde pour éviter de heurter le lit et d'autres éléments matériels.
 * Les sondes servo-montées nécessitent un espace supplémentaire pour que le bras puisse tourner.
 * Les sondes inductives ont besoin d'espace pour ne pas se déclencher tôt.  
 *
 * Utilisez ces paramètres pour spécifier la distance (mm) pour élever la sonde (ou abaisser le lit). Les valeurs 
 * définies ici s'appliquent au-delà de tout décalage (négatif) de la sonde Z défini avec NOZZLE_TO_PROBE_OFFSET, M851 ou l'écran LCD.
 * 
 * Seules les valeurs entières> = 1 sont valides ici.
 *
 * Exemple: `M851 Z-5` avec un DÉGAGEMENT de 4  =>  9mm du lit à la buse.
 *    Mais: `M851 Z+1` avec un DÉGAGEMENT de 2  =>  2mm du lit à la buse.
 */
#define Z_CLEARANCE_DEPLOY_PROBE   10 // Dégagement en Z pour déploiement / rangement
#define Z_CLEARANCE_BETWEEN_PROBES  5 // Dégagement en Z entre les points de sonde
#define Z_CLEARANCE_MULTI_PROBE     5 // Dégagement en Z entre plusieurs sondes
//#define Z_AFTER_PROBING           5 // Position Z après le sondage

#define Z_PROBE_LOW_POINT          -2 // Distance la plus éloignée sous le point de déclenchement à parcourir avant de s'arrêter

// Pour M851, donnez une plage de réglage du décalage de la sonde Z
#define Z_PROBE_OFFSET_RANGE_MIN -20
#define Z_PROBE_OFFSET_RANGE_MAX 20

// Activer le test de répétabilité M48 pour tester la précision de la sonde
//#define Z_MIN_PROBE_REPEATABILITY_TEST

// Confirmation de l'utilisateur avant le déploiement / la pause de rangement.
//#define PAUSE_BEFORE_DEPLOY_STOW
#if ENABLED(PAUSE_BEFORE_DEPLOY_STOW)
  //#define PAUSE_PROBE_DEPLOY_WHEN_TRIGGERED // Pour le déploiement manuel de la sonde "Allenkey"
#endif

/**
 * Activez une ou plusieurs des options suivantes si le sondage ne semble pas fiable.
 * Les chauffages et / ou ventilateurs peuvent être désactivés pendant le sondage pour minimiser le bruit 
 * électrique. Un délai peut également être ajouté pour permettre au bruit et aux vibrations de se stabiliser.
 * Ces options sont très utiles pour la sonde BLTouch, mais peuvent également améliorer 
 * les lectures avec des sondes inductives et des capteurs piézoélectriques.
 */
//#define PROBING_HEATERS_OFF       // Éteignez les chauffages lors du sondage
#if ENABLED(PROBING_HEATERS_OFF)
  //#define WAIT_FOR_BED_HEATER     // Attendez que le lit se réchauffe entre les sondes (pour améliorer la précision)
#endif
//#define PROBING_FANS_OFF          // Éteignez les ventilateurs lors du sondage
//#define PROBING_STEPPERS_OFF      // Désactiver les moteurs pas à pas (sauf si nécessaire pour maintenir la position) lors du sondage
//#define DELAY_BEFORE_PROBING 200  // (ms) Pour empêcher les vibrations de déclencher les capteurs piézoélectriques

// Pour inverser les broches d'activation pas à pas (actif bas), utilisez 0, non inverseur (actif haut), utilisez 1
// :{ 0:'Low', 1:'High' }
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // Pour tous les extrudeurs

// Désactive le stepper d'axe immédiatement lorsqu'il n'est pas utilisé.
// AVERTISSEMENT: lorsque les moteurs s'arrêtent, il y a un risque de perte de précision de position!
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false

// Avertir à l'écran de la précision éventuellement réduite
//#define DISABLE_REDUCED_ACCURACY_WARNING

// @section extrudeur

#define DISABLE_E false             // Pour tous les extrudeurs
#define DISABLE_INACTIVE_EXTRUDER   // Conserver uniquement l'extrudeur utilisé activé

// @section machine

// Inversez la direction pas à pas. Changer (ou inverser le connecteur du moteur) si un axe va dans le mauvais sens.
#define INVERT_X_DIR false
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false

// @section extruder

// Pour l'extrudeur à entraînement direct v9 définie sur true, pour l'extrudeur à engrenages définie sur false.
#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false
#define INVERT_E6_DIR false
#define INVERT_E7_DIR false

// @section homing

//#define NO_MOTION_BEFORE_HOMING // Bloquer les mouvements jusqu'à ce que tous les axes aient été référencés

//#define UNKNOWN_Z_NO_RAISE      // Ne soulevez pas Z (abaissez le lit) si Z est "inconnu". Pour les lits qui tombent lorsque Z est hors tension.

//#define Z_HOMING_HEIGHT  4      // (mm) Hauteur Z minimale avant la prise d'origine (G28) pour le dégagement Z au-dessus du lit, des pinces, ...
                                  // Assurez-vous d'avoir autant d'espace sur votre Z_MAX_POS pour éviter le blocage.

//#define Z_AFTER_HOMING  10      // (mm) Hauteur vers laquelle se déplacer après le homing Z

// Emplacement des butées lors de la prise d'origine; 1 = MAX, -1 = MIN
// :[-1,1]
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

// @section machine

// La taille du lit d'impression
#define X_BED_SIZE 200
#define Y_BED_SIZE 200

// Limites de déplacement (mm) après le référencement, correspondant aux positions de butée.
#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 200

/**
 * Butées logicielles
 *
 * - Empêche les déplacements hors des limites définies de la machine.
 * - Les axes individuels peuvent être désactivés, si vous le souhaitez.
 * - X et Y s'appliquent uniquement aux imprimantes cartésiennes.
 * - Utilisez «M211» pour activer / désactiver les arrêts logiciels ou signaler l'état actuel
 */

// Les butées logicielles minimales limitent le mouvement dans la limites des coordonnées minimales 
#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
#endif

// Les butées logicielles maximales limitent le mouvement dans la limites des coordonnées maximales
#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
#endif

#if EITHER(MIN_SOFTWARE_ENDSTOPS, MAX_SOFTWARE_ENDSTOPS)
  //#define SOFT_ENDSTOPS_MENU_ITEM  // Activer / désactiver les arrêts logiciels à partir de l'écran LCD
#endif

/**
 * Capteurs de fin de filament
 * Des butées mécaniques ou opto sont utilisées pour vérifier la présence de filament.
 *
 * Les cartes RAMPS utilisent SERVO3_PIN pour le premier capteur.
 * Pour d'autres cartes, vous devrez peut-être définir FIL_RUNOUT_PIN, FIL_RUNOUT2_PIN, etc.
 * Par défaut, le firmware suppose HIGH = FILAMENT PRESENT.
 */
//#define FILAMENT_RUNOUT_SENSOR
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define NUM_RUNOUT_SENSORS   1     // Nombre de capteurs, jusqu'à un par extrudeur. Définissez un FIL_RUNOUT # _PIN pour chacun.
  #define FIL_RUNOUT_PIN 19
  #define FIL_RUNOUT_INVERTING false // Réglez sur true pour inverser la logique du capteur.
  #define FIL_RUNOUT_PULLUP          // Utilisez un pullup interne pour les broches de detecteur.
  //#define FIL_RUNOUT_PULLDOWN      // Utilisez le pulldown interne pour les broches de detecteur.

  // Définissez une ou plusieurs commandes à exécuter en fonction de la position du détecteur.
  // (Après 'M412 H', Marlin demandera à l'hôte de gérer le processus.)
  #define FILAMENT_RUNOUT_SCRIPT "M600"

  // Après la détection, continuez d'imprimer cette longueur de filament avant d'exécuter 
  // le "FILAMENT_RUNOUT_SCRIPT". Utile pour un capteur à l'extrémité d'un tube. 
  // Nécessite 4 octets SRAM par capteur, plus 4 octets de surcharge.
  //#define FILAMENT_RUNOUT_DISTANCE_MM 25

  #ifdef FILAMENT_RUNOUT_DISTANCE_MM
    // Activez cette option pour utiliser un disque encodeur qui change l'état des broches de défilement 
    // lorsque le filament se déplace. (Veillez à définir FILAMENT_RUNOUT_DISTANCE_MM suffisamment 
    // élevé pour éviter les faux positifs.)
    //#define FILAMENT_MOTION_SENSOR
  #endif
#endif

//===========================================================================
//============================ Nivellement du lit ===========================
//===========================================================================
// @section calibration

/**
 * Choisissez l'une des options ci-dessous pour activer le nivelement du lit G29. 
 * Les paramètres et le comportement du G29 changeront en fonction de votre sélection.
 *
 *  Si vous utilisez une sonde pour Z Homing, activez également Z_SAFE_HOMING!
 *
 * - AUTO_BED_LEVELING_3POINT
 *   Sondez 3 points arbitraires sur le lit (qui ne sont pas colinéaires)
 *   Vous spécifiez les coordonnées XY des 3 points.
 *   Le résultat est un seul plan incliné. Idéal pour un lit plat.
 *
 * - AUTO_BED_LEVELING_LINEAR
 *   Sondez plusieurs points dans une grille.
 *   Vous spécifiez le rectangle et la densité des points d'échantillonnage.
 *   Le résultat est un seul plan incliné. Idéal pour un lit plat.
 *
 * - AUTO_BED_LEVELING_BILINEAR
 *   Sondez plusieurs points dans une grille.
 *   Vous spécifiez le rectangle et la densité des points d'échantillonnage.
 *   Le résultat est une maille, idéale pour les lits grands ou inégaux.
 *
 * - AUTO_BED_LEVELING_UBL (Unified Bed Leveling)
 *   Un système complet de mise à niveau du lit combinant les caractéristiques et les avantages 
 *   d'autres systèmes. les avantages d'autres systèmes. UBL comprend également des systèmes intégrés de 
 *   intégrés de génération de maillage, de validation de maillage et d'édition de maillage.
 *
 * - MESH_BED_LEVELING
 *   Sonder une grille manuellement
 *   Le résultat est une maille, adaptée aux lits grands ou inégaux. (Voir BILINEAR.)
 *   Pour les machines sans sonde, une méthode pour effectuerle nivellement par étapes afin  
 *   que vous puissiez ajuster manuellement la hauteur Z à chaque point de la grille.
 *   Avec un contrôleur LCD, le processus est guidé étape par étape.
 */
//#define AUTO_BED_LEVELING_3POINT
//#define AUTO_BED_LEVELING_LINEAR
//#define AUTO_BED_LEVELING_BILINEAR
//#define AUTO_BED_LEVELING_UBL
//#define MESH_BED_LEVELING

/**
 * Normalement, G28 laisse le nivellement désactivé à la fin. Activez  
 * cette option pour que G28 rétablisse l'état de mise à niveau précédent.
 */
//#define RESTORE_LEVELING_AFTER_G28

/**
 * Activez la journalisation détaillée de G28, G29, M48, etc.
 * Allumez avec la commande 'M111 S32'.
 * REMARQUE: Nécessite beaucoup de PROGMEM!
 */
//#define DEBUG_LEVELING_FEATURE

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_UBL)
  // Réduisez progressivement la correction de mise à niveau jusqu'à ce qu'une hauteur définie soit 
  // atteinte, moment auquel le mouvement sera de niveau par rapport au plan XY de la machine.
  // La hauteur peut être réglée avec M420 Z <hauteur>
  #define ENABLE_LEVELING_FADE_HEIGHT

  // Pour les machines cartésiennes, au lieu de diviser les mouvements sur les limites 
  // du maillage, divisez les mouvements en segments courts comme un Delta. Cela suit 
  // les contours du lit de plus près que les mouvements droits bord à bord.
  #define SEGMENT_LEVELED_MOVES
  #define LEVELED_SEGMENT_LENGTH 5.0 // (mm) Longueur de tous les segments (sauf le dernier)

  /**
   * Activez l'outil G26 Mesh Validation Pattern.
   */
  //#define G26_MESH_VALIDATION
  #if ENABLED(G26_MESH_VALIDATION)
    #define MESH_TEST_NOZZLE_SIZE    0.4  // (mm) Diamètre de la buse primaire.
    #define MESH_TEST_LAYER_HEIGHT   0.2  // (mm) Hauteur de couche par défaut pour l'outil de validation de maillage G26.
    #define MESH_TEST_HOTEND_TEMP  205    // (°C) Température de buse par défaut pour l'outil de validation de maillage G26.
    #define MESH_TEST_BED_TEMP      60    // (°C) Température de lit par défaut pour l'outil de validation de maillage G26.
    #define G26_XY_FEEDRATE         20    // (mm/s) Vitesse pour les mouvements XY pour l'outil de validation de maillage G26.
    #define G26_RETRACT_MULTIPLIER   1.0  // G26 Q (rétraction) utilisé par défaut entre les éléments de test de maillage.
  #endif

#endif

#if EITHER(AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_BILINEAR)

  // Définissez le nombre de points de grille par dimension.
  #define GRID_MAX_POINTS_X 3
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  // Sonder le long de l'axe Y, avancer X après chaque colonne
  //#define PROBE_Y_FIRST

  #if ENABLED(AUTO_BED_LEVELING_BILINEAR)

    // Au-delà de la grille sondée, continuez l'inclinaison implicite?
    // La valeur par défaut consiste à conserver la hauteur du bord le plus proche.
    //#define EXTRAPOLATE_BEYOND_GRID

    //
    // Subdivision expérimentale de la grille par la méthode Catmull-Rom.
    // Synthétise les points intermédiaires pour produire un maillage plus détaillé.
    //
    //#define ABL_BILINEAR_SUBDIVISION
    #if ENABLED(ABL_BILINEAR_SUBDIVISION)
      // Nombre de subdivisions entre les points de sonde
      #define BILINEAR_SUBDIVISIONS 3
    #endif

  #endif

#elif ENABLED(AUTO_BED_LEVELING_UBL)

  //===========================================================================
  //========================= Unified Bed Leveling ============================
  //===========================================================================

  //#define MESH_EDIT_GFX_OVERLAY   // Afficher une superposition graphique lors de la modification du maillage

  #define MESH_INSET 1              // Définir les limites du maillage en tant que zone exploitable du lit
  #define GRID_MAX_POINTS_X 10      // N'utilisez pas plus de 15 points par axe, implémentation limitée.
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  #define UBL_MESH_EDIT_MOVES_Z     // Les utilisateurs expérimentés préfèrent ne pas déplacer la buse
  #define UBL_SAVE_ACTIVE_ON_M500   // Enregistrer le maillage actuellement actif dans la mémoire avec M500

  //#define UBL_Z_RAISE_WHEN_OFF_MESH 2.5 // Lorsque la buse est hors du maillage, cette valeur 
                                          // est utilisée comme valeur de correction de hauteur Z.

#elif ENABLED(MESH_BED_LEVELING)

  //===========================================================================
  //=================================== Mesh ==================================
  //===========================================================================

  #define MESH_INSET 10          // Définir les limites du maillage en tant que zone exploitable du lit
  #define GRID_MAX_POINTS_X 3    // N'utilisez pas plus de 7 points par axe, implémentation limitée.
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  //#define MESH_G28_REST_ORIGIN // Après avoir référencé tous les axes ('G28' ou 'G28 XYZ'), restez Z à Z_MIN_POS

#endif // BED_LEVELING

/**
 * Ajoutez un sous-menu de mise à niveau du lit pour ABL ou MBL.
 * Incluez une procédure guidée sur le LCD si le sondage manuel est activé.
 */
//#define LCD_BED_LEVELING

#if ENABLED(LCD_BED_LEVELING)
  #define MESH_EDIT_Z_STEP  0.025 // (mm) Taille du pas lors du palpage manuel de l'axe Z.
  #define LCD_PROBE_Z_RANGE 4     // (mm) Plage Z centrée sur Z_MIN_POS pour le réglage LCD Z
  //#define MESH_EDIT_MENU        // Ajouter un menu pour modifier les points de maillage
#endif

// Ajoutez un élément de menu pour vous déplacer entre les coins du lit pour un ajustement manuel du lit
//#define LEVEL_BED_CORNERS

#if ENABLED(LEVEL_BED_CORNERS)
  #define LEVEL_CORNERS_INSET_LFRB { 30, 30, 30, 30 } // (mm) Encarts gauche, avant, droit, arrière
  #define LEVEL_CORNERS_HEIGHT      0.0   // (mm) Hauteur Z de la buse aux points de mise à niveau
  #define LEVEL_CORNERS_Z_HOP       4.0   // (mm) Hauteur Z de la buse entre les points de mise à niveau
  //#define LEVEL_CENTER_TOO              // Déplacer vers le centre après le dernier point
#endif

/**
 * Commandes à exécuter à la fin du sondage G29.
 * Utile pour rétracter ou déplacer la sonde Z à l'écart.
 */
//#define Z_PROBE_END_SCRIPT "G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10"


// @section homing

// L'origine du lit est à (X = 0, Y = 0)
//#define BED_CENTER_AT_0_0

// Définissez manuellement la position d'origine. Laissez ces paramètres non définis pour les paramètres automatiques.
// Pour DELTA, il s'agit du centre du volume d'impression cartésien.
//#define MANUAL_X_HOME_POS 0
//#define MANUAL_Y_HOME_POS 0
//#define MANUAL_Z_HOME_POS 0

// Utilisez "Z Safe Homing" pour éviter le référencement avec une sonde Z à l'extérieur de la zone du lit.
//
// Avec cette fonctionnalité activée:
//
// - Autoriser le référencement Z uniquement après le référencement X et Y ET que les pilotes pas à pas soient toujours activés.
// - Si les pilotes pas à pas sont désactivés, il faudra à nouveau un home X et Y avant un home Z 
// - Déplacez la sonde Z (ou la buse) vers un point XY défini avant Z Homing lors de la prise d'origine de tous les axes (G28).
// - Empêchez le homing Z lorsque la sonde Z est en dehors de la zone du lit.
//
//#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT ((X_BED_SIZE) / 2)    // Point X pour le référencement Z lors du référencement de tous les axes (G28).
  #define Z_SAFE_HOMING_Y_POINT ((Y_BED_SIZE) / 2)    // Point Y pour le référencement Z lors du référencement de tous les axes (G28).
#endif

// Vitesses de prise d'origine (mm / m)
#define HOMING_FEEDRATE_XY (50*60)
#define HOMING_FEEDRATE_Z  (100*60)

// Valider que les fins de course sont déclenchées lors des déplacements de référence
#define VALIDATE_HOMING_ENDSTOPS

// @section calibrate

/**
 * Compensation de l'inclinaison du lit
 *
 * Cette fonction corrige le désalignement dans les axes XYZ.
 *
 * Suivez les étapes suivantes pour obtenir l'inclinaison du lit dans le plan XY:
 *  1. Imprimer un carré de test(e.g., https://www.thingiverse.com/thing:2563185)
 *  2. Pour XY_DIAG_AC, mesurez la diagonale A à C
 *  3. Pour XY_DIAG_BD, mesurez la diagonale B à D
 *  4. Pour XY_SIDE_AD, mesurez l'arête A à D
 *
 * Marlin calcule automatiquement les facteurs d'asymétrie à partir de ces mesures.
 * Les facteurs d'inclinaison peuvent également être calculés et définis manuellement:
 *
 *  - Compute AB     : SQRT(2*AC*AC+2*BD*BD-4*AD*AD)/2
 *  - XY_SKEW_FACTOR : TAN(PI/2-ACOS((AC*AC-AB*AB-AD*AD)/(2*AB*AD)))
 *
 * Si vous le souhaitez, suivez la même procédure pour XZ et YZ.
 * Utilisez ces diagrammes pour référence:
 *
 *    Y                     Z                     Z
 *    ^     B-------C       ^     B-------C       ^     B-------C
 *    |    /       /        |    /       /        |    /       /
 *    |   /       /         |   /       /         |   /       /
 *    |  A-------D          |  A-------D          |  A-------D
 *    +-------------->X     +-------------->X     +-------------->Y
 *     XY_SKEW_FACTOR        XZ_SKEW_FACTOR        YZ_SKEW_FACTOR
 */
//#define SKEW_CORRECTION

#if ENABLED(SKEW_CORRECTION)
  // Entrez toutes les mesures de longueur ici:
  #define XY_DIAG_AC 282.8427124746
  #define XY_DIAG_BD 282.8427124746
  #define XY_SIDE_AD 200

  // Ou, définissez les facteurs d'inclinaison par défaut directement ici
  // pour remplacer les mesures ci-dessus:
  #define XY_SKEW_FACTOR 0.0

  //#define SKEW_CORRECTION_FOR_Z
  #if ENABLED(SKEW_CORRECTION_FOR_Z)
    #define XZ_DIAG_AC 282.8427124746
    #define XZ_DIAG_BD 282.8427124746
    #define YZ_DIAG_AC 282.8427124746
    #define YZ_DIAG_BD 282.8427124746
    #define YZ_SIDE_AD 200
    #define XZ_SKEW_FACTOR 0.0
      #define YZ_SKEW_FACTOR 0.0
  #endif

  // Activez cette option pour M852 pour définir l'inclinaison à l'exécution
  //#define SKEW_CORRECTION_GCODE
#endif

//=============================================================================
//============================= Additional Features ===========================
//=============================================================================

// @section extras

/**
 * EEPROM
 *
 * Stockage persistant pour conserver les paramètres configurables lors des redémarrages.
 *
 *   M500 - Stockez les paramètres dans l'EEPROM.
 *   M501 - Lisez les paramètres de l'EEPROM. (c.-à-d. supprimer les modifications non enregistrées)
 *   M502 - Rétablir les paramètres par défaut "d'usine". (Suivez avec M500 pour lancer l'EEPROM.)
 */
//#define EEPROM_SETTINGS       // Stockage persistant avec M500 et M501
//#define DISABLE_M503        // Enregistre ~ 2700 octets de PROGMEM. Désactiver pour les libérer!
#define EEPROM_CHITCHAT       // Donnez votre avis sur les commandes EEPROM. Désactiver pour enregistrer PROGMEM.
#if ENABLED(EEPROM_SETTINGS)
  //#define EEPROM_AUTO_INIT  // Initialisez l'EEPROM automatiquement en cas d'erreur.
#endif

//
// Host Keepalive
//
// Lorsqu'il est activé, Marlin enverra un message d'état occupé à l'hôte 
// toutes les deux secondes lorsqu'il ne peut pas accepter les commandes.
//
#define HOST_KEEPALIVE_FEATURE        // Désactivez-le si votre hôte n'accepte pas les messages persistants
#define DEFAULT_KEEPALIVE_INTERVAL 2  // Nombre de secondes entre les messages "occupés". régl avec M113.
#define BUSY_WHILE_HEATING            // Certains hôtes nécessitent des messages "occupés" même pendant la mise en chauffe

//
// G20/G21 Prise en charge du mode pouces
//
//#define INCH_MODE_SUPPORT

//
// M149 réglage des unités de température ( si désactivé, °C. Si activé, °F )
//
//#define TEMPERATURE_UNITS_SUPPORT

// @section temperature

// Preheat Constants
#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 180
#define PREHEAT_1_TEMP_BED     70
#define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255

#define PREHEAT_2_LABEL       "ABS"
#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    110
#define PREHEAT_2_FAN_SPEED     0 // Valeur de 0 à 255

/**
 * Nozzle Park (parckage de la buse)
 *
 * Parckerla buse a la position XYZ donnée au ralenti ou G27.
 *
 * Le paramètre "P" contrôle l'action appliquée à l'axe Z:
 *
 *    P0  (Par défaut) Si Z est en dessous de Z, soulevez la buse.
 *    P1  Soulevez toujours la buse à la hauteur du parck Z.
 *    P2  Soulevez la buse d'un montant Z-park, limité à Z_MAX_POS.
 */
#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  // Spécifiez une position de stationnement comme {X, Y, Z_raise}
  #define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 }
  #define NOZZLE_PARK_XY_FEEDRATE 100   // (mm/s) Vitesse des axes X et Y (également utilisé pour l'axe delta Z)
  #define NOZZLE_PARK_Z_FEEDRATE 5      // (mm/s) Vitesse de l'axe Z (non utilisé pour les imprimantes delta)
#endif

/**
 * Fonction de nettoyage de buse - EXPÉRIMENTAL
 *
 * Ajoute la commande G12 pour effectuer un processus de nettoyage des buses.
 *
 * Paramètres:
 *   P  Motif
 *   S  Ruptures / répétitions
 *   T  Triangles (P1 uniquement)
 *
 * Motifs:
 *   P0  Ligne droite (par défaut). Ce processus nécessite un matériau de type 
 *       éponge à un emplacement de lit fixe. "S" spécifie les traits (c'est-à-dire 
 *       les mouvements d'avant en arrière) entre les points de début / fin.
 *
 *   P1  Motif en zig-zag entre (X0, Y0) et (X1, Y1), "T" spécifie le nombre de 
 *       triangles en zig-zag à faire. "S" définit le nombre de ruptures.
 *       Les zigzags sont effectués dans la dimension la plus étroite.
 *       Par exemple, "G12 P1 S1 T3" s'exécutera:
 *
 *          --
 *         |  (X0, Y1) |     /\        /\        /\     | (X1, Y1)
 *         |           |    /  \      /  \      /  \    |
 *       A |           |   /    \    /    \    /    \   |
 *         |           |  /      \  /      \  /      \  |
 *         |  (X0, Y0) | /        \/        \/        \ | (X1, Y0)
 *          --         +--------------------------------+
 *                       |________|_________|_________|
 *                           T1        T2        T3
 *
 *   P2  Motif circulaire avec milieu à NOZZLE_CLEAN_CIRCLE_MIDDLE.
 *       "R" spécifie le rayon. "S" spécifie le nombre de traits.
 *       Avant de commencer, la buse se déplace vers NOZZLE_CLEAN_START_POINT.
 *
 *   Avertissements: le Z de fin doit être le même que le Z de départ.
 * Attention: EXPÉRIMENTAL. Les arguments du code G peuvent changer.
 *
 */
//#define NOZZLE_CLEAN_FEATURE

#if ENABLED(NOZZLE_CLEAN_FEATURE)
  // Nombre de répétitions de motif par défaut
  #define NOZZLE_CLEAN_STROKES  12

  // Nombre de triangles par défaut
  #define NOZZLE_CLEAN_TRIANGLES  3

  // Spécifiez les positions de chaque outil comme {{X, Y, Z}, {X, Y, Z}}
  // Le système à double hotend peut utiliser { {  -20, (Y_BED_SIZE / 2), (Z_MIN_POS + 1) },  {  420, (Y_BED_SIZE / 2), (Z_MIN_POS + 1) }}
  #define NOZZLE_CLEAN_START_POINT { {  30, 30, (Z_MIN_POS + 1) } }
  #define NOZZLE_CLEAN_END_POINT   { { 100, 60, (Z_MIN_POS + 1) } }

  // Rayon du motif circulaire
  #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5
  // Nombre de fragments de cercle à motif circulaire
  #define NOZZLE_CLEAN_CIRCLE_FN 10
  // Centre du cercle
  #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT

  // Déplacez la buse à sa position initiale après le nettoyage
  #define NOZZLE_CLEAN_GOBACK

  // Activer pour une station de purge / nettoyage toujours à la hauteur du portique (donc pas de mouvement Z)
  //#define NOZZLE_CLEAN_NO_Z
#endif

/**
 * Minuterie du travail d'impression
 *
 * Démarrez et arrêtez automatiquement la minuterie des travaux d'impression sur M104 / M109 / M190.
 *
 *   M104 (hotend, pas d'attente) - température Haute = aucune,                     - température basse = arrêter la minuterie
 *   M109 (hotend, attente)       - température Haute = démarrage de la minuterie   - température basse = arrêt de la minuterie 
 *   M190 (plateau, attente)      - température Haute = démarrage de la minuterie   - température basse = arrêt de la minuterie 
 *
 * La minuterie peut également être contrôlée avec les commandes suivantes:
 *
 *   M75 - Démarrer la minuterie 
 *   M76 - Mettre la minuterie en pause
 *   M77 - Arrêter la minuterie 
 */
#define PRINTJOB_TIMER_AUTOSTART

/**
 * Compteur d'impression
 *
 * Suivez les données statistiques telles que:
 *
 *  - Total travaux d'impression
 *  - Total travaux d'impression réussis
 *  - Total travaux d'impression ayant échoué
 *  - Total temps d'impression 
 *
 * Consultez les statistiques actuelles avec M78.
 */
//#define PRINTCOUNTER

//=============================================================================
//========================= Prise en charge LCD et SD =========================
//=============================================================================

// @section lcd

/**
 * LANGAGE DU LCD 
 *
 * Sélectionnez la langue à afficher sur l'écran LCD. Ces langues sont disponibles:
 *
 *   en, an, bg, ca, cz, da, de, el, el_gr, es, eu, fi, fr, gl, hr, it, jp_kana,
 *   ko_KR, nl, pl, pt, pt_br, ru, sk, tr, uk, vi, zh_CN, zh_TW, test
 *
 * :{ 'en':'English', 'an':'Aragonese', 'bg':'Bulgarian', 'ca':'Catalan', 'cz':'Czech', 'da':'Danish', 'de':'German', 'el':'Greek', 'el_gr':'Greek (Greece)', 'es':'Spanish', 'eu':'Basque-Euskera', 'fi':'Finnish', 'fr':'French', 'gl':'Galician', 'hr':'Croatian', 'it':'Italian', 'jp_kana':'Japanese', 'ko_KR':'Korean (South Korea)', 'nl':'Dutch', 'pl':'Polish', 'pt':'Portuguese', 'pt_br':'Portuguese (Brazilian)', 'ru':'Russian', 'sk':'Slovak', 'tr':'Turkish', 'uk':'Ukrainian', 'vi':'Vietnamese', 'zh_CN':'Chinese (Simplified)', 'zh_TW':'Chinese (Traditional)', 'test':'TEST' }
 */
#define LCD_LANGUAGE fr

/**
 * Jeu de caractères LCD
 *
 * Remarque: Cette option n'est PAS applicable aux affichages graphiques.
 *
 * Tous les écrans LCD basés sur des caractères fournissent 
 * ASCII plus une de ces extensions de langue:
 *
 *  - JAPANESE ... le plus courant
 *  - WESTERN  ... avec des caractères plus accentués
 *  - CYRILLIC ... pour la langue russe
 *
 * Pour déterminer l'extension linguistique installée sur votre contrôleur:
 *
 *  - Compiler et télécharger avec LCD_LANGUAGE réglé sur «test»
 *  - Cliquez sur le contrôleur pour afficher le menu LCD
 *  - L'écran LCD affichera du texte japonais, occidental ou cyrillique
 *
 * See http://marlinfw.org/docs/development/lcd_language.html
 *
 * :['JAPANESE', 'WESTERN', 'CYRILLIC']
 */
#define DISPLAY_CHARSET_HD44780 WESTERN

/**
 * Style d'écran d'information (0: Classique, 1: Prusa)
 *
 * :[0:'Classic', 1:'Prusa']
 */
#define LCD_INFO_SCREEN_STYLE 0

/**
 * CARTE SD
 *
 * La prise en charge de la carte SD est désactivée par défaut. Si votre écran dispose 
 * d'un slot SD, vous devez décommenter l'option suivante ou cela ne fonctionnera pas.
 *
 */
//#define SDSUPPORT

/**
 * SD CARD: SPI SPEED
 *
 * Activez l'un des éléments suivants pour une vitesse de transfert SPI plus lente.
 * Cela peut être nécessaire pour résoudre les erreurs "volume init".
 */
//#define SPI_SPEED SPI_HALF_SPEED
//#define SPI_SPEED SPI_QUARTER_SPEED
//#define SPI_SPEED SPI_EIGHTH_SPEED

/**
 * SD CARD: ENABLE CRC
 *
 * Utilisez les vérifications et les tentatives CRC sur la communication SD.
 */
//#define SD_CHECK_AND_RETRY

/**
 * Éléments du menu LCD
 *
 * Désactivez tous les menus et affichez uniquement l'écran d'état, ou supprimez 
 * simplement certains éléments de menu superflus pour récupérer de l'espace.
 */
//#define NO_LCD_MENUS
//#define SLIM_LCD_MENUS

//
// RÉGLAGES De la molette
// Cette option remplace le nombre d'impulsions par défaut nécessaires de l'encodeur 
// pour produire une étape. Doit être augmenté pour les encodeurs haute résolution.
//
//#define ENCODER_PULSES_PER_STEP 4

//
// Utilisez cette option pour remplacer le nombre d'impulsions requis 
// pour vous déplacer entre les éléments de menu, suivant / précédent.
//
//#define ENCODER_STEPS_PER_MENU_ITEM 1

/**
 * Options de direction de l'encodeur (molette)
 *
 * Testez d'abord le comportement de votre encodeur avec les deux options désactivées.
 *
 *  modification des valeurs et navigation dans les menus inversés: Activer REVERSE_ENCODER_DIRECTION.
 *  navigation dans les menus inversé:   Activer REVERSE_MENU_DIRECTION.
 *  modification des valeurs inversé:    Activer BOTH options.
 */

//
// Cette option inverse la direction du codeur partout.
//
//  Définissez cette option si la rotation dans le sens des aiguilles d'une montre entraîne la diminution des valeurs
//
//#define REVERSE_ENCODER_DIRECTION

//
// Cette option inverse la direction de l'encodeur pour naviguer dans les menus LCD.
//
//  Si la rotation dans le sens des aiguilles d'une montre donne normalement un deplacement vers le BAS, cela le fera monter.
//  Si la rotation dans le sens des aiguilles d'une montre donne normalement un deplacement vers le HAUT, cela le fera descendre.
//
//#define REVERSE_MENU_DIRECTION

//
// Cette option inverse le sens du codeur dans l'écran de sélection.
//
//  Si la rotation dans le sens des aiguilles d'une montre donne normalement un deplacement vers la GAUCHE, cela fera aller vers la DROITE.
//  Si la rotation dans le sens des aiguilles d'une montre donne normalement un deplacement vers la DROITE, cela fera aller vers la GAUCHE.
//
//#define REVERSE_SELECT_DIRECTION

//
// Prise d'origine individuelle
//
// Ajoutez des éléments de référencement d'axe individuel (Home X, Home Y et Home Z) au menu LCD.
//
//#define INDIVIDUAL_AXIS_HOMING_MENU

//
// HAUT-PARLEUR / BUZZER
//
// Si vous avez un haut-parleur capable de produire des sons, activez-le ici.
// Par défaut, Marlin suppose que vous avez un buzzer avec une fréquence fixe.
//
//#define SPEAKER

//
// La durée et la fréquence du son d'avertissement de l'interface utilisateur.
// Réglez-les sur 0 pour désactiver le retour audio dans les menus LCD.
//
// Remarque: testez la sortie audio avec le G-Code:
//  M300 S<frequence Hz> P<durée ms>
//
//#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 2
//#define LCD_FEEDBACK_FREQUENCY_HZ 5000

//=============================================================================
//======================== LCD / Controller Selection =========================
//========================   (Character-based LCDs)   =========================
//=============================================================================

//
// Contrôleur intelligent RepRapDiscount.
// http://reprap.org/wiki/RepRapDiscount_Smart_Controller
//
// Remarque: Habituellement vendu avec un PCB blanc.
//
//#define REPRAP_DISCOUNT_SMART_CONTROLLER 

//
// Écran LCD RADDS d'origine + encodeur + lecteur de carte SD
// http://doku.radds.org/dokumentation/lcd-display/
//
//#define RADDS_DISPLAY

//
// Contrôleur ULTIMAKER.
//
//#define ULTIMAKERCONTROLLER

//
// ULTIPANEL vu sur Thingiverse.
//
//#define ULTIPANEL

//
// PanelOne de T3P3 (via RAMPS 1.4 AUX2 / AUX3)
// http://reprap.org/wiki/PanelOne
//
//#define PANEL_ONE

//
// Contrôleur LCD / SD GADGETS3D G3D
// http://reprap.org/wiki/RAMPS_1.3/1.4_GADGETS3D_Shield_with_Panel
//
// Remarque: Habituellement vendu avec un PCB bleu.
//
//#define G3D_PANEL

//
// Contrôleur RigidBot V1.0
// http://www.inventapart.com/
//
//#define RIGIDBOT_PANEL

//
// L'imprimante Makeboard 3D mini contrôleur de l'affichage 1602 de l'imprimante 3D Mini
// https://www.aliexpress.com/item/32765887917.html
//
//#define MAKEBOARD_MINI_2_LINE_DISPLAY_1602

//
// Contrôleur ANET et Tronxy 20x4
//
//#define ZONESTAR_LCD            // Nécessite que ADC_KEYPAD_PIN soit affecté à une broche analogique.
                                  // Cet écran LCD est connu pour être sensible aux interférences électriques
                                  // qui brouille l'affichage.   Appuyez sur n'importe quel bouton pour nettoyer l'affichage.
                                  // Il s'agit d'un écran LCD2004 avec 5 boutons analogiques.

//
// LCD générique 16x2, 16x4, 20x2 ou 20x4 basé sur des caractères.
//
//#define ULTRA_LCD

//=============================================================================
//======================== LCD / Controller Selection =========================
//=====================   (I2C and Shift-Register LCDs)   =====================
//=============================================================================

//
// TYPE DE CONTRÔLEUR: I2C
//
// Remarque: Ces contrôleurs nécessitent l'installation de la bibliothèque LiquidCrystal_I2C 
// d'Arduino. Pour plus d'informations: https://github.com/kiyoshigawa/LiquidCrystal_I2C
//

//
// Panneau de contrôle de la carte Elefu RA
// http://www.elefu.com/index.php?route=product/product&product_id=53
//
//#define RA_CONTROL_PANEL

//
// Écrans LCD Sainsmart (YwRobot)
//
// Ceux-ci nécessitent la bibliothèque LiquidCrystal_I2C de F.Malpartida
// https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home
//
//#define LCD_SAINSMART_I2C_1602
//#define LCD_SAINSMART_I2C_2004

//
// Adaptateur LCD LCM1602 générique
//
//#define LCM1602

//
// LCD PANELOLU2 avec LED d'état,
// encodeur et clic d'entré séparés.
//
// Remarque: ce contrôleur nécessite la bibliothèque LiquidTWI2 d'Arduino v1.2.3 ou ultérieure.
// For more info: https://github.com/lincomatic/LiquidTWI2
//
// Remarque: L'entrée de clic de l'encodeur PANELOLU2 peut être directement connectée à 
// une broche (si BTN_ENC est définie sur! = -1) ou lire via I2C (lorsque BTN_ENC == -1).
//
//#define LCD_I2C_PANELOLU2

//
// LCD Panucatt VIKI avec LED d'état, boutons clic et G / D / H / B intégrés, clic d'entré séparé.
// boutons Click & G / D / H / B intégrés, clic d'entré séparé.
//
//#define LCD_I2C_VIKI

//
// TYPE DE CONTRÔLEUR: panneaux de registre à décalage
//

//
// LCD SR non verrouillable à 2 fils de https://goo.gl/aJJ4sH
// Configuration LCD: http://reprap.org/wiki/SAV_3D_LCD
//
//#define SAV_3DLCD

//
// LCD SR 3 fils avec stroboscope utilisant 74HC4094
// https://github.com/mikeshub/SailfishLCD
// Utilise directement le code de Sailfish
//
//#define FF_INTERFACEBOARD

//=============================================================================
//=======================   LCD / Controller Selection  =======================
//=========================      (Graphical LCDs)      ========================
//=============================================================================

//
// TYPE DE CONTRÔLEUR: graphique 128x64 (DOGM)
//
// IMPORTANT: La bibliothèque U8glib est requise pour l'affichage graphique!
//            https://github.com/olikraus/U8glib_Arduino
//

//
// Contrôleur intelligent RepRapDiscount FULL GRAPHIC
// http://reprap.org/wiki/RepRapDiscount_Full_Graphic_Smart_Controller
//
//#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER  // Modif

//
// LCD graphique ReprapWorld
// https://reprapworld.com/?products_details&products_id/1218
//
//#define REPRAPWORLD_GRAPHICAL_LCD

//
// Activez l'un d'eux si vous avez un appareil Panucatt
// Viki 2.0 ou mini Viki avec LCD graphique
// http://panucatt.com
//
//#define VIKI2
//#define miniVIKI

//
// MakerLab Mini Panel avec graphique
// contrôleur et support SD - http://reprap.org/wiki/Mini_panel
//
//#define MINIPANEL

//
// MaKr3d Makr-Panel avec contrôleur graphique et prise en charge SD.
// http://reprap.org/wiki/MaKr3d_MaKrPanel
//
//#define MAKRPANEL

//
// Contrôleur graphique complet Adafruit ST7565.
// https://github.com/eboston/Adafruit-ST7565-Full-Graphic-Controller/
//
//#define ELB_FULL_GRAPHIC_CONTROLLER

//
// BQ LCD Smart Controller livré par défaut avec 
// le BQ Hephestos 2 et Witbox 2.
//
//#define BQ_LCD_SMART_CONTROLLER

//
// Cartesio UI
// http://mauk.cc/webshop/cartesio-shop/electronics/user-interface
//
//#define CARTESIO_UI

//
// LCD pour carte Melzi avec LCD graphique
//
//#define LCD_FOR_MELZI

//
// Ulticontroller d'origine de l'imprimante Ultimaker 2 avec écran SSD1309 I2C et encodeur
// https://github.com/Ultimaker/Ultimaker2/tree/master/1249_Ulticontroller_Board_(x1)
//
//#define ULTI_CONTROLLER

//
// MKS MINI12864 avec contrôleur graphique et prise en charge SD
// https://reprap.org/wiki/MKS_MINI_12864
//
//#define MKS_MINI_12864

//
// Variante FYSETC du contrôleur graphique MINI12864 avec prise en charge SD
// https://wiki.fysetc.com/Mini12864_Panel/
//
//#define FYSETC_MINI_12864_X_X    // Type C / D / E / F. Pas de rétroéclairage RVB réglable par défaut
//#define FYSETC_MINI_12864_1_2    // Type C / D / E / F. Rétroéclairage RVB simple (toujours allumé)
//#define FYSETC_MINI_12864_2_0    // Type A/B. Rétroéclairage RVB discret
//#define FYSETC_MINI_12864_2_1    // Type A/B. Rétroéclairage RVB néopixel
//#define FYSETC_GENERIC_12864_1_1 // Affichage plus grand avec rétro-éclairage ON / OFF de base.

//
// Affichage d'usine pour Creality CR-10
// https://www.aliexpress.com/item/32833148327.html
//
// Ceci est compatible RAMPS en utilisant un seul connecteur à 10 broches.
// (Pour les propriétaires de CR-10 qui souhaitent remplacer la carte Melzi Creality mais conserver l'affichage)
//
//#define CR10_STOCKDISPLAY

//
// Écran OEM Ender-2, une variante du MKS_MINI_12864
//
//#define ENDER2_STOCKDISPLAY

//
// Contrôleur graphique ANET et Tronxy
//
// LCD graphique complet Anet 128x64 avec encodeur rotatif tel qu'utilisé sur Anet A6
// Un clone de l'affichage graphique complet RepRapDiscount mais 
// avec différentes broches / câblage (voir pins_ANET_10.h).
//
//#define ANET_FULL_GRAPHICS_LCD

//
// LCD AZSMZ 12864 avec SD
// https://www.aliexpress.com/item/32837222770.html
//
//#define AZSMZ_12864

//
// Contrôleur Silvergate GLCD
// http://github.com/android444/Silvergate
//
//#define SILVER_GATE_GLCD_CONTROLLER

//=============================================================================
//===============================  Écrans OLED  ===============================
//=============================================================================

//
// Écran générique SSD1306 OLED graphique complet
//
//#define U8GLIB_SSD1306

//
// Prise en charge du module LCD SAV OLEd utilisant des modules LCD basés sur SSD1306 ou SH1106
//
//#define SAV_3DGLCD
#if ENABLED(SAV_3DGLCD)
  #define U8GLIB_SSD1306
  //#define U8GLIB_SH1106
#endif

//
// Panneau OLED / Encodeur TinyBoy2 128x64
//
//#define OLED_PANEL_TINYBOY2

//
// CONTRÔLEUR GRAPHIQUE COMPLET MKS OLED 1,3 "128 × 64
// http://reprap.org/wiki/MKS_12864OLED
//
// Écran OLED minuscule mais très net
//
//#define MKS_12864OLED          // Utilise le contrôleur SH1106 (par défaut)
//#define MKS_12864OLED_SSD1306  // Utilise le contrôleur SSD1306

//
// Einstart S OLED SSD1306
//
//#define U8GLIB_SH1106_EINSTART

//
// Écran / contrôleur OLED Overlord avec buzzer i2c et LED
//
//#define OVERLORD_OLED

//=============================================================================
//================ Écrans d'interface utilisateur extensibles =================
//=============================================================================

//
// Écran tactile DGUS avec DWIN OS. (Choisissez-en un.)
//
//#define DGUS_LCD_UI_ORIGIN
//#define DGUS_LCD_UI_FYSETC
//#define DGUS_LCD_UI_HIPRECY

//
// LCD à écran tactile pour imprimantes Malyan M200
//
//#define MALYAN_LCD

//
// Interface utilisateur tactile pour les écrans FTDI EVE (FT800 / FT810)
// Voir Configuration_adv.h pour toutes les options de configuration.
//
//#define TOUCH_UI_FTDI_EVE

//
// Interfaces de contrôleur tierces ou personnalisées par le fournisseur.
// Les sources doivent être installées dans 'src / lcd / extensible_ui'.
//
//#define EXTENSIBLE_UI

//=============================================================================
//=============================== TFT graphiques ==============================
//=============================================================================

//
// Écran FSMC (MKS Robin, Alfawise U20, JGAurora A5S, REXYZ A1, etc.)
//
//#define FSMC_GRAPHICAL_TFT

//=============================================================================
//===========================  Autres contrôleurs  ============================
//=============================================================================

//
// ADS7843 / XPT2046 ADC Ecran tactile tel que ILI9341 2.8
//
//#define TOUCH_BUTTONS
#if ENABLED(TOUCH_BUTTONS)
  #define BUTTON_DELAY_EDIT  50 // (ms) Délai de répétition des boutons pour les écrans d'édition
  #define BUTTON_DELAY_MENU 250 // (ms) Délai de répétition des boutons pour les menus
  #define XPT2046_X_CALIBRATION   12316
  #define XPT2046_Y_CALIBRATION  -8981
  #define XPT2046_X_OFFSET       -43
  #define XPT2046_Y_OFFSET        257
#endif

//
// RepRapWorld REPRAPWORLD_KEYPAD v1.1
// http://reprapworld.com/?products_details&products_id=202&cPath=1591_1626
//
//#define REPRAPWORLD_KEYPAD
//#define REPRAPWORLD_KEYPAD_MOVE_STEP 10.0 // (mm) Distance à parcourir par pression d'une touche

//=============================================================================
//=============================== Extra Features ==============================
//=============================================================================

// @section extras

// Augmentez la fréquence FAN PWM. Supprime le bruit PWM mais augmente le chauffage dans le FET / Arduino
//#define FAST_PWM_FAN

// Utilisez le logiciel PWM pour piloter le ventilateur, comme pour les radiateurs. Cela utilise 
// une fréquence très basse qui n'est pas aussi ennuyeuse qu'avec le PWM matériel. En revanche, 
// si cette fréquence est trop faible, vous devez également incrémenter SOFT_PWM_SCALE.
//#define FAN_SOFT_PWM

// L'incrémentation de 1 doublera la fréquence du logiciel PWM, affectant 
// les chauffages et le ventilateur si FAN_SOFT_PWM est activé.
// Cependant, la résolution de contrôle sera réduite de moitié pour chaque 
// incrément; à la valeur zéro, il y a 128 positions de contrôle efficaces.
// :[0,1,2,3,4,5,6,7]
#define SOFT_PWM_SCALE 0

// Si SOFT_PWM_SCALE est défini sur une valeur supérieure à 0, 
// le tramage peut être utilisé pour atténuer la perte de résolution associée. 
// S'il est activé, certains des cycles PWM sont étirés de sorte qu'en moyenne 
// le cycle de service souhaité est atteint.
//#define SOFT_PWM_DITHER

// LED d'état de température qui affichent la température de la buse et du plateau
// Si tous les hotends, la température du lit et la température cible sont inférieurs à 54 ° C, 
// la LED BLEUE est allumée. Sinon, la LED ROUGE est allumée. (Hystérésis 1C)
//#define TEMP_STAT_LEDS

// SkeinForge envoie les codes G d'arc incorrects lors de l'utilisation d'Arc Point comme procédure de fin
//#define SF_ARC_FIX

// Prise en charge de l'extrudeur BariCUDA
//#define BARICUDA

// Prise en charge de BlinkM / CyzRgb
//#define BLINKM

// Prise en charge du pilote LED PCA9632 PWM
//#define PCA9632

// Prise en charge du pilote LED PWM PCA9533
// https://github.com/mikeshub/SailfishRGB_LED
//#define PCA9533

/**
 * RGB LED / LED Strip Control
 *
 * Activez la prise en charge d'une LED RVB connectée à des broches numériques 5 V 
 * ou d'une bande RVB connectée à des MOSFET contrôlés par des broches numériques.
 *
 * Ajoute la commande M150 pour définir la couleur de la LED (ou bande de LED).
 * Si les broches sont compatibles PWM (par exemple, 4, 5, 6, 11), 
 * une plage de valeurs de luminance peut être définie de 0 à 255.
 * Pour la LED Neopixel, un paramètre de luminosité globale est également disponible.
 *
 * *** MISE EN GARDE ***
 *  Les bandes de LED nécessitent une puce MOSFET entre les lignes PWM et les LED, 
 *  car l'Arduino ne peut pas gérer le courant dont les LED auront besoin.
 *  Le non-respect de cette précaution peut détruire votre Arduino!
 *  REMARQUE: une alimentation séparée de 5 V est requise! La LED Neopixel a besoin 
 *  de plus de courant que le régulateur linéaire Arduino 5V peut produire.
 * *** MISE EN GARDE ***
 *
 * Type de LED. Activez une seule des deux options suivantes.
 *
 */
//#define RGB_LED
//#define RGBW_LED

#if EITHER(RGB_LED, RGBW_LED)
  //#define RGB_LED_R_PIN 34
  //#define RGB_LED_G_PIN 43
  //#define RGB_LED_B_PIN 35
  //#define RGB_LED_W_PIN -1
#endif

// Prise en charge du pilote LED Adafruit Neopixel
//#define NEOPIXEL_LED
#if ENABLED(NEOPIXEL_LED)
  #define NEOPIXEL_TYPE   NEO_GRBW // NEO_GRBW / NEO_GRB - type de pilote quatre / trois canaux (défini dans Adafruit_NeoPixel.h)
  #define NEOPIXEL_PIN     4       // Pin de contrôle des LED
  //#define NEOPIXEL2_TYPE NEOPIXEL_TYPE
  //#define NEOPIXEL2_PIN    5
  #define NEOPIXEL_PIXELS 30       // Nombre de LED dans la bande, plus grande de 2 bandes si 2 bandes de néopixels sont utilisées
  #define NEOPIXEL_IS_SEQUENTIAL   // Affichage séquentiel pour changement de température - LED par LED. Désactivez pour changer toutes les LED en même temps.
  #define NEOPIXEL_BRIGHTNESS 127  // Luminosité initiale (0-255)
  //#define NEOPIXEL_STARTUP_TEST  // Parcourez les couleurs au démarrage

  // Utilisez une seule LED Neopixel pour un éclairage statique (en arrière-plan)
  //#define NEOPIXEL_BKGD_LED_INDEX  0               // Index of the LED to use
  //#define NEOPIXEL_BKGD_COLOR { 255, 255, 255, 0 } // R, G, B, W
#endif

/**
 * Voyants d'événement de l'imprimante
 *
 * Pendant l'impression, les voyants reflètent l'état de l'imprimante:
 *
 *  - Passez progressivement du bleu au violet lorsque le lit chauffé atteint la température cible
 *  - Passez progressivement du violet au rouge à mesure que le hotend atteint la température
 *  - Passez au blanc pour éclairer la surface de travail
 *  - Passer au vert une fois l'impression terminée
 *  - Désactiver une fois l'impression terminée et l'utilisateur a appuyé sur un bouton
 */
#if ANY(BLINKM, RGB_LED, RGBW_LED, PCA9632, PCA9533, NEOPIXEL_LED)
  #define PRINTER_EVENT_LEDS
#endif

/**
 * R/C SERVO support
 * Sponsorisé par TrinityLabs, retravaillé par codexmas
 */

/**
 * Nombre de servos
 *
 * Pour certaines options liées aux servos, NUM_SERVOS sera défini automatiquement.
 * Réglez-le manuellement s'il y a des servos supplémentaires nécessitant un contrôle manuel.
 * Laissez indéfini ou défini sur 0 pour désactiver entièrement le sous-système d'asservissement.
 */
//#define NUM_SERVOS 3 // Servo index starts with 0 for M280 command

// (ms) Délai avant que le prochain mouvement ne commence, pour donner au servo le temps d'atteindre son angle cible.
// 300 ms est une bonne valeur mais vous pouvez essayer une valeur plus petite.
// Si le servo ne peut pas atteindre la position demandée, augmentez-la.
#define SERVO_DELAY { 300 }

// Only power servos during movement, otherwise leave off to prevent jitter
//#define DEACTIVATE_SERVOS_AFTER_MOVE

// Permettre à l'angle d'asservissement d'être modifié et enregistré dans l'EEPROM
//#define EDITABLE_SERVO_ANGLES
