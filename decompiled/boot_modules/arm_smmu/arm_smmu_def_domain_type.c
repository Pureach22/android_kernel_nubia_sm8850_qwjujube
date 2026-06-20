__int64 __fastcall arm_smmu_def_domain_type(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v5; // x8
  __int64 (__fastcall *v6)(__int64, __int64); // x8

  v2 = *(_QWORD *)(a1 + 824);
  if ( !v2 )
    return 0;
  v3 = *(_QWORD *)(v2 + 72);
  if ( !v3 )
    return 0;
  if ( (using_legacy_binding & 1) != 0 )
    return 4;
  v5 = *(_QWORD *)(*(_QWORD *)v3 + 48LL);
  if ( !v5 )
    return 0;
  v6 = *(__int64 (__fastcall **)(__int64, __int64))(v5 + 104);
  if ( !v6 )
    return 0;
  if ( *((_DWORD *)v6 - 1) != 711998475 )
    __break(0x8228u);
  return v6(a1, a2);
}
