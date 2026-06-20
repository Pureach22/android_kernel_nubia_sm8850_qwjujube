__int64 __fastcall icnss_audio_smmu_unmap(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 152);
  if ( v1 )
  {
    result = *(_QWORD *)(v1 + 6176);
    if ( result )
    {
      if ( (*(_BYTE *)(v1 + 6153) & 1) == 0 )
        return iommu_unmap();
    }
  }
  return result;
}
