__int64 __fastcall geni_i3c_runtime_suspend(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  unsigned __int64 v3; // x20
  __int64 v4; // x0
  __int64 (*v5)(void); // x8
  int v6; // w21
  __int64 v7; // x21
  __int64 v8; // x22
  __int64 v9; // x23
  int v10; // w21
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x21
  __int64 v14; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v2 = *(_QWORD *)(v1 + 2536);
  if ( v2 )
  {
    if ( *(_DWORD *)(v1 + 2544) )
    {
      v3 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_runtime_suspend", v3, v3 / 0x3E8);
    }
    else
    {
      v3 = 0;
    }
  }
  else
  {
    v3 = -22;
  }
  ipc_log_string(*(_QWORD *)(v1 + 2528), "%s(): ret:%d start\n", "geni_i3c_runtime_suspend", 0);
  if ( *(_QWORD *)(v1 + 8) )
    i3c_trace_log();
  if ( *(_BYTE *)(v1 + 21641) == 1 && *(_BYTE *)(v1 + 21651) == 1 )
  {
    *(_DWORD *)(v1 + 2584) = 0;
    geni_i3c_wait_for_hotjoin(v1);
  }
  if ( *(_DWORD *)(v1 + 108) == 3 )
  {
    geni_i3c_gsi_stop_on_bus(v1);
    v4 = *(_QWORD *)(v1 + 2800);
    if ( v4 )
    {
      v5 = *(__int64 (**)(void))(*(_QWORD *)v4 + 320LL);
      if ( v5 )
      {
        if ( *((_DWORD *)v5 - 1) != -403578064 )
          __break(0x8228u);
        v6 = v5();
        if ( !v6 )
          goto LABEL_19;
      }
      else
      {
        v6 = -38;
      }
      ipc_log_string(*(_QWORD *)(v1 + 2528), "%s failed: tx:%d is_suspend:%d\n", "geni_i3c_gpi_pause_resume", v6, 1);
      if ( *(_QWORD *)(v1 + 8) )
        i3c_trace_log();
      ipc_log_string(*(_QWORD *)(v1 + 2528), "%s: ret:%d\n", "geni_i3c_runtime_suspend", -22);
      if ( *(_QWORD *)(v1 + 8) )
        i3c_trace_log();
      return 4294967274LL;
    }
  }
  else
  {
    disable_irq(*(unsigned int *)(v1 + 100));
  }
LABEL_19:
  v7 = *(_QWORD *)(v1 + 24);
  v8 = *(_QWORD *)(v1 + 21584);
  v9 = *(_QWORD *)(v1 + 21592);
  clk_disable(v7);
  clk_unprepare(v7);
  clk_disable(v8);
  clk_unprepare(v8);
  clk_disable(v9);
  clk_unprepare(v9);
  v10 = geni_icc_disable(v1);
  if ( v10 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 2528), "%s geni_icc_disable failed %d\n", "geni_i3c_runtime_suspend", v10);
    if ( *(_QWORD *)(v1 + 8) )
      i3c_trace_log();
  }
  if ( *(_BYTE *)(v1 + 21641) == 1 && *(_BYTE *)(v1 + 21650) == 1 )
  {
    geni_i3c_enable_ibi_ctrl(v1, 0);
    v10 = pinctrl_select_state(*(_QWORD *)(v1 + 21600), *(_QWORD *)(v1 + 21616));
    v11 = *(_QWORD *)(v1 + 2528);
    if ( v10 )
    {
      ipc_log_string(v11, "%s: pinctrl sleep state failed\n", "geni_i3c_runtime_suspend");
      if ( *(_QWORD *)(v1 + 8) )
        i3c_trace_log();
    }
    else
    {
      ipc_log_string(v11, "%s: pinctrl set to sleep state\n", "geni_i3c_runtime_suspend");
      if ( *(_QWORD *)(v1 + 8) )
        i3c_trace_log();
      v10 = 0;
    }
  }
  ipc_log_string(*(_QWORD *)(v1 + 2528), "%s():ret:%d end\n", "geni_i3c_runtime_suspend", v10);
  if ( *(_QWORD *)(v1 + 8) )
    i3c_trace_log();
  v13 = *(_QWORD *)(v1 + 2536);
  if ( !v13 )
    return 0;
  result = 0;
  if ( v3 && *(_DWORD *)(v1 + 2544) )
  {
    v14 = sched_clock(0);
    ipc_log_string(v13, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_runtime_suspend", v14 - v3, (v14 - v3) / 0x3E8);
    return 0;
  }
  return result;
}
