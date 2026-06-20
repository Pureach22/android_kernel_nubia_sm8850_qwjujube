__int64 __fastcall cfg80211_clear_ibss(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 *v3; // x23
  __int64 v4; // x21
  _DWORD *v5; // x8
  unsigned int v6; // w22
  _DWORD *v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x8
  unsigned int v22; // w9
  unsigned int v23; // w9
  unsigned int v26; // w8
  unsigned int v27; // w8

  v3 = *(__int64 **)(a1 + 992);
  v4 = *v3;
  if ( *v3 )
  {
    v2 = a1;
    v1 = v4 - 992;
    kfree_sensitive(v3[11]);
    v3[11] = 0;
    if ( !*(_QWORD *)(*(_QWORD *)(v4 - 992) + 736LL) )
      goto LABEL_6;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v12 = _traceiter_rdev_set_qos_map(0, 0, v2, 0);
      v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v15;
      if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v12, v13, v14);
    }
  }
  v5 = *(_DWORD **)(*(_QWORD *)v1 + 736LL);
  if ( *(v5 - 1) != -824243271 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD))v5)(v4, v2, 0);
LABEL_6:
  if ( *(_QWORD *)(*(_QWORD *)v1 + 80LL) )
  {
    v6 = 0;
    _ReadStatusReg(SP_EL0);
    do
    {
      v7 = *(_DWORD **)(*(_QWORD *)v1 + 80LL);
      if ( *(v7 - 1) != 1549052562 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD, _QWORD))v7)(v4, v2, 0xFFFFFFFFLL, v6++, 0, 0);
    }
    while ( v6 != 6 );
  }
  v8 = v3[35];
  if ( v8 )
  {
    _X10 = (unsigned int *)(v8 + 80);
    __asm { PRFM            #0x11, [X10] }
    do
    {
      v22 = __ldxr(_X10);
      v23 = v22 - 1;
    }
    while ( __stlxr(v23, _X10) );
    __dmb(0xBu);
    if ( (v23 & 0x80000000) != 0 )
    {
      __break(0x800u);
      v9 = *(_QWORD *)(v8 + 152);
      if ( !v9 )
        goto LABEL_15;
    }
    else
    {
      v9 = *(_QWORD *)(v8 + 152);
      if ( !v9 )
      {
LABEL_15:
        cfg80211_put_bss(*v3, v3[35] + 112);
        goto LABEL_16;
      }
    }
    _X9 = (unsigned int *)(v9 - 32);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v26 = __ldxr(_X9);
      v27 = v26 - 1;
    }
    while ( __stlxr(v27, _X9) );
    __dmb(0xBu);
    if ( (v27 & 0x80000000) != 0 )
      __break(0x800u);
    goto LABEL_15;
  }
LABEL_16:
  *((_BYTE *)v3 + 356) = 0;
  v3[35] = 0;
  v3[36] = 0;
  v3[37] = 0;
  v3[38] = 0;
  v3[39] = 0;
  return cfg80211_sched_dfs_chan_update(v1);
}
