__int64 __fastcall sps_bam_process_irq(_QWORD *a1, __int64 a2, __int64 a3)
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
       || (unsigned int)__ratelimit(&sps_bam_process_irq__rs, "sps_bam_process_irq")) )
    {
      printk(&unk_261D8, "sps_bam_process_irq", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM handle is NULL\n", "sps_bam_process_irq");
    return 0xFFFFFFFFLL;
  }
  v3 = sps_h2bam(a1);
  if ( !v3 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_process_irq__rs_238, "sps_bam_process_irq")) )
    {
      printk(&unk_25470, "sps_bam_process_irq", v4);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM is not found by handle\n", "sps_bam_process_irq");
    return 0xFFFFFFFFLL;
  }
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 3u )
  {
    if ( !print_limit_option
      || (v9 = v3, v8 = __ratelimit(&sps_bam_process_irq__rs_239, "sps_bam_process_irq"), v3 = v9, v8) )
    {
      v7 = v3;
      printk(&unk_2346F, "sps_bam_process_irq", v3 + 3);
      v3 = v7;
    }
  }
  if ( *((_DWORD *)v3 + 142) <= 1u )
  {
    v5 = v3;
    ipc_log_string(v3[67], "%s: sps: BAM: %pa\n", "sps_bam_process_irq", v3 + 3);
    v3 = v5;
  }
  return sps_bam_check_irq(v3);
}
