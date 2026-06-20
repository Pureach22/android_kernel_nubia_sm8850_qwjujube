__int64 __fastcall fs_ready_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  unsigned __int64 StatusReg; // x21
  const char *v7; // x1
  __int64 v8; // x6
  __int64 v9; // x7
  __int64 v10; // x0
  const char *v11; // x1
  const char *v12; // x5
  unsigned int v13; // w3
  unsigned int v14; // w4
  unsigned __int64 v22; // x9
  char v23; // [xsp+0h] [xbp-10h]
  char v24; // [xsp+0h] [xbp-10h]
  unsigned int v25; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v25 = 0;
  if ( sscanf(s, "%du", &v25) != 1 )
  {
    a4 = -22;
    goto LABEL_27;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v7 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v7 = "soft_irq";
  }
  else
  {
    v7 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v7,
    "fs_ready_store",
    7u,
    7u,
    "File system is ready, fs_ready is %d, count is %zu\n",
    v25,
    a4,
    v23);
  if ( !v5 )
  {
    v10 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v11 = "soft_irq";
    }
    else
    {
      v11 = (const char *)(StatusReg + 2320);
    }
    v12 = "plat_priv is NULL\n";
    v13 = 3;
    v14 = 3;
    goto LABEL_26;
  }
  if ( (*(_QWORD *)(v5 + 6680) & 0x10) != 0 )
  {
    v10 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v11 = "soft_irq";
    }
    else
    {
      v11 = (const char *)(StatusReg + 2320);
    }
    v12 = "QMI is bypassed\n";
    v13 = 7;
    v14 = 7;
LABEL_26:
    cnss_debug_ipc_log_print(v10, v11, "fs_ready_store", v13, v14, v12, v8, v9, v24);
    goto LABEL_27;
  }
  _X8 = (unsigned __int64 *)(v5 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 | 0x2000000, _X8) );
  if ( v25 == 1 && *(_BYTE *)(v5 + 7488) == 1 )
    cnss_driver_event_post(v5, 5u, 0, 0);
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return a4;
}
