__int64 __fastcall ifpc_count_show(__int64 a1)
{
  void (*v2)(void); // x8

  v2 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 296LL);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != 994519391 )
      __break(0x8228u);
    v2();
  }
  return *(unsigned int *)(a1 + 20648);
}
