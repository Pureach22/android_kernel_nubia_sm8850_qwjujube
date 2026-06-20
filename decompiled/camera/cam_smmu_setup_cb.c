__int64 __fastcall cam_smmu_setup_cb(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x21
  __int64 v5; // x0
  __int64 v6; // x23
  unsigned int v7; // w0
  unsigned int v8; // w21
  __int64 v9; // x22
  unsigned __int64 v10; // x6
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned __int64 domain_for_dev; // x0
  const char *v14; // x5
  __int64 v15; // x4
  __int64 v16; // x0
  unsigned int v17; // w0
  unsigned __int64 StatusReg; // x24
  __int64 v19; // x25
  int v20; // w8
  __int64 v21; // x0
  __int64 v22; // x20
  __int64 v23; // x24
  __int64 v24; // x0
  __int64 v25; // x0
  _QWORD *v26; // x0

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_setup_cb",
      4521,
      "Error: invalid input params");
    return (unsigned int)-22;
  }
  *(_QWORD *)a1 = a2;
  *(_BYTE *)(a1 + 104) = 0;
  *(_QWORD *)(a1 + 8672) = -1;
  if ( !*(_BYTE *)(a1 + 83) || *(int *)(a1 + 1640) < 1 )
  {
    LODWORD(v9) = 0;
    goto LABEL_9;
  }
  v5 = gen_pool_create(16, 0xFFFFFFFFLL);
  *(_QWORD *)(a1 + 144) = v5;
  v6 = a1 + 144;
  if ( v5 )
  {
    v7 = gen_pool_add_owner(v5, *(_QWORD *)(a1 + 2232), -1, *(_QWORD *)(a1 + 2240), 0xFFFFFFFFLL, 0);
    if ( v7 )
    {
      v8 = v7;
      v9 = 0;
LABEL_7:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_setup_cb",
        4544,
        "Genpool chunk creation failed");
      gen_pool_destroy(*(_QWORD *)(v6 + 8 * v9));
      *(_QWORD *)(v6 + 8 * v9) = 0;
LABEL_42:
      if ( *(_BYTE *)(a1 + 83) && (_DWORD)v9 )
      {
        v22 = a1 + 144;
        v23 = (unsigned int)v9 - 1LL;
        v24 = *(_QWORD *)(a1 + 144 + 8 * v23);
        if ( v24 )
        {
          gen_pool_destroy(v24);
          *(_QWORD *)(v22 + 8 * v23) = 0;
        }
        if ( (unsigned int)v9 >= 2 )
        {
          v25 = *(_QWORD *)(v22 + 8 * ((unsigned int)v9 - 2LL));
          if ( v25 )
          {
            gen_pool_destroy(v25);
            *(_QWORD *)(v22 + 8 * ((unsigned int)v9 - 2LL)) = 0;
          }
        }
      }
      goto LABEL_49;
    }
    v9 = (__int64)&unk_393000;
    if ( (debug_mdl & 0x40) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_setup_cb",
        4553,
        "cb: %s Shared mem start->%lX len->%zu",
        *(const char **)(a1 + 32),
        *(_QWORD *)(a1 + 2232),
        *(_QWORD *)(a1 + 2240));
    if ( *(int *)(a1 + 1640) < 2 )
    {
      LODWORD(v9) = 1;
    }
    else
    {
      v16 = gen_pool_create(16, 0xFFFFFFFFLL);
      *(_QWORD *)(a1 + 152) = v16;
      if ( !v16 )
      {
        v8 = 0;
        LODWORD(v9) = 1;
        goto LABEL_42;
      }
      v17 = gen_pool_add_owner(v16, *(_QWORD *)(a1 + 2904), -1, *(_QWORD *)(a1 + 2912), 0xFFFFFFFFLL, 0);
      if ( v17 )
      {
        v8 = v17;
        v9 = 1;
        goto LABEL_7;
      }
      if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40,
          4,
          "cam_smmu_setup_cb",
          4553,
          "cb: %s Shared mem start->%lX len->%zu",
          *(const char **)(a1 + 32),
          *(_QWORD *)(a1 + 2904),
          *(_QWORD *)(a1 + 2912));
      if ( *(int *)(a1 + 1640) > 2 )
      {
        gen_pool_create(16, 0xFFFFFFFFLL);
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v19 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &cam_smmu_init_scratch_map__alloc_tag;
        v21 = _kvmalloc_node_noprof(v20 & 0x3FFFFFF8, 0, 3520, 0xFFFFFFFFLL);
        *(_QWORD *)(StatusReg + 80) = v19;
        *(_QWORD *)(a1 + 112) = v21;
        if ( v21 )
          goto LABEL_18;
        goto LABEL_40;
      }
      LODWORD(v9) = 2;
    }
LABEL_9:
    if ( !*(_BYTE *)(a1 + 81) )
      goto LABEL_19;
    v10 = *(_QWORD *)(a1 + 168);
    if ( (v10 & 0xFFFFFFFF000LL) != 0 )
    {
      v6 = *(_QWORD *)(a1 + 160);
      v2 = (unsigned int)(v10 >> 12) + 63LL;
      if ( mem_trace_en == 1 )
      {
        v11 = cam_mem_trace_alloc((v2 >> 3) & 0x3FFFFFF8, 0xCC0u, 0, "cam_smmu_init_scratch_map", 0x530u);
        *(_QWORD *)(a1 + 112) = v11;
        if ( !v11 )
          goto LABEL_40;
        goto LABEL_18;
      }
      v12 = _kvmalloc_node_noprof((v2 >> 3) & 0x3FFFFFF8, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(a1 + 112) = v12;
      if ( v12 )
      {
LABEL_18:
        *(_QWORD *)(a1 + 136) = v6;
        *(_QWORD *)(a1 + 120) = (unsigned int)v2 & 0xFFFFFFC0;
        *(_DWORD *)(a1 + 128) = 0;
LABEL_19:
        if ( *(_BYTE *)(a1 + 84) )
        {
          domain_for_dev = iommu_get_domain_for_dev(a2);
          *(_QWORD *)(a1 + 8) = domain_for_dev;
          if ( domain_for_dev && domain_for_dev < 0xFFFFFFFFFFFFF001LL )
          {
            cam_smmu_util_iommu_custom();
            v8 = 0;
            *(_DWORD *)(a1 + 8484) = 0;
            return v8;
          }
          v14 = "Error: create domain Failed";
          v15 = 4574;
        }
        else
        {
          v14 = "Context bank does not have IO region";
          v15 = 4585;
        }
        goto LABEL_41;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_init_scratch_map",
        1324,
        "Page count is zero, size passed = %zu",
        v10);
    }
LABEL_40:
    v14 = "Error: failed to create scratch map";
    v15 = 4564;
LABEL_41:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_setup_cb",
      v15,
      v14);
    v8 = -19;
    goto LABEL_42;
  }
  v8 = 0;
LABEL_49:
  if ( *(_BYTE *)(a1 + 81) )
  {
    v26 = *(_QWORD **)(a1 + 112);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v26, 0);
    else
      kvfree(v26);
    *(_QWORD *)(a1 + 112) = 0;
  }
  return v8;
}
