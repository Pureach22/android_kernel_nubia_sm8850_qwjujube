__int64 __fastcall msm_vidc_memory_alloc_map(__int64 a1, __int64 a2)
{
  unsigned int v3; // w1
  int v4; // w20
  __int64 v5; // t2
  unsigned __int64 context_bank_for_region; // x0
  __int64 v7; // x0

  if ( a2 )
  {
    v5 = a2 + 20;
    v3 = *(_DWORD *)(a2 + 20);
    v4 = *(_DWORD *)(v5 + 4);
    *(_QWORD *)(a2 + 72) = 4;
    context_bank_for_region = msm_vidc_get_context_bank_for_region(a1, v3);
    if ( context_bank_for_region )
    {
      v7 = dma_alloc_attrs(
             *(_QWORD *)(context_bank_for_region + 24),
             (int)((v4 + 4095) & 0xFFFFF000),
             a2 + 64,
             3264,
             *(_QWORD *)(a2 + 72));
      *(_QWORD *)(a2 + 56) = v7;
      if ( v7 )
      {
        if ( (msm_vidc_debug & 2) != 0 )
        {
          buf_name(*(_DWORD *)(a2 + 16));
          printk(&unk_837DB, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_alloc_map");
        }
        return 0;
      }
      else
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_89309, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_alloc_map");
        return 4294967284LL;
      }
    }
    else
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8B6CC, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_alloc_map");
      return 4294967291LL;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_memory_alloc_map");
    return 4294967274LL;
  }
}
