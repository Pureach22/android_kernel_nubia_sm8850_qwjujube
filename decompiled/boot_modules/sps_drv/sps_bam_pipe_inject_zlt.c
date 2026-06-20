__int64 __fastcall sps_bam_pipe_inject_zlt(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w19
  __int64 v3; // x20
  _BYTE *v4; // x23
  __int64 v5; // x24
  int offset; // w22
  unsigned int v7; // w21
  int v9; // w22
  __int64 v10; // x21
  int v11; // w0

  if ( a2 >= 0x1F )
  {
    __break(0x5512u);
    goto LABEL_59;
  }
  v4 = &loc_2C000;
  v2 = a2;
  v3 = a1;
  v5 = *(_QWORD *)(a1 + 8LL * a2 + 256);
  if ( (*(_BYTE *)(v5 + 184) & 0x10) == 0 )
  {
    if ( (unsigned __int8)logging_option < 2u || (unsigned __int8)debug_level_option < 2u )
    {
LABEL_4:
      if ( v3 && *(_DWORD *)(v3 + 568) <= 2u )
        ipc_log_string(
          *(_QWORD *)(v3 + 544),
          "%s: sps: BAM-to-System pipe: BAM %pa pipe %d\n",
          "sps_bam_pipe_inject_zlt",
          v3 + 24,
          v2);
      goto LABEL_11;
    }
    if ( !print_limit_option )
    {
LABEL_41:
      printk(&unk_27B42, "sps_bam_pipe_inject_zlt", v3 + 24);
      goto LABEL_4;
    }
LABEL_59:
    if ( !(unsigned int)__ratelimit(&sps_bam_pipe_inject_zlt__rs_216, "sps_bam_pipe_inject_zlt") )
      goto LABEL_4;
    goto LABEL_41;
  }
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 2u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_pipe_inject_zlt__rs, "sps_bam_pipe_inject_zlt")) )
  {
    printk(&unk_2866F, "sps_bam_pipe_inject_zlt", v3 + 24);
  }
  if ( v3 && *(_DWORD *)(v3 + 568) < 3u )
    ipc_log_string(
      *(_QWORD *)(v3 + 544),
      "%s: sps: BAM-to-BAM pipe: BAM %pa pipe %d\n",
      "sps_bam_pipe_inject_zlt",
      v3 + 24,
      v2);
LABEL_11:
  if ( (*(_BYTE *)(v5 + 184) & 8) == 0 )
  {
    if ( v4[424] != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_pipe_inject_zlt__rs_219, "sps_bam_pipe_inject_zlt")) )
    {
      printk(&unk_2353C, "sps_bam_pipe_inject_zlt", v3 + 24);
    }
    if ( v3 )
      ipc_log_string(
        *(_QWORD *)(v3 + 552),
        "%s: sps: BAM %pa pipe %d is not enabled\n",
        "sps_bam_pipe_inject_zlt",
        (const void *)(v3 + 24),
        v2);
    return 0xFFFFFFFFLL;
  }
  offset = bam_pipe_get_desc_read_offset(v3 + 216, v2);
  v7 = bam_pipe_get_desc_write_offset(v3 + 216, v2);
  if ( (unsigned __int8)v4[424] >= 2u
    && (unsigned __int8)debug_level_option >= 2u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_pipe_inject_zlt__rs_222, "sps_bam_pipe_inject_zlt")) )
  {
    printk(&unk_251A9, "sps_bam_pipe_inject_zlt", v3 + 24);
  }
  if ( v3 && *(_DWORD *)(v3 + 568) <= 2u )
    ipc_log_string(
      *(_QWORD *)(v3 + 544),
      "%s: sps: BAM %pa pipe %d: read pointer:0x%x; write pointer:0x%x\n",
      "sps_bam_pipe_inject_zlt",
      (const void *)(v3 + 24),
      v2,
      offset,
      v7);
  if ( offset == v7 )
  {
    if ( v4[424] != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_pipe_inject_zlt__rs_225, "sps_bam_pipe_inject_zlt")) )
    {
      printk(&unk_29B56, "sps_bam_pipe_inject_zlt", v3 + 24);
    }
    if ( v3 )
      ipc_log_string(
        *(_QWORD *)(v3 + 552),
        "%s: sps: BAM %pa pipe %d: read pointer 0x%x is already equal to write pointer\n",
        "sps_bam_pipe_inject_zlt",
        (const void *)(v3 + 24),
        v2,
        offset);
    return 0xFFFFFFFFLL;
  }
  v9 = v7 + 8;
  if ( v7 + 8 >= *(_DWORD *)(v5 + 224) )
  {
    if ( (unsigned __int8)v4[424] >= 2u
      && (unsigned __int8)debug_level_option >= 2u
      && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_pipe_inject_zlt__rs_228, "sps_bam_pipe_inject_zlt")) )
    {
      printk(&unk_26447, "sps_bam_pipe_inject_zlt", v3 + 24);
    }
    if ( v3 && *(_DWORD *)(v3 + 568) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v3 + 544),
        "%s: sps: BAM %pa pipe %d: next write is 0x%x: wrap around\n",
        "sps_bam_pipe_inject_zlt",
        (const void *)(v3 + 24),
        v2,
        v9);
    v9 = 0;
  }
  *(_QWORD *)(*(_QWORD *)(v5 + 88) + v7) = 0x4000000000000000LL;
  bam_pipe_set_desc_write_offset(v3 + 216, v2, v9);
  __dsb(0xEu);
  if ( (unsigned __int8)v4[424] >= 2u
    && (unsigned __int8)debug_level_option >= 2u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_pipe_inject_zlt__rs_231, "sps_bam_pipe_inject_zlt")) )
  {
    bam_pipe_get_desc_write_offset(v3 + 216, v2);
    printk(&unk_296D0, "sps_bam_pipe_inject_zlt", v3 + 24);
  }
  if ( v3 && *(_DWORD *)(v3 + 568) <= 2u )
  {
    v10 = *(_QWORD *)(v3 + 544);
    v11 = bam_pipe_get_desc_write_offset(v3 + 216, v2);
    ipc_log_string(
      v10,
      "%s: sps: BAM %pa pipe %d: write pointer to tell HW: 0x%x; write pointer read from HW: 0x%x\n",
      "sps_bam_pipe_inject_zlt",
      (const void *)(v3 + 24),
      v2,
      v9,
      v11);
  }
  return 0;
}
