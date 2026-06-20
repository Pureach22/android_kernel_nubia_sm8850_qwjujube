__int64 __fastcall sps_bam_pipe_transfer_one(__int64 a1, unsigned int a2, unsigned int a3, int a4, __int64 a5, int a6)
{
  __int64 v6; // x19
  __int64 v7; // x20
  __int64 v8; // x21
  __int64 v9; // x22
  __int64 v10; // x24
  _BYTE *v11; // x25
  _QWORD *v12; // x29
  __int64 v13; // x30
  unsigned int v14; // w23
  __int64 v15; // x26
  int v16; // w8
  int v18; // w23
  int v19; // w9
  unsigned int v20; // w26
  __int64 v21; // x27
  int v22; // w9
  _QWORD *v23; // x8
  unsigned int v24; // w9
  int v25; // w9
  __int64 v26; // x21
  int v27; // w0
  unsigned int v28; // w23
  __int64 v29; // x26
  __int64 v30; // x23
  unsigned int v31; // w26
  int v32; // w0
  _QWORD v33[12]; // [xsp+0h] [xbp-60h] BYREF

  if ( a2 >= 0x1F )
  {
    __break(0x5512u);
    goto LABEL_88;
  }
  v33[0] = v12;
  v33[1] = v13;
  v33[5] = v11;
  v33[6] = v10;
  v33[8] = v9;
  v33[9] = v8;
  v33[10] = v7;
  v33[11] = v6;
  v12 = v33;
  v11 = &loc_2C000;
  LODWORD(v8) = a6;
  LODWORD(v10) = a4;
  LODWORD(v6) = a2;
  v9 = *(_QWORD *)(a1 + 8LL * a2 + 256);
  v7 = a1;
  v33[3] = 0;
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 4u )
  {
    if ( !print_limit_option )
    {
LABEL_69:
      v28 = a3;
      v29 = a5;
      printk(&unk_267C6, "sps_bam_pipe_transfer_one", v7 + 24);
      a3 = v28;
      a5 = v29;
      goto LABEL_3;
    }
LABEL_88:
    v30 = a5;
    v31 = a3;
    v32 = __ratelimit(&sps_bam_pipe_transfer_one__rs, "sps_bam_pipe_transfer_one");
    a3 = v31;
    a5 = v30;
    if ( !v32 )
      goto LABEL_3;
    goto LABEL_69;
  }
