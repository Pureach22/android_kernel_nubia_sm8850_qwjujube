__int64 __fastcall init_smmu(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  __int64 v8; // x0
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x21
  int v12; // w8
  unsigned __int64 domain_for_dev; // x0
  __int64 v14; // x3
  unsigned __int64 v15; // x4
  unsigned __int64 *v16; // x25
  __int64 v17; // x22
  __int64 v18; // x4
  unsigned __int64 v19; // x0
  __int64 v20; // x3
  __int64 v21; // x4
  unsigned int v22; // w22
  unsigned int variable_u32_array; // w0
  int v24; // w9
  int v25; // w8
  __int64 *v26; // x0
  __int64 v27; // x4
  __int64 *v28; // x21
  unsigned int v29; // w0
  __int64 v30; // x4
  unsigned int v31; // w0
  int v32; // w8
  __int64 result; // x0
  __int64 v34; // x22
  unsigned int v35; // w19
  unsigned int v36; // w25
  __int64 v37; // x3
  __int64 v38; // x4
  __int64 v39; // x20
  __int64 v40; // x22
  __int64 v41; // x3
  __int64 v42; // x4
  __int64 v43; // x4
  unsigned int v44; // w19
  unsigned int v45; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v46[2]; // [xsp+10h] [xbp-10h] BYREF

  v6 = v5;
  v46[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( a1 )
      goto LABEL_3;
LABEL_32:
    printk(&unk_1905C, "init_smmu", 386, v6, a5);
    result = 4294967274LL;
    goto LABEL_56;
  }
  printk(&unk_1E83A, "init_smmu", 378, a4, a5);
  if ( !a1 )
    goto LABEL_32;
LABEL_3:
  v8 = _kmalloc_cache_noprof(irq_set_irq_wake, 3520, 24);
  v11 = v8;
  if ( !v8 )
  {
    result = 4294967284LL;
    goto LABEL_54;
  }
  v12 = msm_hfi_core_debug_level;
  *(_QWORD *)(a1 + 728) = v8;
  if ( (~v12 & 0x10001) == 0 )
  {
    printk(&unk_1E83A, "get_drv_domain", 34, v9, v10);
    if ( *(_QWORD *)a1 )
      goto LABEL_6;
LABEL_34:
    v34 = v6;
    printk(&unk_19CD1, "get_drv_domain", 37, v6, v10);
    v35 = -22;
    goto LABEL_35;
  }
  if ( !*(_QWORD *)a1 )
    goto LABEL_34;
LABEL_6:
  domain_for_dev = iommu_get_domain_for_dev();
  v15 = domain_for_dev;
  *(_QWORD *)(v11 + 16) = domain_for_dev;
  if ( !domain_for_dev || domain_for_dev > 0xFFFFFFFFFFFFF000LL )
  {
    v34 = v6;
    printk(&unk_1DFF4, "get_drv_domain", 44, v6, domain_for_dev);
    if ( !*(_DWORD *)(v11 + 16) )
      goto LABEL_10;
    v35 = *(_DWORD *)(v11 + 16);
LABEL_35:
    printk(&unk_1A2E8, "init_smmu", 400, v34, v15);
    result = v35;
    goto LABEL_54;
  }
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1C28B, "get_drv_domain", 48, v14, domain_for_dev);
LABEL_10:
  v16 = *(unsigned __int64 **)(a1 + 728);
  v45 = 0;
  v46[0] = 0;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    v17 = *(_QWORD *)a1;
    if ( *(_QWORD *)a1 )
      goto LABEL_12;
LABEL_39:
    printk(&unk_19CD1, "parse_dt_props", 65, v6, v15);
    v22 = -22;
    goto LABEL_41;
  }
  printk(&unk_1E83A, "parse_dt_props", 62, v14, v15);
  v17 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
    goto LABEL_39;
