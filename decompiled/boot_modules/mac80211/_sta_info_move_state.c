__int64 __fastcall sta_info_move_state(__int64 a1, int a2, char a3)
{
  int v3; // w3
  unsigned int v4; // w8
  __int64 v5; // x19
  __int64 v6; // x20
  int v7; // w21
  char v8; // w22
  unsigned int v9; // w0
  int v10; // w8
  __int64 v11; // x19
  __int64 v12; // x1
  __int64 v13; // x8
  int v14; // w19
  __int64 v15; // x20
  int v16; // w8
  char v17; // w19
  __int64 v18; // x21
  __int64 v19; // x8
  __int64 v20; // x19
  int v21; // w20
  __int64 v22; // x20
  unsigned int *v23; // x0
  __int64 v24; // x1
  unsigned __int64 v28; // x9
  unsigned __int64 v31; // x10
  unsigned __int64 v38; // x9
  unsigned __int64 v41; // x9
  unsigned __int64 v44; // x10
  unsigned __int64 v47; // x11

  v3 = *(_DWORD *)(a1 + 208);
  if ( v3 == a2 )
    return 0;
  v5 = *(_QWORD *)(a1 + 72);
  if ( a2 > 2 )
  {
    if ( a2 == 3 )
    {
      if ( v3 != 2 && v3 != 4 )
        return (unsigned int)-22;
      goto LABEL_17;
    }
    if ( a2 != 4 )
    {
LABEL_12:
      _warn_printk("invalid state %d", a2);
      __break(0x800u);
      return (unsigned int)-22;
    }
    if ( v3 == 3 )
      goto LABEL_17;
    return (unsigned int)-22;
  }
  if ( a2 == 1 )
  {
    if ( v3 == 2 )
      goto LABEL_17;
    return (unsigned int)-22;
  }
  if ( a2 != 2 )
    goto LABEL_12;
  if ( (v3 | 2) != 3 )
    return (unsigned int)-22;
LABEL_17:
  if ( (*(_QWORD *)(a1 + 216) & 0x100000) == 0 )
    goto LABEL_19;
  v6 = a1;
  v7 = a2;
  v8 = a3;
  v9 = drv_sta_state(*(_QWORD *)(a1 + 72), *(_QWORD *)(a1 + 80), a1, v3, a2);
  a3 = v8;
  a2 = v7;
  v4 = v9;
  a1 = v6;
  if ( !v4 )
  {
LABEL_19:
    if ( a2 > 2 )
    {
      if ( a2 != 3 )
      {
        if ( *(_DWORD *)(a1 + 208) == 3 )
        {
          v11 = a1;
          ieee80211_vif_inc_num_mcast(*(unsigned int **)(a1 + 80));
          _X8 = (unsigned __int64 *)(v11 + 216);
          __asm { PRFM            #0x11, [X8] }
          do
            v28 = __ldxr(_X8);
          while ( __stxr(v28 | 8, _X8) );
          ieee80211_check_fast_xmit(v11);
          ieee80211_check_fast_rx(v11, v12);
          a1 = v11;
          a2 = 4;
        }
        v13 = *(_QWORD *)(a1 + 80);
        if ( (unsigned int)(*(_DWORD *)(v13 + 4720) - 3) <= 1 )
        {
          v14 = a2;
          v15 = a1;
          cfg80211_send_layer2_update(*(_QWORD *)(v13 + 1608), a1 + 2688);
          a1 = v15;
          a2 = v14;
        }
        goto LABEL_46;
      }
      v16 = *(_DWORD *)(a1 + 208);
      if ( v16 == 4 )
      {
        v22 = a1;
        v23 = ieee80211_vif_dec_num_mcast(*(unsigned int **)(a1 + 80));
        _X9 = (unsigned __int64 *)(v22 + 216);
        __asm { PRFM            #0x11, [X9] }
        do
          v47 = __ldxr(_X9);
        while ( __stxr(v47 & 0xFFFFFFFFFFFFFFF7LL, _X9) );
        if ( *(_QWORD *)(*(_QWORD *)(v5 + 464) + 152LL) )
        {
          synchronize_net(v23);
          v24 = *(_QWORD *)(v22 + 80);
          if ( *(_QWORD *)(*(_QWORD *)(v5 + 464) + 440LL) )
            drv_flush_sta(v5, v24, v22);
          else
            ieee80211_flush_queues(v5, v24, 0);
        }
        ieee80211_clear_fast_xmit(v22);
        ieee80211_clear_fast_rx(v22);
        a1 = v22;
        a2 = 3;
        goto LABEL_46;
      }
      if ( v16 != 2 )
        goto LABEL_46;
      _X8 = (unsigned __int64 *)(a1 + 216);
      __asm { PRFM            #0x11, [X8] }
      do
        v41 = __ldxr(_X8);
      while ( __stxr(v41 | 2, _X8) );
      v17 = a3;
      v18 = a1;
      v19 = ktime_get_with_offset(1);
      a1 = v18;
      a2 = 3;
      *(_QWORD *)(v18 + 440) = v19;
      if ( (v17 & 1) == 0 )
        goto LABEL_46;
    }
    else
    {
      if ( a2 == 1 )
      {
        if ( *(_DWORD *)(a1 + 208) == 2 )
        {
          _X8 = (unsigned __int64 *)(a1 + 216);
          __asm { PRFM            #0x11, [X8] }
          do
            v31 = __ldxr(_X8);
          while ( __stxr(v31 & 0xFFFFFFFFFFFFFFFELL, _X8) );
        }
        goto LABEL_46;
      }
      v10 = *(_DWORD *)(a1 + 208);
      if ( v10 != 3 )
      {
        if ( v10 == 1 )
        {
          _X8 = (unsigned __int64 *)(a1 + 216);
          __asm { PRFM            #0x11, [X8] }
          do
            v38 = __ldxr(_X8);
          while ( __stxr(v38 | 1, _X8) );
        }
        goto LABEL_46;
      }
      _X8 = (unsigned __int64 *)(a1 + 216);
      __asm { PRFM            #0x11, [X8] }
      do
        v44 = __ldxr(_X8);
      while ( __stxr(v44 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      if ( (a3 & 1) == 0 )
      {
LABEL_46:
        v4 = 0;
        *(_DWORD *)(a1 + 208) = a2;
        return v4;
      }
    }
    v20 = a1;
    v21 = a2;
    ieee80211_recalc_min_chandef(*(_QWORD *)(a1 + 80), 0xFFFFFFFFLL);
    a1 = v20;
    a2 = v21;
    if ( (*(_BYTE *)(v20 + 2728) & 1) == 0 )
    {
      ieee80211_recalc_p2p_go_ps_allowed(*(_QWORD *)(v20 + 80));
      a1 = v20;
      a2 = v21;
    }
    goto LABEL_46;
  }
  return v4;
}
