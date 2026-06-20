unsigned __int64 __fastcall qcom_arch_sync_dma_for_device(unsigned __int64 result, __int64 a2, unsigned int a3)
{
  __int64 v3; // x3
  __int64 v5; // x1
  __int64 v6; // x9
  unsigned __int64 v7; // x10
  _QWORD *v8; // x9
  unsigned __int64 v9; // x11
  bool v10; // cf
  unsigned __int64 v11; // x11

  v3 = a3;
  v5 = result;
  v6 = *(_QWORD *)(qcom_dma_iommu_dev + 664);
  if ( v6 )
  {
    v7 = *(_QWORD *)(v6 + 16);
    if ( v7 )
    {
      v8 = (_QWORD *)(v6 + 8);
      while ( 1 )
      {
        v9 = *(v8 - 1);
        v10 = result >= v9;
        v11 = result - v9;
        if ( v10 && v11 < v7 )
          break;
        v7 = v8[4];
        v8 += 3;
        if ( !v7 )
          goto LABEL_9;
      }
      v5 = *v8 + v11;
    }
    else
    {
LABEL_9:
      v5 = -1;
    }
  }
  if ( (*(_BYTE *)(qcom_dma_iommu_dev + 844) & 0x40) == 0 )
    return _dma_sync_single_for_device(qcom_dma_iommu_dev, v5, a2, v3);
  return result;
}
