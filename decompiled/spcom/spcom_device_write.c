unsigned __int64 __fastcall spcom_device_write(__int64 a1, size_t a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  size_t v5; // x22
  const char *v7; // x23
  unsigned __int64 v8; // x21
  __int64 v9; // x2
  __int64 v10; // x20
  __int64 v11; // x2
  unsigned int *v12; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v14; // x9
  size_t v15; // x23
  size_t v16; // x1
  unsigned __int64 v17; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  __int64 v27; // x2
  unsigned int v28; // w24
  unsigned int v29; // w25
  int channel_chardev; // w22
  unsigned int v31; // w22
  unsigned __int64 v32; // x0
  __int64 v33; // x2
  const void *v34; // x23
  __int64 i; // x8
  __int64 v36; // x5
  _QWORD *v37; // x8
  unsigned __int64 v38; // x0
  unsigned __int64 v39; // x23
  __int64 j; // x22
  unsigned int v41; // w25
  unsigned int v42; // w26
  _DWORD *v43; // x24
  unsigned int v44; // w28
  __int64 v45; // x8
  int v46; // w8
  int v47; // w8
  unsigned __int64 v48; // x1
  unsigned int v49; // w26
  int v50; // w8
  int v51; // w8
  unsigned int v52; // w28
  __int64 v53; // x0
  __int64 v54; // x2
  unsigned int v55; // w0
  __int64 v56; // x2
  const char *v57; // x21
  const char *v58; // x21
  __int64 v59; // x2
  unsigned __int64 v60; // x23
  __int64 v61; // x24
  unsigned int v63; // [xsp+Ch] [xbp-34h]
  unsigned int v64; // [xsp+10h] [xbp-30h]
  unsigned int v65; // [xsp+14h] [xbp-2Ch]
  unsigned int v66; // [xsp+18h] [xbp-28h]
  unsigned int v67; // [xsp+1Ch] [xbp-24h]
  unsigned int v68; // [xsp+20h] [xbp-20h]
  unsigned int v69; // [xsp+24h] [xbp-1Ch]
  unsigned int v70; // [xsp+28h] [xbp-18h]
  _QWORD v71[2]; // [xsp+30h] [xbp-10h] BYREF

  v71[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || ((v4 = *(_QWORD *)(a1 + 72), v5 = a2, v4) ? (v7 = (const char *)(v4 + 56)) : (v7 = "unknown"), !a2 || !a4) )
  {
    printk(&unk_FBA0, "spcom_device_write", a3);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: invalid null parameters\n", "spcom_device_write", &unk_F80E);
LABEL_112:
    v8 = -22;
    goto LABEL_219;
  }
  if ( *(_DWORD *)(spcom_dev + 58428) )
  {
    printk(&unk_1146C, "spcom_device_write", a3);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: module remove in progress\n",
      "spcom_device_write",
      (const char *)&unk_F80E);
    v8 = -19;
    goto LABEL_219;
  }
  if ( *a4 )
  {
    printk(&unk_FBC5, "spcom_device_write", a3);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: offset should be zero, no sparse buffer\n",
      "spcom_device_write",
      &unk_F80E);
    goto LABEL_112;
  }
  if ( !v7 )
  {
    printk(&unk_F6F0, "spcom_device_write", a3);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: name is NULL\n", "spcom_device_write", &unk_F80E);
    goto LABEL_112;
  }
  v8 = a3;
  if ( !strcmp(v7, "unknown") )
  {
    printk(&unk_118C7, "spcom_device_write", v9);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: name is unknown\n", "spcom_device_write", &unk_F80E);
    goto LABEL_112;
  }
  if ( v8 > 0x1000 )
  {
    printk(&unk_F1BF, "spcom_device_write", (unsigned int)v8);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: size [%d] > max size [%d]\n",
      "spcom_device_write",
      (const char *)&unk_F80E,
      v8,
      4096);
    v8 = -22;
    goto LABEL_219;
  }
  v10 = *(_QWORD *)(a1 + 32);
  if ( !v10 && strcmp(v7, "spcom") )
  {
    printk(&unk_EA64, "spcom_device_write", v11);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: NULL ch, command not allowed\n", "spcom_device_write", &unk_F80E);
    goto LABEL_112;
  }
  v12 = (unsigned int *)_kmalloc_noprof(v8, 3520);
  if ( !v12 )
  {
LABEL_210:
    v8 = -12;
    goto LABEL_219;
  }
  while ( 1 )
  {
    _check_object_size(v12, v8, 0);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = v5, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v14 = v5 & ((__int64)(v5 << 8) >> 8);
    v15 = v8;
    if ( 0x8000000000LL - v8 < v14 )
      goto LABEL_19;
    v17 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v23 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v23);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v17);
    v15 = _arch_copy_from_user(v12, v5 & 0xFF7FFFFFFFFFFFFFLL, v8);
    v24 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v26 - 4096);
    _WriteStatusReg(TTBR1_EL1, v26);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v24);
    if ( v15 )
    {
LABEL_19:
      if ( v8 >= v15 )
        v16 = v15;
      else
        v16 = 0;
      if ( v16 < v15 )
        goto LABEL_207;
      memset((char *)v12 + v8 - v15, 0, v15);
      if ( (_DWORD)v15 )
      {
        printk(&unk_10CF2, "spcom_device_write", (unsigned int)v15);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: Unable to copy from user (err %d)\n",
          "spcom_device_write",
          (const char *)&unk_F80E,
          v15);
        kfree(v12);
        v8 = -14;
        goto LABEL_219;
      }
    }
    if ( (unsigned int)v8 <= 7 )
    {
      printk(&unk_FD48, "spcom_handle_write", (unsigned int)v8);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: Command buffer size [%d] too small\n",
        "spcom_handle_write",
        &unk_F80E,
        (unsigned int)v8);
      goto LABEL_186;
    }
    v5 = *v12;
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: cmd_id [0x%x]\n",
      "spcom_handle_write",
      (const char *)&unk_F80E,
      *v12);
    if ( !v10 )
    {
      if ( (_DWORD)v5 == 1129465172 )
      {
LABEL_54:
        if ( (_DWORD)v8 != 37 )
        {
          printk(&unk_F860, "spcom_handle_create_channel_command", (unsigned int)v8);
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: cmd_size [%d] , expected [%d]\n",
            "spcom_handle_create_channel_command",
            &unk_F80E,
            (unsigned int)v8,
            37);
          goto LABEL_179;
        }
        mutex_lock(spcom_dev + 58296);
        channel_chardev = spcom_create_channel_chardev(v12 + 1, *((unsigned __int8 *)v12 + 36));
        mutex_unlock(spcom_dev + 58296);
        if ( channel_chardev )
        {
          if ( channel_chardev != -22 )
          {
            printk(&unk_F252, "spcom_handle_create_channel_command", v12 + 1);
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: failed to create ch[%s], ret [%d]\n",
              "spcom_handle_create_channel_command",
              (const char *)&unk_F80E,
              (const char *)v12 + 4,
              channel_chardev);
            goto LABEL_213;
          }
          channel_chardev = -22;
          printk(&unk_F88B, "spcom_handle_create_channel_command", 4294967274LL);
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: failed to create channel, ret [%d]\n",
            "spcom_handle_create_channel_command",
            (const char *)&unk_F80E,
            -22);
          goto LABEL_215;
        }
