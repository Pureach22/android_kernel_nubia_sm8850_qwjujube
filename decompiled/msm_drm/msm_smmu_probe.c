__int64 __fastcall msm_smmu_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 matched; // x0
  __int64 v4; // x22
  __int64 result; // x0
  __int64 v6; // x21
  _QWORD *v7; // x0
  _QWORD *v8; // x23
  __int64 domain_for_dev; // x0
  _DWORD *v10; // x8
  char v11; // w10
  __int64 v12; // x21
  __int64 v13; // x8
  long double v14; // q0
  __int64 v15; // x1
  unsigned int v16; // w19

  v1 = a1 + 16;
  matched = of_match_device(&_mod_of__msm_smmu_dt_match_device_table, a1 + 16);
  if ( !matched || (v4 = *(_QWORD *)(matched + 192)) == 0 )
  {
    dev_err(v1, "[%s:%d] probe failed as match data is invalid\n", "msm_smmu_probe", 554);
    return 4294967274LL;
  }
  v6 = matched + 64;
  printk(&unk_22968A, matched + 64);
  v7 = (_QWORD *)devm_kmalloc(v1, 64, 3520);
  if ( !v7 )
    return 4294967284LL;
  *v7 = v1;
  v8 = v7;
  domain_for_dev = iommu_get_domain_for_dev(v1);
  v8[3] = domain_for_dev;
  if ( !domain_for_dev )
  {
    dev_err(v1, "[%s:%d] iommu get domain for dev failed\n", "msm_smmu_probe", 573);
    return 4294967274LL;
  }
  v8[2] = v6;
  v10 = *(_DWORD **)(a1 + 688);
  v11 = *(_BYTE *)(v4 + 8);
  *((_BYTE *)v8 + 40) = 1;
  *((_BYTE *)v8 + 41) = v11;
  if ( v10
    || (v12 = domain_for_dev,
        v10 = (_DWORD *)devm_kmalloc(v1, 16, 3520),
        domain_for_dev = v12,
        (*(_QWORD *)(a1 + 688) = v10) != 0) )
  {
    *v10 = -1;
    v13 = *(_QWORD *)(a1 + 688);
    if ( v13 )
    {
LABEL_13:
      *(_QWORD *)(v13 + 8) = -1;
      goto LABEL_14;
    }
  }
  else
  {
    __break(0x800u);
    v13 = *(_QWORD *)(a1 + 688);
    if ( v13 )
      goto LABEL_13;
  }
  __break(0x800u);
LABEL_14:
  iommu_set_fault_handler(domain_for_dev, msm_smmu_fault_handler, v8);
  printk(&unk_26B129, *(_QWORD *)v4);
  *(_QWORD *)(a1 + 168) = v8;
  mutex_lock(&smmu_list_lock);
  list_add_0(v8 + 6);
  mutex_unlock(&smmu_list_lock);
  result = component_add(v1, msm_smmu_comp_ops, v14);
  if ( (_DWORD)result )
  {
    v16 = result;
    printk(&unk_27C03D, v15);
    return v16;
  }
  return result;
}
