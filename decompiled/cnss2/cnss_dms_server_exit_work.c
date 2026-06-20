__int64 __fastcall cnss_dms_server_exit_work(__int64 a1)
{
  _QWORD *v2; // x19
  __int64 v3; // x6
  __int64 v4; // x7
  unsigned __int64 StatusReg; // x21
  const char *v6; // x1
  __int64 result; // x0
  __int64 v8; // x7
  const char *v9; // x1
  unsigned __int64 v15; // x8
  unsigned __int64 v17; // x9
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  _X20 = (unsigned __int64 *)(a1 - 272);
  __asm { PRFM            #0x11, [X20] }
  do
    v15 = __ldxr(_X20);
  while ( __stxr(v15 | 0x8000000, _X20) );
  v2 = (_QWORD *)(a1 - 824);
  qmi_handle_release(a1 + 336);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v6 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v6 = "soft_irq";
  }
  else
  {
    v6 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v6,
    "cnss_dms_server_exit_work",
    6u,
    6u,
    "QMI DMS Server Exit",
    v3,
    v4,
    vars0);
  __asm { PRFM            #0x11, [X20] }
  do
    v17 = __ldxr(_X20);
  while ( __stxr(v17 & 0xFFFFFFFFF7FFFFFFLL, _X20) );
  result = cnss_dms_init(v2);
  if ( (result & 0x80000000) != 0 )
  {
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
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v9,
             "cnss_dms_server_exit_work",
             3u,
             3u,
             "QMI DMS service registraton failed, ret\n",
             (unsigned int)result,
             v8,
             vars0a);
  }
  return result;
}
