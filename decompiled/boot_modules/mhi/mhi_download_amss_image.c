__int64 __fastcall mhi_download_amss_image(__int64 a1)
{
  __int64 *v1; // x8
  __int64 v3; // x22
  __int64 v4; // x21
  int v5; // w23
  __int64 v6; // x20
  __int64 lock_bh; // x0
  unsigned int *v8; // x21
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x23
  __int64 v11; // x8
  unsigned int v12; // w21
  unsigned __int64 v13; // x21
  __int64 v14; // x8
  bool v16; // zf
  __int64 v17; // x0
  unsigned __int64 v18; // x21
  bool v19; // zf
  __int64 v20; // x0
  int v21; // w20
  __int64 v22; // x20
  int v23; // w20
  _QWORD v24[5]; // [xsp+8h] [xbp-38h] BYREF
  int v25; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+38h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(__int64 **)(a1 + 152);
  if ( !v1 )
  {
    v12 = -5;
    goto LABEL_19;
  }
  v3 = *(_QWORD *)(a1 + 16);
  v4 = *v1;
  v5 = *((_DWORD *)v1 + 4);
  v6 = *(_QWORD *)(a1 + 48);
  v25 = 0;
  lock_bh = raw_read_lock_bh(a1 + 320);
  if ( (*(_WORD *)(a1 + 336) & 0xFDE) != 0 )
  {
    v8 = (unsigned int *)(v4 + 32LL * (unsigned int)(v5 - 1));
    do
    {
      lock_bh = get_random_u32(lock_bh);
      v9 = 0x3FFFFFFFLL * (unsigned int)lock_bh;
    }
    while ( (v9 & 0xFFFFFFFC) == 0 );
    v10 = HIDWORD(v9);
    v11 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v11 && !*(_DWORD *)(v11 + 24) )
      ipc_log_string(
        *(_QWORD *)(v11 + 32),
        "[D][%s] Starting image download via BHIe. Sequence ID: %u\n",
        "mhi_fw_load_bhie",
        HIDWORD(v9) + 1);
    mhi_write_reg(a1, v6, 48, v8[5]);
    mhi_write_reg(a1, v6, 44, v8[4]);
    mhi_write_reg(a1, v6, 52, v8[6]);
    v12 = mhi_write_reg_field(a1, v6, 60, 0x3FFFFFFF, (unsigned int)(v10 + 1));
    raw_read_unlock_bh(a1 + 320);
    if ( !v12 )
    {
      v13 = _msecs_to_jiffies(*(unsigned int *)(a1 + 328));
      if ( *(_DWORD *)(a1 + 336) > 0x7Fu || (unsigned int)mhi_read_reg_field(a1, v6, 68, 3221225472LL, &v25) )
      {
        LODWORD(v14) = v13 <= 1 ? 1 : v13;
      }
      else
      {
        if ( v13 )
          v16 = 1;
        else
          v16 = v25 == 0;
        if ( v16 )
          v14 = v13;
        else
          v14 = 1;
        if ( !v25 && v14 )
        {
          v17 = *(unsigned int *)(a1 + 328);
          memset(v24, 0, sizeof(v24));
          v18 = _msecs_to_jiffies(v17);
          init_wait_entry(v24, 0);
          while ( 1 )
          {
            prepare_to_wait_event(a1 + 456, v24, 2);
            if ( *(_DWORD *)(a1 + 336) > 0x7Fu || (unsigned int)mhi_read_reg_field(a1, v6, 68, 3221225472LL, &v25) )
              break;
            if ( v18 )
              v19 = 1;
            else
              v19 = v25 == 0;
            if ( v19 )
              v20 = v18;
            else
              v20 = 1;
            if ( v25 || !v20 )
            {
              v21 = v20;
              goto LABEL_43;
            }
            v18 = schedule_timeout();
          }
          if ( v18 <= 1 )
            v21 = 1;
          else
            v21 = v18;
LABEL_43:
          finish_wait(a1 + 456, v24);
          LODWORD(v14) = v21;
        }
      }
      v12 = -5;
      if ( *(_DWORD *)(a1 + 336) <= 0x7Fu && v25 == 2 )
      {
        if ( (_DWORD)v14 )
        {
          v12 = 0;
          goto LABEL_19;
        }
        v12 = -110;
      }
    }
  }
  else
  {
    raw_read_unlock_bh(a1 + 320);
    v12 = -5;
  }
  v22 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  dev_err(v3 + 40, "[E][%s] MHI did not load AMSS, ret:%d\n", "mhi_download_amss_image", v12);
  if ( v22 && *(_DWORD *)(v22 + 24) <= 2u )
    ipc_log_string(*(_QWORD *)(v22 + 32), "[E][%s] MHI did not load AMSS, ret:%d\n", "mhi_download_amss_image", v12);
  raw_write_lock_irq(a1 + 320);
  v23 = mhi_tryset_pm_state(a1, 128);
  raw_write_unlock_irq(a1 + 320);
  if ( v23 == 128 )
    _wake_up(a1 + 456, 3, 0, 0);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v12;
}
