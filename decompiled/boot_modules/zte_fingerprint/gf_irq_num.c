__int64 __fastcall gf_irq_num(__int64 a1)
{
  __int64 v1; // x0

  if ( a1 )
  {
    v1 = gpio_to_desc(*(unsigned int *)(a1 + 60));
    return gpiod_to_irq(v1);
  }
  else
  {
    printk(&unk_9404);
    return 4294967277LL;
  }
}
