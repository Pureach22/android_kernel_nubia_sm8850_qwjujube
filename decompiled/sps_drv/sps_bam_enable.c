__int64 __fastcall sps_bam_enable(__int64 a1)
{
  int v1; // w8
  int v2; // w9
  __int64 result; // x0
  int v5; // w9
  int v6; // w0
  int v7; // w20
  unsigned int v8; // w3
  char v9; // w8
  __int64 v10; // x2
  int v11; // w9
  unsigned int v12; // w20
  int v13; // w8
  unsigned int v14; // w8
  unsigned int v15; // w20
  int v16; // w21
  char v17; // w9
  int v18; // w9
  __int64 v19; // x3
  __int64 v20; // x2
  int *v21; // x20
  char v22; // w9
  int v23; // w8
  int v24; // w21
  int v25; // w20
  int v26; // w8
  int v27; // w20
  int v28; // w20
  int v29; // w8
  int v30; // w9
  int v31; // w20
  int v32; // w8
  int v33; // w20
  int v34; // w8
  int v35; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 160);
  if ( (v1 & 8) != 0 )
    goto LABEL_142;
  v2 = *(_DWORD *)(a1 + 120);
  v35 = 0;
  if ( (~v2 & 0x1D) != 0 )
  {
    v5 = *(_DWORD *)(a1 + 16);
    if ( (v5 & 2) != 0 || !*(_DWORD *)(a1 + 44) )
    {
      v8 = 0;
      *(_DWORD *)(a1 + 160) = v1 & 0xFFFFFFF3;
      goto LABEL_17;
    }
    if ( (v5 & 0x80) != 0 )
    {
      v6 = request_threaded_irq();
      if ( (unsigned __int8)logging_option >= 2u )
      {
        if ( debug_level_option )
        {
          if ( !print_limit_option
            || (v33 = v6, v34 = __ratelimit(&sps_bam_enable__rs_29, "sps_bam_enable"), v6 = v33, v34) )
          {
            v28 = v6;
            printk(&unk_29EE4, "sps_bam_enable", a1 + 24);
            v6 = v28;
          }
        }
      }
      if ( !a1 || *(_DWORD *)(a1 + 568) >= 4u )
        goto LABEL_51;
      v7 = v6;
      ipc_log_string(
        *(_QWORD *)(a1 + 552),
        "%s: sps:BAM %pa uses edge for IRQ# %d\n",
        "sps_bam_enable",
        a1 + 24,
        *(unsigned int *)(a1 + 44));
    }
    else
    {
      v6 = request_threaded_irq();
      if ( (unsigned __int8)logging_option >= 2u )
      {
        if ( debug_level_option )
        {
          if ( !print_limit_option
            || (v31 = v6, v32 = __ratelimit(&sps_bam_enable__rs_32, "sps_bam_enable"), v6 = v31, v32) )
          {
            v27 = v6;
            printk(&unk_2AE62, "sps_bam_enable", a1 + 24);
            v6 = v27;
          }
        }
      }
      if ( !a1 || *(_DWORD *)(a1 + 568) > 3u )
        goto LABEL_51;
      v7 = v6;
      ipc_log_string(
        *(_QWORD *)(a1 + 552),
        "%s: sps:BAM %pa uses level for IRQ# %d\n",
        "sps_bam_enable",
        a1 + 24,
        *(unsigned int *)(a1 + 44));
    }
    v6 = v7;
LABEL_51:
    if ( v6 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_enable__rs_38, "sps_bam_enable")) )
      {
        printk(&unk_2862C, "sps_bam_enable", a1 + 24);
      }
      if ( !a1 )
        goto LABEL_125;
      ipc_log_string(
        *(_QWORD *)(a1 + 552),
        "%s: sps:Failed to enable BAM %pa IRQ %d\n",
        "sps_bam_enable",
        a1 + 24,
        *(unsigned int *)(a1 + 44));
