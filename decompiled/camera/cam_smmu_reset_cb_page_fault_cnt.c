void cam_smmu_reset_cb_page_fault_cnt()
{
  unsigned int v0; // w8
  __int64 v1; // x11

  if ( dword_394060 )
  {
    v0 = 0;
    do
    {
      v1 = iommu_cb_set + 14280LL * (int)v0++;
      *(_DWORD *)(v1 + 8592) = 0;
    }
    while ( v0 < dword_394060 );
  }
}
