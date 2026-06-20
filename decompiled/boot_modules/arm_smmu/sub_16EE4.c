__int64 __fastcall sub_16EE4(__int64 a1)
{
  unsigned int *v1; // x19
  unsigned int v2; // w8

  v2 = atomic_load(v1);
  atomic_load(v1);
  atomic_load((unsigned __int64 *)v1);
  atomic_load((unsigned __int64 *)v1);
  if ( !v2 )
    JUMPOUT(0xB317C);
  return arm_smmu_power_on(a1);
}
