__int64 __fastcall kgsl_iommu_setup_context(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 node_by_name; // x0
  __int64 v10; // x24
  __int64 device_by_node; // x23
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x1
  unsigned int v16; // w8
  __int64 v17; // x0
  unsigned int v18; // w20
  int context_bank_nr; // w0

  node_by_name = of_find_node_by_name(a2, a4);
  if ( !node_by_name )
    return 4294967294LL;
  v10 = node_by_name;
  device_by_node = of_find_device_by_node();
  result = of_dma_configure_id(device_by_node + 16, v10, 1, 0);
  if ( (_DWORD)result )
    return result;
  *(_QWORD *)(a3 + 40) = 0;
  *(_QWORD *)(a3 + 48) = 0;
  *(_DWORD *)(a3 + 16) = -1;
  *(_QWORD *)(a3 + 24) = a1 - 56;
  *(_DWORD *)(a3 + 44) = 1250;
  *(_DWORD *)(a3 + 48) = 10;
  *(_QWORD *)a3 = device_by_node;
  *(_QWORD *)(a3 + 8) = a4;
  *(_QWORD *)(a3 + 56) = 0;
  *(_QWORD *)(a3 + 64) = 0;
  *(_QWORD *)(device_by_node + 168) = a3 + 80;
  v13 = iommu_domain_alloc(&platform_bus_type);
  *(_QWORD *)(a3 + 72) = v13;
  if ( !v13 )
    return 4294967277LL;
  qcom_iommu_set_fault_model(v13, 1);
  v14 = *(_QWORD *)(a3 + 72);
  if ( (*(_QWORD *)(a1 + 48) & 0x10) != 0 )
  {
    if ( *(_DWORD *)(a1 + 12) != 1 )
    {
      v15 = 64;
      goto LABEL_11;
    }
    if ( (*(_QWORD *)(a1 + 48) & 8) == 0 )
    {
      v15 = 0x80000000LL;
LABEL_11:
      iommu_set_pgtable_quirks(v14, v15);
      v14 = *(_QWORD *)(a3 + 72);
    }
  }
  v16 = iommu_attach_device(v14, *(_QWORD *)a3 + 16LL);
  v17 = *(_QWORD *)(a3 + 72);
  if ( v16 )
  {
    v18 = v16;
    iommu_domain_free(v17);
    result = v18;
LABEL_14:
    *(_QWORD *)(a3 + 72) = 0;
    return result;
  }
  iommu_set_fault_handler(v17, a5, a1);
  context_bank_nr = qcom_iommu_get_context_bank_nr(*(_QWORD *)(a3 + 72));
  *(_DWORD *)(a3 + 16) = context_bank_nr;
  if ( context_bank_nr < 0 )
  {
    dev_err(
      *(_QWORD *)(a1 + 11112) + 16LL,
      "Couldn't get the context bank for %s: %d\n",
      *(const char **)(a3 + 8),
      context_bank_nr);
    iommu_detach_device(*(_QWORD *)(a3 + 72), *(_QWORD *)a3 + 16LL);
    iommu_domain_free(*(_QWORD *)(a3 + 72));
    result = *(unsigned int *)(a3 + 16);
    goto LABEL_14;
  }
  return 0;
}
