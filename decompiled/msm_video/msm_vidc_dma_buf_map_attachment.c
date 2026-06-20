_QWORD *__fastcall msm_vidc_dma_buf_map_attachment(__int64 a1, __int64 a2)
{
  _QWORD *result; // x0
  _QWORD *v4; // x20
  __int64 v5; // x4

  if ( a2 )
  {
    result = (_QWORD *)dma_buf_map_attachment_unlocked(a2, 0);
    if ( result && (unsigned __int64)result < 0xFFFFFFFFFFFFF001LL )
    {
      if ( *result )
        return result;
      v4 = result;
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_96ED0, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_buf_map_attachment");
      dma_buf_unmap_attachment_unlocked(a2, v4, 0);
    }
    else if ( (msm_vidc_debug & 1) != 0 )
    {
      if ( result )
        v5 = (unsigned int)result;
      else
        v5 = 0xFFFFFFFFLL;
      printk(&unk_81603, "err ", 0xFFFFFFFFLL, "codec", v5);
    }
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_buf_map_attachment");
  }
  return nullptr;
}
