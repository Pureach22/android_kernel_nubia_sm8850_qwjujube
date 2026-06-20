__int64 __fastcall if_mgr_validate_candidate(
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
  unsigned int v12; // w19
  __int64 cm_ctx_fl; // x0
  __int64 v14; // x23
  __int64 v15; // x21
  __int64 v16; // x25
  unsigned int v17; // w24
  __int64 *v18; // x26
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int16 v35; // w9
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x4
  __int64 v45; // x5
  const char *v46; // x2
  __int64 v47; // x6
  __int64 v48; // x7
  unsigned int v49; // w8
  unsigned int v50; // w1
  __int64 result; // x0
  __int64 v52; // x25
  __int64 v53; // x26
  __int64 v54; // x8
  unsigned int v55; // w20
  unsigned int v56; // w21
  unsigned int v57; // w24
  unsigned int v58; // w22
  __int64 v59; // x8
  unsigned int v60; // w25
  int v61; // w8
  unsigned int conc_ext_flags; // w0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned int conc_freq; // w25
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x8
  int v81; // w9
  __int64 v82; // x8
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  const char *v91; // x2
  unsigned int v92; // [xsp+0h] [xbp-30h]
  int v93; // [xsp+8h] [xbp-28h]
  char v94[4]; // [xsp+10h] [xbp-20h] BYREF
  char v95[4]; // [xsp+14h] [xbp-1Ch] BYREF
  _DWORD v96[4]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v97; // [xsp+28h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_DWORD *)(a2 + 16);
  memset(v96, 0, 7);
  cm_ctx_fl = cm_get_cm_ctx_fl(a1, (__int64)"if_mgr_validate_candidate", 0x39Bu, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cm_ctx_fl || (v14 = *(_QWORD *)(a1 + 216)) == 0 || (v15 = *(_QWORD *)(v14 + 80)) == 0 )
  {
    result = 16;
    goto LABEL_51;
  }
  v16 = *(_QWORD *)(a2 + 24);
  v17 = *(_DWORD *)(a1 + 16);
  v18 = (__int64 *)cm_ctx_fl;
  if ( (*(_QWORD *)(v16 + 1824) || *(_QWORD *)(v16 + 1800) || *(_QWORD *)(v16 + 1808))
    && ((mlme_get_bss_11be_allowed(
           *(_QWORD *)(v14 + 80),
           a2 + 8,
           *(_QWORD *)(v16 + 1896) + 36LL,
           (unsigned __int16)(*(_WORD *)(v16 + 1888) - 36))
       & 1) == 0
     || (wlan_vdev_mlme_get_user_dis_eht_flag(a1, v19, v20, v21, v22, v23, v24, v25, v26) & 1) != 0
     || !wlan_reg_phybitmap_support_11be(*(_QWORD *)(a1 + 216), v27, v28, v29, v30, v31, v32, v33, v34)) )
  {
    *(_QWORD *)(v16 + 1824) = 0;
    *(_QWORD *)(v16 + 1800) = 0;
    *(_QWORD *)(v16 + 1808) = 0;
    qdf_mem_set((void *)(v16 + 1912), 0xA0u, 0);
    *(_BYTE *)(a2 + 32) = 0;
  }
  if ( !v17 )
  {
    if ( (policy_mgr_is_sta_chan_valid_for_connect_and_roam(v14, v12) & 1) != 0 )
    {
      v52 = *(_QWORD *)(a2 + 24);
      if ( v52 )
      {
        v53 = *v18;
        if ( v53 )
        {
          v54 = *(_QWORD *)(v53 + 216);
          if ( v54 )
          {
            if ( *(_QWORD *)(v54 + 80)
              && (!(unsigned int)wlan_mlme_get_t2lm_negotiation_supported()
               || (*(_BYTE *)(v53 + 60) & 2) != 0
               || *(_DWORD *)(v53 + 16)
               || !*(_QWORD *)(v52 + 1840)
               || !(unsigned int)wlan_t2lm_validate_candidate(v52)) )
            {
              goto LABEL_12;
            }
          }
        }
      }
      v55 = *(unsigned __int8 *)(a2 + 8);
      v56 = *(unsigned __int8 *)(a2 + 9);
      v57 = *(unsigned __int8 *)(a2 + 10);
      v58 = *(unsigned __int8 *)(a2 + 13);
      v59 = wlan_reg_is_freq_indoor() & 1;
      v46 = "%s: STA connection not allowed on bssid: %02x:%02x:%02x:**:**:%02x with freq: %d (6Ghz or indoor(%d)), as TT"
            "LM is not mapped on this link";
    }
    else
    {
      v55 = *(unsigned __int8 *)(a2 + 8);
      v56 = *(unsigned __int8 *)(a2 + 9);
      v57 = *(unsigned __int8 *)(a2 + 10);
      v58 = *(unsigned __int8 *)(a2 + 13);
      v59 = wlan_reg_is_freq_indoor() & 1;
      v46 = "%s: STA connection not allowed on bssid: %02x:%02x:%02x:**:**:%02x with freq: %d (6Ghz or indoor(%d)), as no"
            "t valid for connection";
    }
    v50 = 8;
    v44 = v55;
    v45 = v56;
    v47 = v57;
    v48 = v58;
    v93 = v59;
    v92 = v12;
LABEL_49:
    qdf_trace_msg(
      0x78u,
      v50,
      v46,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "if_mgr_validate_candidate",
      v44,
      v45,
      v47,
      v48,
      v92,
      v93);
LABEL_50:
    result = 4;
    goto LABEL_51;
  }
LABEL_12:
  v35 = *(_WORD *)(a2 + 12);
  v96[0] = *(_DWORD *)(a2 + 8);
  LOWORD(v96[1]) = v35;
  BYTE2(v96[1]) = -1;
  wlan_objmgr_pdev_iterate_obj_list(
    v14,
    2,
    (void (__fastcall *)(__int64, __int64, __int64))if_mgr_get_vdev_id_from_bssid,
    (__int64)v96,
    0,
    0x4Eu);
  v44 = BYTE2(v96[1]);
  if ( BYTE2(v96[1]) != 255 )
  {
    v45 = LOBYTE(v96[0]);
    v46 = "%s: vdev_id %d already connected to %02x:%02x:%02x:**:**:%02x. select next bss for vdev_id %d";
    v47 = BYTE1(v96[0]);
    v48 = BYTE2(v96[0]);
    v49 = BYTE1(v96[1]);
    v93 = *(unsigned __int8 *)(a1 + 168);
    v50 = 4;
LABEL_48:
    v92 = v49;
    goto LABEL_49;
  }
  v60 = policy_mgr_qdf_opmode_to_pm_con_mode(v15, v17, *(unsigned __int8 *)(a1 + 168));
  v61 = *(_DWORD *)(a1 + 80) | *(unsigned __int16 *)(a1 + 84);
  if ( v61 )
    LOBYTE(v61) = *(_BYTE *)(a2 + 32);
  conc_ext_flags = policy_mgr_get_conc_ext_flags(a1, v61 & 1);
  if ( (*(_BYTE *)(a1 + 60) & 2) == 0
    && (policy_mgr_is_concurrency_allowed(v15, v60, v12, 3, conc_ext_flags, 0) & 1) == 0 )
  {
    v45 = LOBYTE(v96[0]);
    v47 = BYTE1(v96[0]);
    v46 = "%s: Concurrency not allowed for this channel freq %d bssid %02x:%02x:%02x:**:**:%02x, selecting next";
    goto LABEL_47;
  }
  if ( (policy_mgr_is_hwmode_set_for_given_chnl(v15, v12) & 1) == 0 )
  {
    v45 = LOBYTE(v96[0]);
    v47 = BYTE1(v96[0]);
    v46 = "%s: HW mode isn't properly set, freq %d BSSID %02x:%02x:%02x:**:**:%02x";
LABEL_47:
    v48 = BYTE2(v96[0]);
    v49 = BYTE1(v96[1]);
    v50 = 4;
    v44 = v12;
    goto LABEL_48;
  }
  if ( (policy_mgr_concurrent_open_sessions_running(v15) & 1) != 0
    && (if_mgr_is_beacon_interval_valid(v14, *(_BYTE *)(a1 + 168), a2 + 8) & 1) == 0 )
  {
    conc_freq = wlan_get_conc_freq();
    qdf_trace_msg(
      0x78u,
      8u,
      "%s: csr Conc Channel freq: %d",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "if_mgr_validate_candidate",
      conc_freq);
    if ( conc_freq )
    {
      if ( conc_freq != v12
        && ((policy_mgr_is_hw_sbs_capable(v15) & 1) == 0 || (policy_mgr_are_sbs_chan(v15, conc_freq, v12) & 1) == 0)
        && ((policy_mgr_is_hw_dbs_capable(v15) & 1) == 0 || (wlan_reg_is_same_band_freqs(conc_freq, v12) & 1) != 0) )
      {
        goto LABEL_50;
      }
      qdf_trace_msg(
        0x78u,
        8u,
        "%s: Conc chnl freq match: %d",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "if_mgr_validate_candidate",
        conc_freq);
    }
  }
  if ( v17 != 2
    || (wlan_reg_is_dfs_for_freq(v14, v12, v63, v64, v65, v66, v67, v68, v69, v70) & 1) == 0
    || (wlan_p2p_is_vdev_wfd_r2_mode(a1) & 1) == 0 )
  {
    goto LABEL_42;
  }
  v80 = *(_QWORD *)(a2 + 24);
  v95[0] = 0;
  v81 = *(unsigned __int16 *)(v80 + 1888);
  v82 = *(_QWORD *)(v80 + 1896);
  v94[0] = 0;
  wlan_p2p_extract_ap_assist_dfs_params(a1, v82 + 36, (unsigned int)(v81 - 36), 1, v12, 1);
  wlan_p2p_get_ap_assist_dfs_params(a1, v95, v94, 0, 0, 0, 0);
  result = 0;
  if ( (v95[0] & 1) == 0 )
  {
    if ( (wlan_p2p_fw_support_ap_assist_dfs_group(v15) & 1) != 0 )
    {
      if ( (v94[0] & 1) != 0 )
      {
LABEL_42:
        result = 0;
        goto LABEL_51;
      }
      v91 = "%s: Invalid AP assist params";
    }
    else
    {
      v91 = "%s: FW doesn't support assisted AP for P2P";
    }
    qdf_trace_msg(0x78u, 8u, v91, v83, v84, v85, v86, v87, v88, v89, v90, "if_mgr_validate_candidate");
    goto LABEL_50;
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
