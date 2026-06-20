__int64 __fastcall policy_mgr_get_qdf_mode_from_pm(
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

  if ( a1 < 7 )
    return (unsigned int)dword_9E73F8[a1];
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Unsupported policy mgr mode (%d)",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "policy_mgr_get_qdf_mode_from_pm",
    a1,
    v9,
    v10);
  return 17;
}
