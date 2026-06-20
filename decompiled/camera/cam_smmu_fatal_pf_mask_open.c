__int64 __fastcall cam_smmu_fatal_pf_mask_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, cam_smmu_get_fatal_pf_mask, cam_smmu_set_fatal_pf_mask, "%16llu", a6);
}
