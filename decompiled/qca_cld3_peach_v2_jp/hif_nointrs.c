__int64 __fastcall hif_nointrs(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(a1 + 176);
  if ( *((_DWORD *)v1 - 1) != 1838711590 )
    __break(0x8228u);
  return v1();
}
