__int64 __fastcall cnss_get_cpumask_for_wlan_txrx_intr(__int64 *a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v4; // x6
  __int64 v5; // x7
  int v6; // w9
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  __int16 v9; // w9
  const char *v10; // x8
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v11[0] = 0;
  result = of_property_read_variable_u32_array(*(_QWORD *)(v2 + 760), "wlan-txrx-intr-cpumask", v11, 2, 0);
  if ( (result & 0x80000000) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v9 = *(_DWORD *)(StatusReg + 16);
      v10 = (const char *)(StatusReg + 2320);
      if ( (v9 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v10;
    }
    result = cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v8,
               "cnss_get_cpumask_for_wlan_txrx_intr",
               3u,
               3u,
               "Failed to get cpumask for wlan txrx interrupts",
               v4,
               v5,
               v11[0]);
  }
  else
  {
    v6 = HIDWORD(v11[0]);
    *((_DWORD *)a1 + 1963) = v11[0];
    *((_DWORD *)a1 + 1964) = v6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
