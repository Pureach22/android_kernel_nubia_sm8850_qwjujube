__int64 __fastcall _ieee80211_start_rx_ba_session(
        __int64 result,
        unsigned __int8 a2,
        unsigned __int16 a3,
        __int16 a4,
        __int16 a5,
        unsigned int a6,
        unsigned int a7,
        char a8,
        char a9,
        _BYTE *a10)
{
  unsigned int v10; // w19
  unsigned __int8 v12; // w28
  __int64 v13; // x20
  int v14; // w25
  __int64 v15; // x8
  __int64 v16; // x23
  unsigned int v17; // w8
  __int16 v18; // w27
  __int64 v19; // x23
  __int64 v20; // x22
  __int64 v21; // x26
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x24
  __int64 v25; // x0
  __int64 v26; // x25
  int v27; // w8
  _WORD *v28; // x8
  unsigned int v29; // w27
  int v30; // w26
  char v31; // w25
  __int64 v32; // x22
  __int64 lock; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  unsigned __int16 v36; // w22
  __int16 v37; // w24
  unsigned __int8 v38; // w22
  __int16 v39; // w28
  unsigned __int64 v40; // x24
  __int64 v41; // x0
  __int64 v42; // x8
  unsigned int v43; // w8
  __int64 v44; // x8
  __int64 v45; // x9
  __int64 v46; // x10
  __int64 v47; // x0
  char v48; // w9
  __int64 v49; // x23
  __int64 v50; // x0
  __int64 v51; // x9
  __int16 v52; // [xsp+Ch] [xbp-34h]
  unsigned __int16 v53; // [xsp+Ch] [xbp-34h]
  _QWORD v54[2]; // [xsp+18h] [xbp-28h] BYREF
  __int16 v55; // [xsp+28h] [xbp-18h]
  __int16 v56; // [xsp+2Ah] [xbp-16h]
  int v57; // [xsp+2Ch] [xbp-14h]
  unsigned __int16 v58; // [xsp+30h] [xbp-10h]
  int v59; // [xsp+32h] [xbp-Eh]
  __int16 v60; // [xsp+36h] [xbp-Ah]
  __int64 v61; // [xsp+38h] [xbp-8h]

  v10 = a7;
  v12 = a2;
  v13 = result;
  v14 = a3;
  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(_QWORD *)(result + 80);
  v54[0] = 0;
  v54[1] = result + 2688;
  v55 = a6;
  v16 = *(_QWORD *)(v15 + 1616);
  v56 = a4;
  v57 = 0;
  v58 = a3;
  v59 = 0;
  v60 = 0;
  if ( (unsigned __int16)a6 <= 7u
    && ((*(_BYTE *)(result + 2926) & 1) != 0 || *(_BYTE *)(result + 2964) == 1)
    && (*(_QWORD *)(result + 216) & 0x100) == 0 )
  {
    if ( (*(_BYTE *)(result + 3021) & 1) != 0 )
    {
      v17 = 1024;
    }
    else if ( *(_BYTE *)(result + 2964) )
    {
      v17 = 256;
    }
    else
    {
      v17 = 64;
    }
    if ( a5 == 1 )
    {
      if ( v17 < (unsigned __int16)a7 )
      {
        v18 = 38;
        goto LABEL_8;
      }
LABEL_25:
      v29 = *(unsigned __int16 *)(result + 2696);
      if ( (_WORD)a7 )
        LOWORD(v17) = a7;
      if ( (unsigned __int16)v17 >= v29 )
        v10 = *(unsigned __int16 *)(result + 2696);
      else
        v10 = (unsigned __int16)v17;
      LOWORD(v57) = v10;
      if ( ((*(_QWORD *)(result + 864) >> a6) & 1) != 0 )
      {
        v30 = a3;
        v31 = a8;
        if ( *(unsigned __int8 *)(result + (unsigned __int16)a6 + 824) == a2 )
        {
          v32 = result + 8LL * (unsigned __int16)a6;
          lock = _rcu_read_lock();
          v34 = *(_QWORD *)(v32 + 696);
          if ( v34 && *(unsigned __int16 *)(v34 + 152) == v30 )
          {
            result = _rcu_read_unlock(lock);
            goto LABEL_63;
          }
          result = _rcu_read_unlock(lock);
          v18 = 37;
          goto LABEL_64;
        }
        v36 = a3;
        v37 = a4;
        _ieee80211_stop_rx_ba_session((_QWORD *)result, a6, 0, 0x20u, 0);
        a4 = v37;
        a3 = v36;
        a8 = v31;
        v14 = v30;
      }
      v30 = v14;
      if ( (*(_QWORD *)(v16 + 96) & 0x200000000LL) == 0 )
      {
        v38 = v12;
        v39 = a4;
        v31 = a8;
        v53 = a3;
        result = _kmalloc_cache_noprof(init_timer_key, 3520, 160);
        v40 = result;
        if ( result )
        {
          *(_DWORD *)(result + 16) = 0;
          init_timer_key(result + 56, sta_rx_agg_session_timer_expired, 0x80000, 0, 0);
          init_timer_key(v40 + 96, sta_rx_agg_reorder_timer_expired, 0, 0, 0);
          *(_QWORD *)(v40 + 32) = _kmalloc_noprof(24LL * v10, 3520);
          v41 = _kmalloc_noprof(8LL * v10, 3520);
          v42 = *(_QWORD *)(v40 + 32);
          *(_QWORD *)(v40 + 40) = v41;
          if ( v42 && v41 )
          {
            if ( v29 )
            {
              if ( v10 <= 1 )
                v43 = 1;
              else
                v43 = v10;
              v44 = 24LL * v43;
              v45 = 0;
              do
              {
                v46 = *(_QWORD *)(v40 + 32) + v45;
                v45 += 24;
                *(_QWORD *)v46 = v46;
                *(_QWORD *)(v46 + 8) = v46;
                *(_DWORD *)(v46 + 16) = 0;
              }
              while ( v44 != v45 );
            }
            result = drv_ampdu_action(v16, *(_QWORD *)(v13 + 80), v54);
            if ( !(_DWORD)result )
            {
              v48 = *(_BYTE *)(v40 + 155);
              *(_WORD *)(v40 + 148) = v39;
              *(_WORD *)(v40 + 144) = v39;
              *(_WORD *)(v40 + 150) = v10;
              v12 = v38;
              *(_BYTE *)(v40 + 155) = v48 & 0xFA | a9 & 1;
              *(_WORD *)(v40 + 152) = v30;
              *(_WORD *)(v40 + 146) = 0;
              *(_QWORD *)(v40 + 24) = 0;
              *(_BYTE *)(v40 + 154) = a6;
              *(_QWORD *)(v40 + 48) = v13;
              atomic_store(v40, (unsigned __int64 *)(v13 + 8LL * (unsigned __int16)a6 + 696));
              if ( v30 )
              {
                v49 = jiffies;
                v50 = _usecs_to_jiffies(v53 << 10);
                result = mod_timer(v40 + 56, v50 + v49);
                *(_QWORD *)(v40 + 136) = jiffies;
              }
              goto LABEL_63;
            }
            v47 = *(_QWORD *)(v40 + 32);
          }
          else
          {
            v47 = v42;
          }
          kfree(v47);
          kfree(*(_QWORD *)(v40 + 40));
          result = kfree(v40);
        }
        v18 = 37;
        a8 = v31;
        v12 = v38;
LABEL_65:
        LOWORD(v14) = v30;
        goto LABEL_8;
      }
      v31 = a8;
      result = drv_ampdu_action(v16, *(_QWORD *)(v13 + 80), v54);
      if ( !(_DWORD)result )
      {
LABEL_63:
        v18 = 0;
        v51 = *(_QWORD *)(v13 + 872) & ~(1LL << a6);
        *(_QWORD *)(v13 + 864) |= 1LL << a6;
        *(_QWORD *)(v13 + 872) = v51;
        *(_BYTE *)(v13 + (unsigned __int16)a6 + 824) = v12;
        goto LABEL_64;
      }
      v18 = 37;
LABEL_64:
      a8 = v31;
      goto LABEL_65;
    }
    v18 = 38;
    if ( (*(_WORD *)(result + 2924) & 0x400) != 0 && v17 >= (unsigned __int16)a7 )
      goto LABEL_25;
  }
  else
  {
    v18 = 37;
  }
LABEL_8:
  if ( (a8 & 1) == 0 )
    goto LABEL_41;
  v19 = *(_QWORD *)(v13 + 80);
  v20 = *(_QWORD *)(v19 + 1616);
  v21 = *(_QWORD *)(v20 + 96);
  result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v20 + 104) + 53), 2080);
  if ( !result )
    goto LABEL_41;
  v22 = *(int *)(v20 + 104);
  v23 = *(_QWORD *)(result + 224) + v22;
  v24 = result;
  LODWORD(v22) = *(_DWORD *)(result + 208) + v22;
  v52 = v14;
  *(_QWORD *)(result + 224) = v23;
  *(_DWORD *)(result + 208) = v22;
  v25 = ((__int64 (*)(void))skb_put)();
  *(_QWORD *)v25 = 0;
  *(_QWORD *)(v25 + 8) = 0;
  v26 = v25;
  *(_QWORD *)(v25 + 16) = 0;
  *(_DWORD *)(v25 + 4) = *(_DWORD *)(v13 + 2688);
  *(_WORD *)(v25 + 8) = *(_WORD *)(v13 + 2692);
  *(_DWORD *)(v25 + 10) = *(_DWORD *)(v19 + 5842);
  *(_WORD *)(v25 + 14) = *(_WORD *)(v19 + 5846);
  v27 = *(_DWORD *)(v19 + 4720);
  if ( v27 <= 2 )
  {
    if ( v27 == 1 )
    {
      *(_DWORD *)(v25 + 16) = *(_DWORD *)(v19 + 2346);
      v28 = (_WORD *)(v19 + 2350);
    }
    else
    {
      if ( v27 != 2 )
        goto LABEL_37;
      *(_DWORD *)(v25 + 16) = *(_DWORD *)(v19 + 4802);
      v28 = (_WORD *)(v19 + 4806);
    }
  }
  else
  {
    if ( (unsigned int)(v27 - 3) >= 2 && v27 != 7 )
      goto LABEL_37;
    v28 = (_WORD *)(v19 + 5846);
    *(_DWORD *)(v25 + 16) = *(_DWORD *)(v19 + 5842);
  }
  *(_WORD *)(v25 + 20) = *v28;
LABEL_37:
  *(_WORD *)v25 = 208;
  skb_put(v24, 9);
  *(_BYTE *)(v26 + 26) = v12;
  *(_WORD *)(v26 + 27) = v18;
  *(_WORD *)(v26 + 24) = 259;
  *(_WORD *)(v26 + 31) = v52;
  *(_WORD *)(v26 + 29) = (__PAIR64__(a6, v21) >> 30) & 0x3F | ((_WORD)v10 << 6) | 2;
  if ( a10 && (*(_BYTE *)(v13 + 2964) & 1) != 0 )
  {
    v35 = skb_put(v24, 3);
    *(_BYTE *)(v35 + 2) = 0;
    *(_WORD *)v35 = 415;
    *(_BYTE *)(v35 + 2) = *a10 & 1 | (32 * ((v10 >> 10) & 7));
  }
  result = ieee80211_tx_skb_tid(v19, v24, 7, 0xFFFFFFFFLL);
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
