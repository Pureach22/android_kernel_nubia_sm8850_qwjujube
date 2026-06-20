__int64 __fastcall lim_handle_add_bss_rsp(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x21
  int v13; // w8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 session_by_vdev_id; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  __int64 v32; // x0
  __int64 cmpt_obj; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x22
  __int64 tx_ops; // x0
  __int64 v44; // x23
  void (__fastcall *v45)(__int64, __int64, __int64); // x8
  __int64 v46; // x0
  __int64 v47; // x1
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double (__fastcall *v56)(__int64, __int64, __int64); // x8
  __int64 v57; // x0
  __int64 v58; // x1
  __int64 concurrent_session; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 result; // x0
  __int64 v69; // x4
  const char *v70; // x2
  const char *v71; // x3
  int v72; // w8
  __int16 v73; // w4
  __int64 v74; // x1
  __int64 v75; // x0
  int v76; // w4
  __int64 v77; // x21
  int v78; // w8
  int v79; // w8
  char v80; // w23
  int v81; // w22
  int v82; // w9
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  int v91; // w8
  int v92; // w8
  char v93; // w9
  __int16 v94; // w2
  int param; // w0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // x4
  const char *v113; // x2
  char v114; // w22
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  __int64 v123; // x9
  char v124; // w8
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  __int64 v133; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v134[7]; // [xsp+8h] [xbp-38h] BYREF

  v134[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v133 = 0;
  if ( a2 )
  {
    v12 = a1 + 0x2000;
    *(_QWORD *)(a1 + 8888) = "lim_handle_add_bss_rsp";
    *(_BYTE *)(a1 + 8885) = 1;
    qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a3, a4, a5, a6, a7, a8, a9, a10, v133);
    v13 = *(unsigned __int8 *)(v12 + 693);
    memset(v134, 0, 48);
    if ( v13 )
    {
      if ( *(_WORD *)(v12 + 496) )
      {
        LOWORD(v134[0]) = 5119;
        if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v134) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to post lim msg:0x%x",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "lim_post_msg_to_process_deferred_queue",
            LOWORD(v134[0]));
      }
    }
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, *a2);
    if ( session_by_vdev_id )
    {
      v31 = session_by_vdev_id;
      if ( *(_DWORD *)(session_by_vdev_id + 88) == 1
        && (wlan_reg_is_ext_tpc_supported(*(_QWORD *)(a1 + 21552), v23, v24, v25, v26, v27, v28, v29, v30) & 1) != 0 )
      {
        v32 = *(_QWORD *)(v31 + 16);
        LODWORD(v134[0]) = 0;
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v32, v23, v24, v25, v26, v27, v28, v29, v30);
        if ( cmpt_obj )
        {
          v42 = cmpt_obj;
          tx_ops = wlan_reg_get_tx_ops(*(_QWORD *)(a1 + 21552), v34, v35, v36, v37, v38, v39, v40, v41);
          if ( tx_ops )
          {
            v44 = tx_ops;
            wlan_reg_get_cur_6g_ap_pwr_type(
              *(_QWORD *)(a1 + 21560),
              (unsigned int *)v134,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30);
            if ( !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(v31 + 284)) || LODWORD(v134[0]) != 3 )
              goto LABEL_18;
            lim_calculate_tpc(a1, v31, 1);
            v45 = *(void (__fastcall **)(__int64, __int64, __int64))(v44 + 144);
            if ( v45 )
            {
              v46 = *(_QWORD *)(a1 + 21552);
              v47 = *(unsigned __int8 *)(v31 + 10);
              if ( *((_DWORD *)v45 - 1) != 1094041931 )
                __break(0x8228u);
              v45(v46, v47, v42 + 528);
            }
            if ( !policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(v31 + 10)) )
            {
LABEL_18:
              lim_calculate_tpc(a1, v31, 0);
              v56 = *(double (__fastcall **)(__int64, __int64, __int64))(v44 + 144);
              if ( v56 )
              {
                v57 = *(_QWORD *)(a1 + 21552);
                v58 = *(unsigned __int8 *)(v31 + 10);
                if ( *((_DWORD *)v56 - 1) != 1094041931 )
                  __break(0x8228u);
                v48 = v56(v57, v58, v42 + 528);
              }
            }
            if ( (wlan_get_tpc_update_required_for_sta(*(_QWORD *)(v31 + 16), v48, v49, v50, v51, v52, v53, v54, v55) & 1) != 0 )
            {
              concurrent_session = lim_get_concurrent_session(
                                     a1,
                                     *(unsigned __int8 *)(v31 + 10),
                                     *(unsigned int *)(v31 + 7036));
              if ( concurrent_session )
              {
                lim_update_tx_power(a1, v31, concurrent_session, 0);
              }
              else
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: TPC update required is set, but concurrent session doesn't exist",
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  v67,
                  "lim_set_tpc_for_sap_go");
                wlan_set_tpc_update_required_for_sta(
                  *(_QWORD *)(v31 + 16),
                  0,
                  v125,
                  v126,
                  v127,
                  v128,
                  v129,
                  v130,
                  v131,
                  v132);
              }
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: vdev component object is NULL",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "lim_set_tpc_for_sap_go");
        }
      }
      v72 = *(_DWORD *)(v31 + 92);
      v73 = *(_WORD *)(v31 + 8);
      BYTE4(v133) = v73;
      if ( v72 == 4 )
      {
        lim_process_ndi_mlm_add_bss_rsp(a1, a2, v31);
        goto LABEL_74;
      }
      if ( *(_DWORD *)(v31 + 80) != 14 )
      {
        v79 = *(_DWORD *)(v31 + 72);
        if ( (v79 | 8) == 0x1B )
        {
          v80 = *(unsigned __int8 *)(v31 + 24) == *(unsigned __int8 *)(v31 + 182)
             && *(unsigned __int8 *)(v31 + 25) == *(unsigned __int8 *)(v31 + 183)
             && *(unsigned __int8 *)(v31 + 26) == *(unsigned __int8 *)(v31 + 184)
             && *(unsigned __int8 *)(v31 + 27) == *(unsigned __int8 *)(v31 + 185)
             && *(unsigned __int8 *)(v31 + 28) == *(unsigned __int8 *)(v31 + 186)
             && *(unsigned __int8 *)(v31 + 29) == *(unsigned __int8 *)(v31 + 187);
          v81 = 1015;
        }
        else
        {
          v80 = 0;
          v81 = 1010;
        }
        v82 = *((_DWORD *)a2 + 1);
        v134[0] = 0;
        if ( v82 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: SessionId: %d ADD_BSS failed!",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "lim_process_sta_mlm_add_bss_rsp");
          v91 = *(_DWORD *)(v31 + 72);
          WORD2(v134[0]) = 1;
          if ( v91 == 27 )
            v92 = 537;
          else
            v92 = 506;
          LODWORD(v134[0]) = v92;
          *(_BYTE *)(v31 + 8637) = 1;
        }
        else
        {
          if ( v79 == 27 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Mlm=%d %d",
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              "lim_process_sta_mlm_add_bss_rsp",
              27,
              19);
            goto LABEL_74;
          }
          *(_DWORD *)(v31 + 72) = 21;
          qdf_trace(53, 0, v73, 21);
          *(_WORD *)(v31 + 248) = 1;
          if ( dph_get_hash_entry(a1, 1u, v31 + 360) )
          {
            lim_set_active_edca_params(a1, v31 + 7096, v31);
            lim_send_edca_params(a1, v31 + 7136, *(unsigned __int8 *)(v31 + 10), 0);
            if ( !(unsigned int)lim_add_sta_self(a1, v80, v31) )
              goto LABEL_74;
            v112 = *(unsigned __int16 *)(v31 + 8);
            v113 = "%s: Session:%d could not Add SelfEntry for the station";
          }
          else
          {
            v112 = *(unsigned __int16 *)(v31 + 8);
            v113 = "%s: Session:%d Fail to add Self Entry for STA";
          }
          qdf_trace_msg(
            0x35u,
            2u,
            v113,
            v104,
            v105,
            v106,
            v107,
            v108,
            v109,
            v110,
            v111,
            "lim_process_sta_mlm_add_bss_rsp",
            v112);
          LODWORD(v134[0]) = 506;
        }
        v93 = *(_BYTE *)(v31 + 8);
        *(_DWORD *)(v31 + 72) = 1;
        BYTE6(v134[0]) = v93;
        lim_process_mlm_rsp_messages(a1, v81, (unsigned __int8 *)v134, v83, v84, v85, v86, v87, v88, v89, v90);
