__int64 __fastcall spcom_device_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  size_t v3; // x23
  __int64 v5; // x8
  unsigned __int64 StatusReg; // x27
  int v9; // w5
  __int64 v10; // x2
  const char *v11; // x0
  __int64 v12; // x8
  int v13; // w0
  __int64 v14; // x2
  unsigned __int64 v15; // x8
  __int64 result; // x0
  unsigned __int64 v18; // x10
  unsigned __int64 v23; // x11
  __int64 v24; // x22
  __int64 v25; // x2
  char v26; // w8
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x1
  int v29; // w20
  __int64 v30; // x2
  size_t v31; // x0
  unsigned int v32; // w19
  __int64 v33; // x21
  const char *v34; // x23
  unsigned int v35; // w21
  __int64 v36; // x2
  unsigned __int64 v38; // x28
  __int64 v39; // x20
  __int64 v40; // x19
  __int64 v41; // x2
  __int64 v43; // x20
  __int64 v44; // x19
  unsigned __int64 v45; // x8
  unsigned __int64 v47; // x9
  unsigned __int64 v48; // x8
  unsigned __int64 v50; // x9
  __int64 v51; // x0
  unsigned int v52; // w0
  unsigned __int64 v53; // x20
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x9
  unsigned __int64 v58; // x10
  unsigned __int64 v59; // x8
  unsigned __int64 v61; // x9
  int v62; // w19
  int channel; // w0
  __int64 v64; // x19
  int v65; // w21
  __int64 v66; // x0
  __int64 v67; // x2
  __int64 v69; // x20
  const char *v70; // x19
  __int64 v71; // x2
  unsigned __int64 v73; // x21
  __int64 v74; // x22
  const char *v75; // x19
  unsigned __int64 v76; // x8
  unsigned __int64 v78; // x10
  unsigned __int64 v80; // x11
  unsigned __int64 v81; // x8
  unsigned __int64 v83; // x9
  const char *v84; // x20
  __int64 v85; // x8
  __int64 v86; // x8
  __int64 v87; // x0
  int v88; // w21
  bool v89; // cc
  unsigned int v90; // w19
  __int64 v91; // x21
  __int64 v92; // x20
  _BOOL8 v93; // x20
  unsigned int v94; // w20
  int v95; // w20
  unsigned __int64 v96; // x0
  __int64 v97; // x2
  const void *v98; // x21
  const char *v99; // x22
  char *v100; // x8
  __int64 v101; // x9
  __int64 v102; // x5
  __int64 v103; // x22
  unsigned int v104; // w22
  unsigned int v105; // w23
  __int64 v106; // x21
  unsigned int v107; // w24
  __int64 v108; // x20
  __int64 v109; // x22
  unsigned __int64 v110; // x9
  unsigned __int64 v112; // x10
  unsigned __int64 v114; // x11
  unsigned __int64 v115; // x8
  unsigned __int64 v117; // x9
  unsigned int v118; // w0
  unsigned int v119; // w19
  int v120; // w8
  int v121; // w11
  __int64 v122; // x10
  unsigned __int64 v123; // x8
  unsigned __int64 v124; // x9
  unsigned __int64 v126; // x10
  unsigned __int64 v127; // x8
  unsigned __int64 v129; // x9
  unsigned __int64 v130; // x0
  unsigned __int64 v131; // x22
  __int64 v132; // x21
  char v133; // w22
  __int64 v134; // x23
  int v135; // w0
  unsigned int v136; // w22
  int v137; // w5
  unsigned int v138; // w23
  unsigned int v139; // w22
  unsigned __int64 v140; // x8
  unsigned __int64 v141; // x8
  unsigned __int64 v143; // x9
  unsigned __int64 v144; // x8
  unsigned __int64 v146; // x9
  __int64 v147; // x0
  __int64 v148; // x2
  __int64 v149; // x8
  int v150; // w19
  unsigned __int8 v151; // w9
  int v152; // w20
  unsigned int v153; // w0
  __int64 v154; // x2
  int v155; // w9
  unsigned int v156; // w21
  unsigned __int64 v157; // x8
  unsigned __int64 v159; // x9
  char string[16]; // [xsp+10h] [xbp-50h] BYREF
  __int64 v161; // [xsp+20h] [xbp-40h]
  __int64 v162; // [xsp+28h] [xbp-38h]
  __int64 v163; // [xsp+30h] [xbp-30h]
  __int64 v164; // [xsp+38h] [xbp-28h]
  __int64 v165; // [xsp+40h] [xbp-20h]
  __int64 v166; // [xsp+48h] [xbp-18h]
  __int64 v167; // [xsp+50h] [xbp-10h]
  __int64 v168; // [xsp+58h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  StatusReg = _ReadStatusReg(SP_EL0);
  v168 = v5;
  v9 = *(_DWORD *)(StatusReg + 1804);
  v166 = 0;
  v167 = 0;
  v164 = 0;
  v165 = 0;
  v162 = 0;
  v163 = 0;
  v161 = 0;
  *(_OWORD *)string = 0u;
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: ioctl cmd [%u], PID [%d]\n",
    "spcom_device_ioctl",
    (const char *)&unk_F80E,
    (unsigned __int8)a2,
    v9);
  if ( *(_DWORD *)(spcom_dev + 58428) )
  {
    printk(&unk_1146C, "spcom_device_ioctl", v10);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: module remove in progress\n",
      "spcom_device_ioctl",
      (const char *)&unk_F80E);
    result = -19;
    goto LABEL_314;
  }
  v11 = "unknown";
  if ( a1 )
  {
    v12 = *(_QWORD *)(a1 + 72);
    if ( v12 )
      v11 = (const char *)(v12 + 56);
  }
  v13 = strcmp(v11, "spcom");
  if ( a2 != -1073130751 && v13 )
  {
    printk(&unk_12C58, "spcom_device_ioctl", v14);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ioctl is supported only for control channel\n",
      "spcom_device_ioctl",
      (const char *)&unk_F80E);
    result = -22;
    goto LABEL_314;
  }
  if ( (a2 & 0x40000000) == 0 )
    goto LABEL_8;
  v24 = HIWORD(a2) & 0x3FFF;
  v26 = is_arg_size_expected(a2, HIWORD(a2) & 0x3FFF);
  result = -14;
  if ( (v26 & 1) == 0 )
    goto LABEL_314;
  if ( !a3 )
  {
    printk(&unk_F766, "spcom_ioctl_copy_user_arg", v25);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: user arg is NULL\n",
      "spcom_ioctl_copy_user_arg",
      (const char *)&unk_F80E);
    result = -22;
    goto LABEL_314;
  }
  if ( (unsigned int)v24 >= 0x49 )
  {
    _copy_overflow(72, HIWORD(a2) & 0x3FFF);
    LODWORD(v3) = HIWORD(a2) & 0x3FFF;
    goto LABEL_30;
  }
  _check_object_size(string, HIWORD(a2) & 0x3FFF, 0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v27 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v27 = a3 & ((__int64)(a3 << 8) >> 8);
  v3 = HIWORD(a2) & 0x3FFF;
  if ( 0x8000000000LL - v24 < v27 )
    goto LABEL_318;
  v45 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v47 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v47 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v47);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v45);
  v3 = _arch_copy_from_user(string, a3 & 0xFF7FFFFFFFFFFFFFLL, HIWORD(a2) & 0x3FFF);
  v48 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v50 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v50 - 4096);
  _WriteStatusReg(TTBR1_EL1, v50);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v48);
  if ( v3 )
  {
LABEL_318:
    if ( v24 - v3 <= 0x48 )
      v28 = 72 - (v24 - v3);
    else
      v28 = 0;
    if ( v28 < v3 )
      goto LABEL_302;
    memset(&string[v24 - v3], 0, v3);
    if ( (_DWORD)v3 )
    {
LABEL_30:
      printk(&unk_EAFE, "spcom_ioctl_copy_user_arg", (unsigned int)v24);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: copy from user failed, size [%u], ret[%d]\n",
        "spcom_ioctl_copy_user_arg",
        (const char *)&unk_F80E,
        v24,
        v3);
      result = -14;
      goto LABEL_314;
    }
  }
