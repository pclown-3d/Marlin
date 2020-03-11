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
 * Configuration_adv.h
 *
 * Réglages avancés.
 * Modifiez-les uniquement si vous savez exactement ce que vous faites.
 * Certains de ces paramètres peuvent endommager votre imprimante s'ils sont mal configurés!
 *
 * Les paramètres de base se trouvent dans Configuration.h
 *
 */
#define CONFIGURATION_ADV_H_VERSION 020004

// @section temperature

//===========================================================================
//========================== Paramètres thermiques  =========================
//===========================================================================

//
// Paramètres personnalisés de la thermistance 1000
//
#if TEMP_SENSOR_0 == 1000
  #define HOTEND0_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND0_RESISTANCE_25C_OHMS  100000  // Résistance à 25 °C
  #define HOTEND0_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_1 == 1000
  #define HOTEND1_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND1_RESISTANCE_25C_OHMS  100000  // Résistance à 25 °C
  #define HOTEND1_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_2 == 1000
  #define HOTEND2_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND2_RESISTANCE_25C_OHMS  100000  // Résistance à 25 °C
  #define HOTEND2_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_3 == 1000
  #define HOTEND3_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND3_RESISTANCE_25C_OHMS  100000  // Résistance à 25 °C
  #define HOTEND3_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_4 == 1000
  #define HOTEND4_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND4_RESISTANCE_25C_OHMS  100000  // Résistance à 25 °C
  #define HOTEND4_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_5 == 1000
  #define HOTEND5_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND5_RESISTANCE_25C_OHMS  100000  // Résistance à 25 °C
  #define HOTEND5_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_6 == 1000
  #define HOTEND6_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND6_RESISTANCE_25C_OHMS  100000  // Résistance à 25 °C
  #define HOTEND6_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_7 == 1000
  #define HOTEND7_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define HOTEND7_RESISTANCE_25C_OHMS  100000  // Résistance à 25 °C
  #define HOTEND7_BETA                 3950    // Valeur bêta
#endif

#if TEMP_SENSOR_BED == 1000
  #define BED_PULLUP_RESISTOR_OHMS     4700    // Résistance pullup
  #define BED_RESISTANCE_25C_OHMS      100000  // Résistance à 25 °C
  #define BED_BETA                     3950    // Valeur bêta
#endif

#if TEMP_SENSOR_CHAMBER == 1000
  #define CHAMBER_PULLUP_RESISTOR_OHMS 4700    // Résistance pullup
  #define CHAMBER_RESISTANCE_25C_OHMS  100000  // Résistance à 25 °C
  #define CHAMBER_BETA                 3950    // Valeur bêta
#endif

//
// Kit de mise à niveau de lit chauffant Hephestos 2 24V.
// https://store.bq.com/en/heated-bed-kit-hephestos2
//
//#define HEPHESTOS2_HEATED_BED_KIT
#if ENABLED(HEPHESTOS2_HEATED_BED_KIT)
  #undef TEMP_SENSOR_BED
  #define TEMP_SENSOR_BED 70
  #define HEATER_BED_INVERTING true
#endif

/**
 * Paramètres du caisson chauffé "Chamber settings"
 */
#if TEMP_SENSOR_CHAMBER
  #define CHAMBER_MINTEMP             5
  #define CHAMBER_MAXTEMP            60
  #define TEMP_CHAMBER_HYSTERESIS     1   // (°C) Différence de température considérée comme "suffisamment proche" de la cible
  //#define CHAMBER_LIMIT_SWITCHING
  //#define HEATER_CHAMBER_PIN       44   // Broche marche / arrêt du chauffage du caisson
  //#define HEATER_CHAMBER_INVERTING false
#endif

#if DISABLED(PIDTEMPBED)
  #define BED_CHECK_INTERVAL 5000 // ms entre les contrôles dans le contrôle du bang-bang
  #if ENABLED(BED_LIMIT_SWITCHING)
    #define BED_HYSTERESIS 2 // Désactiver le chauffage uniquement si T> cible + BED_HYSTERESIS et activer le chauffage si T> cible-BED_HYSTERESIS
  #endif
#endif

/**
 * La protection thermique offre une protection supplémentaire à votre imprimante contre les  
 * dommages et les incendies. Marlin comprend toujours des plages de températures minimales 
 * et maximales sûres qui protègent contre un fil de thermistance cassé ou déconnecté.
 *
 * Le problème: si une thermistance tombe, elle signalera la température 
 * beaucoup plus basse que l'air dans la pièce et le micrologiciel 
 * gardera le chauffage allumé.
 *
 * La solution: Une fois que la température atteint la cible, commencez à observer.
 * Si la température reste trop en dessous de la cible (hystérésis) pendant trop 
 * longtemps (période), le micrologiciel arrêtera la machine par mesure de sécurité.
 *
 * Si vous obtenez des faux positifs pour "Thermal Runaway", augmentez 
 * THERMAL_PROTECTION_HYSTERESIS et / ou THERMAL_PROTECTION_PERIOD
 */
#if ENABLED(THERMAL_PROTECTION_HOTENDS)
  #define THERMAL_PROTECTION_PERIOD 40        // Secondes
  #define THERMAL_PROTECTION_HYSTERESIS 4     // Degrés Celsius

  //#define ADAPTIVE_FAN_SLOWING              // Ralentir le ventilateur de refroidissement en cas de baisse de température
  #if BOTH(ADAPTIVE_FAN_SLOWING, PIDTEMP)
    //#define NO_FAN_SLOWING_IN_PID_TUNING    // Ne ralentissez pas la vitesse du ventilateur pendant M303
  #endif

  /**
   * Chaque fois qu'un M104, M109 ou M303 augmente la température cible, le micrologiciel 
   * attend que le WATCH_TEMP_PERIOD expire. Si la température n'a pas augmenté 
   * de WATCH_TEMP_INCREASE degrés, la machine est arrêtée et nécessite 
   * une réinitialisation matérielle. Ce test redémarre avec n'importe quel 
   * M104 / M109 / M303, mais uniquement si la température actuelle est 
   * suffisamment éloignée de la cible pour un test fiable.
   *
   * Si vous obtenez des faux positifs pour "Échec de chauffage" (Heating failed), 
   * augmentez WATCH_TEMP_PERIOD et / ou diminuez WATCH_TEMP_INCREASE. 
   * WATCH_TEMP_INCREASE ne doit pas être inférieur à 2.
   */
  #define WATCH_TEMP_PERIOD 20                // Secondes
  #define WATCH_TEMP_INCREASE 2               // Degrés Celsius
#endif

/**
 * Les paramètres de protection thermique du plateau sont les mêmes que ci-dessus pour les hotends.
 */
#if ENABLED(THERMAL_PROTECTION_BED)
  #define THERMAL_PROTECTION_BED_PERIOD        20 // Secondes
  #define THERMAL_PROTECTION_BED_HYSTERESIS     2 // Degrés Celsius

  /**
   * Comme décrit ci-dessus, à l'exception du lit (M140 / M190 / M303).
   */
  #define WATCH_BED_TEMP_PERIOD                60 // Secondes
  #define WATCH_BED_TEMP_INCREASE               2 // Degrés Celsius
#endif

/**
 * Paramètres de protection thermique pour le caisson chauffée.
 */
#if ENABLED(THERMAL_PROTECTION_CHAMBER)
  #define THERMAL_PROTECTION_CHAMBER_PERIOD    20 // Secondes
  #define THERMAL_PROTECTION_CHAMBER_HYSTERESIS 2 // Degrés Celsius

  /**
   * Réglages du caisson chauffé (M141 / M191).
   */
  #define WATCH_CHAMBER_TEMP_PERIOD            60 // Secondes
  #define WATCH_CHAMBER_TEMP_INCREASE           2 // Degrés Celsius
#endif

#if ENABLED(PIDTEMP)
  // Ajoutez un terme expérimental supplémentaire à la puissance du réchauffeur, proportionnel à la vitesse d'extrusion.
  // Une valeur Kc bien choisie devrait ajouter juste assez de puissance pour faire fondre le volume de matériau accru.
  //#define PID_EXTRUSION_SCALING
  #if ENABLED(PID_EXTRUSION_SCALING)
    #define DEFAULT_Kc (100) //heating power=Kc*(e_speed)
    #define LPQ_MAX_LEN 50
  #endif

  /**
   * Ajoutez un terme expérimental supplémentaire à la puissance du chauffage, proportionnel à la vitesse du ventilateur.
   * Une valeur Kf bien choisie devrait ajouter juste assez de puissance pour compenser la perte de puissance du ventilateur de refroidissement.
   * Vous pouvez simplement ajouter une compensation constante avec la valeur DEFAULT_Kf 
   * ou suivre les instructions ci-dessous pour obtenir une compensation en fonction de la vitesse.
   *
   * Compensation constante (à utiliser uniquement avec des vitesses de ventilation de 0% et 100%)
   * ---------------------------------------------------------------------
   * Un bon point de départ pour la valeur Kf provient du calcul:
   *   kf = (power_fan * eff_fan) / power_heater * 255
   * où eff_fan est compris entre 0,0 et 1,0, en fonction de l'efficacité du ventilateur et du débit d'air vers la buse / l'élément chauffant.
   *
   * Example:
   *   Chauffage: 40 W, ventilateur: 0,1 A * 24 V = 2,4 W, eff_fan = 0,8
   *   Kf = (2.4W * 0.8) / 40W * 255 = 12.24
   *
   * Compensation en fonction de la vitesse du ventilateur
   * --------------------------------
   * 1. Pour trouver une bonne valeur Kf, réglez la température du hotend, attendez qu'elle se stabilise et activez le ventilateur (100%).
   *    Assurez-vous que PID_FAN_SCALING_LIN_FACTOR est égal à 0 et que PID_FAN_SCALING_ALTERNATIVE_DEFINITION n'est pas activé.
   *    Si vous voyez la baisse de température, répétez le test en augmentant lentement la valeur Kf jusqu'à ce que la 
   *    baisse de température disparaisse. Si la température dépasse après avoir activé le ventilateur, la valeur Kf est trop grande.
   * 2. Notez la valeur Kf pour la vitesse du ventilateur à 100%
   * 3. Déterminez une bonne valeur pour PID_FAN_SCALING_MIN_SPEED, qui se situe autour de la vitesse à laquelle le ventilateur commence à bouger.
   * 4. Répétez les étapes 1. et 2. pour cette vitesse de ventilateur.
   * 5. Activez PID_FAN_SCALING_ALTERNATIVE_DEFINITION et entrez les deux valeurs Kf identifiées dans PID_FAN_SCALING_AT_FULL_SPEED  
   *    et PID_FAN_SCALING_AT_MIN_SPEED. Entrez la vitesse minimale dans PID_FAN_SCALING_MIN_SPEED
   */
  //#define PID_FAN_SCALING
  #if ENABLED(PID_FAN_SCALING)
    //#define PID_FAN_SCALING_ALTERNATIVE_DEFINITION
    #if ENABLED(PID_FAN_SCALING_ALTERNATIVE_DEFINITION)
      // La définition alternative est utilisée pour une configuration plus facile.
      // Il suffit de renseigner Kf à pleine vitesse (255) et PID_FAN_SCALING_MIN_SPEED.
      // DEFAULT_Kf et PID_FAN_SCALING_LIN_FACTOR sont calculés en conséquence.

      #define PID_FAN_SCALING_AT_FULL_SPEED 13.0        //=PID_FAN_SCALING_LIN_FACTOR*255+DEFAULT_Kf
      #define PID_FAN_SCALING_AT_MIN_SPEED 6.0          //=PID_FAN_SCALING_LIN_FACTOR*PID_FAN_SCALING_MIN_SPEED+DEFAULT_Kf
      #define PID_FAN_SCALING_MIN_SPEED 10.0            // Vitesse minimale du ventilateur à laquelle activer PID_FAN_SCALING

      #define DEFAULT_Kf (255.0*PID_FAN_SCALING_AT_MIN_SPEED-PID_FAN_SCALING_AT_FULL_SPEED*PID_FAN_SCALING_MIN_SPEED)/(255.0-PID_FAN_SCALING_MIN_SPEED)
      #define PID_FAN_SCALING_LIN_FACTOR (PID_FAN_SCALING_AT_FULL_SPEED-DEFAULT_Kf)/255.0

    #else
      #define PID_FAN_SCALING_LIN_FACTOR (0)             // Perte de puissance due au refroidissement = Kf * (fan_speed)
      #define DEFAULT_Kf 10                              // Une valeur constante ajoutée au tuner PID
      #define PID_FAN_SCALING_MIN_SPEED 10               // Vitesse minimale du ventilateur à laquelle activer PID_FAN_SCALING
    #endif
  #endif
#endif

/**
 * Température automatique:
 * La température cible hotend est calculée par toutes les lignes contenue dans le buffer de gcode.
 * Le nombre maximum de pas contenus dans le buffer / s du moteur de l'extrudeuse est appelé "se".
 * Démarrer le mode autotemp avec M109 S <mintemp> B <maxtemp> F <factor>
 * La température cible est réglée sur mintemp + facteur * se [pas / sec] et est limitée par 
 * mintemp et maxtemp. Désactivez cette option en exécutant M109 sans F *
 * De plus, si la température est réglée sur une valeur inférieure à la température minimale, elle ne sera pas modifiée par la température automatique.
 * Sur une Ultimaker, certains tests initiaux ont fonctionné avec M109 S215 B260 F1 dans le start.gcode
 */
#define AUTOTEMP
#if ENABLED(AUTOTEMP)
  #define AUTOTEMP_OLDWEIGHT 0.98
#endif

// Afficher des informations de position supplémentaires avec 'M114 D'
//#define M114_DETAIL

// Afficher la valeur ADC de la température
// Activer M105 pour inclure les valeurs ADC lues à partir des capteurs de température.
//#define SHOW_TEMP_ADC_VALUES

/**
 * Support de thermistance haute température
 *
 * Les thermistances capables de supporter des températures élevées ont généralement du mal à obtenir de bonnes 
 * lectures à température ambiante et à des températures plus basses. Cela signifie que 
 * HEATER_X_RAW_LO_TEMP sera probablement utilisé lorsque l'élément chauffant s'allumera pour 
 * la première fois pendant le processus de préchauffage, ce qui déclenchera une min_temp_error 
 * comme mesure de sécurité et forcera à tout arrêter.
 * Pour contourner cette limitation, nous autorisons un temps de préchauffage 
 * (pendant lequel min_temp_error ne sera pas déclenché) et ajoutons un tampon 
 * min_temp pour gérer les lectures aberrantes.
 *
 * Si vous souhaitez activer cette fonctionnalité pour votre ou vos thermistances 
 * hotend, décommentez et définissez des valeurs> 0 dans les constantes ci-dessous
 */

// Nombre d'erreurs consécutives à basse température pouvant survenir avant 
// le déclenchement d'une erreur min_temp_error. (Ne devrait pas dépasser 10.)
//#define MAX_CONSECUTIVE_LOW_TEMPERATURE_ERROR_ALLOWED 0

// Le nombre de millisecondes qu'un hotend préchauffera avant de commencer à 
// vérifier la température. Cette valeur ne doit PAS être réglée sur le temps qu'il faut à  
// l'extrémité chaude pour atteindre la température cible, mais le temps qu'il faut pour atteindre la 
// température minimale que votre thermistance peut lire. La plus basse est la meilleure / la plus sûr.
// Cela ne devrait pas durer plus de 30 secondes (30000)
//#define MILLISECONDS_PREHEAT_TIME 0

// @section extrudeur

// Prévention dde l'obstruction de la tête.
// Si la machine est inactive et que la température dépasse MINTEMP, 
// extrudez du filament toutes les deux SECONDES.
//#define EXTRUDER_RUNOUT_PREVENT
#if ENABLED(EXTRUDER_RUNOUT_PREVENT)
  #define EXTRUDER_RUNOUT_MINTEMP 190
  #define EXTRUDER_RUNOUT_SECONDS 30
  #define EXTRUDER_RUNOUT_SPEED 1500  // (mm/m)
  #define EXTRUDER_RUNOUT_EXTRUDE 5   // (mm)
#endif

// @section temperature

// Calibration pour capteur AD595 / AD8495 pour ajuster les mesures de température.
// La température finale est calculée comme (mesureTemp * GAIN) + OFFSET.
#define TEMP_SENSOR_AD595_OFFSET  0.0
#define TEMP_SENSOR_AD595_GAIN    1.0
#define TEMP_SENSOR_AD8495_OFFSET 0.0
#define TEMP_SENSOR_AD8495_GAIN   1.0

/**
 * Ventilateur du contrôleur (de la carte electronique)
 * Pour refroidir les pilotes pas à pas et les MOSFET.
 *
 * Le ventilateur s'allumera automatiquement chaque fois qu'un moteur pas à pas est activé et 
 * s'éteindra après une période définie une fois que tous les moteurs pas à pas auront été éteints.
 */
//#define USE_CONTROLLER_FAN
#if ENABLED(USE_CONTROLLER_FAN)
  //#define CONTROLLER_FAN_PIN -1           // Définir une broche personnalisée pour le ventilateur du contrôleur
  #define CONTROLLERFAN_SECS 60             // Durée en secondes pendant laquelle le ventilateur fonctionne après l'arrêt de tous les moteurs
  #define CONTROLLERFAN_SPEED 255           // 255 == pleine vitesse
  //#define CONTROLLERFAN_SPEED_Z_ONLY 127  // Réduisez le bruit sur les machines qui gardent Z activé
#endif

// Lors du premier démarrage du ventilateur principal, faites-le tourner à pleine vitesse pendant 
// le nombre de millisecondes donné.  Cela permet au ventilateur de tourner de manière 
// fiable avant de définir une valeur PWM.. (Ne fonctionne pas avec le logiciel PWM pour fan sur Sanguinololu)
//#define FAN_KICKSTART_TIME 100

// Certains ventilateur de refroidissement peuvent nécessiter un état "arrêt" non nul.
//#define FAN_OFF_PWM  1

/**
 * Mise à l'échelle du ventilateur PWM
 *
 * Définissez les vitesses min / max pour les ventilateurs PWM (comme défini avec M106).
 *
 * Avec ces options, la plage de valeurs M106 0-255 est mise à l'échelle en un sous-ensemble 
 * pour garantir que le ventilateur a suffisamment de puissance pour tourner, ou pour faire 
 * fonctionner des ventilateurs à courant plus faible avec un courant plus élevé. 
 * (par exemple, ventilateurs 5V / 12V avec 12V / 24V) La valeur 0 éteint toujours le ventilateur.
 *
 * Définissez l'un ou les deux pour remplacer la plage 0-255 par défaut.
 */
//#define FAN_MIN_PWM 50
//#define FAN_MAX_PWM 128

/**
 * Paramètres FAN PWM FAN
 *
 * Utilisez pour changer la fréquence PWM FAST FAN (si activé dans Configuration.h)
 * Des combinaisons de modes PWM, de valeurs de pré-échelle et de résolutions HAUTE sont utilisées 
 * en interne pour produire une fréquence aussi proche que possible de la fréquence souhaitée.
 *
 * FAST_PWM_FAN_FREQUENCY [non défini par défaut]
 *   Réglez-le sur la fréquence souhaitée.
 *   Si elle n'est pas défini, cette valeur par défaut est F = F_CPU / (2 * 255 * 1)
 *   c'est-à-dire, F = 31,4 kHz sur les microcontrôleurs 16 MHz ou F = 39,2 kHz sur les microcontrôleurs 20 MHz.
 *   Ces valeurs par défaut sont les mêmes qu'avec l'ancienne implémentation FAST_PWM_FAN - aucune migration n'est requise
 *   REMARQUE: le réglage de très basses fréquences (<10 Hz) peut entraîner un comportement inattendu de la minuterie.
 *
 * USE_OCR2A_AS_TOP [non défini par défaut]
 *  Les cartes qui utilisent TIMER2 pour PWM ont des limitations entraînant seulement quelques fréquences possibles sur TIMER2:
 *   16MHz MCUs: [62.5KHz, 31.4KHz (default), 7.8KHz, 3.92KHz, 1.95KHz, 977Hz, 488Hz, 244Hz, 60Hz, 122Hz, 30Hz]
 *   20MHz MCUs: [78.1KHz, 39.2KHz (default), 9.77KHz, 4.9KHz, 2.44KHz, 1.22KHz, 610Hz, 305Hz, 153Hz, 76Hz, 38Hz]
 *   Une plus grande plage peut être obtenue en activant USE_OCR2A_AS_TOP. Mais notez que cette option bloque l'utilisation de 
 *   PWM sur la broche OC2A. N'utilisez cette option que si vous n'avez pas besoin de PWM sur 0C2A. (Vérifiez votre schéma.)
 *   USE_OCR2A_AS_TOP sacrifie la résolution de contrôle du rapport cyclique pour atteindre cette plus large gamme de fréquences.
 */
#if ENABLED(FAST_PWM_FAN)
  //#define FAST_PWM_FAN_FREQUENCY 31400
  //#define USE_OCR2A_AS_TOP
#endif

// @section extrudeur

