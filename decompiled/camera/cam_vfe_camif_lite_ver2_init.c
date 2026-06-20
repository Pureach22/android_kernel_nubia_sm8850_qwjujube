__int64 __fastcall cam_vfe_camif_lite_ver2_init(__int64 a1, __int64 a2, _QWORD *a3, _QWORD *a4, __int64 a5)
{
  __int64 v10; // x0
  __int64 *v11; // x10
  __int64 v12; // x11
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 *v15; // x1
  __int64 v16; // x12

  if ( mem_trace_en == 1 )
  {
    v10 = cam_mem_trace_alloc(22656, 0xCC0u, 0, "cam_vfe_camif_lite_ver2_init", 0x215u);
    if ( !v10 )
      return 4294967284LL;
  }
  else
  {
    v10 = _kvmalloc_node_noprof(22656, 0, 3520, 0xFFFFFFFFLL);
    if ( !v10 )
      return 4294967284LL;
  }
  a4[3] = v10;
  v11 = (__int64 *)(v10 + 88);
  v12 = 256;
  *(_QWORD *)v10 = *(_QWORD *)(a2 + 288);
  *(_QWORD *)(v10 + 16) = a3[1];
  *(_QWORD *)(v10 + 24) = *a3;
  v13 = a3[2];
  *(_QWORD *)(v10 + 8) = a1;
  *(_QWORD *)(v10 + 80) = a5;
  *(_QWORD *)(v10 + 32) = v13;
  *(_QWORD *)(v10 + 40) = a2;
  a4[11] = cam_vfe_camif_lite_resource_start;
  a4[12] = cam_vfe_camif_lite_resource_stop;
  a4[9] = 0;
  a4[10] = 0;
  a4[13] = cam_vfe_camif_lite_process_cmd;
  a4[14] = &cam_vfe_camif_lite_handle_irq_top_half;
  a4[15] = cam_vfe_camif_lite_handle_irq_bottom_half;
  v14 = v10 + 22616;
  *(_DWORD *)(v10 + 22632) = 0;
  *(_QWORD *)(v10 + 22616) = v10 + 22616;
  *(_QWORD *)(v10 + 22624) = v10 + 22616;
  do
  {
    *v11 = (__int64)v11;
    v11[1] = (__int64)v11;
    v15 = *(__int64 **)(v10 + 22624);
    if ( v11 == v15 || *v15 != v14 )
    {
      _list_add_valid_or_report(v11);
      v10 = v16;
    }
    else
    {
      *(_QWORD *)(v10 + 22624) = v11;
      *v11 = v14;
      v11[1] = (__int64)v15;
      *v15 = (__int64)v11;
    }
    --v12;
    v11 += 11;
  }
  while ( v12 );
  return 0;
}
