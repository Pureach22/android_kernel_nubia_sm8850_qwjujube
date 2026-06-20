__int64 __fastcall bam_dma_suspend(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x0

  v1 = *(_QWORD **)(a1 + 152);
  pm_runtime_force_suspend(a1);
  clk_unprepare(v1[56]);
  v2 = v1[67];
  if ( v2 )
    ipc_log_string(v2, "%s ret:%d\n", "bam_dma_suspend", 0);
  _ftrace_dbg(v1[1], "%s ret:%d\n");
  return 0;
}