LABEL_57:
      result = 0xFFFFFFFFLL;
      goto LABEL_143;
    }
    v17 = *(_BYTE *)(a1 + 16);
    *(_DWORD *)(a1 + 160) |= 4u;
    if ( (v17 & 8) != 0 )
    {
      if ( (unsigned int)irq_set_irq_wake(*(unsigned int *)(a1 + 44), 1) )
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_bam_enable__rs_41, "sps_bam_enable")) )
        {
          printk(&unk_2B118, "sps_bam_enable", a1 + 24);
        }
        if ( !a1 )
          goto LABEL_125;
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps:Fail to enable wakeup irq for BAM %pa IRQ %d\n",
          "sps_bam_enable",
          a1 + 24,
          *(unsigned int *)(a1 + 44));
        goto LABEL_57;
      }
      if ( (unsigned __int8)logging_option >= 2u
        && debug_level_option
        && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_enable__rs_44, "sps_bam_enable")) )
      {
        printk(&unk_2B150, "sps_bam_enable", a1 + 24);
      }
      if ( a1 && *(_DWORD *)(a1 + 568) <= 3u )
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps:Enable wakeup irq for BAM %pa IRQ %d\n",
          "sps_bam_enable",
          (const void *)(a1 + 24),
          *(_DWORD *)(a1 + 44));
    }
    v8 = 22;
