/*
 * drivers/video/sun3i/disp/include/eBSP_basetype/ebase_base_ops.h
 *
 * (C) Copyright 2007-2012
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * holigun <holigun@allwinnertech.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef	__EBASE_BASE_OPS_H__
#define	__EBASE_BASE_OPS_H__


/*
#define readb(reg)						(*(volatile unsigned char *)(reg))
#define readw(reg)						(*(volatile unsigned short *)(reg))
#define readl(reg)						(*(volatile unsigned long *)(reg))

#define writeb(value,reg)				(*(volatile unsigned char *)(reg) = (value))
#define writew(value,reg)				(*(volatile unsigned short *)(reg) = (value))
#define writel(value,reg)				(*(volatile unsigned long *)(reg) = (value))
*/

#define __REG(x)    (*(volatile unsigned int   *)(x))
#define __REGw(x)   (*(volatile unsigned int   *)(x))
#define __REGhw(x)  (*(volatile unsigned short *)(x))


//===

#define set_bit_b( mask, reg) 			(writeb((readb(reg) | (mask)) , (reg)))
#define set_bit_w( mask, reg) 	 		(writew((readw(reg) | (mask)) , (reg)))
#define clear_bit_b( mask, reg) 	 	(writeb((readb(reg) & (~ (mask))) , (reg)))
#define clear_bit_w( mask, reg) 	 	(writew((readw(reg) & (~ (mask))) , (reg)))

#undef  set_bit
#define set_bit( value, bit )      		( (value) |=  ( 1U << (bit) ) )

#undef  clear_bit
#define clear_bit( value, bit )    		( (value) &= ~( 1U << (bit) ) )

#undef  reverse_bit
#define reverse_bit( value, bit )  		( (value) ^=  ( 1U << (bit) ) )

#undef  test_bit
#define test_bit( value, bit )     		( (value)  &  ( 1U << (bit) ) )



#define _bits_mod(Len)                 ( ( 1U<<(Len) ) - 1 )

#define _bits_mask(Len, _pos)          ( ~ ( _bits_mod(Len)<<(_pos) ) )

#define clear_bits(regVal, _pos, Len)   (regVal) &= _bits_mask(Len, _pos)

#define set_bits(regVal, _pos, Len, _val)   (regVal) = ( (regVal) & _bits_mask(Len, _pos) ) | ( ( (_val) & _bits_mod(Len) )<<(_pos) )

#define test_bits(regVal, _pos, Len, _val)       ( (regVal) & (~ _bits_mask(Len, _pos) ) ) == ( (_val)<<(_pos) )




#undef  min
#define min( x, y )          			( (x) < (y) ? (x) : (y) )

#undef  max
#define max( x, y )          			( (x) > (y) ? (x) : (y) )


#endif	//__EBASE_BASE_OPS_H__

