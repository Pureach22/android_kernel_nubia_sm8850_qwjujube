__int64 __fastcall sde_irq_postinstall(__int64 a1)
{
  if ( a1 )
    return sde_core_irq_postinstall();
  printk(&unk_27D28A, "sde_irq_postinstall");
  return 4294967274LL;
}