LABEL_3:
  if ( v7 && !*(_DWORD *)(v7 + 568) )
  {
    v14 = a3;
    v15 = a5;
    ipc_log_string(
      *(_QWORD *)(v7 + 528),
      "%s: sps:BAM %pa pipe %d addr 0x%pK size 0x%x flags 0x%x\n",
      "sps_bam_pipe_transfer_one",
      (const void *)(v7 + 24),
      v6,
      (const void *)a3,
      v10,
      v8);
    a3 = v14;
    a5 = v15;
  }
  if ( (*(_BYTE *)(v9 + 184) & 0x50) != 0 )
  {
    if ( v11[424] != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_pipe_transfer_one__rs_190, "sps_bam_pipe_transfer_one")) )
    {
      printk(&unk_24326, "sps_bam_pipe_transfer_one", v7 + 24);
    }
    if ( v7 )
      ipc_log_string(
        *(_QWORD *)(v7 + 552),
        "%s: sps:Transfer on BAM-to-BAM: BAM %pa pipe %d\n",
        "sps_bam_pipe_transfer_one",
        v7 + 24,
        (unsigned int)v6);
    return 0xFFFFFFFFLL;
  }
  v16 = *(_DWORD *)(v9 + 624);
  if ( a5 && v16 )
  {
    if ( v11[424] != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_pipe_transfer_one__rs_193, "sps_bam_pipe_transfer_one")) )
    {
      printk(&unk_28FBF, "sps_bam_pipe_transfer_one", v7 + 24);
    }
    if ( v7 )
      ipc_log_string(
        *(_QWORD *)(v7 + 552),
        "%s: sps:User pointer arg non-NULL: BAM %pa pipe %d\n",
        "sps_bam_pipe_transfer_one",
        v7 + 24,
        (unsigned int)v6);
    return 0xFFFFFFFFLL;
  }
  if ( (unsigned int)(*(_DWORD *)(v9 + 240) + 8) >= *(_DWORD *)(v9 + 224) )
    v18 = 0;
  else
    v18 = *(_DWORD *)(v9 + 240) + 8;
  if ( v18 == *(_DWORD *)(v9 + 244) )
  {
    if ( *(_DWORD *)(v9 + 628) || !*(_DWORD *)(v9 + 200) )
    {
      if ( (sps_bam_pipe_transfer_one_show_recom & 1) == 0 )
      {
        v19 = (unsigned __int8)v11[424];
        sps_bam_pipe_transfer_one_show_recom = 1;
        if ( v19 != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_bam_pipe_transfer_one__rs_202, "sps_bam_pipe_transfer_one")) )
        {
          printk(&unk_27AF9, "sps_bam_pipe_transfer_one", v7 + 24);
        }
        if ( v7 )
          ipc_log_string(
            *(_QWORD *)(v7 + 552),
            "%s: sps:Client of BAM %pa pipe %d is recommended to have flow control\n",
            "sps_bam_pipe_transfer_one",
            (const void *)(v7 + 24),
            v6);
      }
      if ( (unsigned __int8)v11[424] >= 2u
        && (unsigned __int8)debug_level_option >= 3u
        && (!print_limit_option
         || (unsigned int)__ratelimit(&sps_bam_pipe_transfer_one__rs_203, "sps_bam_pipe_transfer_one")) )
      {
        printk(&unk_24359, "sps_bam_pipe_transfer_one", v7 + 24);
      }
      if ( v7 && *(_DWORD *)(v7 + 568) <= 1u )
        ipc_log_string(
          *(_QWORD *)(v7 + 536),
          "%s: sps:Descriptor FIFO is full for BAM %pa pipe %d\n",
          "sps_bam_pipe_transfer_one",
          v7 + 24,
          (unsigned int)v6);
      return 0xFFFFFFFFLL;
    }
    v20 = a3;
    v21 = a5;
    pipe_handler_eot(v7, v9);
    if ( v18 == *(_DWORD *)(v9 + 244) )
    {
      if ( (sps_bam_pipe_transfer_one_show_recom & 1) == 0 )
      {
        v22 = (unsigned __int8)v11[424];
        sps_bam_pipe_transfer_one_show_recom = 1;
        if ( v22 != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_bam_pipe_transfer_one__rs_196, "sps_bam_pipe_transfer_one")) )
        {
          printk(&unk_27AF9, "sps_bam_pipe_transfer_one", v7 + 24);
        }
        if ( v7 )
          ipc_log_string(
            *(_QWORD *)(v7 + 552),
            "%s: sps:Client of BAM %pa pipe %d is recommended to have flow control\n",
            "sps_bam_pipe_transfer_one",
            (const void *)(v7 + 24),
            v6);
      }
      if ( (unsigned __int8)v11[424] >= 2u
        && (unsigned __int8)debug_level_option >= 3u
        && (!print_limit_option
         || (unsigned int)__ratelimit(&sps_bam_pipe_transfer_one__rs_199, "sps_bam_pipe_transfer_one")) )
      {
        printk(&unk_2515B, "sps_bam_pipe_transfer_one", v7 + 24);
      }
      if ( v7 && *(_DWORD *)(v7 + 568) <= 1u )
        ipc_log_string(
          *(_QWORD *)(v7 + 536),
          "%s: sps:Descriptor FIFO is full for BAM %pa pipe %d after pipe_handler_eot\n",
          "sps_bam_pipe_transfer_one",
          v7 + 24,
          (unsigned int)v6);
      return 0xFFFFFFFFLL;
    }
    v16 = *(_DWORD *)(v9 + 624);
    a5 = v21;
    a3 = v20;
  }
  if ( v16 )
    v23 = v12 + 3;
  else
    v23 = (_QWORD *)(*(_QWORD *)(v9 + 248) + *(unsigned int *)(v9 + 240));
  *(_DWORD *)v23 = a3;
  *((_WORD *)v23 + 2) = v10;
  if ( (v8 & 0x10) != 0 )
  {
    v25 = (unsigned __int16)v10 | ((v8 & 0xF) << 16);
    if ( *(_DWORD *)(v9 + 216) )
      v24 = v25 | 0xC0000000;
    else
      v24 = v25 | 0x80000000;
  }
  else
  {
    v24 = ((_DWORD)v8 << 16) & 0xFF0FFFFF | (unsigned __int16)v10;
  }
  *((_DWORD *)v23 + 1) = v24;
  *(_QWORD *)(*(_QWORD *)(v9 + 232) + *(unsigned int *)(v9 + 240)) = *v23;
  if ( *(_DWORD *)(v9 + 624) )
  {
    *(_DWORD *)(v9 + 240) = v18;
    if ( (v8 & 0x20) == 0 )
      goto LABEL_58;
LABEL_61:
    if ( !*(_DWORD *)(v7 + 568) )
      goto LABEL_63;
    return 0;
  }
  *(_QWORD *)(*(_QWORD *)(v9 + 264) + (*(_DWORD *)(v9 + 240) & 0xFFFFFFF8)) = a5;
  *(_DWORD *)(v9 + 240) = v18;
  if ( (v8 & 0x20) != 0 )
    goto LABEL_61;
LABEL_58:
  __dsb(0xEu);
  bam_pipe_set_desc_write_offset(v7 + 216, v6, v18);
  if ( !*(_DWORD *)(v7 + 568) )
  {
LABEL_63:
    if ( (unsigned __int8)v11[424] >= 2u
      && (unsigned __int8)debug_level_option >= 4u
      && (!print_limit_option
       || (unsigned int)__ratelimit(&sps_bam_pipe_transfer_one__rs_206, "sps_bam_pipe_transfer_one")) )
    {
      bam_pipe_get_desc_write_offset(v7 + 216, v6);
      printk(&unk_28270, "sps_bam_pipe_transfer_one", v7 + 24);
    }
    if ( v7 && !*(_DWORD *)(v7 + 568) )
    {
      v26 = *(_QWORD *)(v7 + 528);
      v27 = bam_pipe_get_desc_write_offset(v7 + 216, v6);
      ipc_log_string(
        v26,
        "%s: sps: BAM phy addr:%pa; pipe %d; write pointer to tell HW: 0x%x; write pointer read from HW: 0x%x\n",
        "sps_bam_pipe_transfer_one",
        (const void *)(v7 + 24),
        v6,
        v18,
        v27);
    }
  }
  return 0;
}
