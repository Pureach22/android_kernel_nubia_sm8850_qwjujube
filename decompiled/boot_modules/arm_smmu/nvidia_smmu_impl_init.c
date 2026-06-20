__int64 __fastcall nvidia_smmu_impl_init(_QWORD *a1)
{
  __int64 v1; // x0
  __int64 v2; // x8

  v1 = devm_krealloc(*a1, a1, 360, 3264);
  if ( !v1 )
    return -12;
  v2 = v1;
  *(_QWORD *)(v2 + 352) = -19;
  return -19;
}
