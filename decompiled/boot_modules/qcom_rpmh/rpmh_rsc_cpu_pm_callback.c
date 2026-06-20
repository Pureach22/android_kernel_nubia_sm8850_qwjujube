__int64 __fastcall rpmh_rsc_cpu_pm_callback(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  int v4; // w20
  __int64 result; // x0
  unsigned int v12; // w9
  unsigned int v15; // w21
  unsigned int v16; // w21
  unsigned int v19; // w10

  if ( (unsigned __int64)(a2 - 1) < 2 )
  {
    _X8 = (unsigned int *)(a1 + 48);
    result = 1;
    __asm { PRFM            #0x11, [X8] }
    do
      v12 = __ldxr(_X8);
    while ( __stxr(v12 - 1, _X8) );
    return result;
  }
  if ( a2 )
    return 0;
  _X8 = (unsigned int *)(a1 + 48);
  __asm { PRFM            #0x11, [X8] }
  do
  {
    v15 = __ldxr(_X8);
    v16 = v15 + 1;
  }
  while ( __stlxr(v16, _X8) );
  __dmb(0xBu);
  if ( v16 < _num_online_cpus || !(unsigned int)raw_spin_trylock(a1 + 1056) )
    return 1;
  if ( *(_DWORD *)(a1 - 12) != 1 )
  {
    do
      v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 - 40) + *(unsigned int *)(*(_QWORD *)(a1 + 1600) + 80LL)));
    while ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 - 40)
                                                       + *(unsigned int *)(*(_QWORD *)(a1 + 1600) + 84LL))) != v4 );
    if ( (v4 & 1) != 0 )
    {
      v3 = 1;
      goto LABEL_15;
    }
    if ( (v4 & 2) == 0 )
      goto LABEL_17;
  }
  v3 = 0;
LABEL_15:
  if ( !rpmh_rsc_ctrlr_is_busy(a1 - 64) && !(unsigned int)rpmh_flush(a1 + 1088, v3) )
  {
    raw_spin_unlock(a1 + 1056);
    return 1;
  }
LABEL_17:
  raw_spin_unlock(a1 + 1056);
  if ( v16 < _num_online_cpus )
    return 1;
  _X8 = (unsigned int *)(a1 + 48);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 - 1, _X8) );
  return 32770;
}
