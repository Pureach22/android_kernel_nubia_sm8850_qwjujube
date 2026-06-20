__int64 __fastcall dp_soc_ppeds_stop(__int64 result)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(result + 1736);
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != -1093861181 )
      __break(0x8228u);
    return v1();
  }
  return result;
}
