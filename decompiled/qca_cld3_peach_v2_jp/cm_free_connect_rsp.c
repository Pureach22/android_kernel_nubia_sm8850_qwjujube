__int64 __fastcall cm_free_connect_rsp(void *a1)
{
  __int64 result; // x0

  result = cm_free_connect_rsp_ies((__int64)a1);
  if ( a1 )
  {
    qdf_mem_set(a1, 0xA0u, 0);
    return _qdf_mem_free((__int64)a1);
  }
  return result;
}
