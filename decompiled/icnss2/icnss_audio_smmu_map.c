__int64 __fastcall icnss_audio_smmu_map(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x0

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
    return 4294967277LL;
  v4 = *(_QWORD *)(v3 + 6176);
  if ( !v4 )
    return 4294967274LL;
  if ( (*(_BYTE *)(v3 + 6153) & 1) != 0 )
    return 0;
  return iommu_map(v4, a3 & 0xFFFFFFFFFFFFF000LL);
}
