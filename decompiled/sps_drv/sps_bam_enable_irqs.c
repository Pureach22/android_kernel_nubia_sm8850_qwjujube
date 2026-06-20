__int64 __fastcall sps_bam_enable_irqs(_QWORD *a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x0
  __int64 v4; // x2
  _QWORD *v5; // x19
  _QWORD *v7; // x19
  int v8; // w8
  _QWORD *v9; // [xsp+18h] [xbp+18h]

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_enable_irqs__rs, "sps_bam_enable_irqs")) )
    {
      printk(&unk_261D8, "sps_bam_enable_irqs", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM handle is NULL\n", "sps_bam_enable_irqs");
    return 0xFFFFFFFFLL;
  }
  v3 = sps_h2bam(a1);
  if ( !v3 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_enable_irqs__rs_242, "sps_bam_enable_irqs")) )
    {
      printk(&unk_25470, "sps_bam_enable_irqs", v4);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM is not found by handle\n", "sps_bam_enable_irqs");
    return 0xFFFFFFFFLL;
  }
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 3u )
  {
    if ( !print_limit_option
      || (v9 = v3, v8 = __ratelimit(&sps_bam_enable_irqs__rs_243, "sps_bam_enable_irqs"), v3 = v9, v8) )
    {
      v7 = v3;
      printk(&unk_2346F, "sps_bam_enable_irqs", v3 + 3);
      v3 = v7;
    }
  }
  if ( *((_DWORD *)v3 + 142) <= 1u )
  {
    v5 = v3;
    ipc_log_string(v3[67], "%s: sps: BAM: %pa\n", "sps_bam_enable_irqs", v3 + 3);
    v3 = v5;
  }
  sps_bam_enable_all_irqs(v3);
  return 0;
}
