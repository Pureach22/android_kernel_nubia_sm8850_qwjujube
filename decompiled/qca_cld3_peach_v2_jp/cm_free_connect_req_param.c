__int64 __fastcall cm_free_connect_req_param(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  void *v3; // x20
  void *v4; // x20
  void *v5; // x20

  v1 = *(_QWORD *)(result + 160);
  v2 = result;
  if ( v1 )
  {
    qdf_mem_set(*(void **)(result + 160), *(unsigned int *)(result + 152), 0);
    result = _qdf_mem_free(v1);
  }
  v3 = *(void **)(v2 + 176);
  *(_QWORD *)(v2 + 160) = 0;
  if ( v3 )
  {
    qdf_mem_set(v3, *(unsigned int *)(v2 + 168), 0);
    result = _qdf_mem_free((__int64)v3);
  }
  v4 = *(void **)(v2 + 96);
  *(_QWORD *)(v2 + 176) = 0;
  if ( v4 )
  {
    qdf_mem_set(v4, *(unsigned __int8 *)(v2 + 112), 0);
    result = _qdf_mem_free((__int64)v4);
  }
  v5 = *(void **)(v2 + 104);
  *(_QWORD *)(v2 + 96) = 0;
  if ( v5 )
  {
    qdf_mem_set(v5, *(unsigned __int8 *)(v2 + 113), 0);
    result = _qdf_mem_free((__int64)v5);
  }
  *(_QWORD *)(v2 + 104) = 0;
  return result;
}
