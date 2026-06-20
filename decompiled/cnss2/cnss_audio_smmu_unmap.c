__int64 __fastcall cnss_audio_smmu_unmap(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v3; // x8

  result = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( result )
  {
    v3 = result;
    result = *(_QWORD *)(result + 7544);
    if ( result )
    {
      if ( (*(_BYTE *)(v3 + 7552) & 1) == 0 )
        return iommu_unmap();
    }
  }
  return result;
}
