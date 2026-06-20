__int64 __fastcall cnss_plat_ipc_register(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v8; // x8
  const char *v9; // x1
  __int64 *v10; // x8
  int v11; // w9
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  __int16 v17; // w9
  const char *v18; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( (int)a1 < 2 )
  {
    if ( a1 < 3 )
    {
      v10 = &plat_ipc_qmi_svc[5 * a1];
      v11 = *((_DWORD *)v10 + 28);
      if ( v11 >= 1 )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v13 = "irq";
        }
        else
        {
          v17 = *(_DWORD *)(StatusReg + 16);
          v18 = (const char *)(StatusReg + 2320);
          if ( (v17 & 0xFF00) != 0 )
            v13 = "soft_irq";
          else
            v13 = v18;
        }
        cnss_plat_ipc_debug_log_print(
          cnss_plat_ipc_log_context,
          v13,
          "cnss_plat_ipc_register",
          byte_80DC,
          "Max Service users reached\n",
          a1,
          a7,
          a8,
          vars0);
        return 4294967274LL;
      }
      if ( !v11 )
      {
        v10[12] = a2;
        v10[13] = a3;
        *((_DWORD *)v10 + 28) = 1;
        return 0;
      }
    }
    __break(0x5512u);
    JUMPOUT(0x6A70);
  }
  v8 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v8 + 16) & 0xF0000) != 0 )
  {
    v9 = "irq";
  }
  else
  {
    v14 = *(_DWORD *)(v8 + 16);
    v15 = (const char *)(v8 + 2320);
    if ( (v14 & 0xFF00) != 0 )
      v9 = "soft_irq";
    else
      v9 = v15;
  }
  cnss_plat_ipc_debug_log_print(
    cnss_plat_ipc_log_context,
    v9,
    "cnss_plat_ipc_register",
    byte_80DC,
    "Invalid Client ID: %d\n",
    a1,
    a7,
    a8,
    vars0);
  return 4294967274LL;
}
