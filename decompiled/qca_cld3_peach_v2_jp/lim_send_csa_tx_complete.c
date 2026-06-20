_BYTE *__fastcall lim_send_csa_tx_complete(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x21
  __int64 session_by_vdev_id; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x19
  __int64 v30; // x20
  _BYTE *result; // x0
  char v32; // w8
  __int64 v33; // x20
  __int64 v34; // [xsp+8h] [xbp-38h] BYREF
  _BYTE *v35; // [xsp+10h] [xbp-30h]
  __int64 v36; // [xsp+18h] [xbp-28h]
  __int64 v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+28h] [xbp-18h]
  __int64 v39; // [xsp+30h] [xbp-10h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = nullptr;
  context = _cds_get_context(53, (__int64)"lim_send_csa_tx_complete", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = context;
    session_by_vdev_id = pe_find_session_by_vdev_id((__int64)context, a1, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( session_by_vdev_id )
    {
      v29 = session_by_vdev_id;
      v30 = session_by_vdev_id + 4096;
      if ( (*(_BYTE *)(v19[2694] + 23LL) & 2) != 0 )
        qdf_mc_timer_stop(session_by_vdev_id + 8232);
      *(_BYTE *)(v30 + 3120) = 0;
      if ( !*((_BYTE *)v19 + 14811) )
        *(_BYTE *)(v30 + 3128) = 0;
      *(_WORD *)(v30 + 3186) = 0;
      result = (_BYTE *)_qdf_mem_malloc(2u, "lim_send_csa_tx_complete", 10410);
      if ( result )
      {
        v32 = *(_BYTE *)(v29 + 10);
        v33 = (__int64)result;
        result[1] = 0;
        *result = v32;
        v35 = result;
        LOWORD(v34) = 5208;
        result = (_BYTE *)scheduler_post_message_debug(
                            0x35u,
                            0x34u,
                            52,
                            (unsigned __int16 *)&v34,
                            0x28B5u,
                            (__int64)"lim_send_csa_tx_complete");
        if ( (_DWORD)result )
          result = (_BYTE *)_qdf_mem_free(v33);
      }
    }
    else
    {
      result = (_BYTE *)qdf_trace_msg(
                          0x35u,
                          2u,
                          "%s: Session does not exist for given vdev_id %d",
                          v21,
                          v22,
                          v23,
                          v24,
                          v25,
                          v26,
                          v27,
                          v28,
                          "lim_send_csa_tx_complete",
                          a1);
    }
  }
  else
  {
    result = (_BYTE *)qdf_trace_msg(
                        0x68u,
                        2u,
                        "%s: Invalid mac context",
                        v11,
                        v12,
                        v13,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        "lim_send_csa_tx_complete");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
