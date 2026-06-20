__int64 dma_mapping_fast_init()
{
  return android_rvh_probe_register(&_tracepoint_android_rvh_iommu_setup_dma_ops, _fast_smmu_setup_dma_ops, 0);
}