/**
 * Ventilateurs de refroidissement pour extrudeur
 *
 * Les ventilateurs automatiques d'extrudeur s'activent automatiquement lorsque la 
 * température de leurs extrudeurs dépasse EXTRUDER_AUTO_FAN_TEMPERATURE.
 *
 * Le fichier de broches de votre carte spécifie les broches recommandées. 
 * Remplacez-les ici ou définissez-le sur -1 pour désactiver complètement.
 *
 * Plusieurs extrudeurs peuvent être affectées à la même broche, auquel cas le ventilateur 
 * se mettra en marche lorsqu'un extrudeur sélectionné ateindra une température supérieure au seuil.
 */
#define E0_AUTO_FAN_PIN -1
#define E1_AUTO_FAN_PIN -1
#define E2_AUTO_FAN_PIN -1
#define E3_AUTO_FAN_PIN -1
#define E4_AUTO_FAN_PIN -1
#define E5_AUTO_FAN_PIN -1
#define CHAMBER_AUTO_FAN_PIN -1

#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED 255   // 255 == pleine vitesse
#define CHAMBER_AUTO_FAN_TEMPERATURE 30
#define CHAMBER_AUTO_FAN_SPEED 255

/**
 * Multiplexeur de ventilateur de refroidissement
 *
 * Cette fonction vous permet de multiplexer numériquement la sortie du ventilateur.
 * Le multiplexeur est automatiquement commuté lors du changement d'outil.
 * Définissez les FANMUX [012] _PIN ci-dessous pour jusqu'à 2, 4 ou 8 ventilateurs multiplexés.
 */
#define FANMUX0_PIN -1
#define FANMUX1_PIN -1
#define FANMUX2_PIN -1

/**
 * M355 Voyant allumé / éteint
 */
//#define CASE_LIGHT_ENABLE
#if ENABLED(CASE_LIGHT_ENABLE)
  //#define CASE_LIGHT_PIN 4                  // Remplacez la broche par défaut si nécessaire
  #define INVERT_CASE_LIGHT false             // Définir vrai si le voyant du boîtier est allumé lorsque la broche est LOW
  #define CASE_LIGHT_DEFAULT_ON true          // Activer l'état de démarrage par défaut
  #define CASE_LIGHT_DEFAULT_BRIGHTNESS 105   // Définir la luminosité de démarrage par défaut (0-255, nécessite une broche PWM)
  //#define CASE_LIGHT_MAX_PWM 128            // Limite pwm
  //#define CASE_LIGHT_MENU                   // Ajouter des options de lumière de boîtier au menu LCD
  //#define CASE_LIGHT_NO_BRIGHTNESS          // Désactivez le contrôle de la luminosité. Activer pour l'éclairage non PWM.
  //#define CASE_LIGHT_USE_NEOPIXEL           // Utilisez Neopixel LED comme éclairage de boîtier, nécessite NEOPIXEL_LED.
  #if ENABLED(CASE_LIGHT_USE_NEOPIXEL)
    #define CASE_LIGHT_NEOPIXEL_COLOR { 255, 255, 255, 255 } // { Rouge, vert, bleu, blanc }
  #endif
#endif

// @section homing

// Si vous souhaitez que les butées restent activées (par défaut) même si elles ne sont pas 
// en prise d'origine, activez cette option. Remplacez à tout moment avec M120, M121.
//#define ENDSTOPS_ALWAYS_ON_DEFAULT

// @section extras

//#define Z_LATE_ENABLE // Activez Z au dernier moment. Nécessaire si votre pilote Z surchauffe.

// Utilisez un contrôleur externe en boucle fermée. Remplacez les broches ici si nécessaire.
//#define EXTERNAL_CLOSED_LOOP_CONTROLLER
#if ENABLED(EXTERNAL_CLOSED_LOOP_CONTROLLER)
  //#define CLOSED_LOOP_ENABLE_PIN        -1
  //#define CLOSED_LOOP_MOVE_COMPLETE_PIN -1
#endif

/**
 * Double pas à pas / double butée
 *
 * Cette section vous permettra d'utiliser des pilotes E supplémentaires pour entraîner un deuxième moteur pour les axes X, Y ou Z.
 *
 * Par exemple, définissez le paramètre X_DUAL_STEPPER_DRIVERS pour utiliser un deuxième moteur. Si les moteurs 
 * doivent tourner dans des directions opposées, réglez INVERT_X2_VS_X_DIR. Si le deuxième moteur a besoin de son 
 * propre arrêt, définissez X_DUAL_ENDSTOPS. Cela peut s'ajuster pour le "soutirage". Utilisez X2_USE_ENDSTOP pour définir 
 * le endstop qui doit être utilisé pour le deuxième arrêt. Des butées supplémentaires apparaîtront dans la sortie de «M119».
 *
 * Utilisez X_DUAL_ENDSTOP_ADJUSTMENT pour régler l'imperfection mécanique. Après avoir référencé les deux moteurs, 
 * ce décalage est appliqué au moteur X2. Pour trouver le décalage d'origine de l'axe X et mesurer l'erreur dans X2. Des décalages 
 * de fin de course doubles peuvent être définis lors de l'exécution avec 'M666 X <décalage> Y <décalage> Z <décalage>'.
 */

//#define X_DUAL_STEPPER_DRIVERS
#if ENABLED(X_DUAL_STEPPER_DRIVERS)
  #define INVERT_X2_VS_X_DIR true   // Définissez sur «true» si les moteurs X doivent tourner dans des directions opposées
  //#define X_DUAL_ENDSTOPS
  #if ENABLED(X_DUAL_ENDSTOPS)
    #define X2_USE_ENDSTOP _XMAX_
    #define X2_ENDSTOP_ADJUSTMENT  0
  #endif
#endif

//#define Y_DUAL_STEPPER_DRIVERS
#if ENABLED(Y_DUAL_STEPPER_DRIVERS)
  #define INVERT_Y2_VS_Y_DIR true   // Définissez sur «true» si les moteurs X doivent tourner dans des directions opposées
  //#define Y_DUAL_ENDSTOPS
  #if ENABLED(Y_DUAL_ENDSTOPS)
    #define Y2_USE_ENDSTOP _YMAX_
    #define Y2_ENDSTOP_ADJUSTMENT  0
  #endif
#endif

//
// Pour Z, définissez le nombre de pilotes pas à pas
//
#define NUM_Z_STEPPER_DRIVERS 1   // (1-4) Les options Z changent en fonction du nombre

#if NUM_Z_STEPPER_DRIVERS > 1
  //#define Z_MULTI_ENDSTOPS
  #if ENABLED(Z_MULTI_ENDSTOPS)
    #define Z2_USE_ENDSTOP          _XMAX_
    #define Z2_ENDSTOP_ADJUSTMENT   0
    #if NUM_Z_STEPPER_DRIVERS >= 3
      #define Z3_USE_ENDSTOP        _YMAX_
      #define Z3_ENDSTOP_ADJUSTMENT 0
    #endif
    #if NUM_Z_STEPPER_DRIVERS >= 4
      #define Z4_USE_ENDSTOP        _ZMAX_
      #define Z4_ENDSTOP_ADJUSTMENT 0
    #endif
  #endif
#endif

/**
 * Chariot Dual X
 *
 * Cette configuration a deux chariots X qui peuvent se déplacer indépendamment, chacun avec son propre hotend.
 * Les chariots peuvent être utilisés pour imprimer un objet avec deux couleurs ou matériaux, ou en  
 * "mode de duplication", il peut imprimer deux objets identiques ou en miroir X simultanément.
 * Le chariot inactif est stationné automatiquement pour éviter le suintement du filament.
 * X1 est le chariot gauche, X2 la droite. Ils se garent et se logent aux extrémités opposées de l'axe X.
 * Par défaut, le stepper X2 est affecté à la première prise E inutilisée de la carte.
 *
 * Les modes Dual X Carriage suivants peuvent être sélectionnés avec le M605 S <mode>:
 *
 *   0 : (FULL_CONTROL) Le logiciel de tranchage a un contrôle total sur les deux chariots X et peut 
 *       obtenir des résultats de voyage optimaux tant qu'elle prend en charge deux chariots X. (M605 S0)
 *
 *   1 : (AUTO_PARK) Le micrologiciel stationne et désassemble automatiquement les chariots X lors du changement 
 *       d'outil de sorte que la prise en charge supplémentaire du trancheur n'est pas nécessaire. (M605 S1)
 *
 *   2 : (DUPLICATION) Le micrologiciel déplace le deuxième chariot X et l'extrudeur en synchronisation 
 *       avec le premier chariot X et l'extrudeur, pour imprimer 2 copies du même objet en même temps.
 *       Réglez le décalage X constant et le différentiel de température avec M605 S2 X [off] R [deg] 
 *       et suivez avec M605 S2 pour lancer le mouvement en double.
 *
 *   3 : (MIRRORED) Mode miroir inspiré de Formbot / Vivedino dans lequel le second extrudeur reproduit 
 *       le mouvement du premier, sauf que le second extrudeur est inversée dans l'axe X.
 *       Réglez le décalage X initial et le différentiel de température avec 
 *       M605 S2 X [off] R [deg] et suivez avec M605 S3 pour lancer le mouvement miroir.
 */
//#define DUAL_X_CARRIAGE
#if ENABLED(DUAL_X_CARRIAGE)
  #define X1_MIN_POS X_MIN_POS   // Défini sur X_MIN_POS
  #define X1_MAX_POS X_BED_SIZE  // Définissez une distance maximum pour que le premier chariot X ne puisse pas toucher le deuxième chariot X garé
  #define X2_MIN_POS    80       // Définissez une distance minimum pour garantir que le deuxième chariot X ne puisse pas heurter le premier chariot X garé
  #define X2_MAX_POS   353       // Réglez-le sur la distance entre les têtes d'outils lorsque les deux têtes sont en position de référencement
  #define X2_HOME_DIR    1       // Réglez sur 1. Le deuxième chariot X reste toujours à la position de butée maximale
  #define X2_HOME_POS X2_MAX_POS // Position d'origine X2 par défaut. Défini sur X2_MAX_POS.
                      // Cependant: dans ce mode, la valeur HOTEND_OFFSET_X pour le deuxième extrudeur 
                      // fournit une substitution logicielle pour X2_HOME_POS. Cela permet également de recalibrer 
                      // la distance entre les deux butées sans modifier le firmware (via la commande "M218 T1 X ???").
                      // N'oubliez pas: vous devez définir le deuxième décalage de l'extrudeur sur 0 dans votre trancheur.

  // Il s'agit du mode de démarrage par défaut qui peut être utilisé ultérieurement avec le M605.
  #define DEFAULT_DUAL_X_CARRIAGE_MODE DXC_AUTO_PARK_MODE

  // Décalage x par défaut en mode de duplication (généralement défini sur la moitié de la largeur du lit d'impression)
  #define DEFAULT_DUPLICATION_X_OFFSET 100

#endif // DUAL_X_CARRIAGE

// Activez un solénoïde sur l'extrudeur actif avec M380. Désactivez tout avec M381.
// Définissez SOL0_PIN, SOL1_PIN, etc., pour chaque extrudeuse dotée d'un solénoïde.
//#define EXT_SOLENOID

// @section homing

// La prise d'origine atteint chaque butée, se rétracte sur ces distances, puis fait un touché plus lent.
#define X_HOME_BUMP_MM 5
#define Y_HOME_BUMP_MM 5
#define Z_HOME_BUMP_MM 5
#define HOMING_BUMP_DIVISOR { 2, 2, 4 }  // Diviseur de vitesse de rebondissement (divise la vitesse d'avance de prise d'origine)
//#define QUICK_HOME                     // Si le référencement comprend X et Y, effectuez d'abord un mouvement diagonal
//#define HOMING_BACKOFF_MM { 2, 2, 2 }  // (mm) Mouvement d'éloignement des butées après le retour

// Lorsque G28 est appelé, cette option fera revenir Y avant X 
//#define HOME_Y_BEFORE_X

// Activez cette option si X ou Y ne peut pas revenir à l'origine sans avoir d'abord référencé l'autre axe.
//#define CODEPENDENT_XY_HOMING

#if ENABLED(BLTOUCH)
  /**
   * Soit: utilisez les valeurs par défaut (recommandées) ou: à des fins spéciales, utilisez les DEFINES 
   * les DEFINES suivantes N'activez pas de paramètres que la sonde pourrait ne pas comprendre. 
   * Les clones peuvent mal comprendre les commandes avancées.
   *
   * Remarque: Si la sonde ne se déploie pas, vérifiez les paramètres "Cmd: Reset" et 
   *       "Cmd: Self-Test", puis vérifiez le câblage des fils MARRON, ROUGE et ORANGE.
   *
   * Remarque: Si le signal de déclenchement de votre sonde n'est pas reconnu, c'est très souvent parce 
   *       que les fils NOIR et BLANC devraient être inversés. Ils ne sont pas "interchangeables" 
   *       comme ils le seraient avec un vrai interrupteur. Veuillez donc d'abord vérifier le câblage.
   *
   * Paramètres pour toutes les sondes BLTouch et clones:
   */

  // Sécurité: la sonde a besoin de temps pour reconnaître la commande.
  //         Délai de commande minimum (ms). Activez et augmentez si nécessaire.
  //#define BLTOUCH_DELAY 500

  /**
   * Settings for BLTOUCH Classic 1.2, 1.3 or BLTouch Smart 1.0, 2.0, 2.2, 3.0, 3.1, and most clones:
   */

  // Fonctionnalité: passez en mode SW après un déploiement. Cela rend l'impulsion de sortie plus longue. 
  //                 Peut être utile dans des cas particuliers, comme les configurations d'entrée bruyantes ou filtrées.
  //#define BLTOUCH_FORCE_SW_MODE

  /**
   * Paramètres pour BLTouch Smart 3.0 et 3.1
   * Sommaire:
   *   - Modes de tension: 5 V et OD (circuit ouvert - "sans tension logique") modes de sortie
   *   - Mode haute vitesse
   *   - Désactiver les options de tension sur le LCD
   */

  /**
   * Danger: N'activez pas le mode 5V à moins d'être connecté à un contrôleur tolérant 5V!
   * V3.0 ou 3.1: définissez le mode par défaut sur le mode 5V au démarrage de Marlin.
   * S'il est désactivé, le mode OD est la valeur par défaut activé sur V3.0
   * Au démarrage, Marlin comparera son eeprom à cette valeur. Si le mode sélectionné diffère,
   * une écriture de mode eeprom définie sera faite lors de l'initialisation.
   * Utilisez l'option ci-dessous pour forcer une écriture eeprom sur une sonde V3.1.
   */
  //#define BLTOUCH_SET_5V_MODE

  /**
   * Sécurité: activez cette option si vous connectez une sonde avec un mode de tension inconnu.
   * V3.0: définir une sonde dans le mode sélectionné ci-dessus au démarrage de Marlin. Requis pour le mode 5V sur 3.0
   * V3.1: Forcer une sonde avec un mode inconnu dans le mode sélectionné au démarrage de Marlin (= écriture de la sonde EEPROM)
   * Pour préserver la durée de vie de la sonde, utilisez-la une fois, puis éteignez-la et re flasher.
   */
  //#define BLTOUCH_FORCE_MODE_SET

  /**
   * Utilisez le mode "HIGH SPEED" pour le sondage.
   * Danger: désactivez-le si votre sonde échoue parfois. Convient uniquement aux systèmes stables et bien ajustés.
   * Cette fonction a été conçue pour les Delta avec des mouvements Z très rapides, mais des cartésiens à vitesse plus élevée peuvent 
   * fonctionner Si la machine ne peut pas soulever la sonde assez rapidement après un déclenchement, elle peut entrer en état défaut.
   */
  //#define BLTOUCH_HS_MODE

  // Sécurité: activez les paramètres du mode de tension dans le menu LCD.
  //#define BLTOUCH_LCD_VOLTAGE_MENU

#endif // BLTOUCH

/**
 * Alignement automatique des Z Steppers
 * Ajoutez la commande G34 pour aligner plusieurs steppers Z à l'aide d'une sonde de lit.
 */
//#define Z_STEPPER_AUTO_ALIGN
#if ENABLED(Z_STEPPER_AUTO_ALIGN)
  // Définissez les positions des sondes X et Y pour Z1, Z2 [, Z3 [, Z4]]
  // Si non définie, les limites de sonde seront utilisées.
  // Remplacer par 'M422 S <index> X <pos> Y <pos>'
  //#define Z_STEPPER_ALIGN_XY { {  10, 190 }, { 100,  10 }, { 190, 190 } }

  /**
   * Orientation pour les positions de sonde calculées automatiquement.
   * Remplacer les points d'alignement pas à pas Z avec 'M422 S <index> X <pos> Y <pos>'
   *
   * 2 Steppers:  (0)     (1)
   *               |       |   2   |
   *               | 1   2 |       |
   *               |       |   1   |
   *
   * 3 Steppers:  (0)     (1)     (2)     (3)
   *               |   3   | 1     | 2   1 |     2 |
   *               |       |     3 |       | 3     |
   *               | 1   2 | 2     |   3   |     1 |
   *
   * 4 Steppers:  (0)     (1)     (2)     (3)
   *               | 4   3 | 1   4 | 2   1 | 3   2 |
   *               |       |       |       |       |
   *               | 1   2 | 2   3 | 3   4 | 4   1 |
   *
   */
  #ifndef Z_STEPPER_ALIGN_XY
    //#define Z_STEPPERS_ORIENTATION 0
  #endif

  // Fournir des positions pas à pas Z pour une convergence plus rapide de l'alignement du lit.
  // Nécessite des pilotes pas à pas triple (c.-à-d., Définissez NUM_Z_STEPPER_DRIVERS sur 3)
  //#define Z_STEPPER_ALIGN_KNOWN_STEPPER_POSITIONS
  #if ENABLED(Z_STEPPER_ALIGN_KNOWN_STEPPER_POSITIONS)
    // Définissez les positions XY pas à pas pour Z1, Z2, Z3 
    // correspondant aux positions des vis Z .
    // Définissez une position par stepper Z dans l'ordre du driver pas à pas.
    #define Z_STEPPER_ALIGN_STEPPER_XY { { 210.7, 102.5 }, { 152.6, 220.0 }, { 94.5, 102.5 } }
  #else
    // Facteur d'amplification. Utilisé pour augmenter ou diminuer l'échelle de correction dans  
    // le cas où la position du moteur pas à pas (broche) est plus éloignée que le point de test.
    #define Z_STEPPER_ALIGN_AMP 1.0       // Utilisez une valeur> 1.0 REMARQUE: cela peut provoquer une instabilité!
  #endif

  // Sur un lit de 300 mm, une pente de 5% donnerait un désalignement de ~ 1,5 cm
  #define G34_MAX_GRADE              5    // (%) Inclinaison maximale que G34 peut gérer
  #define Z_STEPPER_ALIGN_ITERATIONS 5    // Nombre d'itérations à appliquer pendant l'alignement
  #define Z_STEPPER_ALIGN_ACC        0.02 // Arrêtez d'itérer avant si la précision est meilleure que cela
  #define RESTORE_LEVELING_AFTER_G34      // Restaurer le nivellement une fois G34 terminé?
#endif

// @section mouvements

#define AXIS_RELATIVE_MODES { false, false, false, false }

// Ajouter une option Duplicate pour des buses conjointes bien séparées
//#define MULTI_NOZZLE_DUPLICATION

// Par défaut, les pilotes pas à pas pololu nécessitent un signal "high" actif. Cependant, certains pilotes de forte puissance nécessitent un signal actif "low" comme étape.
// (By default pololu step drivers require an active high signal. However, some high power drivers require an active low signal as step.)
#define INVERT_X_STEP_PIN false
#define INVERT_Y_STEP_PIN false
#define INVERT_Z_STEP_PIN false
#define INVERT_E_STEP_PIN false

// Arrêt des moteurs pas à pas par défaut si inactif. Réglez sur 0 pour désactiver.
// Les Steppers s'arrêteront DEFAULT_STEPPER_DEACTIVE_TIME secondes après le dernier mouvement lorsque DISABLE_INACTIVE_? est true.
// La durée peut être réglée par M18 et M84.
#define DEFAULT_STEPPER_DEACTIVE_TIME 120
#define DISABLE_INACTIVE_X true
#define DISABLE_INACTIVE_Y true
#define DISABLE_INACTIVE_Z true  // Réglez sur false si la buse tombe sur votre pièce imprimée une fois l'impression terminée.
#define DISABLE_INACTIVE_E true

#define DEFAULT_MINIMUMFEEDRATE       0.0     // vitesse minimale
#define DEFAULT_MINTRAVELFEEDRATE     0.0

//#define HOME_AFTER_DEACTIVATE  // Exiger un référencement après la désactivation des moteurs pas à pas

// Temps minimum qu'un segment doit prendre si le tampon est vidé
#define DEFAULT_MINSEGMENTTIME        20000   // (ms)

// Si défini, les mouvements ralentissent lorsque le tampon d'anticipation n'est qu'à moitié plein
#define SLOWDOWN

