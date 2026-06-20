__int64 __fastcall sps_bam_pipe_connect(__int64 a1, int *a2)
{
  __int64 v4; // x25
  __int64 v5; // x3
  int v6; // w4
  unsigned int v7; // w12
  unsigned int v8; // w5
  char *v9; // x23
  __int64 v10; // x8
  __int64 v11; // x26
  __int64 v12; // x20
  __int64 v13; // x19
  int v14; // w9
  int v15; // w8
  __int64 result; // x0
  int v17; // w8
  char *v18; // x28
  int v19; // w9
  int v20; // w9
  __int64 v21; // x8
  int v22; // w8
  __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x9
  int v26; // w8
  __int64 v27; // x23
  __int64 v28; // x2
  __int64 v29; // x0
  int v30; // w8
  __int64 v31; // x2
  __int64 v32; // x2
  int *v33; // x8
  int v34; // w8
  int v35; // w9
  int v36; // w8
  __int64 v37; // [xsp+0h] [xbp-50h] BYREF
  __int64 v38; // [xsp+8h] [xbp-48h]
  __int64 v39; // [xsp+10h] [xbp-40h]
  __int64 v40; // [xsp+18h] [xbp-38h]
  __int64 v41; // [xsp+20h] [xbp-30h]
  __int64 v42; // [xsp+28h] [xbp-28h]
  __int64 v43; // [xsp+30h] [xbp-20h]
  __int64 v44; // [xsp+38h] [xbp-18h]
  __int64 v45; // [xsp+40h] [xbp-10h]
  __int64 v46; // [xsp+48h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 0;
  v45 = 0;
  v4 = *(_QWORD *)(a1 + 176);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v37 = 0;
  *(_QWORD *)a1 = a1;
  *(_QWORD *)(a1 + 8) = a1;
  *(_QWORD *)(a1 + 184) = 0xFFFFFFFF00000000LL;
  *(_QWORD *)(a1 + 192) = 0;
  *(_QWORD *)(a1 + 216) = 0xFFFFFFFFLL;
  *(_DWORD *)(a1 + 224) = 0;
  *(_BYTE *)(a1 + 640) = 0;
  *(_BYTE *)(a1 + 208) = 0;
  memset((void *)(a1 + 232), 0, 0x198u);
  *(_QWORD *)(a1 + 560) = a1 + 560;
  *(_QWORD *)(a1 + 568) = a1 + 560;
  v6 = *a2;
  v41 = 0;
  v42 = 0;
  v7 = (unsigned __int8)logging_option;
  v37 = 0;
  v38 = 0;
  *(_DWORD *)(a1 + 216) = v6;
  v8 = a2[1];
  v39 = 0;
  v40 = 0;
  v43 = 0;
  v44 = 0;
  if ( v6 )
    v9 = (_BYTE *)&unk_10;
  else
    v9 = (_BYTE *)&unk_38;
  v45 = 0;
  LODWORD(v38) = v6 == 0;
  LODWORD(v42) = HIWORD(v8) & 1;
  if ( v6 )
    v10 = 56;
  else
    v10 = 16;
  v11 = v4 + v10;
  v12 = *(_QWORD *)(v4 + v10 + 32);
  v13 = *(unsigned int *)(v4 + v10 + 16);
  if ( v7 >= 2 && (unsigned __int8)debug_level_option >= 2u )
  {
    if ( print_limit_option )
      goto LABEL_171;
LABEL_117:
    printk(&unk_2A2D8, "sps_bam_pipe_connect", v12 + 24);
    goto LABEL_8;
  }
  while ( 1 )
  {
LABEL_8:
    if ( v12 && *(_DWORD *)(v12 + 568) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v12 + 544),
        "%s: sps:BAM %pa; pipe %d; mode:%d; options:0x%x\n",
        "sps_bam_pipe_connect",
        (const void *)(v12 + 24),
        v13,
        *a2,
        a2[1]);
    if ( (unsigned int)v13 >= *(_DWORD *)(v12 + 48) )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_117, "sps_bam_pipe_connect")) )
      {
        printk(&unk_2AF0B, "sps_bam_pipe_connect", v12 + 24);
      }
      if ( v12 )
        ipc_log_string(
          *(_QWORD *)(v12 + 552),
          "%s: sps:Invalid BAM %pa pipe: %d\n",
          "sps_bam_pipe_connect",
          v12 + 24,
          (unsigned int)v13);
      goto LABEL_24;
    }
    v14 = *(_DWORD *)(v12 + 128);
    LOWORD(v37) = *(_DWORD *)(v11 + 20);
    v15 = *(_DWORD *)(v12 + 120);
    HIDWORD(v42) = v14;
    HIDWORD(v41) = *(_DWORD *)(v11 + 24);
    if ( (v15 & 0x10) != 0 || (v11 = 1LL << v13, ((1LL << v13) & *(unsigned int *)(v12 + 124)) != 0) )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_118, "sps_bam_pipe_connect")) )
      {
        printk(&unk_279FC, "sps_bam_pipe_connect", v12 + 24);
      }
      if ( v12 )
        ipc_log_string(
          *(_QWORD *)(v12 + 552),
          "%s: sps:BAM %pa pipe %d is not local\n",
          "sps_bam_pipe_connect",
          v12 + 24,
          (unsigned int)v13);
