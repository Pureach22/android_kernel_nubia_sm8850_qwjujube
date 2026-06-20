__int64 __fastcall geni_i3c_runtime_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x22
  unsigned __int64 v4; // x20
  unsigned int v5; // w0
  unsigned int v6; // w22
  __int64 v8; // x0
  __int64 (*v9)(void); // x8
  int v10; // w22
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 2536);
  if ( v3 )
  {
    if ( *(_DWORD *)(v1 + 2544) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_runtime_resume", v4, v4 / 0x3E8);
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
  ipc_log_string(*(_QWORD *)(v1 + 2528), "%s(): ret:%d start\n", "geni_i3c_runtime_resume", 0);
  if ( *(_QWORD *)(v1 + 8) )
    i3c_trace_log();
  v5 = geni_icc_enable(v1);
  if ( v5 )
  {
    v6 = v5;
    ipc_log_string(*(_QWORD *)(v1 + 2528), "%s geni_icc_enable failed %d\n", "geni_i3c_runtime_resume", v5);
    if ( *(_QWORD *)(v1 + 8) )
      goto LABEL_14;
    return v6;
  }
  if ( *(_BYTE *)(v1 + 21649) == 1 )
  {
    v6 = geni_se_common_clks_on(*(_QWORD *)(v1 + 24), *(_QWORD *)(v1 + 21584), *(_QWORD *)(v1 + 21592));
    if ( v6 )
      goto LABEL_13;
LABEL_17:
    writel_relaxed(0x7Fu, (unsigned int *)(*(_QWORD *)v1 + 36LL));
    _const_udelay(42950);
    if ( *(_DWORD *)(v1 + 108) != 3 )
    {
      enable_irq(*(unsigned int *)(v1 + 100));
      goto LABEL_25;
    }
    v8 = *(_QWORD *)(v1 + 2800);
    if ( v8 )
    {
      v9 = *(__int64 (**)(void))(*(_QWORD *)v8 + 328LL);
      if ( v9 )
      {
        if ( *((_DWORD *)v9 - 1) != -403578064 )
          __break(0x8228u);
        v10 = v9();
        if ( !v10 )
          goto LABEL_25;
      }
      else
      {
        v10 = -38;
      }
      ipc_log_string(*(_QWORD *)(v1 + 2528), "%s failed: tx:%d is_suspend:%d\n", "geni_i3c_gpi_pause_resume", v10, 0);
      if ( *(_QWORD *)(v1 + 8) )
        i3c_trace_log();
      v6 = -22;
      ipc_log_string(*(_QWORD *)(v1 + 2528), "%s: ret:%d\n", "geni_i3c_runtime_resume", -22);
      if ( *(_QWORD *)(v1 + 8) )
        goto LABEL_14;
      return v6;
    }
LABEL_25:
    if ( *(_BYTE *)(v1 + 21641) == 1 && *(_BYTE *)(v1 + 21650) == 1 )
    {
      if ( **(_DWORD **)(*(_QWORD *)(a1 + 744) + 240LL) )
        *(_DWORD *)(v1 + 2584) = 0;
      geni_i3c_enable_ibi_ctrl(v1, 1);
      if ( **(_DWORD **)(*(_QWORD *)(a1 + 744) + 240LL) )
        geni_i3c_wait_for_hotjoin(v1);
    }
    ipc_log_string(*(_QWORD *)(v1 + 2528), "%s(): ret:%d end\n", "geni_i3c_runtime_resume", 0);
    v11 = *(_QWORD *)(v1 + 8);
    if ( v11 )
      i3c_trace_log();
    v12 = *(_QWORD *)(v1 + 2536);
    if ( v12 )
    {
      v6 = 0;
      if ( !v4 || !*(_DWORD *)(v1 + 2544) )
        return v6;
      v13 = sched_clock(v11);
      ipc_log_string(v12, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_runtime_resume", v13 - v4, (v13 - v4) / 0x3E8);
    }
    return 0;
  }
  v6 = geni_se_resources_on(v1);
  if ( !v6 )
    goto LABEL_17;
LABEL_13:
  ipc_log_string(*(_QWORD *)(v1 + 2528), "%s geni_se_resources_on failed %d\n", "geni_i3c_runtime_resume", v6);
  if ( *(_QWORD *)(v1 + 8) )
LABEL_14:
    i3c_trace_log();
  return v6;
}
