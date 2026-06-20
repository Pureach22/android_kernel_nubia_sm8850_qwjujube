__int64 __fastcall ieee80211_ba_session_work(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x21
  _QWORD *v5; // x27
  __int64 v6; // x22
  __int64 result; // x0
  __int64 v10; // x23
  __int64 v11; // x8
  _QWORD *v12; // x24
  unsigned __int64 v13; // x23
  __int64 v14; // x26
  _QWORD *v15; // x27
  unsigned __int64 *v16; // x21
  __int64 v17; // x22
  __int64 v18; // x25
  __int64 v19; // x19
  _QWORD *v20; // t1
  __int64 v21; // x8
  __int64 v22; // x23
  unsigned __int64 v28; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v33; // x9
  unsigned __int64 v36; // x8
  unsigned __int64 v39; // x9
  unsigned __int64 v42; // x8
  unsigned __int64 v45; // x8
  unsigned __int64 v48; // x8
  __int64 v49; // x0
  unsigned __int64 *v50; // [xsp+10h] [xbp-20h]
  __int16 v51; // [xsp+18h] [xbp-18h]
  __int64 v52; // [xsp+20h] [xbp-10h]
  unsigned __int64 *v53; // [xsp+28h] [xbp-8h]

  v2 = a2;
  v3 = 0;
  v4 = *(_QWORD *)(a2 - 664);
  v5 = (_QWORD *)(a2 - 880);
  v6 = a2 - 732;
  _X25 = (unsigned __int64 *)(a2 - 40);
  _X26 = (unsigned __int64 *)(a2 - 32);
  v50 = (unsigned __int64 *)(a2 - 32);
  v51 = v4;
  v52 = a2 - 732;
  v53 = (unsigned __int64 *)(a2 - 24);
  while ( 1 )
  {
    v10 = 1LL << v3;
    __asm { PRFM            #0x11, [X25] }
    do
      v28 = __ldxr(_X25);
    while ( __stlxr(v28 & ~v10, _X25) );
    __dmb(0xBu);
    if ( (v28 & v10) != 0 )
      _ieee80211_stop_rx_ba_session(v5, v3, 0, 0x27u, 1);
    __asm { PRFM            #0x11, [X26] }
    do
      v30 = __ldxr(_X26);
    while ( __stlxr(v30 & ~v10, _X26) );
    __dmb(0xBu);
    if ( (v30 & v10) != 0 )
      _ieee80211_stop_rx_ba_session(v5, v3, 0, 1u, 1);
    if ( (v4 & 0x100) == 0 )
    {
      _X11 = v53;
      __asm { PRFM            #0x11, [X11] }
      do
        v36 = __ldxr(v53);
      while ( __stlxr(v36 & ~v10, v53) );
      __dmb(0xBu);
      if ( (v36 & v10) != 0 )
        _ieee80211_start_rx_ba_session((__int64)v5, 0, 0, 0, 1, v3, 0x40u, 0, 1, nullptr);
    }
    v11 = 0x10000LL << v3;
    _X12 = v53;
    __asm { PRFM            #0x11, [X12] }
    do
      v33 = __ldxr(v53);
    while ( __stlxr(v33 & ~v11, v53) );
    __dmb(0xBu);
    if ( (v33 & v11) != 0 )
      _ieee80211_stop_rx_ba_session(v5, v3, 0, 0, 0);
    raw_spin_lock_bh(v6);
    v12 = (_QWORD *)(v2 + 8 * v3);
    if ( (v4 & 0x100) != 0 || (v13 = v12[19]) == 0 )
    {
      result = raw_spin_unlock_bh(v6);
      v22 = v12[3];
      if ( v22 )
      {
        if ( (v4 & 0x100) == 0 )
        {
          _X9 = (unsigned __int64 *)(v22 + 128);
          __asm { PRFM            #0x11, [X9] }
          do
            v48 = __ldxr(_X9);
          while ( __stlxr(v48 & 0xFFFFFFFFFFFFFFBFLL, _X9) );
          __dmb(0xBu);
          if ( (v48 & 0x40) != 0 )
            result = ieee80211_start_tx_ba_cb((__int64)v5, v3, v22);
        }
        _X9 = (unsigned __int64 *)(v22 + 128);
        __asm { PRFM            #0x11, [X9] }
        do
          v42 = __ldxr(_X9);
        while ( __stlxr(v42 & 0xFFFFFFFFFFFFFFDFLL, _X9) );
        __dmb(0xBu);
        if ( (v42 & 0x20) != 0 )
          result = _ieee80211_stop_tx_ba_session((__int64)v5, v3, 1u);
        _X9 = (unsigned __int64 *)(v22 + 128);
        __asm { PRFM            #0x11, [X9] }
        do
          v45 = __ldxr(_X9);
        while ( __stlxr(v45 & 0xFFFFFFFFFFFFFF7FLL, _X9) );
        __dmb(0xBu);
        if ( (v45 & 0x80) != 0 )
          result = ieee80211_stop_tx_ba_cb((__int64)v5, v3, v22);
      }
      goto LABEL_4;
    }
    v14 = (__int64)v5;
    v15 = (_QWORD *)v12[232];
    v16 = _X25;
    v17 = v2;
    v18 = *v15 - 3104LL;
    v19 = *(_QWORD *)v18;
    raw_spin_lock_bh(*(_QWORD *)v18 + 240LL);
    _X8 = v15 - 1;
    __asm { PRFM            #0x11, [X8] }
    do
      v39 = __ldxr(_X8);
    while ( __stxr(v39 | 1, _X8) );
    v20 = (_QWORD *)*(v15 - 4);
    raw_spin_unlock_bh(v19 + 240);
    if ( v20 != v15 - 4 )
      break;
    v21 = v12[3];
    v2 = v17;
    v12[19] = 0;
    if ( v21 )
    {
      kfree(v13);
      v6 = v52;
      _X25 = v16;
      v5 = (_QWORD *)v14;
    }
    else
    {
      v5 = (_QWORD *)v14;
      ieee80211_assign_tid_tx(v14, v3, v13);
      v6 = v52;
      _X25 = v16;
    }
    raw_spin_unlock_bh(v6);
    result = ieee80211_tx_ba_session_handle_start((__int64)v5, v3);
    _X26 = v50;
    LOWORD(v4) = v51;
LABEL_4:
    if ( ++v3 == 16 )
      return result;
  }
  v49 = raw_spin_unlock_bh(v52);
  synchronize_net(v49);
  return wiphy_work_queue(*(_QWORD *)(*(_QWORD *)v18 + 72LL), v17);
}
