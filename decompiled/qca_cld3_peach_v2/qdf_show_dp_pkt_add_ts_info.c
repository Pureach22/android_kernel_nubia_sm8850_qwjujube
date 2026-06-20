__int64 __fastcall qdf_show_dp_pkt_add_ts_info(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w0
  unsigned int v38; // w20
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x10
  const char *v48; // x3
  int v49; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  const char *v58; // x10
  const char *v59; // x3
  int v60; // w0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  const char *v69; // x10
  const char *v70; // x3
  int v71; // w0
  long double v72; // q0
  const char *v74; // x10
  const char *v75; // x3
  int v76; // w0

  qdf_trace_msg(
    0x38u,
    8u,
    "%s: dp_pkt_add_timestamp %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "qdf_show_dp_pkt_add_ts_info",
    (unsigned __int8)dp_pkt_add_timestamp);
  qdf_trace_msg(
    0x38u,
    8u,
    "%s: enable_protocol_bitmap %x",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "qdf_show_dp_pkt_add_ts_info",
    (unsigned __int16)word_925D32);
  qdf_trace_msg(
    0x38u,
    8u,
    "%s: current_index %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "qdf_show_dp_pkt_add_ts_info",
    (unsigned __int8)dp_pkt_ts_info);
  v29 = scnprintf(a1, a2, "dp_pkt_add_timestamp %d\n", (unsigned __int8)dp_pkt_add_timestamp);
  v38 = v37;
  if ( !dp_pkt_ts_info )
    return v38;
  qdf_trace_msg(
    0x38u,
    8u,
    "%s: proto %d port %d offset %d",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "qdf_show_dp_pkt_add_ts_info",
    (unsigned int)dword_925D34,
    (unsigned __int16)word_925D38,
    (unsigned __int16)word_925D3A);
  if ( a2 != v38 )
  {
    v47 = "Invalid";
    if ( dword_925D34 == 2 )
      v47 = "UDP";
    if ( dword_925D34 == 1 )
      v48 = "TCP";
    else
      v48 = v47;
    v39 = scnprintf(
            a1 + (int)v38,
            a2 - (int)v38,
            "Protocol: %s Destination Port %d Offset %d\n",
            v48,
            (unsigned __int16)word_925D38,
            (unsigned __int16)word_925D3A);
    v38 += v49;
  }
  if ( (unsigned __int8)dp_pkt_ts_info < 2u )
    return v38;
  qdf_trace_msg(
    0x38u,
    8u,
    "%s: proto %d port %d offset %d",
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    "qdf_show_dp_pkt_add_ts_info",
    (unsigned int)dword_925D3C,
    (unsigned __int16)word_925D40,
    (unsigned __int16)word_925D42);
  if ( a2 != v38 )
  {
    v58 = "Invalid";
    if ( dword_925D3C == 2 )
      v58 = "UDP";
    if ( dword_925D3C == 1 )
      v59 = "TCP";
    else
      v59 = v58;
    v50 = scnprintf(
            a1 + (int)v38,
            a2 - (int)v38,
            "Protocol: %s Destination Port %d Offset %d\n",
            v59,
            (unsigned __int16)word_925D40,
            (unsigned __int16)word_925D42);
    v38 += v60;
  }
  if ( (unsigned __int8)dp_pkt_ts_info < 3u )
    return v38;
  qdf_trace_msg(
    0x38u,
    8u,
    "%s: proto %d port %d offset %d",
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    "qdf_show_dp_pkt_add_ts_info",
    (unsigned int)dword_925D44,
    (unsigned __int16)word_925D48,
    (unsigned __int16)word_925D4A);
  if ( a2 != v38 )
  {
    v69 = "Invalid";
    if ( dword_925D44 == 2 )
      v69 = "UDP";
    if ( dword_925D44 == 1 )
      v70 = "TCP";
    else
      v70 = v69;
    v61 = scnprintf(
            a1 + (int)v38,
            a2 - (int)v38,
            "Protocol: %s Destination Port %d Offset %d\n",
            v70,
            (unsigned __int16)word_925D48,
            (unsigned __int16)word_925D4A);
    v38 += v71;
  }
  if ( (unsigned __int8)dp_pkt_ts_info < 4u )
    return v38;
  qdf_trace_msg(
    0x38u,
    8u,
    "%s: proto %d port %d offset %d",
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    "qdf_show_dp_pkt_add_ts_info",
    (unsigned int)dword_925D4C,
    (unsigned __int16)word_925D50,
    (unsigned __int16)word_925D52);
  if ( a2 != v38 )
  {
    v74 = "Invalid";
    if ( dword_925D4C == 2 )
      v74 = "UDP";
    if ( dword_925D4C == 1 )
      v75 = "TCP";
    else
      v75 = v74;
    *(double *)&v72 = scnprintf(
                        a1 + (int)v38,
                        a2 - (int)v38,
                        "Protocol: %s Destination Port %d Offset %d\n",
                        v75,
                        (unsigned __int16)word_925D50,
                        (unsigned __int16)word_925D52);
    v38 += v76;
  }
  if ( (unsigned __int8)dp_pkt_ts_info <= 4u )
    return v38;
  __break(0x5512u);
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return qdf_is_dp_pkt_timestamp_enabled(v72);
}
