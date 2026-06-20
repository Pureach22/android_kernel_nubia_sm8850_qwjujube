__int64 __fastcall lim_process_ft_aggr_qos_rsp(
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
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w8
  unsigned __int16 *v30; // x20
  __int64 session_by_session_id; // x0
  __int64 v32; // x21
  __int64 v33; // x23
  __int64 v34; // x25
  unsigned int v35; // w8
  char v36; // w10
  char v37; // w11
  __int64 v38; // x10
  __int64 v39; // x12
  __int64 v40; // x11
  __int64 v41; // x13
  __int64 v42; // x12
  __int64 v43; // x9
  __int64 v44; // x11
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  const char *v61; // x2
  __int64 result; // x0
  _DWORD v63[17]; // [xsp+Ch] [xbp-94h] BYREF
  __int64 v64; // [xsp+50h] [xbp-50h]
  int v65; // [xsp+58h] [xbp-48h]
  _QWORD v66[6]; // [xsp+60h] [xbp-40h] BYREF
  int v67; // [xsp+90h] [xbp-10h] BYREF
  __int16 v68; // [xsp+94h] [xbp-Ch]
  __int64 v69; // [xsp+98h] [xbp-8h]

  v12 = a1 + 0x2000;
  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v65 = 0;
  v64 = 0;
  memset(&v63[1], 0, 64);
  LOWORD(v63[0]) = 0;
  v68 = 0;
  v67 = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s:  Received AGGR_QOS_RSP from HAL",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "lim_process_ft_aggr_qos_rsp");
  *(_BYTE *)(v12 + 693) = 1;
  *(_QWORD *)(a1 + 8888) = "lim_process_ft_aggr_qos_rsp";
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Defer LIM msg %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "lim_process_ft_aggr_qos_rsp",
    1);
  v29 = *(unsigned __int8 *)(v12 + 693);
  memset(v66, 0, sizeof(v66));
  if ( v29 )
  {
    if ( *(_WORD *)(v12 + 496) )
    {
      LOWORD(v66[0]) = 5119;
      if ( (unsigned int)lim_post_msg_api(a1, (unsigned __int16 *)v66) )
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
          LOWORD(v66[0]));
    }
  }
  v30 = *(unsigned __int16 **)(a2 + 8);
  if ( v30 )
  {
    session_by_session_id = pe_find_session_by_session_id(a1, *((unsigned __int8 *)v30 + 252));
    if ( !session_by_session_id )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Cant find session entry",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "lim_process_ft_aggr_qos_rsp");
LABEL_19:
      result = _qdf_mem_free((__int64)v30);
      goto LABEL_20;
    }
    v32 = session_by_session_id;
    if ( *(_DWORD *)(session_by_session_id + 88) == 2 )
    {
      v33 = 0;
      v34 = 1;
      do
      {
        v35 = *v30;
        if ( ((v35 >> v33) & 1) != 0 )
        {
          if ( *(_DWORD *)&v30[2 * v33 + 118] )
          {
            v36 = *((_BYTE *)v30 + 252);
            v67 = *(_DWORD *)(v32 + 24);
            LOBYTE(v68) = *(_BYTE *)(v32 + 28);
            v37 = *(_BYTE *)(v32 + 29);
            BYTE4(v64) = v36;
            v39 = *(_QWORD *)&v30[v34 + 8];
            v38 = *(_QWORD *)&v30[v34 + 12];
            HIBYTE(v68) = v37;
            v41 = *(_QWORD *)&v30[v34];
            v40 = *(_QWORD *)&v30[v34 + 4];
            *(_QWORD *)&v63[6] = v39;
            *(_QWORD *)&v63[8] = v38;
            *(_QWORD *)&v63[2] = v41;
            *(_QWORD *)&v63[4] = v40;
            LOWORD(v38) = v30[v34 + 28];
            v42 = *(_QWORD *)&v30[v34 + 16];
            v43 = *(_QWORD *)&v30[v34 + 20];
            v44 = *(_QWORD *)&v30[v34 + 24];
            HIWORD(v63[1]) = v35;
            LOWORD(v63[16]) = v38;
            *(_QWORD *)&v63[10] = v42;
            *(_QWORD *)&v63[12] = v43;
            *(_QWORD *)&v63[14] = v44;
            v45 = lim_send_delts_req_action_frame(a1, &v67, 1, (char *)&v63[2] + 2, &v63[2], v32);
            if ( dph_lookup_hash_entry(
                   v45,
                   v46,
                   v47,
                   v48,
                   v49,
                   v50,
                   v51,
                   v52,
                   a1,
                   (unsigned __int8 *)&v67,
                   v63,
                   v32 + 360) )
            {
              lim_admit_control_delete_ts(
                a1,
                v63[0],
                (__int64)&v63[2] + 2,
                nullptr,
                (_BYTE *)&v63[1] + 2,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60);
            }
          }
        }
        ++v33;
        v34 += 29;
      }
      while ( v33 != 4 );
      lim_ft_send_aggr_qos_rsp(a1, v30, *(unsigned __int8 *)(v32 + 10));
      goto LABEL_19;
    }
    v61 = "%s: pe_session is not in STA mode";
  }
  else
  {
    v61 = "%s: NULL pAggrQosRspMsg";
  }
  result = qdf_trace_msg(0x35u, 2u, v61, v21, v22, v23, v24, v25, v26, v27, v28, "lim_process_ft_aggr_qos_rsp");
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
