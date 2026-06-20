__int64 __fastcall wlan_ipa_setup_iface(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        unsigned __int8 *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v18; // w24
  unsigned int v19; // w26
  int v20; // w4
  int v21; // w5
  int v22; // w6
  int v23; // w7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  __int64 v33; // x25
  __int64 v34; // x4
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // w8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w22
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned __int64 StatusReg; // x8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x8
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x0
  __int64 v97; // x8
  __int64 (*v98)(void); // x8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  unsigned __int8 v115; // w9
  unsigned __int8 v116; // w8
  int v117; // w4
  int v118; // w5
  int v119; // w6
  int v120; // w7
  unsigned int v128; // w9
  char v129; // [xsp+0h] [xbp-20h]

  v18 = a3;
  v19 = a4;
  if ( a5 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: net:%pK mode:%d MAC:%02x:%02x:%02x:**:**:%02x id:%d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_ipa_setup_iface",
      a2,
      a3,
      *a5,
      a5[1],
      a5[2],
      a5[5],
      a4);
    v20 = *a5;
    v21 = a5[1];
    v22 = a5[2];
    v23 = a5[5];
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: net:%pK mode:%d MAC:%02x:%02x:%02x:**:**:%02x id:%d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_ipa_setup_iface",
      a2,
      a3,
      0,
      0,
      0,
      0,
      a4);
    v22 = 0;
    v20 = 0;
    v21 = 0;
    v23 = 0;
  }
  wlan_ipa_log_message(
    (int)"wlan_ipa_setup_iface",
    (int)"net:%pK mode:%d MAC:%02x:%02x:%02x:**:**:%02x id:%d",
    a2,
    v18,
    v20,
    v21,
    v22,
    v23,
    v19);
  v32 = *(unsigned __int8 *)(a1 + 1116);
  v33 = a1 + 1064;
  if ( *(_QWORD *)(a1 + 1088) == a2 && v32 == a4 )
  {
    if ( *(_DWORD *)(a1 + 1096) == v18 )
    {
      if ( a3 )
      {
        if ( a3 == 1 )
        {
          v34 = 0;
LABEL_69:
          qdf_trace_msg(
            0x61u,
            8u,
            "%s: found iface %u device_mode %u",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "wlan_ipa_setup_iface",
            v34,
            1);
          return 0;
        }
      }
      else if ( !(unsigned int)qdf_mem_cmp((const void *)(a1 + 1100), a5, 6u) )
      {
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: same STA iface already connected",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wlan_ipa_setup_iface");
      }
    }
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Obsolete iface %u found, device_mode %u, will remove it.",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_ipa_setup_iface",
      0,
      *(unsigned int *)(a1 + 1096));
    goto LABEL_15;
  }
  if ( v32 == a4 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Obsolete iface %u found, net_dev %pK, will remove it.",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_ipa_setup_iface",
      0);
LABEL_15:
    wlan_ipa_cleanup_iface((__int64 *)(a1 + 1064), nullptr, v35, v36, v37, v38, v39, v40, v41, v42);
  }
  v43 = *(unsigned __int8 *)(a1 + 1244);
  if ( *(_QWORD *)(a1 + 1216) == a2 && v43 == a4 )
  {
    if ( *(_DWORD *)(a1 + 1224) == v18 )
    {
      v34 = a3;
      if ( a3 == 1 )
        goto LABEL_69;
      if ( !a3 && !(unsigned int)qdf_mem_cmp((const void *)(a1 + 1228), a5, 6u) )
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: same STA iface already connected",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wlan_ipa_setup_iface");
    }
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Obsolete iface %u found, device_mode %u, will remove it.",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_ipa_setup_iface",
      1,
      *(unsigned int *)(a1 + 1224));
    goto LABEL_26;
  }
  if ( v43 == a4 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Obsolete iface %u found, net_dev %pK, will remove it.",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_ipa_setup_iface",
      1);
LABEL_26:
    wlan_ipa_cleanup_iface((__int64 *)(a1 + 1192), nullptr, v44, v45, v46, v47, v48, v49, v50, v51);
  }
  v52 = *(unsigned __int8 *)(a1 + 1372);
  if ( *(_QWORD *)(a1 + 1344) == a2 && v52 == a4 )
  {
    if ( *(_DWORD *)(a1 + 1352) == v18 )
    {
      if ( a3 == 1 )
      {
        v34 = 2;
        goto LABEL_69;
      }
      if ( !a3 && !(unsigned int)qdf_mem_cmp((const void *)(a1 + 1356), a5, 6u) )
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: same STA iface already connected",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wlan_ipa_setup_iface");
    }
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Obsolete iface %u found, device_mode %u, will remove it.",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_ipa_setup_iface",
      2,
      *(unsigned int *)(a1 + 1352));
  }
  else
  {
    if ( v52 != a4 )
      goto LABEL_38;
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Obsolete iface %u found, net_dev %pK, will remove it.",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_ipa_setup_iface",
      2);
  }
  wlan_ipa_cleanup_iface((__int64 *)(a1 + 1320), nullptr, v53, v54, v55, v56, v57, v58, v59, v60);
