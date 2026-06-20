__int64 __fastcall wcd_free_irq(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0

  if ( !a1 )
    return printk(&unk_A1EB, "wcd_free_irq");
  result = regmap_irq_get_virq(*(_QWORD *)(a1 + 24));
  if ( (result & 0x80000000) == 0 )
    return devm_free_irq(*(_QWORD *)(a1 + 32), (unsigned int)result, a3);
  return result;
}
