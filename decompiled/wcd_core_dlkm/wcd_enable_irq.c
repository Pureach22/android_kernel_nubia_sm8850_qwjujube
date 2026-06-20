__int64 __fastcall wcd_enable_irq(__int64 a1)
{
  __int64 virq; // x0

  if ( !a1 )
    return printk(&unk_A1EB, "wcd_enable_irq");
  virq = regmap_irq_get_virq(*(_QWORD *)(a1 + 24));
  return enable_irq(virq);
}
