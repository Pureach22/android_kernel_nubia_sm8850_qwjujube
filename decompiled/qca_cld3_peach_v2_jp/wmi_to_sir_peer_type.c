__int64 __fastcall wmi_to_sir_peer_type(
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

  if ( a1 < 5 && ((0x17u >> a1) & 1) != 0 )
    return dword_A18C00[a1];
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Cannot map wmi_peer_type %d to HAL peer type",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wmi_to_sir_peer_type",
    a1,
    v9,
    v10);
  return 6;
}
