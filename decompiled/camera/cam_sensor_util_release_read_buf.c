_QWORD *__fastcall cam_sensor_util_release_read_buf(_QWORD *result)
{
  _QWORD *v1; // x20
  _QWORD *v2; // x19
  _QWORD *v3; // x24
  int v4; // w0
  _QWORD *v5; // x8
  __int64 v6; // x9
  _QWORD *v7; // x0

  v1 = (_QWORD *)*result;
  if ( (_QWORD *)*result != result )
  {
    v2 = result;
    do
    {
      v3 = (_QWORD *)*v1;
      v4 = *((_DWORD *)v1 - 2);
      if ( v4 )
        cam_mem_put_cpu_buf(v4);
      v5 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v5 == v1 && (v6 = *v1, *(_QWORD **)(*v1 + 8LL) == v1) )
      {
        *(_QWORD *)(v6 + 8) = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      v7 = v1 - 1;
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      if ( mem_trace_en == 1 )
        result = cam_mem_trace_free(v7, 0);
      else
        result = (_QWORD *)kvfree(v7);
      v1 = v3;
    }
    while ( v3 != v2 );
  }
  return result;
}
