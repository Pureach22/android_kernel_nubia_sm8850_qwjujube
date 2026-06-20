__int64 __fastcall cm_disconnect_start_req(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0
  __int64 v5; // x9
  __int64 v6; // x10
  int v7; // w8
  __int64 v8; // x20
  __int64 result; // x0
  unsigned int v10; // w19

  if ( !cm_get_cm_ctx_fl(a1, "cm_disconnect_start_req", 829) )
    return 4;
  v4 = _qdf_mem_malloc(0x380u, "cm_disconnect_start_req", 837);
  if ( !v4 )
    return 2;
  v6 = *a2;
  v5 = a2[1];
  v7 = *((_DWORD *)a2 + 4);
  v8 = v4;
  *(_DWORD *)(v4 + 44) = v7;
  *(_QWORD *)(v4 + 36) = v5;
  *(_QWORD *)(v4 + 28) = v6;
  result = cm_sm_deliver_event(a1, 13, 24, v4 + 24);
  if ( (_DWORD)result )
  {
    v10 = result;
    _qdf_mem_free(v8);
    return v10;
  }
  return result;
}
