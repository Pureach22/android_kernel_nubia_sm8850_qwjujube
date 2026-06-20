__int64 __fastcall sps_bam_pipe_get_event(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v7; // x21
  __int64 v9; // x9
  _QWORD *v10; // x0
  _QWORD *v11; // x8
  __int64 v12; // x9
  __int64 v13; // x8
  __int64 v14; // x10
  __int64 v15; // x11
  _QWORD *v16; // x9

  if ( a2 >= 0x1F )
  {
    __break(0x5512u);
    goto LABEL_37;
  }
  v3 = a3;
  v4 = a1;
  v7 = *(_QWORD *)(a1 + 8LL * a2 + 256);
  if ( !*(_DWORD *)(v7 + 624) )
  {
    if ( *(_DWORD *)(v7 + 200) && (*(_BYTE *)(v7 + 184) & 0x10) == 0 )
      pipe_handler_eot(a1, *(_QWORD *)(a1 + 8LL * a2 + 256));
    v9 = *(_QWORD *)(v7 + 560);
    v5 = v7 + 560;
    if ( v9 == v5 )
    {
      if ( (unsigned __int8)logging_option >= 2u
        && (unsigned __int8)debug_level_option >= 4u
        && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_pipe_get_event__rs_236, "sps_bam_pipe_get_event")) )
      {
        printk(&unk_2709E, "sps_bam_pipe_get_event", v4 + 24);
      }
      if ( v4 && !*(_DWORD *)(v4 + 568) )
        ipc_log_string(
          *(_QWORD *)(v4 + 528),
          "%s: sps:events_q of bam %pa is empty\n",
          "sps_bam_pipe_get_event",
          (const void *)(v4 + 24));
LABEL_26:
      *(_DWORD *)(v3 + 8) = 0;
      return 0;
    }
    if ( (unsigned __int8)logging_option < 2u || (unsigned __int8)debug_level_option < 4u )
    {
LABEL_14:
      if ( v4 && !*(_DWORD *)(v4 + 568) )
        ipc_log_string(
          *(_QWORD *)(v4 + 528),
          "%s: sps:events_q of bam %pa is not empty\n",
          "sps_bam_pipe_get_event",
          (const void *)(v4 + 24));
      v10 = *(_QWORD **)v5;
      v11 = *(_QWORD **)(*(_QWORD *)v5 + 8LL);
      if ( *v11 == *(_QWORD *)v5 && (v12 = *v10, *(_QWORD **)(*v10 + 8LL) == v10) )
      {
        *(_QWORD *)(v12 + 8) = v11;
        *v11 = v12;
      }
      else
      {
        _list_del_entry_valid_or_report(v10);
        v10 = v16;
      }
      *v10 = 0xDEAD000000000100LL;
      v10[1] = 0xDEAD000000000122LL;
      if ( v10 )
      {
        v13 = v10[5];
        v14 = v10[2];
        v15 = v10[3];
        *(_QWORD *)(v3 + 16) = v10[4];
        *(_QWORD *)(v3 + 24) = v13;
        *(_QWORD *)v3 = v14;
        *(_QWORD *)(v3 + 8) = v15;
        kfree(v10);
        return 0;
      }
      goto LABEL_26;
    }
    if ( !print_limit_option )
    {
LABEL_32:
      printk(&unk_26C61, "sps_bam_pipe_get_event", v4 + 24);
      goto LABEL_14;
    }
LABEL_37:
    if ( !(unsigned int)__ratelimit(&sps_bam_pipe_get_event__rs_239, "sps_bam_pipe_get_event") )
      goto LABEL_14;
    goto LABEL_32;
  }
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u
     || (unsigned int)__ratelimit(&sps_bam_pipe_get_event__rs, "sps_bam_pipe_get_event")) )
  {
    printk(&unk_25A5D, "sps_bam_pipe_get_event", v4 + 24);
  }
  if ( v4 )
    ipc_log_string(
      *(_QWORD *)(v4 + 552),
      "%s: sps:Invalid connection for event: BAM %pa pipe %d context 0x%pK\n",
      "sps_bam_pipe_get_event",
      (const void *)(v4 + 24),
      a2,
      (const void *)v7);
  *(_DWORD *)(v3 + 8) = 0;
  return 0xFFFFFFFFLL;
}
