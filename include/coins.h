// Copyright (c) 2016-2018 The LoMoCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef  WALLEVE_COINS_H
#define  WALLEVE_COINS_H

#include <stdlib.h>
#include <stdint.h>
#include "vch.h"

typedef enum
{
    WALLEVE_COINS_LMC=0,
    WALLEVE_COINS_BTC=1,
    WALLEVE_COINS_ETH=2,
    WALLEVE_COINS_COUNT
}coin_t;

struct wl_coin_operation
{
    int (*is_compressed)();
    int (*get_addr)(const uint8_t *,char *,size_t);
    int (*get_priv)(const uint8_t *,vch_t *);
    int (*set_priv)(const char *,uint8_t *);
    int (*build_script)(const char *,vch_t *,vch_t *);
    int (*parse_tx)(const char *,const char *,vch_t *);
    int (*sign_tx)(const char *,const char *,vch_t *);
    int (*verify_tx)(const char *,const char *,vch_t *);
};

struct wl_coin_operation *wl_get_coin_operation(coin_t coin);

#endif //WALLEVE_COINS_H
