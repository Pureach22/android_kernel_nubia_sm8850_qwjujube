__int64 __fastcall msm_vidc_component_bind(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  _QWORD *context_bank_for_device; // x0
  _QWORD *v7; // x20
  __int64 domain_for_dev; // x0
  __int64 v9; // x21
  __int64 v10; // x22
  unsigned int v11; // w20
  void *v12; // x0
  unsigned int v13; // w20
  _DWORD *v14; // x0
  __int64 v15; // x8

  if ( !a1 || !a2 || !a3 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_component_bind");
    return 4294967274LL;
  }
  if ( a1[12] != a2 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_95997, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_component_bind");
    return 4294967277LL;
  }
  context_bank_for_device = msm_vidc_get_context_bank_for_device(a3, a1);
  if ( !context_bank_for_device )
  {
    if ( (msm_vidc_debug & 1) == 0 )
    {
LABEL_20:
      result = 4294967291LL;
LABEL_21:
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v13 = result;
        printk(&unk_8AB34, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_component_bind");
        return v13;
      }
      return result;
    }
    v12 = &unk_8AA49;
LABEL_35:
    printk(v12, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_setup_context_bank");
    goto LABEL_20;
  }
  v7 = context_bank_for_device;
  context_bank_for_device[3] = a1;
  domain_for_dev = iommu_get_domain_for_dev(a1);
  v7[4] = domain_for_dev;
  if ( !domain_for_dev )
  {
    if ( (msm_vidc_debug & 1) == 0 )
      goto LABEL_20;
    v12 = &unk_80832;
    goto LABEL_35;
  }
  v9 = v7[6];
  if ( v9 )
  {
    v10 = v7[3];
    result = dma_set_mask(v10, v7[6]);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v11 = result;
        printk(&unk_94C58, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_setup_context_bank");
        result = v11;
      }
      goto LABEL_21;
    }
    dma_set_coherent_mask(v10, v9);
  }
  v14 = (_DWORD *)a1[84];
  if ( v14 || (v14 = (_DWORD *)devm_kmalloc(a1, 16, 3520), (a1[84] = (__int64)v14) != 0) )
    *v14 = -1;
  else
    __break(0x800u);
  v15 = a1[84];
  if ( v15 )
    *(_QWORD *)(v15 + 8) = -1;
  else
    __break(0x800u);
  iommu_set_fault_handler(v7[4], msm_vidc_smmu_fault_handler, a3);
  if ( (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_81753, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_setup_context_bank");
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_85D64, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_component_bind");
  }
  return 0;
}
