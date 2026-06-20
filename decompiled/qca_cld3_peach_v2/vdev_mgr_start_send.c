__int64 __fastcall vdev_mgr_start_send(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  __int64 v12; // x20
  unsigned int started; // w19
  const char *v15; // x2
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int16 *v25; // x25
  unsigned int v26; // w26
  __int16 v27; // w9
  int v28; // w10
  int v29; // w8
  int v30; // w10
  int v31; // w9
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w10
  __int64 v41; // x22
  char is_mlo_vdev; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  char v51; // w8
  int v52; // w10
  int v53; // w9
  char is_start_as_active; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v63; // w8
  unsigned int v64; // w8
  const char *v65; // x2
  const char *v66; // x3
  char v67; // w10
  __int16 v68; // w12
  char v69; // w10
  __int64 v70; // x1
  __int16 v71; // w10
  char v72; // w26
  bool v73; // zf
  __int16 v74; // w8
  __int16 v75; // w10
  char v76; // w9
  char v77; // w10
  int v78; // w8
  char v79; // w9
  char channel_reg_power_for_freq; // w0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int16 v89; // w8
  int v90; // w9
  int v91; // w10
  int v92; // w8
  char v93; // w9
  int v94; // w10
  char v95; // w8
  int v96; // w8
  char v97; // w9
  __int64 v98; // x8
  __int64 v99; // x22
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  __int64 cmpt_obj; // x0
  unsigned int *v109; // x8
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  size_t v118; // x2
  __int64 v119; // x0
  __int64 target_tsf_for_vdev_restart; // x0
  __int64 v121; // x8
  __int64 v122; // x9
  __int64 v123; // x0
  __int64 v124; // x0
  int v125; // w27
  __int64 v126; // x8
  _DWORD *v127; // x9
  __int64 v128; // x0
  _BYTE v129[4]; // [xsp+24h] [xbp-ECh] BYREF
  unsigned int v130; // [xsp+28h] [xbp-E8h] BYREF
  unsigned __int16 v131; // [xsp+2Ch] [xbp-E4h] BYREF
  __int64 v132; // [xsp+30h] [xbp-E0h] BYREF
  __int64 v133; // [xsp+38h] [xbp-D8h]
  _QWORD v134[5]; // [xsp+40h] [xbp-D0h] BYREF
  __int64 v135; // [xsp+68h] [xbp-A8h]
  __int64 v136; // [xsp+70h] [xbp-A0h]
  unsigned __int64 v137; // [xsp+78h] [xbp-98h]
  __int64 v138; // [xsp+80h] [xbp-90h]
  __int64 v139; // [xsp+88h] [xbp-88h]
  __int64 v140; // [xsp+90h] [xbp-80h]
  __int64 v141; // [xsp+98h] [xbp-78h]
  __int64 v142; // [xsp+A0h] [xbp-70h]
  __int64 v143; // [xsp+A8h] [xbp-68h]
  __int64 v144; // [xsp+B0h] [xbp-60h]
  _DWORD v145[8]; // [xsp+B8h] [xbp-58h] BYREF
  __int64 v146; // [xsp+D8h] [xbp-38h]
  _DWORD v147[3]; // [xsp+E0h] [xbp-30h] BYREF
  __int64 v148; // [xsp+F0h] [xbp-20h] BYREF
  __int64 v149; // [xsp+F8h] [xbp-18h]
  __int64 v150; // [xsp+100h] [xbp-10h]

  v150 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v146 = 0;
  memset(v147, 0, sizeof(v147));
  memset(v145, 0, sizeof(v145));
  v143 = 0;
  v144 = 0;
  v141 = 0;
  v142 = 0;
  v139 = 0;
  v140 = 0;
  v137 = 0;
  v138 = 0;
  v135 = 0;
  v136 = 0;
  v133 = 0;
  memset(v134, 0, sizeof(v134));
  v132 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: VDEV_MLME is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "vdev_mgr_start_send");
    started = 4;
