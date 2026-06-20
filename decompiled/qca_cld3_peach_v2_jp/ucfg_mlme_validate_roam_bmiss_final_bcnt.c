bool __fastcall ucfg_mlme_validate_roam_bmiss_final_bcnt(
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

  v9 = a1 - 5;
  if ( a1 - 5 >= 0x60 )
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: bmiss final bcnt %d is out of range (Min: %d Max: %d)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ucfg_mlme_validate_roam_bmiss_final_bcnt",
      a1,
      5,
      100);
  return v9 < 0x60;
}