// Limite de fréquence
// Voir le blog de nophead pour plus d'informations
// Ne fonctionne pas avec O
//#define XY_FREQUENCY_LIMIT  15

// Vitesse minimale de jonction du planificateur. Définit la vitesse minimale par défaut prévue par le planificateur à la fin de 
// la mémoire tampon et à tous les arrêts. Cette valeur ne doit pas être supérieure à zéro et ne doit être modifiée que si 
// un comportement indésirable est observé sur la machine d'un utilisateur lors d'une exécution à des vitesses très lentes.
#define MINIMUM_PLANNER_SPEED 0.05 // (mm/s)

//
// Compensation de jeu
// Ajoute un mouvement supplémentaire aux axes lors des changements de direction pour tenir compte du jeu.
//
//#define BACKLASH_COMPENSATION
#if ENABLED(BACKLASH_COMPENSATION)
  // Définissez des valeurs pour la distance de jeu et la correction.
  // Si BACKLASH_GCODE est activé, ces valeurs sont les valeurs par défaut.
  #define BACKLASH_DISTANCE_MM { 0, 0, 0 } // (mm)
  #define BACKLASH_CORRECTION    0.0       // 0,0 = aucune correction; 1.0 = correction maximum

  // Définissez BACKLASH_SMOOTHING_MM pour répartir la correction de jeu sur plusieurs segments 
  // afin de réduire les artefacts d'impression. (Activer ceci est coûteux en mémoire et en calcul!)
  //#define BACKLASH_SMOOTHING_MM 3 // (mm)

  // Ajouter la configuration d'exécution et le réglage des valeurs de jeu (M425)
  //#define BACKLASH_GCODE

  #if ENABLED(BACKLASH_GCODE)
    // Mesurer le jeu Z lors du palpage (G29) et régler avec "M425 Z"
    #define MEASURE_BACKLASH_WHEN_PROBING

    #if ENABLED(MEASURE_BACKLASH_WHEN_PROBING)
      // Lors de la mesure, la sonde se déplacera jusqu'à BACKLASH_MEASUREMENT_LIMIT 
      // mm du point de contact par incréments BACKLASH_MEASUREMENT_RESOLUTION 
      // tout en vérifiant que le contact (de la sonde) change d'état.
      #define BACKLASH_MEASUREMENT_LIMIT       0.5   // (mm)
      #define BACKLASH_MEASUREMENT_RESOLUTION  0.005 // (mm)
      #define BACKLASH_MEASUREMENT_FEEDRATE    Z_PROBE_SPEED_SLOW // (mm/m)
    #endif
  #endif
#endif

/**
 * Calibrage automatique du jeu, de la position et du décalage de l'extrémité
 *
 * Activez le G425 pour exécuter l'étalonnage automatique à l'aide d'un cube, 
 * d'un boulon ou d'une rondelle électriquement conducteur monté sur le lit.
 *
 * G425 utilise la sonde pour toucher le haut et les côtés de l'objet d'étalonnage 
 * sur le lit et mesure et / ou corrige les décalages de position, 
 * le jeu d'axe et les décalages de hotend.
 *
 * Remarque: HOTEND_OFFSET et CALIBRATION_OBJECT_CENTER doivent être définis 
 *       à ± 5 mm des valeurs vraies pour que G425 réussisse.
 */
//#define CALIBRATION_GCODE
#if ENABLED(CALIBRATION_GCODE)

  #define CALIBRATION_MEASUREMENT_RESOLUTION     0.01 // mm

  #define CALIBRATION_FEEDRATE_SLOW             60    // mm/m
  #define CALIBRATION_FEEDRATE_FAST           1200    // mm/m
  #define CALIBRATION_FEEDRATE_TRAVEL         3000    // mm/m

  // Les paramètres suivants se réfèrent à la section conique de la pointe de buse.
  #define CALIBRATION_NOZZLE_TIP_HEIGHT          1.0  // mm
  #define CALIBRATION_NOZZLE_OUTER_DIAMETER      2.0  // mm

  // Décommentez pour activer la génération de rapports (requis pour "G425 V", mais consomme de la mémoire PROGMEM).
  //#define CALIBRATION_REPORTING

  // Les véritables emplacement et dimensions du cube / boulon / rondelle sur le lit.
  #define CALIBRATION_OBJECT_CENTER     { 264.0, -22.0,  -2.0 } // mm
  #define CALIBRATION_OBJECT_DIMENSIONS {  10.0,  10.0,  10.0 } // mm

  // Commentez tous les côtés qui ne sont pas accessibles par la sonde. 
  // Pour de meilleurs résultats d'auto-étalonnage, tous les côtés doivent être accessibles.
  #define CALIBRATION_MEASURE_RIGHT
  #define CALIBRATION_MEASURE_FRONT
  #define CALIBRATION_MEASURE_LEFT
  #define CALIBRATION_MEASURE_BACK

  // Le sondage au centre supérieur exact ne fonctionne que si le centre est plat. 
  // En cas de sondage sur une tête de vis ou une rondelle creuse, sonder près des bords de celles-ci.
  //#define CALIBRATION_MEASURE_AT_TOP_EDGES

  // Définissez la broche à lire pendant l'étalonnage
  #ifndef CALIBRATION_PIN
    //#define CALIBRATION_PIN -1            // remplacer ici la broche par défaut
    #define CALIBRATION_PIN_INVERTING false // Défini sur true pour inverser la broche personnalisée
    //#define CALIBRATION_PIN_PULLDOWN
    #define CALIBRATION_PIN_PULLUP
  #endif
#endif

/**
 * Le lissage de pas adaptatif augmente la résolution des mouvements multi-axes, en particulier 
 * aux fréquences de pas inférieures à 1 kHz (pour AVR) ou 10 kHz (pour ARM), où le repliement entre 
 * les axes dans les mouvements multi-axes provoque des vibrations audibles et des artefacts de surface. 
 * L'algorithme s'adapte pour fournir le meilleur lissage de pas possible aux fréquences de pas les plus basses.
 */
//#define ADAPTIVE_STEP_SMOOTHING

/**
 * Microstepping personnalisé
 * Remplacez au besoin pour votre configuration. Jusqu'à 3 broches MS sont prises en charge.
 */
//#define MICROSTEP1 LOW,LOW,LOW
//#define MICROSTEP2 HIGH,LOW,LOW
//#define MICROSTEP4 LOW,HIGH,LOW
//#define MICROSTEP8 HIGH,HIGH,LOW
//#define MICROSTEP16 LOW,LOW,HIGH
//#define MICROSTEP32 HIGH,LOW,HIGH

// Paramètre de micros pas (Fonctionne uniquement lorsque les broches de micropas du pilote pas à pas sont connectées au MCU).
#define MICROSTEP_MODES { 16, 16, 16, 16, 16, 16 } // [1,2,4,8,16]

/**
 *  @section courant moteur pas à pas
 *
 *  Certaines cartes ont un moyen de régler le courant du moteur pas à pas via le firmware.
 *
 *  La puissance des courants moteur est réglée par:
 *    PWM_MOTOR_CURRENT - utilisé par MINIRAMBO & ULTIMAIN_2
 *                         puces compatibles connues: A4982
 *    DIGIPOT_MOTOR_CURRENT - utilisé par BQ_ZUM_MEGA_3D, RAMBO & SCOOVO_X9H
 *                         puces compatibles connues: AD5206
 *    DAC_MOTOR_CURRENT_DEFAULT - utilisé par PRINTRBOARD_REVF & RIGIDBOARD_V2
 *                         puces compatibles connues: MCP4728
 *    DIGIPOT_I2C_MOTOR_CURRENTS - utilisé par 5DPRINT, AZTEEG_X3_PRO, AZTEEG_X5_MINI_WIFI, MIGHTYBOARD_REVE
 *                         puces compatibles connues: MCP4451, MCP4018
 *
 *  Les courants du moteur peuvent également être réglés par M907 - M910 et par l'écran LCD.
 *    M907 - s'applique à tous.
 *    M908 - BQ_ZUM_MEGA_3D, RAMBO, PRINTRBOARD_REVF, RIGIDBOARD_V2 & SCOOVO_X9H
 *    M909, M910 & LCD - uniquement PRINTRBOARD_REVF & RIGIDBOARD_V2
 */
//#define PWM_MOTOR_CURRENT { 1300, 1300, 1250 }          // Valeurs en milliampères
//#define DIGIPOT_MOTOR_CURRENT { 135,135,135,135,135 }   // Valeurs 0-255 (RAMBO 135 = ~ 0,75A, 185 = ~ 1A)
//#define DAC_MOTOR_CURRENT_DEFAULT { 70, 80, 90, 80 }    // Pourcentage d'entraînement par défaut - axes X, Y, Z, E

// Utilisez un DIGIPOT basé sur I2C (par exemple, Azteeg X3 Pro)
//#define DIGIPOT_I2C
#if ENABLED(DIGIPOT_I2C) && !defined(DIGIPOT_I2C_ADDRESS_A)
  /**
   * Adresses esclaves communes:
   *
   *                        A   (A shifted)   B   (B shifted)  IC
   * Smoothie              0x2C (0x58)       0x2D (0x5A)       MCP4451
   * AZTEEG_X3_PRO         0x2C (0x58)       0x2E (0x5C)       MCP4451
   * AZTEEG_X5_MINI        0x2C (0x58)       0x2E (0x5C)       MCP4451
   * AZTEEG_X5_MINI_WIFI         0x58              0x5C        MCP4451
   * MIGHTYBOARD_REVE      0x2F (0x5E)                         MCP4018
   */
  #define DIGIPOT_I2C_ADDRESS_A 0x2C  // adresse esclave non décalée pour le premier DIGIPOT
  #define DIGIPOT_I2C_ADDRESS_B 0x2D  // adresse esclave non décalée pour le deuxième DIGIPOT
#endif

//#define DIGIPOT_MCP4018          // Nécessite la bibliothèque de https://github.com/stawel/SlowSoftI2CMaster
#define DIGIPOT_I2C_NUM_CHANNELS 8 // 5 IMPRESSION: 4 AZTEEG_X3_PRO: 8 MKS SBASE: 5
// Courants réels du moteur en ampères. Le nombre d'entrées doit correspondre à DIGIPOT_I2C_NUM_CHANNELS.
// Ceux-ci correspondent aux pilotes physiques, alors soyez attentif si la commande est modifiée.
#define DIGIPOT_I2C_MOTOR_CURRENTS { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 }  //  AZTEEG_X3_PRO

//===========================================================================
//======================Caractéristiques supplémentaires=====================
//===========================================================================

// @section lcd

#if EITHER(ULTIPANEL, EXTENSIBLE_UI)
  #define MANUAL_FEEDRATE { 50*60, 50*60, 4*60, 60 } // Vitesses des mouvements manuels axes X, Y, Z, E à partir du menu
  #define SHORT_MANUAL_Z_MOVE 0.025 // (mm) Plus petit déplacement manuel Z (<0,1 mm)
  #if ENABLED(ULTIPANEL)
    #define MANUAL_E_MOVES_RELATIVE // Afficher la distance de déplacement de l'extrudeur plutôt que la "position"
    #define ULTIPANEL_FEEDMULTIPLY  // L'encodeur définit le multiplicateur d'avance sur l'écran 
  #endif
#endif

// Modifiez les valeurs plus rapidement lorsque l'encodeur tourne plus rapidement
#define ENCODER_RATE_MULTIPLIER
#if ENABLED(ENCODER_RATE_MULTIPLIER)
  #define ENCODER_10X_STEPS_PER_SEC   30  // (steps/s) nombre de de crans 10x
  #define ENCODER_100X_STEPS_PER_SEC  80  // (steps/s) nombre de de crans 100x
#endif

// Émettre un bip lorsque la vitesse d'avance est modifiée à partir de l'écran
//#define BEEP_ON_FEEDRATE_CHANGE
#if ENABLED(BEEP_ON_FEEDRATE_CHANGE)
  #define FEEDRATE_CHANGE_BEEP_DURATION   10
  #define FEEDRATE_CHANGE_BEEP_FREQUENCY 440
#endif

#if HAS_LCD_MENU

  // Inclure une page d'informations sur l'imprimante dans le menu principal LCD
  #define LCD_INFO_MENU
  #if ENABLED(LCD_INFO_MENU)
    //#define LCD_PRINTER_INFO_IS_BOOTSCREEN // Afficher les écrans de démarrage au lieu des pages d'informations sur l'imprimante
  #endif

  // Les éléments du menu RETOUR sont en surbrillance
  //#define TURBO_BACK_MENU_ITEM

  /**
   * Menu de contrôle LED
   * Ajouter un contrôle LED au menu LCD
   */
  //#define LED_CONTROL_MENU
  #if ENABLED(LED_CONTROL_MENU)
    #define LED_COLOR_PRESETS                 // Activez l'option de menu Couleur prédéfinie
    #if ENABLED(LED_COLOR_PRESETS)
      #define LED_USER_PRESET_RED        255  // Valeur ROUGE définie par l'utilisateur
      #define LED_USER_PRESET_GREEN      128  // Valeur VERTE définie par l'utilisateur
      #define LED_USER_PRESET_BLUE         0  // Valeur BLEU définie par l'utilisateur
      #define LED_USER_PRESET_WHITE      255  // Valeur BLANC définie par l'utilisateur
      #define LED_USER_PRESET_BRIGHTNESS 255  // Intensité définie par l'utilisateur
      //#define LED_USER_PRESET_STARTUP       // Demander à l'imprimante d'afficher la couleur prédéfinie par l'utilisateur au démarrage
    #endif
  #endif

#endif // HAS_LCD_MENU

// Faites défiler un message d'état trop long pour être l'afficher
#define STATUS_MESSAGE_SCROLLING

// Sur l'écran d'informations, affichez XY avec une décimale si possible
//#define LCD_DECIMAL_SMALL_XY

// Le délai (en ms) pour revenir à l'écran d'état à partir des sous-menus
//#define LCD_TIMEOUT_TO_STATUS 15000

// Ajoutez un code G «M73» pour définir le pourcentage actuel
//#define LCD_SET_PROGRESS_MANUALLY

// Afficher la position E (filament utilisé) pendant l'impression
//##define LCD_SHOW_E_TOTAL

#if HAS_GRAPHICAL_LCD && HAS_PRINT_PROGRESS
  //#define PRINT_PROGRESS_SHOW_DECIMALS // Afficher la progression avec des chiffres décimaux
  //#define SHOW_REMAINING_TIME          // Afficher le temps estimé jusqu'à la fin
  #if ENABLED(SHOW_REMAINING_TIME)
    //#define USE_M73_REMAINING_TIME     // Utiliser le temps restant de la commande M73 au lieu de l'estimation
    //#define ROTATE_PROGRESS_DISPLAY    // Afficher (P) la progression, (E) le temps passé et (R) le temps restant
  #endif
#endif

#if HAS_CHARACTER_LCD && HAS_PRINT_PROGRESS
  //#define LCD_PROGRESS_BAR              // Afficher une barre de progression sur les écrans LCD HD44780 pour l'impression SD
  #if ENABLED(LCD_PROGRESS_BAR)
    #define PROGRESS_BAR_BAR_TIME 2000    // (ms) Temps sous forme de barre
    #define PROGRESS_BAR_MSG_TIME 3000    // (ms) Durée d'affichage du message d'état
    #define PROGRESS_MSG_EXPIRE   0       // (ms) Durée de conservation du message d'état (0 = pour toujours)
    //#define PROGRESS_MSG_ONCE           // Afficher le message pour MSG_TIME puis l'effacer
    //#define LCD_PROGRESS_BAR_TEST       // Ajouter un élément de menu pour tester la barre de progression
  #endif
#endif

#if ENABLED(SDSUPPORT)

  // Certaines RAMPS et autres cartes ne détectent pas lorsqu'une carte SD est insérée. 
  // Vous pouvez contourner ce problème en connectant un bouton-poussoir ou un interrupteur 
  // à la broche définie comme SD_DETECT_PIN dans les définitions de broches de votre carte.
  // Ce paramètre doit être désactivé, sauf si vous utilisez un bouton-poussoir, mettant la broche à Gnd.
  // Remarque: Ceci est toujours désactivé pour ULTIPANEL (sauf ELB_FULL_GRAPHIC_CONTROLLER).
  #define SD_DETECT_INVERTED

  #define SD_FINISHED_STEPPERRELEASE true          // Désactiver les steppers lorsque l'impression SD est terminée
  #define SD_FINISHED_RELEASECOMMAND "M84 X Y Z E" // Vous voudrez peut-être garder le Z activé pour que votre lit reste en place.

  // Inverser le tri SD pour afficher d'abord les fichiers "les plus récents", selon le FAT de la carte.
  // Étant donné que le FAT est hors service avec cette l'utilisation, SDCARD_SORT_ALPHA est recommandé.
  #define SDCARD_RATHERRECENTFIRST

  #define SD_MENU_CONFIRM_START             // Confirmez le fichier SD sélectionné avant d'imprimer

  //#define MENU_ADDAUTOSTART               // Ajouter une option de menu pour exécuter des fichiers # #g automatiques

  #define EVENT_GCODE_SD_STOP "G28XY"       // GCode à exécuter sur Stop Print (par exemple, "G28XY" ou "G27")

  /**
   * Continuer après une coupure de courant (Creality3D)
   *
   * Enregistrez l'état actuel sur la carte SD au début de chaque couche pendant 
   * l'impression SD. Si le fichier de récupération est trouvé au démarrage, 
   * présentez une option sur l'écran LCD pour poursuivre l'impression à partir du dernier point connu du fichier.
   * à partir du dernier point connu du fichier.
   */
  //#define POWER_LOSS_RECOVERY
  #if ENABLED(POWER_LOSS_RECOVERY)
    //#define BACKUP_POWER_SUPPLY       // Alimentation de secours / onduleur pour déplacer les steppers en cas de perte d'alimentation
    //#define POWER_LOSS_ZRAISE       2 // (mm) Augmentation de l'axe Z à la reprise (en cas de perte d'alimentation avec onduleur)
    //#define POWER_LOSS_PIN         44 // Broche pour détecter la coupure de courant. Réglez sur -1 pour désactiver la broche par défaut sur les cartes sans module.
    //#define POWER_LOSS_STATE     HIGH // État de la broche indiquant une perte de courant
    //#define POWER_LOSS_PULL           // Réglez pullup / pulldown de façon appropriée
    //#define POWER_LOSS_PURGE_LEN   20 // (mm) Longueur du filament à purger à la reprise
    //#define POWER_LOSS_RETRACT_LEN 10 // (mm) Longueur du filament à rétracter en cas de coupure. Nécessite une alimentation de secours.

    // Sans POWER_LOSS_PIN, l'option suivante permet de réduire l'usure de la carte SD, en particulier avec 
    // l'impression en "mode vase". Réglez une valeur trop haute et les vases ne peuvent pas continuer.
    #define POWER_LOSS_MIN_Z_CHANGE 0.05 // (mm) Changement Z minimum avant d'enregistrer les données de perte de courant
  #endif

  /**
   * Trier la liste des fichiers SD par ordre alphabétique.
   *
   * Lorsque cette option est activée, les éléments sur les cartes SD 
   * seront triés par nom pour faciliter la navigation.
   *
   * Par défaut...
   *
   *  - Utilisez la méthode de tri la plus lente mais la plus sûre.
   *  - Les dossiers sont affichés en haut.
   *  - La clé de tri est allouée statiquement.
   *  - Aucun support de Gcode ajouté (M34).
   *  - Limite de tri de 40 éléments. (Les articles après les 40 premiers ne sont pas triés.)
   *
   * Le tri SD utilise l'allocation statique (telle que définie par SDSORT_LIMIT), 
   * permettant au compilateur de calculer l'utilisation la plus défavorable et 
   * de générer une erreur si la limite SRAM est dépassée.
   *
   *  - SDSORT_USES_RAM permet un tri plus rapide via un tampon de répertoire statique.
   *  - SDSORT_USES_STACK fait de même, mais utilise un tampon basé sur la pile local.
   *  - SDSORT_CACHE_NAMES conservera la liste des fichiers triés dans la RAM. (Coûteux en Progmem!)
   *  - SDSORT_DYNAMIC_RAM utilise uniquement la RAM lorsque le menu SD est visible. (Utiliser avec précaution!)
   */
  //#define SDCARD_SORT_ALPHA

  // SD Card Sorting options
  #if ENABLED(SDCARD_SORT_ALPHA)
    #define SDSORT_LIMIT       40     // Nombre maximum d'articles triés (10-256). Coûte 27 octets chacun.
    #define FOLDER_SORTING     -1     // -1 = supérieur à   0 = aucun    1 = inférieur à
    #define SDSORT_GCODE       false  // Permet d'activer / désactiver le tri avec l'écran LCD et le Gcode M34.
    #define SDSORT_USES_RAM    false  // Pré-allouer un tableau statique pour un pré-tri plus rapide.
    #define SDSORT_USES_STACK  false  // Préférez la pile de pré-tri pour restituer de la SRAM. (Anulé par les 2 options suivantes.)
    #define SDSORT_CACHE_NAMES false  // Conservez les éléments triés dans la RAM plus longtemps pour des performances rapides. Option la plus couteuse en Progmem.
    #define SDSORT_DYNAMIC_RAM false  // Utilisez l'allocation dynamique (dans les menus SD). Option la moins couteuse en Progmem.. Réglez SDSORT_LIMIT avant utilisation!
    #define SDSORT_CACHE_VFATS 2      // Nombre maximal d'entrées VFAT de 13 octets à utiliser pour le tri.
                                      // Remarque: affecte uniquement SCROLL_LONG_FILENAMES avec SDSORT_CACHE_NAMES mais pas SDSORT_DYNAMIC_RAM.
  #endif

  // Permet aux hôtes de demander des noms longs pour les fichiers et dossiers avec M33
  //#define LONG_FILENAME_HOST_SUPPORT

  // Activez cette option pour faire défiler les noms de fichiers longs dans le menu de la carte SD
  //#define SCROLL_LONG_FILENAMES

  // Laissez les éléments chauffants allumés après l'arrêt de l'impression (non recommandé!)
  //#define SD_ABORT_NO_COOLDOWN

  /**
   * Cette option vous permet d'interrompre l'impression SD lorsqu'un endstop est activé
   * Cette fonction doit être activée avec "M540 S1" ou depuis le menu LCD.
   * Pour avoir un effet, les endstop doivent être activés lors de l'impression SD.
   */
  //#define SD_ABORT_ON_ENDSTOP_HIT

  /**
   * Cette option facilite la réimpression du même fichier de carte SD.
   * Une fois l'impression terminée, le menu LCD s'ouvre avec le fichier sélectionné.
   * Vous pouvez simplement cliquer pour démarrer l'impression ou naviguer ailleurs.
   */
  //#define SD_REPRINT_LAST_SELECTED_FILE

  /**
   * Rapport automatique de l'état SdCard avec M27 S <secondes>
   */
  //#define AUTO_REPORT_SD_STATUS

  /**
   * Prise en charge des clés USB utilisant un bouclier hôte Arduino USB 
   * ou une carte de dérivation MAX3421E équivalente. La clé USB apparaîtra à Marlin comme une carte SD.
   * La clé USB apparaîtra à Marlin comme une carte SD.
   *
   * The MAX3421E can be assigned the same pins as the SD card reader, with
   *Le MAX3421E peut se voir attribuer les mêmes broches que le lecteur de carte SD, avec le mappage des broches suivant:
   *
   *    SCLK, MOSI, MISO --> SCLK, MOSI, MISO
   *    INT              --> SD_DETECT_PIN [1]
   *    SS               --> SDSS
   *
   * [1] Sur AVR, une broche capable d'interruption est la meilleure pour la compatibilité UHS3.
   */
  //#define USB_FLASH_DRIVE_SUPPORT
  #if ENABLED(USB_FLASH_DRIVE_SUPPORT)
    #define USB_CS_PIN    SDSS
    #define USB_INTR_PIN  SD_DETECT_PIN

    /**
     * Bibliothèque USB Host Shield
     *
     * - UHS2 n'utilise aucune interruption et a été testé en production 
     *   sur un LulzBot TAZ Pro avec une carte Archim 32 bits.
     *
     * - UHS3 est un code plus récent avec une meilleure compatibilité USB. 
     *   Mais il a été moins testé et est connu pour interférer avec les servos.
     *   [1] Cela nécessite que USB_INTR_PIN soit capable d'interruption.
     */
    //#define USE_UHS3_USB
  #endif

  /**
   * Lorsque vous utilisez un chargeur de démarrage qui prend en charge le SD-Firmware-Flashing, 
   * ajoutez un élément de menu pour activer SD-FW-Update au prochain redémarrage.
   *
   * Nécessite ATMEGA2560 (Arduino Mega)
   *
   * Testé avec ce chargeur de démarrage:
   *   https://github.com/FleetProbe/MicroBridge-Arduino-ATMega2560
   */
  //#define SD_FIRMWARE_UPDATE
  #if ENABLED(SD_FIRMWARE_UPDATE)
    #define SD_FIRMWARE_UPDATE_EEPROM_ADDR    0x1FF
    #define SD_FIRMWARE_UPDATE_ACTIVE_VALUE   0xF0
    #define SD_FIRMWARE_UPDATE_INACTIVE_VALUE 0xFF
  #endif

  // Ajouter un mode de transfert de fichiers binaires optimisé, initié avec 'M28 B1'
  //#define BINARY_FILE_TRANSFER

  /**
   * Définissez cette option sur l'une des options suivantes (ou les valeurs par défaut du tableau s'appliquent):
   *
   *           LCD - Utilisez le lecteur SD du contrôleur LCD externe.
   *       ONBOARD - Utilisez le lecteur SD sur la carte de commande. (Pas de SD_DETECT_PIN. M21 à init.)
   *  CUSTOM_CABLE - Utilisez un câble personnalisé pour accéder à la SD (comme défini dans un fichier de broches).
   *
   * :[ 'LCD', 'ONBOARD', 'CUSTOM_CABLE' ]
   */
  //#define SDCARD_CONNECTION LCD

