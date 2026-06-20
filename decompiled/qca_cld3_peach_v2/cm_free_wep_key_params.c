__int64 __fastcall cm_free_wep_key_params(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  void *v3; // x20

  v1 = *(_QWORD *)(result + 96);
  v2 = result;
  if ( v1 )
  {
    qdf_mem_set(*(void **)(result + 96), *(unsigned __int8 *)(result + 112), 0);
    result = _qdf_mem_free(v1);
  }
  v3 = *(void **)(v2 + 104);
  *(_QWORD *)(v2 + 96) = 0;
  if ( v3 )
  {
    qdf_mem_set(v3, *(unsigned __int8 *)(v2 + 113), 0);
    result = _qdf_mem_free((__int64)v3);
  }
  *(_QWORD *)(v2 + 104) = 0;
  return result;
}
