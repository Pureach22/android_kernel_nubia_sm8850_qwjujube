__int64 __fastcall icnss_wlan_enable(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v5; // x19
  __int64 v8; // x8
  unsigned int v9; // w8
  __int64 result; // x0
  unsigned int v11; // w20
  const char *v12; // x20
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v13 = 0;
  if ( (*(_QWORD *)(v5 + 1832) & 0x2000) != 0 || (*(_QWORD *)(v5 + 1832) & 4) == 0 )
  {
    v12 = "%sicnss2: FW down, ignoring wlan_enable state: 0x%lx\n";
    printk("%sicnss2: FW down, ignoring wlan_enable state: 0x%lx\n", byte_130B32);
LABEL_21:
    ipc_log_string(icnss_ipc_log_context, v12, &unk_12DBF3, *(_QWORD *)(v5 + 1832));
    result = 4294967274LL;
    goto LABEL_22;
  }
  if ( (*(_QWORD *)(v5 + 1832) & 0x10000) != 0 )
  {
    v12 = "%sicnss2: Already Mode on, ignoring wlan_enable state: 0x%lx\n";
    printk("%sicnss2: Already Mode on, ignoring wlan_enable state: 0x%lx\n", byte_130B32);
    goto LABEL_21;
  }
  if ( *(_BYTE *)(v5 + 5968) == 1 && !*(_BYTE *)(v5 + 5649) && !*(_BYTE *)(v5 + 5648) )
    icnss_setup_dms_mac(v5);
  v8 = *(_QWORD *)(v5 + 304);
  if ( (v8 | 0x1000) == 0x7750 )
  {
    if ( !(unsigned int)icnss_get_temperature(v5, &v13) )
    {
      ipc_log_string(icnss_ipc_log_context, "icnss2: Temperature: %d\n", v13);
      if ( v13 <= 4999 )
      {
        v9 = *(_DWORD *)(v5 + 5784);
        if ( v9 <= 0x1F4 )
          v9 = 500;
        *(_DWORD *)(v5 + 5780) = v9;
      }
    }
    v8 = *(_QWORD *)(v5 + 304);
  }
  if ( v8 == 25680 )
    icnss_hw_power_off(v5);
  result = icnss_send_wlan_enable_to_fw(v5, a2, a3, a4);
  if ( *(_QWORD *)(v5 + 304) == 25680 )
  {
    v11 = result;
    icnss_hw_power_on(v5);
    result = v11;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
