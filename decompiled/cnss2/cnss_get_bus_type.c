__int64 __fastcall cnss_get_bus_type(__int64 a1)
{
  int v1; // w8
  __int64 result; // x0
  __int64 v3; // x6
  unsigned __int64 v4; // x8
  const char *v5; // x1
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  unsigned __int64 v8; // x8
  const char *v9; // x1
  __int16 v10; // w9
  const char *v11; // x8
  __int16 v12; // w9
  const char *v13; // x8
  __int16 v14; // w9
  const char *v15; // x8
  unsigned int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD *)(a1 + 7736);
  v16 = -1;
  if ( v1 == 2 )
  {
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "qcom,bus-type", &v16, 1, 0)
        & 0x80000000) != 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v7 = "irq";
      }
      else
      {
        v10 = *(_DWORD *)(StatusReg + 16);
        v11 = (const char *)(StatusReg + 2320);
        if ( (v10 & 0xFF00) != 0 )
          v7 = "soft_irq";
        else
          v7 = v11;
      }
      cnss_debug_ipc_log_print(cnss_ipc_log_context, v7, "cnss_get_bus_type", 3, 3, "No bus type for multi-exchg dt\n");
      result = v16;
    }
    else if ( v16 )
    {
      v16 = -1;
      result = 0xFFFFFFFFLL;
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
        v12 = *(_DWORD *)(v8 + 16);
        v13 = (const char *)(v8 + 2320);
        if ( (v12 & 0xFF00) != 0 )
          v9 = "soft_irq";
        else
          v9 = v13;
      }
      cnss_debug_ipc_log_print(cnss_ipc_log_context, v9, "cnss_get_bus_type", 7, 7, "Got bus type[%u] from dt\n", 0);
      result = v16;
    }
  }
  else
  {
    v3 = *(_QWORD *)(a1 + 528);
    result = 0;
    if ( ((unsigned __int64)(v3 - 4352) > 0x12 || ((1LL << v3) & 0x6448F) == 0) && v3 != 62 )
    {
      v4 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v4 + 16) & 0xF0000) != 0 )
      {
        v5 = "irq";
      }
      else
      {
        v14 = *(_DWORD *)(v4 + 16);
        v15 = (const char *)(v4 + 2320);
        if ( (v14 & 0xFF00) != 0 )
          v5 = "soft_irq";
        else
          v5 = v15;
      }
      cnss_debug_ipc_log_print(cnss_ipc_log_context, v5, "cnss_get_bus_type", 3, 3, "Unknown device_id: 0x%lx\n", v3);
      result = 0xFFFFFFFFLL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
