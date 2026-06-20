bool __fastcall ucfg_mlme_validate_full_roam_scan_period(
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
  if ( a1 >= 0x259 )
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: Full roam scan period value %d is out of range (Min: %d Max: %d)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ucfg_mlme_validate_full_roam_scan_period",
      a1,
      0,
      600);
  return a1 < 0x259;
}
