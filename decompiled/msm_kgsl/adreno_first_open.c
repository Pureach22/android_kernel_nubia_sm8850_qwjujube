__int64 __fastcall adreno_first_open(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v2)(__int64, __int64); // x8

  if ( *(_BYTE *)(a1 + 13417) != 1 )
    return 4294967277LL;
  v2 = **(__int64 (__fastcall ***)(__int64, __int64))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 160LL);
  if ( *((_DWORD *)v2 - 1) != -83892780 )
    __break(0x8228u);
  return v2(a1, a2);
}
