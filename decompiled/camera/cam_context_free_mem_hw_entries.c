_QWORD *__fastcall cam_context_free_mem_hw_entries(_QWORD *result)
{
  _QWORD *v1; // x19
  unsigned int v2; // w21
  _QWORD *v3; // x0
  _QWORD *v4; // x0
  unsigned int v5; // w21
  _QWORD *v6; // x0
  _QWORD *v7; // x0
  unsigned int v8; // w21
  _QWORD *v9; // x0
  _QWORD *v10; // x0

  v1 = result;
  if ( result[62] )
  {
    if ( *((_DWORD *)result + 50) )
    {
      v2 = 0;
      do
      {
        v3 = *(_QWORD **)(v1[62] + 8LL * (int)v2);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v3, 0);
        else
          kvfree(v3);
        *(_QWORD *)(v1[62] + 8LL * (int)v2++) = 0;
      }
      while ( v2 < *((_DWORD *)v1 + 50) );
    }
    v4 = (_QWORD *)v1[62];
    if ( mem_trace_en == 1 )
      result = cam_mem_trace_free(v4, 0);
    else
      result = (_QWORD *)kvfree(v4);
    v1[62] = 0;
  }
  if ( v1[61] )
  {
    if ( *((_DWORD *)v1 + 50) )
    {
      v5 = 0;
      do
      {
        v6 = *(_QWORD **)(v1[61] + 8LL * (int)v5);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v6, 0);
        else
          kvfree(v6);
        *(_QWORD *)(v1[61] + 8LL * (int)v5++) = 0;
      }
      while ( v5 < *((_DWORD *)v1 + 50) );
    }
    v7 = (_QWORD *)v1[61];
    if ( mem_trace_en == 1 )
      result = cam_mem_trace_free(v7, 0);
    else
      result = (_QWORD *)kvfree(v7);
    v1[61] = 0;
  }
  if ( v1[60] )
  {
    if ( *((_DWORD *)v1 + 50) )
    {
      v8 = 0;
      do
      {
        v9 = *(_QWORD **)(v1[60] + 8LL * (int)v8);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v9, 0);
        else
          kvfree(v9);
        *(_QWORD *)(v1[60] + 8LL * (int)v8++) = 0;
      }
      while ( v8 < *((_DWORD *)v1 + 50) );
    }
    v10 = (_QWORD *)v1[60];
    if ( mem_trace_en == 1 )
      result = cam_mem_trace_free(v10, 0);
    else
      result = (_QWORD *)kvfree(v10);
    v1[60] = 0;
  }
  return result;
}
