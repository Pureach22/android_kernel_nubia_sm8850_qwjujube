__int64 __fastcall cnss_force_fw_assert(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  unsigned __int64 StatusReg; // x8
  const char *v6; // x1
  unsigned __int64 v7; // x8
  const char *v8; // x1
  __int64 v9; // x19
  __int64 v10; // x6
  __int64 v11; // x7
  unsigned __int64 v12; // x8
  __int64 v13; // x0
  const char *v14; // x1
  __int16 v15; // w9
  const char *v16; // x8
  __int16 v18; // w9
  const char *v19; // x8
  __int16 v20; // w9
  const char *v21; // x8
  const char *v22; // x5
  unsigned __int64 v23; // x8
  __int16 v24; // w9
  const char *v25; // x8
  char v26; // [xsp+0h] [xbp+0h]

  v2 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( v2 )
  {
    if ( *(_QWORD *)(v2 + 528) == 62 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v6 = "irq";
      }
      else
      {
        v18 = *(_DWORD *)(StatusReg + 16);
        v19 = (const char *)(StatusReg + 2320);
        if ( (v18 & 0xFF00) != 0 )
          v6 = "soft_irq";
        else
          v6 = v19;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v6,
        "cnss_force_fw_assert",
        6u,
        6u,
        "Forced FW assert is not supported\n",
        v3,
        v4,
        v26);
      return 4294967201LL;
    }
    v9 = v2;
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
      v22 = "Device is already in bad state, ignore force assert\n";
    }
    else
    {
      if ( (*(_QWORD *)(v9 + 552) & 0x200) == 0 )
      {
        if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0 || (_ReadStatusReg(DAIF) & 0x80) != 0 )
          cnss_driver_event_post(v9, 0xAu, 0, 0);
        else
          cnss_bus_force_fw_assert_hdlr(v9);
        return 0;
      }
      v23 = _ReadStatusReg(SP_EL0);
      v13 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v23 + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else
      {
        v24 = *(_DWORD *)(v23 + 16);
        v25 = (const char *)(v23 + 2320);
        if ( (v24 & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = v25;
      }
      v22 = "Recovery is already in progress, ignore forced FW assert\n";
    }
    cnss_debug_ipc_log_print(v13, v14, "cnss_force_fw_assert", 6u, 6u, v22, v10, v11, v26);
    return 0;
  }
  v7 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v7 + 16) & 0xF0000) != 0 )
  {
    v8 = "irq";
  }
  else
  {
    v15 = *(_DWORD *)(v7 + 16);
    v16 = (const char *)(v7 + 2320);
    if ( (v15 & 0xFF00) != 0 )
      v8 = "soft_irq";
    else
      v8 = v16;
  }
  cnss_debug_ipc_log_print(cnss_ipc_log_context, v8, "cnss_force_fw_assert", 3u, 3u, "plat_priv is NULL\n", v3, v4, v26);
  return 4294967277LL;
}
