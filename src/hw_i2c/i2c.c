/*
 * Copyright (c) 2012 Sebastian Trahm
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Interrupt based I2C (TWI) implementation as described by Atmel Application
 * Note "AVR315: Using the TWI module as I2C master on tinyAVR and megaAVR
 * devices".
 */

#include <avr/interrupt.h>
#include <compat/twi.h>

#include "i2c.h"

void
i2cInit(uint32_t i2c_clk)
{
	TWSR = 0;
	TWBR = ((F_CPU / i2c_clk) - 16) / 2;
}

/* TODO: implement at least full Master Mode support */
ISR
(TWI_vect)
{
	switch (TW_STATUS)
	{
		case TW_START:
		case TW_REP_START:
			break;
	}
}
