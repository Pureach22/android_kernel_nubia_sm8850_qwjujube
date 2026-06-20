__int64 __fastcall bam_output_register_content(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  int reg_field; // w20
  __int64 v5; // x21
  unsigned __int64 v6; // x22
  unsigned int i; // w21

  v2 = result;
  if ( result == 216 )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (result = __ratelimit(&bam_output_register_content__rs, "bam_output_register_content"), (_DWORD)result) )
      {
        result = printk(&unk_27124, "bam_output_register_content", 216);
      }
    }
    if ( sps )
      return ipc_log_string(
               *(_QWORD *)(sps + 272),
               "%s: Failed to get dev for base addr 0x%pK\n",
               "bam_output_register_content",
               &_ksymtab_sps_get_free_count);
  }
  else
  {
    print_bam_test_bus_reg(result, 0);
    print_bam_selected_reg(v2, 8);
    reg_field = bam_read_reg_field(v2, 3u, 0, 0xFFu);
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 2u
       || (unsigned int)__ratelimit(&bam_output_register_content__rs_28, "bam_output_register_content")) )
    {
      printk(&unk_268E1, "bam_output_register_content", v2 - 192);
    }
    result = ipc_log_string(
               *(_QWORD *)(v2 + 336),
               "%s: sps:bam %pa 0x%pK(va) has %d pipes\n",
               "bam_output_register_content",
               (const void *)(v2 - 192),
               *(const void **)v2,
               reg_field);
    if ( enhd_pipe == 1
      && (result = bam_read_reg_field(v2, 0x1Bu, a2, 0x7FFFFFFFu), (enhd_pipe & 1) != 0)
      && (_DWORD)result )
    {
      if ( reg_field )
      {
        v5 = 0;
        v6 = (unsigned int)result;
        do
        {
          if ( ((v6 >> v5) & 1) != 0 )
            result = print_bam_pipe_selected_reg(v2, (unsigned int)v5);
          ++v5;
        }
        while ( reg_field != v5 );
      }
    }
    else if ( reg_field )
    {
      for ( i = 0; i != reg_field; ++i )
        result = print_bam_pipe_selected_reg(v2, i);
    }
  }
  return result;
}
