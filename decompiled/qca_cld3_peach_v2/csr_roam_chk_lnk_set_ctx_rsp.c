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
  char *v23; // x22
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
  __int64 v39; // x25
  int *v40; // x24
  unsigned int v41; // w26
  unsigned int v42; // w27
  int v43; // w22
  int v44; // w19
  int v45; // w28
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x8
  __int64 v63; // x0
  __int64 v64; // x25
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 assoc_link_vdev; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned __int8 v82; // w1
  __int64 v83; // x0
  const char *v84; // x2
  const char *v85; // x3
  unsigned int *v86; // x8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // x4
  unsigned int v96; // w22
  int v97; // w9
  __int64 v99; // x8
  _DWORD *v100; // x8
  __int64 v101; // x0
  __int64 v102; // x0
  __int16 v103; // w9
  __int64 v104; // x8
  _DWORD *v105; // x8
  __int64 v106; // x0
  unsigned int *v107; // x8
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // [xsp+0h] [xbp-60h]
  int v117; // [xsp+8h] [xbp-58h]
  int opmode_from_vdev_id; // [xsp+20h] [xbp-40h]
  char *v119; // [xsp+28h] [xbp-38h]
  unsigned int v120; // [xsp+34h] [xbp-2Ch]
  unsigned int v121; // [xsp+38h] [xbp-28h]
  unsigned int operation_chan_freq_vdev_id; // [xsp+3Ch] [xbp-24h]
  int v123; // [xsp+40h] [xbp-20h] BYREF
  __int16 v124; // [xsp+44h] [xbp-1Ch]
  _QWORD v125[3]; // [xsp+48h] [xbp-18h] BYREF

  v125[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v124 = 0;
  v123 = 0;
  if ( a2 )
  {
    result = _qdf_mem_malloc(0x180u, "csr_roam_chk_lnk_set_ctx_rsp", 3588);
    if ( result )
    {
      v21 = *(unsigned __int8 *)(a2 + 4);
      v22 = result;
      if ( (unsigned int)v21 <= 5
        && (v23 = (char *)(*(_QWORD *)(a1 + 17296) + 96LL * *(unsigned __int8 *)(a2 + 4))) != nullptr )
      {
        v24 = *(_QWORD *)(a1 + 21632);
        memset(v125, 0, 13);
        vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(v24, *v23, 0xBu);
        if ( vdev_by_id_from_pdev )
        {
          v26 = (__int64)vdev_by_id_from_pdev;
          is_open_mode = wlan_vdev_is_open_mode((__int64)vdev_by_id_from_pdev);
          wlan_objmgr_vdev_release_ref(v26, 0xBu, v28, v29, v30, v31, v32, v33, v34, v35, v36);
          if ( !is_open_mode )
          {
            qdf_mem_set(v125, 0xDu, 0);
            v37 = *(_QWORD *)(a1 + 21624);
            if ( (*(_BYTE *)(a2 + 12) & 1) != 0 )
              v38 = 13;
            else
              v38 = 11;
            LOBYTE(v125[0]) = v38;
            cm_diag_get_auth_enc_type_vdev_id(
              v37,
              (_BYTE *)v125 + 1,
              (_BYTE *)v125 + 2,
              (_BYTE *)v125 + 3,
              (unsigned __int8)*v23);
            wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21632), *v23, (char *)v125 + 5);
            if ( *(_DWORD *)(a2 + 8) )
              BYTE4(v125[1]) = 1;
            host_diag_event_report_payload(1653, 13, v125);
          }
        }
        v119 = v23;
        operation_chan_freq_vdev_id = wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), v21);
        wlan_mlme_get_bssid_vdev_id(*(_QWORD *)(a1 + 21632), v21, &v123);
        v39 = v22;
        v40 = (int *)(a2 + 12);
        v41 = *(unsigned __int8 *)(a2 + 4);
        v42 = *(_DWORD *)(a2 + 8);
        v43 = *(unsigned __int8 *)(a2 + 14);
        v120 = *(unsigned __int8 *)(a2 + 13);
        v121 = *(unsigned __int8 *)(a2 + 12);
        v44 = *(unsigned __int8 *)(a2 + 17);
        v45 = *(unsigned __int8 *)(a1 + 22028);
        opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), v21);
        v117 = v44;
        v22 = v39;
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: vdev %d, Status %d, peer_macaddr %02x:%02x:%02x:**:**:%02x obss offload %d freq %d opmode %d",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "csr_roam_chk_lnk_set_ctx_rsp",
          v41,
          v42,
          v121,
          v120,
          v43,
          v117,
          v45,
          operation_chan_freq_vdev_id,
          opmode_from_vdev_id);
        v62 = a1 + 4 * v21;
        if ( *(_DWORD *)(v62 + 17244) != 3 || *(_DWORD *)(v62 + 17268) != 5 )
        {
LABEL_27:
          v95 = *(unsigned int *)(a2 + 8);
          if ( (_DWORD)v95 )
          {
            LODWORD(v116) = *(unsigned __int8 *)(a2 + 17);
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: CSR: setkey command failed(err=%d) PeerMac %02x:%02x:%02x:**:**:%02x",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "csr_roam_chk_lnk_set_ctx_rsp",
              v95,
              *(unsigned __int8 *)(a2 + 12),
              *(unsigned __int8 *)(a2 + 13),
              *(unsigned __int8 *)(a2 + 14),
              v116);
            v96 = 1;
            if ( !a1 )
              goto LABEL_41;
          }
          else
          {
            v97 = *v40;
            *(_WORD *)(v22 + 27) = *(_WORD *)(a2 + 16);
            *(_DWORD *)(v22 + 23) = v97;
            if ( *v40 == -1 && *(__int16 *)(a2 + 16) == -1 )
            {
              if ( *(_BYTE *)(a1 + 22028) == 1
                && wlan_reg_is_24ghz_ch_freq(operation_chan_freq_vdev_id)
                && cm_is_vdevid_connected(*(_QWORD *)(a1 + 21632), v21) )
              {
                v102 = _qdf_mem_malloc(0xAu, "csr_roam_chk_lnk_set_ctx_rsp", 3639);
                if ( !v102 )
                  goto LABEL_43;
                *(_DWORD *)v102 = 660602;
                v103 = v124;
                *(_DWORD *)(v102 + 4) = v123;
                *(_WORD *)(v102 + 8) = v103;
                umac_send_mb_message_to_mac(v102);
              }
              if ( a1
                && (v104 = *(_QWORD *)(a1 + 17296)) != 0
                && (*(_BYTE *)(v104 + 96LL * (unsigned int)v21 + 1) & 1) != 0 )
              {
                wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), v21);
                v105 = *(_DWORD **)(a1 + 22040);
                if ( v105 )
                {
                  v106 = *(_QWORD *)(a1 + 21624);
                  if ( *(v105 - 1) != 1469140685 )
                    __break(0x8228u);
                  ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64))v105)(
                    v106,
                    (unsigned int)v21,
                    v22,
                    17,
                    6);
                }
              }
              else
              {
                qdf_trace_msg(
                  0x34u,
                  2u,
                  "%s: Session ID: %d is not valid",
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  "csr_roam_call_callback",
                  (unsigned int)v21);
              }
              sme_qos_csr_event_ind(a1, (unsigned int)v21, 10, 0);
              if ( v119[53] == 1 && (wlan_cm_get_ese_assoc(*(_QWORD *)(a1 + 21632), v21) & 1) != 0 )
              {
                csr_send_ese_adjacent_ap_rep_ind(a1, v119);
                v119[53] = 0;
              }
              goto LABEL_43;
            }
            v96 = 0;
            if ( !a1 )
              goto LABEL_41;
          }
          v99 = *(_QWORD *)(a1 + 17296);
          if ( v99 && (*(_BYTE *)(v99 + 96LL * (unsigned int)v21 + 1) & 1) != 0 )
          {
            wlan_get_operation_chan_freq_vdev_id(*(_QWORD *)(a1 + 21632), v21);
            v100 = *(_DWORD **)(a1 + 22040);
            if ( v100 )
            {
              v101 = *(_QWORD *)(a1 + 21624);
              if ( *(v100 - 1) != 1469140685 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))v100)(
                v101,
                (unsigned int)v21,
                v22,
                17,
                v96);
            }
            goto LABEL_42;
          }
