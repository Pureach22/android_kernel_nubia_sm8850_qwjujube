__int64 __fastcall cm_connect_complete_ind(
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
  __int64 v11; // x20
  unsigned int v12; // w19
  __int64 v14; // x24
  unsigned int v15; // w22
  int v16; // w8
  __int16 v17; // w8
  __int64 v18; // x27
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 cmpt_obj; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x25
  _DWORD *crypto_params; // x0
  int v38; // w9
  _DWORD *v39; // x26
  char v40; // w8
  bool v41; // zf
  __int64 result; // x0
  __int64 v43; // x5
  const char *v44; // x2
  const char *v45; // x2
  int v46; // w9
  char v47; // w10
  unsigned __int64 StatusReg; // x9
  char v49; // w8
  int v50; // w10
  __int64 v51; // x8
  char v52; // w8
  __int64 v53; // x9
  unsigned int v54; // w8
  int v55; // w9
  size_t v56; // x2
  __int16 v57; // w9
  char v58; // w10
  __int64 v59; // x8
  unsigned int v60; // w25
  unsigned int v61; // w9
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  int param; // w0
  unsigned int v71; // w26
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  char tdls_chan_switch_prohibited; // w25
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  char tdls_prohibited; // w0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  bool v114; // [xsp+8h] [xbp-58h] BYREF
  unsigned int v115; // [xsp+Ch] [xbp-54h] BYREF
  __int16 v116; // [xsp+10h] [xbp-50h] BYREF
  _QWORD v117[7]; // [xsp+12h] [xbp-4Eh] BYREF
  _BYTE v118[11]; // [xsp+4Ah] [xbp-16h]
  __int64 v119; // [xsp+58h] [xbp-8h]

  v119 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v114 = 0;
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev or rsp is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "cm_connect_complete_ind");
    result = 4;
    goto LABEL_71;
  }
  v11 = *(_QWORD *)(a1 + 152);
  v12 = *(unsigned __int8 *)(a1 + 104);
  if ( !v11 )
  {
    v43 = *(unsigned int *)(a2 + 4);
    v44 = "%s: vdev %d cm_id 0x%x: pdev not found";
LABEL_19:
    qdf_trace_msg(
      0x68u,
      2u,
      v44,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_connect_complete_ind",
      *(unsigned __int8 *)(a1 + 104),
      v43);
    result = 4;
    goto LABEL_71;
  }
  v14 = *(_QWORD *)(v11 + 80);
  if ( !v14 )
  {
    v43 = *(unsigned int *)(a2 + 4);
    v44 = "%s: vdev %d cm_id 0x%x: psoc not found";
    goto LABEL_19;
  }
  v15 = *(_DWORD *)(a1 + 16);
  cm_csr_connect_done_ind(a1, a2);
  v16 = *(_DWORD *)(a2 + 52);
  v115 = 0;
  *(_DWORD *)&v118[7] = 0;
  if ( v16 )
    v17 = 9;
  else
    v17 = 8;
  *(_QWORD *)v118 = 0;
  memset(v117, 0, sizeof(v117));
  v116 = v17;
  wlan_mlme_get_sta_ch_width(a1, &v115, nullptr);
  v18 = *(_QWORD *)(a1 + 40);
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v19, v20, v21, v22, v23, v24, v25, v26);
  if ( !cmpt_obj )
  {
    v45 = "%s: vdev component object is NULL";
LABEL_22:
    qdf_trace_msg(0x68u, 2u, v45, v28, v29, v30, v31, v32, v33, v34, v35, "cm_cp_stats_cstats_log_connect_event");
    goto LABEL_49;
  }
  v36 = cmpt_obj;
  crypto_params = (_DWORD *)wlan_crypto_vdev_get_crypto_params(a1);
  if ( !crypto_params )
  {
    v45 = "%s: crypto params is null";
    goto LABEL_22;
  }
  v38 = *crypto_params;
  v39 = crypto_params;
  v40 = 0;
  if ( !*crypto_params || (v38 & 3) != 0 )
    goto LABEL_32;
  if ( (v38 & 0x10) != 0 )
  {
    v40 = (crypto_params[1] & 0x18001) != 0;
  }
  else
  {
    if ( (v38 & 4) == 0 )
    {
      if ( (v38 & 0x6C8) != 0 )
      {
        v41 = (crypto_params[5] & 0x10300A1) == 0;
        v40 = 4;
        goto LABEL_30;
      }
      if ( (v38 & 0x20) != 0 )
      {
        v41 = (crypto_params[5] & 1) == 0;
        v40 = 2;
      }
      else
      {
        if ( (v38 & 0x100) == 0 )
        {
          v40 = 0;
          goto LABEL_32;
        }
        v41 = (crypto_params[5] & 0x2000) == 0;
        v40 = 6;
      }
LABEL_30:
      if ( v41 )
        ++v40;
      goto LABEL_32;
    }
    v40 = 1;
  }
