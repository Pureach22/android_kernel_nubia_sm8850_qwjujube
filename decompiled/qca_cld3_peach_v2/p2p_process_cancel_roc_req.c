__int64 __fastcall p2p_process_cancel_roc_req(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x20
  _QWORD *v11; // x21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  _QWORD *v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w8
  int v31; // [xsp+0h] [xbp-20h]
  int v32; // [xsp+8h] [xbp-18h]
  _QWORD *v33[2]; // [xsp+10h] [xbp-10h] BYREF

  v33[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v11 = (_QWORD *)a1[1];
  v33[0] = nullptr;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: p2p soc obj:%pK, cookie:%llx",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "p2p_find_roc_ctx",
    v10,
    v11);
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(v10 + 8), v33) )
    goto LABEL_2;
  while ( v11 != v33[0] )
  {
    if ( (unsigned int)qdf_list_peek_next((_QWORD *)(v10 + 8), v33[0], v33) )
      goto LABEL_2;
  }
  if ( !v33[0] )
  {
LABEL_2:
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: Failed to find roc req by cookie, cookie %llx",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "p2p_process_cancel_roc_req",
      a1[1]);
    result = 4;
  }
  else
  {
    v21 = v33[0];
    v32 = *((_DWORD *)v33[0] + 60);
    v31 = *((_DWORD *)v33[0] + 56);
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: roc ctx:%pK vdev_id:%d, scan_id:%d, roc_type:%d, roc_state:%d opmode:%d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "p2p_process_cancel_roc_req",
      v33[0],
      *((unsigned int *)v33[0] + 6),
      *((unsigned int *)v33[0] + 7),
      *((unsigned int *)v33[0] + 13),
      v31,
      v32);
    v30 = *((_DWORD *)v21 + 56);
    if ( v30 == 4 )
    {
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: Receive cancel roc req when roc req is canceling, cookie %llx",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "p2p_process_cancel_roc_req",
        a1[1]);
      result = 0;
    }
    else if ( v30 )
    {
      result = p2p_execute_cancel_roc_req((__int64)v21, v22, v23, v24, v25, v26, v27, v28, v29);
    }
    else
    {
      result = p2p_destroy_roc_ctx((__int64)v21, 1, 1, v22, v23, v24, v25, v26, v27, v28, v29);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
