//#include "acunit/i.h"
#include "cunit_include.h"
#include "../src/lib/Hash.h"
#include "../src/lib/Curl.h"
#include "random_trits.h"
#include <stdio.h>
#include <string.h>

static const size_t length = STATE_LENGTH;
static const int length_2 = length;
static const trit_t trits_2[] = (const trit_t []){0, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, 0, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, -1, -1, 0, -1, 0, -1, -1, -1, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, -1, 0, 0, -1, -1, -1, 0, -1, -1, -1, -1, -1, 0, -1, -1, -1, 0, -1, 0, 0, -1, -1, 0, 0, 0, -1, 0, -1, -1, -1, 0, 0, -1, -1, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0,-1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, -1, -1, 0, 0, -1, -1, -1, -1, 0, -1, -1, 0, -1, 0, -1, -1, 0, -1, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, -1, 0, 0, -1, -1, 0, 0, -1, -1, -1, -1, 0, -1, -1, -1, -1, 0, -1, 0, 0, -1, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0,0, 0, 0, 0, -1, 0, -1, -1, -1, -1, 0, 0, -1, -1, -1, 0, -1, 0, 0, 0, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, 0, 0, -1, -1, -1, 0, -1, -1, 0, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, -1, 0, 0, 0, -1, -1, -1, 0, -1, -1, 0, -1, -1, -1, -1, 0, -1, 0, -1, -1, 0, 0, 0, 0, -1, -1, 0, 0, 0, -1, 0, 0, 0, -1, -1, -1, 0, 0, -1, 0, -1, -1, -1, -1, 0, -1, -1, 0, -1, -1, 0, -1, -1, -1, 0, -1, 0, 0, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, -1, -1, 0, -1, 0, 0,-1, 0, -1, -1, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, -1, 0, -1, 0, -1, 0, 0, 0, 0, 0, -1, -1, 0, -1, 0, -1, -1, 0, 0, -1, 0, 0, 0, -1, -1, 0, -1, 0, 0, 0, 0, -1, -1, 0, -1, -1, -1, -1, -1, 0, 0, -1, -1, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, 0, 0, 0, -1, 0, -1, 0, 0, -1, -1, 0, -1, 0, -1, -1, -1, 0, -1, 0, 0, 0, 0, -1, -1, -1, 0, -1, -1, -1, 0, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1, -1, 0, 0, 0, -1, -1, 0, -1, 0, -1, 0, -1, -1, 0, -1, -1, -1, 0, -1, -1, 0, -1, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, 0, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, 0, -1, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, -1, 0, 0, 0, -1, -1, 0, -1, 0, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, -1, 0, -1, 0, -1, -1, 0, 0, -1, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1, 0, -1, -1, 0, -1, 0, 0, -1, -1, 0, -1, 0, 0, 0, 0, 0, -1, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, -1, -1, 0, -1, 0, 0, 0, 0, 0, -1, 0, -1, -1, 0, -1, 0, -1,0, 0, -1, -1, 0, 0, 0, 0, -1, 0, -1, -1, 0, 0, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1, 0, -1, 0};
static const trit_t expect_2[] = (const trit_t []){0, 1, 1, 0, -1, 0, 1, 0, 1, -1, -1, 0, 0, 1, 0, -1, 1, 1, -1, 1, -1, 1, 1, 1, 0, -1, 0, 1, -1, -1, 1, 0, 0, -1, -1, -1, 1, 0, -1, 1, 1, 0, 0, -1, 1, -1, 1, 0, 0, -1, 1, 0, 1, 1, 1, 1, -1,1, -1, 0, 1, 0, 1, -1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, -1, -1, 1, -1, 1, 0, 1, -1, -1, -1, 0, -1, -1, 1, 1, 0, 0, 0, -1, 1, 0, 0, 0, -1, 0, 0, -1, -1, 1, 0, 1, -1, 0, 0, 1, 1, 0, -1, 0, 0, -1, -1, 1, 0, -1, -1, -1, 0, 1, -1, 0, -1, 0, 1, -1, -1, 0, -1, 0, 0, 0, 0, 0, -1, -1, -1, -1, 0, 1, -1, -1, 1, 0, -1, 0, -1, -1, 1, 1, 0, 0, 1, -1, -1, -1, 1, 1, 1, 1, -1, -1, -1, 0, -1, 1,0, -1, 0, 1, 1, 0, -1, -1, -1, -1, 1, -1, 1, -1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, -1, 1, -1, 1, 1, 0, 0, 1, 1, -1, 0, -1, 1, -1, -1, 0, -1, -1, 0, 1, -1, 0, -1, 1, -1, -1, 0, 0, -1, 1, 0, 0, 1, 0, -1, 0, 1, 1, 1, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, -1, -1, 1, 0, 1, -1, 1, 1, 1, 1, 1, 0, 0, 1, 0, -1, 1, 0, 1, 1, 1, 0, 0, -1, 0, -1, -1, -1, 1, 1, 0, 0, 0, 0, 0, -1, 1, 1, 1, 1, 1, -1,-1, -1, 0, -1, 0, -1, 1, 0, 1, 1, -1, 1, 0, 0, -1, -1, 0, -1, -1, 1, -1, 1, -1, -1, -1, 1, -1, 0, 0, 1, 0, 0, 1, -1, -1, 0, -1, -1, 0, -1, 1, 0, 0, -1, -1, -1, 0, 0, 1, 0, 1, 0, 1, -1, -1,1, 0, 1, -1, 1, -1, -1, -1, 0, 0, 0, 0, -1, 1, 1, 1, 0, 1, -1, 0, -1, -1, 0, -1, 0, 0, 0, 0, -1, 1, -1, -1, 1, 0, 1, -1, -1, 0, -1, 1, 1, -1, -1, 1, -1, 0, 1, 1, 1, 0, -1, -1, -1, -1, 1, 0, 0, 0, 1, 1, 1, -1, 0, 0, -1, 0, 1, 0, -1, 0, 0, -1, 1, 0, 1, -1, 1, 0, 0, 0, 1, 1, 1, 0, -1, 1, 1, -1, 0, 0, -1, -1, 0, -1, -1, 0, -1, 0, -1, 1, 1, 0, 1, 0, 1, -1, -1, 0, -1, 1, -1, -1, 0, -1, 1, 1, 0, 1, 0, 0, -1, 0, 0, 1, -1, 0, -1, -1, -1, 1, 0, -1, -1, 1, 0, 0, 0, 1, -1, 0, 1, -1, 1, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1, 0, -1, -1, 0, -1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, -1, -1, 0, 1, 1, -1, -1, -1, 1, 0, 1, -1, -1, -1, 1, 1, 1, 0, -1, 0, 0, 0, 0, 0, 0, 1, 1, -1, -1, 0, 0, 1, 0, 1, 1, 0, -1, 1, 0, -1, 0, 1, 0, 1, 1, 1, -1, 1, 0, 0, 0, 1,0, 1, 0, -1, 1, 0, 1, 1, -1, -1, -1, 0, -1, -1, 1, 1, 1, -1, 1, 1, -1, -1, 0, 0, -1, 0, 1, -1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, -1, -1, -1, 0, 1, 1, 0, -1, -1, -1, 0, 0, 0, -1, 0, 0, 0,1, 0, -1, 0, 1, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 0, 0, 1, -1, 0, -1, 1, 0, -1, 1, 0, 1, -1, 1, 1, -1, -1, -1, 0, 1, 1, 0, 1, 1, -1, 0, -1, 0, 0, -1, 1, 1, -1, 0, 1, 1, 1, 1, 1, 0, -1, 1, 0, 0, -1, -1, -1, 1, 0, -1, -1, 1, 0, -1, 1, -1, 1, -1, 0, 1, 1, -1, 1, 0, 0, 1, -1, -1, -1, 1, 1, 1, 1, -1, 0, 0, -1, 0, 1, -1, 0, 1, 1, -1, -1, -1};

