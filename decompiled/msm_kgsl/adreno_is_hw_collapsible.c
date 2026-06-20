bool __fastcall adreno_is_hw_collapsible(__int64 a1)
{
  __int64 v2; // x20
  __int64 (*v3)(void); // x8
  unsigned int (__fastcall *v4)(_QWORD); // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL);
  v3 = *(__int64 (**)(void))(v2 + 192);
  if ( *((_DWORD *)v3 - 1) != -1780529452 )
    __break(0x8228u);
  if ( (v3() & 1) == 0 )
    return 0;
  v4 = *(unsigned int (__fastcall **)(_QWORD))(v2 + 168);
  if ( *((_DWORD *)v4 - 1) != -83892780 )
    __break(0x8228u);
  return v4(a1) == 0;
}
