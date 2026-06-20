__int64 __fastcall hw_fence_init(__int64 a1)
{
  __int64 v1; // x30
  __int64 v2; // x20
  unsigned int v4; // w0
  __int64 v5; // x4
  unsigned int v6; // w0
  unsigned int inited; // w0
  unsigned int v8; // w0
  int v9; // w8
  __int64 v10; // x3
  __int64 v11; // x9
  __int64 v12; // x4
  unsigned int v13; // w0
  __int64 v14; // x8
  __int64 v15; // x9
  unsigned int v16; // w10
  __int64 v17; // x0
  __int64 v18; // x3
  __int64 v19; // x4
  unsigned int v20; // w0
  unsigned int v21; // w0
  unsigned int v22; // w0
  unsigned int v23; // w0
  const char *v24; // x4
  unsigned int v25; // w19
  unsigned int v26; // w0
  __int64 result; // x0
  __int64 v28; // x30
  const char *v29; // x1
  void *v30; // x0
  __int64 v31; // x2
  unsigned int v32; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v34[2]; // [xsp+10h] [xbp-10h] BYREF

  v2 = v1;
  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = hw_fence_utils_parse_dt_props();
  if ( v4 )
  {
    v28 = v2;
    v29 = "hw_fence_init";
    v25 = v4;
    v30 = &unk_2A75E;
    v31 = 782;
LABEL_47:
    printk(v30, v29, v31, v28, v5);
LABEL_48:
    result = v25;
    goto LABEL_49;
  }
  v6 = hw_fence_utils_alloc_mem(a1);
  if ( v6 )
  {
    v28 = v2;
    v29 = "hw_fence_init";
    v25 = v6;
    v30 = &unk_2171F;
    v31 = 789;
    goto LABEL_47;
  }
  inited = init_hw_fences_queues(a1, 0, a1 + 184, a1 + 216, 2, 0);
  if ( inited )
  {
    v28 = v2;
    v29 = "init_ctrl_queue";
    v25 = inited;
    v30 = &unk_25F5F;
    v31 = 764;
    goto LABEL_47;
  }
  v33 = 0;
  v34[0] = 0;
  v32 = 0;
  v8 = hw_fence_utils_reserve_mem(a1, 1, v34, &v33, &v32, 0);
  if ( v8 )
  {
    printk(&unk_28C42, "init_global_locks", 674, v2, v8);
    result = 4294967284LL;
    goto LABEL_49;
  }
  v9 = msm_hw_fence_debug_level;
  if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
  {
    printk(&unk_23AA7, "init_global_locks", 677, v34[0], v33);
    v9 = msm_hw_fence_debug_level;
  }
  v10 = v33;
  v11 = v34[0];
  v12 = v32 >> 3;
  *(_QWORD *)(a1 + 168) = v32;
  *(_QWORD *)(a1 + 176) = 0;
  *(_QWORD *)(a1 + 152) = v10;
  *(_QWORD *)(a1 + 160) = v11;
  *(_QWORD *)(a1 + 104) = v10;
  *(_DWORD *)(a1 + 112) = v12;
  if ( (~v9 & 0x10008) == 0 )
    printk(&unk_28684, "hw_fence_init", 802, v10, v12);
  v33 = 0;
  v34[0] = 0;
  v32 = 0;
  v13 = hw_fence_utils_reserve_mem(a1, 2, v34, &v33, &v32, 0);
  if ( v13 )
  {
    printk(&unk_24FF1, "init_hw_fences_table", 704, v2, v13);
LABEL_38:
    result = 4294967284LL;
    goto LABEL_49;
  }
  if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
    printk(&unk_23AA7, "init_hw_fences_table", 707, v34[0], v33);
  v14 = v33;
  v15 = v34[0];
  v16 = v32;
  *(_QWORD *)(a1 + 136) = v32;
  *(_QWORD *)(a1 + 144) = 0;
  *(_QWORD *)(a1 + 120) = v14;
  *(_QWORD *)(a1 + 128) = v15;
  *(_QWORD *)(a1 + 64) = v14;
  *(_DWORD *)(a1 + 80) = v16 >> 7;
  v17 = _kmalloc_noprof(8LL * *(unsigned int *)(a1 + 80), 3520);
  *(_QWORD *)(a1 + 72) = v17;
  if ( !v17 )
    goto LABEL_38;
  if ( (~msm_hw_fence_debug_level & 0x10008) != 0 )
  {
    if ( *(_DWORD *)(a1 + 12) )
      goto LABEL_18;
  }
  else
  {
    printk(&unk_28173, "init_hw_fences_table", 726, *(_QWORD *)(a1 + 64), *(unsigned int *)(a1 + 80));
    if ( *(_DWORD *)(a1 + 12) )
      goto LABEL_18;
  }
  if ( (unsigned int)init_hw_fences_events(a1) && (~msm_hw_fence_debug_level & 0x10004) == 0 )
    printk(&unk_2AE39, "hw_fence_init", 813, v18, v19);
LABEL_18:
  v20 = hw_fence_utils_map_ipcc(a1);
  if ( v20 )
  {
    v28 = v2;
    v29 = "hw_fence_init";
    v25 = v20;
    v30 = &unk_24F9B;
    v31 = 819;
    goto LABEL_47;
  }
  v21 = hw_fence_utils_map_qtime(a1);
  if ( v21 )
  {
    v28 = v2;
    v29 = "hw_fence_init";
    v25 = v21;
    v30 = &unk_291AF;
    v31 = 826;
    goto LABEL_47;
  }
  v22 = hw_fence_debug_debugfs_register(a1);
  if ( v22 )
  {
    v28 = v2;
    v29 = "hw_fence_init";
    v25 = v22;
    v30 = &unk_286C2;
    v31 = 833;
    goto LABEL_47;
  }
  if ( *(_BYTE *)(a1 + 33520) == 1 )
  {
    v23 = hw_fence_utils_init_soccp_irq(a1);
    if ( v23 )
    {
LABEL_23:
      if ( *(_BYTE *)(a1 + 33520) )
        v24 = "true";
      else
        v24 = "false";
      v25 = v23;
      printk(&unk_24415, "hw_fence_init", 844, v2, v24);
      goto LABEL_48;
    }
  }
  else
  {
    v23 = hw_fence_utils_init_virq(a1);
    if ( v23 )
      goto LABEL_23;
  }
  if ( *(_BYTE *)(a1 + 33520) == 1 )
  {
    v26 = hw_fence_utils_register_soccp_ssr_notifier(a1);
    if ( v26 )
    {
      v28 = v2;
      v29 = "hw_fence_init";
      v25 = v26;
      v30 = &unk_2302F;
      v31 = 851;
      goto LABEL_47;
    }
  }
  memset((void *)(a1 + 748), 0, 0x8004u);
  if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
  {
    printk(&unk_296C0, "hw_fence_init", 859, *(_QWORD *)(a1 + 312), **(unsigned int **)(a1 + 312));
    if ( (~msm_hw_fence_debug_level & 0x10008) != 0 )
      goto LABEL_32;
LABEL_45:
    printk(&unk_2B2D8, "hw_fence_init", 862, *(_QWORD *)(a1 + 64), *(unsigned int *)(a1 + 80));
    goto LABEL_32;
  }
  if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
    goto LABEL_45;
LABEL_32:
  result = 0;
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
