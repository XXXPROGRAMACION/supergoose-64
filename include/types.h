/**
 * @brief It defines common types
 * @file types.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H


#define SAFE_MODE 0                 /*!< Safe mode, to avoid possibly leaks of memmory: (1) ON or (0) OFF */

#define MAX_DIA_C 85                /*!< Maximum columns of the text dialogue */
#define MAX_DIA_R 8                 /*!< Maximum rows of the text dialogue */

#define MAX_TDESC_C 85              /*!< Maximum columns of the text descriptions */
#define MAX_TDESC_R 3               /*!< Maximum rows of the text descriptions */

#define MAX_GDESC_C 21              /*!< Maximum columns of the graphic description field */
#define MAX_GDESC_R 10              /*!< Maximum rows of the graphic description field */

#define MAX_NAME 128                /*!< Maximum characters of a link name */
#define WORD_SIZE 1000              /*!< Maximum size of some of the names (players, objects and else)*/

#define NO_ID -1                    /*!< Default Id used when there is no Id or something works as it shouldn't */
#define NOT_FOUND -1                /*!< Used when a set doesnt found the given Id position */

#define SET_MAX_IDS 10              /*!< Maximum number of Ids a set can store */
#define MAX_SPACES 100              /*!< Maximum number of spaces a game is prepared to store */
#define MAX_PLAYERS 5               /*!< Maximum number of players a game is prepared to store */
#define MAX_OBJECTS 20              /*!< Maximum number of objects a game is prepared to store */
#define MAX_DIES 1                  /*!< Maximum number of dies a game is prepared to store */
#define MAX_LINKS 50                /*!< Maximum number of links a game is prepared to store */
#define MAX_TAGS 10                 /*!< Maximun number of tags an object can have */

#define ID_RANGE 10000               /*!< Used to define the maximum amount of elements from each type we can manage */
#define SPACE_BASE_ID 00000          /*!< Marks where the Spaces Ids start */
#define PLAYER_BASE_ID 10000         /*!< Marks where the Players Ids start */
#define OBJECT_BASE_ID 20000         /*!< Marks where the Objects Ids start */
#define DIE_BASE_ID 30000            /*!< Marks where the Dies Ids start */
#define LINK_BASE_ID 40000           /*!< Marks where the Links Ids start */

#define OBJECT_BASE_TAGS 0           /*!< The number of tags that an object has by default */
#define SPACE_BASE_TAGS 0            /*!< The number of tags that an object has by default */

#define HALL_ROOM_ID 13              /*!< The id of the hall */
#define FAILING_SPACE_ID 119         /*!< The id of the space that has a failing light */
#define TRANS_ROOM_ID 1229           /*!< The id of the transmutation room */
#define TRANS_CORE_ID 8              /*!< The id of the transmutation core */
#define POWER_CORE_ID 40             /*!< The id of the power core */
#define FUSE_ID 22                   /*!< The id of the fuses */
#define GEARS_ID 9                   /*!< The id of the gears */

/**
 * @brief Id (to store Ids of objects, players, etc)
 */
typedef long Id;

/**
 * @brief Boolean (to store boolean values that are or not)
 */
typedef enum {
    FALSE,          /*!< If the condition is not fullfilled */
    TRUE            /*!< If the condition is correct and real */
} BOOL;

/**
 * @brief Status (to store all the executions, if correct or not)
 */
typedef enum {
    ERROR,          /*!< If something went wrong */
    OK,             /*!< If all worked correctly */
    DARK,           /*!< If the space is not illuminated */
    FAR,            /*!< If the object is not in the same room */
    UNMOVABLE,      /*!< If the object is not movable */
    CLOSED_LINK     /*!< If the link is closed */
} STATUS;

/**
 * @brief Command enumeration (to be used on command.c
 */
