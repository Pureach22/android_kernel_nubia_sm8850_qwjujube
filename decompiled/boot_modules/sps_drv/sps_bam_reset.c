__int64 __fastcall sps_bam_reset(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x11

  if ( (unsigned __int8)logging_option >= 2u && debug_level_option )
  {
    if ( print_limit_option )
    {
LABEL_27:
      if ( !(unsigned int)__ratelimit(&sps_bam_reset__rs, "sps_bam_reset") )
        goto LABEL_2;
    }
    printk(&unk_26FF9, "sps_bam_reset", a1 + 24);
  }
LABEL_2:
  if ( a1 && *(_DWORD *)(a1 + 568) <= 3u )
    ipc_log_string(
      *(_QWORD *)(a1 + 552),
      "%s: sps:BAM device RESET: phys %pa IRQ %d\n",
      "sps_bam_reset",
      (const void *)(a1 + 24),
      *(_DWORD *)(a1 + 44));
  if ( (*(_BYTE *)(a1 + 160) & 8) != 0 )
  {
    v2 = *(unsigned int *)(a1 + 48);
    if ( (_DWORD)v2 )
    {
      v3 = 0;
      while ( 1 )
      {
        if ( v3 == 31 )
        {
          __break(0x5512u);
          goto LABEL_27;
        }
        v4 = *(_QWORD *)(a1 + 256 + 8 * v3);
        if ( v4 != -2290649225LL )
        {
          if ( v4 )
            break;
        }
        if ( v2 == ++v3 )
          goto LABEL_17;
      }
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(
                                                                        &sps_bam_reset__rs_90,
                                                                        "sps_bam_reset")) )
      {
        printk(&unk_2A2A1, "sps_bam_reset", a1 + 24);
      }
      if ( a1 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps:BAM device %pa RESET failed: pipe %d in use\n",
          "sps_bam_reset",
          (const void *)(a1 + 24),
          v3);
        return 0xFFFFFFFFLL;
      }
      return 0xFFFFFFFFLL;
    }
LABEL_17:
    if ( (unsigned int)sps_bam_disable(a1) )
      return 0xFFFFFFFFLL;
  }
  return sps_bam_enable(a1);
}