LABEL_38:
  if ( *(_BYTE *)(a1 + 1448) != 3 )
  {
    if ( *(_BYTE *)(a1 + 1116) != 5 )
    {
      if ( *(_BYTE *)(a1 + 1244) == 5 )
        v33 = a1 + 1192;
      else
        v33 = a1 + 1320;
    }
    if ( !v33 )
    {
      v61 = 2;
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: All the IPA interfaces are in use",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "wlan_ipa_setup_iface");
      return v61;
    }
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v33 + 56);
    }
    else
    {
      raw_spin_lock_bh(v33 + 56);
      *(_QWORD *)(v33 + 64) |= 1uLL;
    }
    if ( *(_DWORD *)(v33 + 44) == *(_DWORD *)(v33 + 48) )
    {
      _X8 = (unsigned int *)(v33 + 44);
      __asm { PRFM            #0x11, [X8] }
      do
        v128 = __ldxr(_X8);
      while ( __stxr(v128 + 1, _X8) );
    }
    else
    {
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: connect/disconnect out of sync",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "wlan_ipa_setup_iface");
    }
    *(_QWORD *)(v33 + 24) = a2;
    *(_DWORD *)(v33 + 32) = v18;
    *(_BYTE *)(v33 + 52) = a4;
    qdf_mem_copy((void *)(v33 + 36), a5, 6u);
    v79 = *(_QWORD *)(v33 + 64);
    if ( (v79 & 1) != 0 )
    {
      *(_QWORD *)(v33 + 64) = v79 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v33 + 56);
    }
    else
    {
      raw_spin_unlock(v33 + 56);
    }
    if ( *(_BYTE *)(a1 + 6984) == 1 )
    {
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: ifname %s",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "wlan_ipa_setup_iface",
        *(_QWORD *)(v33 + 24) + 296LL);
      v96 = *(_QWORD *)(a1 + 1456);
      if ( v96 && *(_QWORD *)v96 && (v97 = *(_QWORD *)(*(_QWORD *)v96 + 152LL)) != 0 )
      {
        v98 = *(__int64 (**)(void))(v97 + 136);
        if ( !v98 )
          goto LABEL_63;
        if ( *((_DWORD *)v98 - 1) != 1486385766 )
          __break(0x8228u);
        v61 = v98();
        if ( !v61 )
          goto LABEL_63;
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v88, v89, v90, v91, v92, v93, v94, v95, "cdp_ipa_setup_iface");
        v61 = 16;
      }
      wlan_ipa_cleanup_iface((__int64 *)v33, a5, v99, v100, v101, v102, v103, v104, v105, v106);
      return v61;
    }
LABEL_63:
    _qdf_nbuf_reg_free_cb(wlan_ipa_nbuf_cb);
    v115 = *(_BYTE *)(a1 + 3705);
    v116 = *(_BYTE *)(a1 + 1448) + 1;
    *(_BYTE *)(a1 + 1448) = v116;
    if ( a3 == 1 )
      *(_BYTE *)(a1 + 3705) = ++v115;
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: exit: num_iface=%d num_sap_connected=%d",
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      "wlan_ipa_setup_iface",
      v116,
      v115);
    wlan_ipa_log_message(
      (int)"wlan_ipa_setup_iface",
      (int)"exit: num_iface=%d num_sap_connected=%d",
      *(unsigned __int8 *)(a1 + 1448),
      *(unsigned __int8 *)(a1 + 3705),
      v117,
      v118,
      v119,
      v120,
      v129);
    return 0;
  }
  v61 = 2;
  qdf_trace_msg(
    0x61u,
    2u,
    "%s: Max interface reached %d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "wlan_ipa_setup_iface",
    3);
  qdf_trace_msg(
    0x61u,
    2u,
    "%s: Interface setup failed for session id - %d, device mode - %d",
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    "wlan_ipa_setup_iface",
    v19,
    v18);
  return v61;
}
