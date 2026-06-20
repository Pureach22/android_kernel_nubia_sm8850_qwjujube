__int64 __fastcall arm_smmu_probe_finalize(__int64 a1)
{
  __int64 *v1; // x8
  __int64 result; // x0
  __int64 v3; // x8
  __int64 (*v4)(void); // x8

  v1 = *(__int64 **)(a1 + 824);
  if ( v1 )
    v1 = (__int64 *)v1[9];
  result = *v1;
  v3 = *(_QWORD *)(*v1 + 48);
  if ( v3 )
  {
    v4 = *(__int64 (**)(void))(v3 + 152);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != 688053488 )
        __break(0x8228u);
      return v4();
    }
  }
  return result;
}
