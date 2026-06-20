__int64 __fastcall lim_process_mlm_del_sta_rsp(
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
  __int64 v10; // x21
  __int64 v13; // x22
  int v14; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 session_by_session_id; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  __int64 result; // x0
  _QWORD v34[7]; // [xsp+8h] [xbp-38h] BYREF

  v34[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a2 + 8);
  if ( v10 )
  {
    v13 = a1 + 0x2000;
    *(_QWORD *)(a1 + 8888) = "lim_process_mlm_del_sta_rsp";
    *(_BYTE *)(a1 + 8885) = 1;
    qdf_trace_msg(0x35u, 8u, "%s: Defer LIM msg %d", a3, a4, a5, a6, a7, a8, a9, a10);
    v14 = *(unsigned __int8 *)(v13 + 693);
    memset(v34, 0, 48);
    if ( v14 )
    {
      if ( *(_WORD *)(v13 + 496) )
      {
        LOWORD(v34[0]) = 5119;
        if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v34) )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to post lim msg:0x%x",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "lim_post_msg_to_process_deferred_queue",
            LOWORD(v34[0]));
      }
    }
    session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(v10 + 9));
    if ( session_by_session_id )
    {
      v32 = *(_DWORD *)(session_by_session_id + 88);
      if ( v32 == 6 )
      {
        result = lim_process_ndi_del_sta_rsp(a1, a2, session_by_session_id);
      }
      else if ( v32 == 1 )
      {
        result = lim_process_ap_mlm_del_sta_rsp(a1, a2, session_by_session_id);
      }
      else
      {
        result = lim_process_sta_mlm_del_sta_rsp(a1, a2, session_by_session_id);
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Session Doesn't exist: %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "lim_process_mlm_del_sta_rsp",
        *(unsigned __int8 *)(v10 + 9));
      result = _qdf_mem_free(v10);
      *(_QWORD *)(a2 + 8) = 0;
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: null pointer del_sta_params msg",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_process_mlm_del_sta_rsp");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
