__int64 __fastcall sps_transfer(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  unsigned int v6; // w21
  unsigned int *v7; // x22
  unsigned int v8; // w8
  unsigned int v9; // t1
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x20
  unsigned int v14; // w19

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_transfer__rs, "sps_transfer")) )
    {
      printk(&unk_228D4, "sps_transfer", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_transfer");
    return 0xFFFFFFFFLL;
  }
  if ( !a2 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_transfer__rs_72, "sps_transfer")) )
    {
      printk(&unk_2A9EC, "sps_transfer", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: transfer is NULL\n", "sps_transfer");
    return 0xFFFFFFFFLL;
  }
  v4 = *(_QWORD *)(a2 + 8);
  if ( !v4 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_transfer__rs_75, "sps_transfer")) )
    {
      printk(&unk_23189, "sps_transfer", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: iovec list is NULL\n", "sps_transfer");
    return 0xFFFFFFFFLL;
  }
  if ( !*(_DWORD *)(a2 + 16) )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_transfer__rs_78, "sps_transfer")) )
    {
      printk(&unk_249F2, "sps_transfer", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: iovec list is empty\n", "sps_transfer");
    return 0xFFFFFFFFLL;
  }
  if ( !*(_QWORD *)a2 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_transfer__rs_81, "sps_transfer")) )
    {
      printk(&unk_241C5, "sps_transfer", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: iovec list address is invalid\n", "sps_transfer");
    return 0xFFFFFFFFLL;
  }
  v6 = 0;
  v7 = (unsigned int *)(v4 + 4);
  do
  {
    v9 = *v7;
    v7 += 2;
    v8 = v9;
    if ( (v9 & 0x8000) != 0 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_transfer__rs_84, "sps_transfer")) )
      {
        printk(&unk_23759, "sps_transfer", a3);
      }
      if ( sps )
        ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: iovec size is invalid\n", "sps_transfer");
      return 0xFFFFFFFFLL;
    }
    if ( (unsigned int)sps_check_iovec_flags(HIWORD(v8)) )
      return 0xFFFFFFFFLL;
    ++v6;
  }
  while ( v6 < *(_DWORD *)(a2 + 16) );
  v11 = sps_bam_lock(a1, v10, a3);
  if ( !v11 )
    return 0xFFFFFFFFLL;
  v12 = *(unsigned int *)(a1 + 188);
  v13 = v11;
  v14 = sps_bam_pipe_transfer(v11, v12, a2);
  raw_spin_unlock_irqrestore(v13 + 232, *(_QWORD *)(v13 + 240));
  return v14;
}
