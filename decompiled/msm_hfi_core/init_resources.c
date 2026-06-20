__int64 __fastcall init_resources(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int *v5; // x30
  unsigned int *v6; // x23
  __int64 v8; // x3
  __int64 v9; // x4
  __int64 v10; // x21
  int v11; // w8
  __int64 v12; // x20
  unsigned int v13; // w5
  int v14; // w0
  __int64 v15; // x3
  __int64 v16; // x4
  int v17; // w8
  __int64 v18; // x3
  __int64 v19; // x4
  int v20; // w8
  __int64 v21; // x20
  unsigned int *v22; // x25
  unsigned int *v23; // x22
  int v24; // w8
  unsigned __int64 v25; // x21
  unsigned int *v26; // x27
  int v27; // w8
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v31; // x4
  unsigned int v32; // w20
  __int64 v33; // x3
  __int64 v34; // x4
  unsigned int inited; // w0
  __int64 v36; // x3
  __int64 v37; // x4
  int v38; // w20
  unsigned int *v39; // x20
  unsigned __int64 StatusReg; // x20
  __int64 v41; // x22
  unsigned int *v42; // [xsp+8h] [xbp-8h]

  v6 = v5;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_49:
      printk(&unk_1905C, "init_resources", 673, v6, a5);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_1E83A, "init_resources", 664, a4, a5);
    if ( !a1 )
      goto LABEL_49;
  }
  if ( !*(_QWORD *)(a1 + 288) )
    goto LABEL_49;
  v10 = _kmalloc_cache_noprof(snprintf, 3520, 552);
  if ( !v10 )
    goto LABEL_81;
  while ( 1 )
  {
    *(_QWORD *)(a1 + 280) = v10;
    v11 = msm_hfi_core_debug_level;
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      printk(&unk_1E83A, "hfi_create_resource_mem", 599, v8, v9);
      v11 = msm_hfi_core_debug_level;
      v10 = *(_QWORD *)(a1 + 280);
    }
    v12 = *(_QWORD *)(a1 + 288);
    if ( (~v11 & 0x10001) == 0 )
      printk(&unk_1E83A, "hfi_create_tbl_and_res_hdrs_mem", 302, v8, v9);
    v13 = *(_DWORD *)(v12 + 16);
    *(_DWORD *)v10 = v13;
    if ( v13 >= 3 )
    {
      printk(&unk_1EF92, "hfi_create_tbl_and_res_hdrs_mem", 307, v6, 2);
LABEL_51:
      v14 = -22;
      goto LABEL_67;
    }
    *(_QWORD *)(v10 + 40) += 24LL * v13 + 20;
    v14 = allocate_and_map(a1, v10 + 8);
    if ( v14 )
      goto LABEL_67;
    v17 = msm_hfi_core_debug_level;
    if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
    {
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        goto LABEL_53;
    }
    else
    {
      printk(&unk_1B47B, "hfi_create_tbl_and_res_hdrs_mem", 323, *(_QWORD *)(v10 + 8), *(_QWORD *)(v10 + 16));
      v17 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      {
LABEL_53:
        printk(&unk_1A868, "hfi_create_tbl_and_res_hdrs_mem", 327, *(_QWORD *)(v10 + 16), *(_QWORD *)(v10 + 24));
        if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
          goto LABEL_14;
        goto LABEL_54;
      }
    }
    if ( (~v17 & 0x10001) != 0 )
      goto LABEL_14;
LABEL_54:
    printk(&unk_1C28B, "hfi_create_tbl_and_res_hdrs_mem", 329, v15, v16);
LABEL_14:
    v14 = hfi_res_mem_op(a1, 1);
    if ( v14 )
      goto LABEL_67;
    v20 = msm_hfi_core_debug_level;
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    {
      printk(&unk_1C28B, "hfi_create_resource_mem", 610, v18, v19);
      v20 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      {
        printk(&unk_1E83A, "hfi_populate_resource_mem", 619, v18, v19);
        v20 = msm_hfi_core_debug_level;
      }
    }
    v22 = *(unsigned int **)(a1 + 280);
    v21 = *(_QWORD *)(a1 + 288);
    if ( (~v20 & 0x10001) == 0 )
      printk(&unk_1E83A, "hfi_populate_tbl_and_res_hdrs_mem", 467, v18, v19);
    v23 = *((unsigned int **)v22 + 2);
    *v23 = *(_DWORD *)(v21 + 4);
    *(_QWORD *)(v23 + 1) = 0x1400000014LL;
    v23[3] = 24;
    v24 = msm_hfi_core_debug_level;
    v23[4] = *v22;
    if ( (~v24 & 0x10008) != 0
      || (printk(&unk_1DCFC, "_dbg_dump_table_header", 335, v23, v19),
          v24 = msm_hfi_core_debug_level,
          (~msm_hfi_core_debug_level & 0x10008) != 0) )
    {
      if ( (~v24 & 0x10008) != 0 )
        goto LABEL_20;
    }
    else
    {
      printk(&unk_1A3D6, "_dbg_dump_table_header", 336, *v23, v19);
      v24 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
      {
LABEL_20:
        if ( (~v24 & 0x10008) != 0 )
          goto LABEL_21;
        goto LABEL_60;
      }
    }
    printk(&unk_1A360, "_dbg_dump_table_header", 337, v23[1], v19);
    v24 = msm_hfi_core_debug_level;
    if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
    {
LABEL_21:
      if ( (~v24 & 0x10008) == 0 )
        goto LABEL_61;
      goto LABEL_22;
    }
