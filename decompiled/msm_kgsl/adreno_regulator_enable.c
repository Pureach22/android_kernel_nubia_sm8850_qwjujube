__int64 __fastcall adreno_regulator_enable(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 64LL);
  if ( !v1 )
    return 0;
  if ( *((_DWORD *)v1 - 1) != -83892780 )
    __break(0x8228u);
  return v1();
}
