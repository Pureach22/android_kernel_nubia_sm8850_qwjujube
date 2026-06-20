__int64 __fastcall cm_store_first_candidate_rsp(__int64 result, unsigned int a2, __int64 a3)
{
  __int64 v3; // x19
  _QWORD *v6; // x1
  __int64 v7; // x23
  __int64 v8; // x0
  unsigned __int8 *v9; // x22
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _QWORD *v18; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v19[2]; // [xsp+20h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  v18 = nullptr;
  if ( (a2 & 0xF000000) == 0xC000000 )
  {
    v3 = result;
    qdf_mutex_acquire(result + 120);
    qdf_list_peek_front((_QWORD *)(v3 + 96), v19);
    v6 = (_QWORD *)v19[0];
    if ( v19[0] )
    {
      while ( 1 )
      {
        qdf_list_peek_next((_QWORD *)(v3 + 96), v6, &v18);
        v7 = v19[0];
        if ( *(_DWORD *)(v19[0] + 16LL) == a2 )
          break;
        v6 = v18;
        v18 = nullptr;
        v19[0] = v6;
        if ( !v6 )
          goto LABEL_7;
      }
      if ( !*(_QWORD *)(v19[0] + 888LL) && (*(_BYTE *)(*(_QWORD *)(v19[0] + 848LL) + 16LL) & 0xFE) != 0 )
      {
        v8 = _qdf_mem_malloc(0xA0u, "cm_store_first_candidate_rsp", 2252);
        if ( v8 )
        {
          v9 = (unsigned __int8 *)v8;
          cm_copy_rsp_from_rsp(v8, a3);
          *(_QWORD *)(v7 + 888) = v9;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: vdev %d cm_id 0x%x:  %02x:%02x:%02x:**:**:%02x with reason %d",
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            "cm_store_first_candidate_rsp",
            *v9,
            a2,
            v9[8],
            v9[9],
            v9[10],
            v9[13],
            *((_DWORD *)v9 + 14));
        }
      }
    }
LABEL_7:
    result = qdf_mutex_release(v3 + 120);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
