__int64 __fastcall sde_qtimer_irq_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x19
  _QWORD *v9; // x21
  unsigned __int64 v10; // kr08_8
  int v11; // w7
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a2 + 56);
  v9 = *(_QWORD **)(v8 + 8);
  sde_evtlog_log(sde_dbg_base_evtlog, "sde_qtimer_irq_cb", 110, -1, 0, -1059143953, a7, a8, vars0);
  if ( v9[802] && !*(_DWORD *)(v8 + 5912) )
  {
    v10 = v9[804] * (unsigned int)readl_relaxed_10(v9[803] + 16LL);
    writel_relaxed_8(2, v9[803] + 44LL);
    writel_relaxed_8((unsigned int)(v10 / 0x3B9ACA00), v9[803] + 40LL);
    writel_relaxed_8(1, v9[803] + 44LL);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_qtimer_start",
      173,
      -1,
      v10 / 0x3B9ACA0000000000LL,
      v10 / 0x3B9ACA00,
      -1059143953,
      v11,
      vars0a);
  }
  return 1;
}