LABEL_10:
    _ReadStatusReg(SP_EL0);
    return started;
  }
  v10 = *(_QWORD *)(a1 + 520);
  v130 = 0;
  v129[0] = 0;
  if ( !v10 )
  {
    started = 4;
    v15 = "%s: VDEV is NULL";
    goto LABEL_9;
  }
  v12 = *(_QWORD *)(v10 + 216);
  if ( !v12 )
  {
    started = 4;
    v15 = "%s: PDEV is NULL";
    goto LABEL_9;
  }
  if ( (unsigned int)wlan_objmgr_pdev_try_get_ref(*(_QWORD *)(v10 + 216), 1u, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    started = 16;
    v15 = "%s: Failed to get pdev reference";
LABEL_9:
    qdf_trace_msg(0x68u, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "vdev_mgr_start_param_update");
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Param Update Error: %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "vdev_mgr_start_send",
      started);
    goto LABEL_10;
  }
  v25 = *(unsigned __int16 **)(v10 + 40);
  v26 = *(_DWORD *)(v10 + 16) & 0xFFFFFFFD;
  LOBYTE(v132) = *(_BYTE *)(v10 + 168);
  if ( v26 == 1 && (wlan_reg_is_5ghz_ch_freq(*v25) & 1) != 0 )
  {
    tgt_dfs_set_current_channel_for_freq(
      v12,
      *v25,
      *((_QWORD *)v25 + 1),
      v25[3],
      *((unsigned __int8 *)v25 + 2),
      *((unsigned __int8 *)v25 + 3),
      *((unsigned __int8 *)v25 + 4),
      *((_DWORD *)v25 + 4),
      *((_DWORD *)v25 + 5),
      v25[16],
      (__int64)v129);
    if ( *((_DWORD *)v25 + 5) )
    {
      if ( (utils_is_dfs_cfreq2_ch(v12) & 1) != 0 )
        v27 = 8;
      else
        v27 = 0;
      WORD2(v139) = WORD2(v139) & 0xFFF7 | v27;
    }
  }
  v28 = *(unsigned __int8 *)(a1 + 8);
  HIDWORD(v132) = *(unsigned __int16 *)(a1 + 20);
  LODWORD(v133) = v28;
  v29 = *(unsigned __int8 *)(a1 + 183);
  v30 = *(unsigned __int8 *)(a1 + 418);
  WORD2(v139) &= ~0x100u;
  v31 = *(unsigned __int8 *)(a1 + 419);
  LODWORD(v134[0]) = v29;
  HIDWORD(v135) = v30;
  LODWORD(v136) = v31;
  wlan_reg_get_dfs_region(v12, &v130);
  v40 = *(_DWORD *)(a1 + 84);
  v41 = *(_QWORD *)(a1 + 520);
  v137 = __PAIR64__(*(_DWORD *)(a1 + 68), v130);
  LODWORD(v138) = v40;
  WORD1(v142) = v25[16];
  if ( !v41 )
  {
    v65 = "%s: VDEV is NULL";
    v66 = "vdev_mgr_start_param_update_mlo";
LABEL_37:
    qdf_trace_msg(0x68u, 2u, v65, v32, v33, v34, v35, v36, v37, v38, v39, v66);
    goto LABEL_38;
  }
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v41, v32, v33, v34, v35, v36, v37, v38, v39);
  v51 = a2;
  if ( (is_mlo_vdev & 1) == 0 )
    goto LABEL_39;
  v52 = HIDWORD(v144);
  HIDWORD(v144) |= 1u;
  v53 = *(_DWORD *)(v41 + 16);
  if ( v53 )
    goto LABEL_32;
  if ( (*(_BYTE *)(v41 + 60) & 2) != 0 )
    goto LABEL_25;
  HIDWORD(v144) = v52 | 3;
  v51 = a2;
  v53 = *(_DWORD *)(v41 + 16);
  if ( v53 )
    goto LABEL_32;
  if ( (*(_BYTE *)(v41 + 60) & 2) != 0 )
  {
LABEL_25:
    if ( (wlan_cm_is_link_add_connecting(v41, v43, v44, v45, v46, v47, v48, v49, v50) & 1) != 0
      || (mlo_mgr_is_link_add_link_switch(v41) & 1) != 0 )
    {
      HIDWORD(v144) |= 0x10u;
      is_start_as_active = mlo_link_recfg_is_start_as_active(v41);
      v63 = HIDWORD(v144);
      if ( (is_start_as_active & 1) != 0 )
      {
        v63 = HIDWORD(v144) | 0x80;
        HIDWORD(v144) |= 0x80u;
      }
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev mlo_link_add flag set 1 start_as_active %d",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "vdev_mgr_start_param_update_mlo",
        (v63 >> 7) & 1);
    }
  }
  v53 = *(_DWORD *)(v41 + 16);
  v51 = a2;
  if ( !v53 )
  {
    if ( (*(_BYTE *)(v41 + 49) & 4) != 0 )
    {
      HIDWORD(v144) |= 8u;
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: eMLSR support=%d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "vdev_mgr_start_param_update_mlo",
        1);
      v53 = *(_DWORD *)(v41 + 16);
      v51 = a2;
      goto LABEL_32;
    }
