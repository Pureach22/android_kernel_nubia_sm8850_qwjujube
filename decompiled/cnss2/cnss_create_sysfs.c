__int64 __fastcall cnss_create_sysfs(__int64 *a1)
{
  __int64 v2; // x7
  unsigned int v3; // w19
  unsigned __int64 StatusReg; // x8
  const char *v5; // x1
  __int64 v6; // x20
  unsigned int link; // w0
  __int64 v8; // x7
  unsigned __int64 v9; // x8
  const char *v10; // x1
  __int16 v11; // w9
  const char *v12; // x8
  unsigned int v13; // w0
  __int64 v14; // x7
  unsigned __int64 v15; // x8
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  __int16 v19; // w9
  const char *v20; // x8
  char v22; // [xsp+0h] [xbp-40h]
  _QWORD v23[4]; // [xsp+8h] [xbp-38h] BYREF
  char v24[5]; // [xsp+28h] [xbp-18h] BYREF
  __int64 v25; // [xsp+2Dh] [xbp-13h]
  __int16 v26; // [xsp+35h] [xbp-Bh]
  __int64 v27; // [xsp+38h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = devm_device_add_group(*a1 + 16, &cnss_attr_group);
  if ( v3 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v5 = "irq";
    }
    else
    {
      v11 = *(_DWORD *)(StatusReg + 16);
      v12 = (const char *)(StatusReg + 2320);
      if ( (v11 & 0xFF00) != 0 )
        v5 = "soft_irq";
      else
        v5 = v12;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v5,
      "cnss_create_sysfs",
      3u,
      3u,
      "Failed to create cnss device group, err = %d\n",
      v3,
      v2,
      v22);
  }
  else
  {
    v6 = *a1;
    strcpy(v24, "cnss");
    v25 = 0;
    v26 = 0;
    memset((char *)&v23[1] + 6, 0, 18);
    strcpy((char *)v23, "shutdown_wlan");
    link = sysfs_create_link(kernel_kobj, v6 + 16, v24);
    if ( link )
    {
      v9 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v10 = "irq";
      }
      else
      {
        v17 = *(_DWORD *)(v9 + 16);
        v18 = (const char *)(v9 + 2320);
        if ( (v17 & 0xFF00) != 0 )
          v10 = "soft_irq";
        else
          v10 = v18;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v10,
        "cnss_create_sysfs_link",
        3u,
        3u,
        "Failed to create cnss link, err = %d\n",
        link,
        v8,
        v22);
    }
    else
    {
      v13 = sysfs_create_link(kernel_kobj, v6 + 16, v23);
      if ( v13 )
      {
        v15 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
        {
          v16 = "irq";
        }
        else
        {
          v19 = *(_DWORD *)(v15 + 16);
          v20 = (const char *)(v15 + 2320);
          if ( (v19 & 0xFF00) != 0 )
            v16 = "soft_irq";
          else
            v16 = v20;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v16,
          "cnss_create_sysfs_link",
          3u,
          3u,
          "Failed to create shutdown_wlan link, err = %d\n",
          v13,
          v14,
          v22);
        sysfs_remove_link(kernel_kobj, v24);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
