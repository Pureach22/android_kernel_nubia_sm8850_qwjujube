__int64 __fastcall ieee80211_tx_ba_session_handle_start(__int64 a1, unsigned int a2)
{
  __int64 v2; // x22
  __int64 v3; // x23
  __int64 v5; // x24
  __int64 v7; // x25
  __int64 v8; // x21
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x1
  unsigned __int64 v19; // x10
  unsigned __int64 v22; // x9
  unsigned int v24; // w9
  unsigned int v25; // w9
  _QWORD v26[2]; // [xsp+8h] [xbp-28h] BYREF
  __int16 v27; // [xsp+18h] [xbp-18h]
  __int16 v28; // [xsp+1Ah] [xbp-16h]
  __int64 v29; // [xsp+1Ch] [xbp-14h]
  int v30; // [xsp+24h] [xbp-Ch]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 72);
  v2 = *(_QWORD *)(a1 + 80);
  v26[0] = 2;
  v26[1] = a1 + 2688;
  v27 = a2;
  v29 = 0;
  v30 = 0;
  if ( a2 >= 0x10 )
    goto LABEL_14;
  v5 = a1 + 904;
  v7 = (int)a2;
  v8 = *(_QWORD *)(a1 + 904 + 8LL * (int)a2);
  _X8 = (unsigned __int64 *)(v8 + 128);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
  synchronize_net();
  v28 = *(_WORD *)(a1 + 2 * v7 + 490) >> 4;
  result = drv_ampdu_action(v3, v2, v26);
  *(_WORD *)(v8 + 152) = v28;
  if ( !(_DWORD)result )
    goto LABEL_7;
  if ( (_DWORD)result != 2 )
  {
    if ( (_DWORD)result == 1 )
    {
      _X8 = (unsigned __int64 *)(v8 + 128);
      __asm { PRFM            #0x11, [X8] }
      do
        v22 = __ldxr(_X8);
      while ( __stxr(v22 | 1, _X8) );
LABEL_7:
      result = ieee80211_send_addba_with_timeout(a1, v8);
      goto LABEL_13;
    }
    raw_spin_lock_bh(a1 + 148);
    ieee80211_agg_splice_packets(v2, v8, a2);
    atomic_store(0, (unsigned __int64 *)(v5 + 8LL * a2));
    v10 = ieee802_1d_to_ac[a2 & 7];
    if ( (unsigned int)v10 < 4 )
    {
      v11 = *(unsigned __int8 *)(v2 + v10 + 5850);
      if ( (unsigned int)v11 <= 0x10 )
      {
        _X8 = (unsigned int *)(*(_QWORD *)(v2 + 1616) + 4LL * *(unsigned __int8 *)(v2 + v10 + 5850) + 2464);
        __asm { PRFM            #0x11, [X8] }
        do
        {
          v24 = __ldxr(_X8);
          v25 = v24 - 1;
        }
        while ( __stlxr(v25, _X8) );
        __dmb(0xBu);
        if ( !v25 )
          ieee80211_wake_queue_by_reason(*(_QWORD *)(v2 + 1616), v11, 3, 0);
        raw_spin_unlock_bh(a1 + 148);
        result = ieee80211_agg_start_txq(a1, a2, 0);
        if ( v8 )
          result = kvfree_call_rcu(v8, v8);
        goto LABEL_13;
      }
    }
LABEL_14:
    __break(0x5512u);
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