static const trit_t trits_in_2[] = (const trit_t []){0, 0, -1, -1, 0, 0, -1, 0, -1, -1, -1, -1, 0, -1, 0, -1, 0, -1, -1, 0, -1, -1, -1, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, -1, 0, -1, -1, 0, 0, -1, -1, -1, 0, 0, 0, -1, 0,-1, -1, -1, 0, 0, 0, 0, -1, 0, -1, -1, 0, -1, 0, 0, 0, -1, 0, 0, -1, -1, -1, 0, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, -1, 0, -1, -1, -1, -1, -1, 0, -1, -1, -1, 0, -1, -1, 0, -1, -1, -1, 0, -1, 0, 0, -1, -1, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, 0, 0, 0, -1, 0, -1, -1, -1, -1, -1, 0, 0, 0, -1, 0, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, 0, 0, 0, -1, -1, -1, -1, 0, -1, 0, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, -1, 0, -1, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0,0, -1, -1, -1, -1, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, -1, -1, 0, -1, 0, -1, -1, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, -1, -1,0, 0, 0, 0, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, -1, -1, 0, -1, 0, 0, -1,0, 0, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1, 0, -1, -1, -1, -1, 0, 0, 0, -1, -1, 0, 0, -1, -1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 0, -1, -1, 0, -1, -1, 0, 0, -1, -1, 0, -1, 0, 0, 0, -1, -1, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, 0, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1,-1, 0, -1, -1, -1, 0, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, -1, 0, 0, -1, -1, -1, -1, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0, -1, 0, 0, 0, -1, -1, 0, -1, 0, 0, -1, 0, -1, 0, -1, 0, 0, -1, 0, 0, -1, -1, 0, 0, 0, 0, -1, -1, 0, 0, 0, -1, -1, 0, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, -1, -1, 0, 0, -1, 0, -1, -1, 0, -1, -1, 0, -1, 0, 0, -1, -1, 0, -1, -1, 0, -1, -1, 0, -1, -1, -1, -1, 0, 0, 0, -1, 0, -1, -1, -1, -1, 0, -1, 0, 0, -1, 0, -1, 0, -1, -1, -1, 0, 0, 0, -1, 0, 0, 0, 0, -1, -1, 0, -1, -1, 0, 0, 0, 0, -1, 0, -1, 0, -1, 0, -1, -1, 0, -1, -1, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, -1, -1, -1, -1, -1, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, -1, 0, -1, -1, 0, 0, 0, 0, 0, 0, -1, -1, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, -1, -1, -1, 0, 0, 0, -1, -1, 0, -1, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, -1, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, 0};
static const trit_t trits_out_2[] = (const trit_t []){1, 1, 1, 1, 1, 0, 0, 0, 1, -1, 0, -1, 0, 0, 0, 0, 1, 0, 1, 0, 1, -1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, -1, 1, 0, -1, -1, 1, 1, 0, 1, 1, 1, 1, 0, -1, 0, 1, 0, -1, 0, 0, 1, 1, 0, 0, 0, 0, -1, 0, 0, 1, 0, -1, 1, 0, 1, 1, 1, -1, 1, 1, 1, 1, 1, 0, 1, 1, -1, 1, 1, 1, -1, 0, 1, 0, 1, -1, -1, 0, 1, 1, 0, 1, 0, -1, 1, 1, 1, 0, 1, 0, 1, 1, -1, -1, -1, -1, -1, 1, -1, 0, 1, 1, 0, 1, 0, -1,-1, -1, -1, 0, 0, 1, 1, 0, 0, 1, -1, 0, 1, 1, 1, -1, 0, -1, 0, -1, 1, 1, 1, 0, 1, 1, -1, 0, -1, -1, -1, 0, 0, 1, -1, -1, 0, 0, -1, 1, -1, 1, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, 0, 0, -1, 1, -1, -1, 0, 0, 1, 0, 0, 1, 0, -1, -1, -1, 1, 1, -1, 0, -1, 1, -1, 0, 0, 0, 1, -1, 1, 0, 1, 1, 1, -1, -1, 0, 1, -1, 1, 0, 0, 0, 1, -1, 0, -1, 1, 1, 0, 0, -1, -1, 1, -1, 0, -1, 0, 1, 0, 1, 0, -1, 0, 1, -1, 0, 1, 1, 0, -1, -1, -1, -1, 1, 0, -1, 1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, -1, 1, 1, -1, 0, 0, -1, 1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, 0, -1, 1,0, 1, 1, 1, -1, 0, 1, 0, 1, 1, -1, -1, -1, 0, 1, 1, -1, 1, 0, 0, 0, 1, 1, 0, -1, 0, 1, 1, 1, 0, 0, 0, 1, -1, 1, 0, 0, 0, 0, -1, 1, 0, 0, 1, 0, 0, 0, -1, -1, 1, 0, 1, 0, 0, 1, -1, -1, 0, 0,0, 1, 0, -1, 0, -1, 1, -1, -1, 0, 1, 1, 0, -1, 1, -1, -1, 1, 1, 0, -1, 0, 1, -1, 1, -1, 1, 1, 1, 0, 0, -1, 0, 0, 1, -1, 1, 0, -1, 0, 1, 1, 1, 0, 1, 0, -1, 1, 1, -1, -1, -1, 1, -1, -1, 1, 1, -1, 0, 1, -1, 0, -1, 1, 1, 1, 1, 0, 1, -1, 0, 0, 1, -1, 1, -1, 1, -1, -1, 0, -1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, -1, -1, -1, 0, 0, -1, 1, -1, -1, 1, 1, 0, -1, 1, 0, 0, 1, -1, 1, 0, 1,0, 1, 0, 1, 1, 0, 1, 0, 0, -1, 0, -1, 1, 1, 1, 1, 1, 1, 1, 0, -1, 0, 0, 0, -1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, -1, 1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, 0, -1, 0, 1, 1, 0, -1, 1, 1, 0, 1, 1, -1, 0, 0, 0, -1, 1, -1, 1, -1, 1, -1, 0, 1, -1, -1, -1, 0, 0, 1, -1, -1, -1, 0, 0, 1, 0, 1, 0, -1, 0, 0, 0, -1, 0, 0, 1, 1, 0, -1, 0, 1, 1, -1, 0, 0, 1, 0, 1, 1, -1, 1, -1, 1, 0, -1, 0, 0, -1, 1, 0, 1, -1, -1, 0, 1, 0, 1, 0, 0, -1, 1, -1, -1, 1, 0, -1, -1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, -1, 1, 1, -1, 0, -1, 1, -1, 1, 1, 1, 1, 1, -1, -1, 0, 1, 0, 1, -1, 1, 1, -1, -1, -1, 0, -1, 1, 1, 0, 0, 0, 0, 0, 1, 0, -1, -1, -1, 0, 0, 0, -1, -1, -1, -1, 1, -1, 0, -1, 0, 0, 0, 1, 1, 0, -1, 1, 1, -1, 0, 1, 0, 0, -1, 0, 0, 0, 1, 1, 0, 1, -1, 1, -1, 1, -1, 0, 1, 1, -1, -1, -1, -1, 1, 1, 0, 0, 1, 0, -1, 0, 0, 1, 0, 0, 0, 0, 1, 1, -1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, -1, 0, 1};
static const trit_t trits_in_1[] = (const trit_t []){-1, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, 0, -1, 0, 0, 0, -1, -1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0, -1, -1, 0, -1, -1, -1, 0, 0, 0, -1, -1, 0, -1, 0, -1, -1, 0, -1, 0, -1, -1, -1, 0, 0, 0, 0, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, 0, -1, 0, 0, -1, -1, 0, -1, -1, -1, -1, 0, -1, 0, 0, -1, -1, 0, -1, -1, -1, 0, -1, 0, 0, 0, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, 0, -1, -1, 0, 0, -1, -1, 0, 0, 0, 0, -1, -1, 0, -1, -1, -1, 0, -1, 0, 0, -1, 0, -1, -1, 0, 0, -1, -1, -1, -1, 0, 0, 0, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, 0, -1, -1, 0, -1, -1, -1, 0, 0, -1, -1, -1, -1, 0, -1, 0, 0, 0, -1, -1, -1, 0, -1, -1, -1, 0, 0, -1, 0, -1, 0, -1, 0, 0, -1, 0, -1, -1, 0, -1, 0, -1, -1, 0, -1, 0, 0, 0, -1, -1, -1, -1, -1, 0, 0, 0, -1, -1, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1, 0, -1, 0, 0, -1, 0, -1, -1, 0, 0, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, 0, -1, 0, -1, -1, -1, -1, 0, -1, -1, 0, -1, 0, 0, -1, 0, -1, 0, 0, -1, -1, -1, -1, 0, -1, 0, 0, -1, 0, 0, 0, 0, -1, -1, 0, 0, -1, 0, -1, -1, 0, -1, -1, -1, -1, 0, -1, -1, 0, -1, 0, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, -1, -1, -1, -1, 0, -1, -1, 0, -1, -1, -1, -1, 0, -1, -1, -1, 0, 0, 0, -1, -1, 0, 0, 0, -1, -1, 0, 0, -1, 0, -1, -1, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, 0, -1, -1, -1, 0, -1, 0, 0, 0, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, 0, -1, 0, 0, -1, 0, -1, -1, 0, -1, -1, -1, -1, 0, -1, 0, 0, -1, -1, -1, 0, 0, 0, -1, -1, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1, 0, -1, -1, -1, 0, -1, 0, 0, 0, -1, 0, 0, -1, 0, 0, 0, -1, -1, -1, 0, -1, 0, -1, -1, 0, 0, -1, -1, 0, 0, -1, 0, -1, -1, 0, -1, -1, 0, 0, -1, 0, -1, -1, -1, -1, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, -1, 0, 0, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1, -1, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, -1, -1, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, 0, -1, -1, 0, -1, 0, -1, 0, 0, -1, -1, 0, 0, 0, -1, -1, 0, -1, 0, 0, 0, 0, -1, -1, -1, 0, -1, -1, -1, -1, 0, 0, 0, 0, -1, -1, -1, 0, -1, -1, 0, 0, -1, 0, -1, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -1, -1, -1, 0, 0, -1, -1, 0, 0, -1, -1, 0, 0, -1, -1, -1, 0, -1, 0, -1, 0, -1, -1, -1, 0, -1, 0, -1, -1, -1, 0, -1, 0, -1, 0, -1, -1, -1, 0, -1, 0, 0, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, -1, 0, 0, 0, -1, -1, -1, 0, 0, 0, -1, -1, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, -1, 0, 0, 0, -1};
static const trit_t trits_out_1[] = (const trit_t []){0, -1, 1, 1, 1, -1, -1, 0, 0, -1, 1, 0, 0, 1, -1, 1, 0, -1, 1, 0, 0, -1, -1, -1, 1, 1, -1, 1, 1, -1, 1, -1, -1, 0, 1, -1, 0, 0, 0, -1, 0, 1, 1, 0, 1, -1, 0, -1, -1, 1, 0, 1, 0, -1, -1, 1, 1, -1, 1, 0, -1, -1, 1, 1, 0, 0, 0, 1, -1, 1, 0, 1, 0, -1, -1, -1, -1, 1, -1, 1, -1, -1, -1, 1, 0, 0, 0, -1, -1, 1, 1, 1, 0, 0, 0, 0, 0, -1, 1, 0, 1, 0, -1, -1, 0, 1, -1, 0, -1, 1, 1, -1, -1, 0, 0, 0, 1, 1, 0, -1, 1, 0, 0, -1, 1, -1, 1, 0, 1, -1, 1, 1, 1, 1, 0, 0, 1, 1, -1, -1, 1, -1, 1, -1, -1, -1, -1, 0, -1, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, 1, 0, 0, 0, 0, 1, 0, -1, 1, -1, -1, -1, -1, -1, -1, 1, -1, 0, -1, 1, 0, 1, 0, 0, -1, 1, 1, -1, 0, 1, 1, 0, 0, -1, 0, -1, 1, -1, -1, -1, -1, 0, -1, -1, 0, 1, 1, 1, -1, 1, -1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, -1, 0, 1, 0, 1, -1, -1, 1, 0, -1, 1, 0, 0, 0, -1, 0, -1, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, -1, 1, 1, 1, -1, -1, 1, -1, -1, -1, 1, -1, 1, 1, 0, 0, 1, -1, 0, -1, -1, 0, -1, 1, 1, 1, 0, 1, -1, -1, 0, -1, -1, 1, 0, 0, -1, 0, 0, 1, 1, -1, 0, 1, -1, 0, 0, -1, -1, 0, 0, 1, -1, 1, -1, -1, -1, 0, 0, -1, -1, -1, 1, 1, -1, -1, -1, 1, 0, -1, -1, 1, -1, 1, 1, 1, 1, 0, 1, 1, 1, -1, 1, 1, -1, 1, 0, -1, -1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, -1, -1, -1, 0, -1, 1, 1, 0, 1, -1, -1, -1, -1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, -1, 1, 0, 0, 1, 1, 1, -1, 0, 0, 0, 0, 1, 1, -1, 1, -1, -1, -1, 0, 1, 0, 0, 0, 1, 1, -1, 0, 0, 0, 1, 1, 1, -1, 1, -1, 1, 1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, 1, 1, 0, -1, 0, 0, 0, 0, 1, 1, 0, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, -1, -1, 1, 0, 0, 1, 1, -1, 1, 0, 1, 1, 0, -1, 1, -1, 0, 0, 0, 0, -1, 1, 1, 0, 0, 1, 1, 1, 0, -1, 1, 1, 0, 0, 1, 1, 0, -1, -1, 1, 0, 0, 1, 1, -1, -1, 0, -1, -1, 1, 1, -1, -1, 1, -1, -1, 1, 0, -1, 0, -1, 0, 0, 1, 0, 0, 1, -1, 0, 1, 1, -1, -1, 0, -1, -1, 1, 0, 1, -1, 0, -1, 0, 1, 0, -1, 1, 1, 1, -1, 0, 1, -1, -1, -1, 1, 1, 0, 0, -1, 0, -1, -1, -1, 1, 0, 1, 0, 1, 1, 0, -1, 0, 0, 1, -1, -1, 0, 1, 0, -1, -1, -1, 0, 1, 1, -1, -1, 1, -1, 0, 0, -1, 1, 1, 1, -1, 1, -1, 0, -1, 0, 1, -1, 1, -1, 0, 1, -1, -1, -1, 1, 0, -1, 0, 0, 1, 0, 0, 0, 1, -1, 1, 1, -1, -1, -1, 0, -1, 1, 1, -1, 1, 1, 0, 1, -1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, -1, 0, 0, 0, -1, 0, -1, 0, -1, 0, 0, 0, 1, 1, 1, 0, 0, 1, -1, -1, -1, -1, 1, -1, 0, -1, -1, 1, 1, -1, -1, -1, -1, -1, 1, 0, 0, 0, 0, 1, 1, 0, 1, -1, -1, -1, -1, -1, 0, -1, -1, 1, 1, 0, 0, 0, 0, 1, 1, -1, 0, 1, 0, -1, 0, 0, 1, 0, 0, 0, 0, 1, -1};

