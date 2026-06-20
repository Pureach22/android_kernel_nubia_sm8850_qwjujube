__int64 __fastcall sde_irq_uninstall(__int64 a1)
{
  if ( !a1 )
    return printk(&unk_27D28A, "sde_irq_uninstall");
  sde_core_irq_uninstall();
  return sde_core_irq_domain_fini(a1);
}
