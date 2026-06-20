__int64 __fastcall hif_irq_enable(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(a1 + 264);
  if ( *((_DWORD *)v1 - 1) != -1512672541 )
    __break(0x8228u);
  return v1();
}
