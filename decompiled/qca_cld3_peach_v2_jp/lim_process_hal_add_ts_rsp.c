__int64 __fastcall lim_process_hal_add_ts_rsp(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  __int64 v22; // x20
  __int64 session_by_session_id; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x21
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x5
  __int64 v50; // x9
  __int64 v51; // x10
  __int64 v52; // x0
  __int64 v53; // x11
  __int64 v54; // x8
  __int64 v55; // x12
  __int64 v56; // x2
  __int64 result; // x0
  __int64 v58; // x9
  __int64 v59; // x10
  __int64 v60; // x11
  __int64 v61; // x8
  __int64 v62; // x13
  __int64 v63; // x14
  __int64 v64; // x3
  __int64 v65; // x13
  __int64 v66; // x14
  __int64 v67; // [xsp+0h] [xbp-50h] BYREF
  __int64 v68; // [xsp+8h] [xbp-48h]
  __int64 v69; // [xsp+10h] [xbp-40h]
  __int64 v70; // [xsp+18h] [xbp-38h]
  __int64 v71; // [xsp+20h] [xbp-30h]
  __int64 v72; // [xsp+28h] [xbp-28h]
  __int64 v73; // [xsp+30h] [xbp-20h]
  __int16 v74; // [xsp+38h] [xbp-18h]
  unsigned __int16 v75; // [xsp+3Ch] [xbp-14h] BYREF
  int v76; // [xsp+40h] [xbp-10h] BYREF
  __int16 v77; // [xsp+44h] [xbp-Ch]
  __int64 v78; // [xsp+48h] [xbp-8h]

  v12 = a1 + 0x2000;
  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)(a1 + 8888) = "lim_process_hal_add_ts_rsp";
  v75 = 0;
  v77 = 0;
  v76 = 0;
  *(_BYTE *)(a1 + 8885) = 1;
  qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a3, a4, a5, a6, a7, a8, a9, a10);
  v21 = *(unsigned __int8 *)(v12 + 693);
  v71 = 0;
  v72 = 0;
  v69 = 0;
  v70 = 0;
  v67 = 0;
  v68 = 0;
  if ( v21 )
  {
    if ( *(_WORD *)(v12 + 496) )
    {
      LOWORD(v67) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, &v67) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "lim_post_msg_to_process_deferred_queue",
          (unsigned __int16)v67);
    }
  }
  v22 = *(_QWORD *)(a2 + 8);
  if ( v22 )
  {
    session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(v22 + 68));
    if ( session_by_session_id )
    {
      v32 = session_by_session_id;
      if ( *(_DWORD *)(v22 + 64) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Received failure ADDTS response from HAL",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "lim_process_hal_add_ts_rsp");
        v76 = *(_DWORD *)(v32 + 24);
        v77 = *(_WORD *)(v32 + 28);
        v33 = lim_send_delts_req_action_frame(a1, &v76, 1, v22 + 6, v22 + 4, v32);
        if ( dph_lookup_hash_entry(v33, v34, v35, v36, v37, v38, v39, v40, a1, (unsigned __int8 *)&v76, &v75, v32 + 360) )
          lim_admit_control_delete_ts(
            a1,
            v75,
            v22 + 6,
            nullptr,
            (_BYTE *)(v22 + 2),
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48);
        v49 = *(unsigned __int8 *)(v32 + 10);
        v50 = *(_QWORD *)(v22 + 36);
        v51 = *(_QWORD *)(v22 + 44);
        v52 = a1;
        v53 = *(_QWORD *)(v22 + 52);
        v74 = *(_WORD *)(v22 + 60);
        v54 = *(_QWORD *)(v22 + 28);
        v55 = *(_QWORD *)(v22 + 20);
        v56 = 526;
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Received successful ADDTS response from HAL",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "lim_process_hal_add_ts_rsp");
        v49 = *(unsigned __int8 *)(v32 + 10);
        v50 = *(_QWORD *)(v22 + 36);
        v51 = *(_QWORD *)(v22 + 44);
        v52 = a1;
        v53 = *(_QWORD *)(v22 + 52);
        v74 = *(_WORD *)(v22 + 60);
        v54 = *(_QWORD *)(v22 + 28);
        v55 = *(_QWORD *)(v22 + 20);
        v56 = 0;
      }
      v65 = *(_QWORD *)(v22 + 4);
      v66 = *(_QWORD *)(v22 + 12);
      v72 = v51;
      v73 = v53;
      v69 = v55;
      v70 = v54;
      v67 = v65;
      v68 = v66;
      v71 = v50;
      v64 = v32;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Session does Not exist with given sessionId: %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "lim_process_hal_add_ts_rsp",
        *(unsigned __int8 *)(v22 + 68));
      v58 = *(_QWORD *)(v22 + 36);
      v59 = *(_QWORD *)(v22 + 44);
      v60 = *(_QWORD *)(v22 + 52);
      v52 = a1;
      v74 = *(_WORD *)(v22 + 60);
      v49 = *(unsigned __int8 *)(v12 + 508);
      v61 = *(_QWORD *)(v22 + 28);
      v56 = 526;
      v62 = *(_QWORD *)(v22 + 4);
      v63 = *(_QWORD *)(v22 + 12);
      v64 = 0;
      v69 = *(_QWORD *)(v22 + 20);
      v70 = v61;
      v67 = v62;
      v68 = v63;
      v72 = v59;
      v73 = v60;
      v71 = v58;
    }
    lim_send_sme_addts_rsp(v52, 1, v56, v64, &v67, v49);
    result = _qdf_mem_free(v22);
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Received WMA_ADD_TS_RSP with NULL",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "lim_process_hal_add_ts_rsp");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
