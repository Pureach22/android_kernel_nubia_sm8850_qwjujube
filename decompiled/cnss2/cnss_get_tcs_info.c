__int64 __fastcall cnss_get_tcs_info(_QWORD *a1)
{
  __int64 v2; // x20
  _QWORD *resource_byname; // x0
  __int64 v4; // x6
  __int64 v5; // x7
  __int64 v6; // x8
  _QWORD *v7; // x21
  unsigned __int64 StatusReg; // x22
  const char *v9; // x1
  unsigned __int64 v10; // x8
  const char *v11; // x1
  __int64 v12; // x0
  __int64 v13; // x7
  __int64 v14; // x8
  __int64 result; // x0
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  resource_byname = (_QWORD *)platform_get_resource_byname(*a1, 512, "tcs_cmd");
  if ( resource_byname )
  {
    v6 = *resource_byname;
    v7 = resource_byname;
    StatusReg = _ReadStatusReg(SP_EL0);
    a1[937] = v6;
    v19[0] = resource_byname[1] - v6 + 1;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v9 = "soft_irq";
    }
    else
    {
      v9 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v9,
      "cnss_get_tcs_info",
      7u,
      7u,
      "TCS CMD base address is %pa with length %pa\n",
      (__int64)(a1 + 937),
      (__int64)v19,
      v19[0]);
    v12 = devm_ioremap(v2 + 16, *v7, v19[0]);
    if ( v12 )
    {
      v14 = v12;
      result = 0;
      a1[938] = v14;
    }
    else
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v16 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v16 = "soft_irq";
      }
      else
      {
        v16 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v16,
        "cnss_get_tcs_info",
        3u,
        3u,
        "Failed to map TCS CMD address, err = %d\n",
        4294967274LL,
        v13,
        v19[0]);
      result = 4294967274LL;
    }
  }
  else
  {
    v10 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(v10 + 16);
      v18 = (const char *)(v10 + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v18;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "cnss_get_tcs_info",
      7u,
      7u,
      "TCS CMD address is not present for CPR\n",
      v4,
      v5,
      v19[0]);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
