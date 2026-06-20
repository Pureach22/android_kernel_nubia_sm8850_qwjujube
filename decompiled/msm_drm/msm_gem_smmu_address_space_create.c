__int64 __fastcall msm_gem_smmu_address_space_create(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x0
  __int64 v7; // x19

  if ( !a2 )
    return -22;
  v6 = _kmalloc_cache_noprof(msleep, 3520, 368);
  if ( !v6 )
    return -12;
  *(_DWORD *)(v6 + 248) = 0;
  *(_QWORD *)(v6 + 272) = smmu_aspace_ops;
  *(_QWORD *)(v6 + 280) = a1;
  *(_QWORD *)v6 = a3;
  *(_QWORD *)(v6 + 256) = a2;
  v7 = v6;
  *(_QWORD *)(v6 + 288) = v6 + 288;
  *(_QWORD *)(v6 + 296) = v6 + 288;
  *(_QWORD *)(v6 + 304) = v6 + 304;
  *(_QWORD *)(v6 + 312) = v6 + 304;
  *(_DWORD *)(v6 + 264) = 1;
  _mutex_init(v6 + 320, "&aspace->list_lock", &msm_gem_smmu_address_space_create___key);
  return v7;
}
