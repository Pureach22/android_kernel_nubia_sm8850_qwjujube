__int64 __fastcall ping_subsystem_init(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x0
  unsigned int irq_byname; // w0
  unsigned int v6; // w20
  void *v8; // x0

  if ( !a1 )
  {
    v8 = &unk_72F5;
LABEL_11:
    printk(v8);
    return (unsigned int)-19;
  }
  v4 = devm_qcom_smem_state_get(a2 + 16, "ping", a1 + 60);
  *(_QWORD *)(a1 + 24) = v4;
  if ( v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_7315);
    return (unsigned int)-19;
  }
  irq_byname = platform_get_irq_byname(a2, "pong");
  *(_DWORD *)(a1 + 84) = irq_byname;
  if ( (irq_byname & 0x80000000) != 0 )
  {
    v8 = &unk_7750;
    goto LABEL_11;
  }
  v6 = devm_request_threaded_irq(a2 + 16, irq_byname, 0, q6v5_pong_interrupt, 8193, "q6v5 pong", a1);
  if ( v6 )
    printk(&unk_73C5);
  *(_DWORD *)(a1 + 240) = 0;
  _init_swait_queue_head(a1 + 248, "&x->wait", &init_completion___key);
  return v6;
}
