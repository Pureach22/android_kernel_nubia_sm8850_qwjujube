unsigned __int64 __fastcall arm_smmu_device_probe(_QWORD *a1)
{
  _QWORD *v2; // x19
  __int64 v3; // x0
  __int64 *v4; // x21
  __int64 v5; // x0
  _DWORD *match_data; // x0
  int v7; // w8
  __int64 v8; // x0
  char *v9; // x8
  unsigned __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x9
  unsigned __int64 v14; // x21
  unsigned int v15; // w0
  unsigned int v16; // w8
  int v17; // w9
  bool v18; // zf
  __int64 v19; // x0
  int v20; // w3
  __int64 v21; // x22
  __int64 irq; // x0
  __int64 v23; // x0
  unsigned __int64 v24; // x19
  unsigned int v25; // w3
  unsigned int v26; // w2
  __int64 v27; // x8
  __int64 (__fastcall *v28)(); // x22
  unsigned int v29; // w23
  unsigned int v30; // w25
  unsigned int v31; // w0
  _QWORD *resource; // x0
  __int64 v33; // x0
  __int64 v34; // x22
  unsigned __int64 v35; // x20
  _QWORD *v36; // x2
  __int64 v37; // x0
  __int64 v38; // x20
  unsigned int v39; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v40[2]; // [xsp+10h] [xbp-10h] BYREF

  v40[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40[0] = 0;
  v39 = 0;
  if ( (qcom_dma_iommu_is_ready() & 1) == 0 )
  {
    result = 4294966779LL;
    goto LABEL_66;
  }
  v2 = a1 + 2;
  v3 = devm_kmalloc(a1 + 2, 328, 3520);
  if ( !v3 )
  {
    dev_err(a1 + 2, "failed to allocate arm_smmu_device\n");
    result = 4294967284LL;
    goto LABEL_66;
  }
  v4 = (__int64 *)v3;
  v5 = a1[95];
  *v4 = (__int64)v2;
  if ( !v5 )
  {
    result = 4294967277LL;
    goto LABEL_66;
  }
  if ( (of_property_read_variable_u32_array(v5, "#global-interrupts", &v39, 1, 0) & 0x80000000) == 0 )
  {
    match_data = (_DWORD *)of_device_get_match_data(a1 + 2);
    *((_DWORD *)v4 + 10) = *match_data;
    v7 = match_data[1];
    v8 = a1[95];
    *((_DWORD *)v4 + 11) = v7;
    if ( of_find_property(v8, "mmu-masters", 0) )
    {
      if ( (using_generic_binding & 1) == 0 )
      {
        v9 = &using_legacy_binding;
        if ( (using_legacy_binding & 1) == 0 )
        {
          printk(&unk_18481, "SMMU");
          v9 = &using_legacy_binding;
        }
        goto LABEL_15;
      }
    }
    else if ( using_legacy_binding != 1 )
    {
      v9 = &using_generic_binding;
LABEL_15:
      v11 = a1[95];
      *v9 = 1;
      if ( (of_dma_is_coherent(v11) & 1) != 0 )
        *((_DWORD *)v4 + 8) |= 1u;
      if ( of_find_property(*(_QWORD *)(*v4 + 744), "qcom,fatal-asf", 0) )
        *((_DWORD *)v4 + 9) |= 1u;
      if ( of_find_property(*(_QWORD *)(*v4 + 744), "qcom,use-3-lvl-tables", 0) )
        *((_DWORD *)v4 + 9) |= 4u;
      if ( of_find_property(*(_QWORD *)(*v4 + 744), "qcom,no-asid-retention", 0) )
        *((_DWORD *)v4 + 9) |= 8u;
      if ( of_find_property(*(_QWORD *)(*v4 + 744), "qcom,disable-atos", 0) )
        *((_DWORD *)v4 + 9) |= 0x10u;
      if ( of_find_property(*(_QWORD *)(*v4 + 744), "qcom,context-fault-retry", 0) )
        *((_DWORD *)v4 + 9) |= 0x20u;
      if ( of_find_property(*(_QWORD *)(*v4 + 744), "qcom,multi-match-handoff-smr", 0) )
        *((_DWORD *)v4 + 9) |= 0x40u;
      if ( of_find_property(*(_QWORD *)(*v4 + 744), "qcom,ignore-numpagendxb", 0) )
        *((_DWORD *)v4 + 9) |= 0x80u;
      goto LABEL_31;
    }
    dev_err(a1 + 2, "not probing due to mismatched DT properties\n");
    result = 4294967277LL;
    goto LABEL_66;
  }
  result = dev_err_probe(a1 + 2, 4294967277LL, "missing #global-interrupts property\n");
  if ( (_DWORD)result )
    goto LABEL_66;
LABEL_31:
  result = devm_platform_get_and_ioremap_resource(a1, 0, v40);
  v4[1] = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_66;
  v12 = v40[0];
  v13 = *(_QWORD *)v40[0];
  v4[2] = *(_QWORD *)v40[0];
  *((_DWORD *)v4 + 6) = *(_DWORD *)(v12 + 8) - v13 + 1;
  result = arm_smmu_impl_init(v4);
  v14 = result;
  if ( result >= 0xFFFFFFFFFFFFF001LL )
  {
    result = (unsigned int)result;
    goto LABEL_66;
  }
  v15 = platform_irq_count(a1);
  v16 = v39;
  v17 = v15 - v39;
  v18 = v15 == v39;
  *(_DWORD *)(v14 + 200) = v15 - v39;
  if ( v17 < 0 || v18 )
  {
    result = dev_err_probe(a1 + 2, 4294967277LL, "found %d interrupts but expected at least %d\n", v15, v16 + 1);
    goto LABEL_66;
  }
  v19 = devm_kmalloc(a1 + 2, 4LL * (unsigned int)v17, 3520);
  v20 = *(_DWORD *)(v14 + 200);
  *(_QWORD *)(v14 + 208) = v19;
  if ( !v19 )
  {
    result = dev_err_probe(a1 + 2, 4294967284LL, "failed to allocate %d irqs\n", v20);
    goto LABEL_66;
  }
  if ( v20 < 1 )
  {
LABEL_40:
    result = arm_smmu_init_power_resources(a1 + 2);
    *(_QWORD *)(v14 + 304) = result;
    if ( result >= 0xFFFFFFFFFFFFF001LL )
      goto LABEL_66;
    result = arm_smmu_power_on();
    if ( (_DWORD)result )
      goto LABEL_66;
    v23 = arm_smmu_device_cfg_probe(v14);
    if ( !(_DWORD)v23 )
    {
      if ( *(_DWORD *)(v14 + 40) == 2 )
      {
        v25 = *(_DWORD *)(v14 + 56);
        v26 = *(_DWORD *)(v14 + 200);
        if ( v25 > v26 )
        {
          dev_err(a1 + 2, "found only %d context irq(s) but %d required\n", v26, v25);
          v23 = 4294967277LL;
          goto LABEL_48;
        }
        *(_DWORD *)(v14 + 200) = v25;
      }
      v27 = *(_QWORD *)(v14 + 48);
      if ( !v27 || (v28 = *(__int64 (__fastcall **)())(v27 + 112)) == nullptr )
        v28 = arm_smmu_global_fault;
      if ( v39 )
      {
        v29 = 0;
        do
        {
          result = platform_get_irq(a1, v29);
          if ( (result & 0x80000000) != 0 )
            goto LABEL_66;
          v30 = result;
          v31 = devm_request_threaded_irq(a1 + 2, result, v28, 0, 128, "arm-smmu global fault", v14);
          if ( v31 )
          {
            result = dev_err_probe(a1 + 2, v31, "failed to request global IRQ %d (%u)\n", v29, v30);
            goto LABEL_66;
          }
        }
        while ( ++v29 < v39 );
      }
      resource = (_QWORD *)platform_get_resource(a1, 512, 0);
      v40[0] = resource;
      if ( resource )
      {
        *(_QWORD *)(v14 + 312) = *resource;
        v23 = arm_smmu_handoff_cbs(v14);
        if ( !(_DWORD)v23 )
        {
          v33 = iommu_device_sysfs_add(v14 + 232, *(_QWORD *)v14, 0, "smmu.%pa", (const void *)(v14 + 16));
          if ( (_DWORD)v33 )
          {
            v38 = v33;
            dev_err(v2, "Failed to register iommu in sysfs\n");
            v23 = v38;
          }
          else
          {
            v34 = register_qcom_iommu_ops(arm_smmu_ops);
            if ( !(_DWORD)v34 )
            {
              if ( using_legacy_binding )
                v36 = nullptr;
              else
                v36 = a1 + 2;
              v37 = iommu_device_register(v14 + 232, &off_D70, v36);
              if ( !(_DWORD)v37 )
              {
                a1[21] = v14;
                arm_smmu_rmr_install_bypass_smr(v14);
                arm_smmu_device_reset(v14);
                arm_smmu_test_smr_masks(v14);
                if ( *(_DWORD *)(*(_QWORD *)(v14 + 304) + 32LL) || a1[76] )
                {
                  _pm_runtime_set_status(a1 + 2, 0);
                  pm_runtime_enable(a1 + 2);
                }
                result = 0;
                goto LABEL_66;
              }
              v34 = v37;
              dev_err(a1 + 2, "Failed to register iommu\n");
            }
            iommu_device_sysfs_remove(v14 + 232);
            v23 = v34;
          }
        }
      }
      else
      {
        dev_err(a1 + 2, "Failed to get mem resource\n");
        v23 = 4294967290LL;
      }
    }
LABEL_48:
    v24 = v23;
    arm_smmu_power_off(v14, *(_QWORD *)(v14 + 304));
    result = v24;
    goto LABEL_66;
  }
  v21 = 0;
  while ( 1 )
  {
    irq = platform_get_irq(a1, (unsigned int)v21 + v39);
    if ( (irq & 0x80000000) != 0 )
      break;
    *(_DWORD *)(*(_QWORD *)(v14 + 208) + 4 * v21++) = irq;
    if ( v21 >= *(int *)(v14 + 200) )
      goto LABEL_40;
  }
  v35 = irq;
  dev_err(v2, "failed to get irq index %d, error: %d\n", v39 + v21, irq);
  result = v35;
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return result;
}
