/** 
 * @brief It defines the space functions
 * @file space.c
 * @author Profesores PPROG
 * @version 3.0 
 * @date 
 * @updated 
 * @copyright GNU Public License
 */

#undef __STRICT_ANSI__

/*C libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <stdarg.h>
/*Own libraries*/
#include "../include/types.h"
#include "../include/set.h"
#include "../include/space.h"

/*We define the Space structure as the following:*/
struct _Space {
    Id id; /*An Id to distinguish the space from other spaces or things*/
    wchar_t name[WORD_SIZE]; /*A wchar_t used to name the space*/
    Id directions_ids[6]; /*An array of ids for the links*/
    Set *objects_ids; /*A set to store the objects it has*/
    wchar_t **graphic_description; /*A graphic description to use in the graphic engine*/
    wchar_t graphic_description_type[WORD_SIZE]; /*A string that lets us save the game storing the graphic description type*/
    wchar_t **basic_description; /*A field to store the basic information of the space.*/
    wchar_t **check_description; /*A field to store the information of the space and give it when asked playing.*/
    TAG space_tags[MAX_TAGS]; /*An array of tags that define the propierties of the space*/
    int num_tags; /*A number that indicates the number of tags*/
};

/*This function is used to allocate memory for a space and create it with a given Id*/
Space *space_create(Id id) {    
    Space *space = NULL;
    DIRECTION direction;
    int i;

    if (id == NO_ID) return NULL;

    space = (Space *) malloc(sizeof(Space));

    if (space == NULL) return NULL;

    space->objects_ids = set_create();

    if (space->objects_ids == NULL) {
        free(space);
        return NULL;
    }

    space->graphic_description = (wchar_t **) malloc(sizeof(wchar_t *)*MAX_GDESC_R);
    for (i = 0; i < MAX_GDESC_R; i++) {
        space->graphic_description[i] = (wchar_t *) malloc(sizeof(wchar_t)*MAX_GDESC_C);
        if (space->graphic_description[i] == NULL) {
            for (i = i - 1; i >= 0; i--) {
                free(space->graphic_description[i]);
            }
            free(space->graphic_description);
            set_destroy(space->objects_ids);
            free(space);
            return NULL;
        }
    }

    space->basic_description = (wchar_t **) malloc(sizeof(wchar_t*)*MAX_TDESC_R);
    for (i = 0; i < MAX_TDESC_R; i++) {
        space->basic_description[i] = (wchar_t *) malloc(sizeof(wchar_t)*MAX_TDESC_C);
        if (space->basic_description[i] == NULL) {
            for (i = i - 1; i >= 0; i--) {
                free(space->basic_description[i]);
            }
            for (i = 0; i < MAX_GDESC_R; i++) {
                free(space->graphic_description[i]);
            }
            free(space->graphic_description);
            free(space->basic_description);
            set_destroy(space->objects_ids);
            free(space);
            return NULL;
        }
    }

    space->check_description = (wchar_t **) malloc(sizeof(wchar_t*)*MAX_TDESC_R);
    for (i = 0; i < MAX_TDESC_R; i++) {
        space->check_description[i] = (wchar_t *) malloc(sizeof(wchar_t)*MAX_TDESC_C);
        if (space->check_description[i] == NULL) {
            for (i = i - 1; i >= 0; i--) {
                free(space->check_description[i]);
            }
            for (i = 0; i < MAX_TDESC_R; i++) {
                free(space->basic_description[i]);
            }
            for (i = 0; i < MAX_GDESC_R; i++) {
                free(space->graphic_description[i]);
            }
            free(space->graphic_description);
            free(space->check_description);
            set_destroy(space->objects_ids);
            free(space);
            return NULL;
        }
    }

    space->id = id;
    space->name[0] = '\0';

    for (direction = NORTH; direction <= BELOW; direction++) space->directions_ids[direction] = NO_ID;

    wcscpy(space->graphic_description[0], L"NO_GDES");
    wcscpy(space->graphic_description[1], L"NO_GDES");
    wcscpy(space->graphic_description[2], L"NO_GDES");

    wcscpy(space->basic_description[0], L"No basic description.");
    wcscpy(space->basic_description[1], L"No basic description.");
    wcscpy(space->basic_description[2], L"No basic description.");

    wcscpy(space->check_description[0], L"No check description.");
    wcscpy(space->check_description[1], L"No check description.");
    wcscpy(space->check_description[2], L"No check description.");

    space->num_tags = 0;

    for (i = 0; i < MAX_TAGS; i++) {
    	space->space_tags[i] = NO_TAG;
    }

    return space;
}

