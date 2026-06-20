__int64 __fastcall icnss_update_soc_level(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w20
  int property; // w0
  __int64 result; // x0
  _DWORD *v6; // x8
  int v7; // w20
  const char *v8; // x19
  __int64 v9; // x0
  int v10; // w20
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 16);
  v11[0] = 0;
  if ( v2 || (v2 = power_supply_get_by_name("battery"), (*(_QWORD *)(a1 - 16) = v2) != 0) )
  {
    property = power_supply_get_property(v2, 47, v11);
    if ( property )
    {
      v7 = property;
      printk("%sbattery percentage read error:%d\n", byte_130B32, property);
      ipc_log_string(icnss_ipc_log_context, "%sbattery percentage read error:%d\n", (const char *)&unk_12DBF3, v7);
LABEL_15:
      v8 = "%sBattery percentage read failure\n";
      printk("%sBattery percentage read failure\n", byte_130B32);
      v9 = icnss_ipc_log_context;
LABEL_16:
      result = ipc_log_string(v9, v8, &unk_12DBF3);
      goto LABEL_24;
    }
    v3 = v11[0];
  }
  else
  {
    v3 = 0;
  }
  printk("%sBattery Percentage: %d\n", byte_13289B, v3);
  result = ipc_log_string(icnss_ipc_log_context, "%sBattery Percentage: %d\n", (const char *)&unk_12DBF3, v3);
  if ( !v3 || v3 > 100 )
    goto LABEL_15;
  if ( v3 >= 70 )
  {
    v6 = &icnss_battery_level;
    goto LABEL_21;
  }
  if ( v3 > 59 )
  {
    v6 = &unk_A8BE8;
    goto LABEL_21;
  }
  if ( v3 > 49 )
  {
    v6 = &unk_A8BF0;
    goto LABEL_21;
  }
  if ( v3 > 24 )
  {
    v6 = &unk_A8BF8;
    goto LABEL_21;
  }
  if ( (v3 & 0x80000000) == 0 )
  {
    v6 = &unk_A8C00;
LABEL_21:
    v10 = v6[1];
    if ( *(_DWORD *)(a1 - 8) == v10 )
      goto LABEL_24;
    result = icnss_send_vbatt_update(a1 - 5888, v10);
    if ( (result & 0x80000000) == 0 )
    {
      *(_DWORD *)(a1 - 8) = v10;
      goto LABEL_24;
    }
    v8 = "%sUnable to update ldo voltage";
    printk("%sUnable to update ldo voltage", byte_130B32);
    v9 = icnss_ipc_log_context;
    goto LABEL_16;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
