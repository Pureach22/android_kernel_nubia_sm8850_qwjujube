__int64 __fastcall sps_bam_check_irq(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x1
  int v6; // w27
  unsigned int v7; // w1
  int v8; // w23
  __int64 v9; // x1
  void (__fastcall *v10)(__int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x1
  void (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x0
  __int64 *v15; // x23
  unsigned int v16; // w25
  int v17; // w24
  int v18; // w28
  int v19; // w8
  __int64 *v20; // x9
  __int64 v21; // x10
  unsigned int v22; // w24
  __int64 v23; // x2
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x8
  int v30; // w25
  unsigned int v31; // w1
  int v32; // w23
  __int64 result; // x0
  __int64 v34; // x1
  __int64 v35; // [xsp+8h] [xbp-18h]
  unsigned int v36; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+18h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned __int8)logging_option >= 2u
    && (unsigned __int8)debug_level_option >= 3u
    && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_check_irq__rs, "sps_bam_check_irq")) )
  {
    printk(&unk_28F1A, "sps_bam_check_irq", a1 + 24);
  }
  if ( a1 && *(_DWORD *)(a1 + 568) <= 1u )
    ipc_log_string(*(_QWORD *)(a1 + 536), "%s: sps: bam=%pa\n", "sps_bam_check_irq", (const void *)(a1 + 24));
  v2 = raw_spin_lock_irqsave(a1 + 228);
  v3 = v2;
  if ( (*(_BYTE *)(a1 + 824) & 1) == 0 )
  {
    v35 = v2;
    while ( 1 )
    {
      v6 = *(_DWORD *)(a1 + 248);
      if ( (*(_BYTE *)(a1 + 160) & 0x20) != 0 )
      {
        if ( (unsigned __int8)logging_option >= 2u
          && (unsigned __int8)debug_level_option >= 3u
          && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_check_irq__rs_16, "sps_bam_check_irq")) )
        {
          printk(&unk_2AB43, "sps_bam_check_irq", a1 + 24);
        }
        if ( a1 && *(_DWORD *)(a1 + 568) <= 1u )
          ipc_log_string(
            *(_QWORD *)(a1 + 536),
            "%s: sps:MTI:bam=%pa;source=0x%x\n",
            "sps_bam_check_irq",
            (const void *)(a1 + 24),
            v6);
      }
      else
      {
        v7 = *(_DWORD *)(a1 + 128);
        v36 = 0;
        v8 = bam_check_irq_source((const void **)(a1 + 216), v7, v6, (int *)&v36);
        if ( (unsigned __int8)logging_option >= 2u
          && (unsigned __int8)debug_level_option >= 3u
          && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_check_irq__rs_7, "sps_bam_check_irq")) )
        {
          printk(&unk_23DF9, "sps_bam_check_irq", a1 + 24);
        }
        if ( a1 && *(_DWORD *)(a1 + 568) <= 1u )
          ipc_log_string(
            *(_QWORD *)(a1 + 536),
            "%s: sps:bam=%pa;source=0x%x;mask=0x%x\n",
            "sps_bam_check_irq",
            (const void *)(a1 + 24),
            v8,
            v6);
        if ( v8 )
        {
          if ( v8 < 0 && *(_QWORD *)(a1 + 104) )
          {
            if ( (unsigned __int8)logging_option >= 2u
              && (unsigned __int8)debug_level_option >= 3u
              && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_check_irq__rs_13, "sps_bam_check_irq")) )
            {
              printk(&unk_234E3, "sps_bam_check_irq", a1 + 24);
            }
            if ( a1 && *(_DWORD *)(a1 + 568) <= 1u )
              ipc_log_string(
                *(_QWORD *)(a1 + 536),
                "%s: sps:bam=%pa;callback for case %d\n",
                "sps_bam_check_irq",
                (const void *)(a1 + 24),
                v36);
            v10 = *(void (__fastcall **)(__int64, __int64))(a1 + 104);
            v9 = *(_QWORD *)(a1 + 112);
            v11 = v36;
            if ( *((_DWORD *)v10 - 1) != -835259500 )
              __break(0x8228u);
            v10(v11, v9);
          }
        }
        else if ( (*(_BYTE *)(a1 + 16) & 0x80) != 0 )
        {
          if ( (unsigned __int8)logging_option >= 2u
            && (unsigned __int8)debug_level_option >= 2u
            && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_check_irq__rs_10, "sps_bam_check_irq")) )
          {
            printk(&unk_2A694, "sps_bam_check_irq", a1 + 24);
          }
          v34 = v35;
          if ( a1 && *(_DWORD *)(a1 + 568) <= 2u )
          {
            ipc_log_string(
              *(_QWORD *)(a1 + 544),
              "%s: sps: BAM %pa has no source (source = 0x%x)\n",
              "sps_bam_check_irq",
              (const void *)(a1 + 24),
              0);
            v34 = v35;
          }
          raw_spin_unlock_irqrestore(a1 + 228, v34);
          result = 0xFFFFFFFFLL;
          goto LABEL_150;
        }
        v6 = *(_DWORD *)(a1 + 248) & v8;
      }
      v15 = (__int64 *)(a1 + 504);
      while ( 1 )
      {
        v15 = (__int64 *)*v15;
        if ( v15 == (__int64 *)(a1 + 504) )
          break;
        if ( v15 != (__int64 *)-2290649225LL && v15 && (v15[80] & 1) == 0 && ((_DWORD)v15[24] & v6) != 0 )
        {
          v16 = *((_DWORD *)v15 + 47);
          v17 = bam_pipe_get_and_clear_irq_status(a1 + 216, v16);
          if ( (unsigned __int8)logging_option >= 2u
            && (unsigned __int8)debug_level_option >= 4u
            && (!print_limit_option || (unsigned int)__ratelimit(&pipe_handler__rs, "pipe_handler")) )
          {
            printk(&unk_29BA7, "pipe_handler", a1 + 24);
          }
          if ( a1 && !*(_DWORD *)(a1 + 568) )
            ipc_log_string(
              *(_QWORD *)(a1 + 528),
              "%s: sps: bam %pa.pipe %d.status=0x%x\n",
              "pipe_handler",
              (const void *)(a1 + 24),
              v16,
              v17);
          v18 = *((_DWORD *)v15 + 49) & v17;
          if ( v18 )
          {
            if ( (v18 & 0x21) == 0 || (v15[23] & 0x10) != 0 )
              goto LABEL_170;
            pipe_handler_eot(a1, v15);
            if ( *((_DWORD *)v15 + 156) )
            {
              v15[75] = 0;
              if ( (v18 & 0x20) != 0 )
                v19 = 1;
              else
                v19 = 2;
              v15[77] = 0;
              v15[76] = 0;
              v20 = &v15[4 * (unsigned int)(v19 - 1)];
              v15[74] = 0;
              v15[73] = 0;
              v21 = v20[37];
              v15[72] = 0;
              *((_DWORD *)v15 + 150) = v19;
              v15[74] = v21;
              trigger_event(a1, v20 + 34, v15 + 72);
            }
            v18 &= 0xFFFFFFDE;
            if ( v18 )
            {
LABEL_170:
              if ( (v18 & 4) == 0 )
                goto LABEL_171;
              if ( *((_DWORD *)v15 + 57) )
              {
                v22 = *((_DWORD *)v15 + 47);
                if ( (unsigned __int8)logging_option >= 2u
                  && (unsigned __int8)debug_level_option >= 2u
                  && (!print_limit_option || (unsigned int)__ratelimit(&pipe_handler_wakeup__rs, "pipe_handler_wakeup")) )
                {
                  printk(&unk_24431, "pipe_handler_wakeup", a1 + 24);
                }
                if ( a1 && *(_DWORD *)(a1 + 568) <= 2u )
                  ipc_log_string(
                    *(_QWORD *)(a1 + 544),
                    "%s: sps:BAM:%pa pipe %d wake_up_is_one_shot; irq_mask:0x%x\n",
                    "pipe_handler_wakeup",
                    (const void *)(a1 + 24),
                    v22,
                    *((_DWORD *)v15 + 49));
                v23 = *((unsigned int *)v15 + 50);
                *((_DWORD *)v15 + 49) &= ~4u;
                pipe_set_irq(a1, v22, v23);
              }
              v24 = v15[49];
              v15[75] = 0;
              v15[77] = 0;
              v15[76] = 0;
              v15[73] = 0;
              v15[72] = 0;
              *((_DWORD *)v15 + 150) = 4;
              v15[74] = v24;
              trigger_event(a1, v15 + 46, v15 + 72);
              v18 &= ~4u;
              if ( v18 )
              {
LABEL_171:
                if ( (v18 & 2) == 0 )
                  goto LABEL_173;
                v25 = v15[57];
                v15[75] = 0;
                v15[77] = 0;
                v15[76] = 0;
                v15[73] = 0;
                v15[72] = 0;
                *((_DWORD *)v15 + 150) = 6;
                v15[74] = v25;
                trigger_event(a1, v15 + 54, v15 + 72);
                v18 &= ~2u;
                if ( v18 )
                {
LABEL_173:
                  if ( (v18 & 8) == 0 )
                    goto LABEL_78;
                  v26 = v15[45];
                  v15[75] = 0;
                  v15[77] = 0;
                  v15[76] = 0;
                  v15[73] = 0;
                  v15[72] = 0;
                  *((_DWORD *)v15 + 150) = 3;
                  v15[74] = v26;
                  trigger_event(a1, v15 + 42, v15 + 72);
                  v18 &= ~8u;
                  if ( v18 )
                  {
LABEL_78:
                    if ( (v18 & 0x40) == 0 || enhd_pipe != 1 )
                      goto LABEL_172;
                    if ( logging_option != 1
                      && ((unsigned __int8)print_limit_option < 3u
                       || (unsigned int)__ratelimit(&pipe_handler__rs_320, "pipe_handler")) )
                    {
                      printk(&unk_270DA, "pipe_handler", a1 + 24);
                    }
                    if ( a1 )
                      ipc_log_string(
                        *(_QWORD *)(a1 + 552),
                        "%s: sps:bam %pa ;pipe 0x%x irq status=0x%x\nsps: BAM_PIPE_IRQ_RST_ERROR\n",
                        "pipe_handler",
                        (const void *)(a1 + 24),
                        v16,
                        v18);
                    bam_output_register_content(a1 + 216, *(_DWORD *)(a1 + 128));
                    v27 = v15[65];
                    v15[75] = 0;
                    v15[77] = 0;
                    v15[76] = 0;
                    v15[73] = 0;
                    v15[72] = 0;
                    *((_DWORD *)v15 + 150) = 8;
                    v15[74] = v27;
                    trigger_event(a1, v15 + 62, v15 + 72);
                    v18 &= ~0x40u;
                    if ( v18 )
                    {
LABEL_172:
                      if ( (v18 & 0x80) == 0 || enhd_pipe != 1 )
                        goto LABEL_93;
                      if ( logging_option != 1
                        && ((unsigned __int8)print_limit_option < 3u
                         || (unsigned int)__ratelimit(&pipe_handler__rs_323, "pipe_handler")) )
                      {
                        printk(&unk_2B1C3, "pipe_handler", a1 + 24);
                      }
                      if ( a1 )
                        ipc_log_string(
                          *(_QWORD *)(a1 + 552),
                          "%s: sps:bam %pa ;pipe 0x%x irq status=0x%x\nsps: BAM_PIPE_IRQ_HRESP_ERROR\n",
                          "pipe_handler",
                          (const void *)(a1 + 24),
                          v16,
                          v18);
                      bam_output_register_content(a1 + 216, *(_DWORD *)(a1 + 128));
                      v28 = v15[69];
                      v15[75] = 0;
                      v15[77] = 0;
                      v15[76] = 0;
                      v15[73] = 0;
                      v15[72] = 0;
                      *((_DWORD *)v15 + 150) = 9;
                      v15[74] = v28;
                      trigger_event(a1, v15 + 66, v15 + 72);
                      v18 &= ~0x80u;
                      if ( v18 )
                      {
LABEL_93:
                        if ( (v18 & 7) != 0 )
                        {
                          v29 = v15[61];
                          v15[75] = 0;
                          v15[77] = 0;
                          v15[76] = 0;
                          v15[73] = 0;
                          v15[72] = 0;
                          *((_DWORD *)v15 + 150) = 7;
                          v15[74] = v29;
                          trigger_event(a1, v15 + 58, v15 + 72);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          v6 &= ~*((_DWORD *)v15 + 48);
        }
        if ( !v6 )
          goto LABEL_116;
      }
      if ( v6 )
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_bam_check_irq__rs_19, "sps_bam_check_irq")) )
        {
          printk(&unk_2949E, "sps_bam_check_irq", a1 + 24);
        }
        if ( a1 )
          ipc_log_string(
            *(_QWORD *)(a1 + 552),
            "%s: sps:IRQ from BAM %pa inactive pipe(s) 0x%x\n",
            "sps_bam_check_irq",
            (const void *)(a1 + 24),
            v6);
        ++*(_DWORD *)(a1 + 520);
      }
LABEL_116:
      if ( (*(_BYTE *)(a1 + 16) & 0x80) != 0 )
      {
        v30 = *(_DWORD *)(a1 + 248);
        v31 = *(_DWORD *)(a1 + 128);
        v36 = 0;
        v32 = bam_check_irq_source((const void **)(a1 + 216), v31, v30, (int *)&v36);
        if ( (unsigned __int8)logging_option >= 2u
          && (unsigned __int8)debug_level_option >= 3u
          && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_check_irq__rs_22, "sps_bam_check_irq")) )
        {
          printk(&unk_27986, "sps_bam_check_irq", a1 + 24);
        }
        if ( a1 && *(_DWORD *)(a1 + 568) <= 1u )
          ipc_log_string(
            *(_QWORD *)(a1 + 536),
            "%s: sps:check if there is any new IRQ coming:bam=%pa;source=0x%x;mask=0x%x\n",
            "sps_bam_check_irq",
            (const void *)(a1 + 24),
            v32,
            v30);
        if ( v32 < 0 && *(_QWORD *)(a1 + 104) )
        {
          if ( (unsigned __int8)logging_option >= 2u
            && (unsigned __int8)debug_level_option >= 3u
            && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_check_irq__rs_25, "sps_bam_check_irq")) )
          {
            printk(&unk_234E3, "sps_bam_check_irq", a1 + 24);
          }
          if ( a1 && *(_DWORD *)(a1 + 568) <= 1u )
            ipc_log_string(
              *(_QWORD *)(a1 + 536),
              "%s: sps:bam=%pa;callback for case %d\n",
              "sps_bam_check_irq",
              (const void *)(a1 + 24),
              v36);
          v13 = *(void (__fastcall **)(__int64, __int64))(a1 + 104);
          v12 = *(_QWORD *)(a1 + 112);
          v14 = v36;
          if ( *((_DWORD *)v13 - 1) != -835259500 )
            __break(0x8228u);
          v13(v14, v12);
        }
        if ( v32 )
          continue;
      }
      v5 = v35;
      v4 = a1 + 228;
      goto LABEL_149;
    }
  }
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u
     || (unsigned int)__ratelimit(&sps_bam_check_irq__rs_4, "sps_bam_check_irq")) )
  {
    printk(&unk_28161, "sps_bam_check_irq", a1 + 24);
  }
  if ( a1 )
    ipc_log_string(
      *(_QWORD *)(a1 + 552),
      "%s: sps:IRQ from BAM %pa can't be currently served\n",
      "sps_bam_check_irq",
      (const void *)(a1 + 24));
  v4 = a1 + 228;
  v5 = v3;
LABEL_149:
  raw_spin_unlock_irqrestore(v4, v5);
  result = 0;
LABEL_150:
  _ReadStatusReg(SP_EL0);
  return result;
}
