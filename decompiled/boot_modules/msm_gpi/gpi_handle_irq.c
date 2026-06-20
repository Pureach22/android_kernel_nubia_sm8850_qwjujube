__int64 __fastcall gpi_handle_irq(__int64 a1, __int64 a2)
{
  int v3; // w23
  __int64 lock_irqsave; // x0
  __int64 v5; // x5
  __int64 v6; // x6
  __int64 v7; // x8
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 v10; // x6
  unsigned int v11; // w22
  int v12; // w8
  __int64 v13; // x24
  __int64 v14; // x21
  __int64 v15; // x0
  int v16; // w23
  unsigned int v17; // w0
  __int64 v18; // x8
  unsigned int v19; // w25
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x23
  unsigned int v23; // w28
  __int64 v24; // x5
  __int64 v25; // x6
  unsigned int v26; // w27
  unsigned int v27; // w8
  __int64 v28; // x25
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x2
  _DWORD *v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  unsigned int v35; // w0
  __int64 v36; // x5
  __int64 v37; // x6
  unsigned int v38; // w9
  unsigned int v39; // w10
  unsigned int v40; // w8
  __int64 v41; // x0
  __int64 v42; // x8
  const char *v43; // x4
  __int64 v44; // x0
  int v45; // w25
  unsigned int v46; // w23
  unsigned int v47; // w0
  int v48; // w8
  int v49; // w8
  unsigned int v50; // w0
  int v51; // w8
  int v52; // w8
  const char *v53; // x4
  __int64 v54; // x0
  unsigned __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x8
  const char *v64; // x4
  __int64 v65; // x0
  int v66; // w24
  __int64 v67; // x5
  __int64 v68; // x6
  unsigned int v69; // w22
  __int64 v70; // x0
  char v71; // w9
  __int64 v73; // [xsp+8h] [xbp-58h]
  __int64 v74; // [xsp+10h] [xbp-50h]
  _QWORD v75[4]; // [xsp+18h] [xbp-48h] BYREF
  __int64 v76; // [xsp+38h] [xbp-28h]
  __int64 v77; // [xsp+40h] [xbp-20h]
  __int64 v78; // [xsp+48h] [xbp-18h]
  __int64 v79; // [xsp+50h] [xbp-10h]
  __int64 v80; // [xsp+58h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)a2;
  *(_BYTE *)(a2 + 1473) = 1;
  lock_irqsave = raw_read_lock_irqsave(a2 + 948);
  v7 = *(unsigned int *)(a2 + 944);
  v73 = lock_irqsave;
  if ( (unsigned int)v7 > 1 )
  {
    v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 816) + (unsigned int)((*(_DWORD *)a2 << 14) + 143488)));
    v74 = a2 + 8;
    v12 = (v3 << 14) + 143488;
    v13 = v12 | 0x14u;
    v14 = v12 | 0x24u;
    while ( 1 )
    {
      if ( (v11 & 4) == 0 )
      {
        if ( (v11 & 8) == 0 )
          goto LABEL_5;
        goto LABEL_32;
      }
      if ( *(_DWORD *)(a2 + 1068) >= 2u )
      {
        printk(&unk_13CA0, a2 + 1076, 99, "gpi_handle_irq", v8, v9, v10);
        v15 = *(_QWORD *)(a2 + 1056);
        if ( !v15 )
          goto LABEL_13;
      }
      else
      {
        v15 = *(_QWORD *)(a2 + 1056);
        if ( !v15 )
          goto LABEL_13;
      }
      if ( *(_DWORD *)(a2 + 1064) >= 2u )
        ipc_log_string(v15, "ch:%u %s: processing global error irq\n", 99, "gpi_handle_irq");
LABEL_13:
      v16 = (*(_DWORD *)a2 << 14) + 143488;
      v17 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 816) + (unsigned int)((*(_DWORD *)a2 << 14) + 143616)));
      v18 = *(_QWORD *)(a2 + 816);
      v19 = v17;
      v78 = 0;
      v79 = 0;
      v76 = 0;
      v77 = 0;
      memset(v75, 0, sizeof(v75));
      writel_relaxed(v17, (unsigned int *)(v18 + (unsigned int)(v16 + 144)));
      if ( v19 >= 2 )
      {
        if ( *(_DWORD *)(a2 + 1068) >= 2u )
        {
          printk(&unk_13FE2, a2 + 1076, 99, "gpi_process_glob_err_irq", v19, v20, v21);
          v33 = *(_QWORD *)(a2 + 1056);
          if ( !v33 )
            goto LABEL_30;
        }
        else
        {
          v33 = *(_QWORD *)(a2 + 1056);
          if ( !v33 )
            goto LABEL_30;
        }
        if ( *(_DWORD *)(a2 + 1064) >= 2u )
          ipc_log_string(v33, "ch:%u %s: invalid error status:0x%x\n", 99, "gpi_process_glob_err_irq", v19);
        goto LABEL_30;
      }
      v22 = (unsigned int)(v16 + 384);
      v23 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 816) + v22));
      writel_relaxed(0, (unsigned int *)(*(_QWORD *)(a2 + 816) + v22));
      v26 = (v23 >> 19) & 0x1F;
      if ( v26 >= 2 )
      {
        if ( *(_DWORD *)(a2 + 1068) >= 2u )
        {
          printk(&unk_11E30, a2 + 1076, 99, "gpi_process_glob_err_irq", v26, v24, v25);
          v54 = *(_QWORD *)(a2 + 1056);
          if ( v54 )
            goto LABEL_96;
        }
        else
        {
          v54 = *(_QWORD *)(a2 + 1056);
          if ( v54 )
          {
LABEL_96:
            if ( *(_DWORD *)(a2 + 1064) >= 2u )
              ipc_log_string(v54, "ch:%u %s: invalid chid reported:%u\n", 99, "gpi_process_glob_err_irq", v26);
          }
        }
LABEL_30:
        gpi_generate_cb_event(v74, 3u, v19);
        gpi_generate_cb_event(a2 + 400, 3u, v19);
        goto LABEL_31;
      }
      v27 = *(_DWORD *)(a2 + 1068);
      LODWORD(v75[0]) = 1;
      v28 = v74 + 392LL * v26;
      LODWORD(v76) = v23 & 0xF;
      HIDWORD(v76) = (unsigned __int8)v23 >> 4;
      LODWORD(v77) = (unsigned __int16)v23 >> 12;
      if ( v27 >= 3 )
      {
        printk(
          &unk_12F60,
          a2 + 1076,
          *(unsigned int *)(v28 + 256),
          "gpi_process_glob_err_irq",
          "GLOBAL ERROR",
          v24,
          v25);
        v29 = *(_QWORD *)(a2 + 1056);
        if ( !v29 )
          goto LABEL_19;
      }
      else
      {
        v29 = *(_QWORD *)(a2 + 1056);
        if ( !v29 )
          goto LABEL_19;
      }
      if ( *(_DWORD *)(a2 + 1064) >= 3u )
        ipc_log_string(
          v29,
          "ch:%u %s: sending CB event:%s\n",
          *(_DWORD *)(v28 + 256),
          "gpi_process_glob_err_irq",
          "GLOBAL ERROR");
