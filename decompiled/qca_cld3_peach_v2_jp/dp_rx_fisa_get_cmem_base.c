__int64 __fastcall dp_rx_fisa_get_cmem_base(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(a1 + 1776);
  if ( !v1 )
    return 0;
  if ( *((_DWORD *)v1 - 1) != -537271456 )
    __break(0x8228u);
  return v1();
}