#endif // SDSUPPORT

/**
 * Par défaut, un lecteur de carte SD intégré peut être partagé en tant que 
 * périphérique de stockage de masse USB. Cette option masque la carte SD du PC hôte.
 */
//#define NO_SD_HOST_DRIVE   // Désactivez l'accès à la carte SD via USB (pour des raisons de sécurité).

/**
 * Options supplémentaires pour les affichages graphiques
 *
 * Utilisez les optimisations ici pour améliorer les performances d'impression, 
 * qui peuvent être affectées par le dessin de l'affichage graphique, en particulier 
 * lorsque vous effectuez plusieurs mouvements courts et lorsque vous imprimez sur des machines DELTA et SCARA.
 * sur des machines DELTA et SCARA.
 *
 * Certaines de ces options peuvent entraîner un retard d'affichage sur les 
 * événements du contrôleur, car il existe un compromis entre des performances d'impression 
 * d'impression fiables et des mises à jour rapides de l'affichage.
 */
#if HAS_GRAPHICAL_LCD
  // Afficher le pourcentage SD à côté de la barre de progression
  //#define DOGM_SD_PERCENT

  // Permet d'enregistrer de nombreux cycles en dessinant un cadre creux sur l'écran d'informations
  #define XYZ_HOLLOW_FRAME

  // Permet d'enregistrer de nombreux cycles en dessinant un cadre creux sur les écrans de menu
  #define MENU_HOLLOW_FRAME

  // Une police plus grande est disponible pour modifier les éléments. Coûte 3120 octets de PROGMEM.
  // Western uniquement. Non disponible pour Cyrillic, Kana, Turkish, Greek, or Chinese.
  //#define USE_BIG_EDIT_FONT

  // Une police plus petite peut être utilisée sur l'écran d'informations. Coûte 2300 octets de PROGMEM.
  // Western uniquement. Non disponible pour Cyrillic, Kana, Turkish, Greek, or Chinese.
  //#define USE_SMALL_INFOFONT

  // Activez cette option et réduisez la valeur pour optimiser les mises à jour d'écran.
  // Le retard normal est de 10µs. Utilisez la valeur la plus basse qui donne toujours un affichage fiable.
  //#define DOGM_SPI_DELAY_US 5

  // Échangez les indicateurs CW / CCW dans la superposition graphique
  //#define OVERLAY_GFX_REVERSE

  /**
   * Les écrans LCD basés sur ST7920 peuvent émuler un affichage 16 x 4 caractères à l'aide 
   * du générateur de caractères ST7920 pour des mises à jour d'écran très rapides.
   * Activez LIGHTWEIGHT_UI pour utiliser ce mode d'affichage spécial.
   *
   * Étant donné que LIGHTWEIGHT_UI a un espace limité, le message de position 
   * et d'état occupe la même ligne. Définissez STATUS_EXPIRE_SECONDS sur la durée 
   * d'affichage du message d'état avant l'effacement.
   *
   * Définissez STATUS_EXPIRE_SECONDS sur zéro pour ne jamais effacer l'état.
   * Cela empêchera la mises à jour de l'affichage de position.
   */
  #if ENABLED(U8GLIB_ST7920)
    //#define LIGHTWEIGHT_UI
    #if ENABLED(LIGHTWEIGHT_UI)
      #define STATUS_EXPIRE_SECONDS 20
    #endif
  #endif

  /**
   * Personnalisation de l'écran d'état (info)
   * Ces options peuvent affecter la taille du code et le temps de rraffraichissement de l'écran.
   * Les écrans d'état personnalisés peuvent forcer ces paramètres.
   */
  //#define STATUS_COMBINE_HEATERS    // Utilisez des icones de chauffage combinées au lieu d'icones distinctes
  //#define STATUS_HOTEND_NUMBERLESS  // Utilisez des icônes de hotend simples au lieu de celles numérotées (avec plud de 2 hotends)
  #define STATUS_HOTEND_INVERTED      // Afficher les images bitmap des buses pleines lors du chauffage (nécessite STATUS_HOTEND_ANIM)
  #define STATUS_HOTEND_ANIM          // Utilisez un deuxième bitmap pour indiquer le chauffage du hotend
  #define STATUS_BED_ANIM             // Utilisez un deuxième bitmap pour indiquer le chauffage du lit
  #define STATUS_CHAMBER_ANIM         // Utilisez un deuxième bitmap pour indiquer le chauffage du caisson
  //#define STATUS_CUTTER_ANIM        // Utilisez un deuxième bitmap pour indiquer que la broche / le laser est actif
  //#define STATUS_ALT_BED_BITMAP     // Utilisez le bitmap de lit alternatif
  //#define STATUS_ALT_FAN_BITMAP     // Utilisez le bitmap de ventilateur alternatif
  //#define STATUS_FAN_FRAMES 3       // : [0,1,2,3,4] Nombre d'images d'animation de ventilateur
  //#define STATUS_HEAT_PERCENT       // Afficher le chauffage dans une barre de progression
  //#define BOOT_MARLIN_LOGO_SMALL    // Afficher un logo Marlin plus petit sur l'écran de démarrage (économisant 399 octets de flash)
  //#define BOOT_MARLIN_LOGO_ANIMATED // Logo Marlin animé. Coûts ~ 3260 (ou ~ 940) octets de PROGMEM.

  // Frivolous Game Options
  //#define MARLIN_BRICKOUT
  //#define MARLIN_INVADERS
  //#define MARLIN_SNAKE
  //#define GAMES_EASTER_EGG          // Ajoutez des lignes vierges supplémentaires au-dessus du sous-menu "Jeux"

#endif // HAS_GRAPHICAL_LCD

//
// Options supplémentaires pour les écrans DGUS / DWIN
//
#if HAS_DGUS_LCD
  #define DGUS_SERIAL_PORT 2
  #define DGUS_BAUDRATE 115200

  #define DGUS_RX_BUFFER_SIZE 128
  #define DGUS_TX_BUFFER_SIZE 48
  //#define DGUS_SERIAL_STATS_RX_BUFFER_OVERRUNS  // Correction de la situation de dépassement Rx (actuellement uniquement pour AVR)

  #define DGUS_UPDATE_INTERVAL_MS  500    // (ms) Intervalle entre les mises à jour d'écran
  #define BOOTSCREEN_TIMEOUT      3000    // (ms) Durée d'affichage de l'écran de démarrage

  #if EITHER(DGUS_LCD_UI_FYSETC, DGUS_LCD_UI_HIPRECY)
    #define DGUS_PRINT_FILENAME           // Afficher le nom de fichier pendant l'impression
    #define DGUS_PREHEAT_UI               // Afficher un écran de préchauffage pendant le préchauffage

    #if ENABLED(DGUS_LCD_UI_FYSETC)
      //#define DUGS_UI_MOVE_DIS_OPTION   // Désactivé par défaut pour UI_FYSETC
    #else
      #define DUGS_UI_MOVE_DIS_OPTION     // Activé par défaut pour UI_HIPRECY
    #endif

    #define DGUS_FILAMENT_LOADUNLOAD
    #if ENABLED(DGUS_FILAMENT_LOADUNLOAD)
      #define DGUS_FILAMENT_PURGE_LENGTH 10
      #define DGUS_FILAMENT_LOAD_LENGTH_PER_TIME 0.5 // (mm) Adjust in proportion to DGUS_UPDATE_INTERVAL_MS
    #endif

    #define DGUS_UI_WAITING               // Afficher un écran "en attente" entre certains écrans
    #if ENABLED(DGUS_UI_WAITING)
      #define DGUS_UI_WAITING_STATUS 10
      #define DGUS_UI_WAITING_STATUS_PERIOD 8 // Augmentez pour une boucle de statut d'attente plus lente
    #endif
  #endif
#endif // HAS_DGUS_LCD

//
// Interface utilisateur tactile pour le moteur vidéo embarqué FTDI (EVE)
//
#if ENABLED(TOUCH_UI_FTDI_EVE)
  // Display board used
  //#define LCD_FTDI_VM800B35A        // FTDI 3.5" avec FT800 (320x240)
  //#define LCD_4DSYSTEMS_4DLCD_FT843 // 4D Systems 4.3" (480x272)
  //#define LCD_HAOYU_FT800CB         // Haoyu avec 4.3" or 5" (480x272)
  //#define LCD_HAOYU_FT810CB         // Haoyu avec 5" (800x480)
  //#define LCD_ALEPHOBJECTS_CLCD_UI  // Aleph Objects LCD couleur UI

  // Corrigez la résolution si vous n'utilisez pas le panneau TFT d'origine.
  //#define TOUCH_UI_320x240
  //#define TOUCH_UI_480x272
  //#define TOUCH_UI_800x480

  // Mappages pour les cartes avec un connecteur d'affichage RepRapDiscount standard
  //#define AO_EXP1_PINMAP    // AlephObjects CLCD UI EXP1 mapping
  //#define AO_EXP2_PINMAP    // AlephObjects CLCD UI EXP2 mapping
  //#define CR10_TFT_PINMAP   // Rudolph Riedel's CR10 pin mapping
  //#define S6_TFT_PINMAP     // FYSETC S6 pin mapping

  //#define OTHER_PIN_LAYOUT  // Définissez les broches manuellement ci-dessous
  #if ENABLED(OTHER_PIN_LAYOUT)
    // Pins for CS and MOD_RESET (PD) doit être choisi
    #define CLCD_MOD_RESET  9
    #define CLCD_SPI_CS    10

    // Si vous utilisez un logiciel SPI, spécifiez les broches pour SCLK, MOSI, MISO
    //#define CLCD_USE_SOFT_SPI
    #if ENABLED(CLCD_USE_SOFT_SPI)
      #define CLCD_SOFT_SPI_MOSI 11
      #define CLCD_SOFT_SPI_MISO 12
      #define CLCD_SOFT_SPI_SCLK 13
    #endif
  #endif

  // Afficher l'orientation. Un affichage inversé (c'est-à-dire à l'envers) 
  // est pris en charge sur le FT800. Le FT810 et au-delà prend également 
  // en charge les orientations portrait et miroir.
  //#define TOUCH_UI_INVERTED
  //#define TOUCH_UI_PORTRAIT
  //#define TOUCH_UI_MIRRORED

  // Traitement et rendu UTF8.
  // Les caractères non pris en charge sont indiqués par «?».
  //#define TOUCH_UI_USE_UTF8
  #if ENABLED(TOUCH_UI_USE_UTF8)
    // Prise en charge des accents occidentaux. Ces caractères accentués utilisent 
    // des bitmaps combinés et nécessitent relativement peu de stockage.
    #define TOUCH_UI_UTF8_WESTERN_CHARSET
    #if ENABLED(TOUCH_UI_UTF8_WESTERN_CHARSET)
      // Groupes de caractères supplémentaires. Ces caractères nécessitent des bitmaps 
      // complets et occupent un espace de stockage considérable:
      //#define TOUCH_UI_UTF8_SUPERSCRIPTS  // ¹ ² ³
      //#define TOUCH_UI_UTF8_COPYRIGHT     // © ®
      //#define TOUCH_UI_UTF8_GERMANIC      // ß
      //#define TOUCH_UI_UTF8_SCANDINAVIAN  // Æ Ð Ø Þ æ ð ø þ
      //#define TOUCH_UI_UTF8_PUNCTUATION   // « » ¿ ¡
      //#define TOUCH_UI_UTF8_CURRENCY      // ¢ £ ¤ ¥
      //#define TOUCH_UI_UTF8_ORDINALS      // º ª
      //#define TOUCH_UI_UTF8_MATHEMATICS   // ± × ÷
      //#define TOUCH_UI_UTF8_FRACTIONS     // ¼ ½ ¾
      //#define TOUCH_UI_UTF8_SYMBOLS       // µ ¶ ¦ § ¬
    #endif
  #endif

  // Utilisez une police plus petite lorsque les étiquettes ne correspondent pas aux boutons
  #define TOUCH_UI_FIT_TEXT

  // Autoriser la sélection de la langue dans le menu au moment de l'exécution (sinon utilisez LCD_LANGUAGE)
  //#define LCD_LANGUAGE_1 en
  //#define LCD_LANGUAGE_2 fr
  //#define LCD_LANGUAGE_3 de
  //#define LCD_LANGUAGE_4 es
  //#define LCD_LANGUAGE_5 it

  // Utilisez un code d'accès numérique pour le clavier "Verrouillage de l'écran".
  // (recommandé pour les petits écrans)
  //#define TOUCH_UI_PASSCODE

  // Afficher des informations de débogage supplémentaires pour les événements Touch UI
  //#define TOUCH_UI_DEBUG

  // Menu développeur (accessible en touchant le texte de copyright "A propos de l'imprimante")
  //#define TOUCH_UI_DEVELOPER_MENU
#endif

//
// FSMC graphique TFT
//
#if ENABLED(FSMC_GRAPHICAL_TFT)
  //#define TFT_MARLINUI_COLOR 0xFFFF // Blanc
  //#define TFT_MARLINBG_COLOR 0x0000 // Noir
  //#define TFT_DISABLED_COLOR 0x0003 // Presque noir ( Gris ?)
  //#define TFT_BTCANCEL_COLOR 0xF800 // Rouge
  //#define TFT_BTARROWS_COLOR 0xDEE6 // 11011 110111 00110 Jaune
  //#define TFT_BTOKMENU_COLOR 0x145F // 00010 100010 11111 Cyan
#endif

//
// Anti-rebond du bouton ADC
//
#if HAS_ADC_BUTTONS
  #define ADC_BUTTON_DEBOUNCE_DELAY 16  // (ms) Augmentez si les appuis rebondissent ou se répètent trop rapidement
#endif

// @section safety

/**
 * La minuterie matérielle du watchdog effectuera une réinitialisation et désactivera toutes 
 * les sorties si le micrologiciel est trop surchargé pour lire les capteurs de température.
 *
 * Si vous constatez que le redémarrage du watchdog entraîne le blocage permanent de votre carte AVR, activez 
 * WATCHDOG_RESET_MANUAL pour utiliser un minuteur personnalisé au lieu de WDTO.
 * REMARQUE: cette méthode est moins fiable car elle ne peut intercepter les blocages 
 * que lorsque les interruptions sont activées.
 */
#define USE_WATCHDOG
#if ENABLED(USE_WATCHDOG)
  //#define WATCHDOG_RESET_MANUAL
#endif

// @section lcd

/**
 * Babystepping permet de déplacer les axes par petits incréments sans modifier les valeurs 
 * de position actuelles. Cette fonction est principalement utilisée pour ajuster l'axe Z 
 * pour la première couche d'une impression en temps réel.
 *
 * Attention: ne respecte pas les butées de fin de course!
 */
//#define BABYSTEPPING
#if ENABLED(BABYSTEPPING)
  //#define INTEGRATED_BABYSTEPPING         // Intégration EXPÉRIMENTALE du babystepping dans le Stepper ISR
  //#define BABYSTEP_WITHOUT_HOMING
  //#define BABYSTEP_XY                     // Activez également le babystepping X / Y. Non pris en charge sur DELTA!
  #define BABYSTEP_INVERT_Z false           // Changer si les babysteps Z doivent aller dans l'autre sens
  #define BABYSTEP_MULTIPLICATOR_Z  1       // Les babysteps sont très petits. Augmentez pour un mouvement plus rapide.
  #define BABYSTEP_MULTIPLICATOR_XY 1

  //#define DOUBLECLICK_FOR_Z_BABYSTEPPING  // Double-cliquez sur l'écran d'état de Z Babystepping.
  #if ENABLED(DOUBLECLICK_FOR_Z_BABYSTEPPING)
    #define DOUBLECLICK_MAX_INTERVAL 1250   // Intervalle maximum entre les clics, en millisecondes.
                                            // Remarque: du temps supplémentaire peut être ajouté pour atténuer la latence du contrôleur.
    //#define BABYSTEP_ALWAYS_AVAILABLE     // Autorisez le babystepping à tout moment (pas seulement pendant le mouvement).
    //#define MOVE_Z_WHEN_IDLE              // Accédez au menu de déplacement Z sur double-clic lorsque l'imprimante est inactive.
    #if ENABLED(MOVE_Z_WHEN_IDLE)
      #define MOVE_Z_IDLE_MULTIPLICATOR 1   // Multipliez 1 mm par ce facteur pour la taille du pas de déplacement.
    #endif
  #endif

  //#define BABYSTEP_DISPLAY_TOTAL          // Afficher le nombre total de babysteps depuis le dernier G28

  //#define BABYSTEP_ZPROBE_OFFSET          // Combinez M851 Z et Babystepping
  #if ENABLED(BABYSTEP_ZPROBE_OFFSET)
    //#define BABYSTEP_HOTEND_Z_OFFSET      // Pour plusieurs hotends, babystep décalages Z relatifs
    //#define BABYSTEP_ZPROBE_GFX_OVERLAY   // Activer la superposition graphique sur l'éditeur de Zoffset
  #endif
