__int64 __fastcall lim_process_sme_tdls_mgmt_send_req(__int64 a1, __int64 a2)
{
  __int64 session_by_bssid; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x4
  __int64 v14; // x21
  int v15; // w23
  const char *v16; // x2
  unsigned int v17; // w20
  const char *v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x0
  __int64 v28; // x21
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w8
  unsigned int v48; // w22
  unsigned __int8 v49[4]; // [xsp+4h] [xbp-3Ch] BYREF
  __int64 v50; // [xsp+8h] [xbp-38h] BYREF
  __int64 v51; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v52)(__int64, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 v53; // [xsp+20h] [xbp-20h]
  __int64 v54; // [xsp+28h] [xbp-18h]
  __int64 v55; // [xsp+30h] [xbp-10h]
  __int64 v56; // [xsp+38h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49[0] = 0;
  session_by_bssid = pe_find_session_by_bssid(a1, (unsigned __int8 *)(a2 + 16), v49);
  if ( !session_by_bssid )
  {
    v13 = *(unsigned __int8 *)(a2 + 4);
    v16 = "%s: PE Session does not exist for given sme session_id %d";
LABEL_7:
    qdf_trace_msg(0x35u, 2u, v16, v5, v6, v7, v8, v9, v10, v11, v12, "lim_process_sme_tdls_mgmt_send_req", v13);
    v15 = 500;
    goto LABEL_8;
  }
  v13 = *(unsigned int *)(session_by_bssid + 88);
  if ( (_DWORD)v13 != 2 )
  {
    v16 = "%s: send mgmt received in wrong system Role: %d";
    goto LABEL_7;
  }
  v14 = session_by_bssid;
  if ( !wlan_cm_is_vdev_roam_sync_inprogress(*(_QWORD *)(session_by_bssid + 16), v5, v6, v7, v8, v9, v10, v11, v12) )
  {
    v13 = *(unsigned int *)(v14 + 80);
    if ( ((unsigned int)v13 | 2) == 0xA )
    {
      cds_tdls_tx_rx_mgmt_event(12, 1, 13, *(_BYTE *)(a2 + 5), (const void *)(a2 + 22));
      v47 = *(unsigned __int8 *)(a2 + 5);
      v15 = 500;
      v48 = *(unsigned __int16 *)(a2 + 2) - 36;
      if ( v47 > 2 )
      {
        switch ( v47 )
        {
          case 3u:
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Transmit Teardown Frame",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "lim_process_sme_tdls_mgmt_send_req");
            lim_send_tdls_teardown_frame(
              a1,
              *(unsigned int *)(a2 + 22) | ((unsigned __int64)*(unsigned __int16 *)(a2 + 26) << 32),
              *(unsigned __int16 *)(a2 + 8),
              *(unsigned __int8 *)(a2 + 10),
              v14,
              a2 + 32,
              v48,
              *(unsigned int *)(a2 + 28));
            break;
          case 0xEu:
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Transmit Discovery Response Frame",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "lim_process_sme_tdls_mgmt_send_req");
            lim_send_tdls_dis_rsp_frame(
              a1,
              *(unsigned int *)(a2 + 22) | ((unsigned __int64)*(unsigned __int16 *)(a2 + 26) << 32),
              *(unsigned __int8 *)(a2 + 6),
              v14,
              a2 + 32,
              v48);
            break;
          case 0xAu:
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Transmit Discovery Request Frame",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "lim_process_sme_tdls_mgmt_send_req");
            lim_send_tdls_dis_req_frame(
              a1,
              *(unsigned int *)(a2 + 22) | ((unsigned __int64)*(unsigned __int16 *)(a2 + 26) << 32),
              *(unsigned __int8 *)(a2 + 6),
              v14,
              *(unsigned int *)(a2 + 28));
            break;
          default:
            goto LABEL_8;
        }
      }
      else if ( *(_BYTE *)(a2 + 5) )
      {
        if ( v47 == 1 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Transmit Setup Response Frame",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "lim_process_sme_tdls_mgmt_send_req");
          lim_send_tdls_setup_rsp_frame(
            a1,
            *(unsigned int *)(a2 + 22) | ((unsigned __int64)*(unsigned __int16 *)(a2 + 26) << 32),
            *(unsigned __int8 *)(a2 + 6),
            v14,
            *(unsigned __int16 *)(a2 + 8),
            a2 + 32,
            v48,
            *(unsigned int *)(a2 + 28));
        }
        else
        {
          if ( v47 != 2 )
            goto LABEL_8;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Transmit Setup Confirm Frame",
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            "lim_process_sme_tdls_mgmt_send_req");
          lim_send_tdls_link_setup_cnf_frame(
            a1,
            *(unsigned int *)(a2 + 22) | ((unsigned __int64)*(unsigned __int16 *)(a2 + 26) << 32),
            *(unsigned __int8 *)(a2 + 6),
            *(unsigned int *)(a2 + 12),
            v14,
            a2 + 32,
            v48,
            *(unsigned int *)(a2 + 28));
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Transmit Setup Request Frame",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "lim_process_sme_tdls_mgmt_send_req");
        lim_send_tdls_link_setup_req_frame(
          a1,
          *(unsigned int *)(a2 + 22) | ((unsigned __int64)*(unsigned __int16 *)(a2 + 26) << 32),
          *(unsigned __int8 *)(a2 + 6),
          v14,
          a2 + 32,
          v48,
          *(unsigned int *)(a2 + 28));
      }
      v15 = 0;
      goto LABEL_8;
    }
    v16 = "%s: send mgmt received in invalid LIMsme state: %d";
    goto LABEL_7;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: roaming in progress, reject mgmt! for session %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "lim_process_sme_tdls_mgmt_send_req",
    *(unsigned __int8 *)(a2 + 4));
  v15 = 506;
LABEL_8:
  v17 = *(unsigned __int8 *)(a2 + 4);
  v54 = 0;
  v55 = 0;
  v52 = nullptr;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v18 = lim_result_code_str(v15);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdev:%d TDLS_SEND_MGMT_RSP reasonCode %s",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "lim_send_tdls_comp_mgmt_rsp",
    v17,
    v18);
  v27 = _qdf_mem_malloc(0x10u, "lim_send_tdls_comp_mgmt_rsp", 3964);
  if ( v27 )
  {
    *(_DWORD *)(v27 + 4) = v15;
    v28 = v27;
    *(_BYTE *)v27 = v17;
    *(_QWORD *)(v27 + 8) = *(_QWORD *)(a1 + 21624);
    v51 = v27;
    v52 = tgt_tdls_send_mgmt_rsp;
    v29 = scheduler_post_message_debug(
            0x35u,
            0,
            73,
            (unsigned __int16 *)&v50,
            0xF88u,
            (__int64)"lim_send_tdls_comp_mgmt_rsp");
    if ( v29 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: vdev_id %d post msg fail, %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "lim_send_tdls_comp_mgmt_rsp",
        v17,
        v29);
      _qdf_mem_free(v28);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
