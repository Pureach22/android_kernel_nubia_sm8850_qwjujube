__int64 __fastcall msm_vidc_check_mmrm_support(__int64 result)
{
  __int64 v1; // x19

  v1 = result;
  if ( *(_BYTE *)(*(_QWORD *)(result + 3912) + 204LL) == 1 )
  {
    result = mmrm_client_check_scaling_supported(0, 0);
    if ( (result & 1) == 0 )
    {
      if ( (msm_vidc_debug & 1) != 0 )
        result = printk(&unk_93281, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_check_mmrm_support");
      *(_BYTE *)(*(_QWORD *)(v1 + 3912) + 204LL) = 0;
    }
  }
  if ( (msm_vidc_debug & 2) != 0 )
    return printk(&unk_84479, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_check_mmrm_support");
  return result;
}
