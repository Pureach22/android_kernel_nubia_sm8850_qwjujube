__int64 __fastcall cm_get_req_by_cm_id_fl(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4)
{
  _QWORD *v8; // x1
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  __int64 v18; // x19
  _QWORD *v19; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = nullptr;
  v20[0] = 0;
  qdf_mutex_acquire(a1 + 120);
  qdf_list_peek_front((_QWORD *)(a1 + 96), v20);
  v8 = (_QWORD *)v20[0];
  if ( v20[0] )
  {
    while ( 1 )
    {
      qdf_list_peek_next((_QWORD *)(a1 + 96), v8, &v19);
      if ( *(_DWORD *)(v20[0] + 16LL) == a2 )
        break;
      v8 = v19;
      v19 = nullptr;
      v20[0] = v8;
      if ( !v8 )
        goto LABEL_4;
    }
    v18 = v20[0];
    qdf_mutex_release(a1 + 120);
    result = v18;
  }
  else
  {
LABEL_4:
    qdf_mutex_release(a1 + 120);
    qdf_trace_msg(
      0x68u,
      4u,
      "%s:%u: cm req not found for cm id 0x%x",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      a3,
      a4,
      a2);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
