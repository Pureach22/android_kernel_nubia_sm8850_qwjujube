__int64 __fastcall hw_fence_utils_alloc_mem(_QWORD *a1)
{
  __int64 v1; // x30
  __int64 v3; // x20
  __int64 compatible_node; // x0
  __int64 v5; // x21
  __int64 v6; // x4
  unsigned int v7; // w0
  __int64 v8; // x0
  __int64 v9; // x4
  __int64 v10; // x4
  unsigned int v11; // w22
  __int64 v12; // x0
  __int64 v13; // x8
  unsigned __int64 v14; // x12
  __int64 v15; // x9
  __int64 v16; // x8
  __int64 v17; // x4
  int v18; // w8
  __int64 v19; // x0
  unsigned __int64 v20; // x5
  __int64 v21; // x8
  __int64 v22; // x4
  __int64 v23; // x3
  __int64 v24; // x0
  int v25; // w0
  unsigned __int64 domain_for_dev; // x0
  unsigned int v27; // w22
  unsigned int v28; // w0
  unsigned int variable_u32_array; // w0
  _DWORD *v30; // x22
  int v31; // w0
  unsigned int v32; // w21
  int v33; // w0
  __int64 v34; // x19
  __int64 v35; // x30
  void *v36; // x0
  const char *v37; // x1
  __int64 v38; // x2
  __int64 v39; // x4
  int v40; // w22
  const char *v41; // x4
  _QWORD v43[11]; // [xsp+8h] [xbp-58h] BYREF

  v3 = v1;
  v43[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  compatible_node = of_find_compatible_node(*(_QWORD *)(*a1 + 744LL), 0, "qcom,msm-hw-fence-mem");
  v5 = compatible_node;
  if ( !compatible_node )
  {
    if ( (a1[4190] & 1) == 0 )
    {
      printk(&unk_24584, "hw_fence_utils_alloc_mem", 1370, v3, "qcom,msm-hw-fence-mem");
      v27 = -22;
      goto LABEL_72;
    }
    if ( !a1 )
    {
      v34 = v3;
      printk(&unk_29F4A, "_alloc_mem_dynamic", 1331, v3, 0);
      goto LABEL_53;
    }
    v10 = *((unsigned int *)a1 + 115);
    if ( (unsigned int)v10 >= 0xFFFF05FF )
    {
      v34 = v3;
      printk(&unk_24B73, "_alloc_mem_dynamic", 1338, v3, v10);
      goto LABEL_53;
    }
    v11 = (v10 + 68095) & 0xFFFFF000;
    v12 = alloc_pages_exact_noprof(v11, 3264);
    a1[39] = v12;
    if ( v12 )
    {
      v13 = v12 << 8 >> 8;
      v14 = (unsigned __int64)(v13 + 0x8000000000LL) >> 38;
      v15 = memstart_addr + v13 + 0x8000000000LL;
      v16 = v13 - kimage_voffset;
      if ( v14 )
        v17 = v16;
      else
        v17 = v15;
      v18 = msm_hw_fence_debug_level;
      a1[40] = v17;
      a1[41] = v17 + v11 - 1;
      a1[42] = "hwfence_shbuf";
      *((_BYTE *)a1 + 464) = 1;
      if ( (~v18 & 0x10008) == 0 )
        printk(&unk_267FD, "_alloc_mem_dynamic", 1355, v12, v17);
      goto LABEL_19;
    }
    v35 = v3;
    v36 = &unk_267C5;
    v37 = "_alloc_mem_dynamic";
    v38 = 1345;
LABEL_70:
    v34 = v35;
    printk(v36, v37, v38, v35, v6);
    v27 = -12;
    goto LABEL_71;
  }
  if ( !a1 )
  {
    v34 = v3;
    printk(&unk_2052D, "_alloc_mem_static", 1292, v3, 0);
LABEL_53:
    v27 = -22;
    goto LABEL_71;
  }
  memset(v43, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(compatible_node, "shared-buffer", 0, 0, 0, v43) || !v43[0] )
  {
    v35 = v3;
    v36 = &unk_23358;
    v37 = "_alloc_mem_static";
    v38 = 1298;
    goto LABEL_70;
  }
  v7 = of_address_to_resource(v43[0], 0, a1 + 40);
  if ( v7 )
  {
    v34 = v3;
    printk(&unk_26D50, "_alloc_mem_static", 1305, v3, v7);
    goto LABEL_53;
  }
  if ( *((_BYTE *)a1 + 33520) == 1 )
  {
    v8 = memremap();
    a1[39] = v8;
    if ( !v8 )
      goto LABEL_49;
  }
  else
  {
    v19 = devm_ioremap_wc(*a1);
    a1[39] = v19;
    if ( !v19 )
    {
LABEL_49:
      v34 = v3;
      printk(&unk_2510E, "_alloc_mem_static", 1317, v3, v9);
      v27 = -6;
LABEL_71:
      printk(&unk_21955, "hw_fence_utils_alloc_mem", 1380, v34, v27);
      goto LABEL_72;
    }
  }
LABEL_19:
  v20 = *((unsigned int *)a1 + 115);
  v21 = a1[41] - a1[40];
  v22 = v21 + 1;
  a1[52] = v21 + 1;
  if ( v21 + 1 < v20 )
  {
    printk(&unk_2B49B, "hw_fence_utils_alloc_mem", 1387, v3, v22);
    v27 = -12;
    goto LABEL_72;
  }
  v23 = *((unsigned int *)a1 + 3);
  if ( (_DWORD)v23 )
  {
    if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
      printk(&unk_21F03, "hw_fence_utils_alloc_mem", 1395, v23, v22);
  }
  else
  {
    _memset_io(a1[39], 0, v21 + 1);
  }
  if ( (~msm_hw_fence_debug_level & 0x10008) != 0 )
  {
    if ( *((_DWORD *)a1 + 3) )
    {
LABEL_42:
      v27 = 0;
      goto LABEL_72;
    }
  }
  else
  {
    printk(&unk_2AF81, "hw_fence_utils_alloc_mem", 1399, a1[39], a1[40]);
    if ( *((_DWORD *)a1 + 3) )
      goto LABEL_42;
  }
  if ( *((_BYTE *)a1 + 33520) != 1 )
  {
    if ( !v5 )
    {
      printk(&unk_21A18, "_register_vm_mem_with_hyp", 1212, v3, a1);
      goto LABEL_64;
    }
    variable_u32_array = of_property_read_variable_u32_array(v5, "gunyah-label", a1 + 53, 1, 0);
    if ( (variable_u32_array & 0x80000000) != 0 )
    {
      v27 = variable_u32_array;
      printk(&unk_20C86, "_register_vm_mem_with_hyp", 1218, v3, variable_u32_array);
      goto LABEL_65;
    }
    v30 = (_DWORD *)a1 + 107;
    v31 = of_property_read_variable_u32_array(v5, "peer-name", (char *)a1 + 428, 1, 0);
    v32 = v31 & (v31 >> 31);
    if ( v31 < 0 )
      *v30 = 0;
    a1[54] = hw_fence_rm_cb;
    *((_DWORD *)a1 + 112) = 0x7FFFFFFF;
    v33 = gh_rm_register_notifier(a1 + 54);
    if ( (~msm_hw_fence_debug_level & 0x10008) != 0 )
    {
      if ( !v33 )
        goto LABEL_42;
    }
    else
    {
      v39 = (unsigned int)*v30;
      v40 = v33;
      printk(&unk_220E0, "_register_vm_mem_with_hyp", 1231, v32, v39);
      if ( !v40 )
        goto LABEL_42;
    }
    if ( (register_vm_mem_with_hyp___already_done & 1) == 0 )
    {
      register_vm_mem_with_hyp___already_done = 1;
      printk(&unk_2636D, "_register_vm_mem_with_hyp", 1233, v3, v32);
    }
    v27 = -517;
    goto LABEL_65;
  }
  v24 = *(_QWORD *)(*a1 + 744LL);
  LODWORD(v43[0]) = 0;
  v25 = of_property_read_variable_u32_array(v24, "shbuf_soccp_va", v43, 1, 0);
  if ( v25 < 0 || !LODWORD(v43[0]) )
  {
    if ( *((_BYTE *)a1 + 464) != 1 )
    {
      LODWORD(v43[0]) = a1[40];
      goto LABEL_31;
    }
    printk(&unk_2B573, "_init_soccp_mem", 1255, v3, v25 & (unsigned int)(v25 >> 31));
LABEL_64:
    v27 = -22;
    goto LABEL_65;
  }
LABEL_31:
  domain_for_dev = iommu_get_domain_for_dev(*a1);
  v27 = domain_for_dev;
  if ( domain_for_dev && domain_for_dev <= 0xFFFFFFFFFFFFF000LL )
  {
    v28 = iommu_map(domain_for_dev, LODWORD(v43[0]), a1[40], a1[52], 7, 3264);
    if ( !v28 )
    {
      if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
        printk(&unk_23C94, "_init_soccp_mem", 1280, a1[40], LODWORD(v43[0]));
      goto LABEL_42;
    }
    v27 = v28;
    printk(&unk_2566E, "_init_soccp_mem", 1277, v3, a1[40]);
  }
  else
  {
    printk(&unk_274DA, "_init_soccp_mem", 1264, v3, domain_for_dev);
    if ( !v27 )
      goto LABEL_72;
  }
LABEL_65:
  if ( *((_BYTE *)a1 + 33520) )
    v41 = "soccp";
  else
    v41 = (const char *)&unk_21F53;
  printk(&unk_25B9E, "hw_fence_utils_alloc_mem", 1413, v3, v41);
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return v27;
}
