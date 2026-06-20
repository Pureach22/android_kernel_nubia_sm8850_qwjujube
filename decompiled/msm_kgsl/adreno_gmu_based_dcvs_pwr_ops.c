__int64 __fastcall adreno_gmu_based_dcvs_pwr_ops(__int64 a1, __int64 a2)
{
  void (__fastcall *v3)(__int64, __int64); // x8

  if ( (*(_BYTE *)(a1 + 14232) & 1) != 0 )
    return 4294967201LL;
  v3 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 160LL) + 64LL);
  if ( !v3 )
    return 0;
  if ( *((_DWORD *)v3 - 1) != -1013493491 )
    __break(0x8228u);
  v3(a1, a2);
  return 0;
}
