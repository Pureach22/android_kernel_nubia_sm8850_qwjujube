__int64 __fastcall mhi_read_reg(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(a1 + 568);
  if ( *((_DWORD *)v1 - 1) != -748163823 )
    __break(0x8228u);
  return v1();
}