LABEL_39:
    v67 = *(_BYTE *)(a1 + 136);
    v68 = *(unsigned __int8 *)(a1 + 412);
    BYTE4(v138) = *((_BYTE *)v25 + 2);
    BYTE5(v138) = v67;
    v69 = *(_BYTE *)(a1 + 413);
    v70 = *v25;
    LODWORD(v139) = *v25;
    WORD2(v139) = WORD2(v139) & 0xFFFC | v68 & 0xFFFD | (2 * (v69 & 1));
    if ( v26 == 1 )
    {
      if ( (wlan_reg_is_dfs_for_freq(v12, *v25) & 1) != 0 )
        v71 = 4;
      else
        v71 = 0;
      v70 = (unsigned int)v139;
      v51 = a2;
      WORD2(v139) = WORD2(v139) & 0xFFFB | v71;
    }
    v72 = v51 & 1;
    v73 = (wlan_reg_is_dfs_for_freq(v12, v70) & 1) == 0;
    v74 = WORD2(v139) & 0xFF8F | (32 * (*(_BYTE *)(a1 + 64) & 1)) | ((*(_BYTE *)(a1 + 59) & 1) << 6);
    if ( v73 )
      v75 = 0;
    else
      v75 = 16;
    LODWORD(v140) = *(_DWORD *)(a1 + 192);
    v76 = *(_BYTE *)(a1 + 138);
    WORD2(v139) = v74 | v75;
    v77 = *(_BYTE *)(a1 + 137);
    HIDWORD(v140) = *((_DWORD *)v25 + 4);
    v78 = *((_DWORD *)v25 + 5);
    BYTE4(v141) = v76;
    v79 = *(_BYTE *)(a1 + 139);
    BYTE5(v141) = v77;
    LODWORD(v141) = v78;
    BYTE6(v141) = v79;
    channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(v12, *v25);
    v89 = *(_WORD *)(a1 + 140);
    v90 = *(_DWORD *)(a1 + 324);
    v91 = *(unsigned __int8 *)(a1 + 22);
    HIBYTE(v141) = channel_reg_power_for_freq;
    LOWORD(v142) = v89;
    v92 = *(_DWORD *)(a1 + 464);
    v73 = v91 == 0;
    HIDWORD(v142) = v90;
    v93 = *(_BYTE *)(a1 + 493);
    v94 = *(unsigned __int8 *)(a1 + 179);
    HIDWORD(v143) = v92;
    v95 = !v73;
    LOBYTE(v143) = v95;
    v96 = *(_DWORD *)(a1 + 496);
    BYTE4(v146) = v93;
    v97 = *(_BYTE *)(a1 + 468);
    v147[0] = v96;
    LOBYTE(v144) = v97;
    if ( v94 == 1 )
    {
      v98 = *(_QWORD *)(v10 + 216);
      BYTE4(v134[0]) = *(_BYTE *)(a1 + 240);
      if ( v98 && (v99 = *(_QWORD *)(v98 + 80)) != 0 )
      {
        HIDWORD(v136) = wlan_util_vdev_mgr_get_cac_timeout_for_vdev(v10);
        if ( (mlo_mgr_is_link_switch_in_progress_by_psoc(v99) & 1) != 0 && HIDWORD(v136) >= 0x65 )
        {
          HIDWORD(v136) = 100;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: link switch ongoing, cac dur %d",
            v100,
            v101,
            v102,
            v103,
            v104,
            v105,
            v106,
            v107,
            "vdev_mgr_start_param_update_cac_ms",
            100);
        }
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: psoc null",
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          "vdev_mgr_start_param_update_cac_ms");
      }
    }
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v10);
    if ( cmpt_obj )
    {
      v118 = *(unsigned __int8 *)(cmpt_obj + 178);
      v109 = (unsigned int *)cmpt_obj;
      if ( *(_BYTE *)(cmpt_obj + 178) )
      {
        BYTE6(v134[0]) = *(_BYTE *)(cmpt_obj + 178);
        qdf_mem_copy((char *)v134 + 7, (const void *)(cmpt_obj + 145), v118);
      }
      else
      {
        BYTE6(v134[0]) = 0;
      }
    }
    wlan_objmgr_pdev_release_ref(v12, 1u, v109, v110, v111, v112, v113, v114, v115, v116, v117);
    BYTE4(v133) = v72;
    if ( (a2 & 1) != 0 )
    {
      v119 = *(_QWORD *)(a1 + 520);
      *(_QWORD *)&v147[1] = 0;
      target_tsf_for_vdev_restart = wlan_ll_sap_get_target_tsf_for_vdev_restart(v119);
      if ( target_tsf_for_vdev_restart )
        *(_QWORD *)&v147[1] = target_tsf_for_vdev_restart;
    }
    v121 = *(_QWORD *)(a1 + 520);
    if ( (*(_DWORD *)(v121 + 16) & 0xFFFFFFFD) == 1 )
    {
      v122 = *(_QWORD *)(v121 + 216);
      if ( v122 )
        v123 = *(_QWORD *)(v122 + 80);
      else
        v123 = 0;
      policy_mgr_update_dfs_master_dynamic_enabled(v123, 1, *(_QWORD *)(v121 + 40));
    }
    started = tgt_vdev_mgr_start_send(a1, &v132);
    goto LABEL_10;
  }
