__int64 __fastcall hdd_reg_legacy_setband_to_reg_wifi_band_bitmap(
        unsigned __int8 a1,
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

  if ( a1 < 8u )
    return dword_B352A8[a1];
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Invalid band value %u",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_reg_legacy_setband_to_reg_wifi_band_bitmap",
    v9,
    v10);
  return 0;
}
