__int64 __fastcall hdd_crash_inject(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x3
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  __int64 result; // x0
  _BYTE v25[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: v1: %d v2: %d", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_crash_inject", a2, a3);
  printk(&unk_9B381E, a2, a3, v14);
  if ( (unsigned int)wlan_mlme_get_crash_inject(**(_QWORD **)(a1 + 24), v25) )
  {
    v23 = "%s: Failed to get crash inject ini config";
LABEL_7:
    qdf_trace_msg(0x33u, 2u, v23, v15, v16, v17, v18, v19, v20, v21, v22, "hdd_crash_inject");
    goto LABEL_8;
  }
  if ( (v25[0] & 1) == 0 )
  {
    v23 = "%s: Crash Inject ini disabled, Ignore Crash Inject";
    goto LABEL_7;
  }
  if ( a2 != 3 )
  {
    result = wma_cli_set2_command(*(unsigned __int8 *)(*(_QWORD *)(a1 + 52824) + 8LL), 3, a2, a3, 3);
    goto LABEL_9;
  }
  _cds_trigger_recovery(0, (__int64)"hdd_crash_inject", 23525, v15, v16, v17, v18, v19, v20, v21, v22);
LABEL_8:
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
