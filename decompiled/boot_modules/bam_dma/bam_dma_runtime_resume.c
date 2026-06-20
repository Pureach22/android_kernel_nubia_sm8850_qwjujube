__int64 __fastcall bam_dma_runtime_resume(__int64 a1)
{
  int v2; // w0
  unsigned int v4; // w20

  v2 = clk_enable(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 448LL));
  if ( (v2 & 0x80000000) == 0 )
    return 0;
  v4 = v2;
  dev_err(a1, "clk_enable failed: %d\n", v2);
  return v4;
}
