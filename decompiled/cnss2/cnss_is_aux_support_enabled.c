__int64 __fastcall cnss_is_aux_support_enabled(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v8; // x8
  bool v9; // cc
  __int64 v10; // x8
  unsigned __int64 v13; // x8
  __int64 v14; // x0
  const char *v15; // x1
  unsigned __int64 StatusReg; // x8
  __int16 v17; // w9
  const char *v18; // x8
  const char *v19; // x5
  __int16 v20; // w9
  const char *v21; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 528) - 4366LL;
  v9 = v8 > 4;
  v10 = (1LL << v8) & 0x19;
  if ( v9 || v10 == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v20 = *(_DWORD *)(StatusReg + 16);
      v21 = (const char *)(StatusReg + 2320);
      if ( (v20 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v21;
    }
    v19 = "Host does not support aux uc capability\n";
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 7513) & 1) != 0 )
      return 1;
    v13 = _ReadStatusReg(SP_EL0);
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(v13 + 16);
      v18 = (const char *)(v13 + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v18;
    }
    v19 = "FW does not support aux uc capability\n";
  }
  cnss_debug_ipc_log_print(v14, v15, "cnss_is_aux_support_enabled", 7u, 7u, v19, a7, a8, vars0);
  return 0;
}
