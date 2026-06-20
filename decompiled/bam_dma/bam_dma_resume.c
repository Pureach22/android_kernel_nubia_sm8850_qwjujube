__int64 __fastcall bam_dma_resume(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 result; // x0
  __int64 v4; // x0

  v1 = *(_QWORD **)(a1 + 152);
  result = clk_prepare(v1[56]);
  if ( !(_DWORD)result )
  {
    pm_runtime_force_resume(a1);
    v4 = v1[67];
    if ( v4 )
      ipc_log_string(v4, "%s ret:%d\n", "bam_dma_resume", 0);
    _ftrace_dbg(v1[1], "%s ret:%d\n");
    return 0;
  }
  return result;
}
