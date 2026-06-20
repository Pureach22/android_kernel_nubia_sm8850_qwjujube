__int64 __fastcall osif_dp_populate_tcp_stats_info(
        __int64 a1,
        __int64 a2,
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
  __int16 track_src_port_value; // w21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int16 track_dest_port_value; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 tcp_stats; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _WORD *v41; // x22
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int16 v50; // w8
  _WORD *v51; // x22
  __int64 v52; // x0
  __int64 v53; // x1
  _WORD *v54; // x22
  __int64 result; // x0
  _WORD v56[2]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  track_src_port_value = ucfg_dp_get_track_src_port_value(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  track_dest_port_value = ucfg_dp_get_track_dest_port_value(a1, v15, v16, v17, v18, v19, v20, v21, v22);
  tcp_stats = ucfg_dp_get_tcp_stats(a1, v24, v25, v26, v27, v28, v29, v30, v31);
  if ( !tcp_stats )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Unable to get TCP stats",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "osif_dp_populate_tcp_stats_info");
LABEL_30:
    result = 4294967274LL;
    goto LABEL_31;
  }
  if ( a3 == 128 )
  {
    v54 = (_WORD *)tcp_stats;
    v56[0] = 128;
    if ( (unsigned int)nla_put(a2, 1, 2, v56) )
      goto LABEL_29;
    v56[0] = track_src_port_value;
    if ( (unsigned int)nla_put(a2, 3, 2, v56) )
      goto LABEL_29;
    v56[0] = track_dest_port_value;
    if ( (unsigned int)nla_put(a2, 4, 2, v56) )
      goto LABEL_29;
    v56[0] = v54[1];
    if ( (unsigned int)nla_put(a2, 7, 2, v56) )
      goto LABEL_29;
    v56[0] = v54[8];
    if ( (unsigned int)nla_put(a2, 8, 2, v56) )
      goto LABEL_29;
    v56[0] = v54[8];
    if ( (unsigned int)nla_put(a2, 9, 2, v56) )
      goto LABEL_29;
    v50 = v54[12];
    goto LABEL_27;
  }
  if ( a3 != 64 )
  {
    if ( a3 != 32 )
    {
      result = 0;
      goto LABEL_31;
    }
    v41 = (_WORD *)tcp_stats;
    v56[0] = 32;
    if ( (unsigned int)nla_put(a2, 1, 2, v56) )
      goto LABEL_29;
    v56[0] = track_src_port_value;
    if ( (unsigned int)nla_put(a2, 3, 2, v56) )
      goto LABEL_29;
    v56[0] = track_dest_port_value;
    if ( (unsigned int)nla_put(a2, 4, 2, v56) )
      goto LABEL_29;
    v56[0] = *v41;
    if ( (unsigned int)nla_put(a2, 7, 2, v56) )
      goto LABEL_29;
    v56[0] = v41[7];
    if ( (unsigned int)nla_put(a2, 8, 2, v56) )
      goto LABEL_29;
    v56[0] = v41[7];
    if ( (unsigned int)nla_put(a2, 9, 2, v56) )
      goto LABEL_29;
    v50 = v41[11];
LABEL_27:
    v52 = a2;
    v53 = 10;
    goto LABEL_28;
  }
  v51 = (_WORD *)tcp_stats;
  v56[0] = 64;
  if ( (unsigned int)nla_put(a2, 1, 2, v56) )
    goto LABEL_29;
  v56[0] = track_src_port_value;
  if ( (unsigned int)nla_put(a2, 3, 2, v56) )
    goto LABEL_29;
  v56[0] = track_dest_port_value;
  if ( (unsigned int)nla_put(a2, 4, 2, v56) )
    goto LABEL_29;
  v56[0] = v51[10];
  if ( (unsigned int)nla_put(a2, 11, 2, v56) )
    goto LABEL_29;
  v56[0] = v51[2];
  if ( (unsigned int)nla_put(a2, 12, 2, v56) )
    goto LABEL_29;
  v56[0] = v51[5];
  if ( (unsigned int)nla_put(a2, 13, 2, v56) )
    goto LABEL_29;
  v50 = v51[9];
  v52 = a2;
  v53 = 14;
LABEL_28:
  v56[0] = v50;
  result = nla_put(v52, v53, 2, v56);
  if ( (_DWORD)result )
  {
LABEL_29:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: nla put fail",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "osif_dp_populate_tcp_stats_info");
    sk_skb_reason_drop(0, a2, 2);
    goto LABEL_30;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
