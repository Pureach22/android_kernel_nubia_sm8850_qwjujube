__int64 __fastcall mhi_download_rddm_image(__int64 a1, char a2)
{
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x8
  __int64 v6; // x20
  const char *v7; // x0
  int v8; // w8
  const char *v9; // x4
  __int64 v10; // x8
  __int64 v11; // x21
  __int64 v12; // x0
  __int64 v13; // x21
  int v14; // w0
  int v15; // w8
  bool v16; // zf
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 result; // x0
  __int64 v20; // x8
  const char *v21; // x5
  unsigned int exec_env; // w20
  __int64 v23; // x8
  __int64 v24; // x8
  int v25; // w20
  __int64 v26; // x8
  __int64 v27; // x8
  const char *v28; // x3
  int v29; // w0
  __int64 v30; // x19
  char v31; // w22
  const char *v32; // x3
  const char *v33; // x3
  _QWORD v34[5]; // [xsp+8h] [xbp-38h] BYREF
  int v35; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+38h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 48);
  v4 = *(_QWORD *)(a1 + 16);
  v35 = 0;
  if ( (a2 & 1) != 0 )
  {
    v5 = *(_QWORD *)(v4 + 192);
    if ( !v5 || *(_DWORD *)(v5 + 24) )
      goto LABEL_51;
    v6 = *(_QWORD *)(v5 + 32);
    v7 = (const char *)to_mhi_pm_state_str(*(unsigned int *)(a1 + 336));
    v8 = *(_DWORD *)(a1 + 348);
    if ( v8 <= 3 )
    {
      if ( v8 <= 1 )
      {
        if ( !v8 )
        {
          v9 = "RESET";
          goto LABEL_47;
        }
        if ( v8 == 1 )
        {
          v9 = "READY";
          goto LABEL_47;
        }
        goto LABEL_46;
      }
      if ( v8 == 2 )
        v9 = "M0";
      else
        v9 = "M1";
    }
    else
    {
      if ( v8 > 5 )
      {
        switch ( v8 )
        {
          case 6:
            v9 = "M3_FAST";
            goto LABEL_47;
          case 7:
            v9 = "BHI";
            goto LABEL_47;
          case 255:
            v9 = "SYS ERROR";
            goto LABEL_47;
        }
LABEL_46:
        v9 = "Unknown state";
        goto LABEL_47;
      }
      if ( v8 == 4 )
        v9 = "M2";
      else
        v9 = "M3";
    }
LABEL_47:
    v20 = *(unsigned int *)(a1 + 344);
    if ( (unsigned int)v20 <= 9 )
      v21 = mhi_ee_str[v20];
    else
      v21 = "INVALID_EE";
    ipc_log_string(
      v6,
      "[D][%s] Entered with pm_state:%s dev_state:%s ee:%s\n",
      "__mhi_download_rddm_in_panic",
      v7,
      v9,
      v21);
LABEL_51:
    *(_DWORD *)(a1 + 336) = 4096;
    __dmb(0xAu);
    exec_env = mhi_get_exec_env(a1);
    if ( exec_env != 3 )
    {
      if ( exec_env == 10 )
      {
        v30 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        goto LABEL_84;
      }
      v23 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      if ( v23 && !*(_DWORD *)(v23 + 24) )
        ipc_log_string(
          *(_QWORD *)(v23 + 32),
          "[D][%s] Trigger device into RDDM mode using SYS ERR\n",
          "__mhi_download_rddm_in_panic");
      mhi_set_mhi_state(a1, 255);
      v24 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      if ( v24 && !*(_DWORD *)(v24 + 24) )
        ipc_log_string(
          *(_QWORD *)(v24 + 32),
          "[D][%s] Waiting for device to enter RDDM\n",
          "__mhi_download_rddm_in_panic");
      v25 = 99;
      while ( (unsigned int)mhi_get_exec_env(a1) != 3 )
      {
        _const_udelay(8590000);
        if ( --v25 == -1 )
          goto LABEL_64;
      }
      if ( v25 > 0 )
        goto LABEL_68;
LABEL_64:
      v26 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      if ( v26 && !*(_DWORD *)(v26 + 24) )
        ipc_log_string(
          *(_QWORD *)(v26 + 32),
          "[D][%s] Did not enter RDDM, do a host req reset\n",
          "__mhi_download_rddm_in_panic");
      mhi_soc_reset(a1);
      _const_udelay(8590000);
LABEL_68:
      exec_env = mhi_get_exec_env(a1);
    }
    v27 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( v27 && !*(_DWORD *)(v27 + 24) )
    {
      if ( exec_env <= 9 )
        v28 = mhi_ee_str[exec_env];
      else
        v28 = "INVALID_EE";
      ipc_log_string(
        *(_QWORD *)(v27 + 32),
        "[D][%s] Waiting for RDDM image download via BHIe, current EE:%s\n",
        "__mhi_download_rddm_in_panic",
        v28);
    }
    v29 = mhi_rddm_download_status(a1);
    v30 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
    if ( !v29 )
    {
      if ( v30 && *(_DWORD *)(v30 + 24) <= 1u )
        ipc_log_string(
          *(_QWORD *)(v30 + 32),
          "[I][%s] RDDM dumps collected successfully",
          "__mhi_download_rddm_in_panic");
      result = 0;
      goto LABEL_80;
    }
    if ( exec_env <= 9 )
    {
      v31 = 0;
      v32 = mhi_ee_str[exec_env];
LABEL_85:
      dev_err(v4 + 40, "[E][%s] RDDM transfer failed. Current EE: %s\n", "__mhi_download_rddm_in_panic", v32);
      if ( v30 && *(_DWORD *)(v30 + 24) <= 2u )
      {
        if ( (v31 & 1) != 0 )
          v33 = "INVALID_EE";
        else
          v33 = mhi_ee_str[exec_env];
        ipc_log_string(
          *(_QWORD *)(v30 + 32),
          "[E][%s] RDDM transfer failed. Current EE: %s\n",
          "__mhi_download_rddm_in_panic",
          v33);
        result = 4294967291LL;
      }
      else
      {
        result = 4294967291LL;
      }
      goto LABEL_80;
    }
LABEL_84:
    v32 = "INVALID_EE";
    v31 = 1;
    goto LABEL_85;
  }
  v10 = *(_QWORD *)(v4 + 192);
  if ( v10 && !*(_DWORD *)(v10 + 24) )
    ipc_log_string(
      *(_QWORD *)(v10 + 32),
      "[D][%s] Waiting for RDDM image download via BHIe\n",
      "mhi_download_rddm_image");
  v11 = _msecs_to_jiffies(*(unsigned int *)(a1 + 328));
  if ( !(unsigned int)mhi_read_reg_field(a1, v3, 120, 3221225472LL, &v35) && !v35 && v11 )
  {
    v12 = *(unsigned int *)(a1 + 328);
    memset(v34, 0, sizeof(v34));
    v13 = _msecs_to_jiffies(v12);
    init_wait_entry(v34, 0);
    while ( 1 )
    {
      prepare_to_wait_event(a1 + 456, v34, 2);
      v14 = mhi_read_reg_field(a1, v3, 120, 3221225472LL, &v35);
      v15 = v14 | v35;
      v16 = v13 || v15 == 0;
      v17 = v16 ? v13 : 1LL;
      if ( v15 || !v17 )
        break;
      v13 = schedule_timeout();
    }
    finish_wait(a1 + 456, v34);
  }
  v18 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( v18 && !*(_DWORD *)(v18 + 24) )
    ipc_log_string(*(_QWORD *)(v18 + 32), "[D][%s] RXVEC_STATUS: 0x%x\n", "mhi_download_rddm_image", v35);
  if ( v35 == 2 )
    result = 0;
  else
    result = 4294967291LL;
LABEL_80:
  _ReadStatusReg(SP_EL0);
  return result;
}
