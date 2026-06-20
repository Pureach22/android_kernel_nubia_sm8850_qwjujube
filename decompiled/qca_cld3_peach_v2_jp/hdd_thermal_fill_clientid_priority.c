__int64 __fastcall hdd_thermal_fill_clientid_priority(
        __int64 result,
        char a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x5
  const char *v14; // x2
  __int64 v15; // x4

  if ( *(_BYTE *)(result + 6922) == 1 )
  {
    if ( a2 == 2 )
    {
      *(_DWORD *)(a5 + 20) = 2;
      *(_BYTE *)(a5 + 24) = a4;
      v14 = "%s: Thermal client:%d priority_wpps: %d";
      *(_DWORD *)(a5 + 36) = 50;
      v13 = a4;
      v15 = 2;
    }
    else
    {
      if ( a2 != 1 )
        return result;
      *(_DWORD *)(a5 + 20) = 1;
      *(_BYTE *)(a5 + 24) = a3;
      v13 = a3;
      v14 = "%s: Thermal client:%d priority_apps: %d";
      v15 = 1;
    }
    return qdf_trace_msg(
             0x33u,
             8u,
             v14,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             "hdd_thermal_fill_clientid_priority",
             v15,
             v13);
  }
  return result;
}
