__int64 __fastcall a6xx_gmu_oob_set(__int64 a1, unsigned int a2)
{
  int v4; // w8
  unsigned int v5; // w21
  unsigned int v6; // w8
  bool v7; // cc
  int v8; // w8
  __int64 v10; // x20
  __int64 v11; // x22
  const char *v12; // x1
  const char *v14; // x8
  const char *v15; // x2
  unsigned int v21; // w9

  if ( a2 == 1 )
  {
    v4 = *(_DWORD *)(a1 - 232);
    *(_DWORD *)(a1 - 232) = v4 + 1;
    if ( v4 )
      return 0;
  }
  v6 = **(_DWORD **)(a1 + 14264) - 615;
  v7 = v6 > 0xF;
  v8 = (1 << v6) & 0x801B;
  if ( !v7 && v8 != 0 )
  {
    v10 = 1LL << ((unsigned __int8)a2 + 16);
    v11 = 1LL << ((unsigned __int8)a2 + 24);
LABEL_9:
    gmu_core_regwrite(a1, 129428, (unsigned int)v10);
    if ( (unsigned int)gmu_core_timed_poll_check(a1, 129426, (unsigned int)v11, 100, (unsigned int)v11) )
    {
      if ( a2 == 1 )
      {
        v12 = "oob_perfcntr";
        --*(_DWORD *)(a1 - 232);
      }
      else if ( a2 )
      {
        if ( a2 == 7 )
        {
          v12 = "oob_dcvs";
        }
        else if ( a2 == 6 )
        {
          v12 = "oob_boot_slumber";
        }
        else
        {
          v12 = "unknown";
        }
      }
      else
      {
        v12 = "oob_gpu";
      }
      _warn_printk("OOB request %s timed out\n", v12);
      __break(0x800u);
      gmu_core_fault_snapshot(a1, 3);
      if ( a2 == 1 )
      {
        _X8 = (unsigned int *)(a1 + 24448);
        __asm { PRFM            #0x11, [X8] }
        do
          v21 = __ldxr(_X8);
        while ( __stxr(v21 | 0x80, _X8) );
        __dmb(0xAu);
        kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
      }
      v5 = -110;
    }
    else
    {
      v5 = 0;
    }
    gmu_core_regwrite(a1, 129425, (unsigned int)v11);
    return v5;
  }
  if ( a2 < 6 )
  {
    LODWORD(v11) = 0x80000000 >> a2;
    LODWORD(v10) = 1 << (30 - 2 * a2);
    goto LABEL_9;
  }
  v14 = "unknown";
  if ( a2 == 6 )
    v14 = "oob_boot_slumber";
  if ( a2 == 7 )
    v15 = "oob_dcvs";
  else
    v15 = v14;
  dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Unsupported OOB request %s\n", v15);
  return (unsigned int)-22;
}
