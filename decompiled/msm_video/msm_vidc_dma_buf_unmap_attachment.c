__int64 __fastcall msm_vidc_dma_buf_unmap_attachment(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a2 && a3 )
  {
    dma_buf_unmap_attachment_unlocked(a2, a3, 0);
    return 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_buf_unmap_attachment");
    return 4294967274LL;
  }
}