LABEL_8:
  if ( a2 > 1075860457 )
  {
    if ( a2 > 1076384748 )
    {
      if ( a2 > 1076384753 )
      {
        if ( a2 != 1076384754 )
        {
          if ( a2 == 1078481902 )
          {
            result = (int)spcom_ioctl_handle_copy_and_send_message(string, a3 + 72, 1);
            goto LABEL_314;
          }
          goto LABEL_234;
        }
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: Unlock dmabuf cmd arg: ch_name[%s], fd[%d], padding[%u], PID[%d]\n",
          "spcom_ioctl_handle_unlock_dmabuf_command",
          (const char *)&unk_F80E,
          string,
          v163,
          HIDWORD(v163),
          *(_DWORD *)(StatusReg + 1804));
        result = -22;
        if ( !string[0] )
          goto LABEL_314;
        v31 = strnlen(string, 0x20u);
        if ( v31 < 0x48 )
        {
          v89 = v31 > 0x1F;
          result = -22;
          if ( !v89 )
          {
            v90 = v163;
            if ( (v163 & 0x80000000) != 0 )
            {
              printk(&unk_10F4B, "spcom_ioctl_handle_unlock_dmabuf_command", (unsigned int)v163);
              ipc_log_string(
                spcom_ipc_log_context,
                "%sspcom:%s: int overflow [%u]\n",
                "spcom_ioctl_handle_unlock_dmabuf_command",
                (const char *)&unk_F80E,
                v90);
              result = -22;
            }
            else
            {
              if ( (_DWORD)v163 == 0xFFFF )
                ipc_log_string(
                  spcom_ipc_log_context,
                  "%sspcom:%s: unlock all FDs of PID [%d]\n",
                  "spcom_ioctl_handle_unlock_dmabuf_command",
                  (const char *)&unk_F80E,
                  *(_DWORD *)(StatusReg + 1804));
              v91 = 32;
              v92 = spcom_dev + 1544;
              while ( strcmp((const char *)(v92 - 344), string) )
              {
                --v91;
                v92 += 1784;
                result = -19;
                if ( !v91 )
                  goto LABEL_314;
              }
              result = -19;
              if ( v92 != 344 )
              {
                v130 = dma_buf_get(v90);
                if ( v130 && (v131 = v130, v130 < 0xFFFFFFFFFFFFF001LL) )
                {
                  dma_buf_put(v130);
                  v132 = v92 - 312;
                  mutex_lock(v92 - 312);
                  if ( v90 == 0xFFFF )
                  {
                    v133 = 0;
                    v134 = 36;
                    do
                    {
                      v135 = spcom_dmabuf_unlock(v92, 1);
                      v92 += 40;
                      --v134;
                      v133 |= v135 == 0;
                    }
                    while ( v134 );
                    mutex_unlock(v132);
                    result = 0;
                    if ( (v133 & 1) == 0 )
                    {
LABEL_249:
                      printk(&unk_11848, "spcom_ioctl_handle_unlock_dmabuf_command", v90);
                      ipc_log_string(
                        spcom_ipc_log_context,
                        "%sspcom:%s: Buffer fd [%d] was not found for PID [%u] on channel [%s]\n",
                        "spcom_ioctl_handle_unlock_dmabuf_command",
                        (const char *)&unk_F80E,
                        v90,
                        *(_DWORD *)(StatusReg + 1804),
                        string);
                      result = -19;
                    }
                  }
                  else
                  {
                    v149 = 36;
                    while ( *(_QWORD *)(v92 + 8) != v131 )
                    {
                      --v149;
                      v92 += 40;
                      if ( !v149 )
                      {
                        mutex_unlock(v132);
                        goto LABEL_249;
                      }
                    }
                    v150 = spcom_dmabuf_unlock(v92, 1);
                    mutex_unlock(v132);
                    result = v150;
                  }
                }
                else
                {
                  printk(&unk_12CFF, "spcom_ioctl_handle_unlock_dmabuf_command", v90);
                  ipc_log_string(
                    spcom_ipc_log_context,
                    "%sspcom:%s: Failed to get dma buf handle, fd [%d]\n",
                    "spcom_ioctl_handle_unlock_dmabuf_command",
                    (const char *)&unk_F80E,
                    v90);
                  result = -22;
                }
              }
            }
          }
          goto LABEL_314;
        }
        goto LABEL_301;
      }
      if ( a2 == 1076384749 )
      {
        result = (int)spcom_ioctl_handle_copy_and_send_message(string, a3 + 40, 0);
        goto LABEL_314;
      }
      if ( a2 != 1076384753 )
        goto LABEL_234;
      v29 = *(_DWORD *)(StatusReg + 1804);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: Lock dmabuf cmd arg: ch_name[%s], fd[%d], padding[%u], PID[%d]\n",
        "spcom_ioctl_handle_lock_dmabuf_command",
        (const char *)&unk_F80E,
        string,
        v163,
        HIDWORD(v163),
        v29);
      if ( string[0] )
      {
        v31 = strnlen(string, 0x20u);
        if ( v31 >= 0x48 )
          goto LABEL_301;
        if ( v31 < 0x20 )
        {
          if ( v29 )
          {
            v32 = v163;
            if ( (v163 & 0x80000000) != 0 )
            {
              printk(&unk_10F4B, "spcom_ioctl_handle_lock_dmabuf_command", (unsigned int)v163);
              ipc_log_string(
                spcom_ipc_log_context,
                "%sspcom:%s: int overflow [%u]\n",
                "spcom_ioctl_handle_lock_dmabuf_command",
                (const char *)&unk_F80E,
                v32);
              result = -22;
            }
            else
            {
              v33 = 32;
              v34 = (const char *)(spcom_dev + 1552);
              while ( strcmp(v34 - 352, string) )
              {
                --v33;
                v34 += 1784;
                if ( !v33 )
                  goto LABEL_218;
              }
              if ( v34 == qword_160 )
              {
LABEL_218:
                printk(&unk_115FB, "spcom_ioctl_handle_lock_dmabuf_command", string);
                ipc_log_string(
                  spcom_ipc_log_context,
                  "%sspcom:%s: could not find channel[%s]\n",
                  "spcom_ioctl_handle_lock_dmabuf_command",
                  (const char *)&unk_F80E,
                  string);
                result = -19;
                goto LABEL_314;
              }
              v96 = dma_buf_get(v32);
              if ( v96 && (v98 = (const void *)v96, v96 < 0xFFFFFFFFFFFFF001LL) )
              {
                v99 = v34 - 320;
                mutex_lock(v34 - 320);
                if ( *((_QWORD *)v34 - 25) )
                {
                  v100 = (char *)(v34 - 8);
                  v101 = 36;
                  do
                  {
                    if ( *(const void **)v34 == v98 )
                    {
                      ipc_log_string(
                        spcom_ipc_log_context,
                        "%sspcom:%s: fd [%d] shared buf is already locked\n",
                        "spcom_ioctl_handle_lock_dmabuf_command",
                        (const char *)&unk_F80E,
                        v32);
                      mutex_unlock(v99);
                      dma_buf_put(v98);
                      result = -22;
                      goto LABEL_314;
                    }
                    --v101;
                    v34 += 40;
                  }
                  while ( v101 );
                  v102 = 0;
                  while ( *((_QWORD *)v100 + 1) )
                  {
                    ++v102;
                    v100 += 40;
                    if ( v102 == 36 )
                    {
                      mutex_unlock(v99);
                      dma_buf_put(v98);
                      printk(&unk_1287C, "spcom_ioctl_handle_lock_dmabuf_command", v32);
                      ipc_log_string(
                        spcom_ipc_log_context,
                        "%sspcom:%s: No free entry to store dmabuf handle of fd [%d] on ch [%s]\n",
                        "spcom_ioctl_handle_lock_dmabuf_command",
                        (const char *)&unk_F80E,
                        v32,
                        string);
                      result = -14;
                      goto LABEL_314;
                    }
                  }
                  *((_QWORD *)v100 + 1) = v98;
                  *(_DWORD *)v100 = v32;
                  *((_DWORD *)v100 + 8) = v29;
                  ipc_log_string(
                    spcom_ipc_log_context,
                    "%sspcom:%s: ch [%s] locked dma buf #%d fd [%d] dma_buf=0x%pK pid #%d\n",
                    "spcom_ioctl_handle_lock_dmabuf_command",
                    (const char *)&unk_F80E,
                    string,
                    v102,
                    v32,
                    v98,
                    v29);
                  mutex_unlock(v99);
                  result = 0;
                }
                else
                {
                  printk(&unk_10C5B, "spcom_ioctl_handle_lock_dmabuf_command", string);
                  ipc_log_string(
                    spcom_ipc_log_context,
                    "%sspcom:%s: Channel [%s] is closed\n",
                    "spcom_ioctl_handle_lock_dmabuf_command",
                    (const char *)&unk_F80E,
                    string);
                  mutex_unlock(v34 - 320);
                  dma_buf_put(v98);
                  result = -22;
                }
              }
              else
              {
                printk(&unk_111CB, "spcom_ioctl_handle_lock_dmabuf_command", v97);
                ipc_log_string(
                  spcom_ipc_log_context,
                  "%sspcom:%s: fail to get dma buf handle\n",
                  "spcom_ioctl_handle_lock_dmabuf_command",
                  (const char *)&unk_F80E);
                result = -22;
              }
            }
          }
          else
          {
            printk(&unk_10736, "spcom_ioctl_handle_lock_dmabuf_command", v30);
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: unknown PID\n",
              "spcom_ioctl_handle_lock_dmabuf_command",
              (const char *)&unk_F80E);
            result = -22;
          }
          goto LABEL_314;
        }
      }
      printk(&unk_1128C, "spcom_ioctl_handle_lock_dmabuf_command", v30);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: invalid channel name\n",
        "spcom_ioctl_handle_lock_dmabuf_command",
        (const char *)&unk_F80E);
      result = -22;
      goto LABEL_314;
    }
    if ( a2 != 1075860458 )
    {
      if ( a2 == 1075860459 )
      {
        if ( !*(_DWORD *)(StatusReg + 1804) )
        {
          printk(&unk_10736, "spcom_ioctl_handle_channel_unregister_command", v14);
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: unknown PID\n",
            "spcom_ioctl_handle_channel_unregister_command",
            (const char *)&unk_F80E);
          result = -22;
          goto LABEL_314;
        }
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: unregister channel cmd arg: ch_name[%s]\n",
          "spcom_ioctl_handle_channel_unregister_command",
          (const char *)&unk_F80E,
          string);
        if ( string[0] )
        {
          v31 = strnlen(string, 0x20u);
          if ( v31 >= 0x48 )
            goto LABEL_301;
          if ( v31 < 0x20 )
          {
            if ( *(_DWORD *)string == 1868787827 && *(unsigned __int16 *)&string[4] == 109 )
            {
              printk(&unk_110E5, "spcom_ioctl_handle_channel_unregister_command", v67);
              ipc_log_string(
                spcom_ipc_log_context,
                "%sspcom:%s: cannot unregister control channel\n",
                "spcom_ioctl_handle_channel_unregister_command",
                (const char *)&unk_F80E);
              result = -22;
            }
            else
            {
              mutex_lock(spcom_dev + 58344);
              v69 = 32;
              v70 = (const char *)(spcom_dev + 1200);
              while ( strcmp(v70, string) )
              {
                --v69;
                v70 += 1784;
                if ( !v69 )
                  goto LABEL_217;
              }
              if ( !v70 )
              {
LABEL_217:
                printk(&unk_115FB, "spcom_ioctl_handle_channel_unregister_command", string);
                ipc_log_string(
                  spcom_ipc_log_context,
                  "%sspcom:%s: could not find channel[%s]\n",
                  "spcom_ioctl_handle_channel_unregister_command",
                  (const char *)&unk_F80E,
                  string);
                mutex_unlock(spcom_dev + 58344);
                result = -19;
                goto LABEL_314;
              }
              v94 = *(_DWORD *)(StatusReg + 1804);
              if ( v94 )
              {
                mutex_lock(v70 + 32);
                v95 = spcom_channel_deinit_locked(v70, v94);
                mutex_unlock(v70 + 32);
              }
              else
              {
                printk(&unk_10736, "spcom_channel_deinit", v71);
                ipc_log_string(
                  spcom_ipc_log_context,
                  "%sspcom:%s: unknown PID\n",
                  "spcom_channel_deinit",
                  (const char *)&unk_F80E);
                v95 = -22;
              }
              mutex_unlock(spcom_dev + 58344);
              ipc_log_string(
                spcom_ipc_log_context,
                "%sspcom:%s: spcom unregister ch[%s] is done, ret[%d]\n",
                "spcom_ioctl_handle_channel_unregister_command",
                (const char *)&unk_F80E,
                string,
                v95);
              result = v95;
            }
            goto LABEL_314;
          }
        }
        printk(&unk_1128C, "spcom_ioctl_handle_channel_unregister_command", v67);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: invalid channel name\n",
          "spcom_ioctl_handle_channel_unregister_command",
          (const char *)&unk_F80E);
        result = -22;
        goto LABEL_314;
      }
      if ( a2 != 1075860460 )
        goto LABEL_234;
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: Is channel connected cmd arg: ch_name[%s]\n",
        "spcom_ioctl_handle_is_channel_connected",
        (const char *)&unk_F80E,
        string);
      if ( string[0] )
      {
        v31 = strnlen(string, 0x20u);
        if ( v31 >= 0x48 )
          goto LABEL_301;
        if ( v31 < 0x20 )
        {
          if ( *(_DWORD *)string == 1868787827 && *(unsigned __int16 *)&string[4] == 109 )
          {
            printk(&unk_F8DD, "spcom_ioctl_handle_is_channel_connected", string);
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: invalid control device: %s\n",
              "spcom_ioctl_handle_is_channel_connected",
              (const char *)&unk_F80E,
              string);
            result = -22;
          }
          else
          {
            v43 = 32;
            v44 = spcom_dev + 1200;
            while ( strcmp((const char *)v44, string) )
            {
              --v43;
              v44 += 1784;
              if ( !v43 )
                goto LABEL_216;
            }
            if ( v44 )
            {
              mutex_lock(v44 + 32);
              v93 = *(_QWORD *)(v44 + 160) != 0;
              mutex_unlock(v44 + 32);
              result = v93;
              goto LABEL_314;
            }
LABEL_216:
            printk(&unk_115FB, "spcom_ioctl_handle_is_channel_connected", string);
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: could not find channel[%s]\n",
              "spcom_ioctl_handle_is_channel_connected",
              (const char *)&unk_F80E,
              string);
            result = -22;
          }
          goto LABEL_314;
        }
      }
      printk(&unk_1128C, "spcom_ioctl_handle_is_channel_connected", v41);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: invalid channel name\n",
        "spcom_ioctl_handle_is_channel_connected",
        (const char *)&unk_F80E);
      result = -22;
      goto LABEL_314;
    }
    if ( !*(_DWORD *)(StatusReg + 1804) )
    {
      printk(&unk_10736, "spcom_ioctl_handle_channel_register_command", v14);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: unknown PID\n",
        "spcom_ioctl_handle_channel_register_command",
        (const char *)&unk_F80E);
      result = -22;
      goto LABEL_314;
    }
    mutex_lock(spcom_dev + 58344);
    channel = spcom_create_channel(string);
    v64 = spcom_dev;
    if ( channel )
    {
      v65 = channel;
      v66 = spcom_dev + 58344;
LABEL_94:
      mutex_unlock(v66);
      result = v65;
      goto LABEL_314;
    }
    v108 = 32;
    v109 = spcom_dev;
    while ( strcmp((const char *)(v109 + 1200), string) )
    {
      --v108;
      v109 += 1784;
      if ( !v108 )
        goto LABEL_192;
    }
    if ( v109 == -1200 )
    {
LABEL_192:
      mutex_unlock(v64 + 58344);
      result = -19;
      goto LABEL_314;
    }
    if ( !*(_QWORD *)(v109 + 1352) )
    {
      *(_DWORD *)(v109 + 1400) = 0;
      v118 = spcom_register_rpmsg_drv(v109 + 1200);
      if ( (v118 & 0x80000000) != 0 )
      {
        v156 = v118;
        mutex_unlock(spcom_dev + 58344);
        printk(&unk_11C2C, "spcom_ioctl_handle_channel_register_command", v156);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: register rpmsg driver failed %d\n",
          "spcom_ioctl_handle_channel_register_command",
          (const char *)&unk_F80E,
          v156);
        result = (int)v156;
        goto LABEL_314;
      }
    }
    v119 = *(_DWORD *)(StatusReg + 1804);
    mutex_lock(v109 + 1232);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: the pid name [%s] of pid [%d] try to open [%s] channel\n",
      "spcom_register_channel",
      (const char *)&unk_F80E,
      (const char *)(StatusReg + 2320),
      v119,
      (const char *)(v109 + 1200));
    if ( *(_QWORD *)(v109 + 1352) )
    {
      if ( (*(_BYTE *)(v109 + 1432) & 1) == 0 )
        goto LABEL_188;
    }
    else
    {
      printk(&unk_11A76, "spcom_register_channel", v109 + 1200);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: channel [%s] is not open\n",
        "spcom_register_channel",
        (const char *)&unk_F80E,
        (const char *)(v109 + 1200));
      if ( (*(_BYTE *)(v109 + 1432) & 1) == 0 )
      {
LABEL_188:
        v120 = *(_DWORD *)(v109 + 1436);
        if ( !v120 )
        {
          v122 = 0;
          goto LABEL_254;
        }
        v121 = *(_DWORD *)(v109 + 1496);
        if ( v121 != v119 )
        {
          if ( v120 == 1 )
          {
            v122 = (v121 != 0) & *(_BYTE *)(v109 + 1433);
LABEL_254:
            v65 = 0;
            v151 = *(_BYTE *)(v109 + 1444) + 1;
            *(_DWORD *)(v109 + 4 * v122 + 1496) = v119;
            *(_BYTE *)(v109 + 1444) = v151;
            *(_BYTE *)(v109 + 1432) = v120 == v151;
LABEL_255:
            mutex_unlock(v109 + 1232);
            v66 = spcom_dev + 58344;
            goto LABEL_94;
          }
          v155 = *(_DWORD *)(v109 + 1500);
          if ( v155 != v119 )
          {
            if ( v120 == 2 )
              goto LABEL_269;
            if ( *(_DWORD *)(v109 + 1504) == v119 )
              goto LABEL_293;
            if ( v120 == 3 )
              goto LABEL_269;
            if ( *(_DWORD *)(v109 + 1508) == v119 )
              goto LABEL_293;
            if ( v120 == 4 )
            {
LABEL_269:
              v122 = 0;
              if ( v121 && (*(_BYTE *)(v109 + 1433) & 1) != 0 )
              {
                v122 = 1;
                if ( v155 )
                  v122 = 2;
                if ( v120 != 2 && v155 )
                {
                  if ( *(_DWORD *)(v109 + 1504) )
                  {
                    if ( v120 == 3 || !*(_DWORD *)(v109 + 1508) )
                    {
                      v122 = 3;
                    }
                    else
                    {
                      if ( v120 != 4 && *(_DWORD *)(v109 + 1512) )
                        goto LABEL_304;
                      v122 = 4;
                    }
                  }
                  else
                  {
                    v122 = 2;
                  }
                }
              }
              goto LABEL_254;
            }
            if ( *(_DWORD *)(v109 + 1512) != v119 )
            {
              if ( v120 != 5 )
              {
LABEL_304:
                __break(0x5512u);
                v157 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v159 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v159 - 4096);
                _WriteStatusReg(TTBR1_EL1, v159);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v157);
                goto LABEL_305;
              }
              goto LABEL_269;
            }
          }
        }
