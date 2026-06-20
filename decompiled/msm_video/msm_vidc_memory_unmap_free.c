__int64 __fastcall msm_vidc_memory_unmap_free(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x22
  __int64 v3; // x24
  unsigned __int64 context_bank_for_region; // x0
  __int64 v6; // x25

  if ( a2 && *(_QWORD *)(a2 + 64) && (v2 = (_QWORD *)(a2 + 56), *(_QWORD *)(a2 + 56)) )
  {
    v3 = a2;
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v6 = a1;
      buf_name(*(_DWORD *)(a2 + 16));
      printk(&unk_89347, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_unmap_free");
      a1 = v6;
      a2 = v3;
    }
    context_bank_for_region = msm_vidc_get_context_bank_for_region(a1, *(_DWORD *)(a2 + 20));
    if ( context_bank_for_region )
    {
      dma_free_attrs(
        *(_QWORD *)(context_bank_for_region + 24),
        *(unsigned int *)(v3 + 24),
        *(_QWORD *)(v3 + 56),
        *(_QWORD *)(v3 + 64),
        *(_QWORD *)(v3 + 72));
      *v2 = 0;
      v2[1] = 0;
      return 0;
    }
    else
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8B6CC, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_unmap_free");
      return 4294967291LL;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_unmap_free");
    return 4294967274LL;
  }
}
