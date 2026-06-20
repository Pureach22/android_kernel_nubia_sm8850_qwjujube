__int64 __fastcall policy_mgr_get_ch_width(
        int a1,
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

  if ( (unsigned int)(a1 - 1) >= 8 )
  {
    v9 = 8;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid phy_ch_width type %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "policy_mgr_get_ch_width",
      8);
  }
  else
  {
    return dword_B356C8[a1 - 1];
  }
  return v9;
}
