__int64 __fastcall bam_isr(int a1, __int64 a2)
{
  _DWORD *v4; // x8
  _DWORD *v5; // x8
  _BYTE v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 3u
    && (!print_limit_option || (unsigned int)__ratelimit(&bam_isr__rs, "bam_isr")) )
  {
    printk(&unk_239D1, "bam_isr", a2 + 24);
  }
  if ( a2 && *(_DWORD *)(a2 + 568) <= 1u )
    ipc_log_string(*(_QWORD *)(a2 + 536), "%s: sps: bam:%pa; IRQ #:%d\n", "bam_isr", (const void *)(a2 + 24), a1);
  if ( (*(_BYTE *)(a2 + 16) & 0x80) != 0 )
  {
    v4 = *(_DWORD **)(a2 + 104);
    if ( v4 )
    {
      v7[0] = 0;
      if ( *(v4 - 1) != -835259500 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _BYTE *))v4)(4, v7);
      if ( v7[0] == 1 )
      {
        if ( (unsigned __int8)logging_option >= 2u
          && (unsigned __int8)debug_level_option >= 3u
          && (!print_limit_option || (unsigned int)__ratelimit(&bam_isr__rs_274, "bam_isr")) )
        {
          printk(&unk_25ADA, "bam_isr", a2 + 24);
        }
        if ( a2 && *(_DWORD *)(a2 + 568) <= 1u )
          ipc_log_string(
            *(_QWORD *)(a2 + 536),
            "%s: sps: handle IRQ for bam:%pa IRQ #:%d\n",
            "bam_isr",
            (const void *)(a2 + 24),
            a1);
        if ( (unsigned int)sps_bam_check_irq(a2) )
        {
          if ( (unsigned __int8)logging_option >= 2u
            && (unsigned __int8)debug_level_option >= 2u
            && (!print_limit_option || (unsigned int)__ratelimit(&bam_isr__rs_277, "bam_isr")) )
          {
            printk(&unk_239EF, "bam_isr", a2 + 24);
          }
          if ( a2 && *(_DWORD *)(a2 + 568) <= 2u )
            ipc_log_string(
              *(_QWORD *)(a2 + 544),
              "%s: sps: callback bam:%pa IRQ #:%d to poll the pipes\n",
              "bam_isr",
              (const void *)(a2 + 24),
              a1);
        }
        v5 = *(_DWORD **)(a2 + 104);
        if ( *(v5 - 1) != -835259500 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _BYTE *))v5)(5, v7);
      }
      else
      {
        if ( (unsigned __int8)logging_option >= 2u
          && (unsigned __int8)debug_level_option >= 3u
          && (!print_limit_option || (unsigned int)__ratelimit(&bam_isr__rs_280, "bam_isr")) )
        {
          printk(&unk_2831E, "bam_isr", a2 + 24);
        }
        if ( a2 && *(_DWORD *)(a2 + 568) <= 1u )
          ipc_log_string(
            *(_QWORD *)(a2 + 536),
            "%s: sps: BAM is not ready and thus skip IRQ for bam:%pa IRQ #:%d\n",
            "bam_isr",
            (const void *)(a2 + 24),
            a1);
      }
    }
    else
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&bam_isr__rs_283, "bam_isr")) )
      {
        printk(&unk_23A27, "bam_isr", a2 + 24);
      }
      if ( a2 )
        ipc_log_string(
          *(_QWORD *)(a2 + 552),
          "%s: sps: Client of BAM %pa requires confirmation but does not register callback\n",
          "bam_isr",
          (const void *)(a2 + 24));
    }
  }
  else
  {
    sps_bam_check_irq(a2);
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
