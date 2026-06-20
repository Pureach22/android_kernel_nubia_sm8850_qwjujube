__int64 __fastcall sps_bam_device_de_init(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x19
  int v4; // w8
  __int64 v5; // [xsp+18h] [xbp+18h]

  if ( (unsigned __int8)logging_option >= 2u )
  {
    if ( debug_level_option )
    {
      if ( !print_limit_option
        || (v5 = a1, v4 = __ratelimit(&sps_bam_device_de_init__rs, "sps_bam_device_de_init"), a1 = v5, v4) )
      {
        v3 = a1;
        printk(&unk_2A6FC, "sps_bam_device_de_init", a1 + 24);
        a1 = v3;
      }
    }
  }
  if ( a1 && *(_DWORD *)(a1 + 568) <= 3u )
  {
    v1 = a1;
    ipc_log_string(
      *(_QWORD *)(a1 + 552),
      "%s: sps:BAM device DEINIT: phys %pa IRQ %d\n",
      "sps_bam_device_de_init",
      (const void *)(a1 + 24),
      *(_DWORD *)(a1 + 44));
    a1 = v1;
  }
  return sps_bam_disable(a1);
}
