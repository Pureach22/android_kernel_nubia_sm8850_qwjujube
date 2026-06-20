__int64 __fastcall wlan_mlme_get_ch_width_from_phymode(
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

  if ( a1 - 7 > 0x17 )
    v9 = 0;
  else
    v9 = dword_9FDB70[a1 - 7];
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: phymode: %d, ch_width: %d ",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_mlme_get_ch_width_from_phymode",
    a1,
    v9);
  return v9;
}
