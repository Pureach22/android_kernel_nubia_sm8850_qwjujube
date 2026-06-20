__int64 __fastcall msm_vidc_iommu_unmap(__int64 a1, __int64 a2)
{
  unsigned __int64 context_bank_for_region; // x0
  unsigned __int64 v5; // x20

  if ( a2 )
  {
    context_bank_for_region = msm_vidc_get_context_bank_for_region(a1, *(_DWORD *)(a2 + 20));
    if ( context_bank_for_region )
    {
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v5 = context_bank_for_region;
        printk(&unk_893AD, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_iommu_unmap");
        context_bank_for_region = v5;
      }
      iommu_unmap(*(_QWORD *)(context_bank_for_region + 32), *(_QWORD *)(a2 + 64), *(unsigned int *)(a2 + 24));
      *(_QWORD *)(a2 + 64) = 0;
      *(_QWORD *)(a2 + 104) = 0;
      *(_DWORD *)(a2 + 24) = 0;
      return 0;
    }
    else
    {
      if ( (msm_vidc_debug & 1) != 0 )
        printk(&unk_85C84, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_iommu_unmap");
      return 4294967291LL;
    }
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_iommu_unmap");
    return 4294967274LL;
  }
}