LABEL_293:
        printk(&unk_1074F, "spcom_register_channel", v119);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: client with pid[%d] is already registered with channel[%s]\n",
          "spcom_register_channel",
          (const char *)&unk_F80E,
          v119,
          (const char *)(v109 + 1200));
        v65 = -22;
        goto LABEL_255;
      }
    }
    printk(&unk_12523, "spcom_register_channel", v109 + 1200);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: channel [%s] is occupied by max num of clients [%d]\n",
      "spcom_register_channel",
      (const char *)&unk_F80E,
      (const char *)(v109 + 1200),
      *(unsigned __int8 *)(v109 + 1444));
    v65 = -16;
    goto LABEL_255;
  }
  if ( a2 > -1071098898 )
  {
    if ( a2 > 21490 )
    {
      switch ( a2 )
      {
        case 1075860457:
          mutex_lock(spcom_dev + 58344);
          v62 = spcom_create_channel(string);
          mutex_unlock(spcom_dev + 58344);
          result = v62;
          goto LABEL_314;
        case 21491:
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: SPSS restart command\n",
            "spcom_ioctl_handle_restart_spu_command",
            (const char *)&unk_F80E);
          v147 = rproc_get_by_phandle(bswap32(**(_DWORD **)(*(_QWORD *)(spcom_dev + 58472) + 16LL)));
          *(_QWORD *)(spcom_dev + 58464) = v147;
          if ( v147 )
          {
            v153 = rproc_boot();
            if ( v153 )
            {
              if ( v153 == -110 )
              {
                printk(&unk_F2A3, "spcom_ioctl_handle_restart_spu_command", 4294967186LL);
                ipc_log_string(
                  spcom_ipc_log_context,
                  "%sspcom:%s: FW loading process timeout\n",
                  "spcom_ioctl_handle_restart_spu_command",
                  (const char *)&unk_F80E);
                result = -110;
              }
              else
              {
                *(_DWORD *)(spcom_dev + 58456) = v153;
                printk(&unk_EF3B, "spcom_ioctl_handle_restart_spu_command", v153);
                ipc_log_string(
                  spcom_ipc_log_context,
                  "%sspcom:%s: spss crashed during device bootup rmb_error[0x%x]\n",
                  "spcom_ioctl_handle_restart_spu_command",
                  (const char *)&unk_F80E,
                  *(_DWORD *)(spcom_dev + 58456));
                result = -19;
              }
            }
            else
            {
              printk(&unk_12046, "spcom_ioctl_handle_restart_spu_command", v154);
              ipc_log_string(
                spcom_ipc_log_context,
                "%sspcom:%s: FW loading process is complete\n",
                "spcom_ioctl_handle_restart_spu_command",
                (const char *)&unk_F80E);
              result = 0;
            }
          }
          else
          {
            printk(&unk_10208, "spcom_ioctl_handle_restart_spu_command", v148);
            result = -19;
          }
          goto LABEL_314;
        case 21492:
          printk(&unk_ED9B, "spcom_handle_enable_ssr_command", v14);
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: TBD: SSR is enabled after FOTA\n",
            "spcom_handle_enable_ssr_command",
            (const char *)&unk_F80E);
          result = 0;
          goto LABEL_314;
      }
      goto LABEL_234;
    }
    if ( a2 != -1071098897 )
    {
      if ( a2 != -1071098896 )
        goto LABEL_234;
      v35 = HIDWORD(v163);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: Get message cmd arg: ch_name[%s], timeout_msec [%u], buffer size[%u]\n",
        "spcom_ioctl_handle_get_message",
        (const char *)&unk_F80E,
        string,
        v163,
        HIDWORD(v163));
      if ( !string[0] )
        goto LABEL_212;
      v31 = strnlen(string, 0x20u);
      if ( v31 < 0x48 )
      {
        if ( v31 < 0x20 )
        {
          if ( *(_DWORD *)string == 1868787827 && *(unsigned __int16 *)&string[4] == 109 )
          {
            printk(&unk_10BFD, "spcom_ioctl_handle_get_message", string);
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: cannot send message on management channel %s\n",
              "spcom_ioctl_handle_get_message",
              (const char *)&unk_F80E,
              string);
            result = -14;
            goto LABEL_314;
          }
          v38 = a3 + 40;
          v39 = 32;
          v40 = spcom_dev + 1448;
          while ( strcmp((const char *)(v40 - 248), string) )
          {
            --v39;
            v40 += 1784;
            result = -19;
            if ( !v39 )
              goto LABEL_314;
          }
          result = -19;
          if ( v40 == 248 )
            goto LABEL_314;
          if ( !*(_QWORD *)(v40 - 96) || !*(_QWORD *)(v40 - 88) )
          {
            printk(&unk_10AFC, "spcom_ioctl_handle_get_message", string);
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: ch [%s] remote side not connect\n",
              "spcom_ioctl_handle_get_message",
              (const char *)&unk_F80E,
              string);
            v106 = 0;
            v136 = -107;
            goto LABEL_309;
          }
          if ( v35 >= 0x10D )
          {
            printk(&unk_118E4, "spcom_ioctl_handle_get_message", string);
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: ch [%s] invalid size [%d]\n",
              "spcom_ioctl_handle_get_message",
              (const char *)&unk_F80E,
              string,
              v35);
            v106 = 0;
            v136 = -22;
            goto LABEL_309;
          }
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: waiting for incoming message, ch[%s], size[%u]\n",
            "spcom_ioctl_handle_get_message",
            (const char *)&unk_F80E,
            string,
            v35);
          v104 = v35 + 8;
          v105 = v35 + 8;
          v106 = _kmalloc_noprof(v35 + 8, 3520);
          if ( !v106 )
          {
            v136 = -12;
            goto LABEL_309;
          }
          if ( (*(_BYTE *)(v40 - 164) & 1) != 0 )
          {
            v107 = 0;
          }
          else
          {
            v107 = *(_DWORD *)(v40 - 160);
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: response timeout_msec [%d]\n",
              "spcom_ioctl_handle_get_message",
              (const char *)&unk_F80E,
              v107);
          }
          v136 = spcom_rx(v40 - 248, v106, v104, v107);
          if ( (v136 & 0x80000000) != 0 )
          {
            printk(&unk_1190B, "spcom_ioctl_handle_get_message", v136);
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: rx error %d\n",
              "spcom_ioctl_handle_get_message",
              (const char *)&unk_F80E,
              v136);
            goto LABEL_309;
          }
          if ( *(_BYTE *)(v40 - 164) != 1 )
          {
LABEL_224:
            v138 = v136 - 8;
            if ( v136 <= 8 )
            {
              printk(&unk_10885, "spcom_ioctl_handle_get_message", v136);
              ipc_log_string(
                spcom_ipc_log_context,
                "%sspcom:%s: rx size [%d] too small\n",
                "spcom_ioctl_handle_get_message",
                &unk_F80E,
                v136);
            }
            else
            {
              ipc_log_string(
                spcom_ipc_log_context,
                "%sspcom:%s: copying message to user space, size: [%d]\n",
                "spcom_ioctl_handle_get_message",
                (const char *)&unk_F80E,
                v138);
              v139 = v136 - 8;
              _check_object_size(v106 + 8, v138, 1);
              if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v140 = v38, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
                v140 = v38 & ((__int64)(v38 << 8) >> 8);
              if ( 0x8000000000LL - (unsigned __int64)v138 >= v140 )
              {
                v141 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v143 = *(_QWORD *)(StatusReg + 8);
                _WriteStatusReg(TTBR1_EL1, v143 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
                _WriteStatusReg(TTBR0_EL1, v143);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v141);
                v139 = _arch_copy_to_user(v38 & 0xFF7FFFFFFFFFFFFFLL, v106 + 8, v138);
                v144 = _ReadStatusReg(DAIF);
                __asm { MSR             DAIFSet, #3 }
                v146 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
                _WriteStatusReg(TTBR0_EL1, v146 - 4096);
                _WriteStatusReg(TTBR1_EL1, v146);
                __isb(0xFu);
                _WriteStatusReg(DAIF, v144);
              }
              if ( !v139 )
              {
                ipc_log_string(
                  spcom_ipc_log_context,
                  "%sspcom:%s: get message done, msg size[%d]\n",
                  "spcom_ioctl_handle_get_message",
                  (const char *)&unk_F80E,
                  v138);
                v136 = v138;
LABEL_309:
                if ( *(_DWORD *)(v40 - 8) == *(_DWORD *)(StatusReg + 1804) )
                {
                  *(_DWORD *)(v40 - 8) = 0;
                  mutex_unlock(v40);
                }
                kfree(v106);
                mutex_lock(v40 - 216);
                if ( (*(_BYTE *)(v40 - 164) & 1) == 0 )
                {
                  _pm_relax(*(_QWORD *)(spcom_dev + 1192));
                  ipc_log_string(
                    spcom_ipc_log_context,
                    "%sspcom:%s: ch[%s]:pm_relax() called for server, after tx\n",
                    "spcom_ioctl_handle_get_message",
                    (const char *)&unk_F80E,
                    (const char *)(v40 - 248));
                }
                mutex_unlock(v40 - 216);
                result = (int)v136;
                goto LABEL_314;
              }
              printk(&unk_124F5, "spcom_ioctl_handle_get_message", v139);
              ipc_log_string(
                spcom_ipc_log_context,
                "%sspcom:%s: failed to copy to user, ret [%d]\n",
                "spcom_ioctl_handle_get_message",
                &unk_F80E,
                v139);
            }
            v136 = -14;
            goto LABEL_309;
          }
          if ( (v105 & 0x7FFFFFFC) != 4 )
          {
            v137 = *(_DWORD *)(v106 + 4);
            *(_DWORD *)(v40 - 168) = v137;
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: ch[%s]: request txn_id [0x%x]\n",
              "spcom_ioctl_handle_get_message",
              (const char *)&unk_F80E,
              string,
              v137);
            goto LABEL_224;
          }
          goto LABEL_303;
        }
