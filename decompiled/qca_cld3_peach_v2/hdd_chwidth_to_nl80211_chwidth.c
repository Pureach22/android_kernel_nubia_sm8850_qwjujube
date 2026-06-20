unsigned __int64 __fastcall hdd_chwidth_to_nl80211_chwidth(
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

  if ( a1 < 6 )
    return 0xD0405030201uLL >> (8 * (unsigned __int8)a1);
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Unsupported channel width %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_chwidth_to_nl80211_chwidth",
    a1,
    v9,
    v10);
  return 255;
}
