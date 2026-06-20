__int64 __fastcall sps_bam_pipe_get_iovec(__int64 a1, unsigned int a2, _QWORD *a3)
{
  __int64 v3; // x19
  unsigned int v4; // w21
  __int64 v5; // x20
  _QWORD *v7; // x22
  int offset; // w0
  unsigned int v9; // w21
  _QWORD *v10; // x22
  __int64 v11; // x8
  unsigned int *v12; // x21
  unsigned int v13; // w10
  int v14; // w6
  __int64 v15; // x2
  int v16; // w0
  _QWORD *v17; // [xsp+8h] [xbp-38h]

  if ( a2 >= 0x1F )
  {
    __break(0x5512u);
    goto LABEL_40;
  }
  v3 = a1;
  v5 = *(_QWORD *)(a1 + 8LL * a2 + 256);
  if ( !*(_DWORD *)(v5 + 628) || (*(_BYTE *)(v5 + 184) & 0x50) != 0 )
    return 0xFFFFFFFFLL;
  if ( (*(_DWORD *)(v5 + 200) || *(_DWORD *)(v5 + 204)) && !*(_DWORD *)(v5 + 624) )
  {
    v9 = a2;
    if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
    {
      v17 = a3;
      if ( !print_limit_option
        || (v16 = __ratelimit(&sps_bam_pipe_get_iovec__rs, "sps_bam_pipe_get_iovec"), a3 = v17, v16) )
      {
        printk(&unk_22ED5, "sps_bam_pipe_get_iovec", v3 + 24);
        a3 = v17;
      }
    }
    v10 = a3;
    if ( v3 && !*(_DWORD *)(v3 + 568) )
      ipc_log_string(
        *(_QWORD *)(v3 + 528),
        "%s: sps: BAM: %pa; pipe index:%d; polled is %d; hybrid is %d\n",
        "sps_bam_pipe_get_iovec",
        (const void *)(v3 + 24),
        v9,
        *(_DWORD *)(v5 + 200),
        *(_DWORD *)(v5 + 204));
    pipe_handler_eot(v3, v5);
    a2 = v9;
    a3 = v10;
    if ( *(_DWORD *)(v5 + 624) )
      goto LABEL_9;
  }
  else if ( *(_DWORD *)(v5 + 624) )
  {
LABEL_9:
    v4 = a2;
    v7 = a3;
    offset = bam_pipe_get_desc_read_offset(v3 + 216, a2);
    a3 = v7;
    goto LABEL_16;
  }
  offset = *(_DWORD *)(v5 + 256);
  v4 = a2;
LABEL_16:
  v11 = *(unsigned int *)(v5 + 244);
  if ( offset != (_DWORD)v11 )
  {
    v12 = (unsigned int *)(*(_QWORD *)(v5 + 232) + v11);
    *a3 = *(_QWORD *)v12;
    v13 = (unsigned __int8)logging_option;
    if ( (unsigned int)(*(_DWORD *)(v5 + 244) + 8) >= *(_DWORD *)(v5 + 224) )
      v14 = 0;
    else
      v14 = *(_DWORD *)(v5 + 244) + 8;
    *(_DWORD *)(v5 + 244) = v14;
    if ( v13 >= 2 && (unsigned __int8)debug_level_option >= 4u )
    {
      if ( print_limit_option )
      {
        if ( !(unsigned int)__ratelimit(&sps_bam_pipe_get_iovec__rs_247, "sps_bam_pipe_get_iovec") )
          goto LABEL_25;
        v15 = *(unsigned int *)(v5 + 188);
      }
      else
      {
        v15 = *(unsigned int *)(v5 + 188);
      }
      printk(&unk_22AC8, "sps_bam_pipe_get_iovec", v15);
    }
LABEL_25:
    if ( v3 && !*(_DWORD *)(v3 + 568) )
      ipc_log_string(
        *(_QWORD *)(v3 + 528),
        "%s: sps: pipe index:%d; iovec addr:0x%pK; size:0x%x; flags:0x%x; acked_offset:0x%x\n",
        "sps_bam_pipe_get_iovec",
        *(_DWORD *)(v5 + 188),
        (const void *)*v12,
        (unsigned __int16)v12[1],
        HIWORD(v12[1]),
        *(_DWORD *)(v5 + 244));
    return 0;
  }
  *a3 = 0;
  if ( (unsigned __int8)logging_option < 2u || (unsigned __int8)debug_level_option < 4u )
    goto LABEL_18;
  if ( !print_limit_option )
  {
LABEL_31:
    printk(&unk_2A758, "sps_bam_pipe_get_iovec", v3 + 24);
    goto LABEL_18;
  }
LABEL_40:
  if ( (unsigned int)__ratelimit(&sps_bam_pipe_get_iovec__rs_244, "sps_bam_pipe_get_iovec") )
    goto LABEL_31;
LABEL_18:
  if ( v3 )
  {
    if ( !*(_DWORD *)(v3 + 568) )
      ipc_log_string(
        *(_QWORD *)(v3 + 528),
        "%s: sps: BAM: %pa; pipe index:%d; no iovec to process\n",
        "sps_bam_pipe_get_iovec",
        (const void *)(v3 + 24),
        v4);
  }
  return 0;
}
