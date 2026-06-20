__int64 __fastcall setup_intr2_irq(__int64 a1, __int64 a2)
{
  unsigned int v4; // w20

  printk(&unk_A30E, "setup_intr2_irq");
  v4 = devm_gpio_request_one(a1 + 16, *(unsigned int *)(a2 + 1048), 0, "qbt_intr2");
  if ( (v4 & 0x80000000) != 0 )
    printk(&unk_A20B, "setup_intr2_irq");
  printk(&unk_9809, "setup_intr2_irq");
  return v4;
}
