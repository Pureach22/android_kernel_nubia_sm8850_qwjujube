__int64 __fastcall qcom_arch_dma_prep_coherent(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x9
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x10
  _QWORD *v7; // x9
  unsigned __int64 v8; // x11
  bool v9; // cf
  unsigned __int64 v10; // x11

  result = qcom_dma_iommu_dev;
  v4 = *(_QWORD *)(qcom_dma_iommu_dev + 664);
  v5 = ((a1 - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
  if ( v4 )
  {
    v6 = *(_QWORD *)(v4 + 16);
    if ( v6 )
    {
      v7 = (_QWORD *)(v4 + 8);
      while ( 1 )
      {
        v8 = *(v7 - 1);
        v9 = v5 >= v8;
        v10 = v5 - v8;
        if ( v9 && v10 < v6 )
          break;
        v6 = v7[4];
        v7 += 3;
        if ( !v6 )
          goto LABEL_9;
      }
      v5 = *v7 + v10;
    }
    else
    {
LABEL_9:
      v5 = -1;
    }
  }
  if ( (*(_BYTE *)(qcom_dma_iommu_dev + 844) & 0x40) == 0 )
    return _dma_sync_single_for_device(qcom_dma_iommu_dev, v5, a2, 1);
  return result;
}
