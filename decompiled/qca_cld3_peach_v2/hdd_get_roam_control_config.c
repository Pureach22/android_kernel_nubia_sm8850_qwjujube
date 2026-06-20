__int64 __fastcall hdd_get_roam_control_config(__int64 *a1, __int64 a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _WORD *v14; // x2
  const char *v15; // x2
  __int64 result; // x0
  int v17; // w8
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x19
  __int64 v28; // x22
  __int64 v29; // x24
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _WORD *v38; // x24
  unsigned int roam_config_status; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  const char *v48; // x4
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w20
  const char *v75; // x2
  unsigned int v76; // w1
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 link_info_by_vdev; // x0
  _QWORD *v86; // x22
  unsigned int roam_scan_freq; // w0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned int v96; // w20
  __int64 v97; // x22
  __int64 v98; // x25
  _WORD *v99; // x22
  __int64 v100; // x22
  __int64 v101; // x25
  __int64 v102; // x0
  __int64 v103; // x1
  __int64 v104; // x2
  __int64 v105; // x3
  _WORD *v106; // x25
  __int64 v107; // x22
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  unsigned int v116; // w22
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  _WORD *v133; // [xsp+8h] [xbp-308h]
  unsigned int v134; // [xsp+14h] [xbp-2FCh] BYREF
  unsigned int v135; // [xsp+18h] [xbp-2F8h] BYREF
  char v136[4]; // [xsp+1Ch] [xbp-2F4h] BYREF
  __int64 v137; // [xsp+20h] [xbp-2F0h] BYREF
  char v138[4]; // [xsp+28h] [xbp-2E8h] BYREF
  unsigned int v139; // [xsp+2Ch] [xbp-2E4h] BYREF
  _QWORD s[40]; // [xsp+30h] [xbp-2E0h] BYREF
  _DWORD v141[102]; // [xsp+170h] [xbp-1A0h] BYREF
  __int64 v142; // [xsp+308h] [xbp-8h]

  v142 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v14 = *(_WORD **)(a2 + 176);
  if ( !v14 )
  {
    v15 = "%s: Attribute CONTROL_CONFIG is not present";
LABEL_7:
    qdf_trace_msg(0x33u, 2u, v15, v6, v7, v8, v9, v10, v11, v12, v13, "hdd_get_roam_control_config");
    result = 4294967274LL;
LABEL_8:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( ((__int16)v14[1] & 0x80000000) == 0 )
  {
    do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_6:
    v15 = "%s: nla_parse failed";
    goto LABEL_7;
  }
  if ( (unsigned int)_nla_parse(s, 39, v14 + 2, (unsigned __int16)(*v14 - 4), &roam_control_policy, 31, 0) )
    goto LABEL_6;
  if ( s[2] )
    v17 = 5;
  else
    v17 = 0;
  if ( s[6] )
    v17 |= 8u;
  if ( s[4] )
    v17 += 836;
  if ( s[17] )
    v17 += 8;
  if ( s[37] )
    v17 += 8;
  if ( s[35] )
    v17 += 8;
  if ( !v17 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: No data requested",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hdd_send_roam_control_config");
    v74 = -22;
LABEL_76:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to enable/disable roam control",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "hdd_get_roam_control_config");
    result = v74;
    goto LABEL_8;
  }
  v18 = _cfg80211_alloc_reply_skb(a1[3], 103, 197, (unsigned int)(v17 + 16));
  if ( !v18 )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "hdd_send_roam_control_config");
    v74 = -12;
    goto LABEL_76;
  }
  v27 = v18;
  v138[0] = 0;
  v137 = 0;
  v136[0] = 0;
  memset(v141, 0, sizeof(v141));
  v28 = *(_QWORD *)(v27 + 216);
  v29 = *(unsigned int *)(v27 + 208);
  v134 = 0;
  v135 = 0;
  if ( (nla_put(v27, 32790, 0, 0) & 0x80000000) != 0 || (v38 = (_WORD *)(v28 + v29)) == nullptr )
  {
    v75 = "%s: nla nest start failure";
    v76 = 2;
LABEL_36:
    qdf_trace_msg(0x33u, v76, v75, v30, v31, v32, v33, v34, v35, v36, v37, "hdd_roam_control_config_fill_data");
    v65 = -22;
    goto LABEL_75;
  }
  if ( s[2] )
  {
    roam_config_status = sme_get_roam_config_status(a1[2], a3, v138);
    if ( roam_config_status )
      goto LABEL_74;
    if ( v138[0] )
      v48 = "Enabled";
    else
      v48 = "Disabled";
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Roam control: %s",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "hdd_roam_control_config_fill_data",
      v48);
    LOBYTE(v139) = v138[0];
    if ( (unsigned int)nla_put(v27, 2, 1, &v139) )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: failed to put vendor_roam_control",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "hdd_roam_control_config_fill_data");
      v65 = -12;
