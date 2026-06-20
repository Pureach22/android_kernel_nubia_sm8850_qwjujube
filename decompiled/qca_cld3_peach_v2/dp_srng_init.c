__int64 __fastcall dp_srng_init(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(a1 + 1792);
  if ( *((_DWORD *)v1 - 1) != -386661336 )
    __break(0x8228u);
  return v1();
}