LABEL_212:
        printk(&unk_1128C, "spcom_ioctl_handle_get_message", v36);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: invalid channel name\n",
          "spcom_ioctl_handle_get_message",
          (const char *)&unk_F80E);
        result = -22;
        goto LABEL_314;
      }
      goto LABEL_301;
    }
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: Get next request msg size cmd arg: ch_name[%s], size[%u], padding[%d]\n",
      "spcom_ioctl_handle_get_next_req_msg_size",
      (const char *)&unk_F80E,
      string,
      v163,
      HIDWORD(v163));
    _W20 = -22;
    if ( !string[0] )
    {
LABEL_200:
      result = _W20;
      goto LABEL_314;
    }
    v31 = strnlen(string, 0x20u);
    if ( v31 < 0x48 )
    {
      _W20 = -22;
      if ( v31 <= 0x1F )
      {
        v73 = a3 + 32;
        v74 = 32;
        v75 = (const char *)(spcom_dev + 1200);
        while ( strcmp(v75, string) )
        {
          --v74;
          v75 += 1784;
          _W20 = -19;
          if ( !v74 )
            goto LABEL_200;
        }
        _W20 = -19;
        if ( v75 )
        {
          _W20 = spcom_get_next_request_size(v75);
          if ( (_W20 & 0x80000000) == 0 )
          {
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: Channel[%s], next request size[%d]\n",
              "spcom_ioctl_handle_get_next_req_msg_size",
              (const char *)&unk_F80E,
              string,
              _W20);
            if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v123 = v73, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
              v123 = v73 & ((__int64)(v73 << 8) >> 8);
            if ( v123 >= 0x7FFFFFFFFDLL )
            {
              _W20 = -14;
              printk(&unk_104C3, "spcom_ioctl_handle_get_next_req_msg_size", 4294967282LL);
              ipc_log_string(
                spcom_ipc_log_context,
                "%sspcom:%s: unable to copy to user [%d]\n",
                "spcom_ioctl_handle_get_next_req_msg_size",
                (const char *)&unk_F80E,
                -14);
            }
            else
            {
              v124 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v126 = *(_QWORD *)(StatusReg + 8);
              _WriteStatusReg(TTBR1_EL1, v126 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v126);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v124);
              __asm { STTR            W20, [X8] }
              v127 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              _W20 = 0;
              v129 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v129 - 4096);
              _WriteStatusReg(TTBR1_EL1, v129);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v127);
            }
          }
        }
      }
      goto LABEL_200;
    }
