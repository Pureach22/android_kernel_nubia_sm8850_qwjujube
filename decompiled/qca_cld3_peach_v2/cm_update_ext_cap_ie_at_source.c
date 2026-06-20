__int64 __fastcall cm_update_ext_cap_ie_at_source(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8

  if ( result )
  {
    v10 = *(_QWORD *)(result + 2800);
    if ( v10 )
    {
      result = *(_QWORD *)(v10 + 16);
      if ( result )
      {
        result = wmi_service_enabled(result, 0x9Eu, a3, a4, a5, a6, a7, a8, a9, a10);
        if ( (result & 1) != 0 )
        {
          result = (__int64)wlan_get_ie_ptr_from_eid(0x7Fu, *(unsigned __int8 **)(a2 + 8), *(_DWORD *)a2);
          if ( result )
            *(_QWORD *)(result + 2) |= 0x400000uLL;
        }
      }
    }
  }
  return result;
}
