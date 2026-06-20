__int64 __fastcall msm_vidc_dma_fence_release(__int64 a1)
{
  __int64 v2; // x19

  if ( (msm_vidc_debug & 4) != 0 )
  {
    v2 = a1;
    printk(&unk_96EA8, "low ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_fence_release");
    a1 = v2;
  }
  return vfree(a1 - 184);
}
