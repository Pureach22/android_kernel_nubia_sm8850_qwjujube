__int64 __fastcall lim_assoc_rsp_tx_complete(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x21
  __int64 session_by_bssid; // x0
  __int64 v16; // x20
  __int64 v17; // x0
  __int64 v18; // x21
  __int64 v19; // x23
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 result; // x0
  const char *v29; // x2
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned __int8 *v39; // x24
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  _WORD *v48; // x0
  _WORD *v49; // x25
  char v50; // w8
  __int64 v51; // [xsp+0h] [xbp-40h] BYREF
  _WORD *v52; // [xsp+8h] [xbp-38h]
  __int64 v53; // [xsp+10h] [xbp-30h]
  __int64 v54; // [xsp+18h] [xbp-28h]
  __int64 v55; // [xsp+20h] [xbp-20h]
  __int64 v56; // [xsp+28h] [xbp-18h]
  __int64 v57; // [xsp+30h] [xbp-10h] BYREF
  __int64 v58; // [xsp+38h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v57) = 0;
  LOWORD(v57) = 0;
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = nullptr;
  if ( !a2 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Assoc rsp frame buffer is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_assoc_rsp_tx_complete",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58);
LABEL_15:
    result = 16;
    goto LABEL_16;
  }
  v11 = *(_QWORD *)(a2 + 224);
  if ( !v11 )
  {
    v29 = "%s: Assoc rsp frame is NULL";
LABEL_13:
    qdf_trace_msg(
      0x35u,
      2u,
      v29,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_assoc_rsp_tx_complete",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58);
LABEL_14:
    _qdf_nbuf_free(a2);
    goto LABEL_15;
  }
  session_by_bssid = pe_find_session_by_bssid(a1, v11 + 10, (char *)&v57 + 4);
  if ( !session_by_bssid )
  {
    v29 = "%s: session entry is NULL";
    goto LABEL_13;
  }
  v16 = session_by_bssid;
  v17 = dph_lookup_hash_entry(
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a1,
          (unsigned __int8 *)(v11 + 4),
          &v57,
          session_by_bssid + 360);
  if ( !v17 )
  {
    v29 = "%s: sta_ds is NULL";
    goto LABEL_13;
  }
  v18 = v17;
  v19 = *(_QWORD *)(*(_QWORD *)(v16 + 384) + 8LL * *(unsigned __int16 *)(v17 + 336));
  if ( !v19 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: assoc req for assoc_id:%d is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_assoc_rsp_tx_complete",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58);
    goto LABEL_14;
  }
  if ( !a3 )
  {
    v30 = _qdf_mem_malloc(0xB50u, "lim_assoc_rsp_tx_complete", 1955);
    if ( v30 )
    {
      v39 = (unsigned __int8 *)v30;
      if ( (lim_fill_lim_assoc_ind_params(v30, a1, v18, v16, v31, v32, v33, v34, v35, v36, v37, v38) & 1) != 0 )
      {
        v48 = (_WORD *)_qdf_mem_malloc(0xB90u, "lim_assoc_rsp_tx_complete", 1965);
        if ( v48 )
        {
          v49 = v48;
          *v48 = 5156;
          lim_fill_sme_assoc_ind_params(a1, v39, (__int64)v48, v16, 1);
          *((_BYTE *)v49 + 2950) = *(_BYTE *)(v18 + 355);
          v49[1476] = *(unsigned __int8 *)(v18 + 896);
          qdf_mem_set(&v51, 0x30u, 0);
          v50 = *(_BYTE *)(v18 + 32);
          v52 = v49;
          LOWORD(v51) = 5156;
          HIDWORD(v51) = 0;
          *((_BYTE *)v49 + 2739) = v50 & 1;
          *((_BYTE *)v49 + 2752) = *(_BYTE *)(v18 + 640);
          mac_trace_msg_tx(a1, *(unsigned __int8 *)(v16 + 8), 5156);
          sys_process_mmh_msg(a1, &v51);
          _qdf_mem_free((__int64)v39);
          goto LABEL_8;
        }
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: lim assoc ind fill error",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "lim_assoc_rsp_tx_complete",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58);
      }
      _qdf_mem_free((__int64)v39);
    }
    lim_free_assoc_req_frm_buf(v19);
    _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v16 + 384) + 8LL * *(unsigned __int16 *)(v18 + 336)));
    *(_QWORD *)(*(_QWORD *)(v16 + 384) + 8LL * *(unsigned __int16 *)(v18 + 336)) = 0;
    goto LABEL_14;
  }
  lim_send_disassoc_mgmt_frame(a1, 4, v17 + 338, v16, 0);
  lim_trigger_sta_deletion(a1, v18, v16, v20, v21, v22, v23, v24, v25, v26, v27);
LABEL_8:
  lim_free_assoc_req_frm_buf(v19);
  _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v16 + 384) + 8LL * *(unsigned __int16 *)(v18 + 336)));
  *(_QWORD *)(*(_QWORD *)(v16 + 384) + 8LL * *(unsigned __int16 *)(v18 + 336)) = 0;
  _qdf_nbuf_free(a2);
  result = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