LABEL_74:
        result = _qdf_mem_free((__int64)a2);
        goto LABEL_75;
      }
      if ( *(_DWORD *)(v31 + 72) != 16 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: SessionId:%d Received  WMA_ADD_BSS_RSP in state %X",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "lim_handle_add_bss_rsp");
        LODWORD(v133) = 504;
        lim_send_start_bss_confirm(a1, &v133);
      }
      v74 = *a2;
      v134[0] = 0;
      v75 = pe_find_session_by_vdev_id(a1, v74);
      if ( v75 )
      {
        v76 = *((_DWORD *)a2 + 1);
        v77 = v75;
        BYTE4(v134[0]) = *(_BYTE *)(v75 + 8);
        if ( v76 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: WMA_ADD_BSS_REQ failed with status %d",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "lim_process_ap_mlm_add_bss_rsp");
          v78 = 532;
LABEL_73:
          LODWORD(v134[0]) = v78;
          lim_send_start_bss_confirm(a1, v134);
          goto LABEL_74;
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: WMA_ADD_BSS_RSP returned with QDF_STATUS_SUCCESS",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "lim_process_ap_mlm_add_bss_rsp");
        v94 = *(_WORD *)(v77 + 8);
        *(_DWORD *)(v77 + 72) = 4;
        *(_BYTE *)(v77 + 7281) = *((_DWORD *)a2 + 2);
        *(_BYTE *)(v77 + 7280) = a2[12];
        qdf_trace(53, 0, v94, 4);
        *(_DWORD *)(v77 + 88) = 1;
        lim_fill_dfs_p2p_group_params(v77);
        lim_disable_ht_he_dynamic_smps(v77, *(unsigned int *)(v77 + 284));
        sch_edca_profile_update(a1, v77, 0);
        lim_delete_pre_auth_list(a1);
        if ( *(_BYTE *)(v77 + 1620) )
        {
          param = wlan_crypto_get_param(*(_QWORD *)(v77 + 16), 7u);
          if ( !param || (param & 4) != 0 )
          {
            if ( *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 3207LL) >= 0x11u )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: WEP SAP Configuration",
                v96,
                v97,
                v98,
                v99,
                v100,
                v101,
                v102,
                v103,
                "lim_process_ap_mlm_add_bss_rsp");
              v114 = 1;
              *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3207LL) = 16;
LABEL_66:
              lim_init_peer_idxpool(a1, v77);
              if ( (unsigned int)tx_timer_activate((char *)(a1 + 1608)) )
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: tx_timer_activate failed",
                  v115,
                  v116,
                  v117,
                  v118,
                  v119,
                  v120,
                  v121,
                  v122,
                  "lim_process_ap_mlm_add_bss_rsp");
              lim_apply_configuration((_QWORD *)a1, v77, v115, v116, v117, v118, v119, v120, v121, v122);
              v123 = *(_QWORD *)(a1 + 8);
              v124 = v114 ^ 1;
              if ( *(unsigned __int8 *)(v123 + 3207) < 0x11u )
                v124 = 1;
              if ( (v124 & 1) != 0 )
              {
                v78 = 0;
              }
              else
              {
                v78 = 0;
                *(_BYTE *)(v123 + 3207) = 16;
              }
              goto LABEL_73;
            }
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: WPA/RSN SAP configuration",
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              "lim_process_ap_mlm_add_bss_rsp");
          }
        }
        v114 = 0;
        goto LABEL_66;
      }
      v69 = *a2;
      v70 = "%s: session does not exist for vdev_id %d";
      v71 = "lim_process_ap_mlm_add_bss_rsp";
    }
    else
    {
      v69 = *a2;
      v70 = "%s: vdev id:%d Session Doesn't exist";
      v71 = "lim_handle_add_bss_rsp";
    }
    qdf_trace_msg(0x35u, 2u, v70, v23, v24, v25, v26, v27, v28, v29, v30, v71, v69);
    goto LABEL_74;
  }
  result = qdf_trace_msg(
             0x35u,
             2u,
             "%s: add_bss_rsp is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "lim_handle_add_bss_rsp",
             v133);
LABEL_75:
  _ReadStatusReg(SP_EL0);
  return result;
}
