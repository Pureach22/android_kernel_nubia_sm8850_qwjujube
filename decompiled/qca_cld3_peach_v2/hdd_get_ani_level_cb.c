__int64 __fastcall hdd_get_ani_level_cb(const void *a1, unsigned __int8 a2, __int64 a3)
{
  int v4; // w22
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x20
  __int64 v15; // x21
  void *v16; // x0

  if ( a2 >= 0x14u )
    v4 = 20;
  else
    v4 = a2;
  v5 = osif_request_get(a3);
  if ( !v5 )
    return qdf_trace_msg(0x33u, 2u, "%s: Obsolete request", v6, v7, v8, v9, v10, v11, v12, v13, "hdd_get_ani_level_cb");
  v14 = v5;
  v15 = osif_request_priv(v5);
  v16 = (void *)_qdf_mem_malloc(8LL * (v4 & 0x1F), "hdd_get_ani_level_cb", 3361);
  *(_QWORD *)(v15 + 8) = v16;
  if ( v16 )
  {
    *(_DWORD *)v15 = v4;
    qdf_mem_copy(v16, a1, (unsigned __int8)(8 * v4));
  }
  osif_request_complete(v14);
  return osif_request_put(v14);
}
