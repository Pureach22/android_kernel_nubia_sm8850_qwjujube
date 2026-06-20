__int64 __fastcall swrm_register_wake_irq(__int64 a1)
{
  __int64 v3; // x0
  int v4; // w0
  int irq_byname; // w0
  int v6; // w0
  int v7; // w20

  if ( *(_DWORD *)(a1 + 15744) )
    return 0;
  if ( (of_get_named_gpio(*(_QWORD *)(*(_QWORD *)(a1 + 8512) + 744LL), "qcom,swr-wakeup-irq", 0) & 0x80000000) != 0 )
  {
    irq_byname = platform_get_irq_byname(*(_QWORD *)(a1 + 15344), "swr_wake_irq");
    if ( irq_byname < 0 )
    {
      if ( (unsigned int)__ratelimit(&swrm_register_wake_irq__rs_3, "swrm_register_wake_irq") )
        dev_err(*(_QWORD *)(a1 + 8512), "TLMM connect gpio not found\n");
      return 4294967274LL;
    }
    *(_DWORD *)(a1 + 9124) = irq_byname;
LABEL_10:
    v6 = request_threaded_irq();
    if ( !v6 )
    {
      irq_set_irq_wake(*(unsigned int *)(a1 + 9124), 1);
      return 0;
    }
    v7 = v6;
    if ( (unsigned int)__ratelimit(&swrm_register_wake_irq__rs_5, "swrm_register_wake_irq") )
      dev_err(*(_QWORD *)(a1 + 8512), "%s: Failed to request irq %d\n", "swrm_register_wake_irq", v7);
    return 4294967274LL;
  }
  v3 = gpio_to_desc();
  v4 = gpiod_to_irq(v3);
  *(_DWORD *)(a1 + 9124) = v4;
  if ( (v4 & 0x80000000) == 0 )
    goto LABEL_10;
  if ( (unsigned int)__ratelimit(&swrm_register_wake_irq__rs, "swrm_register_wake_irq") )
    dev_err(*(_QWORD *)(a1 + 8512), "Unable to configure irq\n");
  return *(unsigned int *)(a1 + 9124);
}
