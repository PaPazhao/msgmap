/***************************************************************************
 *   Copyright(C)2009-2015 by zhao_li<lizhao15431230@qq.com>               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
 
#include ".\app_cfg.h"

#if MSGMAP == ENABLED
#ifndef __USE_SERVICE_MSG_MAP_H__
#define __USE_SERVICE_MSG_MAP_H__

/*============================ INCLUDES ======================================*/
/*============================ MACROS ========================================*/


/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
typedef struct _msg_t msg_t;
typedef bool MSG_HANDLER(const msg_t *ptMSG);

struct _msg_t {
    uint8_t* chMSG;                 //!< 
    MSG_HANDLER *fnHandler;         //!< 
};

/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
extern void cmd_unregister(void);
extern bool cmd_register(msg_t * ptMsg,uint8_t chItemNum);
extern fsm_rt_t MsgMapSearch(const msg_t **ptSuccessMsg);

#endif
#endif