#endif

// @section extrudeur

/**
 * Contrôle de pression linéaire v1.5 (Linear advance)
 *
 * Hypothèse: avance [pas] = k * (vitesse delta [pas / s])
 * K = 0 signifie que l'avance est désactivée.
 *
 * REMARQUE: les valeurs K pour LIN_ADVANCE 1.5 diffèrent des versions antérieures!
 *
 * Réglez K autour de 0,22 pour un entraînement direct PLA de 3 mm avec ~ 6,5 cm entre l'engrenage d'entraînement et le heatbreak.
 * Des valeurs de K plus élevées seront nécessaires pour un filament flexible et de plus grandes distances.
 * Si cet algorithme produit un décalage de vitesse plus élevé que l'extrudeur ne peut gérer (par rapport à E jerk), 
 * l'accélération d'impression sera réduite pendant les mouvements affectés pour rester dans la limite.
 *
 * Voir http://marlinfw.org/docs/features/lin_advance.html pour des instructions complètes.
 * Mentionnez @ Sebastianv650 sur GitHub pour alerter l'auteur de tout problème.
 */
//#define LIN_ADVANCE
#if ENABLED(LIN_ADVANCE)
  //#define EXTRA_LIN_ADVANCE_K // Pour activer plus de constantes de Linear advance
  #define LIN_ADVANCE_K 0.22    // Unité: compression mm par vitesse d'extrudeur 1 mm / s
  //#define LA_DEBUG            // S'il est activé, cela générera une sortie d'informations de débogage via USB.
#endif

// @section nivellement

/**
 * Points à sonder pour toutes les procédures de mise à niveau en 3 points.
 * Remplacez si les points sélectionnés automatiquement sont inadéquats.
 */
#if EITHER(AUTO_BED_LEVELING_3POINT, AUTO_BED_LEVELING_UBL)
  //#define PROBE_PT_1_X 15
  //#define PROBE_PT_1_Y 180
  //#define PROBE_PT_2_X 15
  //#define PROBE_PT_2_Y 20
  //#define PROBE_PT_3_X 170
  //#define PROBE_PT_3_Y 20
#endif

/**
 * Remplacer MIN_PROBE_EDGE pour chaque côté du plateau. Utile pour obtenir des 
 * points de sonde aux positions exactes sur les cibles ou pour permettre le 
 * nivellement afin d'éviter les pinces ou vis seulement sur des 
 * côtés spécifiques du plateau. Avec NOZZLE_AS_PROBE, des valeurs négatives 
 * sont autorisées pour permettre de sonder à l'extérieur du plateau.
 *
 * Si vous remplacez les options * _PROBE_BED_POSITION ,
 * les valeurs LEFT et FRONT dans la plupart 
 * des cas seront mappées directement sur RIGHT et REAR (en effet miroir), 
 * comme (X / Y_BED_SIZE - RIGHT / BACK_PROBE_BED_POSITION)
 *
 * Cela permettra à toutes les positions de correspondre à la compilation, 
 * mais si la position de la sonde est modifiée avec M851XY, 
 * la position des points de sonde le seront aussi. Cela empêche tout changement 
 * de rendre la sonde incapable d'atteindre les points.
 */
#if PROBE_SELECTED && !IS_KINEMATIC
  //#define MIN_PROBE_EDGE_LEFT MIN_PROBE_EDGE
  //#define MIN_PROBE_EDGE_RIGHT MIN_PROBE_EDGE
  //#define MIN_PROBE_EDGE_FRONT MIN_PROBE_EDGE
  //#define MIN_PROBE_EDGE_BACK MIN_PROBE_EDGE
#endif

#if EITHER(MESH_BED_LEVELING, AUTO_BED_LEVELING_UBL)
  // Override the mesh area if the automatic (max) area is too large
  //#define MESH_MIN_X MESH_INSET
  //#define MESH_MIN_Y MESH_INSET
  //#define MESH_MAX_X X_BED_SIZE - (MESH_INSET)
  //#define MESH_MAX_Y Y_BED_SIZE - (MESH_INSET)
#endif

/**
 * Essayez à plusieurs reprises le nivellement G29 jusqu'à ce qu'il réussisse.
 * Arrêtez après un nombre de tentatives de G29_MAX_RETRIES.
 */
//#define G29_RETRY_AND_RECOVER
#if ENABLED(G29_RETRY_AND_RECOVER)
  #define G29_MAX_RETRIES 3
  #define G29_HALT_ON_FAILURE
  /**
   * Spécifiez les commandes GCODE qui seront exécutées lorsque la mise à niveau réussit, entre les tentatives et après que le nombre maximal de tentatives a été tenté.
   * entre les tentatives et après que le nombre maximal de tentatives a été tenté.
   */
  #define G29_SUCCESS_COMMANDS "M117 Nivellement du lit terminé."
  #define G29_RECOVER_COMMANDS "M117 La sonde a échoué. Rewiping.\nG28\nG12 P0 S12 T0"
  #define G29_FAILURE_COMMANDS "M117 Échec de la mise à niveau du lit.\nG0 Z10\nM300 P25 S880\nM300 P50 S0\nM300 P25 S880\nM300 P50 S0\nM300 P25 S880\nM300 P50 S0\nG4 S1"

#endif

/**
 * Compensation des sondes thermique (Thermistances)
 * Les mesures de la sonde sont ajustées pour compenser la distorsion de température.
 * Utilisez G76 pour calibrer cette fonction. Utilisez M871 pour définir les valeurs manuellement.
 * Pour une explication plus détaillée du processus, voir G76_M871.cpp.
 */
#if HAS_BED_PROBE && TEMP_SENSOR_PROBE && TEMP_SENSOR_BED
  // Activer la compensation thermique de la première couche en utilisant les températures du lit et de la sonde
  #define PROBE_TEMP_COMPENSATION

  // Ajoutez une compensation supplémentaire en fonction de la température du hotend
  // Remarque: ces valeurs ne peuvent pas être calibrées et doivent être définies manuellement
  #if ENABLED(PROBE_TEMP_COMPENSATION)
    // Température maximale pouvant être atteinte par le plateau chauffant.
    // Ceci n'est requis que pour le processus d'étalonnage.
    #define PTC_MAX_BED_TEMP 110

    // Position de stationnement pour attendre le temps de refroidir la sonde
    #define PTC_PARK_POS_X 0.0F
    #define PTC_PARK_POS_Y 0.0F
    #define PTC_PARK_POS_Z 100.0F

    // Position de la sonde pour sonder et attendre que la sonde atteigne la température cible
    #define PTC_PROBE_POS_X  90.0F
    #define PTC_PROBE_POS_Y 100.0F

    // Activer une compensation supplémentaire en utilisant la température du hotend
    // Remarque: ces valeurs ne peuvent pas être calibrées automatiquement mais doivent être définies manuellement
    //#define USE_TEMP_EXT_COMPENSATION
  #endif
#endif

// @section extras

//
// G60/G61 Sauvegarde et retour de position
//
//#define SAVED_POSITIONS 1         // Chaque emplacement de position enregistré coûte 12 octets

//
// G2/G3 Arc Support
//
#define ARC_SUPPORT                 // Désactivez cette fonction pour économiser ~ 3226 octets
#if ENABLED(ARC_SUPPORT)
  #define MM_PER_ARC_SEGMENT      1 // (mm) Longueur (ou longueur minimale) de chaque segment d'arc
  //#define ARC_SEGMENTS_PER_R    1 // Longueur de segment max, MM_PER = Min
  #define MIN_ARC_SEGMENTS       24 // Nombre minimum de segments dans un cercle complet
  //#define ARC_SEGMENTS_PER_SEC 50 // Utilisez la vitesse pour choisir la longueur du segment (avec MM_PER_ARC_SEGMENT comme minimum)
  #define N_ARC_CORRECTION       25 // Nombre de segments interpolés entre les corrections
  //#define ARC_P_CIRCLES           // Activez le paramètre «P» pour spécifier des cercles complets
  //#define CNC_WORKSPACE_PLANES    // Autoriser G2 / G3 à fonctionner dans les plans XY, ZX ou YZ
#endif

// Prise en charge de G5 avec destination XYZE et décalages IJPQ. Nécessite ~ 2666 octets.
//#define BEZIER_CURVE_SUPPORT

/**
 * G38 Cible de sonde
 *
 * Cette option ajoute G38.2 et G38.3 (sonde vers la cible) et 
 * éventuellement G38.4 et G38.5 (sonde loin de la cible).
 * Réglez MULTIPLE_PROBING pour G38 pour sonder plus d'une fois.
 */
//#define G38_PROBE_TARGET
#if ENABLED(G38_PROBE_TARGET)
  //#define G38_PROBE_AWAY        // Inclure G38.4 et G38.5 pour sonder loin de la cible
  #define G38_MINIMUM_MOVE 0.0275 // (mm) Distance minimale qui produira un mouvement.
#endif

// Les mouvements (ou segments) comportant moins d'étapes seront joints au prochain mouvement
#define MIN_STEPS_PER_SEGMENT 6

/**
 * Délai minimum avant et après le réglage du DIR pas à pas (en ns)
 *     0 : Pas de retard (attendez au moins 10µS car un Stepper ISR doit "transpirer")
 *    20 : Minimum pour les pilotes TMC2xxx
 *   200 : Minimum pour les pilotes A4988
 *   400 : Minimum pour les pilotes A5984
 *   500 : Minimum pour les pilotes LV8729 (devinez, aucune information dans la fiche technique)
 *   650 : Minimum pour les pilotes DRV8825
 *  1500 : Minimum pour les pilotes TB6600 (devinez, aucune information dans la fiche technique)
 * 15000 : Minimum pour les pilotes TB6560 (devinez, aucune information dans la fiche technique)
 *
 * Remplacez la valeur par défaut en fonction du type de pilote défini dans Configuration.h.
 */
//#define MINIMUM_STEPPER_POST_DIR_DELAY 650
//#define MINIMUM_STEPPER_PRE_DIR_DELAY 650

/**
 * Impulsion minimale du pilote pas à pas (en µs)
 *   0 : La plus petite largeur possible que le MCU peut produire, compatible avec les pilotes TMC2xxx
 *   0 : 500ns minimum pour LV8729, ajusté en stepper.h
 *   1 : Minimum pour les pilotes pas à pas A4988 et A5984
 *   2 : Minimum pour les pilotes pas à pas DRV8825
 *   3 : Minimum pour les pilotes pas à pas TB6600
 *  30 : Minimum pour les pilotes pas à pas TB6560
 *
 * Remplacez la valeur par défaut en fonction du type de pilote défini dans Configuration.h.
 */
//#define MINIMUM_STEPPER_PULSE 2

/**
 * Taux de progression maximum (en Hz) que le pilote pas à pas permet
 *  Si non défini, la valeur par défaut est 1 MHz / (2 * MINIMUM_STEPPER_PULSE)
 *  5000000 : Maximum pour les pilotes pas à pas TMC2xxx
 *  1000000 : Maximum pour le pilote pas à pas LV8729
 *  500000  : Maximum pour le pilote pas à pas A4988
 *  250000  : Maximum pour le pilote pas à pas DRV8825
 *  150000  : Maximum pour le pilote pas à pas TB6600
 *   15000  : Maximum pour le pilote pas à pas TB6560
 *
 * Remplacez la valeur par défaut en fonction du type de pilote défini dans Configuration.h.
 */
//#define MAXIMUM_STEPPER_RATE 250000

// @section temperature

// Contrôler le chauffage 0 et le chauffage 1 en parallèle.
//#define HEATERS_PARALLEL

//===========================================================================
//================================= Buffers =================================
//===========================================================================

// @section cachée

// Le nombre de mouvements linéaires qui peuvent être fait dans le plan à tout moment.
// LA BLOCK_BUFFER_SIZE DOIT ÊTRE UN MULTIPLE DE 2 (par exemple 8, 16, 32) car les décalages et les "ou" sont utilisés pour faire la mise en mémoire tampon.
#if ENABLED(SDSUPPORT)
  #define BLOCK_BUFFER_SIZE 16 // SD, LCD et les boutons prennent plus de mémoire, le tampon de block doit être plus petit
#else
  #define BLOCK_BUFFER_SIZE 16 // maximiser le tampon de block
#endif

// @section connections série

// Le tampon ASCII pour l'entrée série
#define MAX_CMD_SIZE 96
#define BUFSIZE 4

// Transmission à l'hôte de la taille du tampon 
// Pour enregistrer 386 octets de PROGMEM (et TX_BUFFER_SIZE + 3 octets de RAM), définissez sur 0.
// Pour bufferiser un simple "ok", vous avez besoin de 4 octets.
// Pour ADVANCED_OK (M105), vous avez besoin de 32 octets.
// Pour debug-echo: 128 octets pour la vitesse optimale.
// Les autres sorties n'ont pas besoin d'être aussi rapides.
// :[0, 2, 4, 8, 16, 32, 64, 128, 256]
#define TX_BUFFER_SIZE 0

// Taille du tampon de réception de l'hôte
// Sans contrôle de flux XON / XOFF (voir SERIAL_XON_XOFF ci-dessous), 32 octets devraient suffire.
// Pour utiliser le contrôle de flux, définissez cette taille de tampon sur au moins 1024 octets.
// :[0, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048]
//#define RX_BUFFER_SIZE 1024

#if RX_BUFFER_SIZE >= 1024
  // Activez pour que le contrôleur envoie des caractères de contrôle XON / XOFF 
  // à l'hôte pour signaler que le tampon RX est plein.
  //#define SERIAL_XON_XOFF
#endif

// Ajoutez le Gcode M575 pour modifier le débit en bauds
//#define BAUD_RATE_GCODE

#if ENABLED(SDSUPPORT)
  // Activez cette option pour collecter et afficher l'utilisation maximale 
  // de la file d'attente RX après le transfert d'un fichier vers SD.
  //#define SERIAL_STATS_MAX_RX_QUEUED

  // Activez cette option pour collecter et afficher le nombre 
  // d'octets supprimés après un transfert de fichier vers SD.
  //#define SERIAL_STATS_DROPPED_RX
#endif

// Activez un analyseur de commandes d'urgence pour intercepter certaines commandes lorsqu'elles 
// entrent dans le tampon de réception série, afin qu'elles ne puissent pas être bloquées.
// Gère actuellement M108, M112, M410
// Ne fonctionne pas sur les cartes utilisant des processeurs AT90USB (USBCON)!
//#define EMERGENCY_PARSER

// De mauvaises connexions série peuvent manquer une commande reçue en envoyant un «ok». 
// Par conséquent, certains clients abandonnent après 30 secondes dans un délai d'attente.
// Certains autres clients commencent à envoyer des commandes tout en recevant un «wait».
// Ce «wait» n'est envoyée que lorsque le tampon est vide. 1 seconde est une bonne valeur ici.
//#define NO_TIMEOUTS 1000 // Milliseconds

// Certains clients auront bientôt cette fonctionnalité. Cela pourrait rendre le NO_TIMEOUTS inutile.
//#define ADVANCED_OK

// Printrun peut avoir du mal à recevoir de longues trames à la fois.
// Cette option insère de courts délais entre les lignes de sortie série.
#define SERIAL_OVERRUN_PROTECTION

// @section extras

/**
 * Vitesse de ventilateur supplémentaire
 * Ajoute une vitesse de ventilateur secondaire pour chaque ventilateur de refroidissement d'impression.
 *   'M106 P<fan> T3-255' : Définissez une vitesse secondaire pour <fan>
 *   'M106 P<fan> T2'     : Utiliser la vitesse secondaire réglée
 *   'M106 P<fan> T1'     : Revenir à la vitesse précédente du ventilateur
 */
//#define EXTRA_FAN_SPEED

/**
 * Rétraction basée sur le micrologiciel et contrôlée par LCD
 *
 * Ajoutez des commandes G10 / G11 pour une rétraction / récupération automatique basée sur le micrologiciel.
 * Utilisez M207 et M208 pour définir les paramètres de retrait / récupération.
 *
 * Utilisez M209 pour activer ou désactiver la rétraction automatique.
 * Lorsque la rétraction automatique est activée, tous les mouvements G1 E dans la plage définie 
 * seront convertis en mouvements de rétraction / récupération basés sur le micrologiciel.
 *
 * Assurez-vous de désactiver la rétraction automatique pendant le changement de filament.
 *
 * Notez que les paramètres M207 / M208 / M209 sont enregistrés dans l'EEPROM.
 *
 */
//#define FWRETRACT
#if ENABLED(FWRETRACT)
  #define FWRETRACT_AUTORETRACT           // Remplacer les rétractations du trancheur
  #if ENABLED(FWRETRACT_AUTORETRACT)
    #define MIN_AUTORETRACT 0.1           // (mm) Ne convertissez pas les mouvements E inférieur à cette longueur
    #define MAX_AUTORETRACT 10.0          // (mm) Ne convertissez pas les mouvements E suppérieur à cette longueur
  #endif
  #define RETRACT_LENGTH 3                // (mm) Longueur de retrait par défaut (valeur positive)
  #define RETRACT_LENGTH_SWAP 13          // (mm) Longueur de retrait de swap par défaut (valeur positive)
  #define RETRACT_FEEDRATE 45             // (mm/s) Vitesse par défaut pour la rétraction
  #define RETRACT_ZRAISE 0                // (mm) Retrait par défaut Z-raise ( Z hop dans Cura)
  #define RETRACT_RECOVER_LENGTH 0        // (mm) Longueur de récupération supplémentaire par défaut (ajoutée pour rétracter la longueur lors de la récupération)
  #define RETRACT_RECOVER_LENGTH_SWAP 0   // (mm) Longueur de récupération de swap supplémentaire par défaut (ajoutée pour rétracter la longueur lors de la récupération après un changement d'outils)
  #define RETRACT_RECOVER_FEEDRATE 8      // (mm/s) Vitesse par défaut pour la récupération après rétraction
  #define RETRACT_RECOVER_FEEDRATE_SWAP 8 // (mm/s) Vitesse par défaut pour la récupération suite à la rétraction du swap
  #if ENABLED(MIXING_EXTRUDER)
    //#define RETRACT_SYNC_MIXING         // Rétractez et restaurez tous les steppers de mélange simultanément
  #endif
#endif

/**
 * Paramètres de changement d'outil universels.
 * S'applique à tous les types d'extrudeurs, sauf indication contraire explicite.
 */
#if EXTRUDERS > 1
  // Augmenter la distance Z pour le changement d'outil, selon les besoins de certains extrudeurs
  #define TOOLCHANGE_ZRAISE     2  // (mm)
  //#define TOOLCHANGE_NO_RETURN   // Ne revenez jamais à la position précédente lors du changement d'outil
  #if ENABLED(TOOLCHANGE_NO_RETURN)
    //#define EVENT_GCODE_AFTER_TOOLCHANGE "G12X"   // Gcode à exécuter une fois le changement d'outil terminé
  #endif

  // Rétracter et amorcer le filament lors du changement d'outil
  //#define TOOLCHANGE_FILAMENT_SWAP
  #if ENABLED(TOOLCHANGE_FILAMENT_SWAP)
    #define TOOLCHANGE_FIL_SWAP_LENGTH          12  // (mm)
    #define TOOLCHANGE_FIL_EXTRA_PRIME           2  // (mm)
    #define TOOLCHANGE_FIL_SWAP_RETRACT_SPEED 3600  // (mm/m)
    #define TOOLCHANGE_FIL_SWAP_PRIME_SPEED   3600  // (mm/m)
  #endif

  /**
   * Position pour garer  la tête pendant le changement d'outil.
   * Ne s'applique pas à SWITCHING_TOOLHEAD, DUAL_X_CARRIAGE ou PARKING_EXTRUDER
   */
  //#define TOOLCHANGE_PARK
  #if ENABLED(TOOLCHANGE_PARK)
    #define TOOLCHANGE_PARK_XY    { X_MIN_POS + 10, Y_MIN_POS + 10 }
    #define TOOLCHANGE_PARK_XY_FEEDRATE 6000  // (mm/m)
  #endif
#endif

/**
 * Pause avancée (Advanced Pause)
 * Fonction expérimentale pour le support du changement de filament et pour garer la buse en pause.
 * Ajoute le GCode M600 pour initier le changement de filament.
 * Si PARK_HEAD_ON_PAUSE est activé, ajoute le GCode M125 pour suspendre l'impression et garer la buse.
 *
 * Nécessite un écran LCD.
 * Nécessite NOZZLE_PARK_FEATURE.
 * Cette fonctionnalité est requise pour le FILAMENT_RUNOUT_SCRIPT par défaut.
 */
