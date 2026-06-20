__int64 __fastcall cnss_force_collect_rddm(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  __int64 v5; // x19
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  unsigned __int64 v8; // x8
  const char *v9; // x1
  __int64 v10; // x6
  __int64 v11; // x7
  unsigned __int64 v12; // x8
  __int64 v13; // x0
  const char *v14; // x1
  __int16 v15; // w9
  const char *v16; // x8
  __int64 result; // x0
  __int16 v18; // w9
  const char *v19; // x8
  __int16 v20; // w9
  const char *v21; // x8
  const char *v22; // x5
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  const char *v25; // x1
  __int16 v26; // w9
  const char *v27; // x8
  int v28; // w0
  __int64 v29; // x7
  unsigned __int64 v30; // x8
  const char *v31; // x1
  __int16 v32; // w9
  const char *v33; // x8
  __int16 v34; // w9
  const char *v35; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( v2 )
  {
    v5 = v2;
    if ( *(_QWORD *)(v2 + 528) == 62 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v7 = "irq";
      }
      else
      {
        v18 = *(_DWORD *)(StatusReg + 16);
        v19 = (const char *)(StatusReg + 2320);
        if ( (v18 & 0xFF00) != 0 )
          v7 = "soft_irq";
        else
          v7 = v19;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v7,
        "cnss_force_collect_rddm",
        6u,
        6u,
        "Force collect rddm is not supported\n",
        v3,
        v4,
        vars0);
      return 4294967201LL;
    }
    if ( (unsigned int)cnss_bus_is_device_down(v2) )
    {
      v12 = _ReadStatusReg(SP_EL0);
      v13 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else
      {
        v20 = *(_DWORD *)(v12 + 16);
        v21 = (const char *)(v12 + 2320);
        if ( (v20 & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = v21;
      }
      v22 = "Device is already in bad state, wait to collect rddm\n";
LABEL_37:
      cnss_debug_ipc_log_print(v13, v14, "cnss_force_collect_rddm", 6u, 6u, v22, v10, v11, vars0);
LABEL_38:
      *(_DWORD *)(v5 + 6616) = 0;
      cnss_get_qmi_timeout(v5);
      v28 = wait_for_completion_timeout(v5 + 6616, 5000);
      if ( v28 )
        return v28 & (unsigned int)(v28 >> 31);
      v30 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v30 + 16) & 0xF0000) != 0 )
      {
        v31 = "irq";
      }
      else
      {
        v32 = *(_DWORD *)(v30 + 16);
        v33 = (const char *)(v30 + 2320);
        if ( (v32 & 0xFF00) != 0 )
          v31 = "soft_irq";
        else
          v31 = v33;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v31,
        "cnss_force_collect_rddm",
        3u,
        3u,
        "Timeout (%ums) waiting for RDDM to complete\n",
        20000,
        v29,
        vars0);
      return 4294967186LL;
    }
    if ( (*(_QWORD *)(v5 + 552) & 0x200) != 0 )
    {
      v23 = _ReadStatusReg(SP_EL0);
      v13 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v23 + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else
      {
        v26 = *(_DWORD *)(v23 + 16);
        v27 = (const char *)(v23 + 2320);
        if ( (v26 & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = v27;
      }
      v22 = "Recovery is already in progress, wait to collect rddm\n";
      goto LABEL_37;
    }
    if ( (*(_QWORD *)(v5 + 552) & 0x10) == 0
      && (*(_QWORD *)(v5 + 552) & 0x20) == 0
      && (*(_QWORD *)(v5 + 552) & 0x40) == 0
      && (*(_QWORD *)(v5 + 552) & 0x80) == 0 )
    {
      result = cnss_bus_force_fw_assert_hdlr(v5);
      if ( (_DWORD)result )
        return result;
      goto LABEL_38;
    }
    v24 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v24 + 16) & 0xF0000) != 0 )
    {
      v25 = "irq";
    }
    else
    {
      v34 = *(_DWORD *)(v24 + 16);
      v35 = (const char *)(v24 + 2320);
      if ( (v34 & 0xFF00) != 0 )
        v25 = "soft_irq";
      else
        v25 = v35;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v25,
      "cnss_force_collect_rddm",
      6u,
      6u,
      "Loading/Unloading/idle restart/shutdown is in progress, ignore forced collect rddm\n",
      v10,
      v11,
      vars0);
    return 0;
  }
  else
  {
    v8 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v8 + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v15 = *(_DWORD *)(v8 + 16);
      v16 = (const char *)(v8 + 2320);
      if ( (v15 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v16;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v9,
      "cnss_force_collect_rddm",
      3u,
      3u,
      "plat_priv is NULL\n",
      v3,
      v4,
      vars0);
    return 4294967277LL;
  }
}
