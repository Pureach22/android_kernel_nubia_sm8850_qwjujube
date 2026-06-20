__int64 *__fastcall cam_sensor_get_i2c_ptr(__int64 *a1, unsigned int a2)
{
  __int64 *result; // x0
  __int64 *v5; // x20
  __int64 **v6; // x1
  __int64 *v7; // x23
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 **v10; // x8
  __int64 *v11; // x9
  int v12; // w8

  if ( mem_trace_en == 1 )
  {
    result = (__int64 *)cam_mem_trace_alloc(88, 0xCC0u, 0, "cam_sensor_get_i2c_ptr", 0x7Bu);
    if ( !result )
      return result;
  }
  else
  {
    result = (__int64 *)_kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
    if ( !result )
      return result;
  }
  v5 = result + 9;
  v6 = (__int64 **)a1[1];
  v7 = result;
  if ( result + 9 == a1 || v6 == (__int64 **)v5 || *v6 != a1 )
  {
    _list_add_valid_or_report(result + 9);
  }
  else
  {
    a1[1] = (__int64)v5;
    result[9] = (__int64)a1;
    result[10] = (__int64)v6;
    *v6 = v5;
  }
  if ( mem_trace_en == 1 )
    v8 = cam_mem_trace_alloc(16LL * a2, 0xCC0u, 0, "cam_sensor_get_i2c_ptr", 0x84u);
  else
    v8 = _kvmalloc_node_noprof(16LL * a2, 0, 3520, 0xFFFFFFFFLL);
  v9 = v8;
  result = v7;
  *v7 = v9;
  if ( v9 )
  {
    *((_DWORD *)v7 + 2) = a2;
  }
  else
  {
    v10 = (__int64 **)v7[10];
    if ( *v10 == v5 && (v11 = (__int64 *)*v5, *(__int64 **)(*v5 + 8) == v5) )
    {
      v11[1] = (__int64)v10;
      *v10 = v11;
    }
    else
    {
      _list_del_entry_valid_or_report(v5);
      result = v7;
    }
    v12 = (unsigned __int8)mem_trace_en;
    result[9] = 0xDEAD000000000100LL;
    result[10] = 0xDEAD000000000122LL;
    if ( v12 == 1 )
      cam_mem_trace_free(result, 0);
    else
      kvfree(result);
    return nullptr;
  }
  return result;
}
