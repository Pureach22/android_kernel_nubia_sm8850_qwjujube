__int64 __fastcall wlan_serialization_validate_cmdtype(
        unsigned int a1,
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

  if ( a1 < 0x22 )
    return 0;
  qdf_trace_msg(
    0x4Cu,
    2u,
    "%s: Invalid cmd %d passed",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_serialization_validate_cmdtype",
    a1,
    v9,
    v10);
  return 4;
}
