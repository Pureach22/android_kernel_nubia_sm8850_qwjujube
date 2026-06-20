__int64 __fastcall init_swi(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x30
  __int64 v6; // x19
  __int64 v8; // x23
  int variable_u32_array; // w0
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x1
  __int64 v13; // x3
  unsigned int v14; // w0
  int v15; // w8
  __int64 v16; // x23
  __int64 v17; // x0
  _QWORD *resource_byname; // x0
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x0
  _QWORD *v22; // t2
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 result; // x0
  unsigned int v26; // w19
  __int64 v27; // x4
  unsigned int v28; // w20
  __int64 v29; // x30
  unsigned int v30; // w19
  __int64 v31; // x20
  __int64 v32; // x4
  __int64 v33; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v34[2]; // [xsp+10h] [xbp-10h] BYREF

  v6 = v5;
  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
    {
LABEL_25:
      printk(&unk_19CD1, "init_swi", 152, v6, a5);
      result = 4294967274LL;
      goto LABEL_23;
    }
  }
  else
  {
    printk(&unk_1E83A, "init_swi", 144, a4, a5);
    if ( !a1 )
      goto LABEL_25;
  }
  v8 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
    goto LABEL_25;
  v33 = 0;
  v34[0] = 0;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1E83A, "map_mdss_register", 36, a4, a5);
  variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(v8 + 744), "qcom,mdss-reg", v34, 2, 0);
  if ( variable_u32_array < 0 )
  {
    if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
      printk(&unk_1BFA2, "map_mdss_register", 40, variable_u32_array & (unsigned int)(variable_u32_array >> 31), v11);
  }
  else
  {
    v12 = LODWORD(v34[0]);
    v13 = HIDWORD(v34[0]);
    *(_QWORD *)(a1 + 768) = LODWORD(v34[0]);
    *(_DWORD *)(a1 + 776) = v13;
    v14 = smmu_mmap_for_fw(a1, v12, &v33, v13, 3);
    if ( v14 )
    {
      v29 = v6;
      v30 = v14;
      v31 = v29;
      printk(&unk_1A725, "map_mdss_register", 50, v29, v14);
      printk(&unk_18DC2, "init_swi", 158, v31, v32);
      result = v30;
      goto LABEL_21;
    }
    v15 = msm_hfi_core_debug_level;
    *(_QWORD *)(a1 + 784) = v33;
    if ( (~v15 & 0x10001) == 0 )
    {
      printk(&unk_1EB6C, "map_mdss_register", 56, *(_QWORD *)(a1 + 768), *(unsigned int *)(a1 + 776));
      if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
        printk(&unk_1C28B, "map_mdss_register", 58, v10, v11);
    }
  }
  v16 = *(_QWORD *)a1;
  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    v17 = v16 - 16;
    if ( v16 != 16 )
    {
LABEL_14:
      resource_byname = (_QWORD *)platform_get_resource_byname(v17, 512, "swi_dev0");
      if ( !resource_byname )
      {
        if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
          printk(&unk_19663, "map_swi_register", 105, "swi_dev0", v20);
        goto LABEL_20;
      }
      v22 = resource_byname;
      v21 = *resource_byname;
      v23 = v22[1] - v21;
      *(_QWORD *)(a1 + 256) = v21;
      *(_DWORD *)(a1 + 272) = v23 + 1;
      v24 = memremap();
      if ( v24 )
      {
        *(_QWORD *)(a1 + 264) = v24;
        if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
          printk(&unk_1C28B, "map_swi_register", 121, v19, v20);
LABEL_20:
        result = 0;
        goto LABEL_21;
      }
      printk(&unk_1B413, "map_swi_register", 116, v6, v20);
      v28 = -12;
      goto LABEL_32;
    }
  }
  else
  {
    printk(&unk_1E83A, "map_swi_register", 89, v10, v11);
    v17 = v16 - 16;
    if ( v16 != 16 )
      goto LABEL_14;
  }
  printk(&unk_1B3CD, "map_swi_register", 100, v6, 1);
  v28 = -22;
LABEL_32:
  printk(&unk_1EB36, "init_swi", 164, v6, v27);
  result = v28;
LABEL_21:
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    v26 = result;
    printk(&unk_1C28B, "init_swi", 169, v19, v20);
    result = v26;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
