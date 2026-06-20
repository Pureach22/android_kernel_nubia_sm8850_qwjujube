__int64 __fastcall dlm_flush_reject_ap_list(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *i; // x1
  _QWORD *v20; // x20
  _QWORD *v21; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v22[2]; // [xsp+10h] [xbp-10h] BYREF

  v22[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = nullptr;
  v22[0] = nullptr;
  if ( (unsigned int)qdf_mutex_acquire(a1) )
  {
    result = qdf_trace_msg(
               0x6Du,
               2u,
               "%s: failed to acquire reject_ap_list_lock",
               v2,
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               "dlm_flush_reject_ap_list");
  }
  else
  {
    qdf_list_peek_front((_QWORD *)(a1 + 64), v22);
    for ( i = v22[0]; i; v22[0] = i )
    {
      qdf_list_peek_next((_QWORD *)(a1 + 64), i, &v21);
      v20 = v22[0];
      qdf_list_remove_node(a1 + 64, v22[0]);
      _qdf_mem_free((__int64)v20);
      i = v21;
      v21 = nullptr;
    }
    qdf_trace_msg(
      0x6Du,
      8u,
      "%s: DLM reject ap list flushed",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "dlm_flush_reject_ap_list");
    result = qdf_mutex_release(a1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
