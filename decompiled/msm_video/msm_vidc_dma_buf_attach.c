unsigned __int64 __fastcall msm_vidc_dma_buf_attach(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 result; // x0
  __int64 v4; // x4

  if ( !a2 || !a3 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_buf_attach");
    return 0;
  }
  result = dma_buf_attach(a2, a3);
  if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      if ( result )
        v4 = (unsigned int)result;
      else
        v4 = 0xFFFFFFFFLL;
      printk(&unk_82415, "err ", 0xFFFFFFFFLL, "codec", v4);
    }
    return 0;
  }
  return result;
}
