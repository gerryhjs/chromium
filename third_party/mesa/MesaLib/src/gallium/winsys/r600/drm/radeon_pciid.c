/*
 * Copyright 2010 Jerome Glisse <glisse@freedesktop.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * on the rights to use, copy, modify, merge, publish, distribute, sub
 * license, and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHOR(S) AND/OR THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *      Jerome Glisse
 */
#include <stdlib.h>
#include "radeon_priv.h"

struct pci_id {
	unsigned	vendor;
	unsigned	device;
	unsigned	family;
};

struct pci_id radeon_pci_id[] = {
	{0x1002, 0x3150, CHIP_RV380},
	{0x1002, 0x3152, CHIP_RV380},
	{0x1002, 0x3154, CHIP_RV380},
	{0x1002, 0x3E50, CHIP_RV380},
	{0x1002, 0x3E54, CHIP_RV380},
	{0x1002, 0x4136, CHIP_RS100},
	{0x1002, 0x4137, CHIP_RS200},
	{0x1002, 0x4144, CHIP_R300}, 
	{0x1002, 0x4145, CHIP_R300}, 
	{0x1002, 0x4146, CHIP_R300}, 
	{0x1002, 0x4147, CHIP_R300}, 
	{0x1002, 0x4148, CHIP_R350}, 
	{0x1002, 0x4149, CHIP_R350}, 
	{0x1002, 0x414A, CHIP_R350}, 
	{0x1002, 0x414B, CHIP_R350}, 
	{0x1002, 0x4150, CHIP_RV350}, 
	{0x1002, 0x4151, CHIP_RV350}, 
	{0x1002, 0x4152, CHIP_RV350}, 
	{0x1002, 0x4153, CHIP_RV350}, 
	{0x1002, 0x4154, CHIP_RV350}, 
	{0x1002, 0x4155, CHIP_RV350}, 
	{0x1002, 0x4156, CHIP_RV350}, 
	{0x1002, 0x4237, CHIP_RS200},
	{0x1002, 0x4242, CHIP_R200}, 
	{0x1002, 0x4243, CHIP_R200}, 
	{0x1002, 0x4336, CHIP_RS100},
	{0x1002, 0x4337, CHIP_RS200},
	{0x1002, 0x4437, CHIP_RS200},
	{0x1002, 0x4966, CHIP_RV250}, 
	{0x1002, 0x4967, CHIP_RV250}, 
	{0x1002, 0x4A48, CHIP_R420},
	{0x1002, 0x4A49, CHIP_R420},
	{0x1002, 0x4A4A, CHIP_R420},
	{0x1002, 0x4A4B, CHIP_R420},
	{0x1002, 0x4A4C, CHIP_R420},
	{0x1002, 0x4A4D, CHIP_R420},
	{0x1002, 0x4A4E, CHIP_R420},
	{0x1002, 0x4A4F, CHIP_R420},
	{0x1002, 0x4A50, CHIP_R420},
	{0x1002, 0x4A54, CHIP_R420},
	{0x1002, 0x4B48, CHIP_R420},
	{0x1002, 0x4B49, CHIP_R420},
	{0x1002, 0x4B4A, CHIP_R420},
	{0x1002, 0x4B4B, CHIP_R420},
	{0x1002, 0x4B4C, CHIP_R420},
	{0x1002, 0x4C57, CHIP_RV200},
	{0x1002, 0x4C58, CHIP_RV200},
	{0x1002, 0x4C59, CHIP_RV100},
	{0x1002, 0x4C5A, CHIP_RV100},
	{0x1002, 0x4C64, CHIP_RV250},
	{0x1002, 0x4C66, CHIP_RV250},
	{0x1002, 0x4C67, CHIP_RV250},
	{0x1002, 0x4E44, CHIP_R300}, 
	{0x1002, 0x4E45, CHIP_R300}, 
	{0x1002, 0x4E46, CHIP_R300}, 
	{0x1002, 0x4E47, CHIP_R300}, 
	{0x1002, 0x4E48, CHIP_R350}, 
	{0x1002, 0x4E49, CHIP_R350}, 
	{0x1002, 0x4E4A, CHIP_R350}, 
	{0x1002, 0x4E4B, CHIP_R350}, 
	{0x1002, 0x4E50, CHIP_RV350},
	{0x1002, 0x4E51, CHIP_RV350},
	{0x1002, 0x4E52, CHIP_RV350},
	{0x1002, 0x4E53, CHIP_RV350},
	{0x1002, 0x4E54, CHIP_RV350},
	{0x1002, 0x4E56, CHIP_RV350},
	{0x1002, 0x5144, CHIP_R100},
	{0x1002, 0x5145, CHIP_R100},
	{0x1002, 0x5146, CHIP_R100},
	{0x1002, 0x5147, CHIP_R100},
	{0x1002, 0x5148, CHIP_R200}, 
	{0x1002, 0x514C, CHIP_R200}, 
	{0x1002, 0x514D, CHIP_R200}, 
	{0x1002, 0x5157, CHIP_RV200}, 
	{0x1002, 0x5158, CHIP_RV200}, 
	{0x1002, 0x5159, CHIP_RV100}, 
	{0x1002, 0x515A, CHIP_RV100}, 
	{0x1002, 0x515E, CHIP_RV100},
	{0x1002, 0x5460, CHIP_RV380},
	{0x1002, 0x5462, CHIP_RV380},
	{0x1002, 0x5464, CHIP_RV380},
	{0x1002, 0x5657, CHIP_RV380},
	{0x1002, 0x5548, CHIP_R423},
	{0x1002, 0x5549, CHIP_R423},
	{0x1002, 0x554A, CHIP_R423},
	{0x1002, 0x554B, CHIP_R423},
	{0x1002, 0x554C, CHIP_R423},
	{0x1002, 0x554D, CHIP_R423},
	{0x1002, 0x554E, CHIP_R423},
	{0x1002, 0x554F, CHIP_R423},
	{0x1002, 0x5550, CHIP_R423},
	{0x1002, 0x5551, CHIP_R423},
	{0x1002, 0x5552, CHIP_R423},
	{0x1002, 0x5554, CHIP_R423},
	{0x1002, 0x564A, CHIP_RV410},
	{0x1002, 0x564B, CHIP_RV410},
	{0x1002, 0x564F, CHIP_RV410},
	{0x1002, 0x5652, CHIP_RV410},
	{0x1002, 0x5653, CHIP_RV410},
	{0x1002, 0x5834, CHIP_RS300},
	{0x1002, 0x5835, CHIP_RS300},
	{0x1002, 0x5954, CHIP_RS480},
	{0x1002, 0x5955, CHIP_RS480},
	{0x1002, 0x5974, CHIP_RS480},
	{0x1002, 0x5975, CHIP_RS480},
	{0x1002, 0x5960, CHIP_RV280}, 
	{0x1002, 0x5961, CHIP_RV280}, 
	{0x1002, 0x5962, CHIP_RV280}, 
	{0x1002, 0x5964, CHIP_RV280}, 
	{0x1002, 0x5965, CHIP_RV280},
	{0x1002, 0x5969, CHIP_RV100},
	{0x1002, 0x5a41, CHIP_RS400},
	{0x1002, 0x5a42, CHIP_RS400},
	{0x1002, 0x5a61, CHIP_RS400},
	{0x1002, 0x5a62, CHIP_RS400},
	{0x1002, 0x5b60, CHIP_RV380},
	{0x1002, 0x5b62, CHIP_RV380},
	{0x1002, 0x5b63, CHIP_RV380},
	{0x1002, 0x5b64, CHIP_RV380},
	{0x1002, 0x5b65, CHIP_RV380},
	{0x1002, 0x5c61, CHIP_RV280},
	{0x1002, 0x5c63, CHIP_RV280},
	{0x1002, 0x5d48, CHIP_R423},
	{0x1002, 0x5d49, CHIP_R423},
	{0x1002, 0x5d4a, CHIP_R423},
	{0x1002, 0x5d4c, CHIP_R423},
	{0x1002, 0x5d4d, CHIP_R423},
	{0x1002, 0x5d4e, CHIP_R423},
	{0x1002, 0x5d4f, CHIP_R423},
	{0x1002, 0x5d50, CHIP_R423},
	{0x1002, 0x5d52, CHIP_R423},
	{0x1002, 0x5d57, CHIP_R423},
	{0x1002, 0x5e48, CHIP_RV410},
	{0x1002, 0x5e4a, CHIP_RV410},
	{0x1002, 0x5e4b, CHIP_RV410},
	{0x1002, 0x5e4c, CHIP_RV410},
	{0x1002, 0x5e4d, CHIP_RV410},
	{0x1002, 0x5e4f, CHIP_RV410},
	{0x1002, 0x6880, CHIP_CYPRESS},
	{0x1002, 0x6888, CHIP_CYPRESS},
	{0x1002, 0x6889, CHIP_CYPRESS},
	{0x1002, 0x688A, CHIP_CYPRESS},
	{0x1002, 0x6898, CHIP_CYPRESS},
	{0x1002, 0x6899, CHIP_CYPRESS},
	{0x1002, 0x689c, CHIP_HEMLOCK},
	{0x1002, 0x689d, CHIP_HEMLOCK},
	{0x1002, 0x689e, CHIP_CYPRESS},
	{0x1002, 0x68a0, CHIP_JUNIPER},
	{0x1002, 0x68a1, CHIP_JUNIPER},
	{0x1002, 0x68a8, CHIP_JUNIPER},
	{0x1002, 0x68a9, CHIP_JUNIPER},
	{0x1002, 0x68b0, CHIP_JUNIPER},
	{0x1002, 0x68b8, CHIP_JUNIPER},
	{0x1002, 0x68b9, CHIP_JUNIPER},
	{0x1002, 0x68be, CHIP_JUNIPER},
	{0x1002, 0x68c0, CHIP_REDWOOD},
	{0x1002, 0x68c1, CHIP_REDWOOD},
	{0x1002, 0x68c8, CHIP_REDWOOD},
	{0x1002, 0x68c9, CHIP_REDWOOD},
	{0x1002, 0x68d8, CHIP_REDWOOD},
	{0x1002, 0x68d9, CHIP_REDWOOD},
	{0x1002, 0x68da, CHIP_REDWOOD},
	{0x1002, 0x68de, CHIP_REDWOOD},
	{0x1002, 0x68e0, CHIP_CEDAR},
	{0x1002, 0x68e1, CHIP_CEDAR},
	{0x1002, 0x68e4, CHIP_CEDAR},
	{0x1002, 0x68e5, CHIP_CEDAR},
	{0x1002, 0x68e8, CHIP_CEDAR},
	{0x1002, 0x68e9, CHIP_CEDAR},
	{0x1002, 0x68f1, CHIP_CEDAR},
	{0x1002, 0x68f8, CHIP_CEDAR},
	{0x1002, 0x68f9, CHIP_CEDAR},
	{0x1002, 0x68fe, CHIP_CEDAR},
	{0x1002, 0x7100, CHIP_R520},
	{0x1002, 0x7101, CHIP_R520},
	{0x1002, 0x7102, CHIP_R520},
	{0x1002, 0x7103, CHIP_R520},
	{0x1002, 0x7104, CHIP_R520},
	{0x1002, 0x7105, CHIP_R520},
	{0x1002, 0x7106, CHIP_R520},
	{0x1002, 0x7108, CHIP_R520},
	{0x1002, 0x7109, CHIP_R520},
	{0x1002, 0x710A, CHIP_R520},
	{0x1002, 0x710B, CHIP_R520},
	{0x1002, 0x710C, CHIP_R520},
	{0x1002, 0x710E, CHIP_R520},
	{0x1002, 0x710F, CHIP_R520},
	{0x1002, 0x7140, CHIP_RV515},
	{0x1002, 0x7141, CHIP_RV515},
	{0x1002, 0x7142, CHIP_RV515},
	{0x1002, 0x7143, CHIP_RV515},
	{0x1002, 0x7144, CHIP_RV515},
	{0x1002, 0x7145, CHIP_RV515},
	{0x1002, 0x7146, CHIP_RV515},
	{0x1002, 0x7147, CHIP_RV515},
	{0x1002, 0x7149, CHIP_RV515},
	{0x1002, 0x714A, CHIP_RV515},
	{0x1002, 0x714B, CHIP_RV515},
	{0x1002, 0x714C, CHIP_RV515},
	{0x1002, 0x714D, CHIP_RV515},
	{0x1002, 0x714E, CHIP_RV515},
	{0x1002, 0x714F, CHIP_RV515},
	{0x1002, 0x7151, CHIP_RV515},
	{0x1002, 0x7152, CHIP_RV515},
	{0x1002, 0x7153, CHIP_RV515},
	{0x1002, 0x715E, CHIP_RV515},
	{0x1002, 0x715F, CHIP_RV515},
	{0x1002, 0x7180, CHIP_RV515},
	{0x1002, 0x7181, CHIP_RV515},
	{0x1002, 0x7183, CHIP_RV515},
	{0x1002, 0x7186, CHIP_RV515},
	{0x1002, 0x7187, CHIP_RV515},
	{0x1002, 0x7188, CHIP_RV515},
	{0x1002, 0x718A, CHIP_RV515},
	{0x1002, 0x718B, CHIP_RV515},
	{0x1002, 0x718C, CHIP_RV515},
	{0x1002, 0x718D, CHIP_RV515},
	{0x1002, 0x718F, CHIP_RV515},
	{0x1002, 0x7193, CHIP_RV515},
	{0x1002, 0x7196, CHIP_RV515},
	{0x1002, 0x719B, CHIP_RV515},
	{0x1002, 0x719F, CHIP_RV515},
	{0x1002, 0x71C0, CHIP_RV530},
	{0x1002, 0x71C1, CHIP_RV530},
	{0x1002, 0x71C2, CHIP_RV530},
	{0x1002, 0x71C3, CHIP_RV530},
	{0x1002, 0x71C4, CHIP_RV530},
	{0x1002, 0x71C5, CHIP_RV530},
	{0x1002, 0x71C6, CHIP_RV530},
	{0x1002, 0x71C7, CHIP_RV530},
	{0x1002, 0x71CD, CHIP_RV530},
	{0x1002, 0x71CE, CHIP_RV530},
	{0x1002, 0x71D2, CHIP_RV530},
	{0x1002, 0x71D4, CHIP_RV530},
	{0x1002, 0x71D5, CHIP_RV530},
	{0x1002, 0x71D6, CHIP_RV530},
	{0x1002, 0x71DA, CHIP_RV530},
	{0x1002, 0x71DE, CHIP_RV530},
	{0x1002, 0x7200, CHIP_RV515},
	{0x1002, 0x7210, CHIP_RV515},
	{0x1002, 0x7211, CHIP_RV515},
	{0x1002, 0x7240, CHIP_R580},
	{0x1002, 0x7243, CHIP_R580},
	{0x1002, 0x7244, CHIP_R580},
	{0x1002, 0x7245, CHIP_R580},
	{0x1002, 0x7246, CHIP_R580},
	{0x1002, 0x7247, CHIP_R580},
	{0x1002, 0x7248, CHIP_R580},
	{0x1002, 0x7249, CHIP_R580},
	{0x1002, 0x724A, CHIP_R580},
	{0x1002, 0x724B, CHIP_R580},
	{0x1002, 0x724C, CHIP_R580},
	{0x1002, 0x724D, CHIP_R580},
	{0x1002, 0x724E, CHIP_R580},
	{0x1002, 0x724F, CHIP_R580},
	{0x1002, 0x7280, CHIP_RV570},
	{0x1002, 0x7281, CHIP_RV560},
	{0x1002, 0x7283, CHIP_RV560},
	{0x1002, 0x7284, CHIP_R580},
	{0x1002, 0x7287, CHIP_RV560},
	{0x1002, 0x7288, CHIP_RV570},
	{0x1002, 0x7289, CHIP_RV570},
	{0x1002, 0x728B, CHIP_RV570},
	{0x1002, 0x728C, CHIP_RV570},
	{0x1002, 0x7290, CHIP_RV560},
	{0x1002, 0x7291, CHIP_RV560},
	{0x1002, 0x7293, CHIP_RV560},
	{0x1002, 0x7297, CHIP_RV560},
	{0x1002, 0x7834, CHIP_RS300},
	{0x1002, 0x7835, CHIP_RS300},
	{0x1002, 0x791e, CHIP_RS690},
	{0x1002, 0x791f, CHIP_RS690},
	{0x1002, 0x793f, CHIP_RS600},
	{0x1002, 0x7941, CHIP_RS600},
	{0x1002, 0x7942, CHIP_RS600},
	{0x1002, 0x796c, CHIP_RS740},
	{0x1002, 0x796d, CHIP_RS740},
	{0x1002, 0x796e, CHIP_RS740},
	{0x1002, 0x796f, CHIP_RS740},
	{0x1002, 0x9400, CHIP_R600},
	{0x1002, 0x9401, CHIP_R600},
	{0x1002, 0x9402, CHIP_R600},
	{0x1002, 0x9403, CHIP_R600},
	{0x1002, 0x9405, CHIP_R600},
	{0x1002, 0x940A, CHIP_R600},
	{0x1002, 0x940B, CHIP_R600},
	{0x1002, 0x940F, CHIP_R600},
	{0x1002, 0x94A0, CHIP_RV740},
	{0x1002, 0x94A1, CHIP_RV740},
	{0x1002, 0x94A3, CHIP_RV740},
	{0x1002, 0x94B1, CHIP_RV740},
	{0x1002, 0x94B3, CHIP_RV740},
	{0x1002, 0x94B4, CHIP_RV740},
	{0x1002, 0x94B5, CHIP_RV740},
	{0x1002, 0x94B9, CHIP_RV740},
	{0x1002, 0x9440, CHIP_RV770},
	{0x1002, 0x9441, CHIP_RV770},
	{0x1002, 0x9442, CHIP_RV770},
	{0x1002, 0x9443, CHIP_RV770},
	{0x1002, 0x9444, CHIP_RV770},
	{0x1002, 0x9446, CHIP_RV770},
	{0x1002, 0x944A, CHIP_RV770},
	{0x1002, 0x944B, CHIP_RV770},
	{0x1002, 0x944C, CHIP_RV770},
	{0x1002, 0x944E, CHIP_RV770},
	{0x1002, 0x9450, CHIP_RV770},
	{0x1002, 0x9452, CHIP_RV770},
	{0x1002, 0x9456, CHIP_RV770},
	{0x1002, 0x945A, CHIP_RV770},
	{0x1002, 0x945B, CHIP_RV770},
	{0x1002, 0x9460, CHIP_RV770},
	{0x1002, 0x9462, CHIP_RV770},
	{0x1002, 0x946A, CHIP_RV770},
	{0x1002, 0x946B, CHIP_RV770},
	{0x1002, 0x947A, CHIP_RV770},
	{0x1002, 0x947B, CHIP_RV770},
	{0x1002, 0x9480, CHIP_RV730},
	{0x1002, 0x9487, CHIP_RV730},
	{0x1002, 0x9488, CHIP_RV730},
	{0x1002, 0x9489, CHIP_RV730},
	{0x1002, 0x948F, CHIP_RV730},
	{0x1002, 0x9490, CHIP_RV730},
	{0x1002, 0x9491, CHIP_RV730},
	{0x1002, 0x9495, CHIP_RV730},
	{0x1002, 0x9498, CHIP_RV730},
	{0x1002, 0x949C, CHIP_RV730},
	{0x1002, 0x949E, CHIP_RV730},
	{0x1002, 0x949F, CHIP_RV730},
	{0x1002, 0x94C0, CHIP_RV610},
	{0x1002, 0x94C1, CHIP_RV610},
	{0x1002, 0x94C3, CHIP_RV610},
	{0x1002, 0x94C4, CHIP_RV610},
	{0x1002, 0x94C5, CHIP_RV610},
	{0x1002, 0x94C6, CHIP_RV610},
	{0x1002, 0x94C7, CHIP_RV610},
	{0x1002, 0x94C8, CHIP_RV610},
	{0x1002, 0x94C9, CHIP_RV610},
	{0x1002, 0x94CB, CHIP_RV610},
	{0x1002, 0x94CC, CHIP_RV610},
	{0x1002, 0x94CD, CHIP_RV610},
	{0x1002, 0x9500, CHIP_RV670},
	{0x1002, 0x9501, CHIP_RV670},
	{0x1002, 0x9504, CHIP_RV670},
	{0x1002, 0x9505, CHIP_RV670},
	{0x1002, 0x9506, CHIP_RV670},
	{0x1002, 0x9507, CHIP_RV670},
	{0x1002, 0x9508, CHIP_RV670},
	{0x1002, 0x9509, CHIP_RV670},
	{0x1002, 0x950F, CHIP_RV670},
	{0x1002, 0x9511, CHIP_RV670},
	{0x1002, 0x9515, CHIP_RV670},
	{0x1002, 0x9517, CHIP_RV670},
	{0x1002, 0x9519, CHIP_RV670},
	{0x1002, 0x9540, CHIP_RV710},
	{0x1002, 0x9541, CHIP_RV710},
	{0x1002, 0x9542, CHIP_RV710},
	{0x1002, 0x954E, CHIP_RV710},
	{0x1002, 0x954F, CHIP_RV710},
	{0x1002, 0x9552, CHIP_RV710},
	{0x1002, 0x9553, CHIP_RV710},
	{0x1002, 0x9555, CHIP_RV710},
	{0x1002, 0x9557, CHIP_RV710},
	{0x1002, 0x9580, CHIP_RV630},
	{0x1002, 0x9581, CHIP_RV630},
	{0x1002, 0x9583, CHIP_RV630},
	{0x1002, 0x9586, CHIP_RV630},
	{0x1002, 0x9587, CHIP_RV630},
	{0x1002, 0x9588, CHIP_RV630},
	{0x1002, 0x9589, CHIP_RV630},
	{0x1002, 0x958A, CHIP_RV630},
	{0x1002, 0x958B, CHIP_RV630},
	{0x1002, 0x958C, CHIP_RV630},
	{0x1002, 0x958D, CHIP_RV630},
	{0x1002, 0x958E, CHIP_RV630},
	{0x1002, 0x958F, CHIP_RV630},
	{0x1002, 0x9590, CHIP_RV635},
	{0x1002, 0x9591, CHIP_RV635},
	{0x1002, 0x9593, CHIP_RV635},
	{0x1002, 0x9595, CHIP_RV635},
	{0x1002, 0x9596, CHIP_RV635},
	{0x1002, 0x9597, CHIP_RV635},
	{0x1002, 0x9598, CHIP_RV635},
	{0x1002, 0x9599, CHIP_RV635},
	{0x1002, 0x959B, CHIP_RV635},
	{0x1002, 0x95C0, CHIP_RV620},
	{0x1002, 0x95C2, CHIP_RV620},
	{0x1002, 0x95C4, CHIP_RV620},
	{0x1002, 0x95C5, CHIP_RV620},
	{0x1002, 0x95C6, CHIP_RV620},
	{0x1002, 0x95C7, CHIP_RV620},
	{0x1002, 0x95C9, CHIP_RV620},
	{0x1002, 0x95CC, CHIP_RV620},
	{0x1002, 0x95CD, CHIP_RV620},
	{0x1002, 0x95CE, CHIP_RV620},
	{0x1002, 0x95CF, CHIP_RV620},
	{0x1002, 0x9610, CHIP_RS780},
	{0x1002, 0x9611, CHIP_RS780},
	{0x1002, 0x9612, CHIP_RS780},
	{0x1002, 0x9613, CHIP_RS780},
	{0x1002, 0x9614, CHIP_RS780},
	{0x1002, 0x9615, CHIP_RS780},
	{0x1002, 0x9616, CHIP_RS780},
	{0x1002, 0x9710, CHIP_RS880},
	{0x1002, 0x9711, CHIP_RS880},
	{0x1002, 0x9712, CHIP_RS880},
	{0x1002, 0x9713, CHIP_RS880},
	{0x1002, 0x9714, CHIP_RS880},
	{0x1002, 0x9715, CHIP_RS880},
	{0, 0},
};

