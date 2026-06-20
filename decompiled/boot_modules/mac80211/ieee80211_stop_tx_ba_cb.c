__int64 __fastcall ieee80211_stop_tx_ba_cb(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 v7; // x1
  __int64 result; // x0
  unsigned __int64 v10; // x8
  char v11; // w23
  __int64 v12; // x8
  unsigned __int64 *v13; // x24
  unsigned int v19; // w10
  unsigned int v20; // w10

  v4 = *(_QWORD *)(a1 + 80);
  raw_spin_lock_bh(a1 + 148);
  if ( (*(_QWORD *)(a3 + 128) & 8) == 0 )
    return raw_spin_unlock_bh(a1 + 148);
  v10 = *(unsigned __int8 *)(a3 + 147);
  if ( (_DWORD)v10 == 1 )
    v11 = *(_BYTE *)(a3 + 148);
  else
    v11 = 0;
  if ( a2 >= 0x10 )
    goto LABEL_15;
  v12 = a1 + 8LL * a2;
  a3 = *(_QWORD *)(v12 + 904);
  v13 = (unsigned __int64 *)(v12 + 904);
  ieee80211_agg_splice_packets(*(_QWORD *)(a1 + 80), a3, a2);
  atomic_store(0, v13);
  v10 = (unsigned __int64)ieee802_1d_to_ac;
  _X9 = ieee802_1d_to_ac[a2 & 7];
  if ( (unsigned int)_X9 >= 4
    || (v10 = *(_QWORD *)(a1 + 80), _X9 += v10, v7 = *(unsigned __int8 *)(_X9 + 5850), (unsigned int)v7 > 0x10) )
  {
LABEL_15:
    __break(0x5512u);
  }
  else
  {
    _X9 = *(_QWORD *)(v10 + 1616) + 4LL * *(unsigned __int8 *)(_X9 + 5850) + 2464;
  }
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v19 = __ldxr((unsigned int *)_X9);
    v20 = v19 - 1;
  }
  while ( __stlxr(v20, (unsigned int *)_X9) );
  __dmb(0xBu);
  if ( !v20 )
    ieee80211_wake_queue_by_reason(*(_QWORD *)(v10 + 1616), v7, 3, 0);
  if ( a3 )
    kvfree_call_rcu(a3, a3);
  raw_spin_unlock_bh(a1 + 148);
  result = ieee80211_agg_start_txq(a1, a2, 0);
  if ( (v11 & 1) != 0 )
    return ieee80211_send_delba(v4, a1 + 2688, a2, 1, 37);
  return result;
}
