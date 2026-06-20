__int64 __fastcall dms_new_server(__int64 *a1, __int64 a2)
{
  unsigned int v2; // w20
  unsigned int v3; // w21
  __int64 v5; // x0
  __int64 v6; // x7
  unsigned int v7; // w19
  unsigned __int64 v9; // x9
  const char *v10; // x1
  unsigned __int64 StatusReg; // x8
  const char *v12; // x1
  __int16 v13; // w10
  const char *v14; // x9
  __int16 v15; // w9
  const char *v16; // x8
  unsigned __int64 v23; // x9
  char v24; // [xsp+0h] [xbp-20h]
  _DWORD v25[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = *(_DWORD *)(a2 + 12);
    v3 = *(_DWORD *)(a2 + 16);
    v5 = *a1;
    v25[0] = 42;
    v25[1] = v2;
    v25[2] = v3;
    v7 = kernel_connect(v5, v25, 12, 0);
    if ( (v7 & 0x80000000) != 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v12 = "irq";
      }
      else
      {
        v15 = *(_DWORD *)(StatusReg + 16);
        v16 = (const char *)(StatusReg + 2320);
        if ( (v15 & 0xFF00) != 0 )
          v12 = "soft_irq";
        else
          v12 = v16;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v12,
        "cnss_dms_connect_to_server",
        3u,
        3u,
        "Failed to connect to QMI DMS remote service Node: %d Port: %d\n",
        v2,
        v3,
        v24);
    }
    else
    {
      _X8 = (unsigned __int64 *)(a1 - 76);
      __asm { PRFM            #0x11, [X8] }
      do
        v23 = __ldxr(_X8);
      while ( __stxr(v23 | 0x100000, _X8) );
      v9 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v10 = "irq";
      }
      else
      {
        v13 = *(_DWORD *)(v9 + 16);
        v14 = (const char *)(v9 + 2320);
        if ( (v13 & 0xFF00) != 0 )
          v10 = "soft_irq";
        else
          v10 = v14;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v10,
        "cnss_dms_connect_to_server",
        6u,
        6u,
        "QMI DMS service connected, state: 0x%lx\n",
        *_X8,
        v6,
        v24);
    }
  }
  else
  {
    v7 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
