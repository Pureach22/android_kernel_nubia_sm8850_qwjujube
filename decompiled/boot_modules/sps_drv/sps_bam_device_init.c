__int64 __fastcall sps_bam_device_init(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v5; // w9
  char v6; // w8
  unsigned int v7; // w8
  int v8; // w0
  __int64 v9; // x2
  unsigned int v11; // w8
  __int64 v12; // x2

  v3 = *(_QWORD *)(a1 + 32);
  if ( !v3 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_device_init__rs, "sps_bam_device_init")) )
    {
      printk(&unk_23E66, "sps_bam_device_init", a3);
    }
    if ( a1 )
      ipc_log_string(*(_QWORD *)(a1 + 552), "%s: sps: NULL BAM virtual address\n", "sps_bam_device_init");
    return 0xFFFFFFFFLL;
  }
  v5 = *(_DWORD *)(a1 + 48);
  *(_QWORD *)(a1 + 216) = v3;
  if ( !v5 )
  {
    v11 = (unsigned __int8)logging_option;
    *(_DWORD *)(a1 + 48) = 31;
    if ( v11 >= 2 && debug_level_option )
    {
      if ( print_limit_option )
      {
        if ( !(unsigned int)__ratelimit(&sps_bam_device_init__rs_77, "sps_bam_device_init") )
          goto LABEL_24;
        v12 = a1 + 24;
      }
      else
      {
        v12 = a1 + 24;
      }
      printk(&unk_26791, "sps_bam_device_init", v12);
    }
LABEL_24:
    if ( a1 && *(_DWORD *)(a1 + 568) <= 3u )
      ipc_log_string(
        *(_QWORD *)(a1 + 552),
        "%s: sps:BAM %pa: assuming max number of pipes: %d\n",
        "sps_bam_device_init",
        (const void *)(a1 + 24),
        *(_DWORD *)(a1 + 48));
  }
  *(_DWORD *)(a1 + 160) = 0;
  *(_QWORD *)(a1 + 248) = 0;
  *(_BYTE *)(a1 + 824) = 0;
  *(_QWORD *)(a1 + 504) = a1 + 504;
  *(_QWORD *)(a1 + 512) = a1 + 504;
  v6 = *(_BYTE *)(a1 + 16);
  *(_QWORD *)(a1 + 228) = 0;
  if ( (v6 & 1) == 0 )
  {
    v7 = (unsigned __int8)logging_option;
    goto LABEL_17;
  }
  v8 = sps_bam_enable(a1);
  v7 = (unsigned __int8)logging_option;
  if ( v8 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_device_init__rs_80, "sps_bam_device_init")) )
    {
      printk(&unk_2A27B, "sps_bam_device_init", v9);
    }
    if ( a1 )
      ipc_log_string(*(_QWORD *)(a1 + 552), "%s: sps: Fail to enable bam device\n", "sps_bam_device_init");
    return 0xFFFFFFFFLL;
  }
LABEL_17:
  if ( v7 >= 2
    && debug_level_option
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_device_init__rs_83, "sps_bam_device_init")) )
  {
    printk(&unk_29513, "sps_bam_device_init", a1 + 24);
  }
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 568) <= 3u )
      ipc_log_string(
        *(_QWORD *)(a1 + 552),
        "%s: sps:BAM device: phys %pa IRQ %d\n",
        "sps_bam_device_init",
        (const void *)(a1 + 24),
        *(_DWORD *)(a1 + 44));
  }
  return 0;
}