//#define ADVANCED_PAUSE_FEATURE
#if ENABLED(ADVANCED_PAUSE_FEATURE)
  #define PAUSE_PARK_RETRACT_FEEDRATE         60  // (mm/s) Vitesse de rétraction initiale.
  #define PAUSE_PARK_RETRACT_LENGTH            2  // (mm) Rétraction initiale.
                                                  // Ce court retrait se fait immédiatement, avant de garer la buse.
  #define FILAMENT_CHANGE_UNLOAD_FEEDRATE     10  // (mm/s) Vitesse de déchargement du filament. Cela peut être assez rapide.
  #define FILAMENT_CHANGE_UNLOAD_ACCEL        25  // (mm/s^2) Une accélération plus faible peut permettre une vitesse de déchargement plus rapide.
  #define FILAMENT_CHANGE_UNLOAD_LENGTH      100  // (mm) La longueur du filament pour un déchargement complet.
                                                  //   Pour Bowden, toute la longueur du tube et de la buse.
                                                  //   Pour l'entraînement direct, toute la longueur de la buse.
                                                  //   Réglez sur 0 pour un déchargement manuel.
  #define FILAMENT_CHANGE_SLOW_LOAD_FEEDRATE   6  // (mm/s) Déplacement lent lors du démarrage du chargement
  #define FILAMENT_CHANGE_SLOW_LOAD_LENGTH     0  // (mm) Longueur lente, pour laisser le temps d'insérer le matériau.
                                                  // 0 pour passer à un chargement rapide uniquement
  #define FILAMENT_CHANGE_FAST_LOAD_FEEDRATE   6  // (mm/s) Vitesse de chargement du filament. Cela peut être assez rapide.
  #define FILAMENT_CHANGE_FAST_LOAD_ACCEL     25  // (mm/s^2) Une accélération plus faible peut permettre une vitesse de chargement plus rapide.
  #define FILAMENT_CHANGE_FAST_LOAD_LENGTH     0  // (mm) Longueur du filament, de l'engrenage de l'extrudeur à la buse.
                                                  //   Pour Bowden, toute la longueur du tube et de la buse.
                                                  //   Pour l'entraînement direct, toute la longueur de la buse.
  //#define ADVANCED_PAUSE_CONTINUOUS_PURGE       // Purger toute la longueur sans interruption.
  #define ADVANCED_PAUSE_PURGE_FEEDRATE        3  // (mm/s) Vitesse d'extrusion (après le chargement). Doit être plus lente que la vitesse de charge.
  #define ADVANCED_PAUSE_PURGE_LENGTH         50  // (mm) Longueur à extruder après chargement.
                                                  //   Réglez sur 0 pour une extrusion manuelle.
                                                  //  Le filament peut être extrudé à plusieurs reprises à partir du menu "Changement de filament" 
                                                  //  jusqu'à ce que l'extrusion soit cohérente et pour purger l'ancien filament.
  #define ADVANCED_PAUSE_RESUME_PRIME          0  // (mm) Distance supplémentaire pour amorcer la buse après son retour de la position de garage.
  //#define ADVANCED_PAUSE_FANS_PAUSE             // Désactivez les ventilateurs de refroidissement d'impression pendant que la machine est en pause.

                                                  // Le déchargement de filament effectue d'abord un retrait, une pause et une purge:
  #define FILAMENT_UNLOAD_PURGE_RETRACT       13  // (mm) Déchargez la longueur de retrait initiale.
  #define FILAMENT_UNLOAD_PURGE_DELAY       5000  // (ms) Délai de refroidissement du filament après rétraction.
  #define FILAMENT_UNLOAD_PURGE_LENGTH         8  // (mm) Une rétraction est effectuée, puis cette longueur est purgée.
  #define FILAMENT_UNLOAD_PURGE_FEEDRATE      25  // (mm/s) vitesse de purge avant déchargement

  #define PAUSE_PARK_NOZZLE_TIMEOUT           45  // (seconds) Délai avant l'arrêt du chauffage de la buse pour des raisons de sécurité.
  #define FILAMENT_CHANGE_ALERT_BEEPS         10  // Nombre de bips d'alerte à émettre lorsqu'une action est nécessaire.
  #define PAUSE_PARK_NO_STEPPER_TIMEOUT           // Laisser activer les steppers XYZ pendant le changement de filament.

  //#define PARK_HEAD_ON_PAUSE                    // Garez la buse pendant la pause et le changement de filament.
  //#define HOME_BEFORE_FILAMENT_CHANGE           // Effectuer une prise d'origine avant le stationnement pour le changement de filament

  //#define FILAMENT_LOAD_UNLOAD_GCODES           // Ajoutez les Gcodes M701 / M702 Charger / Décharger, et les actions Charger / Décharger sur le LCD dans le menu "préparer".
  //#define FILAMENT_UNLOAD_ALL_EXTRUDERS         // Autoriser M702 à décharger tous les extrudeurs au-dessus d'une température cible minimale (telle que définie par M302)
#endif

// @section tmc

/**
 * Options du pilote pas à pas TMC26X
 *
 * La bibliothèque TMC26XStepper est requise pour ce pilote pas à pas.
 * https://github.com/trinamic/TMC26XStepper
 */
#if HAS_DRIVER(TMC26X)

  #if AXIS_DRIVER_TYPE_X(TMC26X)
    #define X_MAX_CURRENT     1000  // (mA)
    #define X_SENSE_RESISTOR    91  // (mOhms)
    #define X_MICROSTEPS        16  // Nombre de micropas
  #endif

  #if AXIS_DRIVER_TYPE_X2(TMC26X)
    #define X2_MAX_CURRENT    1000
    #define X2_SENSE_RESISTOR   91
    #define X2_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_Y(TMC26X)
    #define Y_MAX_CURRENT     1000
    #define Y_SENSE_RESISTOR    91
    #define Y_MICROSTEPS        16
  #endif

  #if AXIS_DRIVER_TYPE_Y2(TMC26X)
    #define Y2_MAX_CURRENT    1000
    #define Y2_SENSE_RESISTOR   91
    #define Y2_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_Z(TMC26X)
    #define Z_MAX_CURRENT     1000
    #define Z_SENSE_RESISTOR    91
    #define Z_MICROSTEPS        16
  #endif

  #if AXIS_DRIVER_TYPE_Z2(TMC26X)
    #define Z2_MAX_CURRENT    1000
    #define Z2_SENSE_RESISTOR   91
    #define Z2_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_Z3(TMC26X)
    #define Z3_MAX_CURRENT    1000
    #define Z3_SENSE_RESISTOR   91
    #define Z3_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_Z4(TMC26X)
    #define Z4_MAX_CURRENT    1000
    #define Z4_SENSE_RESISTOR   91
    #define Z4_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E0(TMC26X)
    #define E0_MAX_CURRENT    1000
    #define E0_SENSE_RESISTOR   91
    #define E0_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E1(TMC26X)
    #define E1_MAX_CURRENT    1000
    #define E1_SENSE_RESISTOR   91
    #define E1_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E2(TMC26X)
    #define E2_MAX_CURRENT    1000
    #define E2_SENSE_RESISTOR   91
    #define E2_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E3(TMC26X)
    #define E3_MAX_CURRENT    1000
    #define E3_SENSE_RESISTOR   91
    #define E3_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E4(TMC26X)
    #define E4_MAX_CURRENT    1000
    #define E4_SENSE_RESISTOR   91
    #define E4_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E5(TMC26X)
    #define E5_MAX_CURRENT    1000
    #define E5_SENSE_RESISTOR   91
    #define E5_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E6(TMC26X)
    #define E6_MAX_CURRENT    1000
    #define E6_SENSE_RESISTOR   91
    #define E6_MICROSTEPS       16
  #endif

  #if AXIS_DRIVER_TYPE_E7(TMC26X)
    #define E7_MAX_CURRENT    1000
    #define E7_SENSE_RESISTOR   91
    #define E7_MICROSTEPS       16
  #endif

#endif // TMC26X

// @section tmc_smart

/**
 * Pour utiliser les pilotes pas à pas TMC2130, TMC2160, TMC2660, TMC5130, TMC5160 en mode SPI, 
 * connectez vos broches SPI à l'interface SPI matérielle de votre carte et définissez les broches CS requises
 * dans votre fichier `pins_MYBOARD.h`. (par exemple, RAMPS 1.4 utilise AUX3pins `X_CS_PIN 53`,` Y_CS_PIN 49`, etc.).
 *  
 * Vous pouvez également utiliser le logiciel SPI si vous souhaitez utiliser des broches d'E / S à usage général.
 *
 * Pour utiliser les pilotes pas à pas TMC2208 en mode UART, connectez #_SERIAL_TX_PIN
 * à la broche PDN_UART côté conducteur avec une résistance 1K.
 * Pour exploiter les capacités de lecture, connectez également 
 * #_SERIAL_RX_PIN à PDN_UART sans résistance.
 * Les pilotes peuvent également être utilisés avec le matériel série.
 *
 * La bibliothèque TMCStepper est requise pour utiliser les pilotes pas à pas TMC.
 * https://github.com/teemuatlut/TMCStepper
 */
#if HAS_TRINAMIC

  #define HOLD_MULTIPLIER    0.5  // Réduit le courant de maintien en fonction du courant de fonctionnement
  #define INTERPOLATE       true  // Interpoler X / Y / Z_MICROSTEPS à 256

  #if AXIS_IS_TMC(X)
    #define X_CURRENT       800        // (mA) Courant RMS. Multipliez par 1,414 pour le courant de crête.
    #define X_CURRENT_HOME  X_CURRENT  // (mA) Courant RMS pour le référencement sans capteur de fin de course
    #define X_MICROSTEPS     16    // 0..256
    #define X_RSENSE          0.11
    #define X_CHAIN_POS      -1    // <=0 : Not chained. 1 : MCU MOSI connected. 2 : Next in chain, ...
  #endif

  #if AXIS_IS_TMC(X2)
    #define X2_CURRENT      800
    #define X2_CURRENT_HOME X2_CURRENT
    #define X2_MICROSTEPS    16
    #define X2_RSENSE         0.11
    #define X2_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(Y)
    #define Y_CURRENT       800
    #define Y_CURRENT_HOME  Y_CURRENT
    #define Y_MICROSTEPS     16
    #define Y_RSENSE          0.11
    #define Y_CHAIN_POS      -1
  #endif

  #if AXIS_IS_TMC(Y2)
    #define Y2_CURRENT      800
    #define Y2_CURRENT_HOME Y2_CURRENT
    #define Y2_MICROSTEPS    16
    #define Y2_RSENSE         0.11
    #define Y2_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(Z)
    #define Z_CURRENT       800
    #define Z_CURRENT_HOME  Z_CURRENT
    #define Z_MICROSTEPS     16
    #define Z_RSENSE          0.11
    #define Z_CHAIN_POS      -1
  #endif

  #if AXIS_IS_TMC(Z2)
    #define Z2_CURRENT      800
    #define Z2_CURRENT_HOME Z2_CURRENT
    #define Z2_MICROSTEPS    16
    #define Z2_RSENSE         0.11
    #define Z2_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(Z3)
    #define Z3_CURRENT      800
    #define Z3_CURRENT_HOME Z3_CURRENT
    #define Z3_MICROSTEPS    16
    #define Z3_RSENSE         0.11
    #define Z3_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(Z4)
    #define Z4_CURRENT      800
    #define Z4_CURRENT_HOME Z4_CURRENT
    #define Z4_MICROSTEPS    16
    #define Z4_RSENSE         0.11
    #define Z4_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(E0)
    #define E0_CURRENT      800
    #define E0_MICROSTEPS    16
    #define E0_RSENSE         0.11
    #define E0_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(E1)
    #define E1_CURRENT      800
    #define E1_MICROSTEPS    16
    #define E1_RSENSE         0.11
    #define E1_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(E2)
    #define E2_CURRENT      800
    #define E2_MICROSTEPS    16
    #define E2_RSENSE         0.11
    #define E2_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(E3)
    #define E3_CURRENT      800
    #define E3_MICROSTEPS    16
    #define E3_RSENSE         0.11
    #define E3_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(E4)
    #define E4_CURRENT      800
    #define E4_MICROSTEPS    16
    #define E4_RSENSE         0.11
    #define E4_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(E5)
    #define E5_CURRENT      800
    #define E5_MICROSTEPS    16
    #define E5_RSENSE         0.11
    #define E5_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(E6)
    #define E6_CURRENT      800
    #define E6_MICROSTEPS    16
    #define E6_RSENSE         0.11
    #define E6_CHAIN_POS     -1
  #endif

  #if AXIS_IS_TMC(E7)
    #define E7_CURRENT      800
    #define E7_MICROSTEPS    16
    #define E7_RSENSE         0.11
    #define E7_CHAIN_POS     -1
  #endif

  /**
   * Remplacez ici les broches SPI par défaut pour les pilotes TMC2130, TMC2160, TMC2660, TMC5130 et TMC5160.
   * Les broches par défaut se trouvent dans le fichier de broches de votre carte. (Pins_carte.h)
   */
  //#define X_CS_PIN          -1
  //#define Y_CS_PIN          -1
  //#define Z_CS_PIN          -1
  //#define X2_CS_PIN         -1
  //#define Y2_CS_PIN         -1
  //#define Z2_CS_PIN         -1
  //#define Z3_CS_PIN         -1
  //#define E0_CS_PIN         -1
  //#define E1_CS_PIN         -1
  //#define E2_CS_PIN         -1
  //#define E3_CS_PIN         -1
  //#define E4_CS_PIN         -1
  //#define E5_CS_PIN         -1
  //#define E6_CS_PIN         -1
  //#define E7_CS_PIN         -1

  /**
   * Option logicielle pour les pilotes SPI (TMC2130, TMC2160, TMC2660, TMC5130 et TMC5160).
   * Les broches SW SPI par défaut sont définies dans leurs fichiers de broches respectifs, 
   * mais vous pouvez les remplacer ou les définir ici.
   */
  //#define TMC_USE_SW_SPI
  //#define TMC_SW_MOSI       -1
  //#define TMC_SW_MISO       -1
  //#define TMC_SW_SCK        -1

  /**
   * Quatre pilotes TMC2209 peuvent utiliser le même port série HW / SW avec des adresses configurées par matériel.
   * Réglez l'adresse à l'aide de cavaliers sur les broches MS1 et MS2.
   * Address | MS1  | MS2
   *       0 | LOW  | LOW
   *       1 | HIGH | LOW
   *       2 | LOW  | HIGH
   *       3 | HIGH | HIGH
   *
   * Réglez * _SERIAL_TX_PIN et * _SERIAL_RX_PIN pour correspondre à tous les pilotes 
   * sur le même port série, ici ou dans le fichier de broches de votre carte.
   */
  #define  X_SLAVE_ADDRESS 0
  #define  Y_SLAVE_ADDRESS 0
  #define  Z_SLAVE_ADDRESS 0
  #define X2_SLAVE_ADDRESS 0
  #define Y2_SLAVE_ADDRESS 0
  #define Z2_SLAVE_ADDRESS 0
  #define Z3_SLAVE_ADDRESS 0
  #define Z4_SLAVE_ADDRESS 0
  #define E0_SLAVE_ADDRESS 0
  #define E1_SLAVE_ADDRESS 0
  #define E2_SLAVE_ADDRESS 0
  #define E3_SLAVE_ADDRESS 0
  #define E4_SLAVE_ADDRESS 0
  #define E5_SLAVE_ADDRESS 0
  #define E6_SLAVE_ADDRESS 0
  #define E7_SLAVE_ADDRESS 0

  /**
   * Activer le logiciel
   *
   * À utiliser pour les pilotes qui n'utilisent pas de broche d'activation dédiée, 
   * mais gèrent plutôt la même fonction via une ligne de communication telle que SPI ou UART.
   */
  //#define SOFTWARE_DRIVER_ENABLE

  /**
   * TMC2130, TMC2160, TMC2208, TMC2209, TMC5130 et TMC5160 uniquement
   * Utilisez le mode pas à pas ultra silencieux de Trinamic.
   * Lorsqu'il est désactivé, Marlin utilisera le mode pas à pas spreadCycle.
   */
  #define STEALTHCHOP_XY
  #define STEALTHCHOP_Z
  #define STEALTHCHOP_E

  /**
   * Optimisez les paramètres du trancheur spreadCycle en utilisant des jeux 
   * de paramètres prédéfinis ou à l'aide d'un exemple inclus dans la bibliothèque.
   * Provided parameter sets are
   * CHOPPER_DEFAULT_12V
   * CHOPPER_DEFAULT_19V
   * CHOPPER_DEFAULT_24V
   * CHOPPER_DEFAULT_36V
   * CHOPPER_PRUSAMK3_24V // Paramètres importés du firmware officiel Prusa pour MK3 (24V)
   * CHOPPER_MARLIN_119   // Anciennes valeurs par défaut de Marlin v1.1.9
   *
   * Définissez votre propriété avec
   * { <off_time[1..15]>, <hysteresis_end[-3..12]>, hysteresis_start[1..8] }
   */
  #define CHOPPER_TIMING CHOPPER_DEFAULT_12V

  /**
   * Surveillez les pilotes Trinamic pour les conditions d'erreur, 
   * comme la surchauffe et le court-circuit à la masse.
   * IDans le cas d'une surchauffe, Marlin peut diminuer le courant du pilote jusqu'à ce que la condition d'erreur disparaisse.
   * D'autres conditions détectées peuvent être utilisées pour arrêter l'impression en cours.
   * Gcodes pertinents:
   * M906 - Réglez ou obtenez le courant du moteur en milliampères à l'aide des codes d'axe X, Y, Z, E. Reportez les valeurs si aucun code d'axe n'est indiqué.
   * M911 - Signaler la condition d'avertissement préalable de surchauffe du moteur pas à pas.
   * M912 - Effacer l'indicateur de condition d'avertissement de surchauffe du pilote pas à pas.
   * M122 - Signaler les paramètres du pilote (nécessite TMC_DEBUG)
   */
  //#define MONITOR_DRIVER_STATUS

  #if ENABLED(MONITOR_DRIVER_STATUS)
    #define CURRENT_STEP_DOWN     50  // [mA]
    #define REPORT_CURRENT_CHANGE
    #define STOP_ON_ERROR
  #endif

  /**
   * TMC2130, TMC2160, TMC2208, TMC2209, TMC5130 et TMC5160 uniquement
   * Le pilote passera à spreadCycle lorsque la vitesse du moteur pas à pas dépassera HYBRID_THRESHOLD.
   * Ce mode permet des mouvements plus rapides au détriment de niveaux de bruit plus élevés.
   * STEALTHCHOP_ (XY | Z | E) doit être activé pour utiliser HYBRID_THRESHOLD.
   * M913 X / Y / Z / E pour modifier en direct le réglage
   */
  //#define HYBRID_THRESHOLD

  #define X_HYBRID_THRESHOLD     100  // [mm/s]
  #define X2_HYBRID_THRESHOLD    100
  #define Y_HYBRID_THRESHOLD     100
  #define Y2_HYBRID_THRESHOLD    100
  #define Z_HYBRID_THRESHOLD       3
  #define Z2_HYBRID_THRESHOLD      3
  #define Z3_HYBRID_THRESHOLD      3
  #define Z4_HYBRID_THRESHOLD      3
  #define E0_HYBRID_THRESHOLD     30
  #define E1_HYBRID_THRESHOLD     30
  #define E2_HYBRID_THRESHOLD     30
  #define E3_HYBRID_THRESHOLD     30
  #define E4_HYBRID_THRESHOLD     30
  #define E5_HYBRID_THRESHOLD     30
  #define E6_HYBRID_THRESHOLD     30
  #define E7_HYBRID_THRESHOLD     30

  /**
   * Utilisez StallGuard2 pour le référencement / sonde X, Y, Z.
   *
   * TMC2130, TMC2160, TMC2209, TMC2660, TMC5130 et TMC5160 uniquement
   * Connectez la broche DIAG1 du pilote pas à pas à la broche de butée X / Y.
   * Le référencement X, Y et Z sera toujours effectué en mode spreadCycle.
   *
   * X / Y / Z_STALL_SENSITIVITY est le seuil de décrochage par défaut.
   * Utilisez M914 X Y Z pour définir le seuil de décrochage lors de l'exécution:
   *
   *  Sensitivity   TMC2209   Others
   *    HIGHEST       255      -64    (Trop sensible => Faux positif)
   *    LOWEST         0        63    (Trop insensible => Pas de déclenchement)
   *
   * Il est recommandé de définir [XYZ] _HOME_BUMP_MM sur 0.
   *
   * SPI_ENDSTOPS *** Fonction bêta! *** TMC2130 uniquement ***
   * Interrogez le pilote via SPI pour déterminer la charge lors du référencement.
   * Supprime le besoin d'un fil de DIAG1 à une broche de butée.
   *
   * IMPROVE_HOMING_RELIABILITY ajuste l'accélération et le jerk lors du référencement 
   * et ajoute une période de garde pour le déclenchement de fin de course.
   */
  //#define SENSORLESS_HOMING // Pilotes compatibles StallGuard uniquement

  /**
   * Utilisez StallGuard2 pour sonder le lit avec la buse.
   *
   * ATTENTION: Cela pourrait endommager les machines qui utilisent une vis mère ou une tige filetée pour 
   *            déplacer l'axe Z. Soyez extrêmement prudent lorsque vous essayez d'activer cette fonction.
   */
  //#define SENSORLESS_PROBING // Pilotes compatibles StallGuard uniquement

  #if EITHER(SENSORLESS_HOMING, SENSORLESS_PROBING)
    // TMC2209: 0...255. TMC2130: -64...63
    #define X_STALL_SENSITIVITY  8
    #define X2_STALL_SENSITIVITY X_STALL_SENSITIVITY
    #define Y_STALL_SENSITIVITY  8
    //#define Z_STALL_SENSITIVITY  8
    //#define SPI_ENDSTOPS              // TMC2130 uniquement
    //#define IMPROVE_HOMING_RELIABILITY
  #endif

  /**
   * Fonctionnalité bêta!
   * Créez une impulsion carrée de pas de 50/50 optimale pour les pilotes pas à pas.
   */
  //#define SQUARE_WAVE_STEPPING

  /**
   * Activez la commande de débogage M122 pour les pilotes pas à pas TMC.
   * M122 S0 / 1 permettra un reporting continu.
   */
  //#define TMC_DEBUG

  /**
   * Vous pouvez définir vos propres paramètres avancés en remplissant des fonctions prédéfinies.
   * Une liste des fonctions disponibles peut être trouvée sur la page github de la bibliothèque
   * https://github.com/teemuatlut/TMCStepper
   *
   * Exemple:
   * #define TMC_ADV() { \
   *   stepperX.diag0_otpw(1); \
   *   stepperY.intpol(0); \
   * }
   */
  #define TMC_ADV() {  }

