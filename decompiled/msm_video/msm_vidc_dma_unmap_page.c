__int64 __fastcall msm_vidc_dma_unmap_page(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // w8
  unsigned int v7; // w1
  unsigned __int64 context_bank_for_region; // x0
  unsigned __int64 v10; // x20

  if ( !a2 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_unmap_page");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v5 = *(_DWORD *)(a2 + 80);
  if ( !v5 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_8B70E, "err ", 0xFFFFFFFFLL, "codec", a5);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v7 = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(a2 + 80) = v5 - 1;
  context_bank_for_region = msm_vidc_get_context_bank_for_region(a1, v7);
  if ( context_bank_for_region )
  {
    if ( (msm_vidc_debug & 4) != 0 )
    {
      v10 = context_bank_for_region;
      buf_name(*(_DWORD *)(a2 + 16));
      printk(&unk_806EB, "low ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_unmap_page");
      context_bank_for_region = v10;
      if ( *(_DWORD *)(a2 + 80) )
        return 0;
    }
    else if ( *(_DWORD *)(a2 + 80) )
    {
      return 0;
    }
    dma_unmap_page_attrs(
      *(_QWORD *)(context_bank_for_region + 24),
      *(_QWORD *)(a2 + 64),
      *(unsigned int *)(a2 + 24),
      *(unsigned int *)(a2 + 112),
      0);
    *(_QWORD *)(a2 + 64) = 0;
    return 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8B6CC, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_unmap_page");
    return 4294967291LL;
  }
}
