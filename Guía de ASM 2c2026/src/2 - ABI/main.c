#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "../test-utils.h"
#include "ABI.h"

int main()
{
	/* Acá pueden realizar sus propias pruebas */
	// assert(alternate_sum_4_using_c(8, 2, 5, 1) == 10);

	// assert(alternate_sum_4_using_c_alternative(8, 2, 5, 1) == 10);

	// assert(alternate_sum_8(822, 230, 481, 566, 592, 70, 838, 216) == 1651);
	uint32_t result = -1;
	product_2_f(&result, 5, 1.5);
	assert(result == 7);

	return 0;
}