LABEL_214:
        kfree(v12);
        goto LABEL_219;
      }
      if ( (_DWORD)v5 == 1163088722 )
      {
LABEL_170:
        printk(&unk_ED9B, "spcom_handle_enable_ssr_command", v27);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: TBD: SSR is enabled after FOTA\n",
          "spcom_handle_enable_ssr_command",
          &unk_F80E);
        goto LABEL_214;
      }
      if ( (_DWORD)v5 != 1381192786 )
      {
        printk(&unk_126A6, "spcom_handle_write", v27);
        ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: channel context is null\n", "spcom_handle_write", &unk_F80E);
        goto LABEL_190;
      }
LABEL_172:
      if ( (_DWORD)v8 != 12 )
      {
        printk(&unk_F860, "spcom_handle_restart_sp_command", (unsigned int)v8);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: cmd_size [%d] , expected [%d]\n",
          "spcom_handle_restart_sp_command",
          &unk_F80E,
          (unsigned int)v8,
          12);
        goto LABEL_179;
      }
      v53 = rproc_get_by_phandle(bswap32(**(_DWORD **)(*(_QWORD *)(spcom_dev + 58472) + 16LL)));
      *(_QWORD *)(spcom_dev + 58464) = v53;
      if ( !v53 )
      {
        printk(&unk_10208, "spcom_handle_restart_sp_command", v54);
        channel_chardev = -19;
        goto LABEL_215;
      }
      v55 = rproc_boot();
      if ( v55 )
      {
        if ( v55 == -110 )
        {
          printk(&unk_F2A3, "spcom_handle_restart_sp_command", 4294967186LL);
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: FW loading process timeout\n",
            "spcom_handle_restart_sp_command",
            (const char *)&unk_F80E);
          channel_chardev = -110;
        }
        else
        {
          *(_DWORD *)(spcom_dev + 58456) = v55;
          printk(&unk_EF3B, "spcom_handle_restart_sp_command", v55);
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: spss crashed during device bootup rmb_error[0x%x]\n",
            "spcom_handle_restart_sp_command",
            (const char *)&unk_F80E,
            *(_DWORD *)(spcom_dev + 58456));
          channel_chardev = -19;
        }
        goto LABEL_215;
      }
      printk(&unk_12046, "spcom_handle_restart_sp_command", v56);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: FW loading process is complete\n",
        "spcom_handle_restart_sp_command",
        &unk_F80E);
      goto LABEL_214;
    }
    if ( (int)v5 <= 1397050947 )
    {
      if ( (int)v5 <= 1280262986 )
      {
        if ( (_DWORD)v5 == 1129465172 )
          goto LABEL_54;
        if ( (_DWORD)v5 == 1163088722 )
          goto LABEL_170;
LABEL_175:
        printk(&unk_1034B, "spcom_handle_write", *v12);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: Invalid Command Id [0x%x]\n",
          "spcom_handle_write",
          &unk_F80E,
          *v12);
        goto LABEL_186;
      }
      if ( (_DWORD)v5 == 1280262987 )
      {
        if ( (_DWORD)v8 != 8 )
        {
          printk(&unk_105C2, "spcom_handle_lock_ion_buf_command", (unsigned int)v8);
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: cmd size [%d] , expected [%d]\n",
            "spcom_handle_lock_ion_buf_command",
            &unk_F80E,
            (unsigned int)v8,
            8);
          goto LABEL_179;
        }
        v31 = v12[1];
        if ( (v31 & 0x80000000) != 0 )
        {
          v57 = "spcom_handle_lock_ion_buf_command";
          goto LABEL_185;
        }
        v32 = dma_buf_get(v31);
        if ( v32 )
        {
          v34 = (const void *)v32;
          if ( v32 < 0xFFFFFFFFFFFFF001LL )
          {
            mutex_lock(v10 + 32);
            for ( i = 352; i != 1792; i += 40 )
            {
              if ( *(const void **)(v10 + i) == v34 )
              {
                ipc_log_string(
                  spcom_ipc_log_context,
                  "%sspcom:%s: fd [%d] shared buf is already locked\n",
                  "spcom_handle_lock_ion_buf_command",
                  (const char *)&unk_F80E,
                  v31);
                mutex_unlock(v10 + 32);
                dma_buf_put(v34);
                channel_chardev = -22;
                goto LABEL_215;
              }
            }
            v36 = 0;
            v37 = (_QWORD *)(v10 + 352);
            while ( *v37 )
            {
              ++v36;
              v37 += 5;
              if ( v36 == 36 )
              {
                mutex_unlock(v10 + 32);
                dma_buf_put(v34);
                printk(&unk_FA57, "spcom_handle_lock_ion_buf_command", v31);
                ipc_log_string(
                  spcom_ipc_log_context,
                  "%sspcom:%s: no free entry to store ion handle of fd [%d]\n",
                  "spcom_handle_lock_ion_buf_command",
                  (const char *)&unk_F80E,
                  v31);
                channel_chardev = -14;
                goto LABEL_215;
              }
            }
            *v37 = v34;
            *((_DWORD *)v37 - 2) = v31;
            ipc_log_string(
              spcom_ipc_log_context,
              "%sspcom:%s: ch [%s] locked ion buf #%d fd [%d] dma_buf=0x%pK\n",
              "spcom_handle_lock_ion_buf_command",
              (const char *)&unk_F80E,
              (const char *)v10,
              v36,
              v31,
              v34);
            goto LABEL_110;
          }
        }
        v58 = "spcom_handle_lock_ion_buf_command";
