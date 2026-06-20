__int64 __fastcall osif_twt_setup_req(__int64 a1, _WORD *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  unsigned int v13; // w23
  __int64 v14; // x20
  const char *v15; // x2
  __int64 result; // x0
  unsigned int v17; // w22
  __int64 v18; // x1
  unsigned __int8 pdev_id_from_vdev_id; // w21
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w24
  __int64 v29; // x20
  unsigned int v30; // w25
  __int64 v31; // x20
  __int64 v32; // x20
  unsigned int v33; // w27
  __int64 v34; // x4
  __int64 v35; // x4
  unsigned int v36; // w8
  int v37; // w28
  _BOOL4 v38; // w9
  int v39; // w11
  char v40; // w12
  _BOOL4 v41; // w10
  int v42; // w8
  __int64 v43; // x4
  __int64 v44; // x20
  __int64 v45; // x25
  unsigned int v46; // w24
  __int64 v47; // x20
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  const char *v56; // x2
  __int64 v57; // x20
  __int64 v58; // x20
  unsigned __int16 *v59; // x8
  __int64 v60; // x5
  unsigned int v61; // w9
  __int64 v62; // x26
  unsigned int v63; // w13
  __int64 v64; // x20
  __int64 v65; // x20
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x20
  unsigned int v75; // w14
  __int64 v76; // x20
  char v77; // w25
  unsigned int v78; // w8
  __int64 v79; // x26
  __int64 v80; // x10
  _BOOL4 v81; // w9
  unsigned int v82; // w25
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 v107; // x20
  __int64 v108; // [xsp+0h] [xbp-1D0h]
  unsigned int v109; // [xsp+18h] [xbp-1B8h]
  unsigned int v110; // [xsp+1Ch] [xbp-1B4h]
  unsigned int v111; // [xsp+20h] [xbp-1B0h]
  unsigned int v112; // [xsp+24h] [xbp-1ACh]
  unsigned int v113; // [xsp+28h] [xbp-1A8h]
  unsigned int v114; // [xsp+2Ch] [xbp-1A4h]
  unsigned __int64 v115; // [xsp+30h] [xbp-1A0h]
  char v116; // [xsp+34h] [xbp-19Ch]
  _BOOL4 v117; // [xsp+38h] [xbp-198h]
  _BOOL4 v118; // [xsp+38h] [xbp-198h]
  __int64 v119; // [xsp+38h] [xbp-198h]
  unsigned int v120; // [xsp+40h] [xbp-190h]
  unsigned int v121; // [xsp+40h] [xbp-190h]
  int v122; // [xsp+44h] [xbp-18Ch]
  unsigned int v123; // [xsp+44h] [xbp-18Ch]
  unsigned __int8 v124[4]; // [xsp+48h] [xbp-188h] BYREF
  int v125; // [xsp+4Ch] [xbp-184h] BYREF
  _QWORD v126[3]; // [xsp+50h] [xbp-180h] BYREF
  __int64 v127; // [xsp+68h] [xbp-168h] BYREF
  __int64 v128; // [xsp+70h] [xbp-160h]
  __int64 v129; // [xsp+78h] [xbp-158h]
  __int64 v130; // [xsp+80h] [xbp-150h]
  __int128 v131; // [xsp+88h] [xbp-148h]
  __int64 v132; // [xsp+98h] [xbp-138h]
  __int64 v133; // [xsp+A0h] [xbp-130h]
  __int64 v134; // [xsp+A8h] [xbp-128h]
  __int64 v135; // [xsp+B0h] [xbp-120h]
  _QWORD s[35]; // [xsp+B8h] [xbp-118h] BYREF

  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x108u);
  v12 = *(_QWORD *)(a1 + 216);
  v13 = *(_DWORD *)(a1 + 16);
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = 0;
  v131 = 0u;
  v129 = 0;
  v130 = 0;
  v127 = 0;
  v128 = 0;
  v125 = 0;
  v124[0] = 0;
  if ( !v12 || (v14 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    v15 = "%s: NULL psoc";
LABEL_6:
    qdf_trace_msg(0x48u, 2u, v15, v4, v5, v6, v7, v8, v9, v10, v11, "osif_twt_setup_req");
    goto LABEL_7;
  }
  if ( ((__int16)a2[1] & 0x80000000) == 0 )
  {
    do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_7:
    result = 4294967274LL;
    goto LABEL_8;
  }
  result = _nla_parse(s, 32, a2 + 2, (unsigned __int16)(*a2 - 4), &qca_wlan_vendor_twt_add_dialog_policy, 31, 0);
  if ( (_DWORD)result )
    goto LABEL_8;
  v17 = *(unsigned __int8 *)(a1 + 168);
  v18 = *(unsigned __int8 *)(a1 + 168);
  LODWORD(v127) = v17;
  pdev_id_from_vdev_id = wlan_get_pdev_id_from_vdev_id(v14, v18, 0x5Eu);
  if ( s[5] )
  {
    v28 = *(unsigned __int8 *)(s[5] + 4LL);
    HIDWORD(v128) = v28;
    if ( v28 == 255 )
    {
      v29 = jiffies;
      if ( osif_twt_parse_add_dialog_attrs___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Flow id (%u) invalid",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "osif_twt_parse_add_dialog_attrs",
          255);
        osif_twt_parse_add_dialog_attrs___last_ticks = v29;
      }
      goto LABEL_7;
    }
  }
  else
  {
    HIDWORD(v128) = 0;
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: TWT_SETUP_FLOW_ID not specified. set to zero",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "osif_twt_parse_add_dialog_attrs");
    v28 = 0;
  }
  if ( !s[6] )
  {
    v32 = jiffies;
    if ( osif_twt_parse_add_dialog_attrs___last_ticks_67 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: TWT_SETUP_WAKE_INTVL_EXP is must",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "osif_twt_parse_add_dialog_attrs");
      osif_twt_parse_add_dialog_attrs___last_ticks_67 = v32;
    }
    goto LABEL_7;
  }
  v30 = *(unsigned __int8 *)(s[6] + 4LL);
  if ( v30 >= 0x20 )
  {
    v31 = jiffies;
    if ( osif_twt_parse_add_dialog_attrs___last_ticks_69 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Invalid wake_intvl_exp %u > %u",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "osif_twt_parse_add_dialog_attrs",
        *(unsigned __int8 *)(s[6] + 4LL),
        31);
      osif_twt_parse_add_dialog_attrs___last_ticks_69 = v31;
    }
    goto LABEL_7;
  }
  if ( s[1] )
    v33 = (HIDWORD(v132) & 0xFFFFFFFE) + 1;
  else
    v33 = HIDWORD(v132) & 0xFFFFFFFE;
  HIDWORD(v132) = v33;
  if ( s[22] )
  {
    v28 = *(unsigned __int8 *)(s[22] + 4LL);
    v34 = *(unsigned __int8 *)(s[22] + 4LL);
    HIDWORD(v128) = v28;
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: TWT_SETUP_BCAST_ID %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "osif_twt_parse_add_dialog_attrs",
      v34);
  }
  if ( s[23] )
  {
    v33 = v33 & 0xF8FFFFFF | ((*(_BYTE *)(s[23] + 4LL) & 7) << 24);
    v35 = *(_BYTE *)(s[23] + 4LL) & 7;
    HIDWORD(v132) = v33;
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: TWT_SETUP_BCAST_RECOMM %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "osif_twt_parse_add_dialog_attrs",
      v35);
  }
  if ( s[24] )
  {
    v33 = v33 & 0xFF00FFFF | (*(unsigned __int8 *)(s[24] + 4LL) << 16);
    HIDWORD(v132) = v33;
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: TWT_SETUP_BCAST_PERSIS %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "osif_twt_parse_add_dialog_attrs");
  }
  if ( !s[2] )
  {
    v47 = jiffies;
    if ( osif_twt_parse_add_dialog_attrs___last_ticks_74 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: TWT_SETUP_REQ_TYPE is must",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "osif_twt_parse_add_dialog_attrs");
      osif_twt_parse_add_dialog_attrs___last_ticks_74 = v47;
    }
    goto LABEL_7;
  }
  v36 = *(unsigned __int8 *)(s[2] + 4LL) - 1;
  if ( v36 < 6 && ((0x27u >> v36) & 1) != 0 )
  {
    v37 = dword_B33D3C[(unsigned __int8)(*(_BYTE *)(s[2] + 4LL) - 1)];
    LODWORD(v132) = v37;
    v38 = s[3] != 0;
    if ( !s[4] )
    {
      v57 = jiffies;
      if ( osif_twt_parse_add_dialog_attrs___last_ticks_76 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: TWT_SETUP_FLOW_TYPE is must",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "osif_twt_parse_add_dialog_attrs");
        osif_twt_parse_add_dialog_attrs___last_ticks_76 = v57;
      }
      goto LABEL_7;
    }
    v39 = 2 * v38;
    v40 = *(_BYTE *)(s[4] + 4LL);
    v41 = s[7] != 0;
    HIDWORD(v132) = v33 & 0xFFFFFFF1 | (2 * v38) & 0xFFFFFFF3 | (4 * (v40 & 1)) & 0xF7 | (8 * v41);
    if ( s[8] )
      HIDWORD(v131) = *(_DWORD *)(s[8] + 4LL);
    if ( !s[9] )
    {
      v58 = jiffies;
      if ( osif_twt_parse_add_dialog_attrs___last_ticks_78 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: TWT_SETUP_WAKE_DURATION is must",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "osif_twt_parse_add_dialog_attrs");
        osif_twt_parse_add_dialog_attrs___last_ticks_78 = v58;
      }
      goto LABEL_7;
    }
    v42 = *(_DWORD *)(s[9] + 4LL);
    v43 = (unsigned int)(v42 << 8);
    LODWORD(v131) = v42 << 8;
    if ( (unsigned int)v43 >= 0x10000 )
    {
      v44 = jiffies;
      if ( osif_twt_parse_add_dialog_attrs___last_ticks_80 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Invalid wake_dura_us %u",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "osif_twt_parse_add_dialog_attrs");
        osif_twt_parse_add_dialog_attrs___last_ticks_80 = v44;
      }
      goto LABEL_7;
    }
    if ( s[18] )
      DWORD1(v131) = *(_DWORD *)(s[18] + 4LL);
    if ( s[19] )
    {
      v60 = *(unsigned int *)(s[19] + 4LL);
      DWORD2(v131) = *(_DWORD *)(s[19] + 4LL);
    }
    else
    {
      v60 = DWORD2(v131);
    }
    v61 = DWORD1(v131);
    if ( DWORD1(v131) > (unsigned int)v60 )
    {
      v62 = jiffies;
      if ( osif_twt_parse_add_dialog_attrs___last_ticks_82 - jiffies + 125 < 0 )
      {
        v120 = v42 << 8;
        v122 = v39;
        v116 = v40;
        v117 = s[7] != 0;
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Invalid wake duration range min:%d max:%d. Reset to zero",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "osif_twt_parse_add_dialog_attrs",
          DWORD1(v131));
        v40 = v116;
        v41 = v117;
        v43 = v120;
        v39 = v122;
        osif_twt_parse_add_dialog_attrs___last_ticks_82 = v62;
      }
      v60 = 0;
      v61 = 0;
      *(_QWORD *)((char *)&v131 + 4) = 0;
    }
    if ( !s[10] )
    {
      v65 = jiffies;
      if ( osif_twt_parse_add_dialog_attrs___last_ticks_84 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: SETUP_WAKE_INTVL_MANTISSA is must",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "osif_twt_parse_add_dialog_attrs",
          v43,
          v60);
        osif_twt_parse_add_dialog_attrs___last_ticks_84 = v65;
      }
      goto LABEL_7;
    }
    v63 = *(_DWORD *)(s[10] + 4LL);
    HIDWORD(v129) = v63;
    if ( s[21] )
    {
      v63 = *(_DWORD *)(s[21] + 4LL);
      HIDWORD(v129) = v63;
    }
    if ( v63 >= 0x10000 )
    {
      v64 = jiffies;
      if ( osif_twt_parse_add_dialog_attrs___last_ticks_86 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Invalid wake_intvl_mantis %u",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "osif_twt_parse_add_dialog_attrs",
          v63,
          v60);
        osif_twt_parse_add_dialog_attrs___last_ticks_86 = v64;
      }
      goto LABEL_7;
    }
    v75 = v63;
    if ( v30 )
    {
      v75 = v63;
      if ( v63 )
      {
        if ( ((v63 * (unsigned __int64)(unsigned int)(1 << v30)) & 0xFFFFFFFF00000000LL) != 0 )
        {
          v76 = jiffies;
          if ( osif_twt_parse_add_dialog_attrs___last_ticks_88 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: Invalid exp %d mantissa %d",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              "osif_twt_parse_add_dialog_attrs",
              v30,
              v63);
            osif_twt_parse_add_dialog_attrs___last_ticks_88 = v76;
          }
          goto LABEL_7;
        }
        v75 = v63 << v30;
      }
    }
    v77 = v40;
    v111 = v75;
    v112 = v63;
    v115 = __PAIR64__(v60, v61);
    v118 = v41;
    v121 = v43;
    v123 = v39;
    LODWORD(v129) = v75;
    if ( s[16] )
      LODWORD(v130) = *(_DWORD *)(s[16] + 4LL);
    if ( s[17] )
    {
      v78 = *(_DWORD *)(s[17] + 4LL);
      HIDWORD(v130) = v78;
    }
    else
    {
      v78 = HIDWORD(v130);
    }
    v113 = v130;
    v114 = v78;
    if ( (unsigned int)v130 > v78 )
    {
      v79 = jiffies;
      if ( osif_twt_parse_add_dialog_attrs___last_ticks_90 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Invalid wake intvl range min:%d max:%d. Reset to zero",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "osif_twt_parse_add_dialog_attrs",
          (unsigned int)v130,
          v78);
        osif_twt_parse_add_dialog_attrs___last_ticks_90 = v79;
      }
      v115 = 0;
      *(_QWORD *)((char *)&v131 + 4) = 0;
    }
    if ( s[13] )
    {
      v126[0] = 0;
      nla_memcpy(v126, s[13], 8);
      v80 = v126[0];
    }
    else
    {
      v80 = 0;
    }
    v81 = v118;
    v119 = v80;
    v133 = v80;
    v109 = 8 * v81;
    v110 = 4 * (v77 & 1);
    if ( s[26] )
      v82 = *(_DWORD *)(s[26] + 4LL);
    else
      v82 = 0;
    LODWORD(v134) = v82;
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: twt: dialog_id %d, vdev %d, wake intvl_us %d, min %d, max %d, mantis %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "osif_twt_parse_add_dialog_attrs",
      v28,
      v17,
      v111,
      v113,
      v114,
      v112);
    LODWORD(v108) = v37;
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: twt: wake dura %d, min %d, max %d, sp_offset %d, cmd %d",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      "osif_twt_parse_add_dialog_attrs",
      v121,
      (unsigned int)v115,
      HIDWORD(v115),
      HIDWORD(v131),
      v108);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: twt: bcast %d, trigger %d, flow_type %d, prot %d wake_tsf 0x%llx",
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      "osif_twt_parse_add_dialog_attrs",
      v33 & 1,
      v123 >> 1,
      v110 >> 2,
      v109 >> 3,
      v119);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: twt: announce timeout(in us) %u",
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      "osif_twt_parse_add_dialog_attrs",
      v82);
