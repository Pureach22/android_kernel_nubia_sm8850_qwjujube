__int64 __fastcall attr_store(__int64 a1, __int64 a2)
{
  __int64 (*v2)(void); // x8

  v2 = *(__int64 (**)(void))(a2 + 24);
  if ( !v2 )
    return -5;
  if ( *((_DWORD *)v2 - 1) != 2052807983 )
    __break(0x8228u);
  return v2();
}
