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
  __int64 v29; // x1
  __int64 v30; // x2
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x0
  char diag_tx_status; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w8
  __int64 peer_disconnect_ies; // x0
  int v45; // w8
  __int64 result; // x0
  __int64 v47; // x0
  unsigned int v48; // w21
  __int64 v49; // x20
  char is_log_record_present_for_bssid; // w23
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 ext_hdl; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x22
  __int64 v69; // x27
  unsigned int **v70; // x28
  unsigned int *v71; // x8
  __int64 v72; // x9
  unsigned int **v74; // x26
  __int64 v75; // x6
  __int64 v76; // x20
  __int64 v77; // x22
  bool is_vdev_connecting; // [xsp+Ch] [xbp-164h]
  __int64 v79; // [xsp+10h] [xbp-160h]
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
    goto LABEL_13;
  }
  v28 = (unsigned int *)*(unsigned int *)(v19 + 16);
  if ( !(_DWORD)v28 )
  {
    v79 = v19;
    is_vdev_connecting = wlan_cm_is_vdev_connecting(v19, v20, v21, v22, v23, v24, v25, v26, v27);
    qdf_mem_set(s, 0x143u, 0);
    s[1] = qdf_get_time_of_the_day_us();
    v33 = ktime_get(s[1], v29, v30, v31, v32);
    HIWORD(s[0]) = (unsigned __int8)a3;
    LOWORD(s[5]) = (unsigned __int8)a11;
    s[3] = v33 / 1000;
    qdf_mem_copy(s, (const void *)(a2 + 16), 6u);
    LOBYTE(s[7]) = a5;
    LOBYTE(s[4]) = 5;
    diag_tx_status = wlan_get_diag_tx_status(a5);
    v43 = *(unsigned __int16 *)(a2 + 22);
    BYTE4(s[4]) = a4;
    BYTE1(s[4]) = a7;
    BYTE5(s[4]) = diag_tx_status;
    HIDWORD(s[6]) = a6;
    LODWORD(s[6]) = v43 >> 4;
    BYTE2(s[4]) = a8;
    BYTE3(s[4]) = a9;
    WORD1(s[5]) = a10;
    if ( (a11 & 0xFFFFFFFD) == 8 )
    {
      peer_disconnect_ies = mlme_get_peer_disconnect_ies(v79, v35, v36, v37, v38, v39, v40, v41, v42);
      if ( peer_disconnect_ies )
      {
        v45 = *(_DWORD *)peer_disconnect_ies;
        HIBYTE(s[7]) = *(_DWORD *)peer_disconnect_ies;
        qdf_mem_copy(&s[8], *(const void **)(peer_disconnect_ies + 8), (unsigned __int8)v45);
      }
    }
    if ( (s[5] & 0xFFFC) == 8 )
      BYTE6(s[4]) = a4;
    HIBYTE(s[4]) &= ~1u;
    if ( !is_vdev_connecting && a7 == 3 && (a11 & 0xFFFFFFFE) == 2 && (*(_DWORD *)(a1 + 24) & 8) != 0 )
    {
      v47 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 67);
      if ( !v47 )
      {
        v76 = jiffies;
        v19 = v79;
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
          v19 = v79;
          wlan_cache_connectivity_log___last_ticks = v76;
        }
        goto LABEL_11;
      }
      v48 = *(unsigned __int8 *)(v47 + 104);
      v49 = v47;
      is_log_record_present_for_bssid = wlan_is_log_record_present_for_bssid(a1, (unsigned int *)s, v48);
      ext_hdl = wlan_vdev_mlme_get_ext_hdl(v49, v51, v52, v53, v54, v55, v56, v57, v58);
      if ( ext_hdl )
      {
        v68 = 0;
        v69 = ext_hdl + 336;
        v70 = (unsigned int **)(ext_hdl + 2621);
        while ( 1 )
        {
          v71 = (unsigned int *)((char *)v70 - 2261);
          v72 = *(__int64 *)((char *)v70 - 2261);
          if ( (is_log_record_present_for_bssid & 1) != 0 )
          {
            if ( !v72 )
              goto LABEL_21;
            if ( LODWORD(s[0]) != *(_DWORD *)((char *)v70 - 2285)
              || WORD2(s[0]) != *(unsigned __int16 *)((char *)v70 - 2281) )
            {
              goto LABEL_21;
            }
            if ( !*(_QWORD *)v71 )
            {
              v74 = (unsigned int **)(v69 + 2584 * v68);
              v75 = 0;
              goto LABEL_45;
            }
            if ( !*(unsigned int **)((char *)v70 - 1938) )
            {
              v75 = 1;
              v74 = (unsigned int **)(v69 + 2584 * v68 + 323);
              goto LABEL_45;
            }
            if ( !*(unsigned int **)((char *)v70 - 1615) )
            {
              v75 = 2;
              v74 = (unsigned int **)(v69 + 2584 * v68 + 646);
              goto LABEL_45;
            }
            if ( !*(unsigned int **)((char *)v70 - 1292) )
            {
              v75 = 3;
              v74 = (unsigned int **)(v69 + 2584 * v68 + 969);
              goto LABEL_45;
            }
            if ( !*(unsigned int **)((char *)v70 - 969) )
            {
              v75 = 4;
              v74 = (unsigned int **)(v69 + 2584 * v68 + 1292);
              goto LABEL_45;
            }
            if ( !*(unsigned int **)((char *)v70 - 646) )
            {
              v75 = 5;
              v74 = (unsigned int **)(v69 + 2584 * v68 + 1615);
              goto LABEL_45;
            }
            if ( !*(unsigned int **)((char *)v70 - 323) )
            {
              v75 = 6;
              v74 = (unsigned int **)(v69 + 2584 * v68 + 1938);
              goto LABEL_45;
            }
            v74 = v70 - 3;
            v71 = *v70;
            if ( !*v70 )
            {
              v75 = 7;
LABEL_45:
              qdf_trace_msg(
                0x38u,
                8u,
                "%s: vdev:%d added at [i][j]:[%d][%d]",
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                "wlan_add_sae_log_record_to_available_slot",
                v48,
                (unsigned int)v68,
                v75);
              memcpy(v74, s, 0x143u);
            }
          }
          else if ( !v72 )
          {
            qdf_trace_msg(
              0x38u,
              8u,
              "%s: vdev:%d added entry at [i][j]:[%d][%d]",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "wlan_add_sae_log_record_to_available_slot",
              v48,
              (unsigned int)v68,
              0);
            memcpy((char *)v70 - 2285, s, 0x143u);
            goto LABEL_51;
          }
LABEL_21:
          ++v68;
          v70 += 323;
          if ( v68 == 9 )
            goto LABEL_51;
        }
      }
      v77 = jiffies;
      v71 = (unsigned int *)(wlan_add_sae_log_record_to_available_slot___last_ticks - jiffies);
      if ( wlan_add_sae_log_record_to_available_slot___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x1Fu,
          2u,
          "%s: vdev:%d legacy private object is NULL",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "wlan_add_sae_log_record_to_available_slot",
          v48);
        wlan_add_sae_log_record_to_available_slot___last_ticks = v77;
      }
LABEL_51:
      wlan_objmgr_vdev_release_ref(v49, 0x43u, v71, v60, v61, v62, v63, v64, v65, v66, v67);
    }
    else
    {
      host_diag_event_report_payload(3355, 323, s);
    }
    v19 = v79;
  }
LABEL_11:
  result = wlan_objmgr_vdev_release_ref(v19, 0x43u, v28, v20, v21, v22, v23, v24, v25, v26, v27);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
