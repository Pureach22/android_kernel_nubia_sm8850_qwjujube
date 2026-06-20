__int64 __fastcall cam_icp_mgr_send_memory_region_info(__int64 a1)
{
  __int64 v1; // x23
  int v2; // w10
  int v4; // w9
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x21
  unsigned int v9; // w8
  __int64 v10; // x11
  __int64 v11; // x14
  __int64 v12; // x13
  __int64 v13; // x9
  __int64 v14; // x10
  __int64 v15; // x10
  __int64 v16; // x9
  __int64 v17; // x9
  __int64 v18; // x10
  __int16 v19; // w8

  v1 = a1 + 40960;
  v2 = *(unsigned __int8 *)(a1 + 44236);
  if ( *(_BYTE *)(a1 + 44235) )
    v4 = v2 | 4;
  else
    v4 = v2 + 1;
  v5 = 20LL * (unsigned int)(v4 - 1);
  v6 = v5 + 40;
  if ( mem_trace_en == 1 )
    v7 = cam_mem_trace_alloc(v5 + 40, 0xCC0u, 0, "cam_icp_mgr_send_memory_region_info", 0x15E4u);
  else
    v7 = _kvmalloc_node_noprof(v5 + 40, 0, 3520, 0xFFFFFFFFLL);
  v8 = v7;
  if ( !v7 )
    return 4294967284LL;
  *(_DWORD *)v7 = v6;
  *(_DWORD *)(v7 + 12) = 14;
  *(_QWORD *)(v7 + 4) = 0x100010003LL;
  v9 = *(_DWORD *)(v7 + 16);
  if ( *(_BYTE *)(v1 + 3275) == 1 )
  {
    v10 = v7 + 20 + 20LL * v9;
    *(_QWORD *)v10 = 0x100000000LL;
    v11 = v7 + 20 + 20LL * (v9 + 1);
    *(_QWORD *)(v10 + 8) = *(unsigned int *)(a1 + 536);
    v12 = *(_QWORD *)(a1 + 552);
    *(_DWORD *)(v7 + 16) = v9 + 1;
    *(_QWORD *)v11 = 0x200000001LL;
    *(_DWORD *)(v10 + 16) = v12;
    LODWORD(v10) = v9 + 2;
    v9 += 3;
    v13 = v7 + 20 + 20LL * (unsigned int)v10;
    *(_QWORD *)(v11 + 8) = *(unsigned int *)(a1 + 576);
    v14 = *(_QWORD *)(a1 + 592);
    *(_DWORD *)(v7 + 16) = v10;
    *(_QWORD *)v13 = 0x200000002LL;
    *(_DWORD *)(v11 + 16) = v14;
    *(_QWORD *)(v13 + 8) = *(unsigned int *)(a1 + 616);
    v15 = *(_QWORD *)(a1 + 632);
    *(_DWORD *)(v7 + 16) = v9;
    *(_DWORD *)(v13 + 16) = v15;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_mgr_send_memory_region_info",
        5656,
        "Synx mem regions global_sync[0x%x:0x%x] synx_hw_mutex[0x%x:0x%x] ipc_hw_mutex[0x%x:0x%x]",
        *(_DWORD *)(a1 + 536),
        *(_QWORD *)(a1 + 552),
        *(_DWORD *)(a1 + 576),
        *(_QWORD *)(a1 + 592),
        *(_DWORD *)(a1 + 616),
        *(_QWORD *)(a1 + 632));
      v9 = *(_DWORD *)(v8 + 16);
    }
  }
  v16 = v8 + 20 + 20LL * v9;
  *(_QWORD *)v16 = 0x200000003LL;
  *(_QWORD *)(v16 + 8) = *(unsigned int *)(a1 + 656);
  *(_DWORD *)(v16 + 16) = *(_QWORD *)(a1 + 672);
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_send_memory_region_info",
      5669,
      "Global_cntr[0x%x:0x%x]",
      *(_DWORD *)(a1 + 656),
      *(_QWORD *)(a1 + 672));
    v9 = *(_DWORD *)(v8 + 16);
  }
  *(_DWORD *)(v8 + 16) = v9 + 1;
  if ( *(_BYTE *)(v1 + 3276) == 1
    && (v17 = v8 + 20 + 20LL * (v9 + 1),
        *(_QWORD *)v17 = 0x200000004LL,
        *(_QWORD *)(v17 + 8) = *(unsigned int *)(a1 + 696),
        v18 = *(_QWORD *)(a1 + 712),
        *(_DWORD *)(v8 + 16) = v9 + 2,
        *(_DWORD *)(v17 + 16) = v18,
        (debug_mdl & 0x100) != 0)
    && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_send_memory_region_info",
      5688,
      "LLCC mem regions llcc_reg[0x%x:0x%x]",
      *(_DWORD *)(a1 + 696),
      *(_QWORD *)(a1 + 712));
    v19 = debug_mdl;
    if ( (debug_mdl & 0x100) != 0 )
    {
LABEL_19:
      if ( !debug_priority )
        ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v19 & 0x100,
          4,
          "cam_icp_mgr_send_memory_region_info",
          5693,
          "Mem region property payload size: %zu num_regions: %u",
          v6,
          *(_DWORD *)(v8 + 16));
    }
  }
  else
  {
    v19 = debug_mdl;
    if ( (debug_mdl & 0x100) != 0 )
      goto LABEL_19;
  }
  hfi_write_cmd(*(unsigned int *)(a1 + 156), v8);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v8, 0);
  else
    kvfree(v8);
  return 0;
}
