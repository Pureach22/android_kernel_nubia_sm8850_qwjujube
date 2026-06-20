__int64 __fastcall msm_geni_enable_disable_se_clk(_QWORD *a1, char a2)
{
  unsigned int *v4; // x19
  __int64 v5; // t1
  unsigned int v6; // w20
  __int64 v7; // t1

  ipc_log_string(a1[120], "%s: enable:%d ser_clk_cfg:%lu\n", "msm_geni_enable_disable_se_clk", a2 & 1, a1[141]);
  _ftrace_dbg(a1[43], "%s: enable:%d ser_clk_cfg:%lu\n");
  if ( (a2 & 1) != 0 )
  {
    v5 = a1[2];
    v4 = (unsigned int *)(a1 + 2);
    writel_relaxed(v4[278], (unsigned int *)(v5 + 72));
    v6 = v4[278];
  }
  else
  {
    v7 = a1[2];
    v4 = (unsigned int *)(a1 + 2);
    v6 = 1;
    writel_relaxed(1u, (unsigned int *)(v7 + 72));
  }
  writel_relaxed(v6, (unsigned int *)(*(_QWORD *)v4 + 76LL));
  return readl_relaxed((unsigned int *)(*(_QWORD *)v4 + 72LL));
}
