__int64 __fastcall msm_pcie_pipe_clk_deinit(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w8
  unsigned int i; // w21
  __int64 v4; // x10
  __int64 v5; // x20

  v1 = result;
  if ( result )
  {
    ipc_log_string(
      *(_QWORD *)(result + 1704),
      "DBG1:%s: RC%d: entry\n",
      "msm_pcie_pipe_clk_deinit",
      *(_DWORD *)(result + 1348));
    result = ipc_log_string(
               *(_QWORD *)(v1 + 1696),
               "%s: RC%d: entry\n",
               "msm_pcie_pipe_clk_deinit",
               *(_DWORD *)(v1 + 1348));
  }
  v2 = *(_DWORD *)(v1 + 840);
  if ( v2 )
  {
    for ( i = 0; i < v2; ++i )
    {
      v4 = *(_QWORD *)(v1 + 848);
      v5 = *(_QWORD *)(v4 + 24LL * (int)i);
      if ( v5 )
      {
        clk_disable(*(_QWORD *)(v4 + 24LL * (int)i));
        result = clk_unprepare(v5);
        v2 = *(_DWORD *)(v1 + 840);
      }
    }
  }
  if ( v1 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 1704), "DBG1:%s: RC%d: exit\n", "msm_pcie_pipe_clk_deinit", *(_DWORD *)(v1 + 1348));
    return ipc_log_string(
             *(_QWORD *)(v1 + 1696),
             "%s: RC%d: exit\n",
             "msm_pcie_pipe_clk_deinit",
             *(_DWORD *)(v1 + 1348));
  }
  return result;
}