LABEL_19:
      if ( *(_DWORD *)(a2 + 1068) >= 2u )
      {
        printk(
          &unk_1387C,
          a2 + 1076,
          *(unsigned int *)(v28 + 256),
          "gpi_process_glob_err_irq",
          (v23 >> 26) & 1,
          (v23 >> 25) & 1,
          v23 & 0xF);
        v30 = *(_QWORD *)(a2 + 1056);
        if ( v30 )
        {
LABEL_21:
          if ( *(_DWORD *)(a2 + 1064) >= 2u )
            ipc_log_string(
              v30,
              "ch:%u %s: ee:%u chtype:%u routine:%u type:%u error_code:%u\n",
              *(_DWORD *)(v28 + 256),
              "gpi_process_glob_err_irq",
              (v23 >> 26) & 1,
              (v23 >> 25) & 1,
              v23 & 0xF,
              (unsigned __int8)v23 >> 4,
              (unsigned __int16)v23 >> 12);
        }
      }
      else
      {
        v30 = *(_QWORD *)(a2 + 1056);
        if ( v30 )
          goto LABEL_21;
      }
      v32 = *(_DWORD **)(v28 + 368);
      v31 = *(_QWORD *)(v28 + 376);
      if ( *(v32 - 1) != 1361247836 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD *, __int64))v32)(v28, v75, v31);
LABEL_31:
      v11 &= ~4u;
      if ( (v11 & 8) == 0 )
      {
LABEL_5:
        if ( (v11 & 2) == 0 )
          goto LABEL_6;
        goto LABEL_36;
      }
