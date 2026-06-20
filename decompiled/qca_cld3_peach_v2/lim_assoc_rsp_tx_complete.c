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
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned __int8 *v47; // x24
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  _WORD *v56; // x0
  _WORD *v57; // x25
  char v58; // w8
  __int64 v59; // [xsp+0h] [xbp-40h] BYREF
  _WORD *v60; // [xsp+8h] [xbp-38h]
  __int64 v61; // [xsp+10h] [xbp-30h]
  __int64 v62; // [xsp+18h] [xbp-28h]
  __int64 v63; // [xsp+20h] [xbp-20h]
  __int64 v64; // [xsp+28h] [xbp-18h]
  __int64 v65; // [xsp+30h] [xbp-10h] BYREF
  __int64 v66; // [xsp+38h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v65) = 0;
  LOWORD(v65) = 0;
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = nullptr;
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
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66);
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
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66);
LABEL_14:
    _qdf_nbuf_free(a2);
    goto LABEL_15;
  }
  session_by_bssid = pe_find_session_by_bssid(a1, v11 + 10, (char *)&v65 + 4);
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
          &v65,
          session_by_bssid + 360);
  if ( !v17 )
  {
    v29 = "%s: sta_ds is NULL";
    goto LABEL_13;
  }
  v18 = v17;
  v19 = *(_QWORD *)(*(_QWORD *)(v16 + 384) + 8LL * *(unsigned __int16 *)(v17 + 348));
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
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66);
    goto LABEL_14;
  }
  if ( !a3 )
  {
    if ( (lim_is_mlo_conn(v16, v17) & 1) != 0 && (unsigned int)lim_mlo_assoc_ind_upper_layer(a1, v16, v19 + 3576) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: partner link indicate upper layer error",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "lim_assoc_rsp_tx_complete",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66);
    }
    else
    {
      v38 = _qdf_mem_malloc(0xB58u, "lim_assoc_rsp_tx_complete", 1955);
      if ( v38 )
      {
        v47 = (unsigned __int8 *)v38;
        if ( (lim_fill_lim_assoc_ind_params(v38, a1, v18, v16, v39, v40, v41, v42, v43, v44, v45, v46) & 1) != 0 )
        {
          v56 = (_WORD *)_qdf_mem_malloc(0xB90u, "lim_assoc_rsp_tx_complete", 1965);
          if ( v56 )
          {
            v57 = v56;
            *v56 = 5156;
            lim_fill_sme_assoc_ind_params(a1, v47, (__int64)v56, v16, 1);
            *((_BYTE *)v57 + 2950) = *(_BYTE *)(v18 + 367);
            v57[1476] = *(unsigned __int8 *)(v18 + 924);
            qdf_mem_set(&v59, 0x30u, 0);
            v58 = *(_BYTE *)(v18 + 32);
            v60 = v57;
            LOWORD(v59) = 5156;
            HIDWORD(v59) = 0;
            *((_BYTE *)v57 + 2739) = v58 & 1;
            *((_BYTE *)v57 + 2752) = *(_BYTE *)(v18 + 656);
            mac_trace_msg_tx(a1, *(unsigned __int8 *)(v16 + 8), 5156);
            sys_process_mmh_msg(a1, &v59);
            _qdf_mem_free((__int64)v47);
            goto LABEL_8;
          }
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: lim assoc ind fill error",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "lim_assoc_rsp_tx_complete",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66);
        }
        _qdf_mem_free((__int64)v47);
      }
    }
    lim_free_assoc_req_frm_buf(v19);
    _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v16 + 384) + 8LL * *(unsigned __int16 *)(v18 + 348)));
    *(_QWORD *)(*(_QWORD *)(v16 + 384) + 8LL * *(unsigned __int16 *)(v18 + 348)) = 0;
    goto LABEL_14;
  }
  lim_send_disassoc_mgmt_frame(a1, 4, v17 + 350, v16, 0);
  lim_trigger_sta_deletion(a1, v18, v16, v20, v21, v22, v23, v24, v25, v26, v27);
LABEL_8:
  lim_free_assoc_req_frm_buf(v19);
  _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v16 + 384) + 8LL * *(unsigned __int16 *)(v18 + 348)));
  *(_QWORD *)(*(_QWORD *)(v16 + 384) + 8LL * *(unsigned __int16 *)(v18 + 348)) = 0;
  _qdf_nbuf_free(a2);
  result = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
