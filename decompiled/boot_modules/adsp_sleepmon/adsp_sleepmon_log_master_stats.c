__int64 __fastcall adsp_sleepmon_log_master_stats(unsigned int a1)
{
  unsigned int v2; // w19
  __int64 v3; // x0
  unsigned int v4; // w20
  __int64 (*v5)(void); // x8
  int dsppm_client_stats; // w8
  __int64 v7; // x0
  __int64 (__fastcall *v8)(__int64); // x8

  if ( (a1 & 7) == 0 )
  {
    printk(&unk_995A);
    return 4294967274LL;
  }
  if ( (a1 & 1) != 0 )
  {
    v2 = a1;
    if ( qword_A7D8 )
    {
      printk(&unk_9EC5);
      printk(&unk_A4C9);
      printk(&unk_9D5D);
      printk(&unk_A22D);
      printk(&unk_96D5);
      printk(&unk_927F);
    }
    else
    {
      printk(&unk_9773);
    }
    a1 = v2;
    if ( (v2 & 2) == 0 )
      goto LABEL_4;
  }
  else if ( (a1 & 2) == 0 )
  {
    goto LABEL_4;
  }
  v4 = a1;
  if ( qword_A7D0 )
  {
    printk(&unk_9A4E);
    printk(&unk_9F56);
    printk(&unk_96D5);
    printk(&unk_A4EF);
    printk(&unk_A34B);
    printk(&unk_A34B);
    printk(&unk_A34B);
    printk(&unk_A34B);
    printk(&unk_A34B);
    LOBYTE(a1) = v4;
    if ( !dword_A678 )
      goto LABEL_4;
    dsppm_client_stats = sleepmon_get_dsppm_client_stats(v4);
    LOBYTE(a1) = v4;
    if ( dsppm_client_stats )
      goto LABEL_4;
    v7 = wait_for_completion(&dword_A658);
    ((void (__fastcall *)(__int64))print_complete_dsppm_info)(v7);
  }
  else
  {
    printk(&unk_A3A2);
  }
  LOBYTE(a1) = v4;
LABEL_4:
  if ( (a1 & 4) != 0 )
  {
    if ( qword_A7C0 )
    {
      if ( *(_QWORD *)(qword_A7C0 + 8) > *(_QWORD *)(qword_A7C0 + 16) )
      {
        v5 = (__int64 (*)(void))arch_timer_read_counter;
        if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
          __break(0x8228u);
        v5();
      }
      printk(&unk_A37D);
      printk(&unk_904F);
      printk(&unk_8F9B);
      printk(&unk_A254);
      v3 = printk(&unk_9D84);
    }
    else
    {
      v3 = printk(&unk_9C47);
    }
    if ( qword_A7C8 )
    {
      if ( *(_QWORD *)(qword_A7C8 + 8) > *(_QWORD *)(qword_A7C8 + 16) )
      {
        v8 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
        if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
          __break(0x8228u);
        v8(v3);
      }
      printk(&unk_9DB2);
      printk(&unk_904F);
      printk(&unk_8F9B);
      printk(&unk_A254);
      printk(&unk_9D84);
    }
    else
    {
      printk(&unk_A079);
    }
  }
  return 0;
}
