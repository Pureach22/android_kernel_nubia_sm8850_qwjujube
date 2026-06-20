__int64 __fastcall setup_fd_gpio_irq(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  unsigned int v5; // w19
  void *v6; // x0
  __int64 v7; // x0

  printk(&unk_A240, "setup_fd_gpio_irq");
  if ( (*(_BYTE *)(a2 + 1144) & 1) != 0 )
  {
    v4 = devm_gpio_request_one(a1 + 16, *(unsigned int *)(a2 + 504), 1, "qbt_finger_detect");
    if ( (v4 & 0x80000000) != 0 )
    {
      v5 = v4;
      v6 = &unk_95ED;
LABEL_9:
      printk(v6, "setup_fd_gpio_irq");
      goto LABEL_10;
    }
    v7 = gpio_to_desc(*(unsigned int *)(a2 + 504));
    v5 = gpiod_to_irq(v7);
    if ( (v5 & 0x80000000) != 0 )
    {
      v6 = &unk_961C;
      goto LABEL_9;
    }
    printk(&unk_A440, "setup_fd_gpio_irq");
    *(_QWORD *)(a2 + 520) = 0xFFFFFFFE00000LL;
    *(_DWORD *)(a2 + 512) = v5;
    *(_QWORD *)(a2 + 528) = a2 + 528;
    *(_QWORD *)(a2 + 536) = a2 + 528;
    *(_QWORD *)(a2 + 544) = qbt_gpio_work_func;
    v5 = devm_request_any_context_irq(a1 + 16, v5, qbt_gpio_isr, 3, "qbt_finger_detect", a2);
    if ( (v5 & 0x80000000) != 0 )
    {
      v6 = &unk_91BD;
      goto LABEL_9;
    }
  }
  else
  {
    printk(&unk_9F95, "setup_fd_gpio_irq");
    v5 = 0;
  }
LABEL_10:
  printk(&unk_9A78, "setup_fd_gpio_irq");
  return v5;
}