LABEL_24:
      result = 0xFFFFFFFFLL;
      goto LABEL_25;
    }
    if ( (v15 & 8) != 0 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_119, "sps_bam_pipe_connect")) )
      {
        printk(&unk_259A0, "sps_bam_pipe_connect", v12 + 24);
      }
      if ( v12 )
        ipc_log_string(
          *(_QWORD *)(v12 + 552),
          "%s: sps:BAM %pa pipe %d remote config is not supported\n",
          "sps_bam_pipe_connect",
          v12 + 24,
          (unsigned int)v13);
      goto LABEL_24;
    }
    v17 = *(_DWORD *)(a1 + 84);
    v18 = &v9[v4];
    if ( (v17 & 0x400) != 0 )
    {
      v20 = *(_DWORD *)(a1 + 184);
      HIDWORD(v38) = 0;
      *(_DWORD *)(a1 + 184) = v20 | 0x10;
      if ( (*(_BYTE *)(v12 + 17) & 2) == 0 )
        goto LABEL_44;
    }
    else
    {
      if ( !*((_QWORD *)v18 + 4) )
      {
        v25 = *(_QWORD *)(v4 + 96);
        HIDWORD(v38) = 1;
        *(_QWORD *)(a1 + 232) = v25;
        *(_QWORD *)(a1 + 240) = 0;
        goto LABEL_59;
      }
      v19 = *(_DWORD *)(a1 + 184);
      HIDWORD(v38) = 0;
      *(_DWORD *)(a1 + 184) = v19 | 0x10;
      if ( (*(_BYTE *)(v12 + 17) & 2) == 0 )
      {
        LODWORD(v43) = *(_QWORD *)(*((_QWORD *)v18 + 4) + 24LL);
        goto LABEL_44;
      }
    }
    v21 = 40;
    if ( !*(_DWORD *)(a1 + 216) )
      v21 = 64;
    v9 = *(char **)(a1 + v21);
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 2u
      && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_122, "sps_bam_pipe_connect")) )
    {
      printk(&unk_259DA, "sps_bam_pipe_connect", v12 + 24);
    }
    if ( v12 && *(_DWORD *)(v12 + 568) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v12 + 544),
        "%s: sps:BAM %pa pipe %d uses IOVA 0x%pK\n",
        "sps_bam_pipe_connect",
        (const void *)(v12 + 24),
        v13,
        v9);
    v17 = *(_DWORD *)(a1 + 84);
    LODWORD(v43) = (_DWORD)v9;
LABEL_44:
    if ( (v17 & 0x400) != 0 )
    {
      v23 = *(_QWORD *)(a1 + 56);
      v22 = *(_DWORD *)(a1 + 72);
      BYTE4(v45) = 1;
      LODWORD(v43) = v23;
    }
    else
    {
      v22 = *((_DWORD *)v18 + 4);
    }
    v24 = *(_QWORD *)(v4 + 104);
    HIDWORD(v43) = v22;
    if ( v24 == 3735928559LL
      || *(_QWORD *)(v4 + 136) == 3735928559LL
      || !*(_DWORD *)(v4 + 120)
      || !*(_DWORD *)(v4 + 152) )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_125, "sps_bam_pipe_connect")) )
      {
        printk(&unk_25E35, "sps_bam_pipe_connect", v12 + 24);
      }
      if ( v12 )
        ipc_log_string(
          *(_QWORD *)(v12 + 552),
          "%s: sps:FIFO buffers are not allocated for BAM %pa pipe %d\n",
          "sps_bam_pipe_connect",
          v12 + 24,
          (unsigned int)v13);
      goto LABEL_24;
    }
    if ( (*(_BYTE *)(v12 + 17) & 2) != 0 )
    {
      v44 = *(_QWORD *)(a1 + 136);
      if ( (unsigned __int8)logging_option >= 2u
        && (unsigned __int8)debug_level_option >= 2u
        && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_128, "sps_bam_pipe_connect")) )
      {
        printk(&unk_2468C, "sps_bam_pipe_connect", v12 + 24);
      }
      if ( v12 && *(_DWORD *)(v12 + 568) <= 2u )
        ipc_log_string(
          *(_QWORD *)(v12 + 544),
          "%s: sps:BAM %pa pipe %d uses IOVA 0x%pK for data FIFO\n",
          "sps_bam_pipe_connect",
          (const void *)(v12 + 24),
          v13,
          *(const void **)(a1 + 136));
    }
    else
    {
      v44 = *(_QWORD *)(v4 + 136);
    }
    v28 = *(unsigned int *)(v4 + 152);
    v29 = *(_QWORD *)(v4 + 128);
    v30 = *(_DWORD *)(a1 + 216);
    LODWORD(v45) = *(_DWORD *)(v4 + 152);
    if ( v29 )
    {
      if ( v30 )
        goto LABEL_59;
      _memset_io(v29, 0, v28, v5);
      v30 = *(_DWORD *)(a1 + 216);
    }
    if ( !v30 )
      LODWORD(v39) = (*((_BYTE *)a2 + 6) & 4) != 0;
