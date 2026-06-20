__int64 __fastcall gen7_gmu_oob_set(__int64 a1, unsigned int a2)
{
  int v4; // w9
  unsigned int v5; // w22
  unsigned int v6; // w21
  const char *v7; // x1
  const char *v9; // x8
  const char *v10; // x2
  unsigned int v17; // w9

  if ( a2 == 1 )
  {
    v4 = *(_DWORD *)(a1 - 552);
    *(_DWORD *)(a1 - 552) = v4 + 1;
    if ( v4 )
      return 0;
    goto LABEL_5;
  }
  if ( a2 < 6 )
  {
LABEL_5:
    v6 = 0x80000000 >> a2;
    gmu_core_regwrite(a1, 129428, (unsigned int)(1 << (30 - 2 * a2)));
    if ( (unsigned int)gmu_core_timed_poll_check(a1, 129426, v6, 100, v6) )
    {
      if ( a2 == 1 )
      {
        v7 = "oob_perfcntr";
        --*(_DWORD *)(a1 - 552);
      }
      else if ( a2 )
      {
        v7 = "unknown";
      }
      else
      {
        v7 = "oob_gpu";
      }
      _warn_printk("OOB request %s timed out\n", v7);
      __break(0x800u);
      gmu_core_fault_snapshot(a1, 3);
      if ( a2 == 1 )
      {
        _X8 = (unsigned int *)(a1 + 24448);
        __asm { PRFM            #0x11, [X8] }
        do
          v17 = __ldxr(_X8);
        while ( __stxr(v17 | 0x80, _X8) );
        __dmb(0xAu);
        kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
      }
      v5 = -110;
    }
    else
    {
      v5 = 0;
    }
    gmu_core_regwrite(a1, 129425, v6);
    return v5;
  }
  v9 = "unknown";
  if ( a2 == 6 )
    v9 = "oob_boot_slumber";
  if ( a2 == 7 )
    v10 = "oob_dcvs";
  else
    v10 = v9;
  dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Unsupported OOB request %s\n", v10);
  return (unsigned int)-22;
}
