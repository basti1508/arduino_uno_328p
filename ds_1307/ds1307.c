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

#include <avr/io.h>

#include "ds1307.h"
#include "i2c.h"

struct rtc_tm ds1307_tm;

char
bcd2dec(char val)
{
	 return ((val/16 * 10) + (val % 16));
}

char
dec2bcd(char val)
{
	return ((val/10 * 16) + (val % 10));
}

struct rtc_tm*
ds1307GetTime(void)
{
	unsigned char data;

	/* Request Start Address to be at 0x00 Address (Seconds) */
	i2cStart(DS1307_WR_ADDR);
	i2cWrite(0x00);
	i2cStop();

	/* Consecutive Read Seconds, Minutes, Hours,
	 * Day of Month, Month, Year and Workday */
	i2cStart(DS1307_RD_ADDR);
	data = i2cReadACK();
	/* 7th Bit is CLOCK HALT: ensure it is disabled */
	ds1307_tm.sec  = bcd2dec(data & 0x7F);
	data = i2cReadACK();
	ds1307_tm.min  = bcd2dec(data);
	data = i2cReadACK();
	ds1307_tm.hour  = bcd2dec(data);
	data = i2cReadACK();
	ds1307_tm.mday  = bcd2dec(data);
	data = i2cReadACK();
	ds1307_tm.mon  = bcd2dec(data);
	data = i2cReadACK();
	ds1307_tm.year  = bcd2dec(data);
	data = i2cReadNAK();
	ds1307_tm.wday  = bcd2dec(data);
	i2cStop();

	 return &ds1307_tm;
}

void
ds1307SetTime(uint8_t hours, uint8_t mins, uint8_t secs)
{
	i2cStart(DS1307_WR_ADDR);
	i2cWrite(0x00);
	i2cWrite(dec2bcd(secs));
	i2cWrite(dec2bcd(mins));
	i2cWrite(dec2bcd(hours));
	i2cStop();
}