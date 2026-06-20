__int64 __fastcall spi_geni_runtime_suspend(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x19
  __int64 v3; // x22
  unsigned __int64 v4; // x20
  int v5; // w0
  int v6; // w0
  unsigned int v7; // w21
  __int64 v8; // x20
  __int64 v9; // x21
  __int64 v10; // x22
  __int64 v11; // x0
  __int64 v12; // x22
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x22
  __int64 v16; // x0
  __int64 v18; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(v1 + 152);
  v3 = *(_QWORD *)(v2 + 488);
  if ( v3 )
  {
    if ( *(_DWORD *)(v2 + 496) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "spi_geni_runtime_suspend", v4, v4 / 0x3E8);
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    v4 = -22;
  }
  ipc_log_string(*(_QWORD *)(v2 + 472), "%s: %d\n", "spi_geni_runtime_suspend", 0);
  if ( *(_QWORD *)(v2 + 200) )
    spi_trace_log();
  disable_irq(*(unsigned int *)(v2 + 192));
  if ( *(_BYTE *)(v2 + 503) == 1 )
  {
    spi_geni_unlock_bus(v1);
    if ( (*(_BYTE *)(v2 + 224) & 1) == 0 && (v5 = spi_geni_mas_setup(v1)) != 0 )
    {
      v7 = v5;
      ipc_log_string(*(_QWORD *)(v2 + 472), "%s mas_setup failed: %d\n", "spi_geni_levm_suspend_proc", v5);
      v18 = *(_QWORD *)(v2 + 200);
      if ( v18 )
        dev_err(v18, "%s mas_setup failed: %d\n", "spi_geni_levm_suspend_proc", v7);
      else
        printk(&unk_DF01);
      if ( *(_QWORD *)(v2 + 200) )
        goto LABEL_14;
    }
    else
    {
      if ( *(_BYTE *)(v2 + 500) != 1 || (v6 = spi_geni_gpi_pause_resume(v2, 1)) == 0 )
      {
        ipc_log_string(*(_QWORD *)(v2 + 472), "%s: ret:%d\n", "spi_geni_levm_suspend_proc", 0);
        v11 = *(_QWORD *)(v2 + 200);
        if ( v11 )
          spi_trace_log();
        v12 = *(_QWORD *)(v2 + 488);
        if ( v12 )
        {
          v7 = 0;
          if ( !v4 || !*(_DWORD *)(v2 + 496) )
            return v7;
          v13 = sched_clock(v11);
          ipc_log_string(
            v12,
            "%s:took %llu nsec(%llu usec)\n",
            "spi_geni_levm_suspend_proc",
            v13 - v4,
            (v13 - v4) / 0x3E8);
        }
        return 0;
      }
      v7 = v6;
      ipc_log_string(*(_QWORD *)(v2 + 472), "%s: ret:%d\n", "spi_geni_levm_suspend_proc", v6);
      if ( *(_QWORD *)(v2 + 200) )
LABEL_14:
        spi_trace_log();
    }
  }
  else if ( *(_BYTE *)(v2 + 500) != 1 || (v7 = spi_geni_gpi_pause_resume(v2, 1)) == 0 )
  {
    if ( (*(_BYTE *)(v2 + 504) & 1) != 0
      || *(_BYTE *)(v2 + 501) == 1 && *(_BYTE *)(v2 + 502) != 1
      || *(_BYTE *)(v2 + 500) != 1 )
    {
      geni_se_resources_off(v2);
      v14 = geni_icc_disable(v2);
      v7 = v14;
      if ( (_DWORD)v14 )
      {
        ipc_log_string(
          *(_QWORD *)(v2 + 472),
          "%s failing at geni_icc_disable ret=%d\n",
          "spi_geni_runtime_suspend",
          v14);
        v14 = *(_QWORD *)(v2 + 200);
        if ( v14 )
          spi_trace_log();
      }
      v15 = *(_QWORD *)(v2 + 488);
      if ( v15 && v4 && *(_DWORD *)(v2 + 496) )
      {
        v16 = sched_clock(v14);
        ipc_log_string(v15, "%s:took %llu nsec(%llu usec)\n", "spi_geni_runtime_suspend", v16 - v4, (v16 - v4) / 0x3E8);
      }
    }
    else
    {
      v8 = *(_QWORD *)(v2 + 24);
      v9 = *(_QWORD *)(v2 + 120);
      v10 = *(_QWORD *)(v2 + 128);
      clk_disable(v8);
      clk_unprepare(v8);
      clk_disable(v9);
      clk_unprepare(v9);
      clk_disable(v10);
      clk_unprepare(v10);
      v7 = geni_icc_disable(v2);
      if ( v7 )
      {
        ipc_log_string(*(_QWORD *)(v2 + 472), "%s failing at geni_icc_disable ret=%d\n", "spi_geni_runtime_suspend", v7);
        if ( *(_QWORD *)(v2 + 200) )
          goto LABEL_14;
      }
    }
  }
  return v7;
}
