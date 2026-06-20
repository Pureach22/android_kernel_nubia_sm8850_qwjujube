__int64 __fastcall bam_pipe_check_zlt(__int64 a1, unsigned int a2)
{
  if ( a1 == 216 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&bam_pipe_check_zlt__rs, "bam_pipe_check_zlt")) )
    {
      printk(&unk_27124, "bam_pipe_check_zlt", 216);
    }
    if ( sps )
      ipc_log_string(
        *(_QWORD *)(sps + 272),
        "%s: Failed to get dev for base addr 0x%pK\n",
        "bam_pipe_check_zlt",
        &_ksymtab_sps_get_free_count);
    return 0;
  }
  if ( !(unsigned int)bam_read_reg_field(a1, 0x1Eu, a2, 4u) )
  {
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 4u
      && (!print_limit_option || (unsigned int)__ratelimit(&bam_pipe_check_zlt__rs_52, "bam_pipe_check_zlt")) )
    {
      printk(&unk_2603B, "bam_pipe_check_zlt", a1);
    }
    if ( !*(_DWORD *)(a1 + 352) )
      ipc_log_string(
        *(_QWORD *)(a1 + 312),
        "%s: sps: bam=0x%pK(va).pipe=%d: the last desc is not ZLT\n",
        "bam_pipe_check_zlt",
        (const void *)a1,
        a2);
    return 0;
  }
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 4u
    && (!print_limit_option || (unsigned int)__ratelimit(&bam_pipe_check_zlt__rs_49, "bam_pipe_check_zlt")) )
  {
    printk(&unk_25BE5, "bam_pipe_check_zlt", a1);
  }
  if ( !*(_DWORD *)(a1 + 352) )
    ipc_log_string(
      *(_QWORD *)(a1 + 312),
      "%s: sps: bam=0x%pK(va).pipe=%d: the last desc is ZLT\n",
      "bam_pipe_check_zlt",
      (const void *)a1,
      a2);
  return 1;
}
