__int64 __fastcall setup_ipc_irq(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned int v5; // w20
  void *v6; // x0
  unsigned int v7; // w0

  v4 = gpio_to_desc(*(unsigned int *)(a2 + 456));
  *(_DWORD *)(a2 + 460) = gpiod_to_irq(v4);
  *(_QWORD *)(a2 + 472) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a2 + 480) = a2 + 480;
  *(_QWORD *)(a2 + 488) = a2 + 480;
  *(_QWORD *)(a2 + 496) = qbt_irq_report_event;
  printk(&unk_975C, "setup_ipc_irq");
  v5 = *(_DWORD *)(a2 + 460);
  if ( (v5 & 0x80000000) != 0 )
  {
    v6 = &unk_A25D;
LABEL_7:
    printk(v6, "setup_ipc_irq");
    goto LABEL_8;
  }
  v7 = devm_gpio_request_one(a1 + 16, *(unsigned int *)(a2 + 456), 1, "qbt_ipc");
  if ( (v7 & 0x80000000) != 0 )
  {
    v5 = v7;
    v6 = &unk_95ED;
    goto LABEL_7;
  }
  v5 = devm_request_threaded_irq(a1 + 16, *(unsigned int *)(a2 + 460), 0, qbt_ipc_irq_handler, 8194, "qbt_ipc", a2);
  if ( (v5 & 0x80000000) != 0 )
  {
    v6 = &unk_9656;
    goto LABEL_7;
  }
LABEL_8:
  printk(&unk_9809, "setup_ipc_irq");
  return v5;
}
