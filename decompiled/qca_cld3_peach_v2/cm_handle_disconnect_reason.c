__int64 __fastcall cm_handle_disconnect_reason(
        char *a1,
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
  int v11; // w8
  __int64 v12; // x19
  char v13; // w20
  __int64 result; // x0
  __int64 v15; // x2
  __int16 v16; // w8

  context = _cds_get_context(54, (__int64)"cm_handle_disconnect_reason", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 16;
  v11 = *((_DWORD *)a1 + 4);
  if ( v11 == 2 )
  {
    v12 = (__int64)context;
    v13 = *a1;
    result = _qdf_mem_malloc(0x14u, "wma_handle_disconnect_reason", 267);
    if ( !result )
      return result;
    v15 = result;
    v16 = 5;
    goto LABEL_9;
  }
  if ( v11 == 1 )
  {
    v12 = (__int64)context;
    v13 = *a1;
    result = _qdf_mem_malloc(0x14u, "wma_handle_disconnect_reason", 267);
    if ( !result )
      return result;
    v15 = result;
    v16 = 6;
LABEL_9:
    *(_BYTE *)(v15 + 1) = v13;
    *(_WORD *)(v15 + 16) = v16;
    wma_send_msg(v12, 0x13C1u, v15, 0);
  }
  return 0;
}