LABEL_189:
        printk(&unk_111CB, v58, v33);
        ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: fail to get dma buf handle\n", v58, &unk_F80E);
LABEL_190:
        channel_chardev = -22;
        goto LABEL_215;
      }
      if ( (_DWORD)v5 != 1381192786 )
        goto LABEL_175;
      goto LABEL_172;
    }
    if ( (_DWORD)v5 == 1397050948 )
      goto LABEL_32;
    if ( (_DWORD)v5 == 1431061323 )
    {
      if ( (_DWORD)v8 == 8 )
      {
        v31 = v12[1];
        if ( (v31 & 0x80000000) == 0 )
        {
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: Unlock ion buf ch [%s] fd [%d]\n",
            "spcom_handle_unlock_ion_buf_command",
            (const char *)&unk_F80E,
            (const char *)v10,
            v31);
          v38 = dma_buf_get(v31);
          if ( v38 )
          {
            v39 = v38;
            if ( v38 < 0xFFFFFFFFFFFFF001LL )
            {
              dma_buf_put(v38);
              mutex_lock(v10 + 32);
              if ( v31 == 0xFFFF )
              {
                ipc_log_string(
                  spcom_ipc_log_context,
                  "%sspcom:%s: unlocked ALL ion buf ch [%s]\n",
                  "spcom_handle_unlock_ion_buf_command",
                  (const char *)&unk_F80E,
                  (const char *)v10);
                for ( j = 344; j != 1784; j += 40 )
                  spcom_dmabuf_unlock(v10 + j, 1);
              }
              else
              {
                v45 = 0;
                while ( *(_QWORD *)(v10 + v45 + 352) != v39 )
                {
                  v45 += 40;
                  if ( v45 == 1440 )
                  {
                    mutex_unlock(v10 + 32);
                    printk(&unk_ECF7, "spcom_handle_unlock_ion_buf_command", v10);
                    ipc_log_string(
                      spcom_ipc_log_context,
                      "%sspcom:%s: ch [%s] fd [%d] was not found\n",
                      "spcom_handle_unlock_ion_buf_command",
                      (const char *)&unk_F80E,
                      (const char *)v10,
                      v31);
                    channel_chardev = -19;
                    goto LABEL_215;
                  }
                }
                spcom_dmabuf_unlock(v10 + v45 + 344, 1);
              }
LABEL_110:
              mutex_unlock(v10 + 32);
              goto LABEL_214;
            }
          }
          v58 = "spcom_handle_unlock_ion_buf_command";
          goto LABEL_189;
        }
        v57 = "spcom_handle_unlock_ion_buf_command";
LABEL_185:
        printk(&unk_10F4B, v57, v31);
        ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: int overflow [%u]\n", v57, &unk_F80E, v12[1]);
LABEL_186:
        channel_chardev = -22;
        goto LABEL_215;
      }
      printk(&unk_12BE5, "spcom_handle_unlock_ion_buf_command", (unsigned int)v8);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: cmd size [%d], expected [%d]\n",
        "spcom_handle_unlock_ion_buf_command",
        &unk_F80E,
        (unsigned int)v8,
        8);
