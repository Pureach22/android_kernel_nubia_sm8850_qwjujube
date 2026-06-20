__int64 __fastcall bam_check_irq_source(const void **a1, unsigned int a2, int a3, int *a4)
{
  int reg; // w21
  unsigned int v9; // w22
  int v11; // w8

  if ( a1 != &_ksymtab_sps_get_free_count )
  {
    reg = bam_read_reg((__int64)a1, 0x18u);
    if ( (reg & 0x80000000) == 0 )
      return reg & (a3 | 0x80000000);
    v9 = bam_read_reg((__int64)a1, 0xAu);
    if ( (v9 & 4) != 0 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&bam_check_irq_source__rs_31, "bam_check_irq_source")) )
      {
        printk(&unk_2449D, "bam_check_irq_source", a1 - 24);
      }
      ipc_log_string(
        a1[42],
        "%s: sps:bam %pa 0x%pK(va);bam irq status=0x%x\nsps: BAM_ERROR_IRQ\n",
        "bam_check_irq_source",
        a1 - 24,
        *a1,
        v9);
      bam_output_register_content((__int64)a1, a2);
      v11 = 1;
    }
    else if ( (v9 & 2) != 0 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&bam_check_irq_source__rs_34, "bam_check_irq_source")) )
      {
        printk(&unk_275DF, "bam_check_irq_source", a1 - 24);
      }
      ipc_log_string(
        a1[42],
        "%s: sps:bam %pa 0x%pK(va);bam irq status=0x%x\nsps: BAM_HRESP_ERR_IRQ\n",
        "bam_check_irq_source",
        a1 - 24,
        *a1,
        v9);
      bam_output_register_content((__int64)a1, a2);
      v11 = 2;
    }
    else
    {
      if ( (v9 & 0x10) == 0 )
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 2u
           || (unsigned int)__ratelimit(&bam_check_irq_source__rs_40, "bam_check_irq_source")) )
        {
          printk(&unk_252B9, "bam_check_irq_source", a1 - 24);
        }
        ipc_log_string(
          a1[42],
          "%s: sps:bam %pa 0x%pK(va);bam irq status=0x%x\n",
          "bam_check_irq_source",
          a1 - 24,
          *a1,
          v9);
        goto LABEL_29;
      }
      if ( (unsigned __int8)logging_option >= 2u
        && (unsigned __int8)debug_level_option >= 3u
        && (!print_limit_option || (unsigned int)__ratelimit(&bam_check_irq_source__rs_37, "bam_check_irq_source")) )
      {
        printk(&unk_2528A, "bam_check_irq_source", *a1);
      }
      if ( *((_DWORD *)a1 + 88) <= 1u )
        ipc_log_string(a1[40], "%s: sps:bam 0x%pK(va);receive BAM_TIMER_IRQ\n", "bam_check_irq_source", *a1);
      v11 = 3;
    }
    *a4 = v11;
LABEL_29:
    bam_write_reg((__int64)a1, 0xBu, 0, v9);
    return reg & (a3 | 0x80000000);
  }
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u
     || (unsigned int)__ratelimit(&bam_check_irq_source__rs, "bam_check_irq_source")) )
  {
    printk(&unk_27124, "bam_check_irq_source", 216);
  }
  if ( sps )
    ipc_log_string(
      *(_QWORD *)(sps + 272),
      "%s: Failed to get dev for base addr 0x%pK\n",
      "bam_check_irq_source",
      &_ksymtab_sps_get_free_count);
  return 0xFFFFFFFFLL;
}
