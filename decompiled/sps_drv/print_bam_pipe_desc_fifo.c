__int64 __fastcall print_bam_pipe_desc_fifo(__int64 result, unsigned int a2, int a3)
{
  __int64 v4; // x23
  unsigned int reg; // w20
  unsigned int v6; // w21
  __int64 v7; // x8
  unsigned __int64 v8; // x26
  int v9; // w22
  __int64 v10; // x28
  __int64 v11; // x27
  __int64 v12; // x8
  unsigned int *v13; // x28
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  const char *v17; // x2
  __int64 v18; // x8
  int v19; // w27
  __int64 v20; // x9
  unsigned int v21; // w8
  unsigned int v22; // w25
  unsigned int v23; // w28
  __int64 v24; // x8
  _DWORD *v25; // x8
  int v26; // w23
  unsigned int v27; // w27
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v31; // [xsp+8h] [xbp-58h] BYREF
  __int64 v32; // [xsp+10h] [xbp-50h]
  __int64 v33; // [xsp+18h] [xbp-48h]
  __int64 v34; // [xsp+20h] [xbp-40h]
  __int64 v35; // [xsp+28h] [xbp-38h]
  __int64 v36; // [xsp+30h] [xbp-30h]
  __int64 v37; // [xsp+38h] [xbp-28h]
  __int64 v38; // [xsp+40h] [xbp-20h]
  __int64 v39; // [xsp+48h] [xbp-18h]
  __int64 v40; // [xsp+50h] [xbp-10h]
  __int64 v41; // [xsp+58h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_49;
  v4 = result;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  reg = bam_read_reg(result, 0x2Cu);
  result = bam_read_reg_field(v4, 0x2Fu, a2, 0xFFFFu);
  if ( !reg )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (result = __ratelimit(&print_bam_pipe_desc_fifo__rs, "print_bam_pipe_desc_fifo"), (_DWORD)result) )
      {
        result = printk(&unk_22818, "print_bam_pipe_desc_fifo", a2);
      }
    }
    if ( sps )
      result = ipc_log_string(
                 *(_QWORD *)(sps + 272),
                 "%s: sps: desc FIFO address of Pipe %d is NULL\n",
                 "print_bam_pipe_desc_fifo",
                 a2);
    goto LABEL_49;
  }
  v6 = result;
  if ( !(_DWORD)result )
  {
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u
        || (result = __ratelimit(&print_bam_pipe_desc_fifo__rs_252, "print_bam_pipe_desc_fifo"), (_DWORD)result) )
      {
        result = printk(&unk_28C2F, "print_bam_pipe_desc_fifo", a2);
      }
    }
    if ( sps )
      result = ipc_log_string(
                 *(_QWORD *)(sps + 272),
                 "%s: sps: desc FIFO size of Pipe %d is 0\n",
                 "print_bam_pipe_desc_fifo",
                 a2);
    goto LABEL_49;
  }
  if ( sps )
  {
    result = ipc_log_string(
               *(_QWORD *)(sps + 280),
               "%s: \nsps:<desc-begin> --- descriptor FIFO of Pipe %d -----\n\n",
               "print_bam_pipe_desc_fifo",
               a2);
    v7 = sps;
    if ( sps )
    {
      if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_2A970, "print_bam_pipe_desc_fifo", a2), (v7 = sps) != 0) )
      {
        result = ipc_log_string(
                   *(_QWORD *)(v7 + 280),
                   "%s: BAM_P_DESC_FIFO_ADDR: 0x%x\nBAM_P_DESC_FIFO_SIZE: 0x%x (%d)\n\n",
                   "print_bam_pipe_desc_fifo",
                   reg,
                   v6,
                   v6);
        if ( sps )
        {
          if ( !*(_QWORD *)(sps + 280) )
            result = printk(&unk_2AD5D, "print_bam_pipe_desc_fifo", reg);
        }
      }
    }
  }
  v8 = (reg - memstart_addr) | 0xFFFFFF8000000000LL;
  if ( a3 )
  {
    if ( a3 == 100 )
    {
      if ( sps )
      {
        result = ipc_log_string(
                   *(_QWORD *)(sps + 280),
                   "%s: %s",
                   "print_bam_pipe_desc_fifo",
                   "----- start of data blocks -----\n");
        if ( sps )
        {
          if ( !*(_QWORD *)(sps + 280) )
            result = printk(&unk_2919C, "print_bam_pipe_desc_fifo", "----- start of data blocks -----\n");
        }
      }
      v9 = 0;
      do
      {
        v10 = *(unsigned int *)(v8 + 4LL * (v9 >> 2));
        if ( (_DWORD)v10 )
        {
          if ( sps )
          {
            v11 = memstart_addr;
            result = ipc_log_string(
                       *(_QWORD *)(sps + 280),
                       "%s: desc addr:0x%x; data addr:0x%x:\n",
                       "print_bam_pipe_desc_fifo",
                       reg + v9,
                       v10);
            v12 = sps;
            if ( sps )
            {
              if ( *(_QWORD *)(sps + 280)
                || (result = printk(&unk_28C5A, "print_bam_pipe_desc_fifo", reg + v9), (v12 = sps) != 0) )
              {
                v13 = (unsigned int *)((v10 - v11) | 0xFFFFFF8000000000LL);
                result = ipc_log_string(
                           *(_QWORD *)(v12 + 280),
                           "%s: 0x%x, 0x%x, 0x%x, 0x%x\n",
                           "print_bam_pipe_desc_fifo",
                           *v13,
                           v13[1],
                           v13[2],
                           v13[3]);
                v14 = sps;
                if ( sps )
                {
                  if ( *(_QWORD *)(sps + 280)
                    || (result = printk(&unk_269B0, "print_bam_pipe_desc_fifo", *v13), (v14 = sps) != 0) )
                  {
                    result = ipc_log_string(
                               *(_QWORD *)(v14 + 280),
                               "%s: 0x%x, 0x%x, 0x%x, 0x%x\n",
                               "print_bam_pipe_desc_fifo",
                               v13[4],
                               v13[5],
                               v13[6],
                               v13[7]);
                    v15 = sps;
                    if ( sps )
                    {
                      if ( *(_QWORD *)(sps + 280)
                        || (result = printk(&unk_269B0, "print_bam_pipe_desc_fifo", v13[4]), (v15 = sps) != 0) )
                      {
                        result = ipc_log_string(
                                   *(_QWORD *)(v15 + 280),
                                   "%s: 0x%x, 0x%x, 0x%x, 0x%x\n",
                                   "print_bam_pipe_desc_fifo",
                                   v13[8],
                                   v13[9],
                                   v13[10],
                                   v13[11]);
                        v16 = sps;
                        if ( sps )
                        {
                          if ( *(_QWORD *)(sps + 280)
                            || (result = printk(&unk_269B0, "print_bam_pipe_desc_fifo", v13[8]), (v16 = sps) != 0) )
                          {
                            result = ipc_log_string(
                                       *(_QWORD *)(v16 + 280),
                                       "%s: 0x%x, 0x%x, 0x%x, 0x%x\n\n",
                                       "print_bam_pipe_desc_fifo",
                                       v13[12],
                                       v13[13],
                                       v13[14],
                                       v13[15]);
                            if ( sps )
                            {
                              if ( !*(_QWORD *)(sps + 280) )
                                result = printk(&unk_22849, "print_bam_pipe_desc_fifo", v13[12]);
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        v9 += 8;
      }
      while ( v9 < v6 );
      if ( !sps )
        goto LABEL_49;
      result = ipc_log_string(
                 *(_QWORD *)(sps + 280),
                 "%s: %s",
                 "print_bam_pipe_desc_fifo",
                 "----- end of data blocks -----\n");
      if ( !sps )
        goto LABEL_49;
      if ( *(_QWORD *)(sps + 280) )
        goto LABEL_117;
      v17 = "----- end of data blocks -----\n";
      goto LABEL_126;
    }
    result = bam_read_reg_field(v4, 0x29u, a2, 0xFFFFu);
    v21 = (a3 & 0x1FFFFFF) << 6;
    if ( (unsigned int)result >= v21 )
      v22 = result - v21;
    else
      v22 = 0;
    if ( v6 >= (unsigned int)result + v21 )
      v23 = result + v21;
    else
      v23 = v6;
    if ( sps )
    {
      result = ipc_log_string(
                 *(_QWORD *)(sps + 280),
                 "%s: %s",
                 "print_bam_pipe_desc_fifo",
                 "------------ begin of partial FIFO ------------\n\n");
      v24 = sps;
      if ( sps )
      {
        if ( *(_QWORD *)(sps + 280)
          || (result = printk(
                         &unk_2919C,
                         "print_bam_pipe_desc_fifo",
                         "------------ begin of partial FIFO ------------\n\n"),
              (v24 = sps) != 0) )
        {
          result = ipc_log_string(
                     *(_QWORD *)(v24 + 280),
                     "%s: %s",
                     "print_bam_pipe_desc_fifo",
                     "desc addr; desc content; desc flags\n");
          if ( sps )
          {
            if ( !*(_QWORD *)(sps + 280) )
              result = printk(&unk_2919C, "print_bam_pipe_desc_fifo", "desc addr; desc content; desc flags\n");
          }
        }
      }
    }
    if ( v22 >= v23 )
    {
LABEL_110:
      if ( !sps )
        goto LABEL_49;
      result = ipc_log_string(
                 *(_QWORD *)(sps + 280),
                 "%s: %s",
                 "print_bam_pipe_desc_fifo",
                 "\n------------  end of partial FIFO  ------------\n");
      if ( !sps )
        goto LABEL_49;
      if ( *(_QWORD *)(sps + 280) )
        goto LABEL_117;
      v17 = "\n------------  end of partial FIFO  ------------\n";
      goto LABEL_126;
    }
    while ( 1 )
    {
      v25 = (_DWORD *)(v8 + 4LL * ((int)v22 / 4));
      v26 = v25[1];
      v39 = 0;
      v40 = 0;
      v37 = 0;
      v38 = 0;
      v35 = 0;
      v36 = 0;
      v33 = 0;
      v34 = 0;
      v31 = 0;
      v32 = 0;
      result = scnprintf(&v31, 40, "0x%x: 0x%x, 0x%x: ", reg + v22, *v25, v25[1]);
      v27 = result;
      if ( v26 < 0 )
      {
        if ( (unsigned int)result >= 0x51 )
          goto LABEL_132;
        result = scnprintf((char *)&v31 + (unsigned int)result, 5, "INT ");
        v27 += result;
        if ( (v26 & 0x40000000) == 0 )
        {
LABEL_83:
          if ( (v26 & 0x20000000) == 0 )
            goto LABEL_84;
          goto LABEL_95;
        }
      }
      else if ( (v26 & 0x40000000) == 0 )
      {
        goto LABEL_83;
      }
      if ( v27 > 0x50 )
        goto LABEL_132;
      result = scnprintf((char *)&v31 + v27, 5, "EOT ");
      v27 += result;
      if ( (v26 & 0x20000000) == 0 )
      {
LABEL_84:
        if ( (v26 & 0x10000000) == 0 )
          goto LABEL_85;
        goto LABEL_97;
      }
LABEL_95:
      if ( v27 > 0x50 )
        goto LABEL_132;
      result = scnprintf((char *)&v31 + v27, 5, "EOB ");
      v27 += result;
      if ( (v26 & 0x10000000) == 0 )
      {
LABEL_85:
        if ( (v26 & 0x8000000) == 0 )
          goto LABEL_86;
        goto LABEL_99;
      }
LABEL_97:
      if ( v27 > 0x50 )
        goto LABEL_132;
      result = scnprintf((char *)&v31 + v27, 5, "NWD ");
      v27 += result;
      if ( (v26 & 0x8000000) == 0 )
      {
LABEL_86:
        if ( (v26 & 0x4000000) == 0 )
          goto LABEL_87;
        goto LABEL_101;
      }
LABEL_99:
      if ( v27 > 0x50 )
        goto LABEL_132;
      result = scnprintf((char *)&v31 + v27, 5, "CMD ");
      v27 += result;
      if ( (v26 & 0x4000000) == 0 )
      {
LABEL_87:
        if ( (v26 & 0x2000000) == 0 )
          goto LABEL_88;
        goto LABEL_103;
      }
LABEL_101:
      if ( v27 > 0x50 )
        goto LABEL_132;
      result = scnprintf((char *)&v31 + v27, 5, "LCK ");
      v27 += result;
      if ( (v26 & 0x2000000) == 0 )
      {
LABEL_88:
        if ( (v26 & 0x1000000) == 0 )
          goto LABEL_89;
        goto LABEL_105;
      }
LABEL_103:
      if ( v27 > 0x50 )
        goto LABEL_132;
      result = scnprintf((char *)&v31 + v27, 5, "UNL ");
      v27 += result;
      if ( (v26 & 0x1000000) == 0 )
      {
LABEL_89:
        v28 = sps;
        if ( sps )
          goto LABEL_107;
        goto LABEL_80;
      }
LABEL_105:
      if ( v27 > 0x50 )
LABEL_132:
        __break(0x5512u);
      result = scnprintf((char *)&v31 + v27, 5, "IMM ");
      v28 = sps;
      if ( sps )
      {
LABEL_107:
        result = ipc_log_string(*(_QWORD *)(v28 + 280), "%s: %s\n", "print_bam_pipe_desc_fifo", (const char *)&v31);
        if ( sps && !*(_QWORD *)(sps + 280) )
          result = printk(&unk_269D3, "print_bam_pipe_desc_fifo", &v31);
      }
LABEL_80:
      v22 += 8;
      if ( v22 >= v23 )
        goto LABEL_110;
    }
  }
  v18 = sps;
  if ( sps )
  {
    result = ipc_log_string(
               *(_QWORD *)(sps + 280),
               "%s: %s",
               "print_bam_pipe_desc_fifo",
               "---------------- begin of FIFO ----------------\n\n");
    v18 = sps;
    if ( sps )
    {
      if ( !*(_QWORD *)(sps + 280) )
      {
        result = printk(&unk_2919C, "print_bam_pipe_desc_fifo", "---------------- begin of FIFO ----------------\n\n");
        v18 = sps;
      }
    }
  }
  v19 = 0;
  v20 = v18;
  do
  {
    while ( 1 )
    {
      if ( !v20 )
        goto LABEL_61;
      result = ipc_log_string(
                 *(_QWORD *)(v20 + 280),
                 "%s: addr 0x%x: 0x%x, 0x%x, 0x%x, 0x%x\n",
                 "print_bam_pipe_desc_fifo",
                 v19 + reg,
                 *(_DWORD *)(v8 + 4LL * (v19 >> 2)),
                 *(_DWORD *)(v8 + 4 * (((__int64)v19 >> 2) | 1)),
                 *(_DWORD *)(v8 + 4 * (((__int64)v19 >> 2) | 2)),
                 *(_DWORD *)(v8 + 4 * (((__int64)v19 >> 2) | 3)));
      v18 = sps;
      if ( sps )
        break;
      v19 += 16;
      v20 = 0;
      if ( v19 >= v6 )
        goto LABEL_49;
    }
    v20 = sps;
    if ( !*(_QWORD *)(sps + 280) )
    {
      result = printk(&unk_29947, "print_bam_pipe_desc_fifo", v19 + reg);
      v18 = sps;
      v20 = sps;
    }
LABEL_61:
    v19 += 16;
  }
  while ( v19 < v6 );
  if ( !v18 )
    goto LABEL_49;
  result = ipc_log_string(
             *(_QWORD *)(v18 + 280),
             "%s: %s",
             "print_bam_pipe_desc_fifo",
             "\n----------------  end of FIFO  ----------------\n");
  if ( !sps )
    goto LABEL_49;
  if ( *(_QWORD *)(sps + 280) )
  {
LABEL_117:
    v29 = sps;
    if ( sps )
      goto LABEL_118;
    goto LABEL_49;
  }
  v17 = "\n----------------  end of FIFO  ----------------\n";
LABEL_126:
  result = printk(&unk_2919C, "print_bam_pipe_desc_fifo", v17);
  v29 = sps;
  if ( sps )
  {
LABEL_118:
    result = ipc_log_string(
               *(_QWORD *)(v29 + 280),
               "%s: \nsps:<desc-end> --- descriptor FIFO of Pipe %d -----\n\n",
               "print_bam_pipe_desc_fifo",
               a2);
    if ( sps && !*(_QWORD *)(sps + 280) )
      result = printk(&unk_2A086, "print_bam_pipe_desc_fifo", a2);
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
