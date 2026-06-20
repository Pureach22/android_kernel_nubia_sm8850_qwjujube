__int64 __fastcall sub_134594(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x24
  __int128 v8; // q18
  __int128 v9; // q21

  *(_OWORD *)(v7 + 96) = v8;
  *(_OWORD *)(v7 + 112) = v9;
  return cam_smmu_map_stage2_iova(a1, a2, a3, a4, a5, a6, a7);
}
