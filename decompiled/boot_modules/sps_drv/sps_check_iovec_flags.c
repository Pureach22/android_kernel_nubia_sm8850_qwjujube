__int64 __fastcall sps_check_iovec_flags(int a1, __int64 a2, __int64 a3)
{
  if ( (a1 & 0x5800) == 0x1000 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_check_iovec_flags__rs, "sps_check_iovec_flags")) )
    {
      printk(&unk_27D52, "sps_check_iovec_flags", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: NWD is only valid with EOT or CMD\n", "sps_check_iovec_flags");
  }
  else if ( (~a1 & 0x4800) != 0 )
  {
    if ( (a1 & 0x600) == 0 || (a1 & 0x800) != 0 )
    {
      if ( (a1 & 0x600) == 0x600 )
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_check_iovec_flags__rs_270, "sps_check_iovec_flags")) )
        {
          printk(&unk_24B27, "sps_check_iovec_flags", a3);
        }
        if ( sps )
          ipc_log_string(
            *(_QWORD *)(sps + 272),
            "%s: sps: Can't lock and unlock a pipe by the same Command Descriptor\n",
            "sps_check_iovec_flags");
      }
      else if ( (~a1 & 0x900) != 0 )
      {
        if ( (~a1 & 0x1100) != 0 )
          return 0;
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_check_iovec_flags__rs_276, "sps_check_iovec_flags")) )
        {
          printk(&unk_28E2F, "sps_check_iovec_flags", a3);
        }
        if ( sps )
          ipc_log_string(
            *(_QWORD *)(sps + 272),
            "%s: sps: Immediate and NWD are not allowed to coexist\n",
            "sps_check_iovec_flags");
      }
      else
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_check_iovec_flags__rs_273, "sps_check_iovec_flags")) )
        {
          printk(&unk_237A1, "sps_check_iovec_flags", a3);
        }
        if ( sps )
          ipc_log_string(
            *(_QWORD *)(sps + 272),
            "%s: sps: Immediate and CMD are not allowed to coexist\n",
            "sps_check_iovec_flags");
      }
    }
    else
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_check_iovec_flags__rs_267, "sps_check_iovec_flags")) )
      {
        printk(&unk_23D4B, "sps_check_iovec_flags", a3);
      }
      if ( sps )
        ipc_log_string(
          *(_QWORD *)(sps + 272),
          "%s: sps: pipe lock/unlock flags are only valid with Command Descriptor\n",
          "sps_check_iovec_flags");
    }
  }
  else
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_check_iovec_flags__rs_264, "sps_check_iovec_flags")) )
    {
      printk(&unk_28DFC, "sps_check_iovec_flags", a3);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: sps: EOT and CMD are not allowed to coexist\n",
        "sps_check_iovec_flags");
  }
  return 0xFFFFFFFFLL;
}
