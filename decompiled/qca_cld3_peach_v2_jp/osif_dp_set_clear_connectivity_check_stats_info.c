__int64 __fastcall osif_dp_set_clear_connectivity_check_stats_info(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int pkt_type_bitmap_value; // w0
  _WORD *v17; // x8
  int v18; // w28
  unsigned __int16 *v19; // x26
  int v20; // w24
  __int64 v21; // x8
  unsigned int v22; // w9
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w23
  __int64 v33; // x8
  int v34; // w1
  unsigned __int8 *v35; // x27
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  int v100; // w1
  _BYTE *v101; // x8
  _QWORD *v102; // x10
  _BYTE *v103; // x9
  int v104; // w11
  int v105; // t1
  __int64 v106; // x9
  int v107; // w1
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  const char *v116; // x8
  const char *v117; // [xsp+10h] [xbp-150h]
  _QWORD v118[32]; // [xsp+18h] [xbp-148h] BYREF
  __int64 v119; // [xsp+118h] [xbp-48h] BYREF
  __int64 v120; // [xsp+120h] [xbp-40h]
  _WORD *v121; // [xsp+128h] [xbp-38h]
  __int64 v122; // [xsp+130h] [xbp-30h]
  __int64 v123; // [xsp+138h] [xbp-28h]
  __int64 v124; // [xsp+140h] [xbp-20h]
  __int64 v125; // [xsp+148h] [xbp-18h]
  __int64 v126; // [xsp+150h] [xbp-10h]

  v126 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v124 = 0;
  v125 = 0;
  v122 = 0;
  v123 = 0;
  v120 = 0;
  v121 = nullptr;
  v119 = 0;
  memset(v118, 0, sizeof(v118));
  pkt_type_bitmap_value = ucfg_dp_get_pkt_type_bitmap_value(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  v17 = *(_WORD **)(a3 + 24);
  v18 = (unsigned __int16)(*v17 - 4);
  if ( (unsigned int)v18 < 4 )
  {
LABEL_42:
    result = 0;
    goto LABEL_48;
  }
  v19 = v17 + 2;
  v20 = pkt_type_bitmap_value;
  v117 = "%s: Source/Dest port is not present";
  while ( 1 )
  {
    v22 = *v19;
    result = 0;
    if ( v22 < 4 || v18 < v22 )
      goto LABEL_48;
    if ( (unsigned int)_nla_parse(
                         &v119,
                         6,
                         v19 + 2,
                         (unsigned __int16)(v22 - 4),
                         &dp_set_connectivity_check_stats,
                         31,
                         0) )
    {
      v116 = "%s: nla_parse failed";
LABEL_46:
      v117 = v116;
      goto LABEL_47;
    }
    if ( !v120 )
    {
      v116 = "%s: stats list empty";
      goto LABEL_46;
    }
    v32 = *(_DWORD *)(v120 + 4);
    if ( !v32 )
    {
      v116 = "%s: pkt tracking bitmap is empty";
      goto LABEL_46;
    }
    *(_DWORD *)(a2 + 12) = v32;
    if ( (a4 & 1) != 0 )
      break;
    v20 &= ~v32;
    *(_BYTE *)(a2 + 4) = 0;
    ucfg_dp_set_pkt_type_bitmap_value(a1, v20, v24, v25, v26, v27, v28, v29, v30, v31);
    if ( (v32 & 1) != 0 )
    {
      *(_BYTE *)(a2 + 5) = 1;
      ucfg_dp_clear_arp_stats(a1, v52, v53, v54, v55, v56, v57, v58, v59);
      ucfg_dp_set_track_arp_ip_value(a1, 0, v60, v61, v62, v63, v64, v65, v66, v67);
      if ( (v32 & 2) == 0 )
      {
LABEL_21:
        if ( (v32 & 4) == 0 )
          goto LABEL_22;
        goto LABEL_26;
      }
    }
    else if ( (v32 & 2) == 0 )
    {
      goto LABEL_21;
    }
    *(_DWORD *)(a2 + 12) &= ~2u;
    ucfg_dp_clear_dns_stats(a1, v52, v53, v54, v55, v56, v57, v58, v59);
    ucfg_dp_clear_dns_payload_value(a1, v68, v69, v70, v71, v72, v73, v74, v75);
    ucfg_dp_set_track_dns_domain_len_value(a1, 0, v76, v77, v78, v79, v80, v81, v82, v83);
    if ( (v32 & 4) == 0 )
    {
LABEL_22:
      if ( (v32 & 8) == 0 )
        goto LABEL_4;
      goto LABEL_27;
    }
LABEL_26:
    ucfg_dp_clear_tcp_stats(a1, v52, v53, v54, v55, v56, v57, v58, v59);
    ucfg_dp_set_track_src_port_value(a1, 0, v84, v85, v86, v87, v88, v89, v90, v91);
    ucfg_dp_set_track_dest_port_value(a1, 0, v92, v93, v94, v95, v96, v97, v98, v99);
    if ( (v32 & 8) == 0 )
      goto LABEL_4;
LABEL_27:
    ucfg_dp_clear_icmpv4_stats(a1, v52, v53, v54, v55, v56, v57, v58, v59);
    v100 = 0;
LABEL_3:
    ucfg_dp_set_track_dest_ipv4_value(a1, v100, v24, v25, v26, v27, v28, v29, v30, v31);
LABEL_4:
    v21 = (*v19 + 3) & 0x1FFFC;
    v18 -= v21;
    v19 = (unsigned __int16 *)((char *)v19 + v21);
    if ( v18 <= 3 )
      goto LABEL_42;
  }
  v20 |= v32;
  *(_BYTE *)(a2 + 4) = 1;
  ucfg_dp_set_pkt_type_bitmap_value(a1, v20, v24, v25, v26, v27, v28, v29, v30, v31);
  if ( (v32 & 1) == 0 )
    goto LABEL_14;
  v33 = *(_QWORD *)(a3 + 16);
  if ( !v33 )
  {
    v116 = "%s: GW ipv4 address is not present";
    goto LABEL_46;
  }
  v34 = *(_DWORD *)(v33 + 4);
  *(_BYTE *)(a2 + 5) = 1;
  *(_DWORD *)(a2 + 8) = v34;
  ucfg_dp_set_track_arp_ip_value(a1, v34, v24, v25, v26, v27, v28, v29, v30, v31);
LABEL_14:
  if ( (v32 & 2) == 0 )
    goto LABEL_35;
  if ( !v121 )
  {
    v116 = "%s: DNS domain id is not present";
    goto LABEL_46;
  }
  v35 = (unsigned __int8 *)(v121 + 2);
  ucfg_dp_set_track_dns_domain_len_value(a1, (unsigned __int16)(*v121 - 4), v24, v25, v26, v27, v28, v29, v30, v31);
  ucfg_dp_get_dns_payload_value(a1, v118, v36, v37, v38, v39, v40, v41, v42, v43);
  if ( v35[(unsigned __int8)ucfg_dp_get_track_dns_domain_len_value(a1, v44, v45, v46, v47, v48, v49, v50, v51) - 1] )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: DNS name is not null terminated",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "dp_dns_make_name_query");
LABEL_18:
    ucfg_dp_set_track_dns_domain_len_value(a1, 0, v24, v25, v26, v27, v28, v29, v30, v31);
    goto LABEL_34;
  }
  v101 = (char *)v118 + 1;
  v102 = v118;
  v103 = v118;
  while ( 2 )
  {
    v105 = *v35++;
    v104 = v105;
    if ( v105 == 46 )
    {
      *v103 = (_BYTE)v102 - (_BYTE)v103;
      v103 = v101;
LABEL_30:
      *v101++ = v104;
      LOBYTE(v102) = (_BYTE)v102 + 1;
      continue;
    }
    break;
  }
  if ( v104 )
    goto LABEL_30;
  *v103 = (_BYTE)v102 - (_BYTE)v103;
  *v101 = 0;
  if ( v101 == (_BYTE *)-1LL )
    goto LABEL_18;
LABEL_34:
  *(_DWORD *)(a2 + 12) &= ~2u;
LABEL_35:
  if ( (v32 & 4) == 0 )
  {
LABEL_39:
    if ( (v32 & 8) == 0 )
      goto LABEL_4;
    if ( !v124 )
    {
      v116 = "%s: destination ipv4 address to track ping packets is not present";
      goto LABEL_46;
    }
    v100 = *(_DWORD *)(v124 + 4);
    *(_DWORD *)(a2 + 24) = v100;
    goto LABEL_3;
  }
  if ( v122 )
  {
    v106 = v123;
    if ( v123 )
    {
      v107 = *(_DWORD *)(v122 + 4);
      *(_DWORD *)(a2 + 16) = v107;
      *(_DWORD *)(a2 + 20) = *(_DWORD *)(v106 + 4);
      ucfg_dp_set_track_src_port_value(a1, v107, v24, v25, v26, v27, v28, v29, v30, v31);
      ucfg_dp_set_track_dest_port_value(a1, *(_DWORD *)(a2 + 20), v108, v109, v110, v111, v112, v113, v114, v115);
      goto LABEL_39;
    }
  }
LABEL_47:
  qdf_trace_msg(
    0x45u,
    2u,
    v117,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "osif_dp_set_clear_connectivity_check_stats_info");
  result = 4294967274LL;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