LABEL_32:
  if ( v53 != 1 )
    goto LABEL_39;
  v64 = *(_DWORD *)(v41 + 64);
  v148 = 0;
  v149 = 0;
  v131 = 0;
  HIDWORD(v144) = HIDWORD(v144) & 0xFFFFFFDF | (v64 >> 18) & 0x10;
  mlo_ap_get_vdev_list(v41, &v131, &v148);
  if ( !v131 )
  {
    v65 = "%s: No VDEVs under AP-MLD";
    v66 = "vdev_mgr_start_param_update_mlo_partner";
    goto LABEL_37;
  }
  if ( v131 > 2u )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Invalid number of VDEVs under AP-MLD num_links:%u",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "vdev_mgr_start_param_update_mlo_partner");
    mlo_release_vdev_ref(v148);
    mlo_release_vdev_ref(v149);
LABEL_38:
    v51 = a2;
    goto LABEL_39;
  }
  v124 = v148;
  if ( v148 == v41 )
  {
    v125 = 0;
  }
  else
  {
    v145[1] = *(unsigned __int8 *)(v148 + 168);
    v145[2] = 0xFFFF;
    qdf_mem_copy(&v145[3], (const void *)(v148 + 74), 6u);
    v124 = v148;
    v125 = 1;
  }
  mlo_release_vdev_ref(v124);
  if ( v131 < 2u )
  {
    v51 = a2;
LABEL_80:
    LOBYTE(v145[0]) = v125;
    goto LABEL_39;
  }
  v126 = v149;
  if ( v149 == v41 )
  {
    v128 = mlo_release_vdev_ref(v149);
  }
  else
  {
    v127 = &v145[4 * v125 + 1];
    *v127 = *(unsigned __int8 *)(v149 + 168);
    v127[1] = 0xFFFF;
    qdf_mem_copy(v127 + 2, (const void *)(v126 + 74), 6u);
    v128 = mlo_release_vdev_ref(v149);
    LOBYTE(v125) = v125 + 1;
  }
  v51 = a2;
  if ( v131 <= 2u )
    goto LABEL_80;
  __break(0x5512u);
  return vdev_mgr_delete_send(v128);
}
