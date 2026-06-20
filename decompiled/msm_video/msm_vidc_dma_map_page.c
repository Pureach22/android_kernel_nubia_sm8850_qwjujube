__int64 __fastcall msm_vidc_dma_map_page(__int64 a1, unsigned int *a2)
{
  unsigned int v2; // w8
  char v3; // w9
  unsigned int *v5; // x19
  unsigned __int64 context_bank_for_region; // x0
  __int64 v7; // x0

  if ( a2 )
  {
    v2 = a2[20];
    if ( v2 )
    {
LABEL_3:
      v3 = msm_vidc_debug;
      a2[20] = v2 + 1;
      if ( (v3 & 4) != 0 )
      {
        buf_name(a2[4]);
        printk(&unk_8163D, "low ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_map_page");
      }
      return 0;
    }
    v5 = a2;
    context_bank_for_region = msm_vidc_get_context_bank_for_region(a1, a2[5]);
    if ( context_bank_for_region )
    {
      v7 = dma_map_page_attrs(
             *(_QWORD *)(context_bank_for_region + 24),
             ((*((_QWORD *)v5 + 13) >> 6) & 0x3FFFFFFFFFFFFC0LL) - ((__int64)memstart_addr >> 12 << 6) - 0x140000000LL,
             0,
             v5[6],
             v5[28],
             0);
      if ( v7 != -1 )
      {
        v2 = v5[20];
        a2 = v5;
        *((_QWORD *)v5 + 8) = v7;
        goto LABEL_3;
      }
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_83835, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_map_page");
      return 4294967284LL;
    }
    else
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_8B6CC, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_map_page");
      return 4294967291LL;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_dma_map_page");
    return 4294967274LL;
  }
}
