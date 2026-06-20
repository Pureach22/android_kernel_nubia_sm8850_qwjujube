void __fastcall _lim_process_sme_disassoc_req(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char v11; // w20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 session_by_bssid_and_vdev_id; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w4
  int v39; // w4
  int v40; // w3
  __int16 v41; // w2
  __int64 v42; // x3
  __int16 v43; // w20
  __int64 v44; // x0
  int v45; // w8
  __int16 v46; // w9
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  _BYTE v55[4]; // [xsp+64h] [xbp-5Ch] BYREF
  _QWORD v56[6]; // [xsp+68h] [xbp-58h] BYREF
  int v57; // [xsp+98h] [xbp-28h] BYREF
  __int16 v58; // [xsp+9Ch] [xbp-24h]
  _QWORD v59[4]; // [xsp+A0h] [xbp-20h] BYREF

  v59[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v59, 0, 22);
  v55[0] = 0;
  v58 = 0;
  v57 = 0;
  if ( !a2 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Buffer is Pointing to NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "__lim_process_sme_disassoc_req");
    goto LABEL_30;
  }
  qdf_mem_copy(v59, a2, 0x16u);
  v11 = BYTE4(v59[0]);
  if ( (lim_is_sme_disassoc_req_valid(a1, v59, 0) & 1) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received invalid SME_DISASSOC_REQ message",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "__lim_process_sme_disassoc_req");
    if ( !*(_BYTE *)(a1 + 4012) )
      goto LABEL_30;
    *(_BYTE *)(a1 + 4012) = 0;
LABEL_15:
    lim_send_sme_disassoc_ntf(a1, (char *)&v59[1] + 3, &v57, 500);
    goto LABEL_30;
  }
  session_by_bssid_and_vdev_id = pe_find_session_by_bssid_and_vdev_id(a1, (char *)v59 + 5, BYTE4(v59[0]), v55);
  if ( !session_by_bssid_and_vdev_id )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: session does not exist for bssid %02x:%02x:%02x:**:**:%02x",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "__lim_process_sme_disassoc_req",
      BYTE5(v59[0]),
      BYTE6(v59[0]),
      HIBYTE(v59[0]),
      BYTE2(v59[1]));
    goto LABEL_15;
  }
  v29 = session_by_bssid_and_vdev_id;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdev %d (%d) opmode %d Reason: %u SmeState: %d limMlmState %d ho fail %d send OTA %d to: %02x:%02x:%02x:**:**:%0"
    "2x bssid %02x:%02x:%02x:**:**:%02x",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "__lim_process_sme_disassoc_req",
    *(unsigned __int8 *)(session_by_bssid_and_vdev_id + 10),
    *(unsigned __int16 *)(session_by_bssid_and_vdev_id + 8),
    *(unsigned int *)(session_by_bssid_and_vdev_id + 7036),
    WORD1(v59[2]),
    *(_DWORD *)(session_by_bssid_and_vdev_id + 80),
    *(_DWORD *)(session_by_bssid_and_vdev_id + 72),
    BYTE5(v59[2]),
    BYTE4(v59[2]),
    BYTE3(v59[1]),
    BYTE4(v59[1]),
    BYTE5(v59[1]),
    LOBYTE(v59[2]),
    BYTE5(v59[0]),
    BYTE6(v59[0]),
    HIBYTE(v59[0]),
    BYTE2(v59[1]));
  lim_diag_event_report(a1, 11, v29, 0);
  v38 = *(_DWORD *)(v29 + 88);
  *(_BYTE *)(v29 + 10) = v11;
  *(_BYTE *)(v29 + 8674) = BYTE5(v59[2]);
  if ( v38 != 1 )
  {
    if ( v38 != 2 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: received unexpected SME_DISASSOC_REQ for role %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "__lim_process_sme_disassoc_req");
LABEL_17:
      v42 = 501;
      goto LABEL_18;
    }
    v39 = *(_DWORD *)(v29 + 80);
    if ( v39 <= 9 )
    {
      if ( v39 == 7 )
      {
        if ( !*(_BYTE *)(a1 + 4012) )
          goto LABEL_26;
        v42 = 0;
LABEL_18:
        lim_send_sme_disassoc_ntf(a1, (char *)&v59[1] + 3, &v57, v42);
        goto LABEL_30;
      }
      if ( v39 == 8 )
        goto LABEL_10;
      goto LABEL_21;
    }
    if ( v39 == 13 )
    {
      v41 = *(_WORD *)(v29 + 8);
      v40 = 12;
      *(_DWORD *)(v29 + 80) = 12;
      goto LABEL_25;
    }
    if ( v39 != 12 )
    {
      if ( v39 == 10 )
      {
LABEL_10:
        *(_DWORD *)(v29 + 80) = 12;
        *(_DWORD *)(v29 + 84) = v39;
        lim_delete_tdls_peers(a1, v29, 0);
        v40 = *(_DWORD *)(v29 + 80);
        v41 = *(_WORD *)(v29 + 8);
LABEL_25:
        qdf_trace(53, 1u, v41, v40);
        goto LABEL_26;
      }
LABEL_21:
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: received unexpected SME_DISASSOC_REQ in state %X",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "__lim_process_sme_disassoc_req");
      lim_print_sme_state(a1, 2, *(unsigned int *)(v29 + 80));
      if ( !*(_BYTE *)(a1 + 4012) )
        goto LABEL_30;
      if ( *(_DWORD *)(v29 + 80) != 5 )
        *(_BYTE *)(a1 + 4012) = 0;
      goto LABEL_17;
    }
  }
LABEL_26:
  if ( BYTE4(v59[2]) )
    send_disassoc_frame = 0;
  v43 = WORD1(v59[2]);
  v44 = _qdf_mem_malloc(0xEu, "__lim_process_sme_disassoc_req", 7308);
  if ( v44 )
  {
    v45 = *(_DWORD *)((char *)&v59[1] + 3);
    v46 = *(_WORD *)((char *)&v59[1] + 7);
    *(_WORD *)(v44 + 6) = v43;
    *(_DWORD *)v44 = v45;
    LOBYTE(v45) = v55[0];
    *(_WORD *)(v44 + 8) = 0;
    *(_WORD *)(v44 + 4) = v46;
    *(_BYTE *)(v44 + 12) = v45;
    v56[0] = 1012;
    v56[1] = v44;
    memset(&v56[2], 0, 32);
    mac_trace_msg_rx(a1, 255, 1012);
    lim_process_mlm_req_messages(a1, (unsigned __int16 *)v56, v47, v48, v49, v50, v51, v52, v53, v54);
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
}
