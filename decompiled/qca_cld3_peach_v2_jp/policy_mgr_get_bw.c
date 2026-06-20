__int64 __fastcall policy_mgr_get_bw(
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

  if ( a1 < 8 )
    return dword_A300F0[a1];
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Unknown channel BW type %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "policy_mgr_get_bw",
    a1,
    v9,
    v10);
  return 0;
}
