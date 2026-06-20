_QWORD *__fastcall cam_soc_bus_client_unregister(__int64 ***a1)
{
  __int64 **v1; // x20
  __int64 *v3; // x21
  __int64 *v4; // x8
  _QWORD *result; // x0

  v1 = *a1;
  v3 = **a1;
  v4 = v3;
  if ( *((_BYTE *)(*a1)[1] + 16) == 1 )
  {
    cam_wrapper_icc_put(v3[1]);
    v4 = v3 + 2;
  }
  cam_wrapper_icc_put(*v4);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v3, 0);
  else
    kvfree(v3);
  *v1 = nullptr;
  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free(v1, 0);
  else
    result = (_QWORD *)kvfree(v1);
  *a1 = nullptr;
  return result;
}
