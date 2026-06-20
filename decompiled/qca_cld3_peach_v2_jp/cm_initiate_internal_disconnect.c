__int64 __fastcall cm_initiate_internal_disconnect(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x19
  char v4; // w8
  int cm_id; // w0
  __int64 v6; // x2
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  result = _qdf_mem_malloc(0x380u, "cm_initiate_internal_disconnect", 294);
  if ( result )
  {
    v3 = result;
    v4 = *(_BYTE *)(*(_QWORD *)a1 + 104LL);
    *(_DWORD *)(result + 32) = 9;
    *(_BYTE *)(result + 28) = v4;
    cm_id = cm_get_cm_id(a1, 9);
    v6 = *(unsigned int *)(v3 + 32);
    *(_DWORD *)(v3 + 16) = cm_id;
    *(_DWORD *)(v3 + 24) = cm_id;
    if ( (unsigned int)cm_add_req_to_list_and_indicate_osif(a1, v3, v6) )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: failed to add disconnect req",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "cm_initiate_internal_disconnect",
        *(unsigned __int8 *)(v3 + 28),
        *(unsigned int *)(v3 + 24));
      return _qdf_mem_free(v3);
    }
    else
    {
      return cm_disconnect_start(a1, v3 + 24);
    }
  }
  return result;
}
