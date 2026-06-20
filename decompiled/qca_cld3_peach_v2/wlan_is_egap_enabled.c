bool __fastcall wlan_is_egap_enabled(
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
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 )
    return *(_BYTE *)(a1 + 136) == 1 && *(_BYTE *)(a1 + 137) == 1 && *(_DWORD *)(a1 + 148);
  qdf_trace_msg(
    0x5Du,
    2u,
    "%s: green ap context passed is NULL",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_is_egap_enabled",
    v9,
    v10);
  return 1;
}
