__int64 __fastcall gmu_core_dev_ifpc_store(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  v1 = *(_QWORD *)(a1 + 1520);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(__int64 (**)(void))(v1 + 16);
  if ( !v2 )
    return 4294967274LL;
  if ( *((_DWORD *)v2 - 1) != -1642886764 )
    __break(0x8228u);
  return v2();
}
