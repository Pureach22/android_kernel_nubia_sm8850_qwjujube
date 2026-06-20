__int64 __fastcall cnss_wlfw_server_exit(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x20
  const char *v10; // x1
  __int64 result; // x0
  unsigned int v12; // w0
  __int64 v13; // x7
  const char *v14; // x1
  __int64 v15; // x7
  const char *v16; // x1
  unsigned __int64 v23; // x10
  unsigned __int64 v26; // x10
  char v27; // [xsp+0h] [xbp+0h]
  char v28; // [xsp+0h] [xbp+0h]
  char v29; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967277LL;
  _X8 = (unsigned __int64 *)(a1 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v23 = __ldxr(_X8);
  while ( __stxr(v23 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v10 = "soft_irq";
  }
  else
  {
    v10 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v10,
    "cnss_wlfw_server_exit",
    6u,
    6u,
    "QMI WLFW service disconnected, state: 0x%lx\n",
    *(_QWORD *)(a1 + 552),
    a8,
    v27);
  qmi_handle_release(a1 + 856);
  _X8 = (unsigned __int64 *)(a1 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v26 = __ldxr(_X8);
  while ( __stxr(v26 & 0xFFFFFFFFFFF7FFFFLL, _X8) );
  v12 = cnss_qmi_init(a1);
  if ( (v12 & 0x80000000) == 0 )
    return 0;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v14 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v14 = "soft_irq";
  }
  else
  {
    v14 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v14,
    "cnss_wlfw_server_exit",
    3u,
    3u,
    "QMI WLFW service registraton failed, ret\n",
    v12,
    v13,
    v28);
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
    "cnss_wlfw_server_exit",
    3u,
    3u,
    "ASSERT at line %d\n",
    3801,
    v15,
    v29);
  result = 0;
  __break(0x800u);
  return result;
}
