__int64 __fastcall lim_process_mlm_del_all_sta_rsp(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w19
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  _QWORD *v20; // x22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 session_by_vdev_id; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 result; // x0
  _QWORD v39[7]; // [xsp+8h] [xbp-38h] BYREF

  v39[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL);
  context = _cds_get_context(53, (__int64)"lim_process_mlm_del_all_sta_rsp", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    goto LABEL_9;
  v19 = (__int64)context;
  v20 = context + 1024;
  context[1111] = "lim_process_mlm_del_all_sta_rsp";
  *((_BYTE *)context + 8885) = 1;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Defer LIM msg %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "lim_process_mlm_del_all_sta_rsp",
    1);
  memset(v39, 0, 48);
  if ( *((_BYTE *)v20 + 693) )
  {
    if ( *((_WORD *)v20 + 248) )
    {
      LOWORD(v39[0]) = 5119;
      if ( (unsigned int)lim_post_msg_api(v19, (unsigned __int16 *)v39) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to post lim msg:0x%x",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "lim_post_msg_to_process_deferred_queue",
          LOWORD(v39[0]));
    }
  }
  session_by_vdev_id = pe_find_session_by_vdev_id(v19, v9);
  if ( !session_by_vdev_id )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session Doesn't exist: %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "lim_process_mlm_del_all_sta_rsp",
      v9);
LABEL_9:
    result = 4;
    goto LABEL_10;
  }
  lim_prepare_and_send_del_all_sta_cnf(v19, 0, session_by_vdev_id);
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
