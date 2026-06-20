__int64 __fastcall user_config_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _BYTE *v4; // x20
  __int64 v6; // x7
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  __int16 v9; // w9
  const char *v10; // x8
  unsigned int v11; // w12
  int v12; // w10
  int v13; // w9
  __int64 v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_BYTE **)(a1 + 152);
  v15[0] = 0;
  if ( v4 )
  {
    if ( (unsigned int)kstrtoull(a3, 10, v15) )
    {
      a4 = -22;
    }
    else
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
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v8,
        "user_config_store",
        7u,
        7u,
        "Received User Config: %lu\n",
        v15[0],
        v6,
        v15[0]);
      v11 = (unsigned __int8)v4[7952];
      v12 = v15[0] & 1;
      v13 = (LODWORD(v15[0]) >> 1) & 1;
      v4[7952] = v11 | 1;
      if ( ((v11 >> 1) & 1) != v12 || ((v11 >> 2) & 1) != v13 )
      {
        v4[7952] = (2 * v12) | (4 * v13) | v11 & 0xF8 | 1;
        cnss_xdump_update_config(v4);
      }
    }
  }
  else
  {
    a4 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
