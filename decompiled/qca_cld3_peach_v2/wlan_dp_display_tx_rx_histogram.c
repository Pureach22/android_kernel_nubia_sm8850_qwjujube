__int64 __fastcall wlan_dp_display_tx_rx_histogram(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 result; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x20
  __int64 v61; // x26
  int v62; // w11
  int v63; // w10
  const char *v64; // x11
  const char *v65; // x10
  __int64 v66; // x21
  __int64 v67; // x25
  __int64 v68; // x22
  __int64 v69; // x23
  __int64 v70; // x24
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x9
  const char *v80; // x8
  __int64 v81; // x10
  const char *v82; // x9
  __int64 v83; // x11
  int v84; // [xsp+0h] [xbp-20h]

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: Unable to get DP context",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "wlan_dp_display_tx_rx_histogram");
  v10 = comp_private_obj;
  qdf_trace_msg(
    0x45u,
    4u,
    "BW compute Interval: %d ms",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    *(unsigned int *)(comp_private_obj + 88));
  v84 = *(_DWORD *)(v10 + 68);
  qdf_trace_msg(
    0x45u,
    4u,
    "BW TH - Very High: %d Mid High: %d High: %d Med: %d Low: %d DBS: %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    *(unsigned int *)(v10 + 64),
    *(unsigned int *)(v10 + 72),
    *(unsigned int *)(v10 + 76),
    *(unsigned int *)(v10 + 80),
    *(unsigned int *)(v10 + 84),
    v84);
  qdf_trace_msg(
    0x45u,
    4u,
    "Enable TCP DEL ACK: %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    *(unsigned __int8 *)(v10 + 848));
  qdf_trace_msg(
    0x45u,
    4u,
    "TCP DEL High TH: %d TCP DEL Low TH: %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    *(unsigned int *)(v10 + 108),
    *(unsigned int *)(v10 + 112));
  qdf_trace_msg(
    0x45u,
    4u,
    "TCP TX HIGH TP TH: %d (Use to set tcp_output_bytes_lim)",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    *(unsigned int *)(v10 + 116));
  result = qdf_trace_msg(
             0x45u,
             4u,
             "Total entries: %d Current index: %d",
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             v49,
             v50,
             128,
             *(unsigned __int16 *)(v10 + 1136));
  if ( *(_QWORD *)(v10 + 1144) )
  {
    result = qdf_trace_msg(
               0x45u,
               4u,
               "[index][timestamp]: interval_rx, interval_tx, bus_bw_level, RX TP Level, TX TP Level, Rx:Tx pm_qos",
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               v59);
    v60 = 0;
    v61 = 32;
    do
    {
      v66 = *(_QWORD *)(v10 + 1144);
      v67 = v66 + v61;
      v68 = *(_QWORD *)(v66 + v61);
      if ( v68 )
      {
        v69 = *(_QWORD *)(v67 - 32);
        v70 = *(_QWORD *)(v67 - 24);
        pld_bus_width_type_to_str(*(unsigned int *)(v67 - 16));
        v79 = *(unsigned int *)(v67 - 12);
        v80 = "INVAL";
        if ( (unsigned int)v79 <= 3 )
          v80 = off_AEF740[v79];
        v81 = v66 + v61;
        v82 = "INVAL";
        v83 = *(unsigned int *)(v66 + v61 - 8);
        if ( (unsigned int)v83 <= 3 )
          v82 = off_AEF740[v83];
        v62 = *(unsigned __int8 *)(v81 - 4);
        v63 = *(unsigned __int8 *)(v81 - 3);
        if ( v62 )
          v64 = "HIGH";
        else
          v64 = "LOW";
        if ( v63 )
          v65 = "HIGH";
        else
          v65 = "LOW";
        result = qdf_trace_msg(
                   0x45u,
                   4u,
                   "[%3d][%15llu]: %6llu, %6llu, %s, %s, %s, %s:%s",
                   v71,
                   v72,
                   v73,
                   v74,
                   v75,
                   v76,
                   v77,
                   v78,
                   (unsigned int)v60,
                   v68,
                   v69,
                   v70,
                   v80,
                   v82,
                   v64,
                   v65);
      }
      ++v60;
      v61 += 40;
    }
    while ( v60 != 128 );
  }
  return result;
}
