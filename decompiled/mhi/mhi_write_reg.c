__int64 __fastcall mhi_write_reg(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(a1 + 576);
  if ( *((_DWORD *)v1 - 1) != -242010890 )
    __break(0x8228u);
  return v1();
}
