void __fastcall if_mgr_validate_beacon_interval(
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
        unsigned __int8 *a11)
{
  unsigned int v11; // w20
  int v12; // w4
  int v13; // w22
  unsigned __int8 *v15; // x21
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w23
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x19
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w8
  int v54; // w23
  __int64 v57; // x0
  __int64 v58; // x20
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x8
  __int64 v69; // x19
  int v70; // w8
  unsigned __int16 v71; // w0
  __int64 v72; // x8
  __int64 v73; // x21
  __int64 bsspeer; // x0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  int v85; // w24
  __int64 active_channel; // x0
  __int64 v87; // x22
  __int64 comp_private_obj; // x0
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  int v105; // w8
  int updated; // w0
  const char *v107; // x3
  const char *v108; // x2
  const char *v109; // x3
  int v110; // w8
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  unsigned __int16 v127; // w20
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  _BYTE v136[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v137[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v138[4]; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v139; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v140; // [xsp+18h] [xbp-8h]

  v140 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 *)(a10 + 104);
  if ( v11 == *a11 || *(_DWORD *)(a10 + 20) != 3 || (a11[20] & 1) != 0 )
    goto LABEL_4;
  v12 = *((_DWORD *)a11 + 1);
  if ( v12 <= 1 )
  {
    if ( v12 )
    {
      if ( v12 == 1 )
        goto LABEL_4;
      goto LABEL_12;
    }
    v72 = *(_QWORD *)(a10 + 152);
    v137[0] = 0;
    v136[0] = 0;
    if ( !v72 )
      goto LABEL_4;
    v73 = *(_QWORD *)(v72 + 80);
    if ( !v73 )
      goto LABEL_4;
    v139 = 0;
    v138[0] = 0;
    bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a10, 0x4Eu);
    if ( !bsspeer )
      goto LABEL_4;
    v85 = *(_DWORD *)(a10 + 16);
    wlan_objmgr_peer_release_ref(bsspeer, 0x4Eu, v77, v78, v79, v80, v81, v82, v83, v84);
    if ( (v85 & 0xFFFFFFFD) == 0 )
    {
      v108 = "%s: Bcn Intrvl validation not require for STA/CLIENT";
      v109 = "if_mgr_validate_sta_bcn_intrvl";
      goto LABEL_53;
    }
    active_channel = wlan_vdev_get_active_channel(a10);
    if ( !active_channel )
    {
      v107 = "if_mgr_validate_sta_bcn_intrvl";
      goto LABEL_50;
    }
    v87 = active_channel;
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a10, 0);
    if ( !comp_private_obj )
      goto LABEL_4;
    wlan_util_vdev_mlme_get_param(comp_private_obj, 0, &v139, v89, v90, v91, v92, v93, v94, v95, v96);
    if ( v85 != 3 )
    {
      if ( v85 != 1 )
        goto LABEL_4;
      v105 = *(_DWORD *)(v87 + 16);
      if ( v105 == *((_DWORD *)a11 + 2) && *(_DWORD *)(v87 + 20) == v105 )
        goto LABEL_4;
      qdf_trace_msg(
        0x78u,
        8u,
        "%s: *** MCC with SAP+STA sessions ****",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "if_mgr_validate_sta_bcn_intrvl");
      goto LABEL_46;
    }
    v110 = *(_DWORD *)(v87 + 16);
    if ( v110 == *((_DWORD *)a11 + 2) && *(_DWORD *)(v87 + 20) == v110 || v139 == *((unsigned __int16 *)a11 + 6) )
      goto LABEL_4;
    policy_mgr_get_allow_mcc_go_diff_bi(v73, v138);
    if ( v138[0] > 2u )
    {
      if ( v138[0] == 3 )
      {
        a11[21] = 0;
        updated = wlan_sap_stop_bss(v11);
        goto LABEL_47;
      }
      if ( v138[0] != 4 )
        goto LABEL_61;
    }
    else
    {
      if ( v138[0] == 1 )
      {
LABEL_46:
        updated = 0;
LABEL_47:
        v15 = a11;
        *((_DWORD *)a11 + 4) = updated;
        goto LABEL_66;
      }
      if ( v138[0] != 2 )
      {
LABEL_61:
        qdf_trace_msg(
          0x78u,
          2u,
          "%s: BcnIntrvl is diff can't connect to preferred AP",
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          v117,
          v118,
          "if_mgr_validate_sta_bcn_intrvl");
        updated = 16;
        goto LABEL_47;
      }
    }
    policy_mgr_get_conc_rule1(v73, v137);
    policy_mgr_get_conc_rule2(v73, v136);
    if ( v137[0] | v136[0] )
      v127 = 100;
    else
      v127 = if_mgr_calculate_mcc_beacon_interval(*((unsigned __int16 *)a11 + 6), v139);
    qdf_trace_msg(
      0x78u,
      8u,
      "%s: Peer AP BI : %d, new Beacon Interval: %d",
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      "if_mgr_validate_sta_bcn_intrvl",
      *((unsigned __int16 *)a11 + 6),
      v127);
    if ( v139 != v127 )
    {
      qdf_trace_msg(
        0x78u,
        2u,
        "%s: Beacon Interval got changed config used: %d",
        v128,
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        v135,
        "if_mgr_validate_sta_bcn_intrvl",
        v138[0]);
      *((_WORD *)a11 + 6) = v127;
      a11[21] = 1;
      updated = if_mgr_update_mcc_p2p_beacon_interval(a10, a11);
      goto LABEL_47;
    }
    goto LABEL_46;
  }
  if ( v12 == 2 )
  {
    v13 = *(_DWORD *)(a10 + 16);
    v15 = a11;
    v139 = 0;
    v16 = wlan_objmgr_vdev_try_get_bsspeer(a10, 0x4Eu);
    if ( !v16 )
      goto LABEL_4;
    v25 = *(_DWORD *)(v16 + 68);
    wlan_objmgr_peer_release_ref(v16, 0x4Eu, v17, v18, v19, v20, v21, v22, v23, v24);
    v26 = wlan_vdev_get_active_channel(a10);
    if ( !v26 )
    {
      v107 = "if_mgr_validate_p2pcli_bcn_intrvl";
      goto LABEL_50;
    }
    v35 = v26;
    v36 = wlan_objmgr_vdev_get_comp_private_obj(a10, 0);
    if ( !v36 )
      goto LABEL_4;
    wlan_util_vdev_mlme_get_param(v36, 0, &v139, v37, v38, v39, v40, v41, v42, v43, v44);
    if ( v13 )
    {
      if ( v25 != 3 )
        goto LABEL_4;
      v53 = *(_DWORD *)(v35 + 16);
      if ( v53 == *((_DWORD *)v15 + 2) && *(_DWORD *)(v35 + 20) == v53 )
        goto LABEL_4;
      if ( v139 == *((unsigned __int16 *)v15 + 6) )
        goto LABEL_4;
      qdf_trace_msg(
        0x78u,
        2u,
        "%s: BcnIntrvl is diff can't connect to P2P_GO network",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "if_mgr_validate_p2pcli_bcn_intrvl");
      *((_DWORD *)v15 + 4) = 16;
LABEL_66:
      v15[20] = 1;
      goto LABEL_4;
    }
    v108 = "%s: Ignore Beacon Interval Validation...";
    v109 = "if_mgr_validate_p2pcli_bcn_intrvl";
LABEL_53:
    qdf_trace_msg(0x78u, 8u, v108, v45, v46, v47, v48, v49, v50, v51, v52, v109);
    goto LABEL_4;
  }
  if ( v12 != 3 )
  {
    if ( v12 == 5 )
      goto LABEL_4;
LABEL_12:
    qdf_trace_msg(
      0x78u,
      2u,
      "%s: BSS opmode not supported: %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "if_mgr_validate_beacon_interval");
    goto LABEL_4;
  }
  v54 = *(_DWORD *)(a10 + 16);
  v139 = 0;
  v138[0] = 0;
  v137[0] = 0;
  v57 = wlan_vdev_get_active_channel(a10);
  if ( !v57 )
  {
    v107 = "if_mgr_validate_p2pgo_bcn_intrvl";
LABEL_50:
    qdf_trace_msg(0x78u, 2u, "%s: failed to get active channel", v27, v28, v29, v30, v31, v32, v33, v34, v107);
    goto LABEL_4;
  }
  v58 = v57;
  v59 = wlan_objmgr_vdev_get_comp_private_obj(a10, 0);
  if ( v59 )
  {
    v68 = *(_QWORD *)(a10 + 152);
    if ( v68 )
    {
      v69 = *(_QWORD *)(v68 + 80);
      if ( v69 )
      {
        wlan_util_vdev_mlme_get_param(v59, 0, &v139, v60, v61, v62, v63, v64, v65, v66, v67);
        if ( (v54 & 0xFFFFFFFD) == 0 )
        {
          v70 = *(_DWORD *)(v58 + 16);
          if ( (v70 || *(_DWORD *)(v58 + 20) | v139)
            && *(_DWORD *)(a10 + 20) == 3
            && (v70 != *((_DWORD *)a11 + 2) || *(_DWORD *)(v58 + 20) != v70)
            && v139 != *((unsigned __int16 *)a11 + 6) )
          {
            policy_mgr_get_conc_rule1(v69, v138);
            policy_mgr_get_conc_rule2(v69, v137);
            if ( v138[0] | v137[0] )
              v71 = 100;
            else
              v71 = if_mgr_calculate_mcc_beacon_interval(v139, *((unsigned __int16 *)a11 + 6));
            v15 = a11;
            if ( *((unsigned __int16 *)a11 + 6) != v71 )
              *((_WORD *)a11 + 6) = v71;
            *((_DWORD *)a11 + 4) = 0;
            goto LABEL_66;
          }
        }
      }
    }
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
}
