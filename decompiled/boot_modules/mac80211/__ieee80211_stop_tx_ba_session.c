__int64 __fastcall _ieee80211_stop_tx_ba_session(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x23
  __int64 v4; // x20
  __int64 v7; // x22
  __int64 v8; // x22
  _QWORD *v9; // x24
  __int64 v10; // x23
  __int64 result; // x0
  __int64 v12; // x1
  unsigned __int64 v15; // x9
  unsigned __int64 v18; // x10
  unsigned __int64 v25; // x9
  _QWORD v26[2]; // [xsp+8h] [xbp-28h] BYREF
  __int16 v27; // [xsp+18h] [xbp-18h]
  _WORD v28[11]; // [xsp+1Ah] [xbp-16h]

  *(_QWORD *)&v28[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 72);
  v26[0] = 0;
  v26[1] = a1 + 2688;
  v27 = a2;
  *(_QWORD *)v28 = 0;
  *(_QWORD *)&v28[3] = 0;
  if ( a3 >= 4 )
  {
    __break(0x800u);
    result = 4294967274LL;
    goto LABEL_20;
  }
  v7 = a2;
  LODWORD(v26[0]) = dword_C1510[a3];
  raw_spin_lock_bh(a1 + 148);
  if ( (unsigned __int16)v7 >= 0x10u )
  {
    __break(0x5512u);
  }
  else
  {
    v3 = (unsigned __int16)v7;
    v8 = 8LL * (unsigned __int16)v7;
    kfree(*(_QWORD *)(a1 + v8 + 1032));
    *(_QWORD *)(a1 + v8 + 1032) = 0;
    v7 = *(_QWORD *)(a1 + 904 + v8);
    if ( !v7 )
    {
      raw_spin_unlock_bh(a1 + 148);
      result = 4294967294LL;
      goto LABEL_20;
    }
    if ( (*(_QWORD *)(v7 + 128) & 8) != 0 )
    {
      raw_spin_unlock_bh(a1 + 148);
      if ( a3 != 3 )
      {
        result = 4294967182LL;
        goto LABEL_20;
      }
      v12 = *(_QWORD *)(a1 + 80);
      LODWORD(v26[0]) = 5;
      result = drv_ampdu_action(v4, v12, v26);
      if ( (_DWORD)result )
        goto LABEL_12;
      goto LABEL_20;
    }
    if ( (*(_QWORD *)(v7 + 128) & 0x10) != 0 )
    {
      atomic_store(0, (unsigned __int64 *)(a1 + 904 + 8 * v3));
      raw_spin_unlock_bh(a1 + 148);
      kvfree_call_rcu(v7, v7);
      result = 0;
      goto LABEL_20;
    }
  }
  _X8 = (unsigned __int64 *)(v7 + 128);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 | 8, _X8) );
  v9 = *(_QWORD **)(a1 + 8 * v3 + 2736);
  if ( v9 )
  {
    v10 = *(_QWORD *)(*v9 - 3104LL);
    raw_spin_lock_bh(v10 + 240);
    _X8 = v9 - 1;
    __asm { PRFM            #0x11, [X8] }
    do
      v25 = __ldxr(_X8);
    while ( __stxr(v25 | 1, _X8) );
    raw_spin_unlock_bh(v10 + 240);
  }
  raw_spin_unlock_bh(a1 + 148);
  timer_delete_sync(v7 + 56);
  timer_delete_sync(v7 + 16);
  _X8 = (unsigned __int64 *)(v7 + 128);
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stxr(v18 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  if ( (*(_BYTE *)(v4 + 1470) & 1) == 0 )
    synchronize_net();
  *(_BYTE *)(v7 + 147) = a3 != 2;
  *(_BYTE *)(v7 + 148) = a3 == 1;
  result = drv_ampdu_action(v4, *(_QWORD *)(a1 + 80), v26);
  if ( (_DWORD)result )
  {
LABEL_12:
    result = 0;
    __break(0x800u);
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
