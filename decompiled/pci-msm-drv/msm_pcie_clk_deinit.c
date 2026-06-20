__int64 __fastcall msm_pcie_clk_deinit(__int64 a1)
{
  unsigned int v2; // w8
  unsigned int i; // w21
  __int64 v4; // x10
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 result; // x0
  __int64 v9; // x1

  if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: entry\n", "msm_pcie_clk_deinit", *(_DWORD *)(a1 + 1348));
    ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: entry\n", "msm_pcie_clk_deinit", *(_DWORD *)(a1 + 1348));
  }
  v2 = *(_DWORD *)(a1 + 856);
  if ( v2 )
  {
    for ( i = 0; i < v2; ++i )
    {
      v4 = *(_QWORD *)(a1 + 864);
      v5 = *(_QWORD *)(v4 + 24LL * (int)i);
      if ( v5 )
      {
        clk_disable(*(_QWORD *)(v4 + 24LL * (int)i));
        clk_unprepare(v5);
        v2 = *(_DWORD *)(a1 + 856);
      }
    }
  }
  msm_pcie_icc_vote(a1, 0, 0, 0);
  v6 = *(_QWORD *)(a1 + 1032);
  if ( v6 )
  {
    v7 = *(_QWORD *)(a1 + 1048);
    if ( v7 )
      clk_set_parent(v6, v7);
  }
  result = *(_QWORD *)(a1 + 1016);
  if ( result )
  {
    v9 = *(_QWORD *)(a1 + 1048);
    if ( v9 )
      result = clk_set_parent(result, v9);
  }
  if ( a1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 1704), "DBG1:%s: RC%d: exit\n", "msm_pcie_clk_deinit", *(_DWORD *)(a1 + 1348));
    return ipc_log_string(*(_QWORD *)(a1 + 1696), "%s: RC%d: exit\n", "msm_pcie_clk_deinit", *(_DWORD *)(a1 + 1348));
  }
  return result;
}