LABEL_32:
      writel_relaxed(1u, *(unsigned int **)(a2 + 880));
      if ( *(_DWORD *)(a2 + 800) )
      {
        gpi_config_interrupts((int *)a2, 1, 0);
        _X9 = (unsigned __int64 *)(a2 + 984);
        __asm { PRFM            #0x11, [X9] }
        do
          v61 = __ldxr(_X9);
        while ( __stlxr(v61 | 1, _X9) );
        __dmb(0xBu);
        if ( (v61 & 1) == 0 )
          _tasklet_schedule(a2 + 976);
      }
      else
      {
        gpi_process_events(a2);
      }
      v11 &= ~8u;
      if ( (v11 & 2) == 0 )
      {
LABEL_6:
        if ( (v11 & 1) == 0 )
          goto LABEL_7;
        goto LABEL_50;
      }
LABEL_36:
      if ( *(_DWORD *)(a2 + 1068) >= 3u )
      {
        printk(&unk_14378, a2 + 1076, 99, "gpi_handle_irq", v8, v9, v10);
        v34 = *(_QWORD *)(a2 + 1056);
        if ( !v34 )
          goto LABEL_40;
      }
      else
      {
        v34 = *(_QWORD *)(a2 + 1056);
        if ( !v34 )
          goto LABEL_40;
      }
      if ( *(_DWORD *)(a2 + 1064) >= 3u )
        ipc_log_string(v34, "ch:%u %s: processing EV CTRL interrupt\n", 99, "gpi_handle_irq");
LABEL_40:
      v35 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 816) + v13));
      writel_relaxed(v35, (unsigned int *)(*(_QWORD *)(a2 + 816) + v14));
      v38 = ((unsigned int)readl_relaxed(*(unsigned int **)(a2 + 824)) >> 20) & 0xF;
      v39 = *(_DWORD *)(a2 + 1068);
      if ( *(_DWORD *)(a2 + 1048) == 12 )
        v40 = 0;
      else
        v40 = v38;
      *(_DWORD *)(a2 + 936) = v40;
      if ( v39 < 3 )
      {
        v41 = *(_QWORD *)(a2 + 1056);
        if ( !v41 )
          goto LABEL_49;
LABEL_45:
        if ( *(_DWORD *)(a2 + 1064) >= 3u )
        {
          v42 = *(unsigned int *)(a2 + 936);
          v43 = "INVALID";
          if ( (unsigned int)v42 <= 1 )
            v43 = gpi_ev_state_str[v42];
          ipc_log_string(v41, "ch:%u %s: setting EV state to %s\n", 99, "gpi_handle_irq", v43);
        }
        goto LABEL_49;
      }
      v53 = "INVALID";
      if ( v40 <= 1 )
        v53 = gpi_ev_state_str[v40];
      printk(&unk_11A13, a2 + 1076, 99, "gpi_handle_irq", v53, v36, v37);
      v41 = *(_QWORD *)(a2 + 1056);
      if ( v41 )
        goto LABEL_45;
LABEL_49:
      complete_all(a2 + 1016);
      v11 &= ~2u;
      if ( (v11 & 1) == 0 )
      {
LABEL_7:
        if ( v11 )
          goto LABEL_108;
        goto LABEL_75;
      }
LABEL_50:
      if ( *(_DWORD *)(a2 + 1068) >= 3u )
      {
        printk(&unk_13FBA, a2 + 1076, 99, "gpi_handle_irq", v8, v9, v10);
        v44 = *(_QWORD *)(a2 + 1056);
        if ( !v44 )
          goto LABEL_54;
      }
      else
      {
        v44 = *(_QWORD *)(a2 + 1056);
        if ( !v44 )
          goto LABEL_54;
      }
      if ( *(_DWORD *)(a2 + 1064) >= 3u )
        ipc_log_string(v44, "ch:%u %s: process CH CTRL interrupts\n", 99, "gpi_handle_irq");