LABEL_32:
  v46 = *(_DWORD *)(a1 + 16);
  v47 = *(_BYTE *)(a1 + 104);
  v118[10] = v40;
  strcpy((char *)v117, "A");
  BYTE2(v117[0]) = v46;
  BYTE3(v117[0]) = v47;
  *(_QWORD *)((char *)v117 + 4) = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v49 = v115;
  v50 = *(_DWORD *)(a2 + 48);
  *(_QWORD *)((char *)&v117[1] + 4) = StatusReg;
  *(_WORD *)&v118[4] = v50;
  if ( v115 >= 7 )
    v49 = -1;
  v118[6] = v49;
  v51 = *(unsigned int *)(v18 + 28);
  if ( (unsigned int)v51 >= 0xB )
  {
    if ( (unsigned int)(v51 - 11) >= 0xA )
    {
      if ( (unsigned int)(v51 - 21) >= 0xA )
        v52 = -1;
      else
        v52 = 10;
    }
    else
    {
      v52 = 5;
    }
  }
  else
  {
    v52 = byte_9FDF38[v51];
  }
  v53 = *(_QWORD *)(v36 + 520);
  v118[7] = v52;
  v118[8] = *(_BYTE *)(v53 + 24007);
  v54 = v39[1];
  if ( v54 )
  {
    if ( (v54 & 0x400) != 0 )
    {
      LOBYTE(v54) = 6;
    }
    else if ( (v54 & 0x200) != 0 )
    {
      LOBYTE(v54) = 5;
    }
    else if ( (v54 & 0x19CC) != 0 )
    {
      LOBYTE(v54) = 4;
    }
    else if ( (v54 & 2) != 0 )
    {
      LOBYTE(v54) = 3;
    }
    else if ( (v54 & 0x2010) != 0 )
    {
      LOBYTE(v54) = 7;
    }
    else if ( (v54 & 0x8001) != 0 )
    {
      LOBYTE(v54) = 1;
    }
    else
    {
      v54 = (v54 >> 15) & 2;
    }
  }
  v55 = *(_DWORD *)(a2 + 52);
  v118[9] = v54;
  v56 = *(unsigned __int8 *)(a2 + 14);
  *(_WORD *)&v118[2] = v55;
  LOBYTE(v117[3]) = v56;
  qdf_mem_copy((char *)&v117[3] + 1, (const void *)(a2 + 15), v56);
  v57 = *(_WORD *)(a2 + 9);
  v58 = *(_BYTE *)(a2 + 13);
  BYTE4(v117[2]) = *(_BYTE *)(a2 + 8);
  *(_WORD *)((char *)&v117[2] + 5) = v57;
  HIBYTE(v117[2]) = v58;
  wlan_cp_stats_cstats_write_to_buff(0, &v116, 69);
LABEL_49:
  cm_connect_info(
    a1,
    *(_DWORD *)(a2 + 52) == 0,
    (const void *)(a2 + 8),
    (unsigned __int8 *)(a2 + 14),
    *(_DWORD *)(a2 + 48));
  if ( !*(_DWORD *)(a2 + 52) )
  {
    policy_mgr_is_hw_dbs_capable(v14);
    policy_mgr_incr_active_session(v14, v15, v12, 1);
    v59 = *(_QWORD *)(a2 + 80);
    v60 = *(unsigned __int8 *)(a1 + 104);
    if ( v59 )
    {
      v61 = *(_DWORD *)(a2 + 72);
      if ( v61 >= 0x19 )
        cm_update_prev_ap_ie(v14, *(unsigned __int8 *)(a1 + 104), v61 - 24, (const void *)(v59 + 24));
    }
    if ( (wlan_crypto_get_param(a1, 7u) & 0x10000800) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Update the MDID in PMK cache for FT-SAE case",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "cm_process_connect_complete");
      cm_update_pmk_cache_ft(v14, v60, 0);
    }
    cm_update_owe_info(a1, a2);
    ((void (__fastcall *)(_QWORD))cm_csr_set_joined)(v60);
    cm_csr_send_set_ie(a1);
    param = wlan_crypto_get_param(a1, 1u);
    if ( (*(_BYTE *)(a2 + 1) & 1) != 0 )
    {
      v71 = 120000000;
    }
    else
    {
      if ( (*(_BYTE *)(a2 + 152) & 1) != 0
        || (param & 0xFFFDFFFF) == 0
        || (param & 0x8000) != 0
        || (param & 0x10001) != 0 )
      {
        cm_csr_set_ss_none(v60);
        cm_roam_start_init_on_connect(v11, v60);
LABEL_65:
        tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(a1, v80, v81, v82, v83, v84, v85, v86, v87);
        tdls_prohibited = mlme_get_tdls_prohibited(a1, v89, v90, v91, v92, v93, v94, v95, v96);
        v98 = wlan_tdls_notify_sta_connect(v12, tdls_chan_switch_prohibited & 1, tdls_prohibited & 1, a1);
        wlan_p2p_status_connect(a1, v98, v99, v100, v101, v102, v103, v104, v105);
        cm_update_associated_ch_info(a1, 1);
        wlan_psoc_mlme_get_11be_capab(v14, &v114);
        if ( v114 && (unsigned int)policy_mgr_current_connections_update(v14, v12, *(_DWORD *)(a2 + 48), 0xEu, 0) == 16 )
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: Failed to take next action after connect",
            v106,
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            "cm_connect_complete_ind");
        goto LABEL_68;
      }
      v71 = 70000000;
    }
    v72 = cm_csr_set_ss_wait_for_key(v60);
    if ( (unsigned int)cm_start_wait_for_key_timer(a1, v71, v72, v73, v74, v75, v76, v77, v78, v79) )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Failed wait for key timer start",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "cm_update_wait_for_key_timer");
      cm_csr_set_ss_none(v60);
    }
    goto LABEL_65;
  }
LABEL_68:
  if ( !v15 )
    wlan_cm_roam_state_change(v11, v12, 1, 1);
  result = 0;
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