/*This function frees the allocated memory by a space*/
STATUS space_destroy(Space *space) {
    int i;

    if (space == NULL) return OK;

    if (space->objects_ids != NULL) set_destroy(space->objects_ids);

    if (space->graphic_description != NULL) {
        for (i = 0; i < MAX_GDESC_R; i++) {
            if (space->graphic_description[i] != NULL) free(space->graphic_description[i]);
        }
        free(space->graphic_description);
    }

    if (space->basic_description!= NULL) {
        for (i = 0; i < MAX_TDESC_R; i++) {
            if (space->basic_description[i] != NULL) free(space->basic_description[i]);
        }
        free(space->basic_description);
    }

    if (space->check_description != NULL) {
        for (i = 0; i < MAX_TDESC_R; i++) {
            if (space->check_description[i] != NULL) free(space->check_description[i]);
        }
        free(space->check_description);        
    }

    free(space);

    return OK;
}

/*This function sets the space name*/
STATUS space_set_name(Space *space, wchar_t *name) {

    if (space == NULL || name == NULL) return ERROR;

    if (wcscpy(space->name, name) == 0) return ERROR;

    return OK;
}

/*This function sets the northern Id of the space*/
STATUS space_set_direction(Space *space, DIRECTION direction, Id id) {

    if (space == NULL || id < LINK_BASE_ID || id >= LINK_BASE_ID + ID_RANGE) return ERROR;

    switch (direction) {
        case NORTH:
            space->directions_ids[0] = id;
            break;
        case WEST:
            space->directions_ids[1] = id;
            break;
        case SOUTH:
            space->directions_ids[2] = id;
            break;
        case EAST:
            space->directions_ids[3] = id;
            break;
        case ABOVE:
            space->directions_ids[4] = id;
            break;
        case BELOW:
            space->directions_ids[5] = id;
            break;
        default:
            return ERROR;
    }    

    return OK;
}

/*This function sets the graphic description of the space, to use it on the graphic engine*/
STATUS space_set_graphic_description(Space *space, wchar_t graphic_description[MAX_GDESC_R][MAX_GDESC_C]) {
    int i;

    if (space == NULL || graphic_description == NULL) return ERROR;

    for (i = 0; i < MAX_GDESC_R; i++) {
        wcscpy(space->graphic_description[i], graphic_description[i]);
    }

    return OK;
}


/*This function sets the basic description of the space, to use it on the graphic engine*/
STATUS space_set_basic_description(Space *space, wchar_t basic_description[MAX_TDESC_R][MAX_TDESC_C]) {
    int i;

    if (space == NULL || basic_description == NULL) return ERROR;

    for (i = 0; i < MAX_TDESC_R; i++) {
        wcscpy(space->basic_description[i], basic_description[i]);
    }

    return OK;
}

/*This function sets the graphic description type of the space to use it on the save*/
STATUS space_set_graphic_description_type(Space *space, wchar_t graphic_description_type[WORD_SIZE]) {

    if (space == NULL || graphic_description_type == NULL) return ERROR;

    wcscpy(space->graphic_description_type, graphic_description_type);

    return OK;
}

/*This function sets the check description of the space, to use it on the graphic engine*/
STATUS space_set_check_description(Space *space, wchar_t check_description[MAX_TDESC_R][MAX_TDESC_C]) {
    int i;

    if (space == NULL || check_description == NULL) return ERROR;

    for (i = 0; i < MAX_TDESC_R; i++) {
        wcscpy(space->check_description[i], check_description[i]);
    }

    return OK;
}

/*This function is used to add an object to the space set*/
STATUS space_add_object(Space *space, Id object_id) {

    if (space == NULL || object_id == NO_ID) return ERROR;

    return set_add(space->objects_ids, object_id);
}

/*This function is used to delete an object from the space set*/
STATUS space_del_object(Space *space, Id object_id) {

    if (space == NULL || object_id == NO_ID) return ERROR;

    return set_del(space->objects_ids, object_id);
}

/*This function returns the name of a space*/
const wchar_t *space_get_name(Space *space) {

    if (space == NULL) return NULL;

    return space->name;
}

/*This function is used to get the graphic description to use it in the graphic engine later*/
wchar_t **space_get_graphic_description(Space *space) {

    if (space == NULL) return NULL;

    return space->graphic_description;
}

/*This function is used to get the graphic description type to use it in the save*/
wchar_t *space_get_graphic_description_type(Space *space) {

    if (space == NULL) return NULL;

    return space->graphic_description_type;
}

/*This function gets the basic description of a space*/
wchar_t **space_get_basic_description(Space *space) {

    if (space == NULL) return NULL;

    return space->basic_description;
}

/*This function gets the check description of a space*/
wchar_t **space_get_check_description(Space *space) {

    if (space == NULL) return NULL;

    return space->check_description;
}

/*This function is used to get the id of a space*/
Id space_get_id(Space *space) {

    if (space == NULL) return NO_ID;

    return space->id;
}

