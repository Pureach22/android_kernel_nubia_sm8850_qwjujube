__int64 __fastcall a6xx_probe(__int64 a1, int a2, __int64 a3)
{
  __int64 match_data; // x19
  __int64 result; // x0

  match_data = of_device_get_match_data(a1 + 16);
  memset((void *)match_data, 0, 0x5FE0u);
  *(_DWORD *)(match_data + 20888) = 332456898;
  result = a6xx_probe_common(a1, match_data, a2, a3);
  if ( !(_DWORD)result )
  {
    result = adreno_dispatcher_init(match_data);
    if ( !(_DWORD)result )
    {
      init_timer_key(match_data + 8792, kgsl_timer, 0, 0, 0);
      *(_QWORD *)(match_data + 8760) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(match_data + 8768) = match_data + 8768;
      *(_QWORD *)(match_data + 8776) = match_data + 8768;
      *(_QWORD *)(match_data + 8784) = kgsl_idle_check;
      return 0;
    }
  }
  return result;
}
