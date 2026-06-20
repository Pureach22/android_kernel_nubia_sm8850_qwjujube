__int64 __fastcall ipa3_uc_send_cmd_64b_param(int a1, int a2, int a3, int a4, int a5, __int64 a6)
{
  int v9; // w23
  int v10; // w25
  __int64 v11; // x8
  _QWORD *v12; // x9
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 v17; // x0
  __int64 v18; // x2
  int v19; // w24
  __int64 v20; // x21
  int v21; // w23
  int v22; // w10
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned int v28; // w28
  const char *v29; // x0
  const char *v30; // x4
  __int64 v31; // x8
  unsigned int v32; // w4
  __int64 v33; // x0
  unsigned int v34; // w28
  const char *v35; // x0
  const char *v36; // x4
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 result; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  int v51; // w20
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // [xsp+8h] [xbp-38h]
  __int64 v55; // [xsp+8h] [xbp-38h]
  int v56; // [xsp+14h] [xbp-2Ch]
  __int64 v57; // [xsp+18h] [xbp-28h]
  int v60; // [xsp+30h] [xbp-10h]
  __int64 v61; // [xsp+30h] [xbp-10h]
  __int64 v62; // [xsp+30h] [xbp-10h]

  v9 = a1;
  v10 = 0;
  v57 = 0;
  while ( 2 )
  {
    if ( *(_BYTE *)(ipa3_ctx + 43308) == 1 )
      v57 = raw_spin_lock_irqsave(ipa3_ctx + 34712);
    else
      mutex_lock(ipa3_ctx + 34664);
    v56 = v10;
    if ( (unsigned int)ipa3_uc_state_check() )
    {
      v45 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v46 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v46 )
        {
          ipc_log_string(v46, "ipa %s:%d uC send command aborted\n", "ipa3_uc_send_cmd_64b_param", 965);
          v45 = ipa3_ctx;
        }
        v47 = *(_QWORD *)(v45 + 34160);
        if ( v47 )
        {
          ipc_log_string(v47, "ipa %s:%d uC send command aborted\n", "ipa3_uc_send_cmd_64b_param", 965);
          v45 = ipa3_ctx;
        }
      }
      if ( *(_BYTE *)(v45 + 43308) == 1 )
        raw_spin_unlock_irqrestore(v45 + 34712, v57);
      else
        mutex_unlock(v45 + 34664);
      return 4294967287LL;
    }
    while ( 1 )
    {
      v11 = ipa3_ctx;
      v12 = (_QWORD *)(ipa3_ctx + 34152);
      if ( *(_BYTE *)(ipa3_ctx + 43308) == 1 )
      {
        if ( !(a5 & 1 | (ipa3_ctx == 0)) )
        {
          if ( *v12 )
          {
            ipc_log_string(*v12, "ipa %s:%d Overriding mode to polling mode\n", "ipa3_uc_send_cmd_64b_param", 972);
            v11 = ipa3_ctx;
          }
          v13 = *(_QWORD *)(v11 + 34160);
          if ( v13 )
            ipc_log_string(v13, "ipa %s:%d Overriding mode to polling mode\n", "ipa3_uc_send_cmd_64b_param", 972);
        }
        a5 = 1;
      }
      else
      {
        *(_DWORD *)(ipa3_ctx + 34720) = 0;
        _init_swait_queue_head(v11 + 34728, "&x->wait", &init_completion___key_3);
      }
      *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 34752) + 4LL) = v9;
      v14 = ipa3_ctx;
      *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 34752) + 8LL) = a2;
      **(_BYTE **)(v14 + 34752) = a3;
      v15 = ipa3_ctx + 0x8000;
      v16 = *(_QWORD *)(ipa3_ctx + 34752);
      *(_DWORD *)(ipa3_ctx + 34772) = a3;
      *(_BYTE *)(v16 + 12) = 0;
      *(_DWORD *)(*(_QWORD *)(v15 + 1984) + 16LL) = 0;
      *(_DWORD *)(v15 + 2008) = 0;
      __dsb(0xEu);
      if ( *(_BYTE *)(ipa3_ctx + 43308) == 1 )
      {
        v17 = 66;
        v18 = 23;
      }
      else
      {
        v17 = 58;
        v18 = 0;
      }
      ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))ipahal_write_reg_mn)(v17, 0, v18, 1);
      if ( (a5 & 1) != 0 )
      {
        v60 = a5;
        v19 = a4;
        v20 = *(_QWORD *)(ipa3_ctx + 34752);
        v21 = 10000;
        do
        {
          while ( 1 )
          {
            if ( *(_BYTE *)(v20 + 12) == 2 )
            {
              v22 = *(_DWORD *)(v20 + 16);
              if ( *(_DWORD *)(ipa3_ctx + 34772) == (unsigned __int8)v22 )
              {
                a4 = v19;
                v9 = a1;
                a5 = v60;
                *(_DWORD *)(ipa3_ctx + 34776) = BYTE1(v22);
                goto LABEL_45;
              }
            }
            if ( *(_BYTE *)(ipa3_ctx + 43308) != 1 )
              break;
            _const_udelay(429500);
            if ( !--v21 )
              goto LABEL_27;
          }
          usleep_range_state(100, 100, 2);
          --v21;
        }
        while ( v21 );
LABEL_27:
        printk(&unk_3A4309, "ipa3_uc_send_cmd_64b_param");
        v23 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          a4 = v19;
          v24 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v24 )
          {
            ipc_log_string(v24, "ipa %s:%d uC max polling retries reached\n", "ipa3_uc_send_cmd_64b_param", 1018);
            v23 = ipa3_ctx;
          }
          v9 = a1;
          v25 = *(_QWORD *)(v23 + 34160);
          if ( v25 )
          {
            ipc_log_string(v25, "ipa %s:%d uC max polling retries reached\n", "ipa3_uc_send_cmd_64b_param", 1018);
            v23 = ipa3_ctx;
          }
        }
        else
        {
          v9 = a1;
          a4 = v19;
        }
        a5 = v60;
        if ( *(_BYTE *)(v23 + 34658) != 1 )
          goto LABEL_52;
        v34 = *(_DWORD *)(v23 + 34780);
        printk(&unk_3D3729, "ipa3_uc_send_cmd_64b_param");
        v23 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_52;
        if ( *(_QWORD *)(ipa3_ctx + 34152) )
        {
          v54 = *(_QWORD *)(ipa3_ctx + 34152);
          v35 = ipa_hw_error_str(v34);
          ipc_log_string(
            v54,
            "ipa %s:%d uC reported on Error, errorType = %s\n",
            "ipa3_uc_send_cmd_64b_param",
            1022,
            v35);
          v23 = ipa3_ctx;
        }
        if ( !*(_QWORD *)(v23 + 34160) )
          goto LABEL_52;
        v55 = *(_QWORD *)(v23 + 34160);
        v36 = ipa_hw_error_str(v34);
        ipc_log_string(v55, "ipa %s:%d uC reported on Error, errorType = %s\n", "ipa3_uc_send_cmd_64b_param", 1022, v36);
        goto LABEL_61;
      }
      if ( wait_for_completion_timeout(ipa3_ctx + 34720, a6) )
        goto LABEL_45;
      printk(&unk_3F2E27, "ipa3_uc_send_cmd_64b_param");
      v23 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v26 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v26 )
        {
          ipc_log_string(v26, "ipa %s:%d uC timed out\n", "ipa3_uc_send_cmd_64b_param", 1031);
          v23 = ipa3_ctx;
        }
        v27 = *(_QWORD *)(v23 + 34160);
        if ( v27 )
        {
          ipc_log_string(v27, "ipa %s:%d uC timed out\n", "ipa3_uc_send_cmd_64b_param", 1031);
          v23 = ipa3_ctx;
        }
      }
      if ( *(_BYTE *)(v23 + 34658) == 1 )
      {
        v28 = *(_DWORD *)(v23 + 34780);
        printk(&unk_3D3729, "ipa3_uc_send_cmd_64b_param");
        v23 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          if ( *(_QWORD *)(ipa3_ctx + 34152) )
          {
            v61 = *(_QWORD *)(ipa3_ctx + 34152);
            v29 = ipa_hw_error_str(v28);
            ipc_log_string(
              v61,
              "ipa %s:%d uC reported on Error, errorType = %s\n",
              "ipa3_uc_send_cmd_64b_param",
              1035,
              v29);
            v23 = ipa3_ctx;
          }
          if ( *(_QWORD *)(v23 + 34160) )
          {
            v62 = *(_QWORD *)(v23 + 34160);
            v30 = ipa_hw_error_str(v28);
            ipc_log_string(
              v62,
              "ipa %s:%d uC reported on Error, errorType = %s\n",
              "ipa3_uc_send_cmd_64b_param",
              1035,
              v30);
LABEL_61:
            v23 = ipa3_ctx;
          }
        }
      }
