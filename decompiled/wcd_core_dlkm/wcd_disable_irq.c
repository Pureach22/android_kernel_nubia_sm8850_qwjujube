__int64 __fastcall wcd_disable_irq(__int64 a1)
{
  __int64 virq; // x0

  if ( !a1 )
    return printk(&unk_A1EB, "wcd_disable_irq");
  virq = regmap_irq_get_virq(*(_QWORD *)(a1 + 24));
  return disable_irq_nosync(virq);
}
