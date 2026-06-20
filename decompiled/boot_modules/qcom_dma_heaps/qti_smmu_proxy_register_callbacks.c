__int64 __fastcall qti_smmu_proxy_register_callbacks(__int64 (__fastcall *a1)(), __int64 (__fastcall *a2)())
{
  smmu_proxy_callback_ops_0[0] = a1;
  smmu_proxy_callback_ops_1[0] = a2;
  return 0;
}