LABEL_179:
      channel_chardev = -22;
      goto LABEL_215;
    }
    if ( (_DWORD)v5 != 1397638221 )
      goto LABEL_175;
LABEL_32:
    if ( !*(_QWORD *)(v10 + 152) || !*(_QWORD *)(v10 + 160) )
    {
      printk(&unk_108D0, "spcom_handle_write", v10);
      goto LABEL_167;
    }
    if ( (_DWORD)v5 != 1397638221 )
      break;
    if ( *(_BYTE *)(v10 + 233) == 1 )
    {
      mutex_lock(v10 + 248);
      *(_DWORD *)(v10 + 240) = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1804);
    }
    v71[0] = 0;
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: send req/resp ch [%s] size [%d]\n",
      "spcom_handle_send_modified_command",
      (const char *)&unk_F80E,
      (const char *)v10,
      v8);
    if ( (unsigned int)v8 <= 0x2B )
    {
      printk(&unk_11BB0, "spcom_handle_send_modified_command", v10);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] invalid cmd buf\n",
        "spcom_handle_send_modified_command",
        (const char *)&unk_F80E,
        (const char *)v10);
      channel_chardev = -22;
      goto LABEL_213;
    }
    if ( !*(_QWORD *)(v10 + 152) || !*(_QWORD *)(v10 + 160) )
    {
      printk(&unk_10AFC, "spcom_handle_send_modified_command", v10);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] remote side not connect\n",
        "spcom_handle_send_modified_command",
        (const char *)&unk_F80E,
        (const char *)v10);
      channel_chardev = -107;
      goto LABEL_213;
    }
    if ( (v8 & 0x1FFC) == 0x28
      || (v8 & 0x1FFC) == 0x24
      || (v8 & 0x1FFC) == 4
      || (v8 & 0x1FFC) == 8
      || (v8 & 0x1FFC) == 0xC
      || (v8 & 0x1FFC) == 0x10
      || (v8 & 0x1FFC) == 0x14
      || (v8 & 0x1FFC) == 0x18
      || (v8 & 0x1FFC) == 0x1C
      || (v8 & 0x1FFC) == 0x20 )
    {
LABEL_206:
      __break(1u);
LABEL_207:
      _fortify_panic(15, v16, v15);
LABEL_208:
      _fortify_panic(17, v48, v5);
      goto LABEL_209;
    }
    v5 = v12[10];
    if ( (unsigned int)v5 >= 0x10D )
    {
      printk(&unk_FF75, "spcom_handle_send_modified_command", v10);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] invalid buf size [%d]\n",
        "spcom_handle_send_modified_command",
        &unk_F80E,
        v10,
        (unsigned int)v5);
