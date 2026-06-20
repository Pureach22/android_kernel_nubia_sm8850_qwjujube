__int64 __fastcall csr_roam_chk_lnk_set_ctx_rsp(
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
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x19
  unsigned __int8 *v23; // x26
  __int64 v24; // x0
  _QWORD *vdev_by_id_from_pdev; // x0
  __int64 v26; // x24
  bool is_open_mode; // w25
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x0
  char v38; // w8
  int *v39; // x22
  unsigned int v40; // w26
  unsigned int v41; // w27
  unsigned int v42; // w28
  int v43; // w19
  int v44; // w25
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x8
  __int64 v62; // x4
  unsigned int v63; // w22
  int v64; // w9
  __int64 v66; // x8
  _DWORD *v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  __int16 v70; // w9
  __int64 v71; // x8
  _DWORD *v72; // x8
  __int64 v73; // x0
  int v74; // [xsp+0h] [xbp-60h]
  __int64 v75; // [xsp+0h] [xbp-60h]
  int opmode_from_vdev_id; // [xsp+20h] [xbp-40h]
  unsigned __int8 *v77; // [xsp+28h] [xbp-38h]
  unsigned int v78; // [xsp+30h] [xbp-30h]
  unsigned int operation_chan_freq_vdev_id; // [xsp+34h] [xbp-2Ch]
  __int64 v80; // [xsp+38h] [xbp-28h]
  int v81; // [xsp+40h] [xbp-20h] BYREF
  __int16 v82; // [xsp+44h] [xbp-1Ch]
  _QWORD v83[3]; // [xsp+48h] [xbp-18h] BYREF

  v83[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v82 = 0;
  v81 = 0;
  if ( a2 )
  {
    result = _qdf_mem_malloc(0x180u, "csr_roam_chk_lnk_set_ctx_rsp", 3588);
    if ( result )
    {
      v21 = *(unsigned __int8 *)(a2 + 4);
      v22 = result;
      if ( (unsigned int)v21 > 5
        || (v23 = (unsigned __int8 *)(*(_QWORD *)(a1 + 17224) + 96LL * *(unsigned __int8 *)(a2 + 4))) == nullptr )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: session %d not found",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "csr_roam_chk_lnk_set_ctx_rsp",
          *(unsigned __int8 *)(a2 + 4));
LABEL_34:
        result = _qdf_mem_free(v22);
        goto LABEL_35;
      }
      v24 = *(_QWORD *)(a1 + 21560);
      memset(v83, 0, 13);
      vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v24, *v23, 0xBu);
      if ( vdev_by_id_from_pdev )
      {
        v26 = (__int64)vdev_by_id_from_pdev;
        is_open_mode = wlan_vdev_is_open_mode((__int64)vdev_by_id_from_pdev);
        wlan_objmgr_vdev_release_ref(v26, 0xBu, v28, v29, v30, v31, v32, v33, v34, v35, v36);
        if ( !is_open_mode )
        {
          qdf_mem_set(v83, 0xDu, 0);
          v37 = *(_QWORD *)(a1 + 21552);
          if ( (*(_BYTE *)(a2 + 12) & 1) != 0 )
            v38 = 13;
          else
            v38 = 11;
          LOBYTE(v83[0]) = v38;
          cm_diag_get_auth_enc_type_vdev_id(v37, (_BYTE *)v83 + 1, (_BYTE *)v83 + 2, (_BYTE *)v83 + 3, *v23);
          wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21560), *v23, (char *)v83 + 5);
          if ( *(_DWORD *)(a2 + 8) )
            BYTE4(v83[1]) = 1;
          host_diag_event_report_payload(1653, 13, v83);
        }
      }
      v77 = v23;
      v80 = v22;
      operation_chan_freq_vdev_id = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21560), v21);
      wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21560), v21, &v81);
      v39 = (int *)(a2 + 12);
      v40 = *(unsigned __int8 *)(a2 + 4);
      v41 = *(_DWORD *)(a2 + 8);
      v42 = *(unsigned __int8 *)(a2 + 13);
      v78 = *(unsigned __int8 *)(a2 + 12);
      v43 = *(unsigned __int8 *)(a2 + 17);
      v44 = *(unsigned __int8 *)(a1 + 21956);
      v74 = *(unsigned __int8 *)(a2 + 14);
      opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), v21);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: vdev %d, Status %d, peer_macaddr %02x:%02x:%02x:**:**:%02x obss offload %d freq %d opmode %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "csr_roam_chk_lnk_set_ctx_rsp",
        v40,
        v41,
        v78,
        v42,
        v74,
        v43,
        v44,
        operation_chan_freq_vdev_id,
        opmode_from_vdev_id);
      v61 = a1 + 4 * v21;
      if ( *(_DWORD *)(v61 + 17172) == 3 && *(_DWORD *)(v61 + 17196) == 5 )
      {
        csr_roam_substate_change(a1, 0, v21, v53, v54, v55, v56, v57, v58, v59, v60);
        cm_stop_wait_for_key_timer(*(_QWORD *)(a1 + 21552), (unsigned int)v21);
        cm_roam_start_init_on_connect(*(_QWORD *)(a1 + 21560), v21);
        policy_mgr_trigger_roam_for_sta_sap_mcc_non_dbs(*(_QWORD *)(a1 + 21552));
      }
      v62 = *(unsigned int *)(a2 + 8);
      v22 = v80;
      if ( (_DWORD)v62 )
      {
        LODWORD(v75) = *(unsigned __int8 *)(a2 + 17);
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: CSR: setkey command failed(err=%d) PeerMac %02x:%02x:%02x:**:**:%02x",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "csr_roam_chk_lnk_set_ctx_rsp",
          v62,
          *(unsigned __int8 *)(a2 + 12),
          *(unsigned __int8 *)(a2 + 13),
          *(unsigned __int8 *)(a2 + 14),
          v75);
        v63 = 1;
        if ( !a1 )
          goto LABEL_32;
      }
      else
      {
        v64 = *v39;
        *(_WORD *)(v80 + 27) = *(_WORD *)(a2 + 16);
        *(_DWORD *)(v80 + 23) = v64;
        if ( *v39 == -1 && *(__int16 *)(a2 + 16) == -1 )
        {
          if ( *(_BYTE *)(a1 + 21956) == 1
            && wlan_reg_is_24ghz_ch_freq(operation_chan_freq_vdev_id)
            && cm_is_vdevid_connected(*(_QWORD *)(a1 + 21560), v21) )
          {
            v69 = _qdf_mem_malloc(0xAu, "csr_roam_chk_lnk_set_ctx_rsp", 3639);
            if ( !v69 )
              goto LABEL_34;
            *(_DWORD *)v69 = 660602;
            v70 = v82;
            *(_DWORD *)(v69 + 4) = v81;
            *(_WORD *)(v69 + 8) = v70;
            umac_send_mb_message_to_mac(v69);
          }
          if ( a1 && (v71 = *(_QWORD *)(a1 + 17224)) != 0 && (*(_BYTE *)(v71 + 96LL * (unsigned int)v21 + 1) & 1) != 0 )
          {
            wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21560), v21);
            v72 = *(_DWORD **)(a1 + 21968);
            if ( v72 )
            {
              v73 = *(_QWORD *)(a1 + 21552);
              if ( *(v72 - 1) != 1469140685 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64))v72)(v73, (unsigned int)v21, v80, 17, 6);
            }
          }
          else
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Session ID: %d is not valid",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "csr_roam_call_callback",
              (unsigned int)v21);
          }
          sme_qos_csr_event_ind(a1, (unsigned int)v21, 10, 0);
          if ( v77[53] == 1 && (wlan_cm_get_ese_assoc(*(_QWORD *)(a1 + 21560), v21) & 1) != 0 )
          {
            csr_send_ese_adjacent_ap_rep_ind(a1, v77);
            v77[53] = 0;
          }
          goto LABEL_34;
        }
        v63 = 0;
        if ( !a1 )
          goto LABEL_32;
      }
      v66 = *(_QWORD *)(a1 + 17224);
      if ( v66 && (*(_BYTE *)(v66 + 96LL * (unsigned int)v21 + 1) & 1) != 0 )
      {
        wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21560), v21);
        v67 = *(_DWORD **)(a1 + 21968);
        if ( v67 )
        {
          v68 = *(_QWORD *)(a1 + 21552);
          if ( *(v67 - 1) != 1469140685 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))v67)(v68, (unsigned int)v21, v80, 17, v63);
        }
        goto LABEL_33;
      }
LABEL_32:
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: Session ID: %d is not valid",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "csr_roam_call_callback",
        (unsigned int)v21);
LABEL_33:
      sme_qos_csr_event_ind(a1, (unsigned int)v21, 10, 0);
      goto LABEL_34;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: set key response is NULL",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "csr_roam_chk_lnk_set_ctx_rsp");
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
