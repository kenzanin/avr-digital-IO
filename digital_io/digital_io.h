#ifndef DIGITAL_IO_H_INCLUDED
#define DIGITAL_IO_H_INCLUDED

/*
* Library Digital IO
* License LGPLv3
* Copy-left kenzanin[AT]gmail[dot]com
*/

#include <avr/io.h>
#include <compat/deprecated.h>

/** \brief ArgsToNumber berfungsi untuk merubah parameter list ... dengan jumlah uint8_t n menjadi bentuk _BV(item parameter list 1)|_BV(_BV(item parameter list 1))| dst
 *
 * \param n const uint8_t
 * \param ...
 * \return const uint8_t
 *
 */
inline const uint8_t argsToNumber(const uint8_t n,...)__attribute__ ((pure));


/** \brief berfungsi untuk mengatur PORT dan DDR fungsi ini tidak dirangcang untuk digunakan secara langsung namun
 * dibungkus melalui wrapper untuk menyederhanakan pemakaian
 *
 * \param PORT volatile uint8_t*
 * \param flag0 const uint8_t
 * \param __PORT const uint8_t
 * \return void
 *
 */
inline void ___port_setup(volatile uint8_t* PORT,const uint8_t flag0,const uint8_t __PORT);

/** port_output_hi adalah wrapper ___port_setup, untuk initialisasi pin pada PORT,dengan jumlah y dan list pin
 *  yang di pisahkan oleh koma sebagai output dengan kondisi awal 1
 *  contoh pemakaian
 * \code
 * port_output_hi(PORTC,4,0,1,2,3);
 * \endcode
 */
#define port_output_hi(x,y,...)   ___port_setup(&(x),5,argsToNumber((y),__VA_ARGS__))

/** port_output_lo adalah wrapper ___port_setup, untuk initialisasi pin pada PORT,dengan jumlah y dan list pin
 *  yang di pisahkan oleh koma sebagai output dengan kondisi awal 0
 *  contoh pemakaian
 * \code
 * port_output_lo(PORTC,4,0,1,2,3);
 * \endcode
 */
#define port_output_lo(x,y,...)   ___port_setup(&(x),9,argsToNumber((y),__VA_ARGS__))

/** port_output_hi adalah wrapper ___port_setup, untuk initialisasi pin pada PORT,dengan jumlah y dan list pin
 *  yang di pisahkan oleh koma sebagai output dengan kondisi awal 1
 *  contoh pemakaian
 * \code
 * port_output_hi(PORTC,4,0,1,2,3);
 * \endcode
 */
#define port_input_hi(x,y,...)    ___port_setup(&(x),6,argsToNumber((y),__VA_ARGS__))
#define port_input_lo(x,y,...)    ___port_setup(&(x),10,argsToNumber((y),__VA_ARGS__))
#define pin_output_hi(x,y)        ___port_setup(&(x),5,_BV(y))
#define pin_output_lo(x,y)        ___port_setup(&(x),9,_BV(y))
#define pin_input_hi(x,y)         ___port_setup(&(x),6,_BV(y))
#define pin_input_lo(x,y)         ___port_setup(&(x),10,_BV(y))

#define port_write_hi(x,y,...)    ___port_setup(&(x),4,argsToNumber((y),__VA_ARGS__))
#define port_write_lo(x,y,...)    ___port_setup(&(x),8,argsToNumber((y),__VA_ARGS__))
#define pin_write_hi(x,y)         sbi(x,y)
#define pin_write_lo(x,y)         cbi(x,y)

#define port_read(x)              *(&(x)-2)
#define pin_read(x,y)             (_Bool)*(&(x)-2)&_BV(y)
#define pin_read_wait(x,y,z)      a

#endif // DIGITAL_IO_H_INCLUDED
