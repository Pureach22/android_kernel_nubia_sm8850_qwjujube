__int64 __fastcall lim_process_mlm_deauth_req(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x1
  __int64 session_by_session_id; // x0
  __int64 v22; // x21
  int v23; // w8
  __int64 v24; // x4
  __int64 v25; // x0
  char v26; // w8
  __int64 v27; // x21
  __int64 result; // x0
  __int64 v29; // x4
  const char *v30; // x3
  __int16 v31; // w2
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int16 v41; // w8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  int v51; // w8
  __int16 v52; // w9
  int v53; // w10
  unsigned __int8 v54; // w8
  unsigned __int16 v55; // w22
  __int64 hash_entry; // x0
  __int16 v57; // w8
  _WORD v58[2]; // [xsp+28h] [xbp-28h] BYREF
  int v59; // [xsp+2Ch] [xbp-24h] BYREF
  __int64 v60; // [xsp+30h] [xbp-20h]
  __int64 v61; // [xsp+38h] [xbp-18h]
  unsigned __int8 v62; // [xsp+40h] [xbp-10h] BYREF
  unsigned __int8 v63; // [xsp+41h] [xbp-Fh]
  unsigned __int8 v64; // [xsp+42h] [xbp-Eh]
  char v65; // [xsp+43h] [xbp-Dh]
  char v66; // [xsp+44h] [xbp-Ch]
  unsigned __int8 v67; // [xsp+45h] [xbp-Bh]
  __int64 v68; // [xsp+48h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    result = qdf_trace_msg(
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
               "lim_process_mlm_deauth_req");
    goto LABEL_37;
  }
  if ( !pe_find_session_by_session_id(a1, a2[12]) )
  {
    v29 = a2[12];
    v30 = "lim_process_mlm_deauth_req";
LABEL_14:
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: session does not exist for given sessionId %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v30,
      v29);
LABEL_15:
    result = _qdf_mem_free((__int64)a2);
    goto LABEL_37;
  }
  v20 = a2[12];
  v58[0] = 0;
  v60 = 0;
  v61 = 0;
  session_by_session_id = pe_find_session_by_session_id(a1, v20);
  if ( !session_by_session_id )
  {
    v29 = a2[12];
    v30 = "lim_process_mlm_deauth_req_ntf";
    goto LABEL_14;
  }
  v22 = session_by_session_id;
  v62 = *(_BYTE *)(session_by_session_id + 24);
  v63 = *(_BYTE *)(session_by_session_id + 25);
  v64 = *(_BYTE *)(session_by_session_id + 26);
  v65 = *(_BYTE *)(session_by_session_id + 27);
  v66 = *(_BYTE *)(session_by_session_id + 28);
  v23 = *(_DWORD *)(session_by_session_id + 88);
  v67 = *(_BYTE *)(session_by_session_id + 29);
  if ( v23 != 2 )
    goto LABEL_18;
  v24 = *(unsigned int *)(session_by_session_id + 72);
  if ( (unsigned int)(v24 - 9) >= 2 )
  {
    if ( (_DWORD)v24 == 1 )
      goto LABEL_18;
    if ( (_DWORD)v24 != 14 )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: received MLM_DEAUTH_REQ with in state %d for peer %02x:%02x:%02x:**:**:%02x",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "lim_process_mlm_deauth_req_ntf",
        v24,
        *a2,
        a2[1],
        a2[2],
        a2[5]);
      lim_print_mlm_state(a1, 3, *(unsigned int *)(v22 + 72));
