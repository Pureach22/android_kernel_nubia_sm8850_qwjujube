__int64 __fastcall master_stats_show(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned int v4; // w8
  __int64 v5; // x2
  unsigned int v6; // w8
  __int64 v7; // x2
  __int64 v8; // x20
  __int64 (*v9)(void); // x8
  __int64 v10; // x20
  __int64 (*v11)(void); // x8
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  __int64 v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( dword_A678 )
  {
    v13 = 0;
    v14 = 0;
    mutex_lock(&unk_B140);
    if ( qword_A680 && dword_A678 )
    {
      v2 = *(_QWORD *)(qword_A680 + 968);
      v13 = 0x200000010LL;
      v14 = 0x100000002LL;
      if ( !(unsigned int)rpmsg_send(v2, &v13, 16) )
      {
        mutex_unlock(&unk_B140);
        v3 = wait_for_completion(&dword_A658);
        ((void (__fastcall *)(__int64))print_complete_dsppm_info)(v3);
        goto LABEL_8;
      }
      printk(&unk_9902);
    }
    mutex_unlock(&unk_B140);
  }
LABEL_8:
  if ( qword_A7D8 )
  {
    seq_write(a1, "\nsysMon stats:\n\n", 16);
    seq_printf(a1, "Core clock(KHz): %d\n", *(_DWORD *)qword_A7D8);
    seq_printf(a1, "Ab vote(Bytes): %llu\n", *(_QWORD *)(qword_A7D8 + 4));
    seq_printf(a1, "Ib vote(Bytes): %llu\n", *(_QWORD *)(qword_A7D8 + 12));
    v4 = *(_DWORD *)(qword_A7D8 + 20);
    if ( v4 )
      v5 = v4;
    else
      v5 = 0xFFFFFFFFLL;
    seq_printf(a1, "Sleep latency(usec): %u\n", v5);
    seq_printf(a1, "Timestamp: %llu\n", *(_QWORD *)(qword_A7D8 + 24));
  }
  if ( qword_A7D0 )
  {
    seq_write(a1, "\nDSPPM stats:\n\n", 15);
    seq_printf(a1, "Version: %u\n", *(_DWORD *)qword_A7D0);
    v6 = *(_DWORD *)(qword_A7D0 + 4);
    if ( v6 )
      v7 = v6;
    else
      v7 = 0xFFFFFFFFLL;
    seq_printf(a1, "Sleep latency(usec): %u\n", v7);
    seq_printf(a1, "Timestamp: %u\n", *(_DWORD *)(qword_A7D0 + 8));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_A7D0 + 12), *(_DWORD *)(qword_A7D0 + 16));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_A7D0 + 20), *(_DWORD *)(qword_A7D0 + 24));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_A7D0 + 28), *(_DWORD *)(qword_A7D0 + 32));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_A7D0 + 36), *(_DWORD *)(qword_A7D0 + 40));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_A7D0 + 44), *(_DWORD *)(qword_A7D0 + 48));
  }
  if ( qword_A7C0 )
  {
    v8 = *(_QWORD *)(qword_A7C0 + 24);
    if ( *(_QWORD *)(qword_A7C0 + 8) > *(_QWORD *)(qword_A7C0 + 16) )
    {
      v9 = (__int64 (*)(void))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v8 = v9() + v8 - *(_QWORD *)(qword_A7C0 + 8);
    }
    seq_write(a1, "\nLPM stats:\n\n", 13);
    seq_printf(a1, "Count = %u\n", *(_DWORD *)(qword_A7C0 + 4));
    seq_printf(a1, "Last Entered At = %llu\n", *(_QWORD *)(qword_A7C0 + 8));
    seq_printf(a1, "Last Exited At = %llu\n", *(_QWORD *)(qword_A7C0 + 16));
    seq_printf(a1, "Accumulated Duration = %llu\n", v8);
  }
  if ( qword_A7C8 )
  {
    v10 = *(_QWORD *)(qword_A7C8 + 24);
    if ( *(_QWORD *)(qword_A7C8 + 8) > *(_QWORD *)(qword_A7C8 + 16) )
    {
      v11 = (__int64 (*)(void))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v10 = v11() + v10 - *(_QWORD *)(qword_A7C8 + 8);
    }
    seq_write(a1, "\nLPI stats:\n\n", 13);
    seq_printf(a1, "Count = %u\n", *(_DWORD *)(qword_A7C8 + 4));
    seq_printf(a1, "Last Entered At = %llu\n", *(_QWORD *)(qword_A7C8 + 8));
    seq_printf(a1, "Last Exited At = %llu\n", *(_QWORD *)(qword_A7C8 + 16));
    seq_printf(a1, "Accumulated Duration = %llu\n", v10);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
