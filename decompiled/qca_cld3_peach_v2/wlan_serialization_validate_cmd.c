__int64 __fastcall wlan_serialization_validate_cmd(
        unsigned int a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a1 <= 0x35 && a2 < 0x22 )
    return 0;
  qdf_trace_msg(
    0x4Cu,
    2u,
    "%s: Invalid cmd or comp passed comp %d type %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_serialization_validate_cmd",
    a1,
    a2,
    v10,
    v11);
  return 4;
}
