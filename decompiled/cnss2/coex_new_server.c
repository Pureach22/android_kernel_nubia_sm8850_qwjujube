__int64 __fastcall coex_new_server(__int64 *a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v3; // x21
  const char *v6; // x1
  int v7; // w9
  int v8; // w10
  __int64 v9; // x0
  unsigned int v10; // w0
  __int64 v11; // x6
  __int64 v12; // x7
  const char *v14; // x1
  unsigned int v15; // w19
  const char *v16; // x1
  __int64 result; // x0
  unsigned __int64 v23; // x9
  char v24; // [xsp+0h] [xbp-20h]
  char v25; // [xsp+0h] [xbp-20h]
  _DWORD v26[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = _ReadStatusReg(SP_EL0);
  v27 = *(_QWORD *)(StatusReg + 1808);
  v26[0] = 0;
  if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
  {
    v6 = "irq";
  }
  else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
  {
    v6 = "soft_irq";
  }
  else
  {
    v6 = (const char *)(v3 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v6,
    "coex_new_server",
    7u,
    7u,
    "COEX server arrive: node %u port %u\n",
    *(unsigned int *)(a2 + 12),
    *(unsigned int *)(a2 + 16),
    v24);
  v7 = *(_DWORD *)(a2 + 12);
  v8 = *(_DWORD *)(a2 + 16);
  v9 = *a1;
  LOWORD(v26[0]) = 42;
  v26[1] = v7;
  v26[2] = v8;
  v10 = kernel_connect(v9, v26, 12, 0);
  if ( (v10 & 0x80000000) != 0 )
  {
    v15 = v10;
    if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
    {
      v16 = "soft_irq";
    }
    else
    {
      v16 = (const char *)(v3 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v16,
      "coex_new_server",
      3u,
      3u,
      "Fail to connect to remote service port\n",
      v11,
      v12,
      v25);
    result = v15;
  }
  else
  {
    _X8 = (unsigned __int64 *)(a1 - 776);
    __asm { PRFM            #0x11, [X8] }
    do
      v23 = __ldxr(_X8);
    while ( __stxr(v23 | 0x2000, _X8) );
    if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
    {
      v14 = "soft_irq";
    }
    else
    {
      v14 = (const char *)(v3 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "coex_new_server",
      7u,
      7u,
      "COEX Server Connected: 0x%lx\n",
      *_X8,
      v12,
      v25);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
