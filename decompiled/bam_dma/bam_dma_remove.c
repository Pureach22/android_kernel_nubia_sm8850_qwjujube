__int64 __fastcall bam_dma_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  unsigned __int64 v5; // x21
  __int64 v6; // x1
  __int64 v7; // x19

  v1 = *(_QWORD *)(a1 + 168);
  v3 = *(_QWORD *)(v1 + 536);
  if ( v3 )
    ipc_log_string(v3, "%s ret:%d\n", "bam_dma_remove", 0);
  _ftrace_dbg(*(_QWORD *)(v1 + 8), "%s ret:%d\n", "bam_dma_remove", 0);
  if ( *(_QWORD *)(v1 + 536) )
    ipc_log_context_destroy();
  pm_runtime_force_suspend(a1 + 16);
  of_dma_controller_free(*(_QWORD *)(a1 + 760));
  dma_async_device_unregister(v1 + 16);
  writel_relaxed(
    0,
    *(_QWORD *)v1
  + *(unsigned int *)(*(_QWORD *)(v1 + 440) + 192LL)
  + (unsigned int)(*(_DWORD *)(v1 + 424) * *(_DWORD *)(*(_QWORD *)(v1 + 440) + 204LL)));
  devm_free_irq(*(_QWORD *)(v1 + 8), *(unsigned int *)(v1 + 456), v1);
  if ( *(_DWORD *)(v1 + 416) )
  {
    v4 = 0;
    v5 = 0;
    do
    {
      bam_dma_terminate_all(*(_QWORD *)(v1 + 408) + v4);
      tasklet_kill(*(_QWORD *)(v1 + 408) + v4 + 112);
      if ( *(_QWORD *)(*(_QWORD *)(v1 + 408) + v4 + 344) )
      {
        if ( *(_BYTE *)(v1 + 532) )
          v6 = 256;
        else
          v6 = 0x8000;
        dma_free_attrs(*(_QWORD *)(v1 + 8), v6);
      }
      ++v5;
      v4 += 408;
    }
    while ( v5 < *(unsigned int *)(v1 + 416) );
  }
  tasklet_kill(v1 + 464);
  v7 = *(_QWORD *)(v1 + 448);
  clk_disable(v7);
  return clk_unprepare(v7);
}
