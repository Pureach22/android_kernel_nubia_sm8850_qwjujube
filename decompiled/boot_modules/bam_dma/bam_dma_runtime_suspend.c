__int64 __fastcall bam_dma_runtime_suspend(__int64 a1)
{
  clk_disable(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 448LL));
  return 0;
}
