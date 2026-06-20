__int64 __fastcall hdd_convert_chwidth_to_phy_chwidth(
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
  unsigned int v9; // w19

  if ( a1 >= 6 )
  {
    v9 = 8;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Invalid channel width %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_convert_chwidth_to_phy_chwidth",
      a1);
  }
  else
  {
    return dword_A0564C[a1];
  }
  return v9;
}
