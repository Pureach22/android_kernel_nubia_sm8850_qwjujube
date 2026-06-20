bool __fastcall wlan_hdd_validate_modules_state(
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
  unsigned int v9; // w19

  v9 = *(_DWORD *)(a1 + 1464);
  if ( v9 != 1 )
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Modules not enabled, Present status: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_hdd_validate_modules_state",
      v9);
  return v9 == 1;
}
