__int64 __fastcall _lim_process_sme_delts_req(__int64 a1, __int64 a2)
{
  unsigned int v4; // w20
  unsigned __int8 *session_by_bssid; // x22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x23
  unsigned int v26; // w8
  int v27; // w9
  unsigned int v28; // w8
  int v29; // w8
  unsigned __int8 v30; // w10
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  _BYTE v40[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v41; // [xsp+10h] [xbp-10h] BYREF
  __int16 v42; // [xsp+14h] [xbp-Ch]
  __int64 v43; // [xsp+18h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a2 + 4);
  v42 = 0;
  v41 = 0;
  v40[0] = 0;
  session_by_bssid = (unsigned __int8 *)pe_find_session_by_bssid(a1, a2 + 5, v40);
  if ( !session_by_bssid )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session Does not exist for given bssId",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "__lim_process_sme_delts_req");
LABEL_18:
    v22 = a1;
    v23 = a2;
    v24 = 0;
    goto LABEL_19;
  }
  lim_diag_event_report(a1, 31, session_by_bssid, 0);
  if ( !(unsigned int)lim_validate_delts_req(a1, a2, &v41, session_by_bssid) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sent DELTS request to station with assocId = %d MacAddr = %02x:%02x:%02x:**:**:%02x",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "__lim_process_sme_delts_req",
      *(unsigned __int16 *)(a2 + 12),
      (unsigned __int8)v41,
      BYTE1(v41),
      BYTE2(v41),
      HIBYTE(v42));
    v25 = a2 + 21;
    lim_send_delts_req_action_frame(a1, &v41, *(_BYTE *)(a2 + 83) & 1, a2 + 21, a2 + 25, session_by_bssid);
    if ( (*(_BYTE *)(a2 + 83) & 1) != 0 )
      v25 = a2 + 27;
    lim_set_tspec_uapsd_mask_per_session(a1, session_by_bssid, v25, 0);
    v26 = *(unsigned __int16 *)(v25 + 1);
    v27 = (v26 >> 5) & 3;
    v28 = 0x33220110u >> ((v26 >> 9) & 0x1C);
    if ( v27 == 3 )
    {
      v29 = 1 << (v28 & 3);
      v30 = session_by_bssid[7277] & ~(_BYTE)v29;
      LOBYTE(v29) = session_by_bssid[7278] & ~(_BYTE)v29;
      session_by_bssid[7277] = v30;
    }
    else
    {
      if ( v27 != 1 )
      {
        if ( !v27 )
          session_by_bssid[7277] &= ~(1 << (v28 & 3));
        goto LABEL_14;
      }
      v29 = session_by_bssid[7278] & ~(1 << (v28 & 3));
    }
    session_by_bssid[7278] = v29;
LABEL_14:
    lim_set_active_edca_params(a1, session_by_bssid + 7096, session_by_bssid);
    if ( dph_get_hash_entry(a1, 1u, (__int64)(session_by_bssid + 360)) )
      lim_send_edca_params(a1, session_by_bssid + 7136, session_by_bssid[10], 0);
    else
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Self entry missing in Hash Table",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "__lim_process_sme_delts_req");
    lim_send_sme_tsm_ie_ind(a1, (__int64)session_by_bssid, 0, 0, 0);
    goto LABEL_18;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: lim_validate_delts_req failed",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "__lim_process_sme_delts_req");
  v22 = a1;
  v23 = a2;
  v24 = 16;
LABEL_19:
  result = lim_send_sme_delts_rsp(v22, v23, v24, session_by_bssid, v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
