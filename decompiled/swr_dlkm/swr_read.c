__int64 __fastcall swr_read(__int64 a1)
{
  __int64 v1; // x0
  __int64 (*v2)(void); // x8

  v1 = *(_QWORD *)(a1 + 32);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(__int64 (**)(void))(v1 + 8432);
  if ( *((_DWORD *)v2 - 1) != 403223378 )
    __break(0x8228u);
  return v2();
}