LABEL_41:
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Session ID: %d is not valid",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "csr_roam_call_callback",
            (unsigned int)v21);
LABEL_42:
          sme_qos_csr_event_ind(a1, (unsigned int)v21, 10, 0);
          goto LABEL_43;
        }
        csr_roam_substate_change(a1, 0, v21, v54, v55, v56, v57, v58, v59, v60, v61);
        cm_stop_wait_for_key_timer(*(_QWORD *)(a1 + 21624), (unsigned int)v21);
        v63 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                *(_QWORD *)(a1 + 21624),
                (unsigned int)v21,
                67);
        if ( v63 )
        {
          v64 = v63;
          if ( (wlan_vdev_mlme_is_mlo_vdev(v63, v13, v14, v15, v16, v17, v18, v19, v20) & 1) != 0
            && (mlo_check_if_all_links_up(v64) & 1) != 0 )
          {
            assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(v64);
            if ( !assoc_link_vdev )
            {
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: Assoc vdev is null",
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                v81,
                "csr_roam_send_rso_enable");
              wlan_objmgr_vdev_release_ref(v64, 0x43u, v107, v108, v109, v110, v111, v112, v113, v114, v115);
              goto LABEL_43;
            }
            v82 = *(_BYTE *)(assoc_link_vdev + 168);
            v83 = *(_QWORD *)(a1 + 21632);
          }
          else
          {
            if ( (wlan_vdev_mlme_is_mlo_vdev(v64, v65, v66, v67, v68, v69, v70, v71, v72) & 1) != 0 )
            {
LABEL_26:
              wlan_objmgr_vdev_release_ref(v64, 0x43u, v86, v87, v88, v89, v90, v91, v92, v93, v94);
              policy_mgr_trigger_roam_for_sta_sap_mcc_non_dbs(*(_QWORD *)(a1 + 21624));
              goto LABEL_27;
            }
            v83 = *(_QWORD *)(a1 + 21632);
            v82 = v21;
          }
          cm_roam_start_init_on_connect(v83, v82);
          goto LABEL_26;
        }
        v84 = "%s: vdev object is NULL for vdev %d";
        v85 = "csr_roam_send_rso_enable";
      }
      else
      {
        v84 = "%s: session %d not found";
        v85 = "csr_roam_chk_lnk_set_ctx_rsp";
      }
      qdf_trace_msg(0x34u, 2u, v84, v13, v14, v15, v16, v17, v18, v19, v20, v85, (unsigned int)v21);
LABEL_43:
      result = _qdf_mem_free(v22);
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
  _ReadStatusReg(SP_EL0);
  return result;
}
