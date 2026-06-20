__int64 __fastcall kgsl_readtimestamp(__int64 a1)
{
  __int64 (*v1)(void); // x8

  if ( !a1 )
    return 4294967274LL;
  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 8752) + 64LL);
  if ( *((_DWORD *)v1 - 1) != -362688460 )
    __break(0x8228u);
  return v1();
}