LABEL_75:
      v74 = v65;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: nla put fail",
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        "hdd_send_roam_control_config");
      sk_skb_reason_drop(0, v27, 2);
      goto LABEL_76;
    }
  }
  if ( s[6] )
  {
    roam_config_status = sme_get_full_roam_scan_period(a1[2], a3, (char *)&v137 + 4);
    if ( roam_config_status )
      goto LABEL_74;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: full_roam_scan_period: %u",
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      "hdd_roam_control_config_fill_data",
      HIDWORD(v137));
    v139 = HIDWORD(v137);
    if ( (unsigned int)nla_put(v27, 6, 4, &v139) )
    {
      v75 = "%s: failed to put full_roam_scan_period";
LABEL_72:
      v76 = 4;
      goto LABEL_36;
    }
  }
  if ( !s[4] )
  {
LABEL_58:
    if ( s[17] )
    {
      roam_config_status = ucfg_cm_get_roam_band(*a1, a3, &v137);
      if ( roam_config_status )
        goto LABEL_74;
      v116 = v137 & 4 | (__rbit32(v137) >> 30);
      v139 = v116;
      if ( (unsigned int)nla_put(v27, 17, 4, &v139) )
      {
        v75 = "%s: failed to put roam_band";
        goto LABEL_72;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: sending vendor_band_mask: %d reg band:%d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "hdd_roam_control_config_fill_data",
        v116,
        (unsigned int)v137);
    }
    if ( s[37] )
    {
      roam_config_status = sme_get_roam_periodic_scan_interval(a1[2], a3, &v135);
      if ( roam_config_status )
        goto LABEL_74;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: roam_periodic_scan_interval: %u",
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        "hdd_roam_control_config_fill_data",
        v135);
      v139 = v135;
      if ( (unsigned int)nla_put(v27, 37, 4, &v139) )
      {
        v75 = "%s: failed to put roam_periodic_scan_interval";
        goto LABEL_72;
      }
    }
    if ( s[35] )
    {
      roam_config_status = sme_get_roam_score_delta_value(a1[2], a3, &v134);
      if ( roam_config_status )
        goto LABEL_74;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: roam_score_delta: %u",
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        v131,
        v132,
        "hdd_roam_control_config_fill_data",
        v134);
      v139 = v134;
      if ( (unsigned int)nla_put(v27, 35, 4, &v139) )
      {
        v75 = "%s: failed to put roam_score_delta value";
        goto LABEL_72;
      }
    }
    roam_config_status = 0;
    *v38 = *(_WORD *)(v27 + 216) + *(_DWORD *)(v27 + 208) - (_WORD)v38;
LABEL_74:
    v65 = qdf_status_to_os_return(roam_config_status);
    if ( !v65 )
    {
      v74 = cfg80211_vendor_cmd_reply(v27);
      if ( !v74 )
      {
        result = qdf_status_to_os_return(0);
        goto LABEL_8;
      }
      goto LABEL_76;
    }
    goto LABEL_75;
  }
  link_info_by_vdev = hdd_get_link_info_by_vdev(a1);
  if ( !link_info_by_vdev )
  {
    v75 = "%s: Invalid vdev";
    goto LABEL_72;
  }
  v86 = (_QWORD *)link_info_by_vdev;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Get roam scan frequencies req received",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "hdd_roam_control_config_fill_data");
  roam_scan_freq = hdd_get_roam_scan_freq(*v86, a1[2], v141, v136);
  if ( roam_scan_freq )
  {
    v96 = roam_scan_freq;
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: failed to get roam scan freq",
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      "hdd_roam_control_config_fill_data");
    roam_config_status = v96;
    goto LABEL_74;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: num_channels %d",
    v88,
    v89,
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    "hdd_roam_control_config_fill_data",
    (unsigned __int8)v136[0]);
  v97 = *(_QWORD *)(v27 + 216);
  v98 = *(unsigned int *)(v27 + 208);
  if ( (nla_put(v27, 32772, 0, 0) & 0x80000000) != 0 )
    goto LABEL_62;
  v99 = (_WORD *)(v97 + v98);
  if ( !v99 )
    goto LABEL_62;
  v139 = 0;
  if ( (unsigned int)nla_put(v27, 2, 4, &v139) )
  {
    v75 = "%s: failed to put list type";
    goto LABEL_72;
  }
  v133 = v99;
  v100 = *(_QWORD *)(v27 + 216);
  v101 = *(unsigned int *)(v27 + 208);
  v102 = nla_put(v27, 32769, 0, 0);
  if ( (v102 & 0x80000000) != 0 || (v106 = (_WORD *)(v100 + v101)) == nullptr )
  {
LABEL_62:
    v75 = "%s: failed to nest start for roam scan freq";
    goto LABEL_72;
  }
  if ( !v136[0] )
  {
LABEL_57:
    *v106 = *(_DWORD *)(v27 + 216) + *(_DWORD *)(v27 + 208) - (_WORD)v106;
    *v133 = *(_WORD *)(v27 + 216) + *(_WORD *)(v27 + 208) - (_WORD)v133;
    goto LABEL_58;
  }
  v107 = 0;
  while ( v107 != 102 )
  {
    v139 = v141[v107];
    v102 = nla_put(v27, 1, 4, &v139);
    if ( (_DWORD)v102 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: failed to put freq at index %d",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        "hdd_roam_control_config_fill_data",
        (unsigned int)v107);
      v65 = -22;
      goto LABEL_75;
    }
    if ( ++v107 >= (unsigned __int64)(unsigned __int8)v136[0] )
      goto LABEL_57;
  }
  __break(0x5512u);
  return hdd_send_roam_triggers_to_sme(v102, v103, v104, v105);
}