LABEL_12:
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(v17 + 744), "soccp_controller", &v45, 1, 0) & 0x80000000) != 0 )
  {
    if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
      printk(&unk_19616, "parse_dt_props", 74, v45, v18);
    goto LABEL_20;
  }
  v19 = rproc_get_by_phandle(v45);
  *v16 = v19;
  if ( v19 && v19 < 0xFFFFFFFFFFFFF001LL )
  {
LABEL_20:
    variable_u32_array = of_property_read_variable_u32_array(
                           *(_QWORD *)(v17 + 744),
                           "qcom,device-map-addr-reg",
                           v46,
                           2,
                           0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      v22 = variable_u32_array;
      printk(&unk_1B38E, "parse_dt_props", 86, v6, variable_u32_array);
    }
    else
    {
      v24 = HIDWORD(v46[0]);
      v22 = 0;
      *(_QWORD *)(a1 + 304) = LODWORD(v46[0]);
      *(_DWORD *)(a1 + 312) = v24;
    }
    goto LABEL_22;
  }
  if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
    printk(&unk_1EF49, "parse_dt_props", 78, v45, v21);
  v22 = -517;
LABEL_22:
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1C28B, "parse_dt_props", 93, v20, v21);
    if ( !v22 )
      goto LABEL_24;
LABEL_41:
    printk(&unk_1D8C3, "init_smmu", 406, v6, v21);
    result = v22;
    goto LABEL_54;
  }
  if ( v22 )
    goto LABEL_41;
LABEL_24:
  v25 = msm_hfi_core_debug_level;
  *(_QWORD *)(v11 + 8) = *(_QWORD *)(a1 + 304);
  if ( (~v25 & 0x10001) == 0 )
    printk(&unk_1E83A, "hfi_init_fw_trace_mem", 293, v20, v21);
  v26 = (__int64 *)_kmalloc_cache_noprof(devm_free_irq, 3520, 40);
  v28 = v26;
  if ( v26 )
  {
    v26[3] = 258048;
    v26[4] = 256000;
    v29 = smmu_alloc_and_map_for_drv((_QWORD *)a1, v26, 0x3F000u, v26 + 1, 1);
    if ( v29 )
    {
      v36 = v29;
      printk(&unk_1B782, "hfi_init_fw_trace_mem", 310, v6, v29);
    }
    else
    {
      _memset_io(v28[1], 0, v28[3]);
      v31 = smmu_mmap_debug_trace_mem_for_fw(a1, *v28, v28 + 2, v28[3], v30);
      if ( !v31 )
      {
        v32 = msm_hfi_core_debug_level;
        *(_QWORD *)(a1 + 808) = v28;
        if ( (~v32 & 0x10001) == 0 )
        {
          printk(&unk_1B7BA, "hfi_init_fw_trace_mem", 327, v28[1], v28[2]);
          if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
            printk(&unk_1C28B, "hfi_init_fw_trace_mem", 329, v9, v10);
        }
        result = 0;
        goto LABEL_54;
      }
      v36 = v31;
      printk(&unk_1E041, "hfi_init_fw_trace_mem", 319, v6, v31);
      v39 = v28[1];
      if ( v39 )
      {
        v40 = v28[3];
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          printk(&unk_1E83A, "smmu_unmap_for_drv", 162, v37, v38);
        free_pages_exact(v39, v40);
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          printk(&unk_1C28B, "smmu_unmap_for_drv", 167, v41, v42);
      }
      v28[1] = 0;
    }
    v28[3] = 0;
    kfree(v28);
  }
  else
  {
    printk(&unk_1AAC2, "hfi_init_fw_trace_mem", 297, v6, v27);
    v36 = -12;
  }
  printk(&unk_1988E, "init_smmu", 414, v6, v43);
  result = v36;
LABEL_54:
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v44 = result;
    printk(&unk_1C28B, "init_smmu", 419, v9, v10);
    result = v44;
  }
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