LABEL_17:
    v9 = *(_BYTE *)(a1 + 120);
    v35 = 0;
    if ( (v9 & 1) != 0 )
    {
      if ( (unsigned int)bam_check((const void **)(a1 + 216), (int *)(a1 + 224), *(unsigned int *)(a1 + 128), &v35) )
      {
LABEL_19:
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_bam_enable__rs_47, "sps_bam_enable")) )
        {
          printk(&unk_28F2E, "sps_bam_enable", a1 + 24);
        }
        if ( !a1 )
          goto LABEL_125;
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps:Fail to init BAM %pa IRQ %d\n",
          "sps_bam_enable",
          a1 + 24,
          *(unsigned int *)(a1 + 44));
        goto LABEL_57;
      }
    }
    else if ( (unsigned int)bam_init(
                              (const void **)(a1 + 216),
                              *(_DWORD *)(a1 + 128),
                              *(_DWORD *)(a1 + 52),
                              v8,
                              (int *)(a1 + 224),
                              &v35,
                              *(_DWORD *)(a1 + 16)) )
    {
      goto LABEL_19;
    }
    v11 = *(_DWORD *)(a1 + 120);
    v12 = *(_DWORD *)(a1 + 224);
    if ( (~v11 & 3) == 0 && !*(_DWORD *)(a1 + 128) && v12 <= 2 )
    {
      if ( logging_option != 1
        && ((unsigned __int8)print_limit_option < 3u
         || (unsigned int)__ratelimit(&sps_bam_enable__rs_50, "sps_bam_enable")) )
      {
        printk(&unk_2AB66, "sps_bam_enable", v10);
      }
      if ( a1 )
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps: EE for satellite BAM must be set to non-zero\n",
          "sps_bam_enable");
      goto LABEL_125;
    }
    v13 = *(_DWORD *)(a1 + 160);
    if ( (v13 & 4) != 0 && (v11 & 1) != 0 && v12 <= 2 )
    {
      v18 = *(_DWORD *)(a1 + 136);
      if ( !v18 || v18 == -559038737 )
      {
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 3u
           || (unsigned int)__ratelimit(&sps_bam_enable__rs_53, "sps_bam_enable")) )
        {
          printk(&unk_23846, "sps_bam_enable", a1 + 24);
        }
        if ( a1 )
        {
          ipc_log_string(
            *(_QWORD *)(a1 + 552),
            "%s: sps:MTI destination address not specified for BAM %pa\n",
            "sps_bam_enable",
            a1 + 24);
          goto LABEL_8;
        }
        goto LABEL_125;
      }
      *(_DWORD *)(a1 + 160) = v13 | 0x20;
    }
    if ( v35 )
    {
      *(_DWORD *)(a1 + 48) = v35;
      if ( (unsigned __int8)logging_option >= 2u
        && debug_level_option
        && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_enable__rs_56, "sps_bam_enable")) )
      {
        printk(&unk_24261, "sps_bam_enable", a1 + 24);
      }
      if ( a1 && *(_DWORD *)(a1 + 568) <= 3u )
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps:BAM %pa number of pipes reported by hw: %d\n",
          "sps_bam_enable",
          (const void *)(a1 + 24),
          *(_DWORD *)(a1 + 48));
    }
    if ( v12 < 3 )
    {
      if ( (*(_BYTE *)(a1 + 120) & 1) == 0 )
      {
        v14 = *(_DWORD *)(a1 + 48);
        if ( v14 )
        {
          v15 = 0;
          v16 = 1;
          do
          {
            if ( (*(_DWORD *)(a1 + 124) & v16) != 0 )
            {
              bam_pipe_satellite_mti(a1 + 216, v15);
              v14 = *(_DWORD *)(a1 + 48);
            }
            ++v15;
            v16 *= 2;
          }
          while ( v15 < v14 );
        }
      }
      goto LABEL_129;
    }
    v19 = *(unsigned int *)(a1 + 128);
    if ( (unsigned int)v19 < 4 )
    {
      if ( *(_DWORD *)(a1 + 140) == 172180819 )
      {
        v21 = *(int **)(a1 + 144);
        if ( !v21 )
        {
          if ( logging_option != 1
            && ((unsigned __int8)print_limit_option < 3u
             || (unsigned int)__ratelimit(&sps_bam_enable__rs_62, "sps_bam_enable")) )
          {
            printk(&unk_25933, "sps_bam_enable", a1 + 24);
          }
          if ( a1 )
          {
            ipc_log_string(
              *(_QWORD *)(a1 + 552),
              "%s: sps:EE config table is not specified for BAM %pa\n",
              "sps_bam_enable",
              a1 + 24);
            goto LABEL_8;
          }
          goto LABEL_125;
        }
        v22 = *(_BYTE *)(a1 + 120);
        *(_DWORD *)(a1 + 124) = ~v21[2 * v19];
        if ( (v22 & 1) == 0 )
        {
          v23 = *v21;
          if ( (v21[2] & *v21) != 0 )
          {
            v24 = 0;
            v25 = 1;
          }
          else if ( (v21[4] & v23) != 0 )
          {
            v24 = 0;
            v25 = 2;
          }
          else if ( (v21[6] & v23) != 0 )
          {
            v24 = 0;
            v25 = 3;
          }
          else
          {
            v26 = v21[2];
            if ( (v21[4] & v26) != 0 )
            {
              v25 = 2;
              v24 = 1;
            }
            else if ( (v21[6] & v26) != 0 )
            {
              v25 = 3;
              v24 = 1;
            }
            else
            {
              if ( (v21[6] & v21[4]) == 0 )
              {
                bam_security_init((const void **)(a1 + 216), 0, v21[1], *v21 & 0x7FFFFFFF | (((_DWORD)v19 == 0) << 31));
                bam_security_init(
                  (const void **)(a1 + 216),
                  1,
                  v21[3],
                  v21[2] & 0x7FFFFFFF | ((*(_DWORD *)(a1 + 128) == 1) << 31));
                bam_security_init(
                  (const void **)(a1 + 216),
                  2,
                  v21[5],
                  v21[4] & 0x7FFFFFFF | ((*(_DWORD *)(a1 + 128) == 2) << 31));
                bam_security_init(
                  (const void **)(a1 + 216),
                  3,
                  v21[7],
                  v21[6] & 0x7FFFFFFF | ((*(_DWORD *)(a1 + 128) == 3) << 31));
                goto LABEL_129;
              }
              v25 = 3;
              v24 = 2;
            }
          }
          if ( logging_option != 1
            && ((unsigned __int8)print_limit_option < 3u
             || (unsigned int)__ratelimit(&sps_bam_enable__rs_65, "sps_bam_enable")) )
          {
            printk(&unk_294D0, "sps_bam_enable", a1 + 24);
          }
          if ( a1 )
            ipc_log_string(
              *(_QWORD *)(a1 + 552),
              "%s: sps:Overlapping pipe assignments for BAM %pa: EEs %d and %d\n",
              "sps_bam_enable",
              (const void *)(a1 + 24),
              v24,
              v25);
          goto LABEL_125;
        }
      }
LABEL_129:
      v29 = *(_DWORD *)(a1 + 156);
      v30 = *(unsigned __int8 *)(a1 + 152);
      *(_DWORD *)(a1 + 160) |= 8u;
      if ( v30 == 1 )
      {
        if ( !v29 )
        {
          if ( (unsigned __int8)logging_option >= 2u
            && debug_level_option
            && (!print_limit_option || (unsigned int)__ratelimit(&sps_bam_enable__rs_71, "sps_bam_enable")) )
          {
            printk(&unk_23E22, "sps_bam_enable", a1 + 24);
          }
          if ( !a1 || *(_DWORD *)(a1 + 568) > 3u )
            goto LABEL_142;
          goto LABEL_141;
        }
      }
      else if ( !v29 )
      {
LABEL_137:
        if ( logging_option != 1
          && ((unsigned __int8)print_limit_option < 2u
           || (unsigned int)__ratelimit(&sps_bam_enable__rs_68, "sps_bam_enable")) )
        {
          printk(&unk_23E22, "sps_bam_enable", a1 + 24);
        }
        if ( !a1 )
          goto LABEL_142;
LABEL_141:
        ipc_log_string(
          *(_QWORD *)(a1 + 552),
          "%s: sps:BAM %pa (va:0x%pK) enabled: ver:0x%x, number of pipes:%d\n",
          "sps_bam_enable",
          (const void *)(a1 + 24),
          *(const void **)(a1 + 216),
          *(_DWORD *)(a1 + 224),
          *(_DWORD *)(a1 + 48));
LABEL_142:
        result = 0;
        goto LABEL_143;
      }
      *(_DWORD *)(a1 + 156) = v29 - 1;
      goto LABEL_137;
    }
    if ( logging_option != 1 )
    {
      if ( (unsigned __int8)print_limit_option < 3u )
      {
        v20 = a1 + 24;
LABEL_73:
        printk(&unk_22E4F, "sps_bam_enable", v20);
        goto LABEL_74;
      }
      if ( (unsigned int)__ratelimit(&sps_bam_enable__rs_59, "sps_bam_enable") )
      {
        v20 = a1 + 24;
        goto LABEL_73;
      }
    }
LABEL_74:
    if ( a1 )
    {
      ipc_log_string(
        *(_QWORD *)(a1 + 552),
        "%s: sps:Invalid EE BAM %pa: %d\n",
        "sps_bam_enable",
        a1 + 24,
        *(unsigned int *)(a1 + 128));
      goto LABEL_57;
    }
LABEL_125:
    result = 0xFFFFFFFFLL;
    goto LABEL_143;
  }
  if ( logging_option != 1
    && ((unsigned __int8)print_limit_option < 3u || (unsigned int)__ratelimit(&sps_bam_enable__rs, "sps_bam_enable")) )
  {
    printk(&unk_237FB, "sps_bam_enable", a1 + 24);
  }
  if ( !a1 )
    goto LABEL_125;
  ipc_log_string(*(_QWORD *)(a1 + 552), "%s: sps:No local access to BAM %pa\n", "sps_bam_enable", a1 + 24);
LABEL_8:
  result = 0xFFFFFFFFLL;
LABEL_143:
  _ReadStatusReg(SP_EL0);
  return result;
}
