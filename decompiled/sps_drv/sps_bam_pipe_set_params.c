__int64 __fastcall sps_bam_pipe_set_params(__int64 a1, unsigned int a2, int a3)
{
  unsigned int v3; // w19
  __int64 v4; // x20
  int v5; // w21
  __int64 v6; // x22
  _BYTE *v7; // x23
  __int64 v8; // x25
  int v9; // w8
  int v11; // w8
  int v12; // w8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8

  if ( a2 >= 0x1F )
  {
    __break(0x5512u);
    goto LABEL_49;
  }
  v8 = a2;
  v7 = &loc_2C000;
  v5 = a3;
  v3 = a2;
  v4 = a1;
  v6 = *(_QWORD *)(a1 + 8LL * a2 + 256);
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
  {
    if ( !print_limit_option )
    {
LABEL_41:
      printk(&unk_24302, "sps_bam_pipe_set_params", v4 + 24);
      goto LABEL_3;
    }
LABEL_49:
    if ( !(unsigned int)__ratelimit(&sps_bam_pipe_set_params__rs, "sps_bam_pipe_set_params") )
      goto LABEL_3;
    goto LABEL_41;
  }
LABEL_3:
  if ( v4 && *(_DWORD *)(v4 + 568) <= 2u )
    ipc_log_string(
      *(_QWORD *)(v4 + 544),
      "%s: sps:BAM %pa pipe %d opt 0x%x\n",
      "sps_bam_pipe_set_params",
      (const void *)(v4 + 24),
      v3,
      v5);
  *(_DWORD *)(v6 + 204) = v5 & 0x80000000;
  v9 = *(_DWORD *)(v6 + 184);
  *(_BYTE *)(v6 + 208) = (v5 & 0x80000) != 0;
  if ( (v5 & 0x13000021) == 0 || (v9 & 0x10) == 0 )
  {
    if ( (v5 & 0x2000000) != 0 )
      goto LABEL_16;
    if ( *(_QWORD *)(v6 + 248) )
      goto LABEL_16;
    if ( (v9 & 0x10) != 0 )
      goto LABEL_16;
    v11 = *(_DWORD *)(v6 + 220);
    if ( !v11 )
      goto LABEL_16;
    v12 = 8 * v11;
    if ( (unsigned int)(*(_DWORD *)(v6 + 224) + v12) > 0x1000 )
    {
      v13 = vzalloc_noprof((unsigned int)(*(_DWORD *)(v6 + 224) + v12));
      *(_QWORD *)(v6 + 248) = v13;
      if ( !v13 )
      {
        if ( v7[424] != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_bam_pipe_set_params__rs_175, "sps_bam_pipe_set_params")) )
        {
          printk(&unk_24D05, "sps_bam_pipe_set_params", v3);
        }
        if ( v4 )
          ipc_log_string(
            *(_QWORD *)(v4 + 552),
            "%s: sps:No memory for pipe %d of BAM %pa\n",
            "sps_bam_pipe_set_params",
            v3,
            v4 + 24);
        return 4294967284LL;
      }
    }
    else
    {
      if ( (*(_BYTE *)(v4 + 17) & 1) == 0 )
      {
        v13 = _kmalloc_noprof((unsigned int)(*(_DWORD *)(v6 + 224) + v12), 3520);
        *(_QWORD *)(v6 + 248) = v13;
LABEL_31:
        if ( v13 )
          goto LABEL_32;
        if ( v7[424] != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_bam_pipe_set_params__rs_170, "sps_bam_pipe_set_params")) )
        {
          printk(&unk_29592, "sps_bam_pipe_set_params", v3);
        }
        if ( v4 )
          ipc_log_string(
            *(_QWORD *)(v4 + 552),
            "%s: sps:No memory for pipe%d of BAM %pa\n",
            "sps_bam_pipe_set_params",
            v3,
            v4 + 24);
        return 4294967284LL;
      }
      v13 = *(_QWORD *)(v4 + 576 + 8 * v8);
      if ( !v13 )
      {
        v14 = _kmalloc_noprof((unsigned int)(*(_DWORD *)(v6 + 224) + v12), 3520);
        *(_QWORD *)(v6 + 248) = v14;
        *(_QWORD *)(v4 + 576 + 8 * v8) = v14;
        v13 = *(_QWORD *)(v6 + 248);
        goto LABEL_31;
      }
      *(_QWORD *)(v6 + 248) = v13;
    }
LABEL_32:
    v15 = v13 + *(unsigned int *)(v6 + 224);
    *(_DWORD *)(v6 + 256) = *(_DWORD *)(v6 + 244);
    *(_QWORD *)(v6 + 264) = v15;
LABEL_16:
    *(_DWORD *)(v6 + 196) = (unsigned __int8)v5;
    pipe_set_irq(v4, v3, v5 & 0x1000000);
    *(_DWORD *)(v6 + 228) = v5 & 0x8000000;
    *(_DWORD *)(v6 + 624) = v5 & 0x2000000;
    *(_DWORD *)(v6 + 628) = v5 & 0x10000000;
    return 0;
  }
  if ( v7[424] != 1
    && ((unsigned __int8)print_limit_option < 3u
     || (unsigned int)__ratelimit(&sps_bam_pipe_set_params__rs_163, "sps_bam_pipe_set_params")) )
  {
    printk(&unk_2639E, "sps_bam_pipe_set_params", v4 + 24);
  }
  if ( v4 )
    ipc_log_string(
      *(_QWORD *)(v4 + 552),
      "%s: sps:Invalid option for BAM-to-BAM: BAM %pa pipe %d opt 0x%x\n",
      "sps_bam_pipe_set_params",
      (const void *)(v4 + 24),
      v3,
      v5);
  return 0xFFFFFFFFLL;
}
