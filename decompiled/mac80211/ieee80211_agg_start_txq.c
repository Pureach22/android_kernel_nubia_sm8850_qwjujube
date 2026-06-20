__int64 __fastcall ieee80211_agg_start_txq(__int64 result, unsigned int a2, char a3)
{
  __int64 *v3; // x19
  __int64 v4; // x20
  unsigned __int64 StatusReg; // x21
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x22
  __int64 (__fastcall *v9)(__int64, __int64 *); // x8
  __int64 unlock; // x0
  __int64 v11; // x9
  __int64 v12; // x1
  unsigned __int64 v15; // x10
  unsigned __int64 v18; // x9
  unsigned __int64 v25; // x10
  unsigned __int64 v28; // x9

  if ( a2 >= 0x11 )
  {
    __break(0x5512u);
  }
  else
  {
    v4 = result;
    v3 = *(__int64 **)(result + 8LL * a2 + 2736);
    if ( !v3 )
      return result;
    if ( (a3 & 1) != 0 )
    {
      _X8 = (unsigned __int64 *)(v3 - 1);
      __asm { PRFM            #0x11, [X8] }
      do
        v18 = __ldxr(_X8);
      while ( __stxr(v18 | 2, _X8) );
    }
    else
    {
      _X8 = (unsigned __int64 *)(v3 - 1);
      __asm { PRFM            #0x11, [X8] }
      do
        v25 = __ldxr(_X8);
      while ( __stxr(v25 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    }
  }
  _X8 = (unsigned __int64 *)(v3 - 1);
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr(_X8);
  while ( __stxr(v15 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(StatusReg + 16) += 512;
  _rcu_read_lock();
  v6 = *(_QWORD *)(*(_QWORD *)(v4 + 80) + 1616LL);
  v7 = _ieee80211_schedule_txq(v6, v3, 1);
  if ( *(_BYTE *)(v6 + 1470) == 1 )
  {
    _X8 = (unsigned __int64 *)(v3 - 1);
    __asm { PRFM            #0x11, [X8] }
    do
      v28 = __ldxr(_X8);
    while ( __stxr(v28 | 8, _X8) );
  }
  else
  {
    v8 = *v3;
    if ( (*(_BYTE *)(*(_QWORD *)(*v3 - 3104) + 1471LL) & 1) == 0
      && (*(_DWORD *)(v8 - 3096) & 0x20) == 0
      && (drv_wake_tx_queue___already_done & 1) == 0 )
    {
      v11 = *(_QWORD *)(v8 - 3112);
      drv_wake_tx_queue___already_done = 1;
      if ( v11 )
        v12 = v11 + 296;
      else
        v12 = v8 - 3080;
      v7 = _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v12);
      __break(0x800u);
    }
    if ( (*(_BYTE *)(v8 - 3096) & 0x20) != 0 )
    {
      v9 = *(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(v6 + 464) + 752LL);
      if ( *((_DWORD *)v9 - 1) != -1212882962 )
        __break(0x8228u);
      v7 = v9(v6, v3);
    }
  }
  unlock = _rcu_read_unlock(v7);
  return local_bh_enable(unlock);
}