int init_suite(void) {return 0;}
int clean_suite(void) {return 0;}

void test_curl_absorb(void);


void test_curl_absorb(void) {
	trit_t my_trits_1[STATE_LENGTH];

	Curl curl;
       	init_curl(&curl);

	int length_1 = STATE_LENGTH;
	memcpy(my_trits_1, trits_in_2, length_1 * sizeof(trit_t));

	for(int i=0; i<3; i++) {
		absorb(&curl, my_trits_1, i*HASH_LENGTH,HASH_LENGTH);
	}
	squeeze(&curl, my_trits_1,0,length_1);
	reset(&curl);
	CU_ASSERT(memcmp(my_trits_1, trits_in_2, STATE_LENGTH * sizeof(trit_t)) != 0);
	CU_ASSERT(memcmp(my_trits_1, trits_out_2, STATE_LENGTH * sizeof(trit_t)) == 0);

	length_1 = STATE_LENGTH;
	memcpy(my_trits_1, trits_in_1, length_1 * sizeof(trit_t));
	CU_ASSERT(memcmp(my_trits_1, trits_in_1, STATE_LENGTH * sizeof(trit_t)) == 0);

	absorb(&curl, my_trits_1, HASH_LENGTH,HASH_LENGTH);
	length_1 = STATE_LENGTH;
	squeeze(&curl, my_trits_1,0,length_1);

	CU_ASSERT(memcmp(my_trits_1, trits_out_1, length_1 * sizeof(trit_t)) == 0);
}

