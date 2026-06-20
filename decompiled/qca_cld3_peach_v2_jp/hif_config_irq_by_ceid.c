__int64 __fastcall hif_config_irq_by_ceid(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(a1 + 416);
  if ( *((_DWORD *)v1 - 1) != -577898772 )
    __break(0x8228u);
  return v1();
}
