__int64 __fastcall sendcmd(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v3; // x20
  __int64 v6; // x28
  int *v7; // x27
  unsigned int v8; // w25
  __int64 v9; // x23
  __int64 v10; // x26
  unsigned int v11; // w21
  unsigned int v12; // w23
  int v14; // w8
  unsigned int v15; // w0
  int v16; // w8
  __int64 v17; // x24
  __int64 v18; // x8
  __int64 v19; // x2
  __int64 v20; // x8
  void (__fastcall *v21)(_QWORD); // x8
  unsigned __int64 v24; // x9
  unsigned __int64 v27; // x10
  unsigned __int64 v30; // x8
  unsigned __int64 v37; // x9
  __int64 v38; // [xsp+10h] [xbp-50h]
  __int64 v39; // [xsp+30h] [xbp-30h] BYREF
  __int64 v40; // [xsp+38h] [xbp-28h]
  __int64 v41; // [xsp+40h] [xbp-20h]
  __int64 v42; // [xsp+48h] [xbp-18h]
  __int64 v43; // [xsp+50h] [xbp-10h]
  __int64 v44; // [xsp+58h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = _ReadStatusReg(SP_EL0);
  v44 = *(_QWORD *)(StatusReg + 1808);
  v6 = *(_QWORD *)(a2 + 8);
  v7 = (int *)(a1 + 19896);
  v8 = *(_DWORD *)(v3 + 148);
  LODWORD(StatusReg) = *(_DWORD *)(v3 + 152);
  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL);
  v10 = *(_QWORD *)(v6 + 1536);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v11 = StatusReg - 120;
  v39 = 0;
  rt_mutex_lock(a1 + 11088);
  if ( v8 >= 0x64 )
    sched_set_fifo(v3);
  __dmb(9u);
  if ( v7[129] )
  {
    v12 = -16;
LABEL_5:
    if ( v8 >= 0x64 )
      sched_set_normal(v3, v11);
    rt_mutex_unlock(a1 + 11088);
    goto LABEL_8;
  }
  v14 = *v7;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v39 = 0;
  *v7 = v14 + 1;
  v38 = v9;
  ++*(_DWORD *)(v10 + 1232);
  if ( *v7 != 1 || (*(_QWORD *)(a1 + 19808) & 1) != 0 )
  {
    if ( (*(_QWORD *)(a1 + 14240) & 0x80) != 0 )
      goto LABEL_53;
    goto LABEL_16;
  }
  v15 = adreno_active_count_get(a1);
  if ( v15 )
  {
    v12 = v15;
    --*v7;
    --*(_DWORD *)(v10 + 1232);
    goto LABEL_5;
  }
  _X8 = (unsigned __int64 *)(a1 + 19808);
  __asm { PRFM            #0x11, [X8] }
  do
    v37 = __ldxr(_X8);
  while ( __stxr(v37 | 1, _X8) );
  if ( (*(_QWORD *)(a1 + 14240) & 0x80) != 0 )
    goto LABEL_53;
  while ( 1 )
  {
LABEL_16:
    if ( (*(_QWORD *)(a1 + 14240) & 0x200) != 0
      && *(_DWORD *)(a1 + 10940)
      && (*(_BYTE *)(a1 + 10944) & 1) == 0
      && *(_DWORD *)(a1 + 15584) == 1 )
    {
      kgsl_bus_update(a1, 4);
    }
    v12 = adreno_ringbuffer_submitcmd(a1, a2, &v39);
    if ( *v7 == 1 )
    {
      if ( v12 )
      {
        adreno_active_count_put(a1);
        _X8 = (unsigned __int64 *)(a1 + 19808);
        __asm { PRFM            #0x11, [X8] }
        do
          v27 = __ldxr(_X8);
        while ( __stxr(v27 & 0xFFFFFFFFFFFFFFFELL, _X8) );
LABEL_25:
        --*v7;
        --*(_DWORD *)(v10 + 1232);
        if ( (*(_QWORD *)(a1 + 14240) & 0x200) != 0
          && *(_DWORD *)(a1 + 10940)
          && *(_BYTE *)(a1 + 10944)
          && !*(_DWORD *)(a1 + 15584) )
        {
          kgsl_bus_update(a1, 3);
        }
        if ( v12 != -71 && v12 != -28 && v12 != -2 )
          dev_err(*(_QWORD *)a1, "Unable to submit command to the ringbuffer %d\n", v12);
        goto LABEL_5;
      }
      _X9 = (unsigned __int64 *)(a1 + 19808);
      __asm { PRFM            #0x11, [X9] }
      do
        v30 = __ldxr(_X9);
      while ( __stlxr(v30 | 2, _X9) );
      __dmb(0xBu);
      if ( (v30 & 2) == 0 )
        v7[90] = 0;
    }
    else if ( v12 )
    {
      goto LABEL_25;
    }
    if ( *(_DWORD *)(v10 + 1232) == 1 )
    {
      v17 = jiffies;
      *(_QWORD *)(v10 + 1248) = _msecs_to_jiffies((unsigned int)adreno_drawobj_timeout) + v17;
    }
    adreno_get_rptr(*(_QWORD *)(v6 + 1536));
    v18 = *(_QWORD *)(*(_QWORD *)(v6 + 24) + 8LL);
    if ( v18 )
      v19 = *(unsigned int *)(v18 + 112);
    else
      v19 = 0;
    msm_perf_events_update(
      0,
      2,
      v19,
      *(unsigned int *)(v6 + 4),
      *(unsigned int *)(a2 + 20),
      (*(_QWORD *)(a2 + 24) >> 8) & 1LL);
    log_kgsl_cmdbatch_submitted_event(
      *(unsigned int *)(v6 + 4),
      *(unsigned int *)(a2 + 20),
      *(unsigned int *)(v6 + 8),
      *(_QWORD *)(a2 + 24));
    if ( v8 >= 0x64 )
      sched_set_normal(v3, v11);
    rt_mutex_unlock(a1 + 11088);
    *(_QWORD *)(a2 + 152) = v39;
    v20 = *(unsigned int *)(v10 + 1240);
    if ( (unsigned int)v20 < 0x80 )
      break;
    __break(0x5512u);
LABEL_53:
    _X8 = (unsigned __int64 *)(a2 + 56);
    __asm { PRFM            #0x11, [X8] }
    do
      v24 = __ldxr(_X8);
    while ( __stxr(v24 | 8, _X8) );
    v16 = v7[140];
    *(_DWORD *)(a2 + 144) = v16;
    v7[140] = (v16 + 1) & 0x7F;
  }
  *(_QWORD *)(v10 + 208 + 8 * v20) = a2;
  *(_DWORD *)(v10 + 1240) = ((unsigned __int8)*(_DWORD *)(v10 + 1240) + 1) & 0x7F;
  if ( !v7[148] && *(_QWORD *)(v10 - 1320LL * *(int *)(v10 + 28) + 5288) == v10 )
    mod_timer(a1 + 19816);
  v21 = *(void (__fastcall **)(_QWORD))(v38 + 88);
  if ( v21 )
  {
    if ( *((_DWORD *)v21 - 1) != 994519391 )
      __break(0x8228u);
    v21(a1);
  }
  v12 = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v12;
}