LABEL_199:
      channel_chardev = -22;
      goto LABEL_213;
    }
    if ( v5 + 44 != v8 )
    {
      printk(&unk_F1E6, "spcom_handle_send_modified_command", v10);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] invalid cmd size [%d]\n",
        "spcom_handle_send_modified_command",
        &unk_F80E,
        v10,
        (unsigned int)v8);
      goto LABEL_199;
    }
    v41 = v5 + 8;
    v69 = v12[1];
    v66 = v12[2];
    v70 = v12[3];
    v64 = v12[6];
    v65 = v12[4];
    v67 = v12[7];
    v68 = v12[5];
    v42 = v12[9];
    v63 = v12[8];
    v15 = (unsigned int)(v5 + 8);
    v43 = (_DWORD *)_kmalloc_noprof(v15, 3520);
    if ( !v43 )
    {
      channel_chardev = -12;
      goto LABEL_213;
    }
    mutex_lock(v10 + 32);
    if ( *(_BYTE *)(v10 + 85) == 1 )
    {
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] send first -> it is client\n",
        "spcom_handle_send_modified_command",
        (const char *)&unk_F80E,
        (const char *)v10);
      v44 = v70;
      *(_WORD *)(v10 + 84) = 0;
LABEL_138:
      v51 = *(_DWORD *)(v10 + 80);
      *(_DWORD *)(v10 + 88) = v42;
      v50 = v51 + 1;
      *(_DWORD *)(v10 + 80) = v50;
      goto LABEL_139;
    }
    v44 = v70;
    if ( (*(_BYTE *)(v10 + 84) & 1) == 0 )
      goto LABEL_138;
    v50 = *(_DWORD *)(v10 + 80);
LABEL_139:
    if ( (v15 & 0x7FFFFFFC) == 4 )
      goto LABEL_206;
    v48 = v41 - 8LL;
    v43[1] = v50;
    if ( v48 < v5 )
      goto LABEL_208;
    if ( v8 - 44 >= v5 )
    {
      if ( (_DWORD)v5 && v41 != 8 && (spcom_handle_send_modified_command___already_done_129 & 1) == 0 )
      {
        spcom_handle_send_modified_command___already_done_129 = 1;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v5,
          "field \"hdr->buf\" at ../vendor/qcom/opensource/spu-kernel/drivers/spcom.c:1072",
          0);
        __break(0x800u);
      }
      memcpy(v43 + 2, v12 + 11, v5);
      if ( (v69 & 0x80000000) == 0
        && (v71[0] = __PAIR64__(v66, v69), (modify_dma_buf_addr(v10, v43 + 2, (unsigned int)v5, v71) & 0x80000000) != 0)
        || (v44 & 0x80000000) == 0
        && (v71[0] = __PAIR64__(v65, v44), (modify_dma_buf_addr(v10, v43 + 2, (unsigned int)v5, v71) & 0x80000000) != 0)
        || (v68 & 0x80000000) == 0
        && (v71[0] = __PAIR64__(v64, v68), (modify_dma_buf_addr(v10, v43 + 2, (unsigned int)v5, v71) & 0x80000000) != 0)
        || (v67 & 0x80000000) == 0
        && (v71[0] = __PAIR64__(v63, v67), (modify_dma_buf_addr(v10, v43 + 2, (unsigned int)v5, v71) & 0x80000000) != 0) )
      {
        mutex_unlock(v10 + 32);
        memset(v43, 0, v41);
        kfree(v43);
        channel_chardev = -14;
      }
      else
      {
        v52 = 0;
        while ( *(_BYTE *)(v10 + 316) != 1 )
        {
          channel_chardev = rpmsg_trysend(*(_QWORD *)(*(_QWORD *)(v10 + 160) + 968LL), v43, v41);
          if ( !channel_chardev )
            goto LABEL_163;
          mutex_unlock(v10 + 32);
          msleep(100);
          mutex_lock(v10 + 32);
          if ( channel_chardev == -11 || channel_chardev == -16 )
          {
            v52 += 100;
            if ( v52 < v42 )
              continue;
          }
          goto LABEL_205;
        }
        printk(&unk_126CB, "spcom_handle_send_modified_command", v10);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: ch[%s]: aborted, txn_id=%d\n",
          "spcom_handle_send_modified_command",
          (const char *)&unk_F80E,
          (const char *)v10,
          *(_DWORD *)(v10 + 80));
        channel_chardev = -125;
