__int64 __fastcall lim_send_hal_msg_add_ts(__int64 a1, unsigned __int8 a2, const void *a3, unsigned int a4, __int16 a5)
{
  __int64 session_by_session_id; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x25
  __int64 v20; // x0
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  char v30; // w8
  int v31; // w8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 result; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // w8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // [xsp+8h] [xbp-68h] BYREF
  __int64 v67; // [xsp+10h] [xbp-60h]
  __int64 v68; // [xsp+18h] [xbp-58h]
  __int64 v69; // [xsp+20h] [xbp-50h]
  __int64 v70; // [xsp+28h] [xbp-48h]
  __int64 v71; // [xsp+30h] [xbp-40h]
  __int64 v72; // [xsp+38h] [xbp-38h] BYREF
  __int64 v73; // [xsp+40h] [xbp-30h]
  __int64 v74; // [xsp+48h] [xbp-28h]
  __int64 v75; // [xsp+50h] [xbp-20h]
  __int64 v76; // [xsp+58h] [xbp-18h]
  __int64 v77; // [xsp+60h] [xbp-10h]
  __int64 v78; // [xsp+68h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v70 = 0;
  v71 = 0;
  v68 = 0;
  v69 = 0;
  v66 = 0;
  v67 = 0;
  session_by_session_id = pe_find_session_by_session_id(a1, a4);
  if ( !session_by_session_id )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Unable to get Session for session Id: %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "lim_send_hal_msg_add_ts",
      (unsigned __int8)a4);
LABEL_17:
    result = 16;
    goto LABEL_19;
  }
  v19 = session_by_session_id;
  v20 = _qdf_mem_malloc(0x4Cu, "lim_send_hal_msg_add_ts", 829);
  if ( !v20 )
  {
    result = 2;
    goto LABEL_19;
  }
  v21 = v20;
  *(_WORD *)(v20 + 2) = a2;
  qdf_mem_copy((void *)(v20 + 4), a3, 0x3Au);
  *(_BYTE *)(v21 + 68) = a4;
  v30 = *(_BYTE *)(v19 + 10);
  *(_WORD *)(v21 + 70) = a5;
  *(_BYTE *)v21 = v30;
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1510LL) == 1 && *(_BYTE *)(v19 + 7041) == 1 )
    *(_BYTE *)(v21 + 72) = 1;
  v67 = v21;
  LOWORD(v66) = 4154;
  HIDWORD(v66) = 0;
  *(_BYTE *)(a1 + 8885) = 0;
  *(_QWORD *)(a1 + 8888) = "lim_send_hal_msg_add_ts";
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", v22, v23, v24, v25, v26, v27, v28, v29, "lim_send_hal_msg_add_ts", 0);
  v31 = *(unsigned __int8 *)(a1 + 8885);
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  if ( v31 )
  {
    if ( *(_WORD *)(a1 + 8688) )
    {
      LOWORD(v72) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, &v72) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "lim_post_msg_to_process_deferred_queue",
          (unsigned __int16)v72);
    }
  }
  mac_trace_msg_tx(a1, a4, 4154);
  result = wma_post_ctrl_msg(a1, &v66);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: wma_post_ctrl_msg() failed",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "lim_send_hal_msg_add_ts");
    *(_BYTE *)(a1 + 8885) = 1;
    *(_QWORD *)(a1 + 8888) = "lim_send_hal_msg_add_ts";
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Defer LIM msg %d",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "lim_send_hal_msg_add_ts",
      1);
    v57 = *(unsigned __int8 *)(a1 + 8885);
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    if ( v57 )
    {
      if ( *(_WORD *)(a1 + 8688) )
      {
        LOWORD(v72) = 5119;
        if ( (unsigned int)lim_post_msg_api(a1, &v72) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to post lim msg:0x%x",
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            "lim_post_msg_to_process_deferred_queue",
            (unsigned __int16)v72);
      }
    }
    _qdf_mem_free(v21);
    goto LABEL_17;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
