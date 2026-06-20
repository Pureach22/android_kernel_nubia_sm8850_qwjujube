__int64 __fastcall dp_txrx_get_interface_stats(__int64 a1)
{
  __int64 (*v1)(void); // x8

  if ( !a1 )
    return 16;
  v1 = *(__int64 (**)(void))(a1 + 1808);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 1504611911 )
    __break(0x8228u);
  return v1();
}
