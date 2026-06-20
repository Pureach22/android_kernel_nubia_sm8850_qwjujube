__int64 __fastcall qcom_iommu_dma_invalidate_sg(__int64 result, int a2)
{
  int v2; // w19
  __int64 v3; // x8
  int v4; // w8

  if ( a2 >= 1 )
  {
    v2 = a2;
    do
    {
      v3 = *(_QWORD *)(result + 16);
      if ( v3 != -1 )
        *(_DWORD *)(result + 8) += v3;
      v4 = *(_DWORD *)(result + 24);
      if ( v4 )
        *(_DWORD *)(result + 12) = v4;
      *(_QWORD *)(result + 16) = -1;
      *(_DWORD *)(result + 24) = 0;
      result = sg_next(result);
      --v2;
    }
    while ( v2 );
  }
  return result;
}