/*This function is used to get the northern id of a space*/
Id space_get_direction(Space *space, DIRECTION direction) {

    if (space == NULL) return NO_ID;

    switch (direction) {
        case NORTH:
            return space->directions_ids[0];
            break;
        case WEST:
            return space->directions_ids[1];
            break;
        case SOUTH:
            return space->directions_ids[2];
            break;
        case EAST:
            return space->directions_ids[3];
            break;
        case ABOVE:
            return space->directions_ids[4];
            break;
        case BELOW:
            return space->directions_ids[5];
            break;
        default:
            return NO_ID;
    }    

    return OK;
}

/*This function is used to get an object from the spaces set*/
Id space_get_object_id(Space *space, int position) {

    if (space == NULL || position < 0) return NO_ID;

    return set_get_id(space->objects_ids, position);
}

/*This function returns the number of objects there are in the spaces set*/
int space_get_objects_number(Space *space) {

    if (space == NULL) return 0;

    return set_get_ids_number(space->objects_ids);
}

/*This function checks if the given object id is stored in the spaces set*/
BOOL space_check_object(Space *space, Id object_id) {

    if (space == NULL || object_id == NO_ID) return FALSE;

    if (set_get_id_position(space->objects_ids, object_id) == -1) {
        return FALSE;
    } else {
        return TRUE;
    }
}

/*This function returns if there are no objects in the space or not*/
BOOL space_is_empty(Space *space) {

    if (space == NULL) return TRUE;

    if (set_is_empty(space->objects_ids)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*This function returns if there is space or not to store another object*/
BOOL space_is_full(Space *space) {

    if (space == NULL) return TRUE;

    if (set_is_full(space->objects_ids)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*This function adds a variable number of tags to a space*/
STATUS space_add_tags(Space *space, int num_tags, ...) {
    TAG space_tags[MAX_TAGS];
    va_list space_tags_list;
    int i;

    if (space == NULL || num_tags <= 0 || space->num_tags+num_tags > MAX_TAGS) return ERROR;

    va_start(space_tags_list, num_tags);

    for (i = 0; i < num_tags; i++) {        
        space_tags[i] = va_arg(space_tags_list, TAG);
    }

    for (i = 0; i < num_tags; i++) {
    	if (space_check_tag(space, space_tags[i]) == FALSE) {
    		space->space_tags[space->num_tags] = space_tags[i];
    		space->num_tags++;
    	}
    }

    va_end(space_tags_list);

    return OK;
}

/*This function checks if a space has a determinated tag*/
BOOL space_check_tag(Space *space, TAG space_tag) {
    int i;

    if (space == NULL) return TRUE;

    for (i = 0; i < space->num_tags; i++) {
        if (space_tag == space->space_tags[i]) return TRUE;
    }

    return FALSE;
}

/*This function removes a variable number of tags from a space*/
STATUS space_remove_tags(Space *space, int num_tags, ...) {
	TAG space_tags[MAX_TAGS];
	va_list space_tags_list;
	int i, j, k;

	if (space == NULL || num_tags <= 0) return ERROR;

	va_start(space_tags_list, num_tags);

    for (i = 0; i < num_tags; i++) {        
        space_tags[i] = va_arg(space_tags_list, TAG);
    }

    for (i = 0; i < num_tags; i++) {
		for (j = 0; j < space->num_tags; j++) {
			if (space_tags[i] == space->space_tags[j]) {
				for (k = j; k < space->num_tags-1; k++) {
					space->space_tags[k] = space->space_tags[k+1];
				}				
				space->space_tags[k] = NO_TAG;
				space->num_tags--;
				return OK;
			}
		}
	}

	return ERROR;
}

/*This function returns the tags of a space*/
TAG *space_get_tags(Space *space) {
    
    if (space == NULL) return NULL;

    return space->space_tags;
}

/*This function returns the number of tags in a space*/
int space_get_tags_number(Space *space) {
    
    if (space == NULL) return 0;

    return space->num_tags;
}

STATUS space_print(FILE *f, Space *space) {
    TAG *space_tags = NULL;
    int num_tags, i;

    if (space == NULL) return ERROR;

    space_tags = space_get_tags(space);
    if (space_tags == NULL) return ERROR;

    num_tags = space_get_tags_number(space);

    fwprintf(f, L"#s:%04ld|%-8S|", space->id - SPACE_BASE_ID, space->name);

    for (i = 0; i < 6; i++) {
        if (space_get_direction(space, i) != NO_ID) {
            fwprintf(f, L"%02ld|", space_get_direction(space, i) - LINK_BASE_ID);
        } else {
            fwprintf(f, L"%02ld|", space_get_direction(space, i));
        }
    }

    fwprintf(f, L"%S|%S|%S|%S|%S|%S|%S|", space->graphic_description_type, space->basic_description[0], space->basic_description[1], space->basic_description[2], space->check_description[0], space->check_description[1], space->check_description[2]);

    for (i = 0; i < num_tags; i++) {
        if (space_tags[i] != NO_TAG){
    	   fwprintf(f, L"%d|", space_tags[i]);
        }
    }
    fwprintf(f, L"\n");

    return OK;
}