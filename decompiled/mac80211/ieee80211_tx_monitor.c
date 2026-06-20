__int64 __fastcall ieee80211_tx_monitor(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  char v5; // w20
  char v6; // w22
  __int64 v7; // x19
  __int16 *v9; // x8
  __int16 v10; // w8
  int v11; // w9
  unsigned int v12; // w24
  unsigned int v13; // w9
  unsigned int v14; // w8
  unsigned int v15; // w10
  bool v16; // zf
  __int64 v17; // x26
  __int64 v18; // x25
  __int64 v19; // x23
  void *v20; // x0
  __int64 v21; // x1
  __int64 v22; // x8
  int v23; // w9
  __int16 v24; // w9
  unsigned int v25; // w10
  _BYTE *v26; // x9
  __int16 v27; // w10
  unsigned __int64 v28; // x8
  __int16 v29; // w10
  __int16 v30; // w9
  __int16 v31; // w10
  __int16 v32; // w9
  __int16 v33; // w10
  __int16 v34; // w9
  int v35; // w10
  __int16 v36; // w10
  unsigned __int64 v37; // x8
  unsigned int v38; // w9
  char v39; // w9
  __int16 v40; // w10
  unsigned __int64 v41; // x9
  char v42; // w9
  unsigned int v43; // w9
  int v44; // w10
  __int16 v45; // w9
  __int16 v46; // w8
  __int16 v47; // w9
  __int16 v48; // w8
  __int64 lock; // x0
  __int64 *v50; // x22
  __int64 *v51; // x21
  __int64 v52; // x23

  v5 = a4;
  v6 = a3;
  v7 = a2;
  if ( !a5
    || !*(_BYTE *)(a5 + 40)
    || (v9 = (__int16 *)(*(_QWORD *)(a5 + 24) + 16LL * ((unsigned int)*(unsigned __int8 *)(a5 + 40) - 1))) == nullptr )
  {
    v12 = 11;
    if ( *(char *)(a2 + 48) < 0 )
      goto LABEL_24;
    v13 = *(unsigned __int16 *)(a2 + 49);
    v14 = v13 >> 5;
    if ( (v13 & 0x2100) != 0 )
      v11 = 11;
    else
      v11 = 13;
    if ( (v14 & 8) == 0 )
    {
      v15 = v11 + 13;
      v16 = (v14 & 0x100) == 0;
      goto LABEL_20;
    }
    goto LABEL_23;
  }
  v10 = *v9;
  if ( (v10 & 0x3B) != 0 )
  {
    v11 = 11;
    if ( (*(char *)(a2 + 48) & 0x80000000) == 0 )
    {
      if ( (*(_WORD *)(a2 + 49) & 0x2100) != 0 )
        v11 = 11;
      else
        v11 = 13;
    }
    if ( (v10 & 1) == 0 )
      goto LABEL_18;
LABEL_23:
    v12 = v11 + 3;
    goto LABEL_24;
  }
  v11 = 13;
  if ( (v10 & 1) != 0 )
    goto LABEL_23;
LABEL_18:
  if ( (v10 & 2) != 0 )
  {
    v12 = v11 + 13;
    goto LABEL_24;
  }
  v15 = v11 + 13;
  v16 = (v10 & 0x10) == 0;
LABEL_20:
  if ( v16 )
    v12 = v11;
  else
    v12 = v15;
LABEL_24:
  v17 = *(_QWORD *)(a2 + 224);
  if ( v12 > (int)v17 - *(_DWORD *)(a2 + 216) )
  {
    __break(0x800u);
    printk(&unk_B7AE0, a2, a3, a4);
    return consume_skb(v7);
  }
  if ( a5 && *(_BYTE *)(a5 + 40) )
    v18 = *(_QWORD *)(a5 + 24) + 16LL * ((unsigned int)*(unsigned __int8 *)(a5 + 40) - 1);
  else
    v18 = 0;
  v19 = skb_push(a2, v12);
  v20 = memset((void *)v19, 0, v12);
  v22 = v19 + 8;
  *(_WORD *)(v19 + 2) = v12;
  *(_DWORD *)(v19 + 4) = 163840;
  if ( v18 )
  {
    if ( (*(_WORD *)v18 & 0x3B) != 0 )
      goto LABEL_38;
    v23 = *(unsigned __int16 *)(v18 + 2);
    if ( !*(_WORD *)(v18 + 2) )
      goto LABEL_38;
LABEL_37:
    *(_DWORD *)(v19 + 4) = 163844;
    *(_BYTE *)(v19 + 8) = (858993460 * (unsigned __int64)(unsigned int)(v23 + 4)) >> 32;
    v22 = v19 + 10;
LABEL_38:
    v24 = (*(_BYTE *)(v7 + 41) & 2) == 0 && (*(_WORD *)(v17 + 4) & 1) == 0;
    v25 = *(unsigned __int16 *)(v7 + 49);
    *(_BYTE *)(v22 + 2) = v6;
    *(_WORD *)v22 = (v25 >> 5) & 2 | v24 | (v25 >> 3) & 4;
    v26 = (_BYTE *)(v22 + 3);
    if ( v18 )
    {
      v27 = *(_WORD *)v18;
      if ( (*(_WORD *)v18 & 1) != 0 )
      {
        *(_DWORD *)(v19 + 4) |= 0x80000u;
        *v26 = 7;
        if ( (*(_WORD *)v18 & 4) != 0 )
          *(_BYTE *)(v22 + 4) |= 4u;
        if ( *(_BYTE *)(v18 + 6) == 3 )
          *(_BYTE *)(v22 + 4) |= 1u;
        *(_BYTE *)(v22 + 5) = *(_BYTE *)(v18 + 4);
        goto LABEL_87;
      }
      if ( (v27 & 2) == 0 )
      {
        if ( (v27 & 0x10) != 0 )
        {
          *(_DWORD *)(v19 + 4) |= 0x800000u;
          v28 = v19 + ((unsigned __int64)&v26[-v19 + 1] & 0xFFFFFFFFFFFFFFFELL);
          v29 = *(_WORD *)(v28 + 10);
          *(_DWORD *)v28 = 147552;
          v30 = v29 | *(_BYTE *)(v18 + 5) & 0xF;
          v31 = *(_WORD *)(v28 + 4);
          *(_WORD *)(v28 + 10) = v30;
          v32 = v31 | ((*(_BYTE *)(v18 + 4) & 0xF) << 8);
          *(_WORD *)(v28 + 4) = v32;
          v33 = *(_WORD *)(v28 + 8);
          *(_WORD *)(v28 + 4) = v32 | ((*(_BYTE *)(v18 + 8) & 1) << 12);
          v34 = v33 | (16 * (*(_BYTE *)(v18 + 7) & 3));
          *(_WORD *)(v28 + 8) = v34;
          v21 = *(unsigned __int8 *)(v18 + 6);
          if ( *(unsigned __int8 *)(v18 + 6) <= 3u )
          {
            if ( !*(_BYTE *)(v18 + 6) )
              goto LABEL_87;
            if ( (_DWORD)v21 == 3 )
            {
              *(_WORD *)(v28 + 8) = v34 | 1;
              goto LABEL_87;
            }
          }
          else
          {
            switch ( (_DWORD)v21 )
            {
              case 4:
                *(_WORD *)(v28 + 8) = v34 | 2;
                goto LABEL_87;
              case 5:
                *(_WORD *)(v28 + 8) = v34 | 3;
                goto LABEL_87;
              case 6:
                *(_WORD *)(v28 + 8) = v34 | (*(_BYTE *)(v18 + 9) + 4) & 0xF;
                goto LABEL_87;
            }
          }
          if ( (ieee80211_add_tx_radiotap_header___already_done & 1) == 0 )
          {
            ieee80211_add_tx_radiotap_header___already_done = 1;
            v20 = (void *)_warn_printk("Invalid SU BW %d\n", v21);
            __break(0x800u);
          }
        }
LABEL_87:
        v46 = *(_DWORD *)(v7 + 224);
        v47 = *(_DWORD *)(v7 + 216);
        *(_WORD *)(v7 + 180) = 1024;
        v48 = v46 - v47;
        LOBYTE(v47) = *(_BYTE *)(v7 + 128);
        *(_QWORD *)(v7 + 40) = 0;
        *(_QWORD *)(v7 + 48) = 0;
        *(_WORD *)(v7 + 186) = v48;
        *(_QWORD *)(v7 + 56) = 0;
        *(_QWORD *)(v7 + 64) = 0;
        *(_QWORD *)(v7 + 72) = 0;
        *(_QWORD *)(v7 + 80) = 0;
        *(_BYTE *)(v7 + 128) = v47 & 0x98 | 0x23;
        lock = _rcu_read_lock(v20, v21);
        v50 = *(__int64 **)(a1 + 4616);
        v51 = (__int64 *)(a1 + 4616);
        if ( v50 != v51 )
        {
          v52 = 0;
          do
          {
            if ( *((_DWORD *)v50 + 1180) == 6 && (v50[204] & 1) != 0 && ((v50[283] & 0x20) == 0 || (v5 & 1) != 0) )
            {
              if ( v52 )
              {
                lock = skb_clone(v7, 2080);
                if ( lock )
                {
                  *(_QWORD *)(lock + 16) = v52;
                  lock = ((__int64 (*)(void))netif_rx)();
                }
              }
              v52 = v50[201];
            }
            v50 = (__int64 *)*v50;
          }
          while ( v50 != v51 );
          if ( v52 )
          {
            *(_QWORD *)(v7 + 16) = v52;
            lock = netif_rx(v7);
            v7 = 0;
          }
        }
        _rcu_read_unlock(lock);
        return consume_skb(v7);
      }
      v40 = *(_WORD *)(a1 + 144) & 0x44;
      *(_DWORD *)(v19 + 4) |= 0x200000u;
      v37 = v19 + ((unsigned __int64)&v26[-v19 + 1] & 0xFFFFFFFFFFFFFFFELL);
      *(_WORD *)v37 = v40;
      if ( (*(_WORD *)v18 & 4) != 0 )
        *(_BYTE *)(v37 + 2) |= 4u;
      v41 = *(unsigned __int8 *)(v18 + 6);
      if ( v41 >= 6 )
        v42 = 0;
      else
        v42 = 0xB0401000000uLL >> (8 * (unsigned __int8)v41);
      *(_BYTE *)(v37 + 3) = v42;
      LOBYTE(v43) = *(_BYTE *)(v18 + 4);
      LOBYTE(v44) = *(_BYTE *)(v18 + 5);
LABEL_86:
      *(_BYTE *)(v37 + 4) = v44 | (16 * v43);
      goto LABEL_87;
    }
    if ( *(char *)(v7 + 48) < 0 )
      goto LABEL_87;
    v35 = *(unsigned __int16 *)(v7 + 49) >> 5;
    if ( (v35 & 8) == 0 )
    {
      if ( (v35 & 0x100) == 0 )
        goto LABEL_87;
      v36 = *(_WORD *)(a1 + 144) & 0x44;
      *(_DWORD *)(v19 + 4) |= 0x200000u;
      v37 = v19 + ((unsigned __int64)&v26[-v19 + 1] & 0xFFFFFFFFFFFFFFFELL);
      *(_WORD *)v37 = v36;
      v38 = *(unsigned __int16 *)(v7 + 49);
      if ( (v38 & 0x1000) != 0 )
      {
        *(_BYTE *)(v37 + 2) |= 4u;
        v38 = *(unsigned __int16 *)(v7 + 49);
      }
      if ( ((v38 >> 5) & 0x20) != 0 )
      {
        v39 = 1;
      }
      else if ( ((v38 >> 5) & 0x200) != 0 )
      {
        v39 = 4;
      }
      else if ( (v38 & 0x8000u) != 0 )
      {
        v39 = 11;
      }
      else
      {
        v39 = 0;
      }
      *(_BYTE *)(v37 + 3) = v39;
      v43 = *(char *)(v7 + 48);
      v44 = (v43 >> 4) + 1;
      goto LABEL_86;
    }
    *(_DWORD *)(v19 + 4) |= 0x80000u;
    *v26 = 7;
    v45 = *(_WORD *)(v7 + 49);
    if ( (v45 & 0x1000) != 0 )
    {
      *(_BYTE *)(v22 + 4) |= 4u;
      v45 = *(_WORD *)(v7 + 49);
      if ( (v45 & 0x400) == 0 )
      {
LABEL_73:
        if ( (v45 & 0x200) == 0 )
        {
LABEL_75:
          *(_BYTE *)(v22 + 5) = *(_BYTE *)(v7 + 48);
          goto LABEL_87;
        }
LABEL_74:
        *(_BYTE *)(v22 + 4) |= 8u;
        goto LABEL_75;
      }
    }
    else if ( (*(_WORD *)(v7 + 49) & 0x400) == 0 )
    {
      goto LABEL_73;
    }
    *(_BYTE *)(v22 + 4) |= 1u;
    if ( (*(_WORD *)(v7 + 49) & 0x200) == 0 )
      goto LABEL_75;
    goto LABEL_74;
  }
  if ( (*(char *)(v7 + 48) & 0x8000000000000000LL) != 0 || (*(_WORD *)(v7 + 49) & 0x2100) != 0 )
    goto LABEL_38;
  if ( (*(_DWORD *)(v7 + 44) & 7u) <= 5 )
  {
    v23 = *(unsigned __int16 *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 8LL * (*(_DWORD *)(v7 + 44) & 7) + 328)
                                          + 8LL)
                              + 12LL * *(char *)(v7 + 48)
                              + 4);
    if ( !*(_WORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 8LL * (*(_DWORD *)(v7 + 44) & 7) + 328) + 8LL)
                   + 12LL * *(char *)(v7 + 48)
                   + 4) )
      goto LABEL_38;
    goto LABEL_37;
  }
  __break(0x5512u);
  return ieee80211_tx_status_skb(v20, v21);
}
