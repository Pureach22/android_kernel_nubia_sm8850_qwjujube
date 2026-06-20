__int64 __fastcall cam_res_mgr_add_device(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  __int64 v5; // x2
  _QWORD *v6; // x1
  unsigned int v7; // w8

  if ( mem_trace_en == 1 )
  {
    v4 = (_QWORD *)cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_res_mgr_add_device", 0x189u);
    if ( !v4 )
      return (unsigned int)-12;
  }
  else
  {
    v4 = (_QWORD *)_kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
    if ( !v4 )
      return (unsigned int)-12;
  }
  v4[2] = a1;
  v5 = a2 + 16;
  *v4 = v4;
  v4[1] = v4;
  v6 = *(_QWORD **)(a2 + 24);
  if ( v4 == (_QWORD *)(a2 + 16) || v6 == v4 || *v6 != v5 )
  {
    _list_add_valid_or_report(v4);
    return 0;
  }
  else
  {
    v7 = 0;
    *(_QWORD *)(a2 + 24) = v4;
    *v4 = v5;
    v4[1] = v6;
    *v6 = v4;
  }
  return v7;
}
