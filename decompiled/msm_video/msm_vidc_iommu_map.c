__int64 __fastcall msm_vidc_iommu_map(__int64 a1, __int64 a2)
{
  unsigned __int64 context_bank_for_region; // x0
  __int64 result; // x0
  __int64 v5; // x4
  unsigned int v6; // w19

  if ( a2 )
  {
    context_bank_for_region = msm_vidc_get_context_bank_for_region(a1, *(_DWORD *)(a2 + 20));
    if ( context_bank_for_region )
    {
      result = iommu_map(
                 *(_QWORD *)(context_bank_for_region + 32),
                 *(_QWORD *)(a2 + 64),
                 *(_QWORD *)(a2 + 104),
                 *(unsigned int *)(a2 + 24),
                 19,
                 3264);
      if ( (_DWORD)result )
      {
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v5 = *(_QWORD *)(a2 + 64);
          v6 = result;
          printk(&unk_85CD5, "err ", 0xFFFFFFFFLL, "codec", v5);
          return v6;
        }
      }
      else
      {
        if ( (msm_vidc_debug & 2) != 0 )
          printk(&unk_893AD, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_iommu_map");
        return 0;
      }
    }
    else
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_85C84, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_iommu_map");
      return 4294967291LL;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_iommu_map");
    return 4294967274LL;
  }
  return result;
}
