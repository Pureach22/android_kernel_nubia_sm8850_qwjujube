__int64 __fastcall sps_get_bam_addr(_QWORD *a1, _QWORD *a2, _DWORD *a3)
{
  _QWORD *v5; // x0
  __int64 v6; // x2
  const void *v7; // x3
  _QWORD *v9; // x21
  int v10; // w8
  _QWORD *v11; // [xsp+18h] [xbp+18h]

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_get_bam_addr__rs, "sps_get_bam_addr")) )
    {
      printk(&unk_261D8, "sps_get_bam_addr", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM handle is NULL\n", "sps_get_bam_addr");
    return 0xFFFFFFFFLL;
  }
  v5 = sps_h2bam(a1);
  if ( !v5 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_get_bam_addr__rs_246, "sps_get_bam_addr")) )
    {
      printk(&unk_25470, "sps_get_bam_addr", v6);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: BAM is not found by handle\n", "sps_get_bam_addr");
    return 0xFFFFFFFFLL;
  }
  v7 = v5 + 3;
  *a2 = v5[3];
  *a3 = *((_DWORD *)v5 + 10);
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
  {
    v9 = v5 + 3;
    v11 = v5;
    if ( !print_limit_option
      || (v10 = __ratelimit(&sps_get_bam_addr__rs_247, "sps_get_bam_addr"), v5 = v11, v7 = v9, v10) )
    {
      printk(&unk_272E4, "sps_get_bam_addr", v9);
      v5 = v11;
      v7 = v9;
    }
  }
  if ( *((_DWORD *)v5 + 142) <= 2u )
    ipc_log_string(v5[68], "%s: sps: BAM: %pa; base:%pa; size:%d\n", "sps_get_bam_addr", v7, a2, *a3);
  return 0;
}
