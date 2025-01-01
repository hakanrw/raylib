/*
 * This file is part of Refera, the interpreted scripting language.
 *
 * Refera is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Refera is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Refera.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2024  Ahmet Hakan Candar
 * Copyright (C) 2024  Berk Tahir Kılıç
 * Copyright (C) 2024  Barış Getiren
 * Copyright (C) 2024  Egemen Aybir
 */

#ifndef PS2_DRIVERS_H
#define PS2_DRIVERS_H

extern unsigned char ps2drv_usbd[];
extern unsigned int size_ps2drv_usbd;

extern unsigned char ps2drv_ps2kbd[];
extern unsigned int size_ps2drv_ps2kbd;

extern unsigned char ps2drv_iomanx[];
extern unsigned int size_ps2drv_iomanx;

extern unsigned char ps2drv_filexio[];
extern unsigned int size_ps2drv_filexio;

extern unsigned char ps2drv_mcman[];
extern unsigned int size_ps2drv_mcman;

extern unsigned char ps2drv_mcserv[];
extern unsigned int size_ps2drv_mcserv;

int ps2drv_load_modules();

#endif /* PS2_DRIVERS_H */
