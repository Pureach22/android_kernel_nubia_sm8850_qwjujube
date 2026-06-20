__int64 __fastcall gpi_process_events(__int64 a1)
{
  unsigned int **v1; // x20
  __int64 v2; // x25
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x4
  __int64 v6; // x5
  __int64 v7; // x6
  __int64 v8; // x8
  __int64 v9; // x9
  unsigned int **v10; // x24
  __int64 v11; // x27
  __int64 v12; // x10
  __int64 v13; // x9
  __int64 v14; // x21
  __int64 v15; // x19
  __int64 result; // x0
  void (*v17)(void); // x9
  unsigned __int64 v18; // x9
  __int64 v19; // x10
  unsigned __int64 v20; // x8
  unsigned __int64 v21; // x11
  unsigned __int64 v22; // x10
  unsigned int *v23; // x22
  unsigned int v24; // w21
  __int64 v25; // x23
  unsigned int **v26; // x0
  unsigned int *v27; // x21
  __int64 v28; // x8
  unsigned int **v29; // x19
  __int64 v30; // x8
  unsigned int **v31; // x19
  unsigned int *v32; // x2
  unsigned int *v33; // x10
  __int64 v34; // x9
  __int64 v35; // x21
  __int64 v36; // x8
  __int64 v37; // x26
  __int64 v38; // x28
  __int64 v39; // x27
  __int64 v40; // x0
  __int64 v41; // x23
  __int64 v42; // x8
  __int64 v43; // x24
  __int64 v44; // x8
  __int64 v45; // x26
  __int64 v46; // x27
  __int64 v47; // x28
  __int64 v48; // x19
  __int64 v49; // x20
  __int64 v50; // x0
  __int64 v51; // x23
  __int64 v52; // x4
  __int64 v53; // x5
  __int64 v54; // x6
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x8
  __int64 v57; // x0
  void (*v58)(void); // x8
  __int64 v59; // x8
  __int64 v60; // x28
  __int64 v61; // x26
  __int64 v62; // x27
  __int64 v63; // x0
  __int64 v64; // x23
  __int64 v65; // x8
  __int64 v66; // x0
  __int64 v67; // x8
  const char *v68; // x4
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x1
  __int64 v73; // x2
  __int64 v74; // x8
  __int64 v75; // x0
  __int64 v76; // x0
  unsigned int *v77; // x23
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  int *v81; // x0
  __int64 v82; // x9
  void (__fastcall *v83)(_QWORD); // x8
  int v84; // w8
  int v85; // w8
  int *v86; // x26
  __int64 v87; // x0
  unsigned int **v88; // x19
  unsigned int **v89; // x19
  const char *v90; // x4
  __int64 v91; // x0
  __int64 v92; // x8
  const char *v93; // x4
  __int64 v94; // x0
  __int64 v95; // x8
  const char *v96; // x4
  const char *v97; // x4
  const char *v98; // x4
  unsigned int *v99; // x0
  unsigned int **v100; // [xsp+0h] [xbp-60h]
  unsigned int **v101; // [xsp+8h] [xbp-58h]
  __int64 v102; // [xsp+10h] [xbp-50h]
  __int64 v103; // [xsp+18h] [xbp-48h] BYREF
  __int64 v104; // [xsp+20h] [xbp-40h]
  __int64 v105; // [xsp+28h] [xbp-38h]
  unsigned __int64 v106; // [xsp+30h] [xbp-30h]
  __int64 v107; // [xsp+38h] [xbp-28h]
  _QWORD v108[4]; // [xsp+40h] [xbp-20h] BYREF

  v1 = (unsigned int **)a1;
  v108[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 960);
  v3 = (unsigned int)readl_relaxed(*(unsigned int **)(a1 + 848));
  v4 = readl_relaxed(v1[106] + 1);
  v8 = *(_QWORD *)(v2 + 16);
  v9 = *(_QWORD *)(v2 + 32);
  v10 = v1 + 1;
  v100 = v1;
  v101 = v1 + 1;
  v11 = v9 + (v3 | (v4 << 32)) - v8;
  v12 = *(_QWORD *)(v2 + 48);
  while ( v11 == v12 )
  {
LABEL_3:
    v13 = *(_QWORD *)(v2 + 40) - v9;
    v14 = v13 + v8;
    writel_relaxed(v13 + v8, v1[104]);
    writel_relaxed(HIDWORD(v14), v1[104] + 1);
    writel_relaxed(1u, v1[110]);
    v15 = (unsigned int)readl_relaxed(v1[106]);
    result = readl_relaxed(v1[106] + 1);
    __dsb(0xFu);
    v8 = *(_QWORD *)(v2 + 16);
    v9 = *(_QWORD *)(v2 + 32);
    v12 = *(_QWORD *)(v2 + 48);
    v11 = v9 + (v15 | (result << 32)) - v8;
    if ( v11 == v12 )
      goto LABEL_194;
  }
  v102 = v11;
  while ( 1 )
  {
    __dsb(0xFu);
    v23 = *(unsigned int **)(v2 + 48);
    v24 = *((unsigned __int8 *)v23 + 15);
    v25 = *((unsigned __int8 *)v23 + 14);
    if ( v24 >= 2 )
      break;
    if ( *((unsigned __int8 *)v23 + 14) <= 0x30u )
    {
      if ( (_DWORD)v25 == 34 )
      {
        v35 = (__int64)&v10[49 * *((unsigned __int8 *)v23 + 15)];
        v59 = *(unsigned int *)(v35 + 292);
        v60 = *(_QWORD *)(v35 + 280);
        if ( (_DWORD)v59 != 3 )
        {
          if ( *(_DWORD *)(v60 + 1068) >= 2u )
          {
            v98 = "INVALID";
            if ( (unsigned int)v59 <= 5 )
              v98 = gpi_pm_state_str[v59];
            printk(&unk_14D69, v60 + 1076, *(unsigned int *)(v35 + 256), "gpi_process_xfer_compl_event", v98, v6, v7);
            v94 = *(_QWORD *)(v60 + 1056);
            if ( v94 )
            {
LABEL_176:
              if ( *(_DWORD *)(v60 + 1064) >= 2u )
              {
                v95 = *(unsigned int *)(v35 + 292);
                v96 = "INVALID";
                if ( (unsigned int)v95 <= 5 )
                  v96 = gpi_pm_state_str[v95];
                ipc_log_string(
                  v94,
                  "ch:%u %s: skipping processing event because ch @ %s state\n",
                  *(_DWORD *)(v35 + 256),
                  "gpi_process_xfer_compl_event",
                  v96);
              }
            }
          }
          else
          {
            v94 = *(_QWORD *)(v60 + 1056);
            if ( v94 )
              goto LABEL_176;
          }
          gpi_generate_cb_event(v35, 4, 2441);
          goto LABEL_9;
        }
        v61 = *(_QWORD *)(v35 + 352);
        v62 = *(_QWORD *)(v61 + 32) + *(_QWORD *)v23 - *(_QWORD *)(v61 + 16);
        v63 = raw_spin_lock_irqsave(v35 + 160);
        v64 = *(_QWORD *)(v35 + 200);
        raw_spin_unlock_irqrestore(v35 + 160, v63);
        if ( v64 == v35 + 200 || v64 == 152 )
        {
          v74 = *(_QWORD *)(v61 + 32);
          if ( v62 + (unsigned __int64)*(unsigned int *)(v61 + 60) < v74 + (unsigned __int64)*(unsigned int *)(v61 + 56) )
            v74 = v62 + *(unsigned int *)(v61 + 60);
          *(_QWORD *)(v61 + 48) = v74;
          if ( *(_DWORD *)(v60 + 1068) >= 2u )
            printk(&unk_119BB, v60 + 1076, *(unsigned int *)(v35 + 256), "gpi_process_xfer_compl_event", v5, v6, v7);
          v75 = *(_QWORD *)(v60 + 1056);
          v11 = v102;
          if ( v75 && *(_DWORD *)(v60 + 1064) >= 2u )
            ipc_log_string(
              v75,
              "ch:%u %s: Event without a pending descriptor!\n",
              *(_DWORD *)(v35 + 256),
              "gpi_process_xfer_compl_event");
          if ( *(_DWORD *)(v60 + 1068) >= 2u )
          {
            printk(
              &unk_13A18,
              v60 + 1076,
              *(unsigned int *)(v35 + 256),
              "gpi_process_xfer_compl_event",
              *v23,
              v23[1],
              v23[2]);
            v76 = *(_QWORD *)(v60 + 1056);
            if ( v76 )
              goto LABEL_96;
          }
          else
          {
            v76 = *(_QWORD *)(v60 + 1056);
            if ( v76 )
            {
LABEL_96:
              if ( *(_DWORD *)(v60 + 1064) >= 2u )
                ipc_log_string(
                  v76,
                  "ch:%u %s: Event: %08x %08x %08x %08x\n",
                  *(_DWORD *)(v35 + 256),
                  "gpi_process_xfer_compl_event",
                  *v23,
                  v23[1],
                  v23[2],
                  v23[3]);
            }
          }
          if ( (*(_BYTE *)(v60 + 1472) & 1) == 0 )
            gpi_generate_cb_event(v35, 5, 2471);
          goto LABEL_9;
        }
        if ( *(_BYTE *)(v60 + 1475) == 1 )
          --*(_DWORD *)(v60 + 1476);
        v65 = *(_QWORD *)(v61 + 32);
        if ( v62 + (unsigned __int64)*(unsigned int *)(v61 + 60) < v65 + (unsigned __int64)*(unsigned int *)(v61 + 56) )
          v65 = v62 + *(unsigned int *)(v61 + 60);
        *(_QWORD *)(v61 + 48) = v65;
        __dmb(0xAu);
        if ( *(_BYTE *)(v60 + 1472) != 1 )
        {
          v11 = v102;
          if ( *((_BYTE *)v23 + 11) == 4
            && (*(_DWORD *)(v35 + 388) != 1 || !*(_DWORD *)(v35 + 384))
            && *(_DWORD *)(v60 + 804) != 2 )
          {
            goto LABEL_146;
          }
LABEL_136:
          if ( *(_QWORD *)(v64 - 112) )
          {
            v86 = *(int **)(v64 - 96);
            if ( v86 )
            {
              *v86 = *((unsigned __int16 *)v23 + 4) | (*((unsigned __int8 *)v23 + 10) << 16);
              v86[1] = *((unsigned __int8 *)v23 + 11);
              v86[2] = *((unsigned __int16 *)v23 + 6);
              v86[10] = *((unsigned __int8 *)v23 + 14);
              if ( *(_DWORD *)(v60 + 1068) >= 3u )
              {
                printk(
                  &unk_14817,
                  v60 + 1076,
                  *(unsigned int *)(v35 + 256),
                  "gpi_process_xfer_compl_event",
                  v86,
                  v6,
                  v7);
                v87 = *(_QWORD *)(v60 + 1056);
                if ( v87 )
                  goto LABEL_140;
              }
              else
              {
                v87 = *(_QWORD *)(v60 + 1056);
                if ( v87 )
                {
LABEL_140:
                  if ( *(_DWORD *)(v60 + 1064) >= 3u )
                    ipc_log_string(
                      v87,
                      "ch:%u %s: tx_cb_param:%p\n",
                      *(_DWORD *)(v35 + 256),
                      "gpi_process_xfer_compl_event",
                      v86);
                }
              }
              v83 = *(void (__fastcall **)(_QWORD))(v64 - 112);
              v81 = v86;
LABEL_143:
              if ( *((_DWORD *)v83 - 1) != 251140989 )
                __break(0x8228u);
              v83(v81);
            }
          }
LABEL_146:
          gpi_free_chan_desc(v35);
          goto LABEL_9;
        }
        v11 = v102;
        if ( (*(_BYTE *)(v60 + 1475) & 1) != 0 )
        {
          if ( !*(_DWORD *)(v60 + 1476) )
            goto LABEL_9;
          goto LABEL_136;
        }
        v84 = *((unsigned __int8 *)v23 + 11);
        if ( *((_BYTE *)v23 + 15) == 1 )
        {
          if ( v84 == 2 )
            goto LABEL_146;
          if ( v84 == 16 )
          {
            gpi_free_chan_desc(v60 + 8);
            goto LABEL_136;
          }
        }
        else if ( v84 != 2 )
        {
          goto LABEL_136;
        }
      }
      else if ( (_DWORD)v25 == 48 )
      {
        v35 = (__int64)&v10[49 * *((unsigned __int8 *)v23 + 15)];
        v36 = *(unsigned int *)(v35 + 292);
        v37 = *(_QWORD *)(v35 + 280);
        if ( (_DWORD)v36 != 3 )
        {
          if ( *(_DWORD *)(v37 + 1068) >= 2u )
          {
            v90 = "INVALID";
            if ( (unsigned int)v36 <= 5 )
              v90 = gpi_pm_state_str[v36];
            printk(&unk_14D69, v37 + 1076, *(unsigned int *)(v35 + 256), "gpi_process_imed_data_event", v90, v6, v7);
            v66 = *(_QWORD *)(v37 + 1056);
            if ( v66 )
            {
LABEL_71:
              if ( *(_DWORD *)(v37 + 1064) >= 2u )
              {
                v67 = *(unsigned int *)(v35 + 292);
                v68 = "INVALID";
                if ( (unsigned int)v67 <= 5 )
                  v68 = gpi_pm_state_str[v67];
                ipc_log_string(
                  v66,
                  "ch:%u %s: skipping processing event because ch @ %s state\n",
                  *(_DWORD *)(v35 + 256),
                  "gpi_process_imed_data_event",
                  v68);
              }
            }
          }
          else
          {
            v66 = *(_QWORD *)(v37 + 1056);
            if ( v66 )
              goto LABEL_71;
          }
          gpi_generate_cb_event(v35, 4, 2305);
          goto LABEL_9;
        }
        v38 = *(_QWORD *)(v35 + 352);
        v39 = *(_QWORD *)(v38 + 32) + *(_DWORD *)(v38 + 60) * (unsigned int)*(unsigned __int16 *)((char *)v23 + 9);
        v40 = raw_spin_lock_irqsave(v35 + 160);
        v41 = *(_QWORD *)(v35 + 200);
        raw_spin_unlock_irqrestore(v35 + 160, v40);
        if ( v41 == v35 + 200 || v41 == 152 )
        {
          if ( v39 + (unsigned __int64)*(unsigned int *)(v38 + 60) >= *(_QWORD *)(v38 + 32)
                                                                    + (unsigned __int64)*(unsigned int *)(v38 + 56) )
            v77 = *(unsigned int **)(v38 + 32);
          else
            v77 = (unsigned int *)(v39 + *(unsigned int *)(v38 + 60));
          *(_QWORD *)(v38 + 48) = v77;
          if ( *(_DWORD *)(v37 + 1068) >= 2u )
            printk(&unk_12ADE, v37 + 1076, *(unsigned int *)(v35 + 256), "gpi_process_imed_data_event", v5, v6, v7);
          v78 = *(_QWORD *)(v37 + 1056);
          v11 = v102;
          if ( v78 && *(_DWORD *)(v37 + 1064) >= 2u )
            ipc_log_string(
              v78,
              "ch:%u %s: event without a pending descriptor!\n",
              *(_DWORD *)(v35 + 256),
              "gpi_process_imed_data_event");
          if ( *(_DWORD *)(v37 + 1068) >= 2u )
          {
            printk(
              &unk_13A18,
              v37 + 1076,
              *(unsigned int *)(v35 + 256),
              "gpi_process_imed_data_event",
              *v23,
              v23[1],
              v23[2]);
            v79 = *(_QWORD *)(v37 + 1056);
            if ( v79 )
              goto LABEL_110;
          }
          else
          {
            v79 = *(_QWORD *)(v37 + 1056);
            if ( v79 )
            {
LABEL_110:
              if ( *(_DWORD *)(v37 + 1064) >= 2u )
                ipc_log_string(
                  v79,
                  "ch:%u %s: Event: %08x %08x %08x %08x\n",
                  *(_DWORD *)(v35 + 256),
                  "gpi_process_imed_data_event",
                  *v23,
                  v23[1],
                  v23[2],
                  v23[3]);
            }
          }
          if ( *(_DWORD *)(v37 + 1068) >= 2u )
          {
            printk(
              &unk_11DB0,
              v37 + 1076,
              *(unsigned int *)(v35 + 256),
              "gpi_process_imed_data_event",
              *v77,
              v77[1],
              v77[2]);
            v80 = *(_QWORD *)(v37 + 1056);
            if ( v80 )
              goto LABEL_114;
          }
          else
          {
            v80 = *(_QWORD *)(v37 + 1056);
            if ( v80 )
            {
LABEL_114:
              if ( *(_DWORD *)(v37 + 1064) >= 2u )
                ipc_log_string(
                  v80,
                  "ch:%u %s: Pending TRE: %08x %08x %08x %08x\n",
                  *(_DWORD *)(v35 + 256),
                  "gpi_process_imed_data_event",
                  *v77,
                  v77[1],
                  v77[2],
                  v77[3]);
            }
          }
          if ( (*(_BYTE *)(v37 + 1472) & 1) == 0 )
            gpi_generate_cb_event(v35, 5, 2341);
          goto LABEL_9;
        }
        if ( *(_BYTE *)(v37 + 1475) == 1 )
          --*(_DWORD *)(v37 + 1476);
        v42 = *(_QWORD *)(v38 + 32);
        if ( v39 + (unsigned __int64)*(unsigned int *)(v38 + 60) < v42 + (unsigned __int64)*(unsigned int *)(v38 + 56) )
          v42 = v39 + *(unsigned int *)(v38 + 60);
        *(_QWORD *)(v38 + 48) = v42;
        __dmb(0xAu);
        if ( *(_BYTE *)(v37 + 1472) != 1 )
        {
          v11 = v102;
          if ( *((_BYTE *)v23 + 11) == 4 )
            goto LABEL_146;
          goto LABEL_124;
        }
        v11 = v102;
        if ( (*(_BYTE *)(v37 + 1475) & 1) != 0 )
        {
          if ( !*(_DWORD *)(v37 + 1476) )
            goto LABEL_9;
          goto LABEL_124;
        }
        v85 = *((unsigned __int8 *)v23 + 11);
        if ( *((_BYTE *)v23 + 15) != 1 )
        {
          if ( v85 == 2 )
            goto LABEL_9;
LABEL_124:
          if ( *(_QWORD *)(v41 - 112) )
          {
            v81 = *(int **)(v41 - 96);
            if ( v81 )
            {
              v82 = *(_QWORD *)v23;
              *(_QWORD *)(v81 + 5) = *((_QWORD *)v23 + 1);
              *(_QWORD *)(v81 + 3) = v82;
              *v81 = v23[2] & 0xF;
              v81[1] = *((unsigned __int8 *)v23 + 11);
              v81[2] = *((unsigned __int16 *)v23 + 6);
              v83 = *(void (__fastcall **)(_QWORD))(v41 - 112);
              goto LABEL_143;
            }
          }
          goto LABEL_146;
        }
        if ( v85 == 2 )
          goto LABEL_146;
        if ( v85 == 16 )
        {
          gpi_free_chan_desc(v37 + 8);
          goto LABEL_124;
        }
      }
    }
    else
    {
      switch ( (_DWORD)v25 )
      {
        case '1':
          v107 = 0;
          memset(v108, 0, 24);
          v105 = 0;
          v106 = 0;
          v103 = 0;
          v104 = 0;
          v104 = *v23;
          v105 = v23[1];
          v17 = (void (*)(void))v10[49 * v24 + 46];
          v106 = *((unsigned __int16 *)v23 + 4) | ((unsigned __int64)*((unsigned __int8 *)v23 + 10) << 16);
          if ( *((_DWORD *)v17 - 1) != 1361247836 )
            __break(0x8229u);
          v17();
          break;
        case '5':
          v43 = (__int64)&v10[49 * *((unsigned __int8 *)v23 + 15)];
          v44 = *(unsigned int *)(v43 + 292);
          v45 = *(_QWORD *)(v43 + 280);
          if ( (_DWORD)v44 == 3 )
          {
            v46 = *(_QWORD *)(v43 + 352);
            v47 = *v23;
            v48 = *(_QWORD *)(v46 + 32);
            v49 = *(_QWORD *)(v46 + 16);
            v50 = raw_spin_lock_irqsave(v43 + 160);
            v51 = *(_QWORD *)(v43 + 200);
            raw_spin_unlock_irqrestore(v43 + 160, v50);
            if ( v51 != v43 + 200 && v51 != 152 )
            {
              v55 = v48 - v49 + v47 + *(unsigned int *)(v46 + 60);
              if ( v55 >= *(_QWORD *)(v46 + 32) + (unsigned __int64)*(unsigned int *)(v46 + 56) )
                v55 = *(_QWORD *)(v46 + 32);
              *(_QWORD *)(v46 + 48) = v55;
              __dmb(0xAu);
              v56 = *(_QWORD *)(v23 + 1);
              if ( HIBYTE(v56) != 4 || *(_DWORD *)(v45 + 804) == 14 )
              {
                if ( *(_QWORD *)(v51 - 112) )
                {
                  v57 = *(_QWORD *)(v51 - 96);
                  if ( v57 )
                  {
                    *(_DWORD *)v57 = HIDWORD(v56) & 0xFFFFF;
                    *(_DWORD *)(v57 + 4) = *((unsigned __int8 *)v23 + 11);
                    *(_DWORD *)(v57 + 40) = *((unsigned __int8 *)v23 + 14);
                    *(_DWORD *)(v57 + 8) = *((unsigned __int16 *)v23 + 6);
                    *(_BYTE *)(v57 + 44) = BYTE2(*(_QWORD *)(v23 + 1));
                    v58 = *(void (**)(void))(v51 - 112);
                    if ( *((_DWORD *)v58 - 1) != 251140989 )
                      __break(0x8228u);
                    v58();
                  }
                }
              }
              gpi_free_chan_desc(v43);
              v10 = v101;
              v11 = v102;
              break;
            }
            if ( *(_DWORD *)(v45 + 1068) >= 2u )
              printk(
                &unk_119BB,
                v45 + 1076,
                *(unsigned int *)(v43 + 256),
                "gpi_process_qup_q2spi_status",
                v52,
                v53,
                v54);
            v69 = *(_QWORD *)(v45 + 1056);
            v11 = v102;
            if ( v69 && *(_DWORD *)(v45 + 1064) >= 2u )
              ipc_log_string(
                v69,
                "ch:%u %s: Event without a pending descriptor!\n",
                *(_DWORD *)(v43 + 256),
                "gpi_process_qup_q2spi_status");
            if ( *(_DWORD *)(v45 + 1068) >= 2u )
            {
              printk(
                &unk_13A18,
                v45 + 1076,
                *(unsigned int *)(v43 + 256),
                "gpi_process_qup_q2spi_status",
                *v23,
                v23[1],
                v23[2]);
              v70 = *(_QWORD *)(v45 + 1056);
              if ( v70 )
                goto LABEL_83;
            }
            else
            {
              v70 = *(_QWORD *)(v45 + 1056);
              if ( v70 )
              {
LABEL_83:
                if ( *(_DWORD *)(v45 + 1064) >= 2u )
                  ipc_log_string(
                    v70,
                    "ch:%u %s: Event: %08x %08x %08x %08x\n",
                    *(_DWORD *)(v43 + 256),
                    "gpi_process_qup_q2spi_status",
                    *v23,
                    v23[1],
                    v23[2],
                    v23[3]);
              }
            }
            v71 = v43;
            v72 = 5;
            v73 = 2583;
LABEL_86:
            gpi_generate_cb_event(v71, v72, v73);
            v10 = v101;
            break;
          }
          if ( *(_DWORD *)(v45 + 1068) >= 2u )
          {
            v97 = "INVALID";
            if ( (unsigned int)v44 <= 5 )
              v97 = gpi_pm_state_str[v44];
            printk(&unk_14D69, v45 + 1076, *(unsigned int *)(v43 + 256), "gpi_process_qup_q2spi_status", v97, v6, v7);
            v91 = *(_QWORD *)(v45 + 1056);
            if ( v91 )
            {
LABEL_169:
              if ( *(_DWORD *)(v45 + 1064) >= 2u )
              {
                v92 = *(unsigned int *)(v43 + 292);
                v93 = "INVALID";
                if ( (unsigned int)v92 <= 5 )
                  v93 = gpi_pm_state_str[v92];
                ipc_log_string(
                  v91,
                  "ch:%u %s: skipping processing event because ch @ %s state\n",
                  *(_DWORD *)(v43 + 256),
                  "gpi_process_qup_q2spi_status",
                  v93);
              }
            }
          }
          else
          {
            v91 = *(_QWORD *)(v45 + 1056);
            if ( v91 )
              goto LABEL_169;
          }
          v71 = v43;
          v72 = 4;
          v73 = 2567;
          goto LABEL_86;
        case '6':
          v26 = &v10[49 * *((unsigned __int8 *)v23 + 15)];
          v107 = 0;
          memset(v108, 0, 24);
          v105 = 0;
          v106 = 0;
          v103 = 0;
          v104 = 0;
          v27 = v26[35];
          if ( (unsigned __int64)*((unsigned __int8 *)v23 + 11) << 24 == 184549376 )
          {
            if ( v27[267] >= 2 )
            {
              v88 = v26;
              printk(&unk_14985, v27 + 269, *((unsigned int *)v26 + 64), "gpi_process_xfer_q2spi_cr_header", v5, v6, v7);
              v26 = v88;
              v28 = *((_QWORD *)v27 + 132);
              if ( v28 )
                goto LABEL_22;
            }
            else
            {
              v28 = *((_QWORD *)v27 + 132);
              if ( v28 )
              {
LABEL_22:
                if ( v27[266] >= 2 )
                {
                  v29 = v26;
                  ipc_log_string(
                    v28,
                    "ch:%u %s: Err negative 1H doorbell response\n",
                    *((_DWORD *)v26 + 64),
                    "gpi_process_xfer_q2spi_cr_header");
                  v26 = v29;
                }
              }
            }
          }
          if ( (unsigned __int64)*((unsigned __int8 *)v23 + 11) << 24 == 201326592 )
          {
            if ( v27[267] >= 2 )
            {
              v89 = v26;
              printk(&unk_1214B, v27 + 269, *((unsigned int *)v26 + 64), "gpi_process_xfer_q2spi_cr_header", v5, v6, v7);
              v26 = v89;
              v30 = *((_QWORD *)v27 + 132);
              if ( v30 )
                goto LABEL_27;
            }
            else
            {
              v30 = *((_QWORD *)v27 + 132);
              if ( v30 )
              {
LABEL_27:
                if ( v27[266] >= 2 )
                {
                  v31 = v26;
                  ipc_log_string(
                    v30,
                    "ch:%u %s: Err unexpected CR Header is received\n",
                    *((_DWORD *)v26 + 64),
                    "gpi_process_xfer_q2spi_cr_header");
                  v26 = v31;
                }
              }
            }
          }
          v33 = v26[46];
          v32 = v26[47];
          LODWORD(v103) = 7;
          v34 = *(_QWORD *)v23;
          *(_QWORD *)((char *)&v108[1] + 4) = *((_QWORD *)v23 + 1);
          *(_QWORD *)((char *)v108 + 4) = v34;
          if ( *(v33 - 1) != 1361247836 )
            __break(0x822Au);
          ((void (__fastcall *)(unsigned int **, __int64 *, unsigned int *))v33)(v26, &v103, v32);
          break;
      }
    }
LABEL_9:
    v18 = *(_QWORD *)(v2 + 32);
    v19 = *(unsigned int *)(v2 + 60);
    v20 = *(_QWORD *)(v2 + 40) + v19;
    v21 = v18 + *(unsigned int *)(v2 + 56);
    v22 = *(_QWORD *)(v2 + 48) + v19;
    if ( v20 >= v21 )
      v20 = *(_QWORD *)(v2 + 32);
    if ( v22 < v21 )
      v18 = v22;
    *(_QWORD *)(v2 + 40) = v20;
    *(_QWORD *)(v2 + 48) = v18;
    __dmb(0xAu);
    __dsb(0xFu);
    if ( v11 == *(_QWORD *)(v2 + 48) )
    {
      v8 = *(_QWORD *)(v2 + 16);
      v9 = *(_QWORD *)(v2 + 32);
      v1 = v100;
      goto LABEL_3;
    }
  }
  if ( *((_DWORD *)v100 + 267) >= 2u )
  {
    printk(&unk_13699, (char *)v100 + 1076, 99, "gpi_process_events", *((unsigned __int8 *)v23 + 15), v6, v7);
    v99 = v100[132];
    if ( v99 )
      goto LABEL_191;
  }
  else
  {
    v99 = v100[132];
    if ( v99 )
    {
LABEL_191:
      if ( *((_DWORD *)v100 + 266) >= 2u )
        ipc_log_string(v99, "ch:%u %s: gpii channel:%d not valid\n", 99, "gpi_process_events", v24);
    }
  }
  writel_relaxed(1u, v100[110]);
  gpi_generate_cb_event(v10, 3, v25 << 8);
  result = gpi_generate_cb_event(v100 + 50, 3, ((unsigned __int64)(unsigned __int8)v25 << 8) | 1);
LABEL_194:
  _ReadStatusReg(SP_EL0);
  return result;
}
