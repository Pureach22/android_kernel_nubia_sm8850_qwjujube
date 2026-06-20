__int64 __fastcall cam_vfe_rdi_ver2_init(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4, __int64 a5)
{
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x8
  int v13; // w6
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x19
  __int64 *v17; // x10
  __int64 v18; // x11
  __int64 v19; // x9
  __int64 *v20; // x1
  __int64 v21; // x12
  __int64 result; // x0

  if ( mem_trace_en == 1 )
  {
    v10 = cam_mem_trace_alloc(22680, 0xCC0u, 0, "cam_vfe_rdi_ver2_init", 0x213u);
    if ( !v10 )
    {
LABEL_31:
      result = 4294967284LL;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_vfe_rdi_ver2_init",
          533,
          "Error! Failed to alloc for rdi_priv");
        return 4294967284LL;
      }
      return result;
    }
  }
  else
  {
    v10 = _kvmalloc_node_noprof(22680, 0, 3520, 0xFFFFFFFFLL);
    if ( !v10 )
      goto LABEL_31;
  }
  *(_QWORD *)(a4 + 24) = v10;
  *(_QWORD *)v10 = *(_QWORD *)(a2 + 288);
  *(_QWORD *)(v10 + 8) = a1;
  *(_QWORD *)(v10 + 16) = *a3;
  v11 = a3[1];
  *(_QWORD *)(v10 + 88) = a5;
  *(_QWORD *)(v10 + 24) = v11;
  v12 = a3[2];
  *(_QWORD *)(v10 + 56) = a2;
  *(_QWORD *)(v10 + 32) = v12;
  *(_QWORD *)(v10 + 40) = a3[3];
  v13 = *(_DWORD *)(a4 + 4);
  if ( v13 > 4 )
  {
    if ( v13 == 5 )
    {
      v14 = 6;
      goto LABEL_20;
    }
    if ( v13 == 6 )
    {
      v15 = a3[7];
      if ( v15 )
        goto LABEL_21;
      v16 = v10;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_rdi_ver2_init",
        562,
        "Error! RDI3 is not supported");
      goto LABEL_13;
    }
LABEL_14:
    if ( (debug_mdl & 8) == 0 || debug_priority )
    {
LABEL_16:
      if ( mem_trace_en == 1 )
        cam_mem_trace_free((_QWORD *)v10, 0);
      else
        kvfree(v10);
      return 4294967274LL;
    }
    v16 = v10;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_rdi_ver2_init",
      567,
      "invalid Resource id:%d",
      v13);
LABEL_13:
    v10 = v16;
    goto LABEL_16;
  }
  if ( v13 == 3 )
  {
    v14 = 4;
    goto LABEL_20;
  }
  if ( v13 != 4 )
    goto LABEL_14;
  v14 = 5;
LABEL_20:
  v15 = a3[v14];
LABEL_21:
  *(_QWORD *)(v10 + 48) = v15;
  v17 = (__int64 *)(v10 + 96);
  *(_QWORD *)(a4 + 88) = cam_vfe_rdi_resource_start;
  *(_QWORD *)(a4 + 96) = cam_vfe_rdi_resource_stop;
  v18 = 256;
  *(_QWORD *)(a4 + 104) = cam_vfe_rdi_process_cmd;
  *(_QWORD *)(a4 + 112) = &cam_vfe_rdi_handle_irq_top_half;
  *(_QWORD *)(a4 + 120) = cam_vfe_rdi_handle_irq_bottom_half;
  v19 = v10 + 22624;
  *(_DWORD *)(v10 + 22640) = 0;
  *(_QWORD *)(v10 + 22624) = v10 + 22624;
  *(_QWORD *)(v10 + 22632) = v10 + 22624;
  do
  {
    *v17 = (__int64)v17;
    v17[1] = (__int64)v17;
    v20 = *(__int64 **)(v10 + 22632);
    if ( v17 == v20 || *v20 != v19 )
    {
      _list_add_valid_or_report(v17);
      v10 = v21;
    }
    else
    {
      *(_QWORD *)(v10 + 22632) = v17;
      *v17 = v19;
      v17[1] = (__int64)v20;
      *v20 = (__int64)v17;
    }
    --v18;
    v17 += 11;
  }
  while ( v18 );
  return 0;
}