LABEL_44:
    v46 = v13 & 0xFFFFFFFD;
    if ( v37 == 5 && v46 != 1 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: vdev %d twt_cmd type %d not supported for mode %d",
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        "osif_twt_setup_req",
        v17,
        5,
        v13);
      result = 4294967201LL;
      goto LABEL_8;
    }
    if ( v46 )
    {
      qdf_mem_copy((char *)&v127 + 4, (const void *)(a1 + 74), 6u);
      goto LABEL_51;
    }
    v59 = *(unsigned __int16 **)(a1 + 32);
    if ( !v59 )
    {
      v15 = "%s: Unable to find bss chan";
      goto LABEL_6;
    }
    if ( (unsigned __int8)wlan_reg_freq_to_band(*v59) == 3 )
    {
      v15 = "%s: Invalid bss freq";
      goto LABEL_6;
    }
    result = osif_fill_peer_macaddr(a1, (char *)&v127 + 4);
    if ( (_DWORD)result )
      goto LABEL_8;
    if ( (unsigned int)ucfg_twt_get_peer_capabilities(v14, (unsigned __int8 *)&v127 + 4, v124) )
      goto LABEL_7;
    if ( (v132 & 0x100000000LL) != 0 )
    {
      if ( (v124[0] & 4) == 0 )
      {
        v107 = jiffies;
        if ( osif_twt_setup_req___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: vdev:%d TWT setup reject: TWT Broadcast not supported",
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            "osif_twt_setup_req",
            v17);
          osif_twt_setup_req___last_ticks = v107;
          result = 4294967203LL;
          goto LABEL_8;
        }
        goto LABEL_116;
      }
    }
    else if ( (v124[0] & 2) == 0 )
    {
      v74 = jiffies;
      if ( osif_twt_setup_req___last_ticks_10 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: vdev:%d TWT setup reject: TWT responder not supported",
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          "osif_twt_setup_req",
          v17);
        osif_twt_setup_req___last_ticks_10 = v74;
        result = 4294967203LL;
        goto LABEL_8;
      }
