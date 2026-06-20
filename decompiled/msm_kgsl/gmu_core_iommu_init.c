__int64 __fastcall gmu_core_iommu_init(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x0
  int v4; // w0
  unsigned int v6; // w20

  v2 = *(_QWORD *)(a1 + 1544);
  v3 = iommu_domain_alloc(&platform_bus_type);
  *(_QWORD *)(a1 + 1552) = v3;
  if ( v3 )
  {
    qcom_iommu_set_fault_model(v3, 4);
    v4 = iommu_attach_device(*(_QWORD *)(a1 + 1552), v2 + 16);
    if ( v4 )
    {
      v6 = v4;
      dev_err(v2 + 16, "Unable to attach GMU IOMMU domain: %d\n", v4);
      iommu_domain_free(*(_QWORD *)(a1 + 1552));
      *(_QWORD *)(a1 + 1552) = 0;
      return v6;
    }
    else
    {
      iommu_set_fault_handler(*(_QWORD *)(a1 + 1552), gmu_core_iommu_fault_handler, a1);
      return 0;
    }
  }
  else
  {
    dev_err(v2 + 16, "Unable to allocate GMU IOMMU domain\n");
    return 4294967277LL;
  }
}
