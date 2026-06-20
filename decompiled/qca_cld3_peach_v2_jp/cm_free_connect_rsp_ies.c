__int64 __fastcall cm_free_connect_rsp_ies(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  void *v3; // x20
  void *v4; // x20
  void *v5; // x20
  unsigned __int8 *v6; // x20
  void *v7; // x21
  void *v8; // x19

  v1 = *(_QWORD *)(result + 112);
  v2 = result;
  if ( v1 )
  {
    qdf_mem_set(*(void **)(result + 112), *(unsigned int *)(result + 104), 0);
    result = _qdf_mem_free(v1);
  }
  v3 = *(void **)(v2 + 80);
  *(_DWORD *)(v2 + 104) = 0;
  if ( v3 )
  {
    qdf_mem_set(v3, *(unsigned int *)(v2 + 72), 0);
    result = _qdf_mem_free((__int64)v3);
  }
  v4 = *(void **)(v2 + 96);
  *(_DWORD *)(v2 + 72) = 0;
  if ( v4 )
  {
    qdf_mem_set(v4, *(unsigned int *)(v2 + 88), 0);
    result = _qdf_mem_free((__int64)v4);
  }
  v5 = *(void **)(v2 + 128);
  *(_DWORD *)(v2 + 88) = 0;
  if ( v5 )
  {
    qdf_mem_set(v5, *(unsigned int *)(v2 + 120), 0);
    result = _qdf_mem_free((__int64)v5);
  }
  v6 = *(unsigned __int8 **)(v2 + 136);
  *(_DWORD *)(v2 + 120) = 0;
  if ( v6 )
  {
    v7 = *(void **)v6;
    if ( !*(_QWORD *)v6
      || (qdf_mem_set(*(void **)v6, v6[8], 0),
          result = _qdf_mem_free((__int64)v7),
          (v6 = *(unsigned __int8 **)(v2 + 136)) != nullptr) )
    {
      qdf_mem_set(v6, 0x990u, 0);
      result = _qdf_mem_free((__int64)v6);
    }
  }
  v8 = *(void **)(v2 + 144);
  if ( v8 )
  {
    qdf_mem_set(v8, 0xC8u, 0);
    return _qdf_mem_free((__int64)v8);
  }
  return result;
}