LABEL_59:
    *(_DWORD *)(a1 + 188) = v13;
    *(_DWORD *)(a1 + 192) = v11;
    if ( *(_QWORD *)(v4 + 104) != 3735928559LL )
    {
      if ( *(_DWORD *)(v4 + 120) <= 0xFu )
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_131, "sps_bam_pipe_connect")) )
        {
          printk(&unk_26BEA, "sps_bam_pipe_connect", v12 + 24);
        }
        if ( v12 )
          ipc_log_string(
            *(_QWORD *)(v12 + 552),
            "%s: sps:Invalid descriptor FIFO size for BAM %pa pipe %d: %d\n",
            "sps_bam_pipe_connect",
            (const void *)(v12 + 24),
            v13,
            *(_DWORD *)(v4 + 120));
        goto LABEL_24;
      }
      v9 = *(char **)(v4 + 96);
      if ( (*(_BYTE *)(v12 + 17) & 2) != 0 )
      {
        v40 = *(_QWORD *)(a1 + 104);
        if ( (unsigned __int8)logging_option >= 2u
          && (unsigned __int8)debug_level_option >= 2u
          && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_134, "sps_bam_pipe_connect")) )
        {
          printk(&unk_2953A, "sps_bam_pipe_connect", v12 + 24);
        }
        if ( v12 && *(_DWORD *)(v12 + 568) <= 2u )
          ipc_log_string(
            *(_QWORD *)(v12 + 544),
            "%s: sps:BAM %pa pipe %d uses IOVA 0x%pK for desc FIFO\n",
            "sps_bam_pipe_connect",
            (const void *)(v12 + 24),
            v13,
            *(const void **)(a1 + 104));
      }
      else
      {
        v40 = *(_QWORD *)(v4 + 104);
      }
      v31 = *(unsigned int *)(v4 + 120);
      LODWORD(v41) = *(_DWORD *)(v4 + 120);
      if ( v9 && (!*(_DWORD *)(a1 + 216) || HIDWORD(v38) == 1) )
        _memset_io(v9, 0, v31, v5);
    }
    v26 = v41;
    *(_DWORD *)(a1 + 220) = (unsigned int)v41 >> 3;
    *(_DWORD *)(a1 + 224) = v26;
    if ( (*(_BYTE *)(v12 + 160) & 8) == 0 && (unsigned int)sps_bam_enable(v12) )
      goto LABEL_62;
    if ( (unsigned int)v13 < 0x1F )
      break;
    __break(0x5512u);
