_QWORD *__fastcall cam_sensor_util_release_resources(_QWORD *result, __int64 a2)
{
  _QWORD *v2; // x19
  _QWORD *v4; // x0
  int v5; // w8

  v2 = result;
  if ( *(_QWORD *)(a2 + 3296) )
  {
    v4 = *(_QWORD **)(a2 + 3296);
    if ( mem_trace_en == 1 )
      result = cam_mem_trace_free(v4, 0);
    else
      result = (_QWORD *)kvfree(v4);
    *(_QWORD *)(a2 + 3296) = 0;
  }
  v5 = *(_DWORD *)v2;
  if ( *(_DWORD *)v2 == 1 )
  {
    result = (_QWORD *)v2[2];
    if ( !result )
      return result;
    if ( mem_trace_en == 1 )
      result = cam_mem_trace_free(result, 0);
    else
      result = (_QWORD *)kvfree(result);
    v5 = *(_DWORD *)v2;
    v2[2] = 0;
  }
  if ( v5 == 4 || v5 == 2 )
  {
    result = (_QWORD *)v2[1];
    if ( result )
    {
      if ( mem_trace_en == 1 )
        result = cam_mem_trace_free(result, 0);
      else
        result = (_QWORD *)kvfree(result);
      v2[1] = 0;
    }
  }
  return result;
}
