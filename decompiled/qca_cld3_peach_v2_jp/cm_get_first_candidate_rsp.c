__int64 __fastcall cm_get_first_candidate_rsp(__int64 a1, unsigned int a2, unsigned __int8 *a3)
{
  _QWORD *v6; // x1
  unsigned int v7; // w20
  __int64 v8; // x1
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _QWORD *v18; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v19[2]; // [xsp+20h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  v18 = nullptr;
  if ( (a2 & 0xF000000) == 0xC000000 )
  {
    qdf_mutex_acquire(a1 + 120);
    qdf_list_peek_front((_QWORD *)(a1 + 96), v19);
    v6 = (_QWORD *)v19[0];
    if ( !v19[0] )
      goto LABEL_9;
    while ( 1 )
    {
      qdf_list_peek_next((_QWORD *)(a1 + 96), v6, &v18);
      if ( *(_DWORD *)(v19[0] + 16LL) == a2 )
        break;
      v6 = v18;
      v18 = nullptr;
      v19[0] = v6;
      if ( !v6 )
        goto LABEL_9;
    }
    v8 = *(_QWORD *)(v19[0] + 888LL);
    if ( v8 )
    {
      cm_copy_rsp_from_rsp((__int64)a3, v8);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d cm_id 0x%x:  %02x:%02x:%02x:**:**:%02xwith reason %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "cm_get_first_candidate_rsp",
        *a3,
        a2,
        a3[8],
        a3[9],
        a3[10],
        a3[13],
        *((_DWORD *)a3 + 14));
      v7 = 0;
    }
    else
    {
LABEL_9:
      v7 = 16;
    }
    qdf_mutex_release(a1 + 120);
  }
  else
  {
    v7 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
