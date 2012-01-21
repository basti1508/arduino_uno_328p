/*
 * Copyright (c) 2011 Sebastian Trahm
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

#ifndef _DS1631_H_
#define _DS1631_H_

/*
 * DS1631 - Circuitry
 *
 * .--------------=4k7=-----------.
 * | .------------=4k7=---------. |
 * | |                          | |
 * | |    ,____  ____.          | |
 * | '-1--|SDA `' VCC|--8-------'-'--> 3V3
 * '---2--|SCL     A0|--7----.
 *     3--|Tout    A1|--6----|
 *     4--|GND     A2|--5----|
 *        `----------'       |
 *           DS1631         GND
 */

/*
 * DS1631 - Control Byte
 * ,-------------------------------------.
 * | 1 | 0 | 0 | 1 | A2 | A1 | A0 | R/_W |
 * `-------------------------------------'
 */
#define DS1631_READ_ADDR	0x91
#define DS1631_WRITE_ADDR	0x90

/*
 * DS1631 - Command Set
 */
#define DS1631_ACCESS_TH	0xA1 /* Access the high temperature register */
#define DS1631_ACCESS_TL	0xA2 /* Access the low temperature register */
#define DS1631_READ_CNTR	0xA8 /* Read the counter register */
#define DS1631_READ_SLOPE	0xA9 /* Read the slope register */
#define DS1631_READ_TEMP	0xAA /* Read temperature register */
#define DS1631_ACCESS_CFG	0xAC /* Access the configuration register */

#define DS1631_CONT_CONV	0xEE /* Continuous temperature conversion */
#define DS1631_STOP_CONV	0x22 /* Stop temperature conversion */

#endif /* _DS1631_H_ */