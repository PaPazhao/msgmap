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
 
//! \note do not move this pre-processor statement to other places
#include ".\app_cfg.h"

#ifndef __CHECK_STRING_H__
#define __CHECK_STRING_H__


/*============================ INCLUDES ======================================*/
//#include "..\byte_queue\byte_queue.h"

/*============================ MACROS ========================================*/
#define CHECK_STRING(__STRCONFIG,__BOOL)                                        \
        check_string((__STRCONFIG),(__BOOL))
        
#define INIT_CHK_STRING(__STRCONFIG,__PSRT,__PTQUE)                             \
        init_CHK_string((__STRCONFIG),(__PSRT),(__PTQUE))

/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
typedef struct{
    enum {
        CHECK_STR_START = 0,
        CHECK_SRT_CHECK
    }tState;
    uint8_t* pchSTR;
    uint8_t* pchIndex;
    QUEUE(MsgMapQueue)* ptQueue;
}check_str_t;

/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
extern fsm_rt_t check_string(check_str_t *ptCHK, bool *pbIsRequestDrop);
extern bool init_CHK_string(check_str_t *ptCHK,uint8_t* pchStr,QUEUE(MsgMapQueue)* ptQueue);

#endif
