__int64 __fastcall _lim_process_sme_stop_bss_req(__int64 a1, __int64 a2)
{
  const void *v3; // x1
  unsigned int v4; // w20
  __int64 session_by_bssid; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  int v23; // w5
  __int64 v24; // x0
  __int64 v25; // x1
  __int64 v26; // x2
  int v27; // w8
  __int16 v28; // w2
  int v29; // w8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w1
  __int64 result; // x0
  int v43; // w3
  __int16 v44; // w2
  char v45[4]; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v46; // [xsp+8h] [xbp-18h] BYREF
  int v47; // [xsp+10h] [xbp-10h] BYREF
  __int16 v48; // [xsp+14h] [xbp-Ch]
  __int64 v49; // [xsp+18h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(const void **)(a2 + 8);
  v46 = 0;
  v48 = 0;
  v47 = 0;
  v45[0] = 0;
  qdf_mem_copy(&v46, v3, 8u);
  v4 = (unsigned __int8)v46;
  wlan_mlme_get_mac_vdev_id(*(_QWORD *)(a1 + 21632), v46, &v47);
  session_by_bssid = pe_find_session_by_bssid(a1, &v47, v45);
  if ( !session_by_bssid )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: session does not exist for bssid %02x:%02x:%02x:**:**:%02x",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "__lim_handle_sme_stop_bss_request",
      (unsigned __int8)v47,
      BYTE1(v47),
      BYTE2(v47),
      HIBYTE(v48));
    v24 = a1;
    v25 = v4;
    v26 = 500;
    goto LABEL_16;
  }
  v14 = session_by_bssid;
  lim_diag_event_report(a1, 26, session_by_bssid, 0);
  v23 = *(_DWORD *)(v14 + 88);
  if ( *(_DWORD *)(v14 + 80) != 16 )
  {
LABEL_5:
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received unexpected SME_STOP_BSS_REQ in state %X, for role %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "__lim_handle_sme_stop_bss_request");
    lim_print_sme_state(a1, 2, *(unsigned int *)(v14 + 80));
    v24 = a1;
    v25 = v4;
    v26 = 501;
LABEL_16:
    result = lim_send_stop_bss_response(v24, v25, v26);
    goto LABEL_17;
  }
  if ( v23 == 1 )
  {
    lim_wpspbc_close(v15, v16, v17, v18, v19, v20, v21, v22, a1, v14);
    v27 = *(_DWORD *)(v14 + 80);
  }
  else
  {
    if ( v23 == 2 )
      goto LABEL_5;
    v27 = 16;
  }
  v28 = *(_WORD *)(v14 + 8);
  *(_DWORD *)(v14 + 80) = 1;
  *(_DWORD *)(v14 + 84) = v27;
  qdf_trace(53, 1u, v28, 1);
  v29 = *(_DWORD *)(v14 + 88);
  *(_BYTE *)(v14 + 10) = v4;
  *(_DWORD *)(v14 + 10052) = 0;
  if ( v29 != 6 )
  {
    _qdf_mem_free(*(_QWORD *)(v14 + 7296));
    v30 = *(_QWORD *)(v14 + 7312);
    *(_WORD *)(v14 + 7288) = 0;
    *(_QWORD *)(v14 + 7296) = 0;
    _qdf_mem_free(v30);
    v31 = *(_QWORD *)(v14 + 7328);
    *(_WORD *)(v14 + 7304) = 0;
    *(_QWORD *)(v14 + 7312) = 0;
    _qdf_mem_free(v31);
    *(_WORD *)(v14 + 7320) = 0;
    *(_QWORD *)(v14 + 7328) = 0;
  }
  v32 = *(_QWORD *)(v14 + 8608);
  if ( (unsigned int)wlan_vdev_is_restart_progress(*(_QWORD *)(v14 + 16)) )
    v41 = 12;
  else
    v41 = 6;
  result = wlan_vdev_mlme_sm_deliver_evt(
             *(_QWORD *)(v14 + 16),
             v41,
             0x36B0u,
             v14,
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40);
  if ( (_DWORD)result )
  {
    v43 = *(_DWORD *)(v14 + 84);
    v44 = *(_WORD *)(v14 + 8);
    *(_DWORD *)(v14 + 80) = v43;
    qdf_trace(53, 1u, v44, v43);
    v25 = *(unsigned __int8 *)(v14 + 10);
    v24 = v32;
    v26 = 533;
    goto LABEL_16;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
