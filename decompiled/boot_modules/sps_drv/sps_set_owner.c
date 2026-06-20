__int64 __fastcall sps_set_owner(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x19
  __int64 v7; // x8
  unsigned int v8; // w22
  int v9; // w8
  bool v10; // zf
  __int64 v11; // x8
  __int64 v12; // x8
  int v13; // w8
  unsigned int v15; // w19

  if ( !a1 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_set_owner__rs, "sps_set_owner")) )
    {
      printk(&unk_228D4, "sps_set_owner", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: pipe is NULL\n", "sps_set_owner");
    return 0xFFFFFFFFLL;
  }
  if ( !a3 )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_set_owner__rs_115, "sps_set_owner")) )
    {
      printk(&unk_288B0, "sps_set_owner", a3);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: connection is NULL\n", "sps_set_owner");
    return 0xFFFFFFFFLL;
  }
  if ( (_DWORD)a2 != 2 )
  {
    v15 = a2;
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_set_owner__rs_116, "sps_set_owner")) )
    {
      printk(&unk_25419, "sps_set_owner", v15);
    }
    if ( sps )
      ipc_log_string(*(_QWORD *)(sps + 272), "%s: sps: Unsupported ownership state: %d\n", "sps_set_owner", v15);
    return 0xFFFFFFFFLL;
  }
  v5 = sps_bam_lock(a1, a2, a3);
  if ( !v5 )
    return 0xFFFFFFFFLL;
  v6 = v5;
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 4u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_set_owner__rs_119, "sps_set_owner")) )
  {
    printk(&unk_299D3, "sps_set_owner", v6 + 24);
  }
  v7 = a1;
  if ( !*(_DWORD *)(v6 + 568) )
  {
    ipc_log_string(
      *(_QWORD *)(v6 + 528),
      "%s: sps: BAM: %pa; pipe index:%d\n",
      "sps_set_owner",
      (const void *)(v6 + 24),
      *(_DWORD *)(a1 + 188));
    v7 = a1;
  }
  v8 = ((__int64 (__fastcall *)(__int64, _QWORD))sps_bam_set_satellite)(v6, *(unsigned int *)(v7 + 188));
  if ( !v8 )
  {
    v9 = *(_DWORD *)(a1 + 76);
    v10 = v9 == 0;
    if ( v9 )
      v11 = 64;
    else
      v11 = 24;
    *(_QWORD *)a3 = *(_QWORD *)(*(_QWORD *)(a1 + 176) + v11);
    v12 = 72;
    if ( v10 )
      v12 = 32;
    v13 = *(_DWORD *)(*(_QWORD *)(a1 + 176) + v12);
    *(_QWORD *)(a3 + 12) = 286331153;
    *(_DWORD *)(a3 + 8) = v13;
  }
  raw_spin_unlock_irqrestore(v6 + 232, *(_QWORD *)(v6 + 240));
  return v8;
}