LABEL_205:
        printk(&unk_F211, "spcom_handle_send_modified_command", v10);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: ch [%s] rpmsg_trysend() error (%d), timeout_msec=%d\n",
          "spcom_handle_send_modified_command",
          (const char *)&unk_F80E,
          (const char *)v10,
          channel_chardev,
          v42);
LABEL_163:
        if ( *(_BYTE *)(v10 + 84) == 1 )
        {
          _pm_relax(*(_QWORD *)(spcom_dev + 1192));
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: ch[%s]:pm_relax() called for server, after tx\n",
            "spcom_handle_send_modified_command",
            (const char *)&unk_F80E,
            (const char *)v10);
        }
        mutex_unlock(v10 + 32);
        memset(v43, 0, v41);
        kfree(v43);
      }
LABEL_213:
      if ( channel_chardev )
        goto LABEL_215;
      goto LABEL_214;
    }
LABEL_209:
    _fortify_panic(16, v48, v5);
    _fortify_panic(15, v15, v59);
    v60 = _ReadStatusReg(SP_EL0);
    v61 = *(_QWORD *)(v60 + 80);
    *(_QWORD *)(v60 + 80) = &spcom_device_write__alloc_tag;
    v12 = (unsigned int *)_kmalloc_noprof(v8, 3520);
    *(_QWORD *)(v60 + 80) = v61;
    if ( !v12 )
      goto LABEL_210;
  }
  if ( *(_BYTE *)(v10 + 233) == 1 )
  {
    mutex_lock(v10 + 248);
    *(_DWORD *)(v10 + 240) = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1804);
  }
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: send req/resp ch [%s] size [%d]\n",
    "spcom_handle_send_command",
    (const char *)&unk_F80E,
    (const char *)v10,
    v8);
  if ( (unsigned int)v8 <= 0xB )
  {
    printk(&unk_11BB0, "spcom_handle_send_command", v10);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch [%s] invalid cmd buf\n",
      "spcom_handle_send_command",
      (const char *)&unk_F80E,
      (const char *)v10);
    channel_chardev = -22;
    goto LABEL_215;
  }
  if ( *(_QWORD *)(v10 + 152) && *(_QWORD *)(v10 + 160) )
  {
    if ( (v8 & 0x1FFC) == 8 || (v8 & 0x1FFC) == 4 )
      goto LABEL_206;
    v5 = v12[2];
    if ( (unsigned int)v5 >= 0x10D )
    {
      printk(&unk_FF75, "spcom_handle_send_command", v10);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] invalid buf size [%d]\n",
        "spcom_handle_send_command",
        &unk_F80E,
        v10,
        (unsigned int)v5);
