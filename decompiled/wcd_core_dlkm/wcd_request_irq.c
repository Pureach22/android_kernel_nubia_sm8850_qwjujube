__int64 __fastcall wcd_request_irq(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned int virq; // w0
  unsigned int v10; // w1

  if ( a1 )
  {
    virq = regmap_irq_get_virq(*(_QWORD *)(a1 + 24));
    v10 = virq;
    if ( (virq & 0x80000000) == 0 )
      return (unsigned int)devm_request_threaded_irq(*(_QWORD *)(a1 + 32), virq, 0, a4, 8193, a3, a5);
  }
  else
  {
    printk(&unk_A1EB, "wcd_request_irq");
    return (unsigned int)-22;
  }
  return v10;
}
