// SPDX-License-Identifier: MIT

#define HASHSET_IMPLEMENTATION
#include "hashset.h"

#include <stdio.h>
#include <assert.h>

bool eq_u32(uint32_t a, unsigned int a_size,
            uint32_t b, unsigned int b_size)
{ return a == b; }

// Declare a uint32_t hashset
HASHSET_DECLARE(u32, uint32_t, hashset_hash_int32, eq_u32)

int main(void) {
    u32_set s;
    assert(u32_set_init(&s) == 0);

    assert(u32_set_insert(&s, 42, 0) == 1);
    assert(u32_set_insert(&s, 1337, 0) == 1);
    
    assert(u32_set_contains(&s, 42, 0) == 1);
    assert(u32_set_contains(&s, 1337, 0) == 1);
    
    assert(u32_set_remove(&s, 42, 0) == 1);
    assert(u32_set_contains(&s, 42, 0) == 0);

    u32_set_destroy(&s);
    return 0;
}
