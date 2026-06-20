__int64 __fastcall hif_grp_irq_configure(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(a1 + 272);
  if ( *((_DWORD *)v1 - 1) != 1930914583 )
    __break(0x8228u);
  return v1();
}