LABEL_116:
      result = 4294967203LL;
      goto LABEL_8;
    }
LABEL_51:
    if ( (unsigned int)osif_is_twt_command_allowed(v14, a1, 1) )
    {
      v56 = "%s: TWT setup command not allowed";
LABEL_53:
      qdf_trace_msg(0x48u, 2u, v56, v48, v49, v50, v51, v52, v53, v54, v55, "osif_twt_setup_req");
      result = 4294967201LL;
      goto LABEL_8;
    }
    if ( v46 != 1 )
    {
      ucfg_twt_cfg_get_congestion_timeout(v14, &v125);
      if ( v125 )
      {
        *(_QWORD *)((char *)&v126[1] + 4) = 0x300000000LL;
        LODWORD(v126[0]) = pdev_id_from_vdev_id;
        *(_QWORD *)((char *)v126 + 4) = 1;
        if ( (unsigned int)osif_twt_requestor_disable(v14, (__int64)v126) )
        {
          v56 = "%s: Failed to disable TWT";
          goto LABEL_53;
        }
      }
      ucfg_twt_cfg_set_congestion_timeout(v14, 0);
      if ( (unsigned int)osif_twt_send_requestor_enable_cmd(v14, pdev_id_from_vdev_id) )
      {
        v56 = "%s: Failed to Enable TWT";
        goto LABEL_53;
      }
    }
    result = osif_send_twt_setup_req(a1, v14, &v127);
    goto LABEL_8;
  }
  v45 = jiffies;
  if ( osif_twt_setup_req_type_to_cmd___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid TWT_SETUP_REQ_TYPE %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "osif_twt_setup_req_type_to_cmd");
    osif_twt_setup_req_type_to_cmd___last_ticks = v45;
  }
  result = qdf_status_to_os_return(4u);
  if ( !(_DWORD)result )
  {
    v37 = v132;
    goto LABEL_44;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