LABEL_52:
      v33 = *(_BYTE *)(v23 + 43308) == 1 ? raw_spin_unlock_irqrestore(v23 + 34712, v57) : mutex_unlock(v23 + 34664);
      ((void (__fastcall *)(__int64))ipa_assert)(v33);
LABEL_45:
      v31 = ipa3_ctx;
      v32 = *(_DWORD *)(ipa3_ctx + 34776);
      if ( v32 == a4 )
      {
        if ( *(_BYTE *)(ipa3_ctx + 43308) == 1 )
        {
          raw_spin_unlock_irqrestore(ipa3_ctx + 34712, v57);
          v42 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0;
        }
        else
        {
          mutex_unlock(ipa3_ctx + 34664);
          v42 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0;
        }
        v43 = *(_QWORD *)(v42 + 34152);
        if ( v43 )
        {
          ipc_log_string(v43, "ipa %s:%d uC cmd %u send succeeded\n", "ipa3_uc_send_cmd_64b_param", 1096, a3);
          v42 = ipa3_ctx;
        }
        result = *(_QWORD *)(v42 + 34160);
        if ( !result )
          return result;
        ipc_log_string(result, "ipa %s:%d uC cmd %u send succeeded\n", "ipa3_uc_send_cmd_64b_param", 1096, a3);
        return 0;
      }
      if ( v32 != 8 )
        break;
      if ( ++v10 >= 15 )
      {
        if ( v56 + 1 > 15 )
          v51 = v56 + 1;
        else
          v51 = 15;
        printk(&unk_3B030F, "ipa3_uc_send_cmd_64b_param");
        v48 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v52 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v52 )
          {
            ipc_log_string(v52, "ipa %s:%d Failed after %d tries\n", "ipa3_uc_send_cmd_64b_param", 1073, v51);
            v48 = ipa3_ctx;
          }
          v53 = *(_QWORD *)(v48 + 34160);
          if ( v53 )
          {
            ipc_log_string(v53, "ipa %s:%d Failed after %d tries\n", "ipa3_uc_send_cmd_64b_param", 1073, v51);
LABEL_111:
            v48 = ipa3_ctx;
          }
        }
        goto LABEL_112;
      }
      if ( *(_BYTE *)(ipa3_ctx + 43308) == 1 )
        _const_udelay(6442500);
      else
        usleep_range_state(1000, 2000, 2);
    }
    if ( v32 <= 0xA && ((1 << v32) & 0x6C0) != 0 )
    {
      if ( ++v10 == 10 )
      {
        printk(&unk_3B030F, "ipa3_uc_send_cmd_64b_param");
        v38 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v39 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v39 )
          {
            ipc_log_string(v39, "ipa %s:%d Failed after %d tries\n", "ipa3_uc_send_cmd_64b_param", 1054, 10);
            v38 = ipa3_ctx;
          }
          v40 = *(_QWORD *)(v38 + 34160);
          if ( v40 )
          {
            ipc_log_string(v40, "ipa %s:%d Failed after %d tries\n", "ipa3_uc_send_cmd_64b_param", 1054, 10);
            v38 = ipa3_ctx;
          }
        }
        if ( *(_BYTE *)(v38 + 43308) == 1 )
          v41 = raw_spin_unlock_irqrestore(v38 + 34712, v57);
        else
          v41 = mutex_unlock(v38 + 34664);
        ((void (__fastcall *)(__int64))ipa_assert)(v41);
        v31 = ipa3_ctx;
      }
      if ( *(_BYTE *)(v31 + 43308) == 1 )
        v37 = raw_spin_unlock_irqrestore(v31 + 34712, v57);
      else
        v37 = mutex_unlock(v31 + 34664);
      if ( *(_DWORD *)(ipa3_ctx + 34776) == 7 )
        ipa3_inject_dma_task_for_gsi(v37);
      usleep_range_state(1000, 2000, 2);
      continue;
    }
    break;
  }
  printk(&unk_3D0416, "ipa3_uc_send_cmd_64b_param");
  v48 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v49 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v49 )
    {
      ipc_log_string(
        v49,
        "ipa %s:%d uC cmd(%u): Received status %u, Expected status %u\n",
        "ipa3_uc_send_cmd_64b_param",
        1089,
        a3,
        *(_DWORD *)(ipa3_ctx + 34776),
        a4);
      v48 = ipa3_ctx;
    }
    v50 = *(_QWORD *)(v48 + 34160);
    if ( v50 )
    {
      ipc_log_string(
        v50,
        "ipa %s:%d uC cmd(%u): Received status %u, Expected status %u\n",
        "ipa3_uc_send_cmd_64b_param",
        1089,
        a3,
        *(_DWORD *)(v48 + 34776),
        a4);
      goto LABEL_111;
    }
  }
LABEL_112:
  if ( *(_BYTE *)(v48 + 43308) == 1 )
    raw_spin_unlock_irqrestore(v48 + 34712, v57);
  else
    mutex_unlock(v48 + 34664);
  return 4294967282LL;
}
