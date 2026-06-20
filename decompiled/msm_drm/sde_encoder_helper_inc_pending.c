__int64 __fastcall sde_encoder_helper_inc_pending(__int64 a1)
{
  __int64 v2; // x1
  unsigned int v10; // w9

  if ( a1 )
  {
    v2 = raw_spin_lock_irqsave(a1 + 128);
    _X8 = (unsigned int *)(a1 + 592);
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stxr(v10 + 1, _X8) );
    raw_spin_unlock_irqrestore(a1 + 128, v2);
    return *(unsigned int *)(a1 + 592);
  }
  else
  {
    printk(&unk_26FCAB, "sde_encoder_helper_inc_pending");
    return 4294967274LL;
  }
}
