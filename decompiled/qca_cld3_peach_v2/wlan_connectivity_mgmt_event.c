__int64 __fastcall wlan_connectivity_mgmt_event(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        char a4,
        int a5,
        char a6,
        char a7,
        char a8,
        char a9,
        __int16 a10,
        int a11)
{
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int *v28; // x8
  __int64 v29; // x19
  __int64 result; // x0
  bool is_vdev_connecting; // w20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x0
  char diag_tx_status; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w8
  __int64 peer_disconnect_ies; // x0
  int v60; // w8
  const char *v61; // x6
  __int64 v62; // x0
  unsigned int v63; // w21
  __int64 v64; // x20
  char is_log_record_present_for_bssid; // w23
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 ext_hdl; // x0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x22
  __int64 v84; // x27
  unsigned int **v85; // x28
  unsigned int *v86; // x8
  __int64 v87; // x9
  unsigned int **v89; // x26
  __int64 v90; // x6
  __int64 v91; // x22
  __int64 v92; // x23
  char v93; // [xsp+18h] [xbp-158h]
  _QWORD s[42]; // [xsp+1Dh] [xbp-153h] BYREF

  *(_QWORD *)((char *)&s[40] + 3) = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x143u);
  v19 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 67);
  if ( !v19 )
  {
    result = qdf_trace_msg(
               0x38u,
               8u,
               "%s: Unable to find vdev:%d",
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               "wlan_connectivity_mgmt_event",
               (unsigned __int8)a3);
    goto LABEL_5;
  }
  v28 = (unsigned int *)*(unsigned int *)(v19 + 16);
  v29 = v19;
  v93 = a7;
  if ( !(_DWORD)v28 )
  {
    is_vdev_connecting = wlan_cm_is_vdev_connecting(v19, v20, v21, v22, v23, v24, v25, v26, v27);
    if ( (wlan_vdev_mlme_is_mlo_vdev(v29, v32, v33, v34, v35, v36, v37, v38, v39) & 1) != 0 )
    {
      if ( (*(_BYTE *)(v29 + 67) & 2) != 0 )
      {
        if ( (*(_BYTE *)(v29 + 60) & 2) != 0 )
          v61 = "link_vdev";
        else
          v61 = "link switch in prog";
      }
      else
      {
        if ( !is_vdev_connecting || (*(_BYTE *)(v29 + 60) & 2) == 0 )
          goto LABEL_10;
        v61 = "link_vdev";
      }
      qdf_trace_msg(
        0x38u,
        8u,
        "%s: vdev:%d is_connection:%d | %s skip mgmt event",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "wlan_connectivity_mgmt_event",
        (unsigned __int8)a3,
        is_vdev_connecting,
        v61);
      goto LABEL_3;
    }
LABEL_10:
    qdf_mem_set(s, 0x143u, 0);
    s[1] = qdf_get_time_of_the_day_us();
    v48 = ktime_get(s[1]);
    HIWORD(s[0]) = (unsigned __int8)a3;
    LOWORD(s[5]) = (unsigned __int8)a11;
    s[3] = v48 / 1000;
    qdf_mem_copy(s, (const void *)(a2 + 16), 6u);
    if ( is_vdev_connecting && (unsigned int)wlan_populate_mlo_mgmt_event_param(v29, s, a11) )
      goto LABEL_3;
    LOBYTE(s[4]) = 5;
    LOBYTE(s[7]) = a5;
    diag_tx_status = wlan_get_diag_tx_status(a5);
    v58 = *(unsigned __int16 *)(a2 + 22);
    BYTE4(s[4]) = a4;
    HIDWORD(s[6]) = a6;
    BYTE5(s[4]) = diag_tx_status;
    LODWORD(s[6]) = v58 >> 4;
    BYTE1(s[4]) = v93;
    BYTE2(s[4]) = a8;
    BYTE3(s[4]) = a9;
    WORD1(s[5]) = a10;
    if ( (a11 & 0xFFFFFFFD) == 8 )
    {
      peer_disconnect_ies = mlme_get_peer_disconnect_ies(v29, v50, v51, v52, v53, v54, v55, v56, v57);
      if ( peer_disconnect_ies )
      {
        v60 = *(_DWORD *)peer_disconnect_ies;
        HIBYTE(s[7]) = *(_DWORD *)peer_disconnect_ies;
        qdf_mem_copy(&s[8], *(const void **)(peer_disconnect_ies + 8), (unsigned __int8)v60);
      }
    }
    if ( (s[5] & 0xFFFC) == 8 )
      BYTE6(s[4]) = a4;
    HIBYTE(s[4]) &= ~1u;
    if ( is_vdev_connecting || v93 != 3 || (a11 & 0xFFFFFFFE) != 2 || (*(_DWORD *)(a1 + 24) & 8) == 0 )
    {
      host_diag_event_report_payload(3355, 323, s);
      if ( (a11 & 0xFFFFFFFD) == 5 )
        wlan_connectivity_mlo_setup_event(v29, 0, v20, v21, v22, v23, v24, v25, v26, v27);
      goto LABEL_3;
    }
    v62 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 67);
    if ( !v62 )
    {
      v91 = jiffies;
      v28 = (unsigned int *)(wlan_cache_connectivity_log___last_ticks - jiffies);
      if ( wlan_cache_connectivity_log___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x1Fu,
          2u,
          "%s: Invalid vdev:%d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "wlan_cache_connectivity_log",
          (unsigned __int8)a3);
        wlan_cache_connectivity_log___last_ticks = v91;
      }
      goto LABEL_3;
    }
    v63 = *(unsigned __int8 *)(v62 + 168);
    v64 = v62;
    is_log_record_present_for_bssid = wlan_is_log_record_present_for_bssid(a1, (unsigned int *)s, v63);
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v64, v66, v67, v68, v69, v70, v71, v72, v73);
    if ( !ext_hdl )
    {
      v92 = jiffies;
      v86 = (unsigned int *)(wlan_add_sae_log_record_to_available_slot___last_ticks - jiffies);
      if ( wlan_add_sae_log_record_to_available_slot___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x1Fu,
          2u,
          "%s: vdev:%d legacy private object is NULL",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "wlan_add_sae_log_record_to_available_slot",
          v63);
        wlan_add_sae_log_record_to_available_slot___last_ticks = v92;
      }
