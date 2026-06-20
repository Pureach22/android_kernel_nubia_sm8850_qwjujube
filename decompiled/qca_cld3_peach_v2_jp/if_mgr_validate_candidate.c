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
  __int64 v13; // x23
  __int64 v14; // x21
  unsigned int v15; // w24
  __int16 v16; // w9
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x4
  __int64 v26; // x5
  const char *v27; // x2
  __int64 v28; // x6
  __int64 v29; // x7
  unsigned int v30; // w8
  unsigned int v31; // w1
  __int64 result; // x0
  unsigned int v33; // w0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int conc_freq; // w25
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x8
  int v52; // w9
  __int64 v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w20
  unsigned int v63; // w21
  unsigned int v64; // w24
  unsigned int v65; // w22
  __int64 v66; // x8
  const char *v67; // x2
  unsigned int v68; // [xsp+0h] [xbp-30h]
  int v69; // [xsp+8h] [xbp-28h]
  char v70[4]; // [xsp+18h] [xbp-18h] BYREF
  char v71[4]; // [xsp+1Ch] [xbp-14h] BYREF
  int v72; // [xsp+20h] [xbp-10h] BYREF
  __int16 v73; // [xsp+24h] [xbp-Ch]
  unsigned __int8 v74; // [xsp+26h] [xbp-Ah]
  __int64 v75; // [xsp+28h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_DWORD *)(a2 + 16);
  if ( !cm_get_cm_ctx_fl(a1, (__int64)"if_mgr_validate_candidate", 0x39Bu, a3, a4, a5, a6, a7, a8, a9, a10)
    || (v13 = *(_QWORD *)(a1 + 152)) == 0
    || (v14 = *(_QWORD *)(v13 + 80)) == 0 )
  {
    result = 16;
    goto LABEL_30;
  }
  v15 = *(_DWORD *)(a1 + 16);
  if ( !v15 && (policy_mgr_is_sta_chan_valid_for_connect_and_roam(*(_QWORD *)(a1 + 152), v12) & 1) == 0 )
  {
    v62 = *(unsigned __int8 *)(a2 + 8);
    v63 = *(unsigned __int8 *)(a2 + 9);
    v64 = *(unsigned __int8 *)(a2 + 10);
    v65 = *(unsigned __int8 *)(a2 + 13);
    v66 = wlan_reg_is_freq_indoor() & 1;
    v27 = "%s: STA connection not allowed on bssid: %02x:%02x:%02x:**:**:%02x with freq: %d (6Ghz or indoor(%d)), as not "
          "valid for connection";
    v31 = 8;
    v25 = v62;
    v26 = v63;
    v28 = v64;
    v29 = v65;
    v69 = v66;
    v68 = v12;
LABEL_28:
    qdf_trace_msg(
      0x78u,
      v31,
      v27,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "if_mgr_validate_candidate",
      v25,
      v26,
      v28,
      v29,
      v68,
      v69);
LABEL_29:
    result = 4;
    goto LABEL_30;
  }
  v16 = *(_WORD *)(a2 + 12);
  v72 = *(_DWORD *)(a2 + 8);
  v73 = v16;
  v74 = -1;
  wlan_objmgr_pdev_iterate_obj_list(
    v13,
    2,
    (void (__fastcall *)(__int64, __int64, __int64))if_mgr_get_vdev_id_from_bssid,
    (__int64)&v72,
    0,
    0x4Eu);
  v25 = v74;
  if ( v74 != 255 )
  {
    v26 = (unsigned __int8)v72;
    v27 = "%s: vdev_id %d already connected to %02x:%02x:%02x:**:**:%02x. select next bss for vdev_id %d";
    v28 = BYTE1(v72);
    v29 = BYTE2(v72);
    v30 = HIBYTE(v73);
    v69 = *(unsigned __int8 *)(a1 + 104);
    v31 = 4;
LABEL_27:
    v68 = v30;
    goto LABEL_28;
  }
  v33 = policy_mgr_qdf_opmode_to_pm_con_mode(v14, v15, *(unsigned __int8 *)(a1 + 104));
  if ( (policy_mgr_is_concurrency_allowed(v14, v33, v12, 3, 0, 0) & 1) == 0 )
  {
    v26 = (unsigned __int8)v72;
    v28 = BYTE1(v72);
    v27 = "%s: Concurrency not allowed for this channel freq %d bssid %02x:%02x:%02x:**:**:%02x, selecting next";
LABEL_26:
    v29 = BYTE2(v72);
    v30 = HIBYTE(v73);
    v31 = 4;
    v25 = v12;
    goto LABEL_27;
  }
  if ( (policy_mgr_is_hwmode_set_for_given_chnl(v14, v12) & 1) == 0 )
  {
    v26 = (unsigned __int8)v72;
    v28 = BYTE1(v72);
    v27 = "%s: HW mode isn't properly set, freq %d BSSID %02x:%02x:%02x:**:**:%02x";
    goto LABEL_26;
  }
  if ( (policy_mgr_concurrent_open_sessions_running(v14) & 1) != 0
    && (if_mgr_is_beacon_interval_valid(v13, *(_BYTE *)(a1 + 104), a2 + 8) & 1) == 0 )
  {
    conc_freq = wlan_get_conc_freq();
    qdf_trace_msg(
      0x78u,
      8u,
      "%s: csr Conc Channel freq: %d",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "if_mgr_validate_candidate",
      conc_freq);
    if ( conc_freq )
    {
      if ( conc_freq != v12
        && ((policy_mgr_is_hw_sbs_capable(v14) & 1) == 0 || (policy_mgr_are_sbs_chan(v14, conc_freq, v12) & 1) == 0)
        && ((policy_mgr_is_hw_dbs_capable(v14) & 1) == 0 || (wlan_reg_is_same_band_freqs(conc_freq, v12) & 1) != 0) )
      {
        goto LABEL_29;
      }
      qdf_trace_msg(
        0x78u,
        8u,
        "%s: Conc chnl freq match: %d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "if_mgr_validate_candidate",
        conc_freq);
    }
  }
  if ( v15 != 2
    || (wlan_reg_is_dfs_for_freq(v13, v12, v34, v35, v36, v37, v38, v39, v40, v41) & 1) == 0
    || (wlan_p2p_is_vdev_wfd_r2_mode(a1) & 1) == 0 )
  {
    goto LABEL_22;
  }
  v51 = *(_QWORD *)(a2 + 24);
  v71[0] = 0;
  v52 = *(unsigned __int16 *)(v51 + 1704);
  v53 = *(_QWORD *)(v51 + 1712);
  v70[0] = 0;
  wlan_p2p_extract_ap_assist_dfs_params(a1, v53 + 36, (unsigned int)(v52 - 36), 1, v12, 1);
  wlan_p2p_get_ap_assist_dfs_params(a1, v71, v70, 0, 0, 0, 0);
  result = 0;
  if ( (v71[0] & 1) == 0 )
  {
    if ( (wlan_p2p_fw_support_ap_assist_dfs_group(v14) & 1) != 0 )
    {
      if ( (v70[0] & 1) != 0 )
      {
LABEL_22:
        result = 0;
        goto LABEL_30;
      }
      v67 = "%s: Invalid AP assist params";
    }
    else
    {
      v67 = "%s: FW doesn't support assisted AP for P2P";
    }
    qdf_trace_msg(0x78u, 8u, v67, v54, v55, v56, v57, v58, v59, v60, v61, "if_mgr_validate_candidate");
    goto LABEL_29;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
