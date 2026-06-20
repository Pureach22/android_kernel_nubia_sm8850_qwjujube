__int64 __fastcall cam_vfe_res_mux_init(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x25
  __int64 v13; // x0
  __int64 v14; // x11
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 *v17; // x10
  __int64 *v18; // x1
  __int64 v19; // x12

  v6 = *(_QWORD *)(a3 + 3296);
  if ( mem_trace_en == 1 )
  {
    v13 = cam_mem_trace_alloc(22824, 0xCC0u, 0, "cam_vfe_res_mux_init", 0xB7Du);
    if ( !v13 )
      return 4294967284LL;
  }
  else
  {
    v13 = _kvmalloc_node_noprof(22824, 0, 3520, 0xFFFFFFFFLL);
    if ( !v13 )
      return 4294967284LL;
  }
  *(_QWORD *)(a5 + 24) = v13;
  v14 = 256;
  *(_QWORD *)v13 = *(_QWORD *)(a3 + 288);
  *(_QWORD *)(v13 + 24) = *a4;
  v15 = a4[1];
  *(_QWORD *)(v13 + 16) = a2;
  *(_QWORD *)(v13 + 64) = v15;
  LOBYTE(v15) = *(_BYTE *)(v6 + 24);
  *(_QWORD *)(v13 + 8) = a3;
  *(_QWORD *)(v13 + 112) = a6;
  *(_BYTE *)(v13 + 22810) = v15;
  LODWORD(v15) = *(_DWORD *)(a5 + 4);
  *(_QWORD *)(v13 + 72) = a1;
  *(_BYTE *)(v13 + 22811) = (_DWORD)v15 == 0;
  *(_QWORD *)(a5 + 72) = cam_vfe_resource_init;
  *(_QWORD *)(a5 + 80) = cam_vfe_resource_deinit;
  *(_QWORD *)(a5 + 88) = cam_vfe_resource_start;
  *(_QWORD *)(a5 + 96) = cam_vfe_resource_stop;
  *(_QWORD *)(a5 + 112) = cam_vfe_handle_irq_top_half;
  *(_QWORD *)(a5 + 120) = &cam_vfe_handle_irq_bottom_half;
  v16 = v13 + 22648;
  *(_DWORD *)(v13 + 22664) = 0;
  v17 = (__int64 *)(v13 + 120);
  *(_QWORD *)(v13 + 22648) = v13 + 22648;
  *(_QWORD *)(v13 + 22656) = v13 + 22648;
  do
  {
    *v17 = (__int64)v17;
    v17[1] = (__int64)v17;
    v18 = *(__int64 **)(v13 + 22656);
    if ( v17 == v18 || *v18 != v16 )
    {
      _list_add_valid_or_report(v17);
      v13 = v19;
    }
    else
    {
      *(_QWORD *)(v13 + 22656) = v17;
      *v17 = v16;
      v17[1] = (__int64)v18;
      *v18 = (__int64)v17;
    }
    --v14;
    v17 += 11;
  }
  while ( v14 );
  return 0;
}
