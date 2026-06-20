__int64 __fastcall hdd_convert_nl80211_to_reg_band_mask(
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
  if ( (a1 & 4) != 0 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: band: %d not supported",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_convert_nl80211_to_reg_band_mask",
      2);
  return a1 & 3 | (4 * ((a1 >> 3) & 1));
}
