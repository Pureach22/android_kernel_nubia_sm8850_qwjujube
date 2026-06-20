__int64 __fastcall cam_vfe_fe_ver1_init(__int64 a1, __int64 a2, _QWORD *a3, _QWORD *a4)
{
  __int64 v8; // x0
  _QWORD *v9; // x8
  __int64 v11; // x9

  if ( mem_trace_en == 1 )
    v8 = cam_mem_trace_alloc(104, 0xCC0u, 0, "cam_vfe_fe_ver1_init", 0x242u);
  else
    v8 = _kvmalloc_node_noprof(104, 0, 3520, 0xFFFFFFFFLL);
  v9 = (_QWORD *)v8;
  if ( v8 )
  {
    a4[3] = v8;
    *v9 = *(_QWORD *)(a2 + 288);
    v9[2] = a3[1];
    v9[3] = *a3;
    v11 = a3[2];
    v9[1] = a1;
    v9[4] = v11;
    v9[5] = a2;
    a4[9] = cam_vfe_fe_resource_init;
    a4[10] = cam_vfe_fe_resource_deinit;
    a4[11] = cam_vfe_fe_resource_start;
    a4[12] = cam_vfe_fe_resource_stop;
    a4[13] = cam_vfe_fe_process_cmd;
    a4[14] = cam_vfe_fe_handle_irq_top_half;
    a4[15] = cam_vfe_fe_handle_irq_bottom_half;
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_fe_ver1_init",
      580,
      "Error! Failed to alloc for fe_priv");
    return 4294967284LL;
  }
}
