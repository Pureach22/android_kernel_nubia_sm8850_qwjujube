__int64 __fastcall print_bam_selected_reg(__int64 result, unsigned int a2)
{
  __int64 v3; // x26
  unsigned int reg; // w27
  unsigned int v5; // w25
  unsigned int reg_field; // w23
  unsigned int v7; // w22
  unsigned int v8; // w19
  int v9; // w20
  int v10; // w0
  int v11; // w28
  unsigned int v12; // w24
  __int64 v13; // x8
  unsigned int v14; // w19
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x8
  unsigned int v25; // [xsp+Ch] [xbp-34h]
  unsigned int v26; // [xsp+10h] [xbp-30h]
  unsigned int v27; // [xsp+14h] [xbp-2Ch]
  unsigned int v28; // [xsp+18h] [xbp-28h]
  unsigned int v29; // [xsp+1Ch] [xbp-24h]
  unsigned int v30; // [xsp+20h] [xbp-20h]
  int v31; // [xsp+24h] [xbp-1Ch]
  unsigned int v32; // [xsp+28h] [xbp-18h]
  int v33; // [xsp+2Ch] [xbp-14h]
  unsigned int v34; // [xsp+30h] [xbp-10h]
  unsigned int v35; // [xsp+34h] [xbp-Ch]
  unsigned int v36; // [xsp+38h] [xbp-8h]
  int v37; // [xsp+3Ch] [xbp-4h]

  if ( !result )
    return result;
  v3 = result;
  reg = bam_read_reg(result, 0);
  v5 = bam_read_reg(v3, 1u);
  reg_field = bam_read_reg_field(v3, 1u, 0, 0xFFu);
  v7 = bam_read_reg_field(v3, 1u, 0, 0xF00u);
  v8 = bam_read_reg(v3, 3u);
  v29 = bam_read_reg_field(v3, 3u, 0, 0xFFu);
  v9 = bam_read_reg_field(v3, 3u, 0, 0xC000u);
  v28 = bam_read_reg(v3, 6u);
  v27 = bam_read_reg_field(v3, 6u, 0, 0xFFFFu);
  v26 = bam_read_reg(v3, 0xCu);
  v25 = bam_read_reg(v3, 0xAu);
  v10 = 0;
  v11 = 0;
  v37 = 0;
  if ( a2 <= 7 )
  {
    v11 = bam_read_reg(v3, 0x18u);
    v37 = bam_read_reg(v3, 0x19u);
    v10 = bam_read_reg(v3, 0x1Au);
  }
  v33 = v10;
  v36 = bam_read_reg(v3, 0xEu);
  v35 = bam_read_reg(v3, 0xFu);
  v32 = bam_read_reg(v3, 0x11u);
  v30 = bam_read_reg(v3, 0x17u);
  v12 = bam_read_reg(v3, 2u);
  v34 = bam_read_reg(v3, 0x10u);
  result = 0;
  if ( a2 <= 7 )
  {
    if ( enhd_pipe == 1 )
      result = bam_read_reg(v3, 0x1Bu);
    else
      result = 0;
  }
  v31 = result;
  v13 = sps;
  if ( sps )
  {
    result = ipc_log_string(
               *(_QWORD *)(sps + 280),
               "%s: %s",
               "print_bam_selected_reg",
               "\nsps:<bam-begin> --- BAM-level registers ---\n\n");
    v13 = sps;
    if ( sps )
    {
      if ( *(_QWORD *)(sps + 280)
        || (result = printk(&unk_2919C, "print_bam_selected_reg", "\nsps:<bam-begin> --- BAM-level registers ---\n\n"),
            (v13 = sps) != 0) )
      {
        result = ipc_log_string(*(_QWORD *)(v13 + 280), "%s: BAM_CTRL: 0x%x\n", "print_bam_selected_reg", reg);
        v13 = sps;
        if ( sps )
        {
          if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_27646, "print_bam_selected_reg", reg), (v13 = sps) != 0) )
          {
            result = ipc_log_string(*(_QWORD *)(v13 + 280), "%s: BAM_REVISION: 0x%x\n", "print_bam_selected_reg", v5);
            v13 = sps;
            if ( sps )
            {
              if ( *(_QWORD *)(sps + 280)
                || (result = printk(&unk_2531C, "print_bam_selected_reg", v5), (v13 = sps) != 0) )
              {
                result = ipc_log_string(
                           *(_QWORD *)(v13 + 280),
                           "%s:     REVISION: 0x%x\n",
                           "print_bam_selected_reg",
                           reg_field);
                v13 = sps;
                if ( sps )
                {
                  if ( *(_QWORD *)(sps + 280)
                    || (result = printk(&unk_26933, "print_bam_selected_reg", reg_field), (v13 = sps) != 0) )
                  {
                    result = ipc_log_string(
                               *(_QWORD *)(v13 + 280),
                               "%s:     NUM_EES: %d\n",
                               "print_bam_selected_reg",
                               v7);
                    v13 = sps;
                    if ( sps )
                    {
                      if ( *(_QWORD *)(sps + 280)
                        || (result = printk(&unk_2451F, "print_bam_selected_reg", v7), (v13 = sps) != 0) )
                      {
                        result = ipc_log_string(
                                   *(_QWORD *)(v13 + 280),
                                   "%s: BAM_SW_REVISION: 0x%x\n",
                                   "print_bam_selected_reg",
                                   v12);
                        v13 = sps;
                        if ( sps )
                        {
                          if ( *(_QWORD *)(sps + 280)
                            || (result = printk(&unk_2984F, "print_bam_selected_reg", v12), (v13 = sps) != 0) )
                          {
                            result = ipc_log_string(
                                       *(_QWORD *)(v13 + 280),
                                       "%s: BAM_NUM_PIPES: %d\n",
                                       "print_bam_selected_reg",
                                       v8);
                            v13 = sps;
                            if ( sps )
                            {
                              if ( *(_QWORD *)(sps + 280)
                                || (result = printk(&unk_25336, "print_bam_selected_reg", v8), (v13 = sps) != 0) )
                              {
                                v14 = v9 ? 36 : 32;
                                result = ipc_log_string(
                                           *(_QWORD *)(v13 + 280),
                                           "%s: BAM_DATA_ADDR_BUS_WIDTH: %d\n",
                                           "print_bam_selected_reg",
                                           v14);
                                v13 = sps;
                                if ( sps )
                                {
                                  if ( *(_QWORD *)(sps + 280)
                                    || (result = printk(&unk_28793, "print_bam_selected_reg", v14), (v13 = sps) != 0) )
                                  {
                                    result = ipc_log_string(
                                               *(_QWORD *)(v13 + 280),
                                               "%s:     NUM_PIPES: %d\n",
                                               "print_bam_selected_reg",
                                               v29);
                                    v13 = sps;
                                    if ( sps )
                                    {
                                      if ( *(_QWORD *)(sps + 280)
                                        || (result = printk(&unk_2986C, "print_bam_selected_reg", v29), (v13 = sps) != 0) )
                                      {
                                        result = ipc_log_string(
                                                   *(_QWORD *)(v13 + 280),
                                                   "%s: BAM_DESC_CNT_TRSHLD: 0x%x\n",
                                                   "print_bam_selected_reg",
                                                   v28);
                                        v13 = sps;
                                        if ( sps )
                                        {
                                          if ( *(_QWORD *)(sps + 280)
                                            || (result = printk(&unk_260F4, "print_bam_selected_reg", v28),
                                                (v13 = sps) != 0) )
                                          {
                                            result = ipc_log_string(
                                                       *(_QWORD *)(v13 + 280),
                                                       "%s:     DESC_CNT_TRSHLD: 0x%x (%d)\n",
                                                       "print_bam_selected_reg",
                                                       v27,
                                                       v27);
                                            v13 = sps;
                                            if ( sps )
                                            {
                                              if ( *(_QWORD *)(sps + 280)
                                                || (result = printk(&unk_291DC, "print_bam_selected_reg", v27),
                                                    (v13 = sps) != 0) )
                                              {
                                                result = ipc_log_string(
                                                           *(_QWORD *)(v13 + 280),
                                                           "%s: BAM_IRQ_EN: 0x%x\n",
                                                           "print_bam_selected_reg",
                                                           v26);
                                                v13 = sps;
                                                if ( sps )
                                                {
                                                  if ( *(_QWORD *)(sps + 280)
                                                    || (result = printk(&unk_25C4C, "print_bam_selected_reg", v26),
                                                        (v13 = sps) != 0) )
                                                  {
                                                    result = ipc_log_string(
                                                               *(_QWORD *)(v13 + 280),
                                                               "%s: BAM_IRQ_STTS: 0x%x\n",
                                                               "print_bam_selected_reg",
                                                               v25);
                                                    v13 = sps;
                                                    if ( sps )
                                                    {
                                                      if ( !*(_QWORD *)(sps + 280) )
                                                      {
                                                        result = printk(&unk_2534F, "print_bam_selected_reg", v25);
                                                        v13 = sps;
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
          }
        }
      }
    }
  }
  if ( a2 > 7 )
    goto LABEL_73;
  if ( !v13 )
    return result;
  result = ipc_log_string(*(_QWORD *)(v13 + 280), "%s: BAM_IRQ_SRCS_EE(%d): 0x%x\n", "print_bam_selected_reg", a2, v11);
  v15 = sps;
  if ( !sps )
    return result;
  if ( !*(_QWORD *)(sps + 280) )
  {
    result = printk(&unk_2765C, "print_bam_selected_reg", a2);
    v15 = sps;
    if ( !sps )
      return result;
  }
  result = ipc_log_string(
             *(_QWORD *)(v15 + 280),
             "%s: BAM_IRQ_SRCS_MSK_EE(%d): 0x%x\n",
             "print_bam_selected_reg",
             a2,
             v37);
  v16 = sps;
  if ( !sps )
    return result;
  if ( !*(_QWORD *)(sps + 280) )
  {
    result = printk(&unk_22C3F, "print_bam_selected_reg", a2);
    v16 = sps;
    if ( !sps )
      return result;
  }
  result = ipc_log_string(
             *(_QWORD *)(v16 + 280),
             "%s: BAM_IRQ_SRCS_UNMASKED_EE(%d): 0x%x\n",
             "print_bam_selected_reg",
             a2,
             v33);
  v17 = sps;
  if ( !sps )
    return result;
  if ( !*(_QWORD *)(sps + 280) )
  {
    result = printk(&unk_24074, "print_bam_selected_reg", a2);
    v17 = sps;
    if ( !sps )
      return result;
  }
  result = ipc_log_string(*(_QWORD *)(v17 + 280), "%s: BAM_PIPE_ATTR_EE(%d): 0x%x\n", "print_bam_selected_reg", a2, v31);
  v13 = sps;
  if ( !sps )
    return result;
  if ( !*(_QWORD *)(sps + 280) )
  {
    result = printk(&unk_29CDB, "print_bam_selected_reg", a2);
    v13 = sps;
LABEL_73:
    if ( !v13 )
      return result;
  }
  result = ipc_log_string(*(_QWORD *)(v13 + 280), "%s: BAM_AHB_MASTER_ERR_CTRLS: 0x%x\n", "print_bam_selected_reg", v36);
  v18 = sps;
  if ( sps )
  {
    if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_24536, "print_bam_selected_reg", v36), (v18 = sps) != 0) )
    {
      result = ipc_log_string(
                 *(_QWORD *)(v18 + 280),
                 "%s: BAM_AHB_MASTER_ERR_ADDR: 0x%x\n",
                 "print_bam_selected_reg",
                 v35);
      v19 = sps;
      if ( sps )
      {
        if ( *(_QWORD *)(sps + 280) || (result = printk(&unk_24E04, "print_bam_selected_reg", v35), (v19 = sps) != 0) )
        {
          result = ipc_log_string(
                     *(_QWORD *)(v19 + 280),
                     "%s: BAM_AHB_MASTER_ERR_ADDR_MSB: 0x%x\n",
                     "print_bam_selected_reg",
                     v34);
          v20 = sps;
          if ( sps )
          {
            if ( *(_QWORD *)(sps + 280)
              || (result = printk(&unk_23C16, "print_bam_selected_reg", v34), (v20 = sps) != 0) )
            {
              result = ipc_log_string(
                         *(_QWORD *)(v20 + 280),
                         "%s: BAM_AHB_MASTER_ERR_DATA: 0x%x\n",
                         "print_bam_selected_reg",
                         v32);
              v21 = sps;
              if ( sps )
              {
                if ( *(_QWORD *)(sps + 280)
                  || (result = printk(&unk_287ED, "print_bam_selected_reg", v32), (v21 = sps) != 0) )
                {
                  result = ipc_log_string(
                             *(_QWORD *)(v21 + 280),
                             "%s: BAM_CNFG_BITS: 0x%x\n",
                             "print_bam_selected_reg",
                             v30);
                  v22 = sps;
                  if ( sps )
                  {
                    if ( *(_QWORD *)(sps + 280)
                      || (result = printk(&unk_24909, "print_bam_selected_reg", v30), (v22 = sps) != 0) )
                    {
                      result = ipc_log_string(
                                 *(_QWORD *)(v22 + 280),
                                 "%s: BAM_TIMER: 0x%x\n",
                                 "print_bam_selected_reg",
                                 0);
                      v23 = sps;
                      if ( sps )
                      {
                        if ( *(_QWORD *)(sps + 280)
                          || (result = printk(&unk_22C64, "print_bam_selected_reg", 0), (v23 = sps) != 0) )
                        {
                          result = ipc_log_string(
                                     *(_QWORD *)(v23 + 280),
                                     "%s: BAM_TIMER_CTRL: 0x%x\n",
                                     "print_bam_selected_reg",
                                     0);
                          v24 = sps;
                          if ( sps )
                          {
                            if ( *(_QWORD *)(sps + 280)
                              || (result = printk(&unk_24924, "print_bam_selected_reg", 0), (v24 = sps) != 0) )
                            {
                              result = ipc_log_string(
                                         *(_QWORD *)(v24 + 280),
                                         "%s: %s",
                                         "print_bam_selected_reg",
                                         "\nsps:<bam-end> --- BAM-level registers ---\n\n");
                              if ( sps )
                              {
                                if ( !*(_QWORD *)(sps + 280) )
                                  return printk(
                                           &unk_2919C,
                                           "print_bam_selected_reg",
                                           "\nsps:<bam-end> --- BAM-level registers ---\n\n");
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
        }
      }
    }
  }
  return result;
}
