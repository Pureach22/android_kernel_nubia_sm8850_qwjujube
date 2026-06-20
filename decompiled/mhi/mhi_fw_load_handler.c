__int64 __fastcall mhi_fw_load_handler(__int64 a1)
{
  unsigned int v1; // w8
  __int64 v2; // x27
  int v4; // w8
  __int64 v5; // x8
  __int64 v6; // x22
  int v7; // w0
  unsigned __int64 v8; // x20
  char *v9; // x21
  unsigned __int64 *v10; // x8
  size_t v11; // x8
  size_t v12; // x23
  void *v13; // x0
  void *v14; // x24
  __int64 v15; // x8
  unsigned __int64 v16; // x26
  __int64 v17; // x25
  __int64 lock_bh; // x0
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x28
  __int64 v21; // x8
  unsigned __int64 v22; // x26
  __int64 v23; // x8
  int v24; // w25
  __int64 v25; // x20
  __int64 v26; // x19
  __int64 result; // x0
  __int64 v28; // x20
  bool v29; // zf
  __int64 v30; // x0
  unsigned __int64 v31; // x26
  bool v32; // zf
  __int64 v33; // x0
  __int64 v34; // x21
  int v35; // w20
  __int64 v36; // x26
  __int64 v37; // x8
  const char *v38; // x3
  __int64 v39; // x8
  int v40; // w20
  _QWORD *v41; // x8
  _QWORD *v42; // x23
  __int64 *v43; // x24
  size_t v44; // x22
  __int64 v45; // t1
  __int64 v46; // x20
  __int64 v47; // x20
  __int64 v48; // x26
  __int64 v49; // x26
  __int64 v50; // x26
  __int64 v51; // x25
  __int64 v52; // [xsp+0h] [xbp-50h]
  unsigned __int64 v53; // [xsp+8h] [xbp-48h] BYREF
  unsigned __int64 *v54; // [xsp+10h] [xbp-40h] BYREF
  _QWORD v55[5]; // [xsp+18h] [xbp-38h] BYREF
  _QWORD v56[2]; // [xsp+40h] [xbp-10h] BYREF

  v56[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 336);
  v2 = *(_QWORD *)(a1 + 16);
  v53 = 0;
  v54 = nullptr;
  if ( v1 >= 0x80 )
  {
    v26 = *(_QWORD *)(v2 + 192);
    result = dev_err(v2 + 40, "[E][%s] Device MHI is not in valid state\n", "mhi_fw_load_handler");
    if ( v26 && *(_DWORD *)(v26 + 24) <= 2u )
      result = ipc_log_string(
                 *(_QWORD *)(v26 + 32),
                 "[E][%s] Device MHI is not in valid state\n",
                 "mhi_fw_load_handler");
    goto LABEL_108;
  }
  if ( (unsigned int)mhi_read_reg(a1, *(_QWORD *)(a1 + 40), 64, a1 + 244) )
  {
    v28 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v2 + 40, "[E][%s] Could not capture serial number via BHI\n", "mhi_fw_load_handler");
    if ( v28 )
    {
      if ( *(_DWORD *)(v28 + 24) <= 2u )
        ipc_log_string(
          *(_QWORD *)(v28 + 32),
          "[E][%s] Could not capture serial number via BHI\n",
          "mhi_fw_load_handler");
    }
  }
  v4 = *(_DWORD *)(a1 + 344);
  if ( v4 == 6 || !v4 )
  {
    v29 = v4 == 6;
    v5 = 88;
    if ( v29 )
      v5 = 112;
    v6 = *(_QWORD *)(a1 + v5);
    if ( v6 )
    {
      if ( !*(_BYTE *)(a1 + 614) || *(_QWORD *)(a1 + 128) && *(_QWORD *)(a1 + 136) )
      {
        v7 = request_firmware(&v54, v6, v2 + 40);
        if ( v7 )
        {
          v34 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
          v35 = v7;
          dev_err(v2 + 40, "[E][%s] Error loading firmware: %d\n", "mhi_fw_load_handler", v7);
          if ( v34 && *(_DWORD *)(v34 + 24) <= 2u )
            ipc_log_string(*(_QWORD *)(v34 + 32), "[E][%s] Error loading firmware: %d\n", "mhi_fw_load_handler", v35);
          goto LABEL_95;
        }
        v8 = *v54;
        v9 = (char *)v54[1];
        if ( *(_BYTE *)(a1 + 614) )
          v10 = (unsigned __int64 *)(a1 + 128);
        else
          v10 = v54;
        v11 = *v10;
        if ( v11 >= v8 )
          v12 = *v54;
        else
          v12 = v11;
        goto LABEL_22;
      }
    }
    else if ( *(_BYTE *)(a1 + 614) )
    {
      v9 = *(char **)(a1 + 96);
      if ( v9 )
      {
        v8 = *(_QWORD *)(a1 + 104);
        if ( v8 )
        {
          v12 = *(_QWORD *)(a1 + 128);
          if ( !v12 )
          {
            dev_err(v2 + 40, "fw_data provided but no sbl_size\n");
            goto LABEL_95;
          }
LABEL_22:
          v13 = (void *)dma_alloc_attrs(*(_QWORD *)(a1 + 8), v12, &v53, 3264, 0);
          if ( !v13 )
          {
LABEL_94:
            release_firmware(v54);
LABEL_95:
            raw_write_lock_irq(a1 + 320);
            v40 = mhi_tryset_pm_state(a1, 128);
            result = raw_write_unlock_irq(a1 + 320);
            if ( v40 == 128 )
              result = _wake_up(a1 + 456, 3, 0, 0);
            goto LABEL_108;
          }
          v14 = v13;
          memcpy(v13, v9, v12);
          v15 = *(_QWORD *)(a1 + 16);
          v16 = v53;
          v17 = *(_QWORD *)(a1 + 40);
          v56[0] = 0;
          v52 = v15;
          lock_bh = raw_read_lock_bh(a1 + 320);
          if ( (*(_WORD *)(a1 + 336) & 0xFDE) != 0 )
          {
            do
            {
              lock_bh = get_random_u32(lock_bh);
              v19 = 0x3FFFFFFFLL * (unsigned int)lock_bh;
            }
            while ( (v19 & 0xFFFFFFFC) == 0 );
            v20 = HIDWORD(v19);
            v21 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
            if ( v21 && !*(_DWORD *)(v21 + 24) )
              ipc_log_string(
                *(_QWORD *)(v21 + 32),
                "[D][%s] Starting image download via BHI. Session ID: %u\n",
                "mhi_fw_load_bhi",
                HIDWORD(v19) + 1);
            mhi_write_reg(a1, v17, 44, 0);
            mhi_write_reg(a1, v17, 12, HIDWORD(v16));
            mhi_write_reg(a1, v17, 8, (unsigned int)v16);
            mhi_write_reg(a1, v17, 16, (unsigned int)v12);
            mhi_write_reg(a1, v17, 24, (unsigned int)(v20 + 1));
            raw_read_unlock_bh(a1 + 320);
            v22 = _msecs_to_jiffies(*(unsigned int *)(a1 + 328));
            if ( *(_DWORD *)(a1 + 336) > 0x7Fu
              || (unsigned int)mhi_read_reg_field(a1, v17, 44, 3221225472LL, (char *)v56 + 4) )
            {
              if ( v22 <= 1 )
                LODWORD(v23) = 1;
              else
                LODWORD(v23) = v22;
            }
            else
            {
              if ( v22 )
                v29 = 1;
              else
                v29 = HIDWORD(v56[0]) == 0;
              if ( v29 )
                v23 = v22;
              else
                v23 = 1;
              if ( !HIDWORD(v56[0]) && v23 )
              {
                v30 = *(unsigned int *)(a1 + 328);
                memset(v55, 0, sizeof(v55));
                v31 = _msecs_to_jiffies(v30);
                init_wait_entry(v55, 0);
                while ( 1 )
                {
                  prepare_to_wait_event(a1 + 456, v55, 2);
                  if ( *(_DWORD *)(a1 + 336) > 0x7Fu
                    || (unsigned int)mhi_read_reg_field(a1, v17, 44, 3221225472LL, (char *)v56 + 4) )
                  {
                    break;
                  }
                  if ( v31 )
                    v32 = 1;
                  else
                    v32 = HIDWORD(v56[0]) == 0;
                  if ( v32 )
                    v33 = v31;
                  else
                    v33 = 1;
                  if ( HIDWORD(v56[0]) || !v33 )
                  {
                    LODWORD(v31) = v33;
                    goto LABEL_72;
                  }
                  v31 = schedule_timeout();
                }
                if ( v31 <= 1 )
                  LODWORD(v31) = 1;
LABEL_72:
                finish_wait(a1 + 456, v55);
                LODWORD(v23) = v31;
              }
            }
            if ( *(_DWORD *)(a1 + 336) > 0x7Fu )
              goto LABEL_80;
            if ( HIDWORD(v56[0]) != 3 )
            {
              if ( (_DWORD)v23 )
                v24 = 0;
              else
                v24 = -110;
              goto LABEL_81;
            }
            v36 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
            dev_err(v52 + 40, "[E][%s] Image transfer failed\n", "mhi_fw_load_bhi");
            if ( v36 && *(_DWORD *)(v36 + 24) <= 2u )
              ipc_log_string(*(_QWORD *)(v36 + 32), "[E][%s] Image transfer failed\n", "mhi_fw_load_bhi");
            raw_read_lock_bh(a1 + 320);
            if ( (*(_WORD *)(a1 + 336) & 0xFDE) != 0 && !(unsigned int)mhi_read_reg(a1, v17, 48, v56) )
            {
              v48 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
              dev_err(v52 + 40, "[E][%s] Reg: %s value: 0x%x\n", "mhi_fw_load_bhi", "ERROR_CODE", LODWORD(v56[0]));
              if ( v48 && *(_DWORD *)(v48 + 24) <= 2u )
                ipc_log_string(
                  *(_QWORD *)(v48 + 32),
                  "[E][%s] Reg: %s value: 0x%x\n",
                  "mhi_fw_load_bhi",
                  "ERROR_CODE",
                  LODWORD(v56[0]));
              if ( !(unsigned int)mhi_read_reg(a1, v17, 52, v56) )
              {
                v49 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
                dev_err(v52 + 40, "[E][%s] Reg: %s value: 0x%x\n", "mhi_fw_load_bhi", "ERROR_DBG1", LODWORD(v56[0]));
                if ( v49 && *(_DWORD *)(v49 + 24) <= 2u )
                  ipc_log_string(
                    *(_QWORD *)(v49 + 32),
                    "[E][%s] Reg: %s value: 0x%x\n",
                    "mhi_fw_load_bhi",
                    "ERROR_DBG1",
                    LODWORD(v56[0]));
                if ( !(unsigned int)mhi_read_reg(a1, v17, 56, v56) )
                {
                  v50 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
                  dev_err(v52 + 40, "[E][%s] Reg: %s value: 0x%x\n", "mhi_fw_load_bhi", "ERROR_DBG2", LODWORD(v56[0]));
                  if ( v50 && *(_DWORD *)(v50 + 24) <= 2u )
                    ipc_log_string(
                      *(_QWORD *)(v50 + 32),
                      "[E][%s] Reg: %s value: 0x%x\n",
                      "mhi_fw_load_bhi",
                      "ERROR_DBG2",
                      LODWORD(v56[0]));
                  if ( !(unsigned int)mhi_read_reg(a1, v17, 60, v56) )
                  {
                    v51 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
                    dev_err(v52 + 40, "[E][%s] Reg: %s value: 0x%x\n", "mhi_fw_load_bhi", "ERROR_DBG3", LODWORD(v56[0]));
                    if ( v51 )
                    {
                      if ( *(_DWORD *)(v51 + 24) <= 2u )
                        ipc_log_string(
                          *(_QWORD *)(v51 + 32),
                          "[E][%s] Reg: %s value: 0x%x\n",
                          "mhi_fw_load_bhi",
                          "ERROR_DBG3",
                          LODWORD(v56[0]));
                    }
                  }
                }
              }
            }
          }
          raw_read_unlock_bh(a1 + 320);
LABEL_80:
          v24 = -5;
LABEL_81:
          dma_free_attrs(*(_QWORD *)(a1 + 8), v12, v14, v53, 0);
          if ( v24 )
          {
            v47 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
            dev_err(v2 + 40, "[E][%s] MHI did not load image over BHI, ret: %d\n", "mhi_fw_load_handler", v24);
            if ( v47 && *(_DWORD *)(v47 + 24) <= 2u )
              ipc_log_string(
                *(_QWORD *)(v47 + 32),
                "[E][%s] MHI did not load image over BHI, ret: %d\n",
                "mhi_fw_load_handler",
                v24);
            goto LABEL_94;
          }
          if ( !v6 || v6 != *(_QWORD *)(a1 + 112) )
          {
            raw_write_lock_irq(a1 + 320);
            *(_DWORD *)(a1 + 348) = 0;
            raw_write_unlock_irq(a1 + 320);
            if ( *(_BYTE *)(a1 + 614) == 1 )
            {
              v37 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
              if ( v37 && *(_DWORD *)(v37 + 24) <= 1u )
              {
                if ( *(_BYTE *)(a1 + 168) )
                  v38 = "True";
                else
                  v38 = "False";
                ipc_log_string(*(_QWORD *)(v37 + 32), "[I][%s] tme_supported_image:%s\n", "mhi_fw_load_handler", v38);
              }
              if ( *(_BYTE *)(a1 + 168) == 1 )
              {
                v39 = *(_QWORD *)(a1 + 128);
                v9 += v39;
                v8 -= v39;
              }
              if ( (unsigned int)mhi_alloc_bhie_table(a1, (__int64 *)(a1 + 152), v8) )
                goto LABEL_94;
              if ( v8 )
              {
                v41 = *(_QWORD **)(a1 + 152);
                v42 = (_QWORD *)v41[1];
                v43 = (__int64 *)(*v41 + 16LL);
                do
                {
                  if ( v8 >= v43[1] )
                    v44 = v43[1];
                  else
                    v44 = v8;
                  memcpy((void *)*(v43 - 2), v9, v44);
                  v45 = *v43;
                  v43 += 4;
                  v8 -= v44;
                  v9 += v44;
                  *v42 = v45;
                  v42[1] = v44;
                  v42 += 2;
                }
                while ( v8 );
              }
            }
          }
          release_firmware(v54);
          goto LABEL_104;
        }
      }
    }
    v25 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    dev_err(v2 + 40, "[E][%s] No firmware image defined or !sbl_size || !seg_len\n", "mhi_fw_load_handler");
    if ( v25 && *(_DWORD *)(v25 + 24) <= 2u )
      ipc_log_string(
        *(_QWORD *)(v25 + 32),
        "[E][%s] No firmware image defined or !sbl_size || !seg_len\n",
        "mhi_fw_load_handler");
    goto LABEL_95;
  }
LABEL_104:
  result = mhi_ready_state_transition(a1);
  v46 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( (_DWORD)result )
  {
    dev_err(v2 + 40, "[E][%s] MHI did not enter READY state\n", "mhi_fw_load_handler");
    if ( v46 && *(_DWORD *)(v46 + 24) <= 2u )
      ipc_log_string(*(_QWORD *)(v46 + 32), "[E][%s] MHI did not enter READY state\n", "mhi_fw_load_handler");
    if ( (*(_BYTE *)(a1 + 614) & 1) != 0 )
      mhi_free_bhie_table(a1, (_QWORD *)(a1 + 152));
    goto LABEL_95;
  }
  if ( v46 && *(_DWORD *)(v46 + 24) <= 1u )
    result = ipc_log_string(
               *(_QWORD *)(v46 + 32),
               "[I][%s] Wait for device to enter SBL or Mission mode\n",
               "mhi_fw_load_handler");
LABEL_108:
  _ReadStatusReg(SP_EL0);
  return result;
}
