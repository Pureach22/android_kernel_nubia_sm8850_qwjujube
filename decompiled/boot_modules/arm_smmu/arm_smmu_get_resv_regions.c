_QWORD *__fastcall arm_smmu_get_resv_regions(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x0
  __int64 v5; // x0
  const char *v6; // x1
  _QWORD *result; // x0
  _QWORD *v8; // x1
  _QWORD v9[11]; // [xsp+8h] [xbp-58h] BYREF

  v9[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 744);
  if ( v4 )
  {
    memset(v9, 0, 80);
    if ( (unsigned int)_of_parse_phandle_with_args(v4, "qcom,iommu-group", 0, 0, 0, v9) || (v5 = v9[0]) == 0 )
      v5 = *(_QWORD *)(a1 + 744);
    if ( of_find_property(v5, "qcom,iommu-dma-addr-pool", 0) )
    {
      v6 = *(const char **)(a1 + 112);
      if ( !v6 )
        v6 = *(const char **)a1;
      _warn_printk("%s: qcom,iommu-dma-addr-pool is deprecated. Switch to using iommu-addresses.", v6);
      __break(0x800u);
    }
  }
  result = (_QWORD *)iommu_alloc_resv_region(0x8000000, 0x100000, 26, 4, 3264);
  if ( result )
  {
    v8 = (_QWORD *)a2[1];
    if ( result == a2 || v8 == result || (_QWORD *)*v8 != a2 )
    {
      _list_add_valid_or_report();
    }
    else
    {
      a2[1] = result;
      *result = a2;
      result[1] = v8;
      *v8 = result;
    }
    result = (_QWORD *)iommu_dma_get_resv_regions(a1, a2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
