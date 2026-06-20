__int64 __fastcall geni_i2c_suspend_late(__int64 a1)
{
  _QWORD *v1; // x22
  __int64 v3; // x21
  unsigned __int64 v4; // x19
  __int64 v5; // x0
  __int64 result; // x0
  _DWORD *v7; // x8
  int v8; // w0
  int v9; // w21
  _DWORD *v10; // x8
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x2
  __int64 v15; // x2
  __int64 v16; // x1
  __int64 v17; // x2

  v1 = *(_QWORD **)(a1 + 152);
  v3 = v1[638];
  if ( v3 )
  {
    if ( *((_DWORD *)v1 + 1278) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "geni_i2c_suspend_late", v4, v4 / 0x3E8);
      if ( !*((_DWORD *)v1 + 2279) )
        goto LABEL_4;
LABEL_25:
      v13 = v1[637];
      if ( *(_DWORD *)(*v1 + 500LL) == 2 )
      {
        ipc_log_string(v13, "%s System suspend not allowed while xfer in progress\n", "geni_i2c_suspend_late");
        if ( *v1 )
          dev_err(*v1, "%s System suspend not allowed while xfer in progress\n", "geni_i2c_suspend_late");
        else
          printk(&unk_10BDB, "geni_i2c_suspend_late", v14);
        if ( !*v1 )
          return 4294967280LL;
      }
      else
      {
        ipc_log_string(v13, ":%s: runtime PM is active\n", "geni_i2c_suspend_late");
        if ( *v1 )
          dev_err(*v1, ":%s: runtime PM is active\n", "geni_i2c_suspend_late");
        else
          printk(&unk_FAF8, "geni_i2c_suspend_late", v15);
        if ( !*v1 )
          return 4294967280LL;
      }
      goto LABEL_29;
    }
    v4 = 0;
    if ( *((_DWORD *)v1 + 2279) )
      goto LABEL_25;
  }
  else
  {
    v4 = -22;
    if ( *((_DWORD *)v1 + 2279) )
      goto LABEL_25;
  }
LABEL_4:
  if ( *((_BYTE *)v1 + 9106) == 1 )
  {
    v5 = v1[637];
    if ( *(_DWORD *)(*v1 + 500LL) == 2 )
    {
      ipc_log_string(v5, "%s: System suspend bypassed due to pm-ctrl-client\n", "geni_i2c_suspend_late");
      result = *v1;
      if ( *v1 )
      {
        i2c_trace_log();
        return 0;
      }
      return result;
    }
    ipc_log_string(v5, ":%s: Wait for pm client to call put_sync\n", "geni_i2c_suspend_late");
    if ( !*v1 )
      return 4294967280LL;
LABEL_29:
    i2c_trace_log();
    return 4294967280LL;
  }
  v7 = *(_DWORD **)(v1[8] + 8LL);
  if ( *(v7 - 1) != -1699265455 )
    __break(0x8228u);
  v8 = ((__int64 (__fastcall *)(_QWORD *, __int64))v7)(v1 + 4, 2);
  if ( !v8 )
  {
    ipc_log_string(v1[637], "late I2C transaction request\n");
    if ( *v1 )
      dev_err(*v1, "late I2C transaction request\n");
    else
      printk(&unk_10B1C, v16, v17);
    if ( !*v1 )
      return 4294967280LL;
    goto LABEL_29;
  }
  v9 = v8;
  if ( *(_DWORD *)(a1 + 500) != 2 )
  {
    ipc_log_string(v1[637], "%s: Force suspend\n", "geni_i2c_suspend_late");
    if ( *v1 )
      i2c_trace_log();
    geni_i2c_runtime_suspend(a1);
    _pm_runtime_disable(a1, 1);
    _pm_runtime_set_status(a1, 2);
    pm_runtime_enable(a1);
  }
  v10 = *(_DWORD **)(v1[8] + 16LL);
  if ( *(v10 - 1) != 181739622 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD *, __int64))v10)(v1 + 4, 2);
  ipc_log_string(v1[637], "%s ret=%d\n", "geni_i2c_suspend_late", v9);
  if ( *v1 )
    i2c_trace_log();
  v11 = v1[638];
  if ( !v11 )
    return 0;
  result = 0;
  if ( v4 && *((_DWORD *)v1 + 1278) )
  {
    v12 = sched_clock(0);
    ipc_log_string(v11, "%s:took %llu nsec(%llu usec)\n", "geni_i2c_suspend_late", v12 - v4, (v12 - v4) / 0x3E8);
    return 0;
  }
  return result;
}