typedef enum {
    NO_CMD = -1,    /*!< No command */
    UNKNOWN,        /*!< Unknown command (beginning)*/
    EXIT,           /*!< Exit game */
    MOVE,           /*!< Move to a direction */
    FOLLOWING,      /*!< Following space (old)*/
    LEFT,           /*!< Left space (old) */
    PREVIOUS,       /*!< Previous space (old)*/
    RIGHT,          /*!< Right space (old)*/
    UP,             /*!< Up space (old)*/
    DOWN,           /*!< Down space (old)*/
    GRASP,          /*!< Grasp an object */
    DROP,           /*!< Drop an object */
    THROW,          /*!< Roll the die */
    CHECK,          /*!< Check an object or a space */
    OPEN_L,         /*!< Open a link */
    TURN_ON,        /*!< Turn on an object */
    TURN_OFF,       /*!< Turn off an object */
    LOAD,           /*!< Load a game from a file */
    SAVE,           /*!< Save the current game to a file */
    PROMODE         /*!< Enter proMode */
} T_Command;
/**
 * @brief Direction (to be used when moving through the board)
 */
typedef enum {
    NO_DIR = -1,    /*!< If something went wrong */
    NORTH,          /*!< When going north */
    WEST,           /*!< When going east */
    SOUTH,          /*!< When going south */
    EAST,           /*!< When going east */
    ABOVE,          /*!< When going above */
    BELOW           /*!< When going below */
} DIRECTION;

/**
 * @brief LINK_STATUS enumeration (to be used on links)
 */
typedef enum {
    OPEN = 0,       /*!< Open link */
    CLOSED = 1      /*!< Closed link */
} LINK_STATUS;

/**
 * @brief COLOR enumeration (to be used when painting the graphic engine)
 */
typedef enum {
    BLACK,          /*!< BLACK COLOR */
    RED,            /*!< RED COLOR */
    GREEN,          /*!< GREEN COLOR */
    YELLOW,         /*!< YELLOW COLOR */
    BLUE,           /*!< BLUE COLOR */
    PURPLE,         /*!< PURPLE COLOR */
    CYAN,           /*!< CYAN COLOR */
    WHITE           /*!< WHITE COLOR */
} COLOR;

/**
 * @brief TAG enumeration (to be used when asigning propierties to objects or spaces)
 */
typedef enum {
	NO_TAG = 0,      /*!< Tag not specified */
	MOVABLE,		 /*!< The object can be moved */
	MOVED,			 /*!< The object has been moved */
	HIDDEN,			 /*!< The object is hidden */
	CAN_GLOW,		 /*!< The object is able to glow */
	GLOWING,	 	 /*!< The object is glowing */
	IS_KEY,			 /*!< The object is a key */
    IS_CROWBAR,      /*!< The object is a crowbar */
    IS_BASE_ID_CARD, /*!< The object is a base ID card */
    IS_FULL_ID_CARD, /*!< The object is a full ID card */
    IS_FUSE_KEY,     /*!< The object is a key for the fuse room */
    IS_TRANS_CORE_KEY,/*!< The object is a key for the trans core room */
    ILLUMINATED,     /*!< The space is a illuminated */
    FINAL_ROOM       /*!< The space is the final room */
} TAG;

/**
 * @brief RULES_STATUS enumeration 
 */
typedef enum {
    ERROR_RULES = 0,    /*!< Error when aplying the rules */
    SPACE_ILLUMINATED,  /*!< A space has been illuminated */
    END1,               /*!< The game ends with the first end */
    END2,               /*!< The game ends with the second end */
    END3,               /*!< The game ends with the third end */
    NO_RULE             /*!< The game applied no rule */
    
} RULES_STATUS;


#endif

/*DOXYGEN MAINPAGE*/
/**
 * @mainpage Main Page
 *
 * @section intro_sec SuperGoose_64
 *
 * Welcome to our incredible game! Please, have fun while playing it and remember to ask the creators if you have any doubts. Cheers :)
 *
 * @section install_sec The creators
 *
 * @subsection step1 Eric Morales:
 *
 * 	eric.morales@estudiante.uam.es
 *
 * @subsection step2 Victor Yrazusta:
 *
 * 	victor.yrazusta@estudiante.uam.es
 *
 * @subsection step3 Alejandro Pascual:
 *
 * 	alejandro.pascualp@estudiante.uam.es
 *
 * @subsection step4 Javier Lougedo:
 *
 * 	javier.lougedo@estudiante.uam.es
 *
 */