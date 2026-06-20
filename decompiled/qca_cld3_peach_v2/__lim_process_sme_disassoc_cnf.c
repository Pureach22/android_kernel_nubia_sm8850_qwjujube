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
  int v30; // w11
  int v31; // w12
  int v32; // w13
  int v33; // w8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  int v42; // w4
  unsigned int v43; // w4
  __int64 v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w8
  __int16 *v54; // x21
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // [xsp+0h] [xbp-80h]
  __int64 v64; // [xsp+48h] [xbp-38h]
  __int64 v65; // [xsp+50h] [xbp-30h] BYREF
  __int64 v66; // [xsp+58h] [xbp-28h] BYREF
  __int64 v67; // [xsp+60h] [xbp-20h] BYREF
  __int64 v68; // [xsp+68h] [xbp-18h] BYREF
  _QWORD v69[2]; // [xsp+70h] [xbp-10h] BYREF

  v69[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68 = 0;
  v69[0] = 0;
  v67 = 0;
  WORD2(v66) = 0;
  LOBYTE(v66) = 0;
  v65 = 0;
  qdf_mem_copy(&v67, a2, 0x18u);
  session_by_bssid_and_vdev_id = pe_find_session_by_bssid_and_vdev_id(a1, (char *)&v68 + 4, BYTE4(v67), &v66);
  if ( !session_by_bssid_and_vdev_id )
  {
    if ( &v67 == (__int64 *)-12LL )
      v22 = 0;
    else
      v22 = BYTE4(v68);
    if ( &v68 == (__int64 *)-4LL )
      v23 = 0;
    else
      v23 = BYTE5(v68);
    if ( &v68 == (__int64 *)-4LL )
      v24 = 0;
    else
      v24 = BYTE6(v68);
    if ( &v68 == (__int64 *)-4LL )
      v25 = 0;
    else
      v25 = BYTE1(v69[0]);
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
    v26 = BYTE4(v67);
    v27 = a1;
    v28 = 541;
LABEL_19:
    result = lim_prepare_disconnect_done_ind(v27, &v65, v26, v28, 0);
    if ( !(_DWORD)result )
      goto LABEL_45;
    goto LABEL_46;
  }
  v12 = session_by_bssid_and_vdev_id;
  if ( (lim_is_sme_disassoc_cnf_valid(a1, &v67, session_by_bssid_and_vdev_id) & 1) == 0 )
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
    goto LABEL_22;
  }
  if ( (unsigned __int16)v67 == 5131 )
  {
    v21 = 14;
  }
  else
  {
    if ( (unsigned __int16)v67 != 5146 )
      goto LABEL_26;
    v21 = 28;
  }
  lim_diag_event_report(a1, v21, v12, (unsigned int)v68);
LABEL_26:
  v30 = BYTE5(v68);
  v31 = BYTE6(v68);
  v32 = BYTE1(v69[0]);
  if ( &v68 == (__int64 *)-4LL )
    v33 = 0;
  else
    v33 = BYTE4(v68);
  if ( &v68 == (__int64 *)-4LL )
  {
    v30 = 0;
    v31 = 0;
    v32 = 0;
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
             BYTE2(v69[0]),
             BYTE3(v69[0]),
             BYTE4(v69[0]),
             HIBYTE(v69[0]),
             v33,
             v30,
             v31,
             v32,
             v64,
             v65,
             v66);
  v42 = *(_DWORD *)(v12 + 88);
  if ( v42 == 1 )
  {
LABEL_36:
    v44 = dph_lookup_hash_entry(
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            a1,
            (unsigned __int8 *)v69 + 2,
            (_WORD *)&v66 + 2,
            v12 + 360);
    if ( v44 )
    {
      v53 = *(_DWORD *)(v44 + 8);
      if ( v53 != 22 && v53 != 17 )
      {
        v54 = (__int16 *)v44;
        lim_mlo_notify_peer_disconn(v12, v44);
        lim_cleanup_rx_path(a1, v54, v12, 1, v55, v56, v57, v58, v59, v60, v61, v62);
        result = lim_clean_up_disassoc_deauth_req(a1, (char *)v69 + 2, 0);
        goto LABEL_46;
      }
      LODWORD(v63) = *(_DWORD *)(v44 + 8);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: No need of cleanup for addr:%02x:%02x:%02x:**:**:%02xas MLM state is %d",
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        "__lim_process_sme_disassoc_cnf",
        BYTE2(v69[0]),
        BYTE3(v69[0]),
        BYTE4(v69[0]),
        HIBYTE(v69[0]),
        v63);
      v26 = *(unsigned __int8 *)(v12 + 10);
      v27 = a1;
      v28 = 0;
      goto LABEL_19;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: DISASSOC_CNF for a STA with no context, addr= %02x:%02x:%02x:**:**:%02x",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "__lim_process_sme_disassoc_cnf",
      BYTE2(v69[0]),
      BYTE3(v69[0]),
      BYTE4(v69[0]),
      HIBYTE(v69[0]));
LABEL_22:
    result = lim_prepare_disconnect_done_ind(a1, &v65, *(unsigned __int8 *)(v12 + 10), 500, (char *)v69 + 2);
    if ( !(_DWORD)result )
      goto LABEL_45;
    goto LABEL_46;
  }
  if ( v42 == 2 )
  {
    v43 = *(_DWORD *)(v12 + 80);
    if ( v43 <= 0xD && ((1 << v43) & 0x3002) != 0 )
    {
      if ( (v43 & 0xFFFFFFFE) != 0xC )
        goto LABEL_46;
      goto LABEL_36;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received unexp SME_DISASSOC_CNF in state %X",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "__lim_process_sme_disassoc_cnf");
    lim_print_sme_state(a1, 2, *(unsigned int *)(v12 + 80));
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received unexpected SME_DISASSOC_CNF role %d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "__lim_process_sme_disassoc_cnf");
  }
  result = lim_prepare_disconnect_done_ind(a1, &v65, *(unsigned __int8 *)(v12 + 10), 528, (char *)v69 + 2);
  if ( !(_DWORD)result )
LABEL_45:
    result = lim_send_sme_disassoc_deauth_ntf(a1, 0, v65);
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
