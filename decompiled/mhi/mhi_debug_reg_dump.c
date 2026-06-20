__int64 __fastcall mhi_debug_reg_dump(__int64 a1)
{
  __int64 v2; // x10
  __int64 v3; // x23
  __int64 v4; // x12
  __int64 v5; // x10
  __int64 v6; // x10
  unsigned int v7; // w0
  __int64 v8; // x20
  const char *v9; // x0
  int v10; // w8
  const char *v11; // x4
  __int64 v12; // x8
  const char *v13; // x5
  __int64 v14; // x20
  const char *v15; // x0
  int v16; // w8
  const char *v17; // x4
  __int64 v18; // x8
  const char *v19; // x5
  int mhi_state; // w20
  unsigned int exec_env; // w21
  __int64 v22; // x24
  const char *v23; // x3
  const char *v24; // x4
  __int64 result; // x0
  const char *v26; // x3
  const char *v27; // x4
  __int64 v28; // x24
  int reg; // w22
  __int64 v30; // x26
  _QWORD v31[43]; // [xsp+8h] [xbp-158h] BYREF

  v31[42] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 40);
  v31[0] = "BHI_ERRDBG2";
  v31[1] = 56;
  v3 = *(_QWORD *)(a1 + 16);
  v31[2] = v2;
  v31[3] = "BHI_ERRDBG3";
  v31[6] = "BHI_ERRDBG1";
  v31[7] = 52;
  v31[8] = v2;
  v31[9] = "BHI_ERRCODE";
  v31[10] = 48;
  v31[11] = v2;
  v31[12] = "BHI_EXECENV";
  v31[13] = 40;
  v31[14] = v2;
  v31[15] = "BHI_STATUS";
  v31[4] = 60;
  v31[5] = v2;
  v31[16] = 44;
  v31[17] = v2;
  v4 = *(_QWORD *)(a1 + 32);
  v31[18] = "MHI_CNTRL";
  v31[19] = 56;
  v31[20] = v4;
  v31[21] = "MHI_STATUS";
  v5 = *(_QWORD *)(a1 + 56);
  v31[24] = "MHI_WAKE_DB";
  v31[25] = 0;
  v31[26] = v5;
  v31[27] = "BHIE_TXVEC_DB";
  v6 = *(_QWORD *)(a1 + 48);
  v7 = *(_DWORD *)(a1 + 336);
  v31[28] = 60;
  v31[29] = v6;
  v31[30] = "BHIE_TXVEC_STATUS";
  v31[31] = 68;
  v31[32] = v6;
  v31[33] = "BHIE_RXVEC_DB";
  v31[34] = 112;
  v31[35] = v6;
  v31[36] = "BHIE_RXVEC_STATUS";
  v31[37] = 120;
  v31[38] = v6;
  memset(&v31[39], 0, 24);
  v8 = *(_QWORD *)(v3 + 192);
  v31[22] = 72;
  v31[23] = v4;
  v9 = to_mhi_pm_state_str(v7);
  v10 = *(_DWORD *)(a1 + 348);
  if ( v10 <= 3 )
  {
    if ( v10 > 1 )
    {
      if ( v10 == 2 )
        v11 = "M0";
      else
        v11 = "M1";
      goto LABEL_21;
    }
    if ( !v10 )
    {
      v11 = "RESET";
      goto LABEL_21;
    }
    if ( v10 == 1 )
    {
      v11 = "READY";
      goto LABEL_21;
    }
  }
  else
  {
    if ( v10 <= 5 )
    {
      if ( v10 == 4 )
        v11 = "M2";
      else
        v11 = "M3";
      goto LABEL_21;
    }
    switch ( v10 )
    {
      case 6:
        v11 = "M3_FAST";
        goto LABEL_21;
      case 7:
        v11 = "BHI";
        goto LABEL_21;
      case 255:
        v11 = "SYS ERROR";
        goto LABEL_21;
    }
  }
  v11 = "Unknown state";
