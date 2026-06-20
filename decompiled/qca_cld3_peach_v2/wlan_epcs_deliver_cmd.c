__int64 __fastcall wlan_epcs_deliver_cmd(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 v4; // x19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x4
  const char *v14; // x2
  unsigned int v15; // w1
  const char *v16; // x3
  __int64 result; // x0
  __int64 bsspeer; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x21
  __int64 v28; // x20
  unsigned int v29; // w19
  const char *v30; // x2
  __int64 v31; // x21
  unsigned int v32; // w0
  const char *v33; // x3
  __int16 v34; // w8
  unsigned __int8 v35; // w8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w0
  __int64 v45; // x19
  __int64 v46; // x19
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // [xsp+0h] [xbp-20h] BYREF
  __int64 v50; // [xsp+8h] [xbp-18h]
  __int64 v51; // [xsp+10h] [xbp-10h]
  __int64 v52; // [xsp+18h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_10;
  v2 = *(_QWORD *)(a1 + 216);
  if ( v2 )
  {
    v4 = a1;
    if ( (wlan_mlme_get_epcs_capability(*(_QWORD *)(v2 + 80)) & 1) != 0 )
      goto LABEL_4;
LABEL_8:
    v14 = "%s: EPCS has been disabled";
    v16 = "wlan_epcs_deliver_cmd";
    v15 = 4;
    goto LABEL_9;
  }
  v4 = a1;
  if ( (wlan_mlme_get_epcs_capability(0) & 1) == 0 )
    goto LABEL_8;
LABEL_4:
  if ( (unsigned int)a2 <= 6 )
  {
    if ( a2 > 2 )
    {
      if ( a2 == 3 )
      {
        v13 = "WLAN_EPCS_EV_ACTION_FRAME_RX_RESP";
        goto LABEL_6;
      }
      if ( a2 == 4 )
      {
        v13 = "WLAN_EPCS_EV_ACTION_FRAME_RX_TEARDOWN";
        goto LABEL_6;
      }
      if ( a2 != 5 )
      {
        v13 = "Unknown";
        goto LABEL_6;
      }
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: EPCS cmd received: %s(%d)",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "epcs_deliver_cmd",
        "WLAN_EPCS_EV_ACTION_FRAME_TX_TEARDOWN",
        5);
      v50 = 0;
      v51 = 0;
      v49 = 0;
      bsspeer = wlan_objmgr_vdev_try_get_bsspeer(v4, 0x5Au);
      if ( bsspeer )
      {
        v31 = *(_QWORD *)(bsspeer + 784);
        if ( v31 )
        {
          if ( *(_DWORD *)(v31 + 616) )
          {
            v28 = bsspeer;
            LOWORD(v49) = 1317;
            v32 = lim_send_epcs_action_teardown_frame(
                    v4,
                    (unsigned __int8 *)(bsspeer + 48),
                    &v49,
                    v19,
                    v20,
                    v21,
                    v22,
                    v23,
                    v24,
                    v25,
                    v26);
            if ( v32 )
            {
              v29 = v32;
              v30 = "%s: Failed to send EPCS tear down frame";
              v33 = "epcs_handle_tx_teardown";
LABEL_40:
              qdf_trace_msg(0x68u, 2u, v30, v19, v20, v21, v22, v23, v24, v25, v26, v33, v49, v50, v51);
LABEL_49:
              bsspeer = v28;
              goto LABEL_50;
            }
            v46 = *(_QWORD *)(v4 + 1360);
            if ( v46 )
            {
              v47 = *(_QWORD *)(v46 + 24);
              if ( v47 )
                lim_send_epcs_restore_edca_params(v47, v19, v20, v21, v22, v23, v24, v25, v26);
              v48 = *(_QWORD *)(v46 + 32);
              if ( v48 )
                lim_send_epcs_restore_edca_params(v48, v19, v20, v21, v22, v23, v24, v25, v26);
            }
            *(_DWORD *)(v31 + 616) = 0;
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: EPCS state: Enale -> Teardown.",
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              "epcs_handle_tx_teardown");
            goto LABEL_48;
          }
          v45 = bsspeer;
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: EPCS has been down, ignore the teardwon cmd.",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "epcs_handle_tx_teardown",
            v49,
            v50,
            v51,
            v52);
          bsspeer = v45;
          v29 = 6;
LABEL_50:
          wlan_objmgr_peer_release_ref(bsspeer, 0x5Au, v19, v20, v21, v22, v23, v24, v25, v26);
          result = v29;
          goto LABEL_11;
        }
LABEL_33:
        v29 = 29;
        goto LABEL_50;
      }
    }
    else
    {
      if ( !a2 )
      {
        v13 = "WLAN_EPCS_EV_ACTION_FRAME_RX_REQ";
        goto LABEL_6;
      }
      if ( a2 == 1 )
      {
        v13 = "WLAN_EPCS_EV_ACTION_FRAME_TX_RESP";
        goto LABEL_6;
      }
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: EPCS cmd received: %s(%d)",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "epcs_deliver_cmd",
        "WLAN_EPCS_EV_ACTION_FRAME_TX_REQ",
        2);
      v50 = 0;
      v51 = 0;
      v49 = 0;
      bsspeer = wlan_objmgr_vdev_try_get_bsspeer(v4, 0x5Au);
      if ( bsspeer )
      {
        v27 = *(_QWORD *)(bsspeer + 784);
        if ( v27 )
        {
          v28 = bsspeer;
          if ( *(_DWORD *)(v27 + 616) == 1 )
          {
            v29 = 6;
            v30 = "%s: EPCS has been enable, ignore the req cmd.";
LABEL_39:
            v33 = "epcs_handle_tx_req";
            goto LABEL_40;
          }
          v34 = *(unsigned __int8 *)(v27 + 620);
          LOWORD(v49) = 805;
          if ( ((v34 + 1) & 0x100) != 0 )
            v35 = 1;
          else
            v35 = v34 + 1;
          *(_BYTE *)(v27 + 620) = v35;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: gen dialog token %d",
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            "epcs_gen_dialog_token",
            v35,
            v49,
            v50,
            v51,
            v52);
          HIDWORD(v49) = *(unsigned __int8 *)(v27 + 620);
          v44 = lim_send_epcs_action_req_frame(
                  v4,
                  (unsigned __int8 *)(v28 + 48),
                  (__int16 *)&v49,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  v43);
          if ( v44 )
          {
            v29 = v44;
            v30 = "%s: Failed to send EPCS action request frame";
            goto LABEL_39;
          }
LABEL_48:
          v29 = 0;
          goto LABEL_49;
        }
        goto LABEL_33;
      }
    }
    result = 29;
    goto LABEL_11;
  }
  v13 = (const char *)&unk_98C763;
LABEL_6:
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: EPCS cmd received: %s(%d)",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "epcs_deliver_cmd",
    v13,
    (unsigned int)a2);
  v14 = "%s: Unhandled EPCS cmd";
  v15 = 2;
  v16 = "epcs_deliver_cmd";
LABEL_9:
  qdf_trace_msg(0x68u, v15, v14, v5, v6, v7, v8, v9, v10, v11, v12, v16);
LABEL_10:
  result = 16;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
