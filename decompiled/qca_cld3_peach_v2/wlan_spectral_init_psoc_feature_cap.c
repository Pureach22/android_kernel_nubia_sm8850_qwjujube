__int64 __fastcall wlan_spectral_init_psoc_feature_cap(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 values; // x0
  int v11; // w8
  __int64 result; // x0
  unsigned int v13; // w8

  if ( a1 )
  {
    values = cfg_psoc_get_values(a1);
    v11 = *(_DWORD *)(a1 + 28);
    if ( *(_BYTE *)(values + 784) == 1 )
    {
      result = 0;
      v13 = v11 | 0x800000;
    }
    else
    {
      result = 0;
      v13 = v11 & 0xFF7FFFFF;
    }
    *(_DWORD *)(a1 + 28) = v13;
  }
  else
  {
    qdf_trace_msg(0x56u, 2u, "%s: PSOC is NULL!", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_spectral_init_psoc_feature_cap");
    return 4;
  }
  return result;
}
