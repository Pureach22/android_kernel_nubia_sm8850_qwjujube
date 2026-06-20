__int64 __fastcall bam_pipe_set_irq(__int64 result, unsigned int a2, int a3, unsigned int a4, unsigned int a5)
{
  __int64 v5; // x19

  v5 = result;
  if ( result == 216 )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (result = __ratelimit(&bam_pipe_set_irq__rs, "bam_pipe_set_irq"), (_DWORD)result) )
      {
        result = printk(&unk_27124, "bam_pipe_set_irq", 216);
      }
    }
    if ( sps )
      return ipc_log_string(
               *(_QWORD *)(sps + 272),
               "%s: Failed to get dev for base addr 0x%pK\n",
               "bam_pipe_set_irq",
               &_ksymtab_sps_get_free_count);
  }
  else
  {
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 2u
      && (!print_limit_option || (unsigned int)__ratelimit(&bam_pipe_set_irq__rs_79, "bam_pipe_set_irq")) )
    {
      printk(&unk_2609F, "bam_pipe_set_irq", v5 - 192);
    }
    if ( *(_DWORD *)(v5 + 352) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v5 + 328),
        "%s: sps: bam=%pa 0x%pK(va).pipe=%d; irq_en:%d; src_mask:0x%x; ee:%d\n",
        "bam_pipe_set_irq",
        (const void *)(v5 - 192),
        *(const void **)v5,
        a2,
        a3,
        a4,
        a5);
    if ( (a4 & 0x40) != 0 )
    {
      if ( enhd_pipe == 1 )
      {
        bam_write_reg_field(v5, 0xCu, 0, 4u, 0);
      }
      else
      {
        a4 &= ~0x40u;
        if ( (unsigned __int8)logging_option >= 2u
          && (unsigned __int8)debug_level_option >= 2u
          && (!print_limit_option || (unsigned int)__ratelimit(&bam_pipe_set_irq__rs_82, "bam_pipe_set_irq")) )
        {
          printk(&unk_23BE5, "bam_pipe_set_irq", a2);
        }
        if ( *(_DWORD *)(v5 + 352) <= 2u )
          ipc_log_string(
            *(_QWORD *)(v5 + 328),
            "%s: SPS_O_RST_ERROR is not supported, pipe %d\n",
            "bam_pipe_set_irq",
            a2);
      }
    }
    if ( (a4 & 0x80) != 0 )
    {
      if ( enhd_pipe == 1 )
      {
        bam_write_reg_field(v5, 0xCu, 0, 2u, 0);
      }
      else
      {
        a4 &= ~0x80u;
        if ( (unsigned __int8)logging_option >= 2u
          && (unsigned __int8)debug_level_option >= 2u
          && (!print_limit_option || (unsigned int)__ratelimit(&bam_pipe_set_irq__rs_85, "bam_pipe_set_irq")) )
        {
          printk(&unk_227A4, "bam_pipe_set_irq", a2);
        }
        if ( *(_DWORD *)(v5 + 352) <= 2u )
          ipc_log_string(
            *(_QWORD *)(v5 + 328),
            "%s: SPS_O_HRESP_ERROR is not supported, pipe %d\n",
            "bam_pipe_set_irq",
            a2);
      }
    }
    bam_write_reg(v5, 0x21u, a2, a4);
    return bam_write_reg_field(v5, 0x19u, a5, 1 << a2, a3);
  }
  return result;
}