LABEL_34:
      v51 = 519;
      goto LABEL_35;
    }
  }
  if ( (unsigned int)qdf_mem_cmp(a2, &v62, 6u) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: received MLM_DEAUTH_REQ with invalid BSS id Peer MAC: %02x:%02x:%02x:**:**:%02x CFG BSSID Addr : %02x:%02x:%02x:**:**:%02x",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "lim_process_mlm_deauth_req_ntf",
      *a2,
      a2[1],
      a2[2],
      a2[5],
      v62,
      v63,
      v64,
      v67);
    v25 = _qdf_mem_malloc(0x14u, "lim_process_mlm_deauth_req_ntf", 1444);
    if ( v25 )
    {
      *(_DWORD *)(v25 + 8) = 539;
      *(_DWORD *)v25 = 1315853;
      v26 = *(_BYTE *)(v22 + 10);
      v27 = v25;
      *(_BYTE *)(v25 + 4) = v26;
      qdf_mem_copy((void *)(v25 + 12), a2, 6u);
      lim_send_sme_disassoc_deauth_ntf(a1, 0, v27);
    }
    goto LABEL_15;
  }
  if ( (unsigned int)(*(_DWORD *)(v22 + 72) - 9) <= 1 )
  {
    lim_send_deauth_mgmt_frame(a1, *((unsigned __int16 *)a2 + 3), a2, v22, 0);
    HIDWORD(v60) = 0;
    v31 = *(_WORD *)(v22 + 8);
    *(_DWORD *)(v22 + 72) = 1;
    qdf_trace(53, 0, v31, 1);
LABEL_36:
    v52 = *((_WORD *)a2 + 2);
    v53 = *((_DWORD *)a2 + 2);
    v59 = *(_DWORD *)a2;
    v54 = a2[12];
    LOWORD(v60) = v52;
    LODWORD(v61) = v53;
    BYTE4(v61) = v54;
    _qdf_mem_free((__int64)a2);
    result = lim_process_mlm_rsp_messages(a1, 1018, &v59);
    goto LABEL_37;
  }
LABEL_18:
  v32 = dph_lookup_hash_entry(v12, v13, v14, v15, v16, v17, v18, v19, a1, a2, v58, v22 + 360);
  if ( !v32 )
  {
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3234LL) == 1 && *(_DWORD *)a2 == -1 && *((__int16 *)a2 + 2) == -1 )
    {
      if ( *(_WORD *)(v22 + 376) )
      {
        v55 = 0;
        do
        {
          hash_entry = dph_get_hash_entry(a1, v55, v22 + 360);
          if ( hash_entry )
          {
            *(_DWORD *)(hash_entry + 24) = *((unsigned __int16 *)a2 + 3);
            v57 = *((_WORD *)a2 + 4);
            *(_DWORD *)(hash_entry + 8) = 22;
            *(_WORD *)(hash_entry + 34) = v57;
          }
          ++v55;
        }
        while ( *(unsigned __int16 *)(v22 + 376) > (unsigned int)v55 );
      }
      goto LABEL_21;
    }
    if ( lim_search_pre_auth_list(a1, a2) )
    {
      HIDWORD(v60) = 0;
      lim_delete_pre_auth_node(a1, a2);
      lim_send_deauth_mgmt_frame(a1, *((unsigned __int16 *)a2 + 3), a2, v22, 0);
      goto LABEL_36;
    }
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: rcvd MLM_DEAUTH_REQ in mlme state %d STA does not have context, Addr=%02x:%02x:%02x:**:**:%02x",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "lim_process_mlm_deauth_req_ntf",
      *(unsigned int *)(v22 + 72),
      *a2,
      a2[1],
      a2[2],
      a2[5]);
    goto LABEL_34;
  }
  if ( (*(_DWORD *)(v32 + 8) & 0xFFFFFFFE) != 0xE )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Invalid MLM_DEAUTH_REQ, Addr=%02x:%02x:%02x:**:**:%02x",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "lim_process_mlm_deauth_req_ntf",
      *a2,
      a2[1],
      a2[2],
      a2[5]);
    v51 = 500;
LABEL_35:
    HIDWORD(v60) = v51;
    goto LABEL_36;
  }
  *(_DWORD *)(v32 + 24) = *((unsigned __int16 *)a2 + 3);
  v41 = *((_WORD *)a2 + 4);
  *(_DWORD *)(v32 + 8) = 22;
  *(_WORD *)(v32 + 34) = v41;
LABEL_21:
  if ( *(_QWORD *)(a1 + 12400) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: pMlmDeauthReq is not NULL, freeing",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "lim_process_mlm_deauth_req_ntf");
    _qdf_mem_free(*(_QWORD *)(a1 + 12400));
  }
  *(_QWORD *)(a1 + 12400) = a2;
  result = lim_send_deauth_mgmt_frame(a1, *((unsigned __int16 *)a2 + 3), a2, v22, 1);
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
