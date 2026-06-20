__int64 __fastcall wlan_dcs_im_print_stats(
        unsigned int *a1,
        unsigned int *a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v21; // [xsp+0h] [xbp-50h]
  __int64 v22; // [xsp+8h] [xbp-48h]
  __int64 v23; // [xsp+10h] [xbp-40h]
  __int64 v24; // [xsp+18h] [xbp-38h]
  __int64 v25; // [xsp+20h] [xbp-30h]
  __int64 v26; // [xsp+28h] [xbp-28h]

  if ( !a1 )
    return qdf_trace_msg(
             0x74u,
             2u,
             "%s: previous or current stats is null",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "wlan_dcs_im_print_stats");
  qdf_trace_msg(
    0x74u,
    8u,
    "%s: vdev %d: PREV:tsf %u Cnts:tx %u rx %u my_rx %u clr %u cyc %u clr_e %d ofdm %u cck %u",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_dcs_im_print_stats",
    a3,
    *a1,
    a1[6],
    a1[7],
    a1[14],
    a1[8],
    a1[9],
    a1[10],
    a1[11],
    a1[12]);
  LODWORD(v26) = a2[4];
  LODWORD(v25) = a2[12];
  LODWORD(v24) = a2[11];
  LODWORD(v23) = a2[10];
  LODWORD(v22) = a2[9];
  LODWORD(v21) = a2[8];
  return qdf_trace_msg(
           0x74u,
           8u,
           "%s: CUR:tsf %u Cnts:tx %u rx %u my_rx %u clr %u cyc %u clr_e %d ofdm %u cck %u phy_e %u, lst ack %u Time: was"
           "te %u rx %u lst %u",
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           "wlan_dcs_im_print_stats",
           *a2,
           a2[6],
           a2[7],
           a2[14],
           v21,
           v22,
           v23,
           v24,
           v25,
           v26,
           a2[1],
           a2[2],
           a2[3],
           a2[5]);
}
