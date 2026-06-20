__int64 __fastcall msm_geni_serial_resources_on(__int64 a1)
{
  __int64 v1; // x21
  unsigned __int64 v3; // x20
  unsigned int v4; // w21
  __int64 v5; // x0
  const char *v6; // x20
  __int64 v7; // x0
  __int64 v9; // x22
  __int64 v10; // x24
  __int64 v11; // x23
  unsigned int v12; // w0

  v1 = *(_QWORD *)(a1 + 968);
  if ( v1 )
  {
    if ( *(_DWORD *)(a1 + 916) )
    {
      v3 = sched_clock();
      ipc_log_string(v1, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_resources_on", v3, v3 / 0x3E8);
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
  v4 = pinctrl_select_state(*(_QWORD *)(a1 + 672), *(_QWORD *)(a1 + 688));
  v5 = *(_QWORD *)(a1 + 960);
  if ( v4 )
  {
    v6 = "%s: Error %d pinctrl_select_state failed\n";
LABEL_13:
    ipc_log_string(v5, v6, "msm_geni_serial_resources_on", v4);
    goto LABEL_14;
  }
  ipc_log_string(v5, "%s: geni_icc_enable\n", "msm_geni_serial_resources_on");
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: geni_icc_enable\n");
  v4 = geni_icc_enable(a1 + 712);
  v7 = *(_QWORD *)(a1 + 960);
  if ( !v4 )
  {
    ipc_log_string(v7, "%s: ICC BW voting\n", "msm_geni_serial_resources_on");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: ICC BW voting\n");
    v4 = geni_icc_set_bw(a1 + 712);
    v5 = *(_QWORD *)(a1 + 960);
    if ( v4 )
    {
      v6 = "%s: Error %d ICC BW voting failed\n";
    }
    else
    {
      ipc_log_string(v5, "%s: geni_se_common_clks_on\n", "msm_geni_serial_resources_on");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: geni_se_common_clks_on\n");
      v9 = *(_QWORD *)(a1 + 656);
      v10 = *(_QWORD *)(a1 + 648);
      v11 = *(_QWORD *)(a1 + 664);
      v4 = clk_prepare(v9);
      if ( !v4 )
      {
        v4 = clk_enable(v9);
        if ( !v4 )
        {
          v4 = clk_prepare_enable(v11);
          if ( !v4 )
          {
            v12 = clk_prepare_enable(v10);
            if ( !v12 )
            {
              ipc_log_string(*(_QWORD *)(a1 + 960), "%s: GENI_OUTPUT_CTRL write\n", "msm_geni_serial_resources_on");
              _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: GENI_OUTPUT_CTRL write\n");
              writel_relaxed(127, *(_QWORD *)(a1 + 16) + 36LL);
              _const_udelay(42950);
              geni_capture_stop_time(
                *(_QWORD *)(a1 + 968),
                "msm_geni_serial_resources_on",
                *(unsigned int *)(a1 + 916),
                v3,
                0,
                0);
              return 0;
            }
            v4 = v12;
            clk_disable(v11);
            clk_unprepare(v11);
          }
          clk_disable(v9);
        }
        clk_unprepare(v9);
      }
      v5 = *(_QWORD *)(a1 + 960);
      v6 = "%s: Error %d geni_se_common_clks_on failed\n";
    }
    goto LABEL_13;
  }
  v6 = "%s: Error %d geni_icc_enable failed\n";
  ipc_log_string(v7, "%s: Error %d geni_icc_enable failed\n", "msm_geni_serial_resources_on", v4);
LABEL_14:
  _ftrace_dbg(*(_QWORD *)(a1 + 344), v6);
  return v4;
}
