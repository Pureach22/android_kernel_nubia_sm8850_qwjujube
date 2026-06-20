unsigned __int64 __fastcall msm_vidc_dma_buf_attach_ext(__int64 a1, __int64 a2, __int64 *a3, char a4)
{
  _QWORD *context_bank_for_device; // x0
  int v9; // w24
  char v10; // w0
  void *v11; // x0
  unsigned __int64 result; // x0
  __int64 v13; // x8
  __int64 v14; // x4

  if ( !a2 || !a3 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_buf_attach_ext");
    return 0;
  }
  context_bank_for_device = msm_vidc_get_context_bank_for_device(a1, a3);
  if ( !context_bank_for_device )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8AA49, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_buf_attach_ext");
    return 0;
  }
  v9 = context_bank_for_device[5] & 0xE;
  v10 = mem_buf_dma_buf_exclusive_owner(a2);
  if ( v9 )
  {
    if ( (v10 & 1) == 0 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v11 = &unk_876EA;
LABEL_15:
        printk(v11, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_buf_attach_ext");
        return 0;
      }
      return 0;
    }
  }
  else if ( (v10 & 1) != 0 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v11 = &unk_8AA92;
      goto LABEL_15;
    }
    return 0;
  }
  result = dma_buf_attach(a2, a3);
  if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      if ( result )
        v14 = (unsigned int)result;
      else
        v14 = 0xFFFFFFFFLL;
      printk(&unk_82415, "err ", 0xFFFFFFFFLL, "codec", v14);
    }
    return 0;
  }
  v13 = *(_QWORD *)(result + 72);
  *(_QWORD *)(result + 72) = v13 | 0x20;
  if ( (a4 & 1) != 0 && !*(_QWORD *)(a1 + 4736) )
    *(_QWORD *)(result + 72) = v13 | 0x20020;
  return result;
}
