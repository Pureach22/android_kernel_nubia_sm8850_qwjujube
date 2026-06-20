__int64 __fastcall lpac_store(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 14264) + 40LL) + 264LL);
  if ( !v1 )
    return 4294967274LL;
  if ( *((_DWORD *)v1 - 1) != 1628810607 )
    __break(0x8228u);
  return v1();
}
