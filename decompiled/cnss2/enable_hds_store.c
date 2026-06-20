__int64 __fastcall enable_hds_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v4; // x20
  __int64 v6; // x6
  __int64 v7; // x7
  int v8; // w8
  __int64 v9; // x0
  unsigned __int64 StatusReg; // x9
  const char *v11; // x1
  unsigned __int64 v12; // x8
  const char *v13; // x1
  __int16 v14; // w10
  const char *v15; // x9
  const char *v16; // x6
  __int16 v17; // w9
  const char *v18; // x8
  char v20; // [xsp+0h] [xbp-10h]
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v21 = 0;
  if ( v4 )
  {
    if ( sscanf(s, "%du", &v21) == 1 )
    {
      v8 = v21;
      v9 = cnss_ipc_log_context;
      *(_BYTE *)(v4 + 546) = v21 != 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v11 = "irq";
      }
      else
      {
        v14 = *(_DWORD *)(StatusReg + 16);
        v15 = (const char *)(StatusReg + 2320);
        if ( (v14 & 0xFF00) != 0 )
          v11 = "soft_irq";
        else
          v11 = v15;
      }
      if ( v8 )
        v16 = "Enable";
      else
        v16 = "Disable";
      cnss_debug_ipc_log_print(
        v9,
        v11,
        "enable_hds_store",
        7u,
        7u,
        "%s HDS file download, count is %zu\n",
        (__int64)v16,
        a4,
        v20);
    }
    else
    {
      v12 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else
      {
        v17 = *(_DWORD *)(v12 + 16);
        v18 = (const char *)(v12 + 2320);
        if ( (v17 & 0xFF00) != 0 )
          v13 = "soft_irq";
        else
          v13 = v18;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v13,
        "enable_hds_store",
        3u,
        3u,
        "Invalid enable_hds sysfs command\n",
        v6,
        v7,
        v20);
      a4 = -22;
    }
  }
  else
  {
    a4 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
