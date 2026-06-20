__int64 __fastcall spi_geni_suspend(__int64 a1)
{
  _QWORD *v1; // x23
  __int64 v3; // x22
  __int64 v4; // x21
  unsigned __int64 v5; // x19
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x20
  unsigned int v10; // w21
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  int v15; // w0
  unsigned int v16; // w20
  __int64 v17; // x0

  v1 = *(_QWORD **)(a1 + 152);
  v3 = v1[19];
  v4 = *(_QWORD *)(v3 + 488);
  if ( v4 )
  {
    if ( *(_DWORD *)(v3 + 496) )
    {
      v5 = sched_clock(a1);
      ipc_log_string(v4, "%s:start at %llu nsec(%llu usec)\n", "spi_geni_suspend", v5, v5 / 0x3E8);
    }
    else
    {
      v5 = 0;
    }
  }
  else
  {
    v5 = -22;
  }
  if ( *(_BYTE *)(v3 + 518) == 1 )
  {
    v6 = *(_QWORD *)(v3 + 472);
    if ( *(_DWORD *)(a1 + 500) == 2 )
    {
      ipc_log_string(v6, "%s System suspend not allowed while xfer in progress=%d\n", "spi_geni_suspend", 0);
      if ( !*(_QWORD *)(v3 + 200) )
        return 4294967280LL;
    }
    else
    {
      ipc_log_string(v6, ":%s: runtime PM is active\n", "spi_geni_suspend");
      v12 = *(_QWORD *)(v3 + 200);
      if ( v12 )
        dev_err(v12, ":%s: runtime PM is active\n", "spi_geni_suspend");
      else
        printk(&unk_E6E9);
      if ( !*(_QWORD *)(v3 + 200) )
        return 4294967280LL;
    }
LABEL_9:
    spi_trace_log();
    return 4294967280LL;
  }
  if ( (*(_BYTE *)(v3 + 503) & 1) == 0 && *(_BYTE *)(v3 + 504) != 1 )
  {
    if ( *(_DWORD *)(a1 + 500) == 2 )
      goto LABEL_18;
    if ( (_QWORD *)v1[158] == v1 + 158 && !v1[160] )
    {
      ipc_log_string(*(_QWORD *)(v3 + 472), "%s: Force suspend", "spi_geni_suspend");
      v14 = *(_QWORD *)(v3 + 200);
      if ( v14 )
        dev_err(v14, "%s: Force suspend", "spi_geni_suspend");
      else
        printk(&unk_E087);
      if ( *(_QWORD *)(v3 + 200) )
        spi_trace_log();
      v15 = spi_geni_runtime_suspend(a1);
      if ( !v15 )
      {
        _pm_runtime_disable(a1, 1);
        _pm_runtime_set_status(a1, 2);
        pm_runtime_enable(a1);
LABEL_18:
        result = 0;
        v9 = *(_QWORD *)(v3 + 488);
        if ( !v9 )
          return result;
        goto LABEL_23;
      }
      v16 = v15;
      ipc_log_string(*(_QWORD *)(v3 + 472), "Force suspend Failed:%d", v15);
      v17 = *(_QWORD *)(v3 + 200);
      if ( v17 )
        dev_err(v17, "Force suspend Failed:%d", v16);
      else
        printk(&unk_DC00);
      if ( *(_QWORD *)(v3 + 200) )
        spi_trace_log();
      result = v16;
      v9 = *(_QWORD *)(v3 + 488);
      if ( !v9 )
        return result;
    }
    else
    {
      result = 4294967280LL;
      v9 = *(_QWORD *)(v3 + 488);
      if ( !v9 )
        return result;
    }
LABEL_23:
    if ( v5 && *(_DWORD *)(v3 + 496) )
    {
      v10 = result;
      v11 = sched_clock(result);
      ipc_log_string(v9, "%s:took %llu nsec(%llu usec)\n", "spi_geni_suspend", v11 - v5, (v11 - v5) / 0x3E8);
      return v10;
    }
    return result;
  }
  v8 = *(_QWORD *)(v3 + 472);
  if ( *(_DWORD *)(a1 + 500) != 2 )
  {
    ipc_log_string(v8, ":%s: Client managed runtime PM is active\n", "spi_geni_suspend");
    v13 = *(_QWORD *)(v3 + 200);
    if ( v13 )
      dev_err(v13, ":%s: Client managed runtime PM is active\n", "spi_geni_suspend");
    else
      printk(&unk_E334);
    if ( !*(_QWORD *)(v3 + 200) )
      return 4294967280LL;
    goto LABEL_9;
  }
  ipc_log_string(v8, "%s: System suspend bypassed due to le/la vm\n", "spi_geni_suspend");
  result = *(_QWORD *)(v3 + 200);
  if ( result )
  {
    spi_trace_log();
    return 0;
  }
  return result;
}