LABEL_171:
    if ( (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs, "sps_bam_pipe_connect") )
      goto LABEL_117;
  }
  v27 = v12 + 256;
  if ( *(_QWORD *)(v12 + 256 + 8 * v13) != -2290649225LL )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_137, "sps_bam_pipe_connect")) )
    {
      printk(&unk_28F8D, "sps_bam_pipe_connect", (unsigned int)v13);
    }
    if ( v12 )
      ipc_log_string(
        *(_QWORD *)(v12 + 552),
        "%s: sps:Invalid pipe %d on BAM %pa for connect\n",
        "sps_bam_pipe_connect",
        v13,
        (const void *)(v12 + 24));
    goto LABEL_24;
  }
  if ( (unsigned int)bam_pipe_is_enabled(v12 + 216, v13) )
  {
    if ( (*((_BYTE *)a2 + 6) & 0x80) == 0 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_143, "sps_bam_pipe_connect")) )
      {
        printk(&unk_22A70, "sps_bam_pipe_connect", v12 + 24);
      }
      if ( v12 )
        ipc_log_string(
          *(_QWORD *)(v12 + 552),
          "%s: sps:BAM %pa pipe %d sharing violation\n",
          "sps_bam_pipe_connect",
          v12 + 24,
          (unsigned int)v13);
      goto LABEL_24;
    }
    if ( (unsigned __int8)logging_option >= 2u
      && (unsigned __int8)debug_level_option >= 2u
      && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_140, "sps_bam_pipe_connect")) )
    {
      printk(&unk_25A05, "sps_bam_pipe_connect", v12 + 24);
    }
    if ( v12 && *(_DWORD *)(v12 + 568) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v12 + 544),
        "%s: sps:BAM %pa pipe %d is already enabled\n",
        "sps_bam_pipe_connect",
        (const void *)(v12 + 24),
        v13);
  }
  if ( (unsigned int)bam_pipe_init((const void **)(v12 + 216), v13, (unsigned __int16 *)&v37, *(_DWORD *)(v12 + 128)) )
  {
    if ( logging_option != 1
      && ((unsigned __int8)print_limit_option < 3u
       || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_146, "sps_bam_pipe_connect")) )
    {
      printk(&unk_246C5, "sps_bam_pipe_connect", v12 + 24);
    }
    if ( v12 )
      ipc_log_string(
        *(_QWORD *)(v12 + 552),
        "%s: sps:BAM %pa pipe %d init error\n",
        "sps_bam_pipe_connect",
        (const void *)(v12 + 24),
        v13);
LABEL_125:
    if ( (*((_BYTE *)a2 + 6) & 0x80) != 0 )
    {
      if ( (unsigned __int8)logging_option >= 2u
        && (unsigned __int8)debug_level_option >= 2u
        && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_152, "sps_bam_pipe_connect")) )
      {
        printk(&unk_2470F, "sps_bam_pipe_connect", v12 + 24);
      }
      if ( v12 && *(_DWORD *)(v12 + 568) <= 2u )
        ipc_log_string(
          *(_QWORD *)(v12 + 544),
          "%s: sps:BAM %pa pipe %d connection exits\n",
          "sps_bam_pipe_connect",
          (const void *)(v12 + 24),
          v13);
    }
    else
    {
      bam_pipe_exit(v12 + 216, v13, *(_DWORD *)(v12 + 128));
    }
LABEL_62:
    pipe_clear(a1);
    goto LABEL_24;
  }
  *(_QWORD *)(v27 + 8 * v13) = a1;
  v32 = (unsigned int)a2[1];
  if ( (_DWORD)v32 )
  {
    if ( (v32 & 0x20000) != 0 )
    {
      v33 = a2 + 2;
LABEL_121:
      v34 = *v33;
      if ( v34 != -559038737 )
      {
        v35 = *(_DWORD *)(a1 + 184);
        *(_DWORD *)(a1 + 212) = v34;
        *(_DWORD *)(a1 + 184) = v35 | 0x20;
        v32 = (unsigned int)a2[1];
      }
      goto LABEL_123;
    }
LABEL_119:
    if ( (*(_BYTE *)(v12 + 160) & 0x20) != 0 )
    {
      v33 = (int *)(v12 + 136);
      goto LABEL_121;
    }
LABEL_123:
    if ( (unsigned int)sps_bam_pipe_set_params(v12, (unsigned int)v13, v32) )
    {
      *(_QWORD *)(v27 + 8 * v13) = -2290649225LL;
      goto LABEL_125;
    }
  }
  else if ( (*(_BYTE *)(a1 + 184) & 0x10) == 0 )
  {
    goto LABEL_119;
  }
  v36 = *(_DWORD *)(v12 + 248);
  *(_QWORD *)(v27 + 8 * v13) = a1;
  *(_DWORD *)(v12 + 248) = v36 | v11;
  list_add_tail_0(a1, v12 + 504);
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 2u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_pipe_connect__rs_149, "sps_bam_pipe_connect")) )
  {
    printk(&unk_250C0, "sps_bam_pipe_connect", v12 + 24);
  }
  if ( v12 && *(_DWORD *)(v12 + 568) <= 2u )
    ipc_log_string(
      *(_QWORD *)(v12 + 544),
      "%s: sps:BAM %pa; pipe %d; pipe_index_mask:0x%x; pipe_active_mask:0x%x\n",
      "sps_bam_pipe_connect",
      (const void *)(v12 + 24),
      v13,
      *(_DWORD *)(a1 + 192),
      *(_DWORD *)(v12 + 248));
  result = 0;
  *(_DWORD *)(a1 + 184) |= 2u;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
