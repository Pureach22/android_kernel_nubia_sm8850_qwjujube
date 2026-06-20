__int64 __fastcall osif_dp_set_nud_stats(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        unsigned int a12)
{
  __int64 v15; // x8
  __int64 v16; // x20
  int pkt_type_bitmap_value; // w22
  unsigned int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w21
  const char *v28; // x2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // [xsp+8h] [xbp-48h] BYREF
  __int64 v71; // [xsp+10h] [xbp-40h]
  __int64 v72; // [xsp+18h] [xbp-38h]
  __int64 v73; // [xsp+20h] [xbp-30h]
  __int64 v74; // [xsp+28h] [xbp-28h] BYREF
  __int64 v75; // [xsp+30h] [xbp-20h]
  __int64 v76; // [xsp+38h] [xbp-18h]
  __int64 v77; // [xsp+40h] [xbp-10h]
  __int64 v78; // [xsp+48h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *(_QWORD *)(a10 + 216);
  if ( v15 )
    v16 = *(_QWORD *)(v15 + 80);
  else
    v16 = 0;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v70 = 0;
  v71 = 0;
  pkt_type_bitmap_value = ucfg_dp_get_pkt_type_bitmap_value(a10, a1, a2, a3, a4, a5, a6, a7, a8);
  v18 = _nla_parse(&v74, 3, a11, a12, &dp_set_nud_stats_policy, 31, 0);
  if ( !v18 )
  {
    if ( v75 )
    {
      if ( v77 )
      {
        if ( (unsigned int)osif_dp_set_clear_connectivity_check_stats_info(a10, &v70, &v74, 1) )
        {
LABEL_11:
          v27 = -22;
          goto LABEL_7;
        }
LABEL_14:
        if ( !HIDWORD(v71) )
          goto LABEL_22;
        goto LABEL_20;
      }
      if ( !v76 )
      {
        v27 = -22;
        v28 = "%s: STATS_SET_START CMD";
        goto LABEL_6;
      }
      HIDWORD(v71) = 1;
      ucfg_dp_set_pkt_type_bitmap_value(a10, pkt_type_bitmap_value | 1, v19, v20, v21, v22, v23, v24, v25, v26);
      BYTE4(v70) = 1;
      LODWORD(v71) = *(_DWORD *)(v76 + 4);
      ucfg_dp_set_track_arp_ip_value(a10, v71, v38, v39, v40, v41, v42, v43, v44, v45);
    }
    else
    {
      if ( v77 )
      {
        if ( (unsigned int)osif_dp_set_clear_connectivity_check_stats_info(a10, &v70, &v74, 0) )
          goto LABEL_11;
        goto LABEL_14;
      }
      HIDWORD(v71) = 1;
      ucfg_dp_set_pkt_type_bitmap_value(a10, pkt_type_bitmap_value & 0xFFFFFFFE, v19, v20, v21, v22, v23, v24, v25, v26);
      BYTE4(v70) = 0;
      ucfg_dp_clear_arp_stats(a10, v46, v47, v48, v49, v50, v51, v52, v53);
    }
    BYTE5(v70) = 1;
LABEL_20:
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: STATS_SET_START Received flag %d!",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "osif_dp_set_nud_stats",
      BYTE4(v70));
    LODWORD(v70) = (unsigned __int8)ucfg_dp_get_link_id(a10, v54, v55, v56, v57, v58, v59, v60, v61);
    if ( (unsigned int)ucfg_dp_req_set_arp_stats(v16, (__int64)&v70, v62, v63, v64, v65, v66, v67, v68, v69) )
    {
      v27 = -22;
      v28 = "%s: Unable to set ARP stats!";
      goto LABEL_6;
    }
LABEL_22:
    v27 = 0;
    goto LABEL_7;
  }
  v27 = v18;
  v28 = "%s: STATS_SET_START ATTR";
LABEL_6:
  qdf_trace_msg(0x45u, 2u, v28, v19, v20, v21, v22, v23, v24, v25, v26, "osif_dp_set_nud_stats");
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v27;
}