LABEL_60:
    printk(&unk_1E274, "_dbg_dump_table_header", 338, v23[2], v19);
    v24 = msm_hfi_core_debug_level;
    if ( (~msm_hfi_core_debug_level & 0x10008) == 0 )
    {
LABEL_61:
      printk(&unk_1DD39, "_dbg_dump_table_header", 339, v23[3], v19);
      v24 = msm_hfi_core_debug_level;
    }
LABEL_22:
    v42 = v6;
    if ( (~v24 & 0x10008) != 0
      || (printk(&unk_1A146, "_dbg_dump_table_header", 340, v23[4], v19), (~msm_hfi_core_debug_level & 0x10008) != 0) )
    {
      if ( !*v22 )
        break;
      goto LABEL_24;
    }
    printk(&unk_1C9B0, "_dbg_dump_table_header", 341, v18, v19);
    if ( !*v22 )
      break;
LABEL_24:
    v25 = 0;
    v6 = v22 + 16;
    v26 = (unsigned int *)(*((_QWORD *)v22 + 2) + v23[2]);
    while ( 1 )
    {
      *v26 = *(_DWORD *)(v21 + 8);
      if ( v25 == 2 )
        break;
      v19 = *(unsigned int *)(v21 + 20 + 4 * v25);
      if ( (_DWORD)v19 != 2 )
      {
        if ( (_DWORD)v19 != 1 )
        {
          v39 = v42;
          printk(&unk_1998F, "hfi_populate_tbl_and_res_hdrs_mem", 496, v42, v19);
LABEL_79:
          printk(&unk_1D6EE, "hfi_populate_tbl_and_res_hdrs_mem", 500, v39, (unsigned int)v25);
          goto LABEL_51;
        }
        if ( v22 == (unsigned int *)-64LL || !v26 )
        {
          v39 = v42;
          printk(&unk_1905C, "populate_virtq_res_hdr", 440, v42, v19);
          goto LABEL_79;
        }
        *(_QWORD *)(v26 + 1) = 0x100000001LL;
        v26[3] = v22[21];
        v26[4] = *((_QWORD *)v22 + 10);
        v26[5] = *((_QWORD *)v22 + 12);
      }
      v27 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) != 0
        || (printk(&unk_1A401, "_dbg_dump_res_header", 346, (unsigned int)v25, v26),
            v27 = msm_hfi_core_debug_level,
            (~msm_hfi_core_debug_level & 0x10008) != 0) )
      {
        if ( (~v27 & 0x10008) != 0 )
          goto LABEL_34;
      }
      else
      {
        printk(&unk_1A3D6, "_dbg_dump_res_header", 347, *v26, v19);
        v27 = msm_hfi_core_debug_level;
        if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
        {
LABEL_34:
          if ( (~v27 & 0x10008) != 0 )
            goto LABEL_35;
          goto LABEL_43;
        }
      }
      printk(&unk_1C988, "_dbg_dump_res_header", 348, v26[1], v19);
      v27 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
      {
LABEL_35:
        if ( (~v27 & 0x10008) != 0 )
          goto LABEL_36;
        goto LABEL_44;
      }
LABEL_43:
      printk(&unk_19709, "_dbg_dump_res_header", 349, v26[2], v19);
      v27 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
      {
LABEL_36:
        if ( (~v27 & 0x10008) != 0 )
          goto LABEL_37;
        goto LABEL_45;
      }
LABEL_44:
      printk(&unk_1EC47, "_dbg_dump_res_header", 350, v26[3], v19);
      v27 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
      {
LABEL_37:
        if ( (~v27 & 0x10008) == 0 )
          goto LABEL_46;
        goto LABEL_38;
      }
LABEL_45:
      printk(&unk_1A442, "_dbg_dump_res_header", 351, v26[4], v19);
      v27 = msm_hfi_core_debug_level;
      if ( (~msm_hfi_core_debug_level & 0x10008) == 0 )
      {
LABEL_46:
        printk(&unk_1A360, "_dbg_dump_res_header", 352, v26[5], v19);
        if ( (~msm_hfi_core_debug_level & 0x10008) != 0 )
          goto LABEL_25;
LABEL_39:
        printk(&unk_1EFE0, "_dbg_dump_res_header", 353, (unsigned int)v25, v19);
        goto LABEL_25;
      }
LABEL_38:
      if ( (~v27 & 0x10008) == 0 )
        goto LABEL_39;
LABEL_25:
      ++v25;
      v26 += 6;
      if ( v25 >= *v22 )
        goto LABEL_64;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v41 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &init_resources__alloc_tag;
    v10 = _kmalloc_cache_noprof(snprintf, 3520, 552);
    *(_QWORD *)(StatusReg + 80) = v41;
    if ( !v10 )
    {
LABEL_81:
      printk(&unk_1E8EF, "init_resources", 679, v6, v9);
      return 4294967284LL;
    }
  }
LABEL_64:
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_populate_tbl_and_res_hdrs_mem", 507, v18, v19);
  v14 = hfi_res_mem_op(a1, 2);
  if ( v14 )
    goto LABEL_67;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "hfi_populate_resource_mem", 630, v30, v31);
  inited = init_queues(1u, a1, v29, v30, v31);
  if ( inited )
  {
    v38 = inited;
    printk(&unk_190E9, "init_resources", 698, v42, inited);
    v14 = v38;
LABEL_67:
    v32 = v14;
    deinit_resources(a1);
    if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
      printk(&unk_1C28B, "init_resources", 707, v33, v34);
    return v32;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "init_resources", 702, v36, v37);
  return 0;
}
