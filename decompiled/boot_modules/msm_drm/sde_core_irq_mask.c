__int64 __fastcall sde_core_irq_mask(__int64 result)
{
  __int64 v1; // x9
  __int64 v2; // x8
  __int64 v3; // x10
  __int64 v4; // x8
  unsigned __int64 v11; // x10

  if ( !result )
    return printk(&unk_2351CE, "sde_core_irq_mask");
  v1 = *(_QWORD *)(result + 48);
  if ( !v1 )
    return printk(&unk_2351CE, "sde_core_irq_mask");
  __dmb(0xBu);
  v2 = *(_QWORD *)(result + 8);
  v3 = (unsigned int)v2 >> 6;
  v4 = 1LL << v2;
  _X9 = (unsigned __int64 *)(v1 + 1880 + 8 * v3);
  __asm { PRFM            #0x11, [X9] }
  do
    v11 = __ldxr(_X9);
  while ( __stxr(v11 & ~v4, _X9) );
  __dmb(0xBu);
  return result;
}
