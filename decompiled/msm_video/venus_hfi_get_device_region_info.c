unsigned __int64 __fastcall venus_hfi_get_device_region_info(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8
  unsigned __int64 result; // x0
  unsigned __int64 v4; // x8

  if ( a2 - 4 <= 0xFFFFFFFC )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8DDE4, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_get_device_region_info");
    return 0;
  }
  v2 = *(_QWORD *)(a1 + 3904);
  result = *(_QWORD *)(v2 + 128);
  v4 = result + 32LL * *(unsigned int *)(v2 + 136);
  if ( result >= v4 )
    goto LABEL_7;
  while ( *(_DWORD *)(result + 24) != a2 )
  {
    result += 32LL;
    if ( result >= v4 )
      goto LABEL_7;
  }
  if ( !result )
  {
LABEL_7:
    if ( (msm_vidc_debug & 2) != 0 )
    {
      device_region_name(a2);
      printk(&unk_9292C, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_get_device_region_info");
    }
    return 0;
  }
  return result;
}
