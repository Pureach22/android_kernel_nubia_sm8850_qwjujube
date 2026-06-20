__int64 __fastcall adreno_gx_is_on(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 216LL);
  if ( *((_DWORD *)v1 - 1) != -1780529452 )
    __break(0x8228u);
  return v1() & 1;
}