#endif // HAS_TRINAMIC

// @section L64XX

/**
 * Options du pilote pas à pas L64XX
 *
 * La bibliothèque Arduino-L6470 (0.8.0 ou supérieure) est requise.
 * https://github.com/ameyer/Arduino-L6470
 *
 * Nécessite que les éléments suivants soient définis dans votre fichier pins_votre_carte
 *     L6470_CHAIN_SCK_PIN
 *     L6470_CHAIN_MISO_PIN
 *     L6470_CHAIN_MOSI_PIN
 *     L6470_CHAIN_SS_PIN
 *     ENABLE_RESET_L64XX_CHIPS (Q) où Q est 1 pour activer et 0 pour réinitialiser
 */

#if HAS_L64XX

  //#define L6470_CHITCHAT        // Afficher des informations d'état supplémentaires

  #if AXIS_IS_L64XX(X)
    #define X_MICROSTEPS       128  // Nombre de micropas (VALIDE: 1, 2, 4, 8, 16, 32, 128) - un max de 16 pour les L6474
    #define X_OVERCURRENT     2000  // (mA) Courant où le conducteur détecte une surintensité L6470 & L6474 - 
                                    //   VALIDE: 375 x (1 - 16) - 6A max - arrondi inférieur
                                    //   POWERSTEP01: VALIDE: 1000 x (1-32) - 32A max - arrondi suppérieur
    #define X_STALLCURRENT    1500  // (mA) Courant où le conducteur détecte un décrochage (VALABLE: 31,25 * (1-128) - 4A max - arrondi)
                                    //   L6470 & L6474 - VALIDE: 31,25 * (1-128) - 4A arrondi suppérieur
                                    //   POWERSTEP01: VALIDE: 200 x (1-32) - 6,4A arrondi suppérieur
                                    //   L6474 - Le réglage STALLCURRENT est utilisé pour régler le courant nominal (TVAL)
    #define X_MAX_VOLTAGE      127  // 0-255, Tension efficace maximale vue par le moteur pas à pas - non utilisée par L6474
    #define X_CHAIN_POS         -1  // Position dans la chaîne SPI, 0 = Pas dans la chaîne, 1 = MOSI le plus proche
    #define X_SLEW_RATE          1  // 0-3, Slew 0 est le plus lent, 3 est le plus rapide
  #endif

  #if AXIS_IS_L64XX(X2)
    #define X2_MICROSTEPS      128
    #define X2_OVERCURRENT    2000
    #define X2_STALLCURRENT   1500
    #define X2_MAX_VOLTAGE     127
    #define X2_CHAIN_POS        -1
    #define X2_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(Y)
    #define Y_MICROSTEPS       128
    #define Y_OVERCURRENT     2000
    #define Y_STALLCURRENT    1500
    #define Y_MAX_VOLTAGE      127
    #define Y_CHAIN_POS         -1
    #define Y_SLEW_RATE          1
  #endif

  #if AXIS_IS_L64XX(Y2)
    #define Y2_MICROSTEPS      128
    #define Y2_OVERCURRENT    2000
    #define Y2_STALLCURRENT   1500
    #define Y2_MAX_VOLTAGE     127
    #define Y2_CHAIN_POS        -1
    #define Y2_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(Z)
    #define Z_MICROSTEPS       128
    #define Z_OVERCURRENT     2000
    #define Z_STALLCURRENT    1500
    #define Z_MAX_VOLTAGE      127
    #define Z_CHAIN_POS         -1
    #define Z_SLEW_RATE          1
  #endif

  #if AXIS_IS_L64XX(Z2)
    #define Z2_MICROSTEPS      128
    #define Z2_OVERCURRENT    2000
    #define Z2_STALLCURRENT   1500
    #define Z2_MAX_VOLTAGE     127
    #define Z2_CHAIN_POS        -1
    #define Z2_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(Z3)
    #define Z3_MICROSTEPS      128
    #define Z3_OVERCURRENT    2000
    #define Z3_STALLCURRENT   1500
    #define Z3_MAX_VOLTAGE     127
    #define Z3_CHAIN_POS        -1
    #define Z3_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(Z4)
    #define Z4_MICROSTEPS      128
    #define Z4_OVERCURRENT    2000
    #define Z4_STALLCURRENT   1500
    #define Z4_MAX_VOLTAGE     127
    #define Z4_CHAIN_POS        -1
    #define Z4_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(E0)
    #define E0_MICROSTEPS      128
    #define E0_OVERCURRENT    2000
    #define E0_STALLCURRENT   1500
    #define E0_MAX_VOLTAGE     127
    #define E0_CHAIN_POS        -1
    #define E0_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(E1)
    #define E1_MICROSTEPS      128
    #define E1_OVERCURRENT    2000
    #define E1_STALLCURRENT   1500
    #define E1_MAX_VOLTAGE     127
    #define E1_CHAIN_POS        -1
    #define E1_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(E2)
    #define E2_MICROSTEPS      128
    #define E2_OVERCURRENT    2000
    #define E2_STALLCURRENT   1500
    #define E2_MAX_VOLTAGE     127
    #define E2_CHAIN_POS        -1
    #define E2_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(E3)
    #define E3_MICROSTEPS      128
    #define E3_OVERCURRENT    2000
    #define E3_STALLCURRENT   1500
    #define E3_MAX_VOLTAGE     127
    #define E3_CHAIN_POS        -1
    #define E3_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(E4)
    #define E4_MICROSTEPS      128
    #define E4_OVERCURRENT    2000
    #define E4_STALLCURRENT   1500
    #define E4_MAX_VOLTAGE     127
    #define E4_CHAIN_POS        -1
    #define E4_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(E5)
    #define E5_MICROSTEPS      128
    #define E5_OVERCURRENT    2000
    #define E5_STALLCURRENT   1500
    #define E5_MAX_VOLTAGE     127
    #define E5_CHAIN_POS        -1
    #define E5_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(E6)
    #define E6_MICROSTEPS      128
    #define E6_OVERCURRENT    2000
    #define E6_STALLCURRENT   1500
    #define E6_MAX_VOLTAGE     127
    #define E6_CHAIN_POS        -1
    #define E6_SLEW_RATE         1
  #endif

  #if AXIS_IS_L64XX(E7)
    #define E7_MICROSTEPS      128
    #define E7_OVERCURRENT    2000
    #define E7_STALLCURRENT   1500
    #define E7_MAX_VOLTAGE     127
    #define E7_CHAIN_POS        -1
    #define E7_SLEW_RATE         1
  #endif

  /**
   * Surveillez les pilotes L6470 pour les conditions d'erreur telles que surchauffe et surintensité.
   * En cas de surchauffe, Marlin peut modifer la valeur jusqu'à ce que la condition d'erreur disparaisse.
   * D'autres conditions détectées peuvent être utilisées pour arrêter l'impression en cours.
   * Gcodes pertinents:
   * M906 - I1/2/3/4/5  Réglez ou obtenez le niveau d'entraînement du moteur à l'aide des codes d'axe X, Y, Z, E. Indiquez des valeurs si aucun code d'axe n'est indiqué.
   *         I not present or I0 or I1 - X, Y, Z or E0
   *         I2 - X2, Y2, Z2 or E1
   *         I3 - Z3 or E3
   *         I4 - Z4 or E4
   *         I5 - E5
   * M916 - Augmentez le courant jusqu'à obtenir un avertissement thermique
   * M917 - Trouver les seuils de courant minimum
   * M918 - Augmentez la vitesse jusqu'à max ou erreur
   * M122 S0/1 - Lecture des paramètres du pilote
   */
  //#define MONITOR_L6470_DRIVER_STATUS

  #if ENABLED(MONITOR_L6470_DRIVER_STATUS)
    #define KVAL_HOLD_STEP_DOWN     1
    //#define L6470_STOP_ON_ERROR
  #endif

#endif // HAS_L64XX

// @section i2cbus

//
// ID maître I2C pour LCD LPC176x et contrôle de courant numérique 
// Ne s'applique pas aux autres périphériques basés sur la bibliothèque Wire.
//
//#define I2C_MASTER_ID  1  // Définissez une valeur de 0 à 2

/**
 * TWI/I2C BUS
 *
 * Cette fonctionnalité est une fonctionnalité EXPÉRIMENTALE et ne doit donc pas être utilisée sur 
 * des machines de production. L'activer vous permettra d'envoyer et de recevoir des données I2C 
 * à partir de périphériques esclaves sur le bus.
 *
 * ; Exemple #1
 * ; Cette macro envoie la chaîne "Marlin" au périphérique esclave avec l'adresse 0x63 (99)
 * ; Il utilise plusieurs commandes M260 avec un argument B <base 10>
 * M260 A99  ; Adresse esclave cible
 * M260 B77  ; M
 * M260 B97  ; a
 * M260 B114 ; r
 * M260 B108 ; l
 * M260 B105 ; i
 * M260 B110 ; n
 * M260 S1   ; Envoyer le tampon (buffer) actuel
 *
 * ; Exemple #2
 * ; Demander 6 octets au périphérique esclave avec l'adresse 0x63 (99)
 * M261 A99 B5
 *
 * ; Exemple #3
 * ; Exemple de sortie série d'une demande M261
 * echo:i2c-reply: from:99 bytes:5 data:hello
 */

//#define EXPERIMENTAL_I2CBUS
#if ENABLED(EXPERIMENTAL_I2CBUS)
  #define I2C_SLAVE_ADDRESS  0  // Définissez une valeur de 8 à 127 pour agir comme un esclave
#endif

// @section extras

/**
 * Gcode photo
 * Ajoutez le Gcode M240 pour prendre une photo.
 * La photo peut être déclenchée par une épingle numérique (pin) ou un mouvement physique.
 */
//#define PHOTO_GCODE
#if ENABLED(PHOTO_GCODE)
  // Une position pour se déplacer vers (et élever Z) avant de prendre la photo
  //#define PHOTO_POSITION { X_MAX_POS - 5, Y_MAX_POS, 0 }  // { xpos, ypos, zraise } (M240 X Y Z)
  //#define PHOTO_DELAY_MS   100                            // (ms) Durée de pause avant de reculer (M240 P)
  //#define PHOTO_RETRACT_MM   6.5                          // (mm) E rétracter / extruder pour le déplacement photo (M240 R S)

  // Déclencheur pour appareil photo numérique Canon RC-1 ou homebrew
  // Données de: http://www.doc-diy.net/photo/rc-1_hacked/
  //#define PHOTOGRAPH_PIN 23

  // Kit de développement Canon Hack
  // http://captain-slow.dk/2014/03/09/3d-printing-timelapses/
  //#define CHDK_PIN        4

  // Deuxième mouvement optionnel avec temporisation pour déclencher l'obturateur de l'appareil photo
  //#define PHOTO_SWITCH_POSITION { X_MAX_POS, Y_MAX_POS }  // { xpos, ypos } (M240 I J)

  // Durée pour maintenir le commutateur ou maintenir CHDK_PIN high
  //#define PHOTO_SWITCH_MS   50 // (ms) (M240 D)

  /**
   * PHOTO_PULSES_US peut nécessiter un ajustement selon le modèle de carte et de caméra. 
   * La broche doit fonctionner à 48,4 kHz.
   * Assurez-vous d'utiliser un PHOTOGRAPH_PIN qui peut changer d'état assez rapidement.
   * (par exemple, la broche du capteur de température MKS SBase était trop lente, donc utilisé P1.23 sur J8.)
   *
   *  Exemple de données d'impulsion pour Nikon: https://bit.ly/2FKD0Aq
   *                     IR Wiring: https://git.io/JvJf7
   */
  //#define PHOTO_PULSES_US { 2000, 27850, 400, 1580, 400, 3580, 400 }  // (µs) Durées pour chaque oscillation de 48,4 kHz
  #ifdef PHOTO_PULSES_US
    #define PHOTO_PULSE_DELAY_US 13 // (µs) Durée approximative de chaque impulsion HIGH et LOW dans l'oscillation
  #endif
#endif

/**
 * Fraiseuse et laser
 *
 * Ajoutez les commandes M3, M4 et M5 pour allumer et éteindre la fraiseuse / laser et pour définir 
 * la vitesse de la fraiseuse, la direction de la fraiseuse et la puissance du laser.
 *
 * SuperPid est un contrôleur de vitesse de toupie / fraiseuse utilisé dans la communauté du fraisage CNC.
 * Marlin peut être utilisé pour allumer et éteindre la fraiseuse. Il peut également 
 * être utilisé pour régler la vitesse de rotation de 5 000 à 30 000 tr / min.
 *
 * Vous devrez sélectionner une broche pour la fonction ON / OFF et éventuellement choisir une broche 
 * PWM matérielle 0-5V pour le contrôle de la vitesse et une broche pour le sens de rotation.
 *
 * Voir http://marlinfw.org/docs/configuration/laser_spindle.html pour plus de détails sur la configuration.
 */
//#define SPINDLE_FEATURE
//#define LASER_FEATURE
#if EITHER(SPINDLE_FEATURE, LASER_FEATURE)
  #define SPINDLE_LASER_ACTIVE_HIGH     false  // Réglez sur "true" si la fonction on / off est active HIGH
  #define SPINDLE_LASER_PWM             true   // Réglez sur "true" si votre contrôleur prend en charge le réglage de la vitesse / puissance
  #define SPINDLE_LASER_PWM_INVERT      true   // Réglez sur "true" si la vitesse / puissance augmente lorsque vous voulez qu'elle ralentisse
  #define SPINDLE_LASER_POWERUP_DELAY   5000   // (ms) Délai pour permettre à la fraise / au laser d'atteindre la vitesse / la puissance
  #define SPINDLE_LASER_POWERDOWN_DELAY 5000   // (ms) Délai pour permettre à la fraise de s'arrêter

  #if ENABLED(SPINDLE_FEATURE)
    //#define SPINDLE_CHANGE_DIR               // Activer si votre contrôleur de broche peut changer la direction de la fraise
    #define SPINDLE_CHANGE_DIR_STOP            // Activer si la fraise doit s'arrêter avant de changer la direction de rotation
    #define SPINDLE_INVERT_DIR          false  // Réglez sur "true" si le sens de rotation est inversée

    /**
     *  Les commandes M3 et M4 utilisent l'équation suivante pour convertir le rapport cyclique PWM en vitesse / puissance
     *
     *  VITESSE / PUISSANCE = rapport cyclique PWM * SPEED_POWER_SLOPE + SPEED_POWER_INTERCEPT
     *    où le cycle d'utilisation PWM varie de 0 à 255
     *
     *  définissez les paramètres suivants pour votre contrôleur (TOUT DOIT ÊTRE RÉGLÉ)
     */
    #define SPEED_POWER_SLOPE    118.4
    #define SPEED_POWER_INTERCEPT  0
    #define SPEED_POWER_MIN     5000
    #define SPEED_POWER_MAX    30000    // Contrôleur de vitesse SuperPID 0 - 30 000 tr / min
  #else
    #define SPEED_POWER_SLOPE      0.3922
    #define SPEED_POWER_INTERCEPT  0
    #define SPEED_POWER_MIN       10
    #define SPEED_POWER_MAX      100    // 0-100%
  #endif
#endif

/**
 * Contrôle du refroidissement liquide
 *
 * Ajoutez les commandes M7, M8 et M9 pour activer et désactiver la pulverisation ou la circulation du liquide de refroidissement.
 *
 * Remarque: COOLANT_MIST_PIN et / ou COOLANT_FLOOD_PIN doivent également être définis.
 */
//#define COOLANT_CONTROL
#if ENABLED(COOLANT_CONTROL)
  #define COOLANT_MIST                // Activer si le liquide de refroidissement est pulvérisé
  #define COOLANT_FLOOD               // Activer si le liquide de refroidissement est présent
  #define COOLANT_MIST_INVERT  false  // Définissez "true" si la fonction marche / arrêt est inversée
  #define COOLANT_FLOOD_INVERT false  // Définissez "true" si la fonction marche / arrêt est inversée
#endif

/**
 * Capteur de diamètre de filament
 *
 * Mesure le diamètre du filament en temps réel et 
 * ajuste le débit pour compenser toute irrégularité.
 *
 * Permet également au diamètre de filament mesuré de 
 * définir la vitesse d'extrusion, de sorte que le trancheur 
 * n'a qu'à spécifier le volume.
 *
 * Un seul extrudeur est pris en charge pour le moment.
 *
 *  34 RAMPS_14    : Entrée analogique 5 sur le connecteur AUX2
 *  81 PRINTRBOARD : Entrée analogique 2 sur le connecteur Exp1 (version B, C, D, E)
 * 301 RAMBO       : Entrée analogique 3
 *
 * Remarque: peut nécessiter la définition de broches analogiques pour d'autres cartes.
 */
//#define FILAMENT_WIDTH_SENSOR

#if ENABLED(FILAMENT_WIDTH_SENSOR)
  #define FILAMENT_SENSOR_EXTRUDER_NUM 0    // Index de l'extrudeur équippé du capteur de filament. : [0,1,2,3,4]
  #define MEASUREMENT_DELAY_CM        14    // (cm) La distance entre le capteur de filament et le bloc de chauffe

  #define FILWIDTH_ERROR_MARGIN        1.0  // (mm) Si une mesure diffère trop de la largeur nominale, ignorez-la
  #define MAX_MEASUREMENT_DELAY       20    // (bytes) Taille du tampon pour les mesures enregistrées (1 octet par cm). Doit être plus grand que MEASUREMENT_DELAY_CM.

  #define DEFAULT_MEASURED_FILAMENT_DIA DEFAULT_NOMINAL_FILAMENT_DIA // Régler le diamètre nominal du filament

  // Afficher la largeur du filament sur la ligne d'état LCD. Les messages d'état expireront après 5 secondes.
  //#define FILAMENT_LCD_DISPLAY
#endif

/**
 * Systèmes de coordonnées CNC
 *
 * Active les commandes G53 et G54-G59.3 pour sélectionner les systèmes de coordonnées et 
 * G92.1 pour réinitialiser l'espace de travail à l'espace machine natif.
 */
//#define CNC_COORDINATE_SYSTEMS

/**
 * Rapport automatique des températures avec M155 S <secondes>
 */
#define AUTO_REPORT_TEMPERATURES

/**
 * Inclure des capacités dans la sortie M115
 */
#define EXTENDED_CAPABILITIES_REPORT

/**
 * Vérification de l'imprimante attendue. 
 * Ajoutez le code G M16 pour comparer une chaîne à MACHINE_NAME.
 * M16 avec une chaîne non correspondante entraîne l'arrêt de l'imprimante.
 */
//#define EXPECTED_PRINTER_CHECK

/**
 * Désactiver toutes les options d'extrusion volumétrique
 */
//#define NO_VOLUMETRICS

#if DISABLED(NO_VOLUMETRICS)
  /**
   * État par défaut de l'extrusion volumétrique
   * Activez cette option pour faire de l'extrusion volumétrique la méthode par défaut, 
   * avec DEFAULT_NOMINAL_FILAMENT_DIA comme diamètre par défaut.
   *
   * M200 D0 pour désactiver, M200 Dn pour définir un nouveau diamètre.
   */
  //#define VOLUMETRIC_DEFAULT_ON
