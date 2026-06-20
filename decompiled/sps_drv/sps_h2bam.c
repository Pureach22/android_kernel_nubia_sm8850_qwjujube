_QWORD *__fastcall sps_h2bam(_QWORD *a1)
{
  _QWORD *result; // x0

  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 3u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_h2bam__rs, "sps_h2bam")) )
  {
    printk(&unk_27F9B, "sps_h2bam", a1);
  }
  if ( sps && *(_DWORD *)(sps + 288) <= 1u )
    ipc_log_string(*(_QWORD *)(sps + 256), "%s: sps: BAM handle:0x%pK\n", "sps_h2bam", a1);
  result = nullptr;
  if ( a1 && a1 != (_QWORD *)0x7FFFFFFFFFFFFFFFLL )
  {
    result = (_QWORD *)(sps + 160);
    while ( 1 )
    {
      result = (_QWORD *)*result;
      if ( result == (_QWORD *)(sps + 160) )
        break;
      if ( result == a1 )
        return result;
    }
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_h2bam__rs_30, "sps_h2bam")) )
    {
      printk(&unk_2887E, "sps_h2bam", a1);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps:Can't find BAM device for handle 0x%pK\n", "sps_h2bam", a1);
    return nullptr;
  }
  return result;
}
