__int64 __fastcall msm_geni_serial_resources_off(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x21
  __int64 v4; // x22
  unsigned int v5; // w0
  unsigned int v6; // w20
  const char *v7; // x21
  __int64 v9; // x0

  v1 = *(_QWORD *)(a1 + 648);
  v3 = *(_QWORD *)(a1 + 656);
  v4 = *(_QWORD *)(a1 + 664);
  clk_disable(v1);
  clk_unprepare(v1);
  clk_disable(v3);
  clk_unprepare(v3);
  clk_disable(v4);
  clk_unprepare(v4);
  v5 = geni_icc_disable(a1 + 712);
  if ( v5 )
  {
    v6 = v5;
    v7 = "%s: Error %d geni_icc_disable failed\n";
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Error %d geni_icc_disable failed\n", "msm_geni_serial_resources_off", v5);
  }
  else
  {
    v9 = *(_QWORD *)(a1 + 672);
    if ( *(_DWORD *)(a1 + 1516) )
    {
      v6 = pinctrl_select_state(v9, *(_QWORD *)(a1 + 696));
      if ( !v6 )
        return v6;
      v7 = "%s: Error %d pinctrl sleep failed\n";
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Error %d pinctrl sleep failed\n", "msm_geni_serial_resources_off", v6);
    }
    else
    {
      v6 = pinctrl_select_state(v9, *(_QWORD *)(a1 + 680));
      if ( !v6 )
        return v6;
      v7 = "%s: Error %d pinctrl shutdown state failed\n";
      ipc_log_string(
        *(_QWORD *)(a1 + 960),
        "%s: Error %d pinctrl shutdown state failed\n",
        "msm_geni_serial_resources_off",
        v6);
    }
  }
  _ftrace_dbg(*(_QWORD *)(a1 + 344), v7);
  return v6;
}
