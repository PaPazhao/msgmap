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
 

/*============================ INCLUDES ======================================*/
#include ".\app_cfg.h"

/*============================ MACROS ========================================*/
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
#define CHECK_STR_FSM_RESET() do {ptCHK->tState = CHECK_STR_START;}while(0)
fsm_rt_t check_string(check_str_t *ptCHK, bool *pbIsRequestDrop)
{
    uint8_t chByte = 0;
    
    if( (NULL == ptCHK) || (NULL == pbIsRequestDrop) ){ 
        return fsm_rt_err;
    }
    
    switch(ptCHK->tState){
        case CHECK_STR_START:
            if(NULL == ptCHK->pchSTR) {
                return fsm_rt_err;
            } else {
                ptCHK->pchIndex = ptCHK->pchSTR;
                ptCHK->tState = CHECK_SRT_CHECK;
            }
            //break;
            
        case CHECK_SRT_CHECK:
            if(PEEK_QUEUE(MsgMapQueue,ptCHK->ptQueue,&chByte)) {
                *pbIsRequestDrop = true;
                if(chByte == *(ptCHK->pchIndex)) {
                    if('\0' == *(++(ptCHK->pchIndex))){
                        CHECK_STR_FSM_RESET();
                        return fsm_rt_cpl;
                    }
                    *pbIsRequestDrop = false;
                } 
            }
            break;
    }
    
    return fsm_rt_on_going;
}

bool init_CHK_string(check_str_t *ptCHK,uint8_t* pchStr,QUEUE(MsgMapQueue)* ptQueue)
{
    if((NULL == ptCHK)||(NULL == pchStr)||(NULL == ptQueue)){
        return false;
    }
    
    ptCHK->pchSTR   = pchStr;
    ptCHK->pchIndex = NULL;
    ptCHK->tState   = CHECK_STR_START;
    ptCHK->ptQueue  = ptQueue;

    return true;
}