LABEL_62:
      wlan_objmgr_vdev_release_ref(v64, 0x43u, v86, v75, v76, v77, v78, v79, v80, v81, v82);
      goto LABEL_3;
    }
    v83 = 0;
    v84 = ext_hdl + 336;
    v85 = (unsigned int **)(ext_hdl + 2621);
    while ( 1 )
    {
      v86 = (unsigned int *)((char *)v85 - 2261);
      v87 = *(__int64 *)((char *)v85 - 2261);
      if ( (is_log_record_present_for_bssid & 1) != 0 )
      {
        if ( !v87 )
          goto LABEL_31;
        if ( LODWORD(s[0]) != *(_DWORD *)((char *)v85 - 2285)
          || WORD2(s[0]) != *(unsigned __int16 *)((char *)v85 - 2281) )
        {
          goto LABEL_31;
        }
        if ( !*(_QWORD *)v86 )
        {
          v90 = 0;
          v89 = (unsigned int **)(v84 + 2584 * v83);
          goto LABEL_55;
        }
        if ( !*(unsigned int **)((char *)v85 - 1938) )
        {
          v90 = 1;
          v89 = (unsigned int **)(v84 + 2584 * v83 + 323);
          goto LABEL_55;
        }
        if ( !*(unsigned int **)((char *)v85 - 1615) )
        {
          v90 = 2;
          v89 = (unsigned int **)(v84 + 2584 * v83 + 646);
          goto LABEL_55;
        }
        if ( !*(unsigned int **)((char *)v85 - 1292) )
        {
          v90 = 3;
          v89 = (unsigned int **)(v84 + 2584 * v83 + 969);
          goto LABEL_55;
        }
        if ( !*(unsigned int **)((char *)v85 - 969) )
        {
          v90 = 4;
          v89 = (unsigned int **)(v84 + 2584 * v83 + 1292);
          goto LABEL_55;
        }
        if ( !*(unsigned int **)((char *)v85 - 646) )
        {
          v90 = 5;
          v89 = (unsigned int **)(v84 + 2584 * v83 + 1615);
          goto LABEL_55;
        }
        if ( !*(unsigned int **)((char *)v85 - 323) )
        {
          v90 = 6;
          v89 = (unsigned int **)(v84 + 2584 * v83 + 1938);
          goto LABEL_55;
        }
        v89 = v85 - 3;
        v86 = *v85;
        if ( !*v85 )
        {
          v90 = 7;
LABEL_55:
          qdf_trace_msg(
            0x38u,
            8u,
            "%s: vdev:%d added at [i][j]:[%d][%d]",
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            "wlan_add_sae_log_record_to_available_slot",
            v63,
            (unsigned int)v83,
            v90);
          memcpy(v89, s, 0x143u);
        }
      }
      else if ( !v87 )
      {
        qdf_trace_msg(
          0x38u,
          8u,
          "%s: vdev:%d added entry at [i][j]:[%d][%d]",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "wlan_add_sae_log_record_to_available_slot",
          v63,
          (unsigned int)v83,
          0);
        memcpy((char *)v85 - 2285, s, 0x143u);
        goto LABEL_62;
      }
LABEL_31:
      ++v83;
      v85 += 323;
      if ( v83 == 9 )
        goto LABEL_62;
    }
  }
LABEL_3:
  result = wlan_objmgr_vdev_release_ref(v29, 0x43u, v28, v20, v21, v22, v23, v24, v25, v26, v27);
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