LABEL_54:
      v45 = (*(_DWORD *)a2 << 14) + 143488;
      v46 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 816) + (unsigned int)((*(_DWORD *)a2 << 14) + 143504)));
      writel_relaxed(v46, (unsigned int *)(*(_QWORD *)(a2 + 816) + (unsigned int)(v45 + 32)));
      if ( (v46 & 1) != 0 )
      {
        v47 = readl_relaxed(*(unsigned int **)(a2 + 304));
        v48 = *(_DWORD *)(a2 + 1048);
        if ( v48 == 4 )
        {
          v49 = 0;
        }
        else if ( v48 == 9 )
        {
          v49 = 6;
        }
        else
        {
          v49 = v48 == 8 ? 5 : (v47 >> 20) & 0xF;
        }
        *(_DWORD *)(a2 + 296) = v49;
        complete_all(a2 + 1016);
        if ( *(_DWORD *)(a2 + 296) == 15 )
          gpi_generate_cb_event(v74, 2u, v46);
      }
      if ( (v46 & 2) != 0 )
      {
        v50 = readl_relaxed(*(unsigned int **)(a2 + 696));
        v51 = *(_DWORD *)(a2 + 1048);
        if ( v51 == 4 )
        {
          v52 = 0;
        }
        else if ( v51 == 8 )
        {
          v52 = 5;
        }
        else
        {
          v52 = v51 == 9 ? 6 : (v50 >> 20) & 0xF;
        }
        *(_DWORD *)(a2 + 688) = v52;
        complete_all(a2 + 1016);
        if ( *(_DWORD *)(a2 + 688) == 15 )
          gpi_generate_cb_event(a2 + 400, 2u, v46);
      }
      v11 &= ~1u;
      if ( v11 )
      {
LABEL_108:
        if ( *(_DWORD *)(a2 + 1068) )
        {
          printk(&unk_11FD1, a2 + 1076, 99, "gpi_handle_irq", v11, v9, v10);
          v65 = *(_QWORD *)(a2 + 1056);
          if ( v65 )
            goto LABEL_110;
        }
        else
        {
          v65 = *(_QWORD *)(a2 + 1056);
          if ( v65 )
          {
LABEL_110:
            if ( *(_DWORD *)(a2 + 1064) )
              ipc_log_string(v65, "ch:%u %s: Unhandled interrupt status:0x%x\n", 99, "gpi_handle_irq", v11);
          }
        }
        v66 = *(_DWORD *)a2 << 14;
        v69 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 816) + (unsigned int)(v66 + 143640)));
        if ( *(_DWORD *)(a2 + 1068) >= 2u )
        {
          printk(&unk_11C51, a2 + 1076, 99, "gpi_process_gen_err_irq", v69, v67, v68);
          v70 = *(_QWORD *)(a2 + 1056);
          if ( v70 )
            goto LABEL_114;
        }
        else
        {
          v70 = *(_QWORD *)(a2 + 1056);
          if ( v70 )
          {
LABEL_114:
            if ( *(_DWORD *)(a2 + 1064) >= 2u )
              ipc_log_string(v70, "ch:%u %s: irq_stts:0x%x\n", 99, "gpi_process_gen_err_irq", v69);
          }
        }
        if ( *(_QWORD *)(a2 + 376) )
          gpi_generate_cb_event(v74, 3u, v69);
        if ( *(_QWORD *)(a2 + 768) )
          gpi_generate_cb_event(a2 + 400, 3u, v69);
        writel_relaxed(v69, (unsigned int *)(*(_QWORD *)(a2 + 816) + (unsigned int)(v66 + 143656)));
        v71 = *(_BYTE *)(a2 + 1464);
        ++*(_DWORD *)(a2 + 1468);
        if ( (v71 & 1) == 0 )
        {
          gpi_dump_debug_reg((unsigned int *)a2);
          *(_BYTE *)(a2 + 1464) = 1;
        }
        goto LABEL_124;
      }
LABEL_75:
      v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(a2 + 816) + (unsigned int)((*(_DWORD *)a2 << 14) + 143488)));
      if ( !v11 )
        goto LABEL_124;
    }
  }
  if ( *(_DWORD *)(a2 + 1068) )
  {
    printk(&unk_12F04, a2 + 1076, 99, "gpi_handle_irq", gpi_pm_state_str[v7], v5, v6);
    v62 = *(_QWORD *)(a2 + 1056);
    if ( !v62 )
      goto LABEL_124;
  }
  else
  {
    v62 = *(_QWORD *)(a2 + 1056);
    if ( !v62 )
      goto LABEL_124;
  }
  if ( *(_DWORD *)(a2 + 1064) )
  {
    v63 = *(unsigned int *)(a2 + 944);
    if ( (unsigned int)v63 <= 5 )
      v64 = gpi_pm_state_str[v63];
    else
      v64 = "INVALID";
    ipc_log_string(v62, "ch:%u %s: receive interrupt while in %s state\n", 99, "gpi_handle_irq", v64);
  }
LABEL_124:
  raw_read_unlock_irqrestore(a2 + 948, v73);
  *(_BYTE *)(a2 + 1473) = 0;
  _ReadStatusReg(SP_EL0);
  return 1;
}
