__int64 __fastcall dp_soc_interrupt_detach_wrapper(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(a1 + 1864);
  if ( *((_DWORD *)v1 - 1) != -1106481425 )
    __break(0x8228u);
  return v1();
}