LABEL_197:
      channel_chardev = -22;
      goto LABEL_215;
    }
    if ( v5 + 12 != v8 )
    {
      printk(&unk_F1E6, "spcom_handle_send_command", v10);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] invalid cmd size [%d]\n",
        "spcom_handle_send_command",
        &unk_F80E,
        v10,
        (unsigned int)v8);
      goto LABEL_197;
    }
    v28 = v12[1];
    v29 = v5 + 8;
    v15 = _kmalloc_noprof((unsigned int)(v5 + 8), 3520);
    if ( !v15 )
    {
      channel_chardev = -12;
      goto LABEL_215;
    }
    mutex_lock(v10 + 32);
    if ( *(_BYTE *)(v10 + 85) == 1 )
    {
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] send first -> it is client\n",
        "spcom_handle_send_command",
        (const char *)&unk_F80E,
        (const char *)v10);
      *(_WORD *)(v10 + 84) = 0;
      goto LABEL_115;
    }
    if ( (*(_BYTE *)(v10 + 84) & 1) != 0 )
    {
      v46 = *(_DWORD *)(v10 + 80);
    }
    else
    {
LABEL_115:
      v47 = *(_DWORD *)(v10 + 80);
      *(_DWORD *)(v10 + 88) = v28;
      v46 = v47 + 1;
      *(_DWORD *)(v10 + 80) = v46;
    }
    if ( (((_DWORD)v5 + 8) & 0x7FFFFFFC) == 4 )
      goto LABEL_206;
    v48 = v29 - 8LL;
    *(_DWORD *)(v15 + 4) = v46;
    if ( v48 < v5 )
      goto LABEL_208;
    if ( v8 - 12 >= v5 )
    {
      if ( (_DWORD)v5 && v29 != 8 && (spcom_handle_send_command___already_done & 1) == 0 )
      {
        spcom_handle_send_command___already_done = 1;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v5,
          "field \"hdr->buf\" at ../vendor/qcom/opensource/spu-kernel/drivers/spcom.c:825",
          0);
        __break(0x800u);
      }
      memcpy((void *)(v15 + 8), v12 + 3, v5);
      v49 = 0;
      while ( *(_BYTE *)(v10 + 316) != 1 )
      {
        channel_chardev = rpmsg_trysend(*(_QWORD *)(*(_QWORD *)(v10 + 160) + 968LL), v15, v29);
        if ( !channel_chardev )
        {
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: ch[%s]: successfully sent txn_id=%d\n",
            "spcom_handle_send_command",
            (const char *)&unk_F80E,
            (const char *)v10,
            *(_DWORD *)(v10 + 80));
          goto LABEL_131;
        }
        mutex_unlock(v10 + 32);
        msleep(100);
        mutex_lock(v10 + 32);
        if ( channel_chardev == -11 || channel_chardev == -16 )
        {
          v49 += 100;
          if ( v49 < v28 )
            continue;
        }
        goto LABEL_201;
      }
      printk(&unk_114B0, "spcom_handle_send_command", v10);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] aborted\n",
        "spcom_handle_send_command",
        (const char *)&unk_F80E,
        (const char *)v10);
      channel_chardev = -125;
LABEL_201:
      printk(&unk_F211, "spcom_handle_send_command", v10);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] rpmsg_trysend() error (%d), timeout_msec=%d\n",
        "spcom_handle_send_command",
        (const char *)&unk_F80E,
        (const char *)v10,
        channel_chardev,
        v28);
LABEL_131:
      if ( *(_BYTE *)(v10 + 84) == 1 )
      {
        _pm_relax(*(_QWORD *)(spcom_dev + 1192));
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: ch[%s]:pm_relax() called for server, after tx\n",
          "spcom_handle_send_command",
          (const char *)&unk_F80E,
          (const char *)v10);
      }
      mutex_unlock(v10 + 32);
      kfree(v15);
      goto LABEL_213;
    }
    goto LABEL_209;
  }
  printk(&unk_10AFC, "spcom_handle_send_command", v10);
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: ch [%s] remote side not connect\n",
    "spcom_handle_send_command",
    (const char *)&unk_F80E,
    (const char *)v10);
LABEL_167:
  channel_chardev = -107;
LABEL_215:
  printk(&unk_121E4, "spcom_device_write", (unsigned int)channel_chardev);
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: handle command error [%d]\n",
    "spcom_device_write",
    (const char *)&unk_F80E,
    channel_chardev);
  kfree(v12);
  if ( v10 && *(_DWORD *)(v10 + 240) == *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1804) )
  {
    *(_DWORD *)(v10 + 240) = 0;
    mutex_unlock(v10 + 248);
  }
  v8 = channel_chardev;
LABEL_219:
  _ReadStatusReg(SP_EL0);
  return v8;
}
