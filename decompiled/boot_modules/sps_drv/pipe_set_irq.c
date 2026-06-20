__int64 __fastcall pipe_set_irq(__int64 a1, unsigned int a2, int a3)
{
  unsigned int v3; // w19
  __int64 v4; // x20
  int v5; // w21
  _DWORD *v6; // x22
  unsigned __int8 *v7; // x23
  int v8; // w8
  int v9; // w2
  unsigned int v10; // w8
  unsigned int v11; // w3
  int v13; // w8
  unsigned int v14; // w9

  if ( a2 >= 0x1F )
  {
    __break(0x5512u);
    goto LABEL_29;
  }
  v7 = (unsigned __int8 *)&loc_2C000;
  v5 = a3;
  v3 = a2;
  v4 = a1;
  v6 = *(_DWORD **)(a1 + 8LL * a2 + 256);
  if ( (unsigned __int8)logging_option >= 2u && (unsigned __int8)debug_level_option >= 2u )
  {
    if ( !print_limit_option )
    {
LABEL_24:
      printk(&unk_274CF, "pipe_set_irq", v4 + 24);
      goto LABEL_3;
    }
LABEL_29:
    if ( !(unsigned int)__ratelimit(&pipe_set_irq__rs, "pipe_set_irq") )
      goto LABEL_3;
    goto LABEL_24;
  }
LABEL_3:
  if ( v4 && *(_DWORD *)(v4 + 568) <= 2u )
    ipc_log_string(
      *(_QWORD *)(v4 + 544),
      "%s: sps:BAM:%pa; pipe %d; poll:%d, irq_mask:0x%x; pipe state:0x%x; dev state:0x%x\n",
      "pipe_set_irq",
      (const void *)(v4 + 24),
      v3,
      v5,
      v6[49],
      v6[46],
      *(_DWORD *)(v4 + 160));
  if ( v5 || !v6[49] )
  {
    v8 = v6[46];
    v9 = 0;
    v6[50] = 1;
    v10 = v8 & 0xFFFFFFFB;
LABEL_8:
    v6[46] = v10;
    goto LABEL_9;
  }
  v13 = v6[46];
  if ( (*(_BYTE *)(v4 + 160) & 4) != 0 )
  {
    if ( (v6[46] & 0x14) == 0x10 )
    {
      bam_pipe_get_and_clear_irq_status(v4 + 216, v3);
      v13 = v6[46];
    }
    v10 = v13 | 4;
    v6[50] = 0;
    v9 = 1;
    goto LABEL_8;
  }
  v14 = v7[424];
  v6[46] = v13 & 0xFFFFFFFB;
  v6[50] = 1;
  if ( v14 >= 2
    && (unsigned __int8)debug_level_option >= 2u
    && (!print_limit_option || (unsigned int)__ratelimit(&pipe_set_irq__rs_289, "pipe_set_irq")) )
  {
    printk(&unk_23A7A, "pipe_set_irq", v4 + 24);
  }
  if ( v4 && *(_DWORD *)(v4 + 568) <= 2u )
  {
    ipc_log_string(
      *(_QWORD *)(v4 + 544),
      "%s: sps:BAM %pa pipe %d forced to use polling\n",
      "pipe_set_irq",
      (const void *)(v4 + 24),
      v3);
    v9 = 0;
  }
  else
  {
    v9 = 0;
  }
LABEL_9:
  v11 = v6[49];
  if ( (v6[46] & 0x20) != 0 )
    return bam_pipe_set_mti(v4 + 216, v3, v9, v11);
  else
    return bam_pipe_set_irq(v4 + 216, v3, v9, v11, *(_DWORD *)(v4 + 128));
}
