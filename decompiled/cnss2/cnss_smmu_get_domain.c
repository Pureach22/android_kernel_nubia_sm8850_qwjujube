__int64 __fastcall cnss_smmu_get_domain(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( v1 )
    return *(_QWORD *)(v1 + 264);
  else
    return 0;
}
