__int64 __fastcall mhi_rddm_download_status(__int64 a1)
{
  int v2; // w8
  __int64 v3; // x21
  __int64 v4; // x22
  unsigned int v5; // w8
  unsigned int v6; // w20
  unsigned int exec_env; // w20
  int v8; // w0
  __int64 v9; // x8
  int v10; // w19
  __int64 v11; // x21
  const char *v12; // x5
  __int64 v13; // x8
  __int64 result; // x0
  const char *v15; // x5
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 328);
  v3 = *(_QWORD *)(a1 + 48);
  v4 = *(_QWORD *)(a1 + 16);
  v16 = 0;
  v5 = 1000 * v2;
  if ( v5 >> 3 < 0x271 )
  {
LABEL_6:
    exec_env = mhi_get_exec_env(a1);
    v8 = mhi_read_reg(a1, v3, 120, &v16);
    v9 = *(_QWORD *)(a1 + 16);
    v10 = v8;
    v11 = *(_QWORD *)(v9 + 192);
    if ( exec_env <= 9 )
      v12 = mhi_ee_str[exec_env];
    else
      v12 = "INVALID_EE";
    dev_err(v4 + 40, "[E][%s] ret: %d, RXVEC_STATUS: 0x%x, EE:%s\n", "mhi_rddm_download_status", v8, v16, v12);
    if ( v11 && *(_DWORD *)(v11 + 24) <= 2u )
    {
      if ( exec_env <= 9 )
        v15 = mhi_ee_str[exec_env];
      else
        v15 = "INVALID_EE";
      ipc_log_string(
        *(_QWORD *)(v11 + 32),
        "[E][%s] ret: %d, RXVEC_STATUS: 0x%x, EE:%s\n",
        "mhi_rddm_download_status",
        v10,
        v16,
        v15);
    }
  }
  else
  {
    v6 = v5 / 0x1388;
    while ( !(unsigned int)mhi_read_reg_field(a1, v3, 120, 3221225472LL, &v16) )
    {
      if ( v16 == 2 )
      {
        v13 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
        if ( v13 && *(_DWORD *)(v13 + 24) <= 1u )
          ipc_log_string(*(_QWORD *)(v13 + 32), "[I][%s] RDDM dumps collected successfully", "mhi_rddm_download_status");
        result = 0;
        goto LABEL_20;
      }
      --v6;
      _const_udelay(21475000);
      if ( !v6 )
        goto LABEL_6;
    }
  }
  result = 4294967291LL;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