LABEL_301:
    _fortify_panic(2, 72, v31 + 1);
LABEL_302:
    _fortify_panic(15, v28, v3);
LABEL_303:
    __break(1u);
    goto LABEL_304;
  }
  if ( a2 <= -1073130752 )
  {
    if ( a2 != -2147200011 )
    {
      if ( a2 == -2146938110 )
      {
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v15 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v15 = a3 & ((__int64)(a3 << 8) >> 8);
        result = -14;
        if ( v15 <= 0x7FFFFFFFFCLL )
        {
          _W9 = *(_DWORD *)(spcom_dev + 58456);
          v18 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v23 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v23);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v18);
          __asm { STTR            W9, [X8] }
          uaccess_ttbr0_disable(-14);
          result = 0;
        }
        goto LABEL_314;
      }
LABEL_234:
      printk(&unk_1046F, "spcom_device_ioctl", (unsigned int)a2);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ioctl cmd[%d] is not supported\n",
        "spcom_device_ioctl",
        (const char *)&unk_F80E,
        a2);
      result = -515;
      goto LABEL_314;
    }
    if ( !*(_QWORD *)(spcom_dev + 58464) )
    {
      printk(&unk_10A5A, "spcom_handle_get_crash_cnt_command", v14);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: rproc is null\n",
        "spcom_handle_get_crash_cnt_command",
        (const char *)&unk_F80E);
      result = -19;
      goto LABEL_314;
    }
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v76 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v76 = a3 & ((__int64)(a3 << 8) >> 8);
    if ( v76 < 0x7FFFFFFFFDLL )
    {
      _W9 = *(_DWORD *)(*(_QWORD *)(spcom_dev + 58464) + 1200LL);
      v78 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v80 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v80 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v80);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v78);
      __asm { STTR            W9, [X8] }
      v81 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      result = 0;
      v83 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v83 - 4096);
      _WriteStatusReg(TTBR1_EL1, v83);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v81);
      goto LABEL_314;
    }
