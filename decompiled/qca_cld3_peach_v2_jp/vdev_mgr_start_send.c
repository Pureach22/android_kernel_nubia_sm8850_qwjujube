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
  unsigned __int16 *v25; // x24
  unsigned int v26; // w25
  __int16 v27; // w26
  int v28; // w9
  int v29; // w10
  int v30; // w8
  int v31; // w9
  char v32; // w10
  char v33; // w8
  unsigned int v34; // w22
  __int16 v35; // w26
  __int16 v36; // w8
  __int16 v37; // w8
  __int16 v38; // w8
  char v39; // w9
  char v40; // w10
  int v41; // w8
  char v42; // w9
  char channel_reg_power_for_freq; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int16 v52; // w8
  int v53; // w9
  int v54; // w10
  int v55; // w8
  bool v56; // zf
  char v57; // w9
  int v58; // w10
  char v59; // w8
  int v60; // w8
  char v61; // w9
  __int64 v62; // x8
  __int64 cmpt_obj; // x0
  unsigned int *v64; // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  size_t v73; // x2
  __int64 v74; // x0
  __int64 target_tsf_for_vdev_restart; // x0
  __int64 v76; // x8
  __int64 v77; // x9
  __int64 v78; // x0
  _BYTE v79[4]; // [xsp+20h] [xbp-A0h] BYREF
  unsigned int v80; // [xsp+24h] [xbp-9Ch] BYREF
  __int64 v81; // [xsp+28h] [xbp-98h] BYREF
  __int64 v82; // [xsp+30h] [xbp-90h]
  _QWORD v83[5]; // [xsp+38h] [xbp-88h] BYREF
  __int64 v84; // [xsp+60h] [xbp-60h]
  __int64 v85; // [xsp+68h] [xbp-58h]
  unsigned __int64 v86; // [xsp+70h] [xbp-50h]
  __int64 v87; // [xsp+78h] [xbp-48h]
  __int64 v88; // [xsp+80h] [xbp-40h]
  __int64 v89; // [xsp+88h] [xbp-38h]
  __int64 v90; // [xsp+90h] [xbp-30h]
  __int64 v91; // [xsp+98h] [xbp-28h]
  __int64 v92; // [xsp+A0h] [xbp-20h]
  _DWORD v93[3]; // [xsp+A8h] [xbp-18h] BYREF
  __int64 v94; // [xsp+B8h] [xbp-8h]

  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v92 = 0;
  memset(v93, 0, sizeof(v93));
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  memset(v83, 0, sizeof(v83));
  v81 = 0;
  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 504);
    v80 = 0;
    v79[0] = 0;
    if ( !v10 )
    {
      started = 4;
      v15 = "%s: VDEV is NULL";
      goto LABEL_9;
    }
    v12 = *(_QWORD *)(v10 + 152);
    if ( !v12 )
    {
      started = 4;
      v15 = "%s: PDEV is NULL";
      goto LABEL_9;
    }
    if ( (unsigned int)wlan_objmgr_pdev_try_get_ref(*(_QWORD *)(v10 + 152), 1u, a3, a4, a5, a6, a7, a8, a9, a10) )
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
    LOBYTE(v81) = *(_BYTE *)(v10 + 104);
    if ( v26 == 1
      && (wlan_reg_is_5ghz_ch_freq(*v25) & 1) != 0
      && (tgt_dfs_set_current_channel_for_freq(
            v12,
            *v25,
            *((_QWORD *)v25 + 1),
            v25[3],
            *((unsigned __int8 *)v25 + 2),
            *((unsigned __int8 *)v25 + 3),
            *((unsigned __int8 *)v25 + 4),
            *((_DWORD *)v25 + 4),
            *((_DWORD *)v25 + 5),
            0,
            (__int64)v79),
          *((_DWORD *)v25 + 5)) )
    {
      if ( (utils_is_dfs_cfreq2_ch(v12) & 1) != 0 )
        v27 = 8;
      else
        v27 = 0;
      LOWORD(v88) = v27;
    }
    else
    {
      v27 = 0;
    }
    v28 = *(unsigned __int8 *)(a1 + 8);
    v29 = *(unsigned __int8 *)(a1 + 167);
    HIDWORD(v81) = *(unsigned __int16 *)(a1 + 20);
    LODWORD(v82) = v28;
    v30 = *(unsigned __int8 *)(a1 + 402);
    v31 = *(unsigned __int8 *)(a1 + 403);
    LODWORD(v83[0]) = v29;
    HIDWORD(v84) = v30;
    LODWORD(v85) = v31;
    wlan_reg_get_dfs_region(v12, &v80);
    v32 = *(_BYTE *)(a1 + 397);
    v86 = __PAIR64__(*(_DWORD *)(a1 + 68), v80);
    v33 = *((_BYTE *)v25 + 2);
    BYTE1(v87) = *(_BYTE *)(a1 + 120);
    LOBYTE(v87) = v33;
    v34 = *v25;
    v35 = v27 | *(unsigned __int8 *)(a1 + 396) | (2 * (v32 & 1));
    HIDWORD(v87) = v34;
    if ( v26 == 1 )
    {
      if ( (wlan_reg_is_dfs_for_freq(v12, v34) & 1) != 0 )
        v36 = 4;
      else
        v36 = 0;
      v35 |= v36;
    }
    if ( (wlan_reg_is_dfs_for_freq(v12, v34) & 1) != 0 )
      v37 = 16;
    else
      v37 = 0;
    v38 = (v35 | v37) & 0xFF9F | (32 * (*(_BYTE *)(a1 + 64) & 1)) & 0xBF | ((*(_BYTE *)(a1 + 59) & 1) << 6);
    HIDWORD(v88) = *(_DWORD *)(a1 + 176);
    v39 = *(_BYTE *)(a1 + 122);
    v40 = *(_BYTE *)(a1 + 121);
    LOWORD(v88) = v38;
    LODWORD(v89) = *((_DWORD *)v25 + 4);
    v41 = *((_DWORD *)v25 + 5);
    LOBYTE(v90) = v39;
    v42 = *(_BYTE *)(a1 + 123);
    BYTE1(v90) = v40;
    HIDWORD(v89) = v41;
    BYTE2(v90) = v42;
    channel_reg_power_for_freq = wlan_reg_get_channel_reg_power_for_freq(v12, *v25);
    v52 = *(_WORD *)(a1 + 124);
    v53 = *(_DWORD *)(a1 + 308);
    v54 = *(unsigned __int8 *)(a1 + 22);
    BYTE3(v90) = channel_reg_power_for_freq;
    WORD2(v90) = v52;
    v55 = *(_DWORD *)(a1 + 448);
    v56 = v54 == 0;
    LODWORD(v91) = v53;
    v57 = *(_BYTE *)(a1 + 477);
    v58 = *(unsigned __int8 *)(a1 + 163);
    LODWORD(v92) = v55;
    v59 = !v56;
    BYTE4(v91) = v59;
    v60 = *(_DWORD *)(a1 + 480);
    BYTE5(v92) = v57;
    v61 = *(_BYTE *)(a1 + 452);
    v93[0] = v60;
    BYTE4(v92) = v61;
    if ( v58 == 1 )
    {
      v62 = *(_QWORD *)(v10 + 152);
      BYTE4(v83[0]) = *(_BYTE *)(a1 + 224);
      if ( v62 && *(_QWORD *)(v62 + 80) )
        HIDWORD(v85) = wlan_util_vdev_mgr_get_cac_timeout_for_vdev(v10);
      else
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: psoc null",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "vdev_mgr_start_param_update_cac_ms");
    }
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v10);
    if ( cmpt_obj )
    {
      v73 = *(unsigned __int8 *)(cmpt_obj + 162);
      v64 = (unsigned int *)cmpt_obj;
      if ( *(_BYTE *)(cmpt_obj + 162) )
      {
        BYTE6(v83[0]) = *(_BYTE *)(cmpt_obj + 162);
        qdf_mem_copy((char *)v83 + 7, (const void *)(cmpt_obj + 129), v73);
      }
      else
      {
        BYTE6(v83[0]) = 0;
      }
    }
    wlan_objmgr_pdev_release_ref(v12, 1u, v64, v65, v66, v67, v68, v69, v70, v71, v72);
    BYTE4(v82) = a2 & 1;
    if ( (a2 & 1) != 0 )
    {
      v74 = *(_QWORD *)(a1 + 504);
      *(_QWORD *)&v93[1] = 0;
      target_tsf_for_vdev_restart = wlan_ll_sap_get_target_tsf_for_vdev_restart(v74);
      if ( target_tsf_for_vdev_restart )
        *(_QWORD *)&v93[1] = target_tsf_for_vdev_restart;
    }
    v76 = *(_QWORD *)(a1 + 504);
    if ( (*(_DWORD *)(v76 + 16) & 0xFFFFFFFD) == 1 )
    {
      v77 = *(_QWORD *)(v76 + 152);
      if ( v77 )
        v78 = *(_QWORD *)(v77 + 80);
      else
        v78 = 0;
      policy_mgr_update_dfs_master_dynamic_enabled(v78, 1, *(_QWORD *)(v76 + 40));
    }
    started = tgt_vdev_mgr_start_send(a1, &v81);
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: VDEV_MLME is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "vdev_mgr_start_send");
    started = 4;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return started;
}