#endif

/**
 * Enable this option for a leaner build of Marlin that removes all
 * Activez cette option pour une version allégée de Marlin qui supprime tous les décalages d'espace de travail, simplifiant les transformations de coordonnées, le nivellement, etc.
 *
 *  - M206 et M428 sont désactivés.
 *
 * M206: Exemple: M206 X10.0 Y10.0 Z-0.4. 
 *       Les valeurs spécifiées sont ajoutées à la position de fin de course lorsque les axes sont référencés.
 *       La même chose peut être obtenue avec un G92 juste après le référencement (G28, G161). 
 *       Avec le firmware Marlin, cette valeur peut être enregistrée dans l'EEPROM à l'aide de la commande M500. 
 *       Une commande similaire est G10, l'alignement de ces deux est sujet à discussion. 
 *       Avec Marlin 1.0.0 RC2, une valeur négative pour z soulève (!) Votre tête d'impression. 
 *
 * M428: Utilisez M428 pour définir un décalage persistant vers la position d'origine native et coordonner l'espace 
 *       en affectant la position actuelle comme position d'origine native. Voir l'exemple ci-dessous.
 *       - La position actuelle doit être à moins de 2 cm de 0 ou d'un arrêt.
 *       - La position actuelle est définie sur la position d'origine native.
 *       - Tout décalage de position précédent par rapport à G92 est effacé.
 *       - Le décalage d'origine est persistant - ajouté à la position actuelle après modification.
 *       - Certaines utilisations incluent un réglage fin de la position Z (sans butées mobiles) et le 
 *         déplacement de l'espace de coordonnées pour imprimer sur une autre partie du lit.
 *
 *  - G92 reviendra à son comportement à partir de Marlin 1.0.
 */
//#define NO_WORKSPACE_OFFSETS

/**
 * Définissez le nombre d'espaces de police proportionnels requis pour remplir un espace de caractères typique.
 * Cela peut aider à mieux aligner la sortie de commandes comme la sortie de maillage `G29 O`.
 *
 * Pour les clients qui utilisent une police à largeur fixe (comme OctoPrint), laissez cet ensemble à 1.0.
 * Sinon, ajustez en fonction de votre client et de votre police.
 */
#define PROPORTIONAL_FONT_RATIO 1.0

/**
 * Dépensez 28 octets de SRAM pour optimiser l'analyseur GCode
 */
#define FASTER_GCODE_PARSER

#if ENABLED(FASTER_GCODE_PARSER)
  //#define GCODE_QUOTED_STRINGS  // Prise en charge des paramètres de chaîne entre guillemets
#endif

//#define GCODE_CASE_INSENSITIVE  // Acceptez le Gcode envoyé au firmware en minuscules

/**
 * Options de code G CNC
 * Prend en charge les dialectes de Gcode de style CNC utilisés par les découpeurs laser, les cames de machine à dessiner, etc.
 * Notez que les vitesses d'avance G0 doivent être utilisées avec soin pour l'impression 3D (si elles sont utilisées).
 * Des vitesses d'avance élevées peuvent provoquer des grincements et nuire à la qualité d'impression.
 */
//#define PAREN_COMMENTS      // Prise en charge des commentaires séparés par des parenthèses
//#define GCODE_MOTION_MODES  // Remember the motion mode (G0 G1 G2 G3 G5 G38.X) and apply for X Y Z E F, etc.

// Activer et définir une vitesse d'avance (par défaut) pour tous les mouvements G0
//#define G0_FEEDRATE 3000 // (mm/m)
#ifdef G0_FEEDRATE
  //#define VARIABLE_G0_FEEDRATE // La vitesse d'avance G0 est définie par F en mode mouvement G0
#endif

/**
 * Commandes de démarrage
 *
 * Exécutez certaines commandes de code G immédiatement après la mise sous tension.
 */
//#define STARTUP_COMMANDS "M17 Z"

/**
 * G-code Macros
 *
 * Ajoutez des codes G M810-M819 pour définir et exécuter des macros de code G.
 * Les macros ne sont pas enregistrées dans l'EEPROM.
 */
//#define GCODE_MACROS
#if ENABLED(GCODE_MACROS)
  #define GCODE_MACROS_SLOTS       5  // un maximum de 10 peuvent être utilisés
  #define GCODE_MACROS_SLOT_SIZE  50  // Longueur maximale d'une seule macro
#endif

/**
 * Éléments de menu définis par l'utilisateur qui exécutent un GCode personnalisé
 */
//#define CUSTOM_USER_MENUS
#if ENABLED(CUSTOM_USER_MENUS)
  //#define CUSTOM_USER_MENU_TITLE "Commandes personnalisées"
  #define USER_SCRIPT_DONE "M117 User Script Done"
  #define USER_SCRIPT_AUDIBLE_FEEDBACK
  //#define USER_SCRIPT_RETURN  // Revenir à l'écran d'état après un script

  #define USER_DESC_1 "Home & UBL Info"
  #define USER_GCODE_1 "G28\nG29 W"

  #define USER_DESC_2 "Preheat for " PREHEAT_1_LABEL
  #define USER_GCODE_2 "M140 S" STRINGIFY(PREHEAT_1_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_1_TEMP_HOTEND)

  #define USER_DESC_3 "Preheat for " PREHEAT_2_LABEL
  #define USER_GCODE_3 "M140 S" STRINGIFY(PREHEAT_2_TEMP_BED) "\nM104 S" STRINGIFY(PREHEAT_2_TEMP_HOTEND)

  #define USER_DESC_4 "Heat Bed/Home/Level"
  #define USER_GCODE_4 "M140 S" STRINGIFY(PREHEAT_2_TEMP_BED) "\nG28\nG29"

  #define USER_DESC_5 "Home & Info"
  #define USER_GCODE_5 "G28\nM503"
#endif

/**
 * Commandes d'action de l'hôte
 *
 * Définissez les commandes d'action du streamer hôte conformément à la norme.
 *
 * Voir https://reprap.org/wiki/G-code#Action_commands
 * Commandes courantes ........ mise hors tension, pause, pause, reprise, reprise, annulation
 * G29_RETRY_AND_RECOVER .. probe_rewipe, probe_failed
 *
 * Certaines fonctionnalités ajoutent des codes motif pour étendre ces commandes.
 *
 * La prise en charge des invites de l'hôte permet à Marlin d'utiliser l'hôte pour les invites de l'utilisateur 
 * afin que le manque de filament et d'autres processus puissent être gérés depuis l'hôte.
 */
//#define HOST_ACTION_COMMANDS
#if ENABLED(HOST_ACTION_COMMANDS)
  //#define HOST_PROMPT_SUPPORT
#endif

/**
 * Annuler des objets
 *
 * Implémenter M486 pour permettre à Marlin de sauter des objets
 */
//#define CANCEL_OBJECTS

/**
 * Codeurs de position I2C pour le contrôle en boucle fermée.
 * Développé par Chris Barr chez Aus3D.
 *
 * Wiki: http://wiki.aus3d.com.au/Magnetic_Encoder
 * Github: https://github.com/Aus3D/MagneticEncoder
 *
 * Fournisseur: http://aus3d.com.au/magnetic-encoder-module
 * Fournisseur alternatif: http://reliabuild3d.com/
 *
 * Les encodeurs Reliabuild ont été modifiés pour améliorer la fiabilité.
 */

//#define I2C_POSITION_ENCODERS
#if ENABLED(I2C_POSITION_ENCODERS)

  #define I2CPE_ENCODER_CNT         1                       // Le nombre d'encodeurs installés; max de 5 
                                                            // encodeurs pris en charge actuellement.

  #define I2CPE_ENC_1_ADDR          I2CPE_PRESET_ADDR_X     // Adresse I2C de l'encodeur. 30-200.
  #define I2CPE_ENC_1_AXIS          X_AXIS                  // Axe sur lequel le module d'encodeur est installé. <X | Y | Z | E> _AXIS.
  #define I2CPE_ENC_1_TYPE          I2CPE_ENC_TYPE_LINEAR   // Type d'encodeur: I2CPE_ENC_TYPE_LINEAR -ou- 
                                                            // I2CPE_ENC_TYPE_ROTARY.
  #define I2CPE_ENC_1_TICKS_UNIT    2048                    // 1024 pour bandes magnétiques à pôles de 2 mm; 2048 pour mâts 1 mm. 
                                                            // Pour les codeurs linéaires, il s'agit de ticks / mm, 
                                                            // pour les codeurs rotatifs, il s'agit de ticks / révolution.
  //#define I2CPE_ENC_1_TICKS_REV     (16 * 200)            // Uniquement nécessaire pour les encodeurs rotatifs; nombre de pas 
                                                            // par tour complet (pas moteur / tour * micropas)
  //#define I2CPE_ENC_1_INVERT                              // Inversez le sens de déplacement de l'axe.
  #define I2CPE_ENC_1_EC_METHOD     I2CPE_ECM_MICROSTEP     // Type de correction d'erreur.
  #define I2CPE_ENC_1_EC_THRESH     0.10                    // Taille de seuil d'erreur (en mm) au-dessus de laquelle 
                                                            // l'imprimante tentera de corriger l'erreur; les erreurs 
                                                            // plus petites sont ignorées pour minimiser les effets 
                                                            // du bruit de mesure / latence (filtre).

  #define I2CPE_ENC_2_ADDR          I2CPE_PRESET_ADDR_Y     // Comme ci-dessus, mais pour l'encodeur 2.
  #define I2CPE_ENC_2_AXIS          Y_AXIS
  #define I2CPE_ENC_2_TYPE          I2CPE_ENC_TYPE_LINEAR
  #define I2CPE_ENC_2_TICKS_UNIT    2048
  //#define I2CPE_ENC_2_TICKS_REV   (16 * 200)
  //#define I2CPE_ENC_2_INVERT
  #define I2CPE_ENC_2_EC_METHOD     I2CPE_ECM_MICROSTEP
  #define I2CPE_ENC_2_EC_THRESH     0.10

  #define I2CPE_ENC_3_ADDR          I2CPE_PRESET_ADDR_Z     // Encodeur 3.  Ajoutez des options de configuration supplémentaires 
  #define I2CPE_ENC_3_AXIS          Z_AXIS                  // comme ci-dessus ou utilisez les valeurs par défaut ci-dessous.

  #define I2CPE_ENC_4_ADDR          I2CPE_PRESET_ADDR_E     // Encodeur 4.
  #define I2CPE_ENC_4_AXIS          E_AXIS

  #define I2CPE_ENC_5_ADDR          34                      // Encodeur 5.
  #define I2CPE_ENC_5_AXIS          E_AXIS

  // Paramètres par défaut pour les encodeurs qui sont activés, mais sans les paramètres configurés ci-dessus.
  #define I2CPE_DEF_TYPE            I2CPE_ENC_TYPE_LINEAR
  #define I2CPE_DEF_ENC_TICKS_UNIT  2048
  #define I2CPE_DEF_TICKS_REV       (16 * 200)
  #define I2CPE_DEF_EC_METHOD       I2CPE_ECM_NONE
  #define I2CPE_DEF_EC_THRESH       0.1

  //#define I2CPE_ERR_THRESH_ABORT  100.0                   // Taille du seuil d'erreur (en mm) sur un axe donné, 
                                                            // après quoi l'imprimante abandonnera. Commentez pour 
                                                            // désactiver le comportement d'abandon.

  #define I2CPE_TIME_TRUSTED        10000                   // Après un défaut du codeur, il ne doit pas y avoir d'autre 
                                                            // défaut pendant ce laps de temps (en ms) avant que le codeur 
                                                            // soit à nouveau approuvé.

  /**
   * La position est vérifiée chaque fois qu'une nouvelle commande est exécutée à partir du tampon, mais lors de longs déplacements, 
   * ce paramètre détermine le temps de mise à jour minimum entre les vérifications. Une valeur de 100 fonctionne bien avec une moyenne 
   * glissante d'erreur lors d'une tentative de correction uniquement pour les sauts et non pour les vibrations.
   */
  #define I2CPE_MIN_UPD_TIME_MS     4                       // (ms) Temps minimum entre les vérifications de l'encodeur.

  // Utilisez une moyenne mobile pour identifier les erreurs persistantes qui indiquent des sauts, par opposition aux vibrations et au bruit.
  #define I2CPE_ERR_ROLLING_AVERAGE

#endif // I2C_POSITION_ENCODERS

/**
 * Joystick (s) analogique (s)
 */
//#define JOYSTICK
#if ENABLED(JOYSTICK)
  #define JOY_X_PIN    5  // RAMPS: broche A5 suggérée sur AUX2
  #define JOY_Y_PIN   10  // RAMPS: broche A10 suggérée sur AUX2
  #define JOY_Z_PIN   12  // RAMPS: broche A12 suggérée sur AUX2
  #define JOY_EN_PIN  44  // RAMPS: broche D44 suggérée sur AUX2

  //#define INVERT_JOY_X  // Activer si la direction X est inversée
  //#define INVERT_JOY_Y  // Activer si la direction Y est inversée
  //#define INVERT_JOY_Z  // Activer si la direction Z est inversée

  // Use M119 with JOYSTICK_DEBUG to find reasonable values after connecting:
  #define JOY_X_LIMITS { 5600, 8190-100, 8190+100, 10800 } // min, début de la zone morte, fin de la zone morte, max
  #define JOY_Y_LIMITS { 5600, 8250-100, 8250+100, 11000 }
  #define JOY_Z_LIMITS { 4800, 8080-100, 8080+100, 11550 }
#endif

/**
 * MAX7219 Debug Matrix
 *
 * Ajoutez la prise en charge d'une matrice LED 8x8 à faible coût basée sur la puce Max7219 comme affichage d'état en temps réel.
 * Nécessite 3 fils de signal. Certaines options de débogage utiles sont incluses pour démontrer son utilisation.
 */
//#define MAX7219_DEBUG
#if ENABLED(MAX7219_DEBUG)
  #define MAX7219_CLK_PIN   64
  #define MAX7219_DIN_PIN   57
  #define MAX7219_LOAD_PIN  44

  //#define MAX7219_GCODE          // Ajoutez le code G M7219 pour contrôler la matrice LED
  #define MAX7219_INIT_TEST    2   // Faites un motif de test à l'initialisation (réglé sur 2 pour la spirale)
  #define MAX7219_NUMBER_UNITS 1   // Nombre d'unités Max7219 en chaîne.
  #define MAX7219_ROTATE       0   // Faire pivoter l'affichage dans le sens des aiguilles d'une montre (en multiples de +/- 90 °) 
                                   // connecteur à: droite = 0 bas = -90 haut = 90 gauche = 180
  //#define MAX7219_REVERSE_ORDER  // Les unités matricielles LED individuelles peuvent être dans l'ordre inverse
  //#define MAX7219_SIDE_BY_SIDE   // Les cartes Big Chip + Matrix peuvent être enchaînées côte à côte

  /**
   * Exemples de fonctionnalités de débogage
   * Si vous ajoutez plus d'affichages de débogage, faites attention à éviter les conflits!
   */
  #define MAX7219_DEBUG_PRINTER_ALIVE    // LED clignotante de matrice 8x8 pour montrer que le firmware fonctionne
  #define MAX7219_DEBUG_PLANNER_HEAD  3  // Afficher la position de la tête de file d'attente du planificateur sur cette ligne et sur la ligne de matrice LED suivante
  #define MAX7219_DEBUG_PLANNER_TAIL  5  // Afficher la position de queue de la file d'attente du planificateur sur cette ligne et la ligne de matrice LED suivante

  #define MAX7219_DEBUG_PLANNER_QUEUE 0  // Afficher la taille actuelle de la file d'attente du planificateur sur cette ligne et sur la ligne 
                                         // de matrice LED suivante Si vous rencontrez des bégaiements, des redémarrages, etc. cette option peut révéler 
                                         // comment les modifications apportées à la configuration affectent l'imprimante en temps réel.
#endif

/**
 * Prise en charge de NanoDLP Sync
 *
 * Ajoutez la prise en charge des mouvements Z synchronisés lors de l'utilisation avec NanoDLP. Les déplacements des axes G0 / G1 
 * produiront la chaîne "Z_move_comp" pour permettre la synchronisation avec l'exposition du projecteur DLP. Cette modification 
 * permettra d'utiliser [[WaitForDoneMessage]] au lieu de remplir votre gcode avec les commandes M400
 */
//#define NANODLP_Z_SYNC
#if ENABLED(NANODLP_Z_SYNC)
  //#define NANODLP_ALL_AXIS  // Active la sortie "Z_move_comp" sur n'importe quel déplacement d'axe.
                              // Le comportement par défaut est limité à l'axe Z uniquement.
#endif

/**
 * Prise en charge WiFi (Espressif ESP32 WiFi)
 */
//#define WIFISUPPORT         // Gestion de WiFi intégré Marlin
//#define ESP3D_WIFISUPPORT   // Gestion WiFi de la bibliothèque ESP3D (https://github.com/luc-github/ESP3DLib)

#if EITHER(WIFISUPPORT, ESP3D_WIFISUPPORT)
  //#define WEBSUPPORT          // Démarrez un serveur Web (qui peut inclure la découverte automatique)
  //#define OTASUPPORT          // Prise en charge des mises à jour du micrologiciel en direct
  //#define WIFI_CUSTOM_COMMAND // Accepter les commandes de configuration des fonctionnalités (par exemple, WiFi ESP3D) de l'hôte

  /**
   * Pour définir un SSID / mot de passe WiFi par défaut, créez un fichier appelé Configuration_Secure.h 
   * avec les définitions suivantes, personnalisées pour votre réseau. Ce fichier spécifique est exclu via 
   * .gitignore pour l'empêcher de fuir accidentellement vers le public.
   *
   *   #define WIFI_SSID "WiFi SSID"
   *   #define WIFI_PWD  "WiFi Password"
   */
  //#include "Configuration_Secure.h" // Fichier externe avec WiFi SSID / mot de passe
#endif

/**
 * Unité multi-matériaux Prusa v2
 * Activer dans Configuration.h
 */
#if ENABLED(PRUSA_MMU2)

  // Port série utilisé pour la communication avec MMU2.
  // Pour AVR, activez le port UART utilisé pour la MMU. (par exemple, internalSerial)
  // Pour les cartes 32 bits, vérifiez votre HAL pour les ports série disponibles. (par exemple, Serial2)
  #define INTERNAL_SERIAL_PORT 2
  #define MMU2_SERIAL internalSerial

  // Broche pour la réinitialisation du MMU.
  //#define MMU2_RST_PIN 23

  // Activer si le MMU2 a des moteurs pas à pas 12V (MMU2 Firmware 1.0.2 et plus)
  //#define MMU2_MODE_12V

  // Code G à exécuter lorsque la sonde F.Ii.N.D.A du MMU2 détecte la fin du filament
  #define MMU2_FILAMENT_RUNOUT_SCRIPT "M600"

  // Ajouter un menu MMU2 sur le LCD
  //#define MMU2_MENUS
  #if ENABLED(MMU2_MENUS)
    // Paramètres de chargement / déchargement du filament à partir du menu LCD.
    // Pour les extrudeurs de style Prusa MK3. A personnaliser suivant votre matériel.
    #define MMU2_FILAMENTCHANGE_EJECT_FEED 80.0
    #define MMU2_LOAD_TO_NOZZLE_SEQUENCE \
      {  7.2,  562 }, \
      { 14.4,  871 }, \
      { 36.0, 1393 }, \
      { 14.4,  871 }, \
      { 50.0,  198 }

    #define MMU2_RAMMING_SEQUENCE \
      {   1.0, 1000 }, \
      {   1.0, 1500 }, \
      {   2.0, 2000 }, \
      {   1.5, 3000 }, \
      {   2.5, 4000 }, \
      { -15.0, 5000 }, \
      { -14.0, 1200 }, \
      {  -6.0,  600 }, \
      {  10.0,  700 }, \
      { -10.0,  400 }, \
      { -50.0, 2000 }

  #endif

  //#define MMU2_DEBUG  // Écrire les informations de débogage sur la sortie série

#endif // PRUSA_MMU2

/**
 * Paramètres avancés du compteur d'impression
 */
#if ENABLED(PRINTCOUNTER)
  #define SERVICE_WARNING_BUZZES  3
  // Activate up to 3 service interval watchdogs
  //#define SERVICE_NAME_1      "Service S"
  //#define SERVICE_INTERVAL_1  100 // print hours
  //#define SERVICE_NAME_2      "Service L"
  //#define SERVICE_INTERVAL_2  200 // print hours
  //#define SERVICE_NAME_3      "Service 3"
  //#define SERVICE_INTERVAL_3    1 // print hours
#endif

// @section develop

//
// M100 Observateur de mémoire pour déboguer l'utilisation de la mémoire
//
//#define M100_FREE_MEMORY_WATCHER

// 
// M43 - état des broches (pinà
//
//#define PINS_DEBUGGING

// Activer le mode dev Marlin qui ajoute des commandes spéciales
//#define MARLIN_DEV_MODE
