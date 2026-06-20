__int64 __fastcall sps_register_event(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x19
  unsigned int v7; // w20

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_event__rs, "sps_register_event")) )
    {
      printk(&unk_228D4, "sps_register_event", a3);
    }
    if ( !sps )
      return 0xFFFFFFFFLL;
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_register_event");
    return 0xFFFFFFFFLL;
  }
  if ( !a2 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_register_event__rs_60, "sps_register_event")) )
    {
      printk(&unk_24F2C, "sps_register_event", a3);
    }
    if ( !sps )
      return 0xFFFFFFFFLL;
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: registered event is NULL\n", "sps_register_event");
    return 0xFFFFFFFFLL;
  }
  if ( !sps )
    return 4294967277LL;
  if ( *(_DWORD *)(sps + 48) )
  {
    v5 = sps_bam_lock();
    if ( v5 )
    {
      v6 = v5;
      if ( (unsigned __int8)logging_option >= 2u
        && (unsigned __int8)debug_level_option >= 2u
        && (!print_limit_option || (unsigned int)__ratelimit(&sps_register_event__rs_66, "sps_register_event")) )
      {
        printk(&unk_272B3, "sps_register_event", *a2);
      }
      if ( *(_DWORD *)(v6 + 568) <= 2u )
        ipc_log_string(*(_QWORD *)(v6 + 544), "%s: sps: events:%d\n", "sps_register_event", *a2);
      v7 = sps_bam_pipe_reg_event(v6, *(unsigned int *)(a1 + 188), a2);
      raw_spin_unlock_irqrestore(v6 + 232, *(_QWORD *)(v6 + 240));
      if ( !v7 )
        return 0;
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_register_event__rs_69, "sps_register_event")) )
      {
        printk(&unk_277EA, "sps_register_event", *(_QWORD *)(a1 + 24) + 24LL);
      }
      ipc_log_string(
        *(_QWORD *)(v6 + 552),
        "%s: sps:Fail to register event for BAM %pa pipe %d\n",
        "sps_register_event",
        (const void *)(*(_QWORD *)(a1 + 24) + 24LL),
        *(_DWORD *)(a1 + 188));
      return v7;
    }
    return 0xFFFFFFFFLL;
  }
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u
     || (unsigned int)__ratelimit(&sps_register_event__rs_63, "sps_register_event")) )
  {
    printk(&unk_22D69, "sps_register_event", a3);
  }
  if ( sps )
    ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: sps driver not ready\n", "sps_register_event");
  return 4294967285LL;
}
