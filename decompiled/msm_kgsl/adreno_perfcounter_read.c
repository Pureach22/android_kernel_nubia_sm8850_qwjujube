__int64 __fastcall adreno_perfcounter_read(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v3; // x8
  __int64 v4; // x1
  __int64 (__fastcall *v5)(__int64, __int64); // x8

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 48LL);
  if ( !v3 )
    return 0;
  if ( *(_DWORD *)(v3 + 8) <= a2 )
    return 0;
  v4 = *(_QWORD *)v3 + 56LL * a2;
  if ( *(_DWORD *)(v4 + 8) <= a3 )
    return 0;
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + 40);
  if ( *((_DWORD *)v5 - 1) != -1490883378 )
    __break(0x8228u);
  return v5(a1, v4);
}
