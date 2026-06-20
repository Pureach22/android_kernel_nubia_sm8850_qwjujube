__int64 __fastcall msm_vidc_get_properties(__int64 a1)
{
  __int64 result; // x0

  if ( a1 && (msm_vidc_debug & 4) != 0 )
    printk(&unk_8FEFB, "low ", a1 + 340, "msm_vidc_get_properties", 50331914);
  result = venus_hfi_session_property(a1, 50331914, 11, 0, 0, 0, 0);
  if ( !(_DWORD)result )
  {
    if ( a1 && (msm_vidc_debug & 4) != 0 )
      printk(&unk_8FEFB, "low ", a1 + 340, "msm_vidc_get_properties", 50331915);
    result = venus_hfi_session_property(a1, 50331915, 11, 0, 0, 0, 0);
    if ( !(_DWORD)result )
    {
      if ( *(_DWORD *)(a1 + 308) == 2 )
        return 0;
      if ( a1 )
      {
        if ( (msm_vidc_debug & 4) != 0 )
          printk(&unk_8FEFB, "low ", a1 + 340, "msm_vidc_get_properties", 50331976);
      }
      result = venus_hfi_session_property(a1, 50331976, 11, 1, 0, 0, 0);
      if ( !(_DWORD)result )
        return 0;
    }
  }
  return result;
}
