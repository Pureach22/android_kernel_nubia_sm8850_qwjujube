__int64 __fastcall cam_sensor_util_add_read_buf_to_list(__int64 a1, int a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x8
  _QWORD *v6; // x1
  unsigned int v7; // w9

  if ( mem_trace_en == 1 )
  {
    v4 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_sensor_util_add_read_buf_to_list", 0xB64u);
    if ( !v4 )
      return (unsigned int)-12;
  }
  else
  {
    v4 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
    if ( !v4 )
      return (unsigned int)-12;
  }
  *(_DWORD *)v4 = a2;
  v5 = (_QWORD *)(v4 + 8);
  v6 = *(_QWORD **)(a1 + 8);
  if ( v4 + 8 == a1 || v6 == v5 || *v6 != a1 )
  {
    _list_add_valid_or_report(v4 + 8);
    return 0;
  }
  else
  {
    v7 = 0;
    *(_QWORD *)(a1 + 8) = v5;
    *(_QWORD *)(v4 + 8) = a1;
    *(_QWORD *)(v4 + 16) = v6;
    *v6 = v5;
  }
  return v7;
}
