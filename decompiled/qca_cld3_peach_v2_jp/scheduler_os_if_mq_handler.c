__int64 __fastcall scheduler_os_if_mq_handler(__int64 a1)
{
  void (*v1)(void); // x8

  if ( !a1 )
    return 16;
  v1 = *(void (**)(void))(a1 + 16);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 1685785071 )
    __break(0x8228u);
  v1();
  return 0;
}
