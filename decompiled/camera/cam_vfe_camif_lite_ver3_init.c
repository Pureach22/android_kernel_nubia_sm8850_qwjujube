__int64 __fastcall cam_vfe_camif_lite_ver3_init(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4, __int64 a5)
{
  __int64 v10; // x0
  __int64 *v11; // x10
  __int64 v12; // x11
  __int64 v13; // x8
  __int64 v14; // x9
  __int64 *v15; // x1
  __int64 v16; // x12

  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_camif_lite_ver3_init",
      1262,
      "VFE:%d CAMIF LITE:%d %s Init",
      *(_DWORD *)(a4 + 4),
      *(_DWORD *)(a4 + 4),
      (const char *)(a4 + 128));
  if ( mem_trace_en == 1 )
  {
    v10 = cam_mem_trace_alloc(22752, 0xCC0u, 0, "cam_vfe_camif_lite_ver3_init", 0x4F1u);
    if ( !v10 )
      return 4294967284LL;
  }
  else
  {
    v10 = _kvmalloc_node_noprof(22752, 0, 3520, 0xFFFFFFFFLL);
    if ( !v10 )
      return 4294967284LL;
  }
  *(_QWORD *)(a4 + 24) = v10;
  v11 = (__int64 *)(v10 + 160);
  v12 = 256;
  *(_QWORD *)v10 = *(_QWORD *)(a2 + 288);
  *(_QWORD *)(v10 + 16) = a3[1];
  *(_QWORD *)(v10 + 24) = *a3;
  v13 = a3[2];
  *(_QWORD *)(v10 + 8) = a1;
  *(_QWORD *)(v10 + 128) = a5;
  *(_QWORD *)(v10 + 32) = v13;
  *(_QWORD *)(v10 + 40) = a2;
  *(_QWORD *)(a4 + 88) = cam_vfe_camif_lite_resource_start_0;
  *(_QWORD *)(a4 + 96) = cam_vfe_camif_lite_resource_stop_0;
  *(_QWORD *)(a4 + 72) = 0;
  *(_QWORD *)(a4 + 80) = 0;
  *(_QWORD *)(a4 + 104) = cam_vfe_camif_lite_process_cmd_0;
  *(_QWORD *)(a4 + 112) = &cam_vfe_camif_lite_handle_irq_top_half_0;
  v14 = v10 + 136;
  *(_QWORD *)(a4 + 120) = cam_vfe_camif_lite_handle_irq_bottom_half_0;
  *(_DWORD *)(v10 + 152) = 0;
  *(_QWORD *)(v10 + 136) = v10 + 136;
  *(_QWORD *)(v10 + 144) = v10 + 136;
  do
  {
    *v11 = (__int64)v11;
    v11[1] = (__int64)v11;
    v15 = *(__int64 **)(v10 + 144);
    if ( v11 == v15 || *v15 != v14 )
    {
      _list_add_valid_or_report(v11);
      v10 = v16;
    }
    else
    {
      *(_QWORD *)(v10 + 144) = v11;
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
