__int64 __fastcall msm_geni_serial_cons_pm(__int64 result, int a2, int a3)
{
  __int64 v3; // x19
  __int64 v4; // x21

  if ( a2 || a3 != 3 )
  {
    if ( a2 == 3 && !a3 )
    {
      *(_DWORD *)(result + 1116) = 1;
      v4 = result;
      ipc_log_string(
        *(_QWORD *)(result + 960),
        "%s: enable:%d ser_clk_cfg:%lu\n",
        "msm_geni_enable_disable_se_clk",
        0,
        *(_QWORD *)(result + 1128));
      _ftrace_dbg(*(_QWORD *)(v4 + 344), "%s: enable:%d ser_clk_cfg:%lu\n");
      writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(v4 + 16) + 72LL));
      writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(v4 + 16) + 76LL));
      readl_relaxed((unsigned int *)(*(_QWORD *)(v4 + 16) + 72LL));
      return msm_geni_serial_resources_off(v4);
    }
  }
  else
  {
    v3 = result;
    msm_geni_serial_resources_on(result);
    ipc_log_string(
      *(_QWORD *)(v3 + 960),
      "%s: enable:%d ser_clk_cfg:%lu\n",
      "msm_geni_enable_disable_se_clk",
      1,
      *(_QWORD *)(v3 + 1128));
    _ftrace_dbg(*(_QWORD *)(v3 + 344), "%s: enable:%d ser_clk_cfg:%lu\n");
    writel_relaxed(*(_DWORD *)(v3 + 1128), (unsigned int *)(*(_QWORD *)(v3 + 16) + 72LL));
    writel_relaxed(*(_DWORD *)(v3 + 1128), (unsigned int *)(*(_QWORD *)(v3 + 16) + 76LL));
    result = readl_relaxed((unsigned int *)(*(_QWORD *)(v3 + 16) + 72LL));
    *(_DWORD *)(v3 + 1116) = 0;
  }
  return result;
}
