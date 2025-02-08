/*
 * expcalc - Pokémon experience calculator.
 * Copyright (c) 2024, 2025 Stephanos Stephanidis. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <math.h>

/*
 * Fast experience group. Introduced in Generation I.
 *
 * Max EXP: 800,000
 */
int
CalcEXP_Fast(double n)
{
	return(4 * pow(n, (double)3) / 5);
}

/*
 * Medium-fast experience group. Introduced in Generation I.
 *
 * Max EXP: 1,000,000
 */
int
CalcEXP_MediumFast(double n)
{
	return(pow(n, (double)3));
}

/*
 * Medium-slow experience group. Introduced in Generation I.
 * In R/B/Y/G/S/C, the experience underflow glitch applies to this group.
 *
 * Max EXP: 1,059,860
 */
int
CalcEXP_MediumSlow(double n)
{
	return(((6 * pow(n, (double)3)) / 5) - (15 * pow(n, (double)2)) + (100 * n) - 140);
}

/*
 * Slow experience group. Introduced in Generation I.
 *
 * Max EXP: 1,250,000
 */
int
CalcEXP_Slow(double n)
{
	return(5 * pow(n, (double)3) / 4);
}

/*
 * Erratic (Generations V, VI, VII)
 */
int
CalcEXP_Erratic(double n)
{
	if (n < 50)
		return((pow(n, (double)3) * (100 - n)) / 50);
	else if (n >= 50 && n < 68)
		return((pow(n, (double)3) * (150 - n)) / 100);
	else if (n >= 68 && n < 98)
		return((pow(n, (double)3) * ((1911 - (10 * n)) / 3)) / 500);
	else
		return((pow(n, (double)3) * (160 - n)) / 100);
}

/*
 * Fluctuating
 */
int
CalcEXP_Fluctuating(double n)
{
	if (n < 15)
		return((pow(n, (double)3) * (((n + 1) / 3) + 24)) / 50);
	else if (n >= 15 && n < 36)
		return((pow(n, (double)3) * (n + 14)) / 50);
	else
		return((pow(n, (double)3) * ((n / 2) + 32)) / 50);
}

/*
 * Gen 2 unused experience groups
 */

/*
 * Slightly Fast
 */
int
CalcEXP_SlightlyFast(double n)
{
	return(floor((3 * pow(n, (double)3)) / 4) + (10 * pow(n, (double)2)) + 30);
}

/*
 * Slightly Slow
 */
int
CalcEXP_SlightlySlow(double n)
{
	return(floor((3 * pow(n, (double)3)) / 4) + (20 * pow(n, (double)2)) + 70);
}
