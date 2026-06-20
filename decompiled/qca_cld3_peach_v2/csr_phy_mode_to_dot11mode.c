__int64 __fastcall csr_phy_mode_to_dot11mode(
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

  if ( a1 < 0x29 )
    return dword_B09958[a1];
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: invalid phy mode %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "csr_phy_mode_to_dot11mode",
    a1,
    v9,
    v10);
  return 14;
}
