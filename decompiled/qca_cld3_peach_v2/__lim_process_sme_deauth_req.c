__int64 __fastcall _lim_process_sme_deauth_req(__int64 a1, const void *a2)
{
  unsigned int v3; // w20
  __int64 session_by_bssid_and_vdev_id; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w4
  unsigned int v31; // w4
  __int64 v32; // x2
  __int64 result; // x0
  __int16 v34; // w2
  __int16 v35; // w23
  __int16 v36; // w21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w8
  __int16 v46; // w9
  int v47; // w8
  _BYTE v49[4]; // [xsp+5Ch] [xbp-24h] BYREF
  _QWORD v50[4]; // [xsp+60h] [xbp-20h] BYREF

  v50[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v50, 0, 20);
  v49[0] = 0;
  qdf_mem_copy(v50, a2, 0x14u);
  v3 = BYTE4(v50[0]);
  session_by_bssid_and_vdev_id = pe_find_session_by_bssid_and_vdev_id(a1, (char *)v50 + 5, BYTE4(v50[0]), v49);
  if ( !session_by_bssid_and_vdev_id )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: session does not exist for bssid %02x:%02x:%02x:**:**:%02x",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "__lim_process_sme_deauth_req",
      BYTE5(v50[0]),
      BYTE6(v50[0]),
      HIBYTE(v50[0]),
      BYTE2(v50[1]));
LABEL_13:
    v32 = 500;
    goto LABEL_14;
  }
  v13 = session_by_bssid_and_vdev_id;
  if ( (lim_is_sme_deauth_req_valid(a1, v50, session_by_bssid_and_vdev_id) & 1) == 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received invalid SME_DEAUTH_REQ message",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "__lim_process_sme_deauth_req");
LABEL_12:
    *(_BYTE *)(a1 + 4012) = 0;
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdev %d (%d) opmode %d reasoncode %u limSmestate %d limMlmState %d to %02x:%02x:%02x:**:**:%02x bssid %02x:%02x:%02x:**:**:%02x",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "__lim_process_sme_deauth_req",
    v3,
    *(unsigned __int16 *)(v13 + 8),
    *(unsigned int *)(v13 + 7036),
    WORD1(v50[2]),
    *(_DWORD *)(v13 + 80),
    *(_DWORD *)(v13 + 72),
    BYTE3(v50[1]),
    BYTE4(v50[1]),
    BYTE5(v50[1]),
    LOBYTE(v50[2]),
    BYTE5(v50[0]),
    BYTE6(v50[0]),
    HIBYTE(v50[0]),
    BYTE2(v50[1]));
  lim_diag_event_report(a1, 15, v13, 0);
  v30 = *(_DWORD *)(v13 + 88);
  *(_BYTE *)(v13 + 10) = v3;
  if ( v30 == 1 )
  {
    lim_mlo_sap_validate_and_update_ra(v13, (char *)&v50[1] + 3);
    goto LABEL_21;
  }
  if ( v30 != 2 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: received unexpected SME_DEAUTH_REQ for role %X",
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               "__lim_process_sme_deauth_req");
    if ( !*(_BYTE *)(a1 + 4012) )
      goto LABEL_15;
    goto LABEL_12;
  }
  v31 = *(_DWORD *)(v13 + 80);
  if ( v31 > 0xD )
    goto LABEL_30;
  if ( ((1 << v31) & 0xA2) == 0 )
  {
    if ( ((1 << v31) & 0x500) == 0 )
    {
      if ( ((1 << v31) & 0x3000) != 0 )
      {
        *(_DWORD *)(v13 + 80) = 13;
        goto LABEL_21;
      }
LABEL_30:
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: received unexp SME_DEAUTH_REQ in state %X",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "__lim_process_sme_deauth_req");
      result = lim_print_sme_state(a1, 2, *(unsigned int *)(v13 + 80));
      if ( !*(_BYTE *)(a1 + 4012) )
        goto LABEL_15;
      *(_BYTE *)(a1 + 4012) = 0;
      v32 = 519;
      if ( *(_DWORD *)(v13 + 80) == 13 )
      {
        v47 = *(_DWORD *)(v13 + 72);
        if ( v47 == 22 || v47 == 1 )
          v32 = 519;
        else
          v32 = 539;
      }
      goto LABEL_14;
    }
    lim_delete_tdls_peers(a1, v13, 0);
    v31 = *(_DWORD *)(v13 + 80);
  }
  v34 = *(_WORD *)(v13 + 8);
  *(_DWORD *)(v13 + 80) = 13;
  *(_DWORD *)(v13 + 84) = v31;
  qdf_trace(53, 1u, v34, 13);
LABEL_21:
  v35 = WORD1(v50[2]);
  if ( WORD1(v50[2]) != 6 )
  {
LABEL_25:
    v36 = 4;
    goto LABEL_26;
  }
  if ( *(_DWORD *)(v13 + 88) != 2 )
  {
    v35 = 6;
    goto LABEL_25;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: ** Lost link with AP **",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "__lim_process_sme_deauth_req");
  v35 = 1;
  v36 = 6;
LABEL_26:
  result = _qdf_mem_malloc(0xEu, "__lim_process_sme_deauth_req", 7673);
  if ( result )
  {
    v45 = *(_DWORD *)((char *)&v50[1] + 3);
    v46 = *(_WORD *)((char *)&v50[1] + 7);
    *(_WORD *)(result + 6) = v35;
    *(_DWORD *)result = v45;
    LOBYTE(v45) = v49[0];
    *(_WORD *)(result + 4) = v46;
    *(_WORD *)(result + 8) = v36;
    *(_BYTE *)(result + 12) = v45;
    result = lim_process_mlm_deauth_req(a1, (unsigned __int8 *)result, v37, v38, v39, v40, v41, v42, v43, v44);
    goto LABEL_15;
  }
  if ( !*(_BYTE *)(a1 + 4012) )
    goto LABEL_15;
  v32 = 502;
  *(_BYTE *)(a1 + 4012) = 0;
LABEL_14:
  result = lim_send_sme_deauth_ntf(a1, (char *)&v50[1] + 3, v32, 4, 1, v3);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
