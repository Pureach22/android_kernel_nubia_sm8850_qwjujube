__int64 __fastcall cm_process_disconnect_req(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int *v9; // x19
  _QWORD *context; // x0
  __int64 v11; // x2
  _QWORD *v12; // x21
  __int64 session_by_bssid_and_vdev_id; // x20
  __int64 session_by_vdev_id; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w8
  int v32; // w8
  __int16 v33; // w8
  unsigned int v34; // w20
  int v35; // w8
  char v36; // w9
  __int16 v37; // w8
  __int16 v38; // w8
  char v39; // w9
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w1
  int v51; // w8
  __int64 v52; // [xsp+0h] [xbp-A0h]
  __int64 v53; // [xsp+8h] [xbp-98h]
  _BYTE v54[4]; // [xsp+4Ch] [xbp-54h] BYREF
  __int64 v55; // [xsp+50h] [xbp-50h] BYREF
  _QWORD *v56; // [xsp+58h] [xbp-48h]
  __int64 v57; // [xsp+60h] [xbp-40h]
  __int64 v58; // [xsp+68h] [xbp-38h]
  __int64 v59; // [xsp+70h] [xbp-30h]
  __int64 v60; // [xsp+78h] [xbp-28h]
  _QWORD v61[4]; // [xsp+80h] [xbp-20h] BYREF

  v61[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v9 = *(unsigned int **)(a1 + 8);
    if ( v9 )
    {
      context = _cds_get_context(53, (__int64)"lim_cm_handle_disconnect_req", a2, a3, a4, a5, a6, a7, a8, a9);
      if ( !context )
      {
        v34 = 4;
LABEL_30:
        _qdf_mem_free((__int64)v9);
        goto LABEL_31;
      }
      v11 = *((unsigned __int8 *)v9 + 4);
      v12 = context;
      LOBYTE(v55) = 0;
      session_by_bssid_and_vdev_id = pe_find_session_by_bssid_and_vdev_id(context, v9 + 4, v11, &v55);
      if ( !session_by_bssid_and_vdev_id )
      {
        session_by_vdev_id = pe_find_session_by_vdev_id(v12, *((unsigned __int8 *)v9 + 4));
        if ( !session_by_vdev_id )
        {
LABEL_17:
          LODWORD(v53) = *((unsigned __int8 *)v9 + 21);
          LODWORD(v52) = *((unsigned __int8 *)v9 + 18);
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: vdev_id %d cm_id 0x%x: bssid %02x:%02x:%02x:**:**:%02x : no session found",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "lim_cm_handle_disconnect_req",
            *((unsigned __int8 *)v9 + 4),
            *v9,
            *((unsigned __int8 *)v9 + 16),
            *((unsigned __int8 *)v9 + 17),
            v52,
            v53);
          lim_cm_send_disconnect_rsp(v12, *((unsigned __int8 *)v9 + 4));
          v34 = 4;
          goto LABEL_30;
        }
        session_by_bssid_and_vdev_id = session_by_vdev_id;
        qdf_trace_msg(
          0x35u,
          4u,
          "%s: vdev_id %d cm_id 0x%x: using vdev id, session (%d) found for bssid %02x:%02x:%02x:**:**:%02x [bssid in req"
          " %02x:%02x:%02x:**:**:%02x] sme state %d mlm state %d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "lim_get_disconnect_session",
          *((unsigned __int8 *)v9 + 4),
          *v9,
          *(unsigned __int16 *)(session_by_vdev_id + 8),
          *(unsigned __int8 *)(session_by_vdev_id + 24),
          *(unsigned __int8 *)(session_by_vdev_id + 25),
          *(unsigned __int8 *)(session_by_vdev_id + 26),
          *(unsigned __int8 *)(session_by_vdev_id + 29),
          *((unsigned __int8 *)v9 + 16),
          *((unsigned __int8 *)v9 + 17),
          *((unsigned __int8 *)v9 + 18),
          *((unsigned __int8 *)v9 + 21),
          *(_DWORD *)(session_by_vdev_id + 80),
          *(_DWORD *)(session_by_vdev_id + 72));
      }
      if ( (unsigned int)wlan_vdev_mlme_is_init_state(*(_QWORD *)(session_by_bssid_and_vdev_id + 16)) )
      {
        v31 = v9[2];
        if ( v31 <= 0x12 && ((1 << v31) & 0x400C0) != 0 )
        {
          v32 = *(_DWORD *)(session_by_bssid_and_vdev_id + 80);
          v59 = 0;
          v60 = 0;
          v57 = 0;
          v58 = 0;
          v55 = 0;
          v56 = nullptr;
          memset(v61, 0, 24);
          if ( v32 != 13 )
          {
            if ( v32 != 10 )
            {
              v33 = 5131;
              goto LABEL_24;
            }
            *(_DWORD *)(session_by_bssid_and_vdev_id + 80) = 13;
          }
          v33 = 5146;
LABEL_24:
          v39 = *((_BYTE *)v9 + 4);
          LOWORD(v61[0]) = v33;
          BYTE4(v61[0]) = v39;
          qdf_mem_copy((char *)&v61[1] + 4, (const void *)(session_by_bssid_and_vdev_id + 24), 6u);
          WORD1(v61[0]) = 24;
          v38 = v61[0];
          *(_DWORD *)((char *)&v61[2] + 2) = HIDWORD(v61[1]);
          HIWORD(v61[2]) = v61[2];
          v56 = v61;
          goto LABEL_25;
        }
        v35 = v9[3];
        v54[0] = 0;
        if ( v35 <= 65520 )
        {
          switch ( v35 )
          {
            case 2:
              goto LABEL_22;
            case 3:
              wlan_mlme_get_enable_deauth_to_disassoc_map(v12[2703], v54);
              if ( v54[0] != 1 )
                goto LABEL_22;
              v51 = 8;
              goto LABEL_40;
            case 6:
              goto LABEL_22;
          }
        }
        else if ( (unsigned int)(v35 - 65521) <= 0xD && ((1 << (v35 + 15)) & 0x28D5) != 0 )
        {
          v9[3] = 3;
LABEL_22:
          v59 = 0;
          v60 = 0;
          v57 = 0;
          v58 = 0;
          v55 = 0;
          v56 = nullptr;
          *(_OWORD *)((char *)v61 + 4) = 0u;
          v36 = *((_BYTE *)v9 + 4);
          LODWORD(v61[0]) = 1315852;
          BYTE4(v61[0]) = v36;
          qdf_mem_copy((char *)v61 + 5, (const void *)(session_by_bssid_and_vdev_id + 24), 6u);
          *(_DWORD *)((char *)&v61[1] + 3) = *(_DWORD *)((char *)v61 + 5);
          *(_WORD *)((char *)&v61[1] + 7) = *(_WORD *)((char *)&v61[1] + 1);
          v37 = v9[3];
          v56 = v61;
          WORD1(v61[2]) = v37;
          v38 = 5132;
LABEL_25:
          v40 = *(_QWORD *)(session_by_bssid_and_vdev_id + 16);
          LOWORD(v55) = v38;
          if ( (unsigned int)wlan_vdev_is_restart_progress(v40) )
            v49 = 12;
          else
            v49 = 6;
          wlan_vdev_mlme_sm_deliver_evt(
            *(_QWORD *)(session_by_bssid_and_vdev_id + 16),
            v49,
            0x30u,
            (__int64)&v55,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48);
          goto LABEL_29;
        }
        if ( (unsigned int)v35 < 0xFFEB || v35 == 65520 )
          goto LABEL_41;
        v51 = 1;
LABEL_40:
        v9[3] = v51;
LABEL_41:
        lim_prepare_and_send_disassoc(session_by_bssid_and_vdev_id, v9);
LABEL_29:
        v34 = 0;
        goto LABEL_30;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: vdev_id %d cm_id 0x%x: sme state %d mlm state %d: vdev is in INIT state. Delete session",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "lim_get_disconnect_session",
        *((unsigned __int8 *)v9 + 4),
        *v9,
        *(unsigned int *)(session_by_bssid_and_vdev_id + 80),
        *(unsigned int *)(session_by_bssid_and_vdev_id + 72));
      pe_delete_session(v12);
      goto LABEL_17;
    }
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: msg or msg->bodyptr is NULL",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "cm_process_disconnect_req");
  v34 = 4;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return v34;
}
