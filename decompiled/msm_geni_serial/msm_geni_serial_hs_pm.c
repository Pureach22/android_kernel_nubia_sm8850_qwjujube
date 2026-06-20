__int64 __fastcall msm_geni_serial_hs_pm(__int64 result, int a2, int a3)
{
  int v3; // w8
  __int64 v4; // x19
  __int64 v5; // x21

  if ( (*(_WORD *)(*(_QWORD *)(result + 344) + 488LL) & 7) != 0 )
  {
    if ( a3 == 4 )
      v3 = 3;
    else
      v3 = a3;
    if ( a2 || v3 != 3 )
    {
      if ( a2 == 3 && !v3 )
      {
        *(_DWORD *)(result + 1116) = 1;
        v5 = result;
        ipc_log_string(
          *(_QWORD *)(result + 960),
          "%s: enable:%d ser_clk_cfg:%lu\n",
          "msm_geni_enable_disable_se_clk",
          0,
          *(_QWORD *)(result + 1128));
        _ftrace_dbg(*(_QWORD *)(v5 + 344), "%s: enable:%d ser_clk_cfg:%lu\n");
        writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(v5 + 16) + 72LL));
        writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(v5 + 16) + 76LL));
        readl_relaxed((unsigned int *)(*(_QWORD *)(v5 + 16) + 72LL));
        return msm_geni_serial_resources_off(v5);
      }
    }
    else
    {
      v4 = result;
      msm_geni_serial_resources_on(result);
      ipc_log_string(
        *(_QWORD *)(v4 + 960),
        "%s: enable:%d ser_clk_cfg:%lu\n",
        "msm_geni_enable_disable_se_clk",
        1,
        *(_QWORD *)(v4 + 1128));
      _ftrace_dbg(*(_QWORD *)(v4 + 344), "%s: enable:%d ser_clk_cfg:%lu\n");
      writel_relaxed(*(_DWORD *)(v4 + 1128), (unsigned int *)(*(_QWORD *)(v4 + 16) + 72LL));
      writel_relaxed(*(_DWORD *)(v4 + 1128), (unsigned int *)(*(_QWORD *)(v4 + 16) + 76LL));
      result = readl_relaxed((unsigned int *)(*(_QWORD *)(v4 + 16) + 72LL));
      *(_DWORD *)(v4 + 1116) = 0;
    }
  }
  return result;
}
