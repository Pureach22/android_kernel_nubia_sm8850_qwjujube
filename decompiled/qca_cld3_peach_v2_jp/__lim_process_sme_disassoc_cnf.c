__int64 __fastcall _lim_process_sme_disassoc_cnf(__int64 a1, const void *a2)
{
  __int64 session_by_bssid_and_vdev_id; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x1
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  __int64 v26; // x2
  __int64 v27; // x0
  __int64 v28; // x3
  __int64 result; // x0
  __int64 v30; // x2
  int v31; // w11
  int v32; // w12
  int v33; // w13
  int v34; // w8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w4
  unsigned int v44; // w4
  __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w8
  __int64 v55; // [xsp+0h] [xbp-80h]
  __int64 v56; // [xsp+48h] [xbp-38h]
  __int64 v57; // [xsp+50h] [xbp-30h] BYREF
  __int64 v58; // [xsp+58h] [xbp-28h] BYREF
  __int64 v59; // [xsp+60h] [xbp-20h] BYREF
  __int64 v60; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v61[2]; // [xsp+70h] [xbp-10h] BYREF

  v61[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v60 = 0;
  v61[0] = 0;
  v59 = 0;
  WORD2(v58) = 0;
  LOBYTE(v58) = 0;
  v57 = 0;
  qdf_mem_copy(&v59, a2, 0x18u);
  session_by_bssid_and_vdev_id = pe_find_session_by_bssid_and_vdev_id(a1, (char *)&v60 + 4, BYTE4(v59), &v58);
  if ( !session_by_bssid_and_vdev_id )
  {
    if ( &v59 == (__int64 *)-12LL )
      v22 = 0;
    else
      v22 = BYTE4(v60);
    if ( &v60 == (__int64 *)-4LL )
      v23 = 0;
    else
      v23 = BYTE5(v60);
    if ( &v60 == (__int64 *)-4LL )
      v24 = 0;
    else
      v24 = BYTE6(v60);
    if ( &v60 == (__int64 *)-4LL )
      v25 = 0;
    else
      v25 = BYTE1(v61[0]);
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: session does not exist for bssid %02x:%02x:%02x:**:**:%02x",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "__lim_process_sme_disassoc_cnf",
      v22,
      v23,
      v24,
      v25);
    v26 = BYTE4(v59);
    v27 = a1;
    v28 = 541;
LABEL_19:
    result = lim_prepare_disconnect_done_ind(v27, &v57, v26, v28, 0);
    if ( !(_DWORD)result )
      goto LABEL_45;
    goto LABEL_46;
  }
  v12 = session_by_bssid_and_vdev_id;
  if ( (lim_is_sme_disassoc_cnf_valid(a1, &v59, session_by_bssid_and_vdev_id) & 1) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received invalid SME_DISASSOC_CNF message",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "__lim_process_sme_disassoc_cnf");
    v30 = *(unsigned __int8 *)(v12 + 10);
    goto LABEL_22;
  }
  if ( (unsigned __int16)v59 == 5131 )
  {
    v21 = 14;
  }
  else
  {
    if ( (unsigned __int16)v59 != 5146 )
      goto LABEL_26;
    v21 = 28;
  }
  lim_diag_event_report(a1, v21, v12, (unsigned int)v60);
LABEL_26:
  v31 = BYTE5(v60);
  v32 = BYTE6(v60);
  v33 = BYTE1(v61[0]);
  if ( &v60 == (__int64 *)-4LL )
    v34 = 0;
  else
    v34 = BYTE4(v60);
  if ( &v60 == (__int64 *)-4LL )
  {
    v31 = 0;
    v32 = 0;
    v33 = 0;
  }
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: vdev %d (%d) opmode %d SmeState: %d limMlmState %d from: %02x:%02x:%02x:**:**:%02x bssid %02x:%02x:%02x:**:**:%02x",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "__lim_process_sme_disassoc_cnf",
             *(unsigned __int8 *)(v12 + 10),
             *(unsigned __int16 *)(v12 + 8),
             *(unsigned int *)(v12 + 7036),
             *(unsigned int *)(v12 + 80),
             *(_DWORD *)(v12 + 72),
             BYTE2(v61[0]),
             BYTE3(v61[0]),
             BYTE4(v61[0]),
             HIBYTE(v61[0]),
             v34,
             v31,
             v32,
             v33,
             v56,
             v57,
             v58);
  v43 = *(_DWORD *)(v12 + 88);
  if ( v43 == 1 )
  {
LABEL_36:
    v45 = dph_lookup_hash_entry(
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            a1,
            (unsigned __int8 *)v61 + 2,
            (_WORD *)&v58 + 2,
            v12 + 360);
    if ( v45 )
    {
      v54 = *(_DWORD *)(v45 + 8);
      if ( v54 != 22 && v54 != 17 )
      {
        lim_cleanup_rx_path(a1, (__int16 *)v45, v12, 1, v46, v47, v48, v49, v50, v51, v52, v53);
        result = lim_clean_up_disassoc_deauth_req(a1, (char *)v61 + 2, 0);
        goto LABEL_46;
      }
      LODWORD(v55) = *(_DWORD *)(v45 + 8);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: No need of cleanup for addr:%02x:%02x:%02x:**:**:%02xas MLM state is %d",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "__lim_process_sme_disassoc_cnf",
        BYTE2(v61[0]),
        BYTE3(v61[0]),
        BYTE4(v61[0]),
        HIBYTE(v61[0]),
        v55);
      v26 = *(unsigned __int8 *)(v12 + 10);
      v27 = a1;
      v28 = 0;
      goto LABEL_19;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: DISASSOC_CNF for a STA with no context, addr= %02x:%02x:%02x:**:**:%02x",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "__lim_process_sme_disassoc_cnf",
      BYTE2(v61[0]),
      BYTE3(v61[0]),
      BYTE4(v61[0]),
      HIBYTE(v61[0]));
    v30 = *(unsigned __int8 *)(v12 + 10);
LABEL_22:
    result = lim_prepare_disconnect_done_ind(a1, &v57, v30, 500, (char *)v61 + 2);
    if ( !(_DWORD)result )
      goto LABEL_45;
    goto LABEL_46;
  }
  if ( v43 == 2 )
  {
    v44 = *(_DWORD *)(v12 + 80);
    if ( v44 <= 0xD && ((1 << v44) & 0x3002) != 0 )
    {
      if ( (v44 & 0xFFFFFFFE) != 0xC )
        goto LABEL_46;
      goto LABEL_36;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received unexp SME_DISASSOC_CNF in state %X",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "__lim_process_sme_disassoc_cnf");
    lim_print_sme_state(a1, 2, *(unsigned int *)(v12 + 80));
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received unexpected SME_DISASSOC_CNF role %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "__lim_process_sme_disassoc_cnf");
  }
  result = lim_prepare_disconnect_done_ind(a1, &v57, *(unsigned __int8 *)(v12 + 10), 528, (char *)v61 + 2);
  if ( !(_DWORD)result )
LABEL_45:
    result = lim_send_sme_disassoc_deauth_ntf(a1, 0, v57);
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
