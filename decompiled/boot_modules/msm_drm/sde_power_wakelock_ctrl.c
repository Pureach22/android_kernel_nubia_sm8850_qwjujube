__int64 __fastcall sde_power_wakelock_ctrl(__int64 a1, char a2)
{
  int v2; // w6
  int v3; // w7
  size_t v4; // x0
  int v5; // w2
  int v6; // w4
  unsigned int v14; // w8
  unsigned int v15; // w8
  unsigned int v18; // w8
  unsigned int v19; // w8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 || !*(_QWORD *)(a1 + 96) )
  {
    printk(&unk_2219E0, "sde_power_wakelock_ctrl");
    return 4294967274LL;
  }
  if ( (a2 & 1) != 0 )
  {
    _X9 = (unsigned int *)(a1 + 464);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v14 = __ldxr(_X9);
      v15 = v14 + 1;
    }
    while ( __stlxr(v15, _X9) );
    __dmb(0xBu);
    if ( v15 != 1 )
      return 0;
    pm_stay_awake(*(_QWORD *)(a1 + 96));
    v4 = sde_dbg_base_evtlog;
    v5 = 1483;
    v6 = 13107;
  }
  else
  {
    _X9 = (unsigned int *)(a1 + 464);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v18 = __ldxr(_X9);
      v19 = v18 - 1;
    }
    while ( __stlxr(v19, _X9) );
    __dmb(0xBu);
    if ( v19 )
      return 0;
    pm_relax(*(_QWORD *)(a1 + 96));
    v4 = sde_dbg_base_evtlog;
    v5 = 1487;
    v6 = 17476;
  }
  sde_evtlog_log(v4, "sde_power_wakelock_ctrl", v5, -1, v6, -1059143953, v2, v3, vars0);
  return 0;
}
