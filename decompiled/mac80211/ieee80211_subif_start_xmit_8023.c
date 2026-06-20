__int64 __fastcall ieee80211_subif_start_xmit_8023(__int64 a1, __int64 a2)
{
  __int64 v2; // x24
  __int64 v3; // x25
  __int64 v4; // x26
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x8
  __int64 v9; // x19
  __int64 v10; // x0
  __int64 started; // x0
  _BYTE *v12; // x20
  unsigned __int64 v13; // x8
  char v15; // w27
  __int64 v16; // x8
  __int64 v17; // x23
  int v18; // w9
  _BYTE **v19; // x8
  int v20; // w8
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 *v23; // x8
  __int64 v24; // x1
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // x9
  __int64 v28; // x11
  __int64 v29; // x12
  __int64 v30; // x8
  _BYTE *v31; // x8
  __int64 v32; // x10
  __int16 v33; // w0
  unsigned int v34; // w8
  unsigned __int64 v41; // x10
  unsigned __int64 v44; // x9
  unsigned __int64 v45[2]; // [xsp+0h] [xbp-10h] BYREF

  v5 = a1;
  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 224);
  v7 = *(_QWORD *)(a2 + 4320);
  v45[0] = 0;
  if ( (v7 & 1) == 0 || *(_DWORD *)(a1 + 112) <= 0xDu )
  {
    sk_skb_reason_drop(0);
    goto LABEL_18;
  }
  v9 = a2 + 2688;
  _rcu_read_lock(a1, a2);
  if ( (unsigned int)ieee80211_lookup_ra_sta(v9, v5, v45) )
    goto LABEL_4;
  v12 = (_BYTE *)v45[0];
  if ( !v45[0]
    || v45[0] > 0xFFFFFFFFFFFFF000LL
    || *(_BYTE *)(v45[0] + 204) != 1
    || (*(_QWORD *)(v45[0] + 216) & 8) == 0
    || *(unsigned __int16 *)(a2 + 4628) == *(unsigned __int16 *)(v6 + 12) )
  {
LABEL_16:
    started = ieee80211_subif_start_xmit(v5, a2);
    goto LABEL_17;
  }
  v13 = *(unsigned __int8 *)(v45[0] + 120);
  if ( v13 >= 5 )
    goto LABEL_68;
  v4 = *(_QWORD *)(v45[0] + 8 * v13 + 88);
  if ( v4 || (v4 = *(_QWORD *)(a2 + 4616)) != 0 )
  {
    if ( (*(_BYTE *)(v4 + 40) & 1) == 0 || *(_DWORD *)(v4 + 544) == 1027074 )
      goto LABEL_16;
    v15 = 0;
  }
  else
  {
    v15 = 1;
  }
  v16 = *(_QWORD *)(v5 + 24);
  v17 = *(_QWORD *)(a2 + 4304);
  if ( v16 )
  {
    v18 = *(unsigned __int8 *)(v17 + 171);
    if ( ((1 << *(_BYTE *)(v16 + 18)) & 0xFFFFEFBF) != 0 && *(unsigned __int8 *)(v16 + 560) != v18 )
    {
      *(_BYTE *)(v16 + 560) = v18;
      v17 = *(_QWORD *)(a2 + 4304);
    }
  }
  started = ((__int64 (__fastcall *)(__int64, _BYTE *, __int64))ieee80211_select_queue)(v9, v12, v5);
  *(_WORD *)(v5 + 124) = started;
  v2 = (unsigned int)started;
  if ( (*(_QWORD *)(v17 + 4696) & 1) == 0 || (*(_QWORD *)(a2 + 4320) & 2) == 0 )
  {
    if ( *(_DWORD *)(v5 + 236) == 1 )
    {
      if ( !v5 )
        goto LABEL_17;
    }
    else
    {
      v10 = skb_clone(v5, 2080);
      if ( !v10 )
        goto LABEL_5;
      v3 = v10;
      consume_skb(v5);
      v5 = v3;
    }
    v19 = *(_BYTE ***)(*(_QWORD *)(a2 + 4304) + 2536LL);
    if ( v19 )
    {
      if ( (**v19 & 2) != 0 && v12[2926] == 1 && v12[2698] == 1 )
      {
        if ( *(_WORD *)(v5 + 124) )
        {
          if ( *(unsigned __int16 *)(v5 + 180) != *(unsigned __int16 *)(a2 + 4628) )
          {
            v20 = *(_DWORD *)(v5 + 144);
            if ( !*(_QWORD *)&v12[8 * (v20 & 0xF) + 904] )
              ieee80211_start_tx_ba_session(v12 + 2688, v20 & 0xF, 0);
          }
        }
      }
    }
    v21 = *(_QWORD *)&v12[8 * (*(_DWORD *)(v5 + 144) & 7) + 904];
    if ( v21 )
    {
      if ( (*(_QWORD *)(v21 + 128) & 4) == 0 )
      {
        started = _ieee80211_subif_start_xmit(v5, a2, 0, 0xF0000000, 0);
        goto LABEL_17;
      }
      if ( *(_WORD *)(v21 + 144) )
        *(_QWORD *)(v21 + 136) = jiffies;
    }
    if ( *(_DWORD *)(a2 + 7408) == 4 )
    {
      v22 = *(_QWORD *)(a2 + 4720);
      if ( !v22 )
      {
        v24 = 0;
LABEL_49:
        started = ieee80211_tx_skb_fixup(v5, v24);
        if ( !started )
          goto LABEL_17;
        v13 = (unsigned __int16)v2;
        v5 = started;
        *(_QWORD *)(started + 40) = 0;
        *(_QWORD *)(started + 72) = 0;
        *(_QWORD *)(started + 80) = 0;
        *(_QWORD *)(started + 56) = 0;
        *(_QWORD *)(started + 64) = 0;
        *(_QWORD *)(started + 48) = 0;
        if ( (unsigned __int16)v2 <= 3u )
        {
          v2 = (unsigned __int16)v2;
          *(_DWORD *)(started + 44) = (*(_BYTE *)(a2 + (unsigned __int16)v2 + 8538) & 0xF) << 17;
          if ( *(_DWORD *)(a2 + 7408) == 4 )
            v9 = *(_QWORD *)(a2 + 4720) - 2264LL;
          *(_DWORD *)(started + 40) = 0x4000;
          *(_QWORD *)(started + 64) = v9 + 4720;
          if ( (v15 & 1) == 0 )
            *(_QWORD *)(started + 72) = v4 + 536;
          LODWORD(v4) = 0;
          LODWORD(v3) = 0;
          v25 = started;
          do
          {
            if ( v25 != started )
            {
              v26 = *(_QWORD *)(started + 48);
              *(_QWORD *)(v25 + 40) = *(_QWORD *)(started + 40);
              *(_QWORD *)(v25 + 48) = v26;
              v27 = *(_QWORD *)(started + 80);
              v28 = *(_QWORD *)(started + 56);
              v29 = *(_QWORD *)(started + 64);
              *(_QWORD *)(v25 + 72) = *(_QWORD *)(started + 72);
              *(_QWORD *)(v25 + 80) = v27;
              *(_QWORD *)(v25 + 56) = v28;
              *(_QWORD *)(v25 + 64) = v29;
            }
            v4 = (unsigned int)(v4 + 1);
            v3 = (unsigned int)(*(_DWORD *)(v25 + 112) + v3);
            v25 = *(_QWORD *)v25;
          }
          while ( v25 );
          if ( *(_QWORD *)(started + 24) )
          {
            if ( (*(_BYTE *)(*(_QWORD *)(started + 216) + *(unsigned int *)(started + 212) + 3LL) & 0x10) != 0 )
            {
              v33 = ieee80211_store_ack_skb(v17, started);
              v34 = *(_DWORD *)(v5 + 44) & 0xFFFE000F | (16 * (v33 & 0x1FFF));
              *(_DWORD *)(v5 + 44) = v34;
              if ( (v33 & 0x1FFF) != 0 )
                *(_DWORD *)(v5 + 44) = v34 | 8;
            }
          }
          v30 = *(_QWORD *)(a2 + 160);
          v13 = _ReadStatusReg(TPIDR_EL1) + v30;
          goto LABEL_69;
        }
LABEL_68:
        __break(0x5512u);
LABEL_69:
        _X9 = (unsigned __int64 *)(v13 + 24);
        __asm { PRFM            #0x11, [X9] }
        do
          v41 = __ldxr(_X9);
        while ( __stxr(v41 + v3, _X9) );
        _X8 = (unsigned __int64 *)(v13 + 16);
        __asm { PRFM            #0x11, [X8] }
        do
          v44 = __ldxr(_X8);
        while ( __stxr(v44 + v4, _X8) );
        v31 = &v12[8 * v2];
        v32 = *((_QWORD *)v31 + 295) + v3;
        *((_QWORD *)v31 + 291) += v4;
        *((_QWORD *)v31 + 295) = v32;
        started = ieee80211_tx_8023(v9, v5, v12, 0);
        goto LABEL_17;
      }
      v23 = (__int64 *)(v22 + 3600);
    }
    else
    {
      v23 = (__int64 *)(a2 + 8552);
    }
    v24 = *v23;
    goto LABEL_49;
  }
LABEL_4:
  v10 = 0;
LABEL_5:
  started = sk_skb_reason_drop(v10);
LABEL_17:
  _rcu_read_unlock(started);
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return 0;
}