void test_curl_reset() {

	trit_t my_trits_2[length_2];

	Curl curl;
       	init_curl(&curl);

	memcpy(my_trits_2, trits_2, length_2 * sizeof(trit_t));

	absorb(&curl, my_trits_2,0,length_2);
	squeeze(&curl, my_trits_2,0,length_2);
	CU_ASSERT(memcmp(my_trits_2, expect_2, length_2 * sizeof(trit_t)) == 0);

	reset(&curl);
	memcpy(my_trits_2, trits_2, length_2 * sizeof(trit_t));

	absorb(&curl, my_trits_2,0,length_2);
	squeeze(&curl, my_trits_2,0,length_2);
	CU_ASSERT(memcmp(my_trits_2, expect_2, length_2 * sizeof(trit_t)) == 0);

}

void test_curl_noreset_fail() {
	trit_t my_trits_2[length_2];

	Curl curl;
       	init_curl(&curl);
	memcpy(my_trits_2, trits_2, length_2 * sizeof(trit_t));
	memcpy(my_trits_2, trits_2, length_2 * sizeof(trit_t));

	absorb(&curl, my_trits_2,0,length_2);
	squeeze(&curl, my_trits_2,0,length_2);
	CU_ASSERT(memcmp(my_trits_2, expect_2, length_2 * sizeof(trit_t)) == 0);

	int length = HASH_LENGTH;
	absorb(&curl, my_trits_2,0,length);
	squeeze(&curl, my_trits_2,0,length);
	CU_ASSERT_FALSE(memcmp(my_trits_2, expect_2, HASH_LENGTH * sizeof(trit_t))==0);
}

static CU_TestInfo tests[] = {
	{"Curl Absorb Test", test_curl_absorb},
	{"Curl Reset Test", test_curl_reset},
	{"Curl NoReset Fail Test", test_curl_noreset_fail},
	CU_TEST_INFO_NULL,
};

static CU_SuiteInfo suites[] = {
	{ "suitename1", init_suite, clean_suite, NULL, NULL, tests },
	CU_SUITE_INFO_NULL,
};

int main() {
	return run_tests(suites);
}