LABEL_305:
    printk(&unk_EBF0, "spcom_handle_get_crash_cnt_command", v14);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: unable to copy crash count to user\n",
      "spcom_handle_get_crash_cnt_command",
      (const char *)&unk_F80E);
    result = -14;
    goto LABEL_314;
  }
  if ( a2 == -1073130751 )
  {
    v84 = "unknown";
    if ( a1 )
    {
      v85 = *(_QWORD *)(a1 + 72);
      if ( v85 )
        v84 = (const char *)(v85 + 56);
    }
    if ( *(_DWORD *)&string[1] == 1 )
    {
      if ( !strcmp(v84, "spcom") )
      {
        printk(&unk_F8DD, "handle_poll", v84);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: invalid control device: %s\n",
          "handle_poll",
          (const char *)&unk_F80E,
          v84);
        result = -22;
        goto LABEL_314;
      }
      v103 = *(_QWORD *)(a1 + 32);
      if ( !v103 )
      {
        printk(&unk_10E4D, "handle_poll", v84);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: invalid ch pointer, file [%s]\n",
          "handle_poll",
          (const char *)&unk_F80E,
          v84);
        result = -22;
        goto LABEL_314;
      }
      if ( string[0] == 1 )
      {
        *(_DWORD *)(v103 + 200) = 0;
        v88 = wait_for_completion_interruptible(v103 + 200);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: ch [%s] connect signaled\n",
          "handle_poll",
          (const char *)&unk_F80E,
          v84);
      }
      else
      {
        v88 = 0;
      }
      mutex_lock(v103 + 32);
      *(_DWORD *)&string[5] = *(_QWORD *)(v103 + 160) != 0;
      mutex_unlock(v103 + 32);
    }
    else
    {
      if ( *(_DWORD *)&string[1] )
      {
        printk(&unk_10D7E, "handle_poll", v84);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: ch [%s] unsupported ioctl:%u\n",
          "handle_poll",
          (const char *)&unk_F80E,
          v84,
          *(_DWORD *)&string[1]);
        result = -22;
        goto LABEL_314;
      }
      v86 = spcom_dev;
      if ( string[0] == 1 )
      {
        v87 = spcom_dev + 58392;
        *(_DWORD *)(spcom_dev + 58392) = 0;
        v88 = wait_for_completion_interruptible(v87);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: ch [%s] link state change signaled\n",
          "handle_poll",
          (const char *)&unk_F80E,
          v84);
        v86 = spcom_dev;
      }
      else
      {
        v88 = 0;
      }
      *(_DWORD *)&string[5] = *(_DWORD *)(v86 + 58424) > 0;
    }
    if ( v88 < 0 )
    {
      printk(&unk_1049B, "handle_poll", *(unsigned int *)&string[5]);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: interrupted wait retval=%d\n",
        "handle_poll",
        (const char *)&unk_F80E,
        *(_DWORD *)&string[5]);
      result = -4;
    }
    else
    {
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v110 = a3 + 5, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v110 = (a3 + 5) & ((__int64)((a3 + 5) << 8) >> 8);
      if ( v110 >= 0x7FFFFFFFFDLL )
      {
        printk(&unk_127C9, "handle_poll", 4294967282LL);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: Unable to copy link state to user [%d]\n",
          "handle_poll",
          (const char *)&unk_F80E,
          -14);
        result = -14;
      }
      else
      {
        _W9 = *(_DWORD *)&string[5];
        v112 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v114 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v114 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v114);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v112);
        __asm { STTR            W9, [X8] }
        v115 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        result = 0;
        v117 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v117 - 4096);
        _WriteStatusReg(TTBR1_EL1, v117);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v115);
      }
    }
  }
  else
  {
    if ( a2 != -1072671768 )
      goto LABEL_234;
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: Handle poll event cmd args: event_id[%d], wait[%u], retval[%d], padding[%d]\n",
      "spcom_ioctl_handle_poll_event",
      (const char *)&unk_F80E,
      *(_DWORD *)string,
      *(_DWORD *)&string[4],
      *(_DWORD *)&string[8],
      *(_DWORD *)&string[12]);
    if ( *(_DWORD *)string == 100 )
    {
      if ( *(_DWORD *)&string[4]
        && (v51 = spcom_dev + 58392,
            *(_DWORD *)(spcom_dev + 58392) = 0,
            (v52 = wait_for_completion_interruptible(v51)) != 0) )
      {
        v152 = v52;
        printk(&unk_12EC0, "spcom_ioctl_handle_poll_event", v52);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: Wait for link state change interrupted, ret[%d], pid: %d\n",
          "spcom_ioctl_handle_poll_event",
          (const char *)&unk_F80E,
          v152,
          *(_DWORD *)(StatusReg + 1804));
        result = -4;
      }
      else
      {
        v53 = a3 + 8;
        _W19 = *(_DWORD *)(spcom_dev + 58424) > 0;
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: SPCOM link state change: Signaled [%d], PID [%d]\n",
          "spcom_ioctl_handle_poll_event",
          &unk_F80E,
          *(_DWORD *)(spcom_dev + 58424) > 0,
          *(unsigned int *)(StatusReg + 1804));
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v55 = v53, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v55 = v53 & ((__int64)(v53 << 8) >> 8);
        if ( v55 >= 0x7FFFFFFFFDLL )
        {
          printk(&unk_FE4F, "spcom_ioctl_handle_poll_event", 4294967282LL);
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: unable to copy link state to user [%d]\n",
            "spcom_ioctl_handle_poll_event",
            (const char *)&unk_F80E,
            -14);
          result = -14;
        }
        else
        {
          v56 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v58 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v58 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v58);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v56);
          __asm { STTR            W19, [X8] }
          v59 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          result = 0;
          v61 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v61 - 4096);
          _WriteStatusReg(TTBR1_EL1, v61);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v59);
        }
      }
    }
    else
    {
      printk(&unk_EB8E, "spcom_ioctl_handle_poll_event", *(unsigned int *)string);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: SPCOM handle poll unsupported event id [%u]\n",
        "spcom_ioctl_handle_poll_event",
        (const char *)&unk_F80E,
        *(_DWORD *)string);
      result = -22;
    }
  }
LABEL_314:
  _ReadStatusReg(SP_EL0);
  return result;
}
