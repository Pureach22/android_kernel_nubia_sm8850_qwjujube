__int64 __fastcall msm_smmu_destroy(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19

  v1 = *(_QWORD *)(a1 + 32);
  if ( v1 )
  {
    v2 = a1;
    platform_device_unregister(v1 - 16);
    a1 = v2;
  }
  return kfree(a1);
}