LABEL_21:
  v12 = *(unsigned int *)(a1 + 344);
  if ( (unsigned int)v12 <= 9 )
    v13 = mhi_ee_str[v12];
  else
    v13 = "INVALID_EE";
  dev_err(v3 + 40, "[E][%s] host pm_state:%s dev_state:%s ee:%s\n", "mhi_debug_reg_dump", v9, v11, v13);
  if ( v8 && *(_DWORD *)(v8 + 24) <= 2u )
  {
    v14 = *(_QWORD *)(v8 + 32);
    v15 = to_mhi_pm_state_str(*(_DWORD *)(a1 + 336));
    v16 = *(_DWORD *)(a1 + 348);
    if ( v16 <= 3 )
    {
      if ( v16 <= 1 )
      {
        if ( !v16 )
        {
          v17 = "RESET";
          goto LABEL_46;
        }
        if ( v16 == 1 )
        {
          v17 = "READY";
          goto LABEL_46;
        }
        goto LABEL_45;
      }
      if ( v16 == 2 )
        v17 = "M0";
      else
        v17 = "M1";
    }
    else
    {
      if ( v16 > 5 )
      {
        switch ( v16 )
        {
          case 6:
            v17 = "M3_FAST";
            goto LABEL_46;
          case 7:
            v17 = "BHI";
            goto LABEL_46;
          case 255:
            v17 = "SYS ERROR";
            goto LABEL_46;
        }
LABEL_45:
        v17 = "Unknown state";
        goto LABEL_46;
      }
      if ( v16 == 4 )
        v17 = "M2";
      else
        v17 = "M3";
    }
LABEL_46:
    v18 = *(unsigned int *)(a1 + 344);
    if ( (unsigned int)v18 <= 9 )
      v19 = mhi_ee_str[v18];
    else
      v19 = "INVALID_EE";
    ipc_log_string(v14, "[E][%s] host pm_state:%s dev_state:%s ee:%s\n", "mhi_debug_reg_dump", v15, v17, v19);
  }
  mhi_state = mhi_get_mhi_state(a1);
  exec_env = mhi_get_exec_env(a1);
  v22 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( exec_env <= 9 )
  {
    v23 = mhi_ee_str[exec_env];
    if ( mhi_state > 3 )
      goto LABEL_52;
  }
  else
  {
    v23 = "INVALID_EE";
    if ( mhi_state > 3 )
    {
LABEL_52:
      if ( mhi_state > 5 )
      {
        switch ( mhi_state )
        {
          case 6:
            v24 = "M3_FAST";
            goto LABEL_72;
          case 7:
            v24 = "BHI";
            goto LABEL_72;
          case 255:
            v24 = "SYS ERROR";
            goto LABEL_72;
        }
LABEL_71:
        v24 = "Unknown state";
        goto LABEL_72;
      }
      if ( mhi_state == 4 )
        v24 = "M2";
      else
        v24 = "M3";
      goto LABEL_72;
    }
  }
  if ( mhi_state <= 1 )
  {
    if ( !mhi_state )
    {
      v24 = "RESET";
      goto LABEL_72;
    }
    if ( mhi_state == 1 )
    {
      v24 = "READY";
      goto LABEL_72;
    }
    goto LABEL_71;
  }
  if ( mhi_state == 2 )
    v24 = "M0";
  else
    v24 = "M1";
LABEL_72:
  result = dev_err(v3 + 40, "[E][%s] device ee: %s dev_state: %s\n", "mhi_debug_reg_dump", v23, v24);
  if ( !v22 || *(_DWORD *)(v22 + 24) > 2u )
    goto LABEL_97;
  if ( exec_env > 9 )
  {
    v26 = "INVALID_EE";
    if ( mhi_state > 3 )
      goto LABEL_76;
LABEL_82:
    if ( mhi_state > 1 )
    {
      if ( mhi_state == 2 )
        v27 = "M0";
      else
        v27 = "M1";
      goto LABEL_96;
    }
    if ( !mhi_state )
    {
      v27 = "RESET";
      goto LABEL_96;
    }
    if ( mhi_state == 1 )
    {
      v27 = "READY";
      goto LABEL_96;
    }
LABEL_95:
    v27 = "Unknown state";
    goto LABEL_96;
  }
  v26 = mhi_ee_str[exec_env];
  if ( mhi_state <= 3 )
    goto LABEL_82;
LABEL_76:
  if ( mhi_state <= 5 )
  {
    if ( mhi_state == 4 )
      v27 = "M2";
    else
      v27 = "M3";
    goto LABEL_96;
  }
  if ( mhi_state == 6 )
  {
    v27 = "M3_FAST";
    goto LABEL_96;
  }
  if ( mhi_state == 7 )
  {
    v27 = "BHI";
    goto LABEL_96;
  }
  if ( mhi_state != 255 )
    goto LABEL_95;
  v27 = "SYS ERROR";
LABEL_96:
  result = ipc_log_string(
             *(_QWORD *)(v22 + 32),
             "[E][%s] device ee: %s dev_state: %s\n",
             "mhi_debug_reg_dump",
             v26,
             v27);
LABEL_97:
  v28 = 0;
  while ( v31[v28] )
  {
    if ( v31[v28 + 2] )
    {
      reg = mhi_read_reg(a1);
      v30 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
      result = dev_err(
                 v3 + 40,
                 "[E][%s] reg: %s val: 0x%x, ret: %d\n",
                 "mhi_debug_reg_dump",
                 (const char *)v31[v28],
                 0,
                 reg);
      if ( v30 )
      {
        if ( *(_DWORD *)(v30 + 24) <= 2u )
          result = ipc_log_string(
                     *(_QWORD *)(v30 + 32),
                     "[E][%s] reg: %s val: 0x%x, ret: %d\n",
                     "mhi_debug_reg_dump",
                     (const char *)v31[v28],
                     0,
                     reg);
      }
    }
    v28 += 3;
    if ( v28 == 42 )
      __break(0x5512u);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
