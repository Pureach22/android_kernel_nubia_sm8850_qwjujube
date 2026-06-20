__int64 __fastcall cam_vfe_camif_ver3_init(__int64 a1, __int64 a2, _QWORD *a3, _QWORD *a4, __int64 a5)
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
    v10 = cam_mem_trace_alloc(22816, 0xCC0u, 0, "cam_vfe_camif_ver3_init", 0x606u);
    if ( !v10 )
      return 4294967284LL;
  }
  else
  {
    v10 = _kvmalloc_node_noprof(22816, 0, 3520, 0xFFFFFFFFLL);
    if ( !v10 )
      return 4294967284LL;
  }
  a4[3] = v10;
  v11 = (__int64 *)(v10 + 136);
  v12 = 256;
  *(_QWORD *)v10 = *(_QWORD *)(a2 + 288);
  *(_QWORD *)(v10 + 16) = a3[1];
  *(_QWORD *)(v10 + 24) = *a3;
  v13 = a3[2];
  *(_QWORD *)(v10 + 8) = a1;
  *(_QWORD *)(v10 + 128) = a5;
  *(_QWORD *)(v10 + 32) = v13;
  *(_QWORD *)(v10 + 40) = a2;
  a4[9] = cam_vfe_camif_ver3_resource_init;
  a4[10] = cam_vfe_camif_ver3_resource_deinit;
  a4[11] = cam_vfe_camif_ver3_resource_start;
  a4[12] = cam_vfe_camif_ver3_resource_stop;
  a4[13] = cam_vfe_camif_ver3_process_cmd;
  a4[14] = cam_vfe_camif_ver3_handle_irq_top_half;
  a4[15] = cam_vfe_camif_ver3_handle_irq_bottom_half;
  v14 = v10 + 22664;
  *(_DWORD *)(v10 + 22680) = 0;
  *(_QWORD *)(v10 + 22664) = v10 + 22664;
  *(_QWORD *)(v10 + 22672) = v10 + 22664;
  do
  {
    *v11 = (__int64)v11;
    v11[1] = (__int64)v11;
    v15 = *(__int64 **)(v10 + 22672);
    if ( v11 == v15 || *v15 != v14 )
    {
      _list_add_valid_or_report(v11);
      v10 = v16;
    }
    else
    {
      *(_QWORD *)(v10 + 22672) = v11;
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
