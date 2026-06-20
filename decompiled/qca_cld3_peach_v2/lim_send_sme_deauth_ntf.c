__int64 __fastcall lim_send_sme_deauth_ntf(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int16 a4,
        __int64 a5,
        char a6)
{
  __int64 session_by_bssid; // x0
  int v12; // w8
  __int64 v13; // x21
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  _WORD *v24; // x24
  unsigned int v25; // w8
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x5
  __int64 v36; // x6
  __int64 v37; // x7
  int v38; // w8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x5
  __int64 v48; // x6
  __int64 v49; // x7
  int v50; // w8
  int opmode_from_vdev_id; // w0
  __int64 v52; // x1
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int16 v61; // w8
  __int64 v62; // [xsp+10h] [xbp-40h] BYREF
  _WORD *v63; // [xsp+18h] [xbp-38h]
  __int64 v64; // [xsp+20h] [xbp-30h]
  __int64 v65; // [xsp+28h] [xbp-28h]
  __int64 v66; // [xsp+30h] [xbp-20h]
  __int64 v67; // [xsp+38h] [xbp-18h]
  _BYTE v68[4]; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v69; // [xsp+48h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68[0] = 0;
  session_by_bssid = pe_find_session_by_bssid(a1, a2, v68);
  v12 = a4;
  v13 = session_by_bssid;
  if ( (unsigned int)(v12 - 5) < 2 )
  {
    v14 = _qdf_mem_malloc(0x14u, "lim_prepare_disconnect_done_ind", 1299);
    if ( !v14 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Failed to prepare message",
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 "lim_send_sme_deauth_ntf");
      goto LABEL_30;
    }
    v23 = v14;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Prepare eWNI_SME_DISCONNECT_DONE_IND withretCode: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "lim_prepare_disconnect_done_ind",
      a3);
    *(_BYTE *)(v23 + 4) = a6;
    *(_DWORD *)v23 = 1315855;
    if ( a2 )
      qdf_mem_copy((void *)(v23 + 12), a2, 6u);
    v24 = nullptr;
    if ( a3 == 505 )
      v25 = 0;
    else
      v25 = a3;
    *(_DWORD *)(v23 + 8) = v25;
    if ( !v13 )
      goto LABEL_25;
    goto LABEL_23;
  }
  if ( v12 != 4 )
  {
    result = _qdf_mem_malloc(0x28u, "lim_send_sme_deauth_ntf", 1386);
    if ( !result )
      goto LABEL_30;
    v23 = result;
    if ( a2 )
    {
      v47 = *a2;
      v48 = a2[1];
      v49 = a2[2];
      v50 = a2[5];
    }
    else
    {
      v49 = 0;
      v47 = 0;
      v48 = 0;
      v50 = 0;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: send eWNI_SME_DEAUTH_IND with retCode: %d for %02x:%02x:%02x:**:**:%02x",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "lim_send_sme_deauth_ntf",
      a3,
      v47,
      v48,
      v49,
      v50);
    *(_DWORD *)v23 = 2626574;
    *(_DWORD *)(v23 + 32) = 1;
    *(_BYTE *)(v23 + 4) = a6;
    *(_DWORD *)(v23 + 8) = a3;
    qdf_mem_copy((void *)(v23 + 12), (const void *)(v13 + 24), 6u);
    qdf_mem_copy((void *)(v23 + 18), a2, 6u);
    lim_diag_event_report(a1, 17, v13, 0);
    v24 = (_WORD *)v23;
    if ( !v13 )
      goto LABEL_25;
    goto LABEL_23;
  }
  result = _qdf_mem_malloc(0x14u, "lim_send_sme_deauth_ntf", 1348);
  if ( !result )
    goto LABEL_30;
  v23 = result;
  if ( a2 )
  {
    v35 = *a2;
    v36 = a2[1];
    v37 = a2[2];
    v38 = a2[5];
  }
  else
  {
    v37 = 0;
    v35 = 0;
    v36 = 0;
    v38 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: send eWNI_SME_DEAUTH_RSP with retCode: %d for %02x:%02x:%02x:**:**:%02x",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "lim_send_sme_deauth_ntf",
    a3,
    v35,
    v36,
    v37,
    v38);
  *(_DWORD *)(v23 + 8) = a3;
  *(_DWORD *)v23 = 1315853;
  *(_BYTE *)(v23 + 4) = a6;
  qdf_mem_copy((void *)(v23 + 12), a2, 6u);
  lim_diag_event_report(a1, 16, v13, 0);
  v24 = nullptr;
  if ( v13 )
  {
LABEL_23:
    if ( *(_DWORD *)(v13 + 88) == 2 )
      pe_delete_session(a1);
  }
LABEL_25:
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), a6);
  if ( v24 && (opmode_from_vdev_id & 0xFFFFFFFD) == 0 && *v24 == 5134 )
  {
    v66 = 0;
    v67 = 0;
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = nullptr;
    v61 = *v24;
    v63 = v24;
    LOWORD(v62) = v61;
    result = lim_send_sta_disconnect_ind(a1, (unsigned __int16 *)&v62);
  }
  else
  {
    result = lim_send_sme_disassoc_deauth_ntf(a1, v53, v54, v55, v56, v57, v58, v59, v60, v52, (unsigned __int16 *)v23);
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
