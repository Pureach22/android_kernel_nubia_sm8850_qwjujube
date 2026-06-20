__int64 __fastcall ieee80211_agg_tx_operational(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  __int64 v3; // x8
  __int64 v5; // x1
  __int64 v7; // x21
  char v8; // w9
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x1
  __int64 result; // x0
  unsigned __int64 v20; // x9
  unsigned int v22; // w10
  unsigned int v23; // w10
  _QWORD v24[2]; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int16 v25; // [xsp+18h] [xbp-18h]
  _WORD v26[11]; // [xsp+1Ah] [xbp-16h]

  *(_QWORD *)&v26[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24[0] = 6;
  v24[1] = a2 + 2688;
  v25 = a3;
  *(_QWORD *)v26 = 0;
  *(_QWORD *)&v26[3] = 0;
  if ( a3 >= 0x10u )
    goto LABEL_7;
  v3 = a2 + 8LL * a3;
  v5 = *(_QWORD *)(a2 + 80);
  v7 = *(_QWORD *)(v3 + 904);
  v8 = *(_BYTE *)(v7 + 157);
  v26[1] = *(_WORD *)(v7 + 150);
  LOBYTE(v26[2]) = v8;
  drv_ampdu_action(a1, v5, v24);
  raw_spin_lock_bh(a2 + 148);
  ieee80211_agg_splice_packets(*(_QWORD *)(a2 + 80), v7, a3);
  _X8 = (unsigned __int64 *)(v7 + 128);
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stxr(v20 | 4, _X8) );
  v9 = ieee802_1d_to_ac[a3 & 7];
  if ( (unsigned int)v9 >= 4
    || (v10 = *(_QWORD *)(a2 + 80), v11 = *(unsigned __int8 *)(v10 + v9 + 5850), (unsigned int)v11 > 0x10) )
  {
LABEL_7:
    __break(0x5512u);
  }
  _X9 = (unsigned int *)(*(_QWORD *)(v10 + 1616) + 4LL * *(unsigned __int8 *)(v10 + v9 + 5850) + 2464);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v22 = __ldxr(_X9);
    v23 = v22 - 1;
  }
  while ( __stlxr(v23, _X9) );
  __dmb(0xBu);
  if ( !v23 )
    ieee80211_wake_queue_by_reason(*(_QWORD *)(v10 + 1616), v11, 3, 0);
  raw_spin_unlock_bh(a2 + 148);
  result = ieee80211_agg_start_txq(a2, a3, 1);
  _ReadStatusReg(SP_EL0);
  return result;
}