unsigned radeon_family_from_device(unsigned device)
{
	unsigned i;

	for (i = 0; ; i++) {
		if (!radeon_pci_id[i].vendor)
			return CHIP_UNKNOWN;
		if (radeon_pci_id[i].device == device)
			return radeon_pci_id[i].family;
	}
	return CHIP_UNKNOWN;
}

int radeon_is_family_compatible(unsigned family1, unsigned family2)
{
	switch (family1) {
	case CHIP_R600:
	case CHIP_RV610:
	case CHIP_RV630:
	case CHIP_RV670:
	case CHIP_RV620:
	case CHIP_RV635:
	case CHIP_RS780:
	case CHIP_RS880:
	case CHIP_RV770:
	case CHIP_RV730:
	case CHIP_RV710:
	case CHIP_RV740:
		switch (family2) {
		case CHIP_R600:
		case CHIP_RV610:
		case CHIP_RV630:
		case CHIP_RV670:
		case CHIP_RV620:
		case CHIP_RV635:
		case CHIP_RS780:
		case CHIP_RS880:
		case CHIP_RV770:
		case CHIP_RV730:
		case CHIP_RV710:
		case CHIP_RV740:
			return 1;
		default:
			return 0;
		}
		break;
	case CHIP_R100:
	case CHIP_RV100:
	case CHIP_RS100:
	case CHIP_RV200:
	case CHIP_RS200:
	case CHIP_R200:
	case CHIP_RV250:
	case CHIP_RS300:
	case CHIP_RV280:
	case CHIP_R300:
	case CHIP_R350:
	case CHIP_RV350:
	case CHIP_RV380:
	case CHIP_R420:
	case CHIP_R423:
	case CHIP_RV410:
	case CHIP_RS400:
	case CHIP_RS480:
	case CHIP_RS600:
	case CHIP_RS690:
	case CHIP_RS740:
	case CHIP_RV515:
	case CHIP_R520:
	case CHIP_RV530:
	case CHIP_RV560:
	case CHIP_RV570:
	case CHIP_R580:
	case CHIP_CEDAR:
	case CHIP_REDWOOD:
	case CHIP_JUNIPER:
	case CHIP_CYPRESS:
	case CHIP_HEMLOCK:
	default:
		return 0;
	}
}
