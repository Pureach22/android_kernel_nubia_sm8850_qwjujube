__int64 __fastcall rmnet_shs_init(__int64 result, __int64 a2)
{
  char v2; // w19
  char mask_len; // w20
  __int64 v4; // x21
  __int64 port; // x0

  if ( !byte_19494 )
  {
    if ( *(_QWORD *)(*(_QWORD *)(a2 + 232) + 64LL) )
    {
      v4 = result;
      v2 = rmnet_shs_mask_from_map(*(unsigned int **)(*(_QWORD *)(a2 + 232) + 64LL));
      mask_len = rmnet_shs_get_mask_len(v2);
      result = v4;
    }
    else
    {
      v2 = 61;
      mask_len = 5;
    }
    port = rmnet_get_port(result);
    byte_19496 = 2;
    byte_19497 = v2;
    qword_19098 = port;
    byte_19498 = mask_len;
    dword_19499 = 67174657;
    word_1949D = 25500;
    rmnet_shs_cpu_node_tbl[0] = (__int64)rmnet_shs_cpu_node_tbl;
    qword_194B0 = (__int64)rmnet_shs_cpu_node_tbl;
    qword_194D0 = (__int64)&qword_194D0;
    qword_194D8 = (__int64)&qword_194D0;
    qword_194F8 = (__int64)&qword_194F8;
    qword_19500 = (__int64)&qword_194F8;
    qword_19520 = (__int64)&qword_19520;
    qword_19528 = (__int64)&qword_19520;
    qword_19548 = (__int64)&qword_19548;
    qword_19550 = (__int64)&qword_19548;
    qword_19570 = (__int64)&qword_19570;
    qword_19578 = (__int64)&qword_19570;
    qword_19598 = (__int64)&qword_19598;
    qword_195A0 = (__int64)&qword_19598;
    qword_195C0 = (__int64)&qword_195C0;
    qword_195C8 = (__int64)&qword_195C0;
    rmnet_shs_freq_init();
    rmnet_shs_ll_init();
    if ( (register_oom_notifier(&rmnet_oom_nb) & 0x80000000) != 0 )
      printk(&unk_1550A);
    printk(&unk_1573D);
    result = wakeup_source_register(0, "RMNET_SHS");
    qword_19480 = result;
    byte_19494 = 1;
  }
  return result;
}
