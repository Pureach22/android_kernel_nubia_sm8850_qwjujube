__int64 __fastcall hif_set_irq_config_by_ceid(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 30696) + 136LL);
  if ( !v1 )
    return 11;
  if ( *((_DWORD *)v1 - 1) != 817160334 )
    __break(0x8228u);
  return v1();
}
