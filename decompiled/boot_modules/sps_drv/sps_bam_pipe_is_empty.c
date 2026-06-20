__int64 __fastcall sps_bam_pipe_is_empty(__int64 a1, unsigned int a2, _DWORD *a3)
{
  __int64 v3; // x19
  _DWORD *v4; // x20
  __int64 v5; // x24
  int offset; // w22
  int v8; // w23
  char v10; // w0
  int v11; // w8
  void *v12; // x4

  if ( a2 >= 0x1F )
  {
    __break(0x5512u);
    goto LABEL_50;
  }
  v3 = a1;
  v5 = *(_QWORD *)(a1 + 8LL * a2 + 256);
  if ( (*(_BYTE *)(v5 + 184) & 0x40) == 0 )
  {
    v4 = a3;
    offset = bam_pipe_get_desc_read_offset(a1 + 216, a2);
    if ( (*(_BYTE *)(v5 + 184) & 0x10) != 0 )
    {
      v8 = bam_pipe_get_desc_write_offset(v3 + 216, a2);
      if ( offset != v8 )
        goto LABEL_5;
    }
    else
    {
      v8 = *(_DWORD *)(v5 + 244);
      if ( offset != v8 )
      {
LABEL_5:
        if ( (*(_BYTE *)(v5 + 184) & 0x10) == 0 )
        {
          *v4 = 0;
          if ( (unsigned __int8)logging_option >= 2u
            && (unsigned __int8)debug_level_option >= 3u
            && (!print_limit_option || (unsigned int)__ratelimit(
                                                       &sps_bam_pipe_is_empty__rs_252,
                                                       "sps_bam_pipe_is_empty")) )
          {
            printk(&unk_26801, "sps_bam_pipe_is_empty", *(unsigned int *)(v5 + 188));
          }
          if ( v3 )
          {
            if ( *(_DWORD *)(v3 + 568) <= 1u )
              ipc_log_string(
                *(_QWORD *)(v3 + 536),
                "%s: sps: pipe index:%d; this sys2bam pipe is NOT empty\n",
                "sps_bam_pipe_is_empty",
                *(_DWORD *)(v5 + 188));
          }
          return 0;
        }
        if ( (bam_pipe_check_zlt(v3 + 216, a2) & 1) != 0
          && ((v10 = bam_pipe_check_pipe_empty(v3 + 216, a2), (unsigned int)(v8 + 8) >= *(_DWORD *)(v5 + 224))
            ? (v11 = 0)
            : (v11 = v8 + 8),
              v11 == offset) )
        {
          *v4 = 1;
          if ( (v10 & 1) == 0 )
          {
            if ( (unsigned __int8)logging_option >= 2u
              && debug_level_option
              && (!print_limit_option
               || (unsigned int)__ratelimit(&sps_bam_pipe_is_empty__rs_255, "sps_bam_pipe_is_empty")) )
            {
              printk(&unk_2A7C8, "sps_bam_pipe_is_empty", v3 + 24);
            }
            if ( v3 && *(_DWORD *)(v3 + 568) <= 3u )
              ipc_log_string(
                *(_QWORD *)(v3 + 552),
                "%s: sps:BAM %pa pipe %d pipe empty checking for ZLT\n",
                "sps_bam_pipe_is_empty",
                (const void *)(v3 + 24),
                a2);
          }
        }
        else
        {
          *v4 = 0;
        }
LABEL_30:
        if ( (unsigned __int8)logging_option < 2u || (unsigned __int8)debug_level_option < 3u )
        {
LABEL_31:
          if ( v3 && *(_DWORD *)(v3 + 568) <= 1u )
          {
            if ( *v4 )
              v12 = &unk_24626;
            else
              v12 = &unk_26484;
            ipc_log_string(
              *(_QWORD *)(v3 + 536),
              "%s: sps: pipe index:%d; this pipe is %s empty\n",
              "sps_bam_pipe_is_empty",
              *(unsigned int *)(v5 + 188),
              v12);
          }
          return 0;
        }
        if ( !print_limit_option )
        {
LABEL_40:
          printk(&unk_27DF5, "sps_bam_pipe_is_empty", *(unsigned int *)(v5 + 188));
          goto LABEL_31;
        }
LABEL_50:
        if ( !(unsigned int)__ratelimit(&sps_bam_pipe_is_empty__rs_258, "sps_bam_pipe_is_empty") )
          goto LABEL_31;
        goto LABEL_40;
      }
    }
    *v4 = 1;
    goto LABEL_30;
  }
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u
     || (unsigned int)__ratelimit(&sps_bam_pipe_is_empty__rs, "sps_bam_pipe_is_empty")) )
  {
    printk(&unk_29F1D, "sps_bam_pipe_is_empty", v3 + 24);
  }
  if ( v3 )
    ipc_log_string(
      *(_QWORD *)(v3 + 552),
      "%s: sps:Is empty on remote: BAM %pa pipe %d\n",
      "sps_bam_pipe_is_empty",
      (const void *)(v3 + 24),
      a2);
  return 0xFFFFFFFFLL;
}
