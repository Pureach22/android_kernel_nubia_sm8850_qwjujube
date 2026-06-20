__int64 __fastcall dms_del_server(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x6
  unsigned __int64 v10; // x10
  __int64 v11; // x19
  const char *v12; // x1
  unsigned __int64 StatusReg; // x8
  const char *v14; // x1
  __int16 v15; // w11
  const char *v16; // x10
  __int16 v17; // w9
  const char *v18; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x10
  char v27; // [xsp+0h] [xbp+0h]

  if ( result != 1160 )
  {
    _X9 = (unsigned __int64 *)(result - 608);
    v9 = *(_QWORD *)(result - 608);
    if ( (v9 & 0x8000000) != 0 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else
      {
        v17 = *(_DWORD *)(StatusReg + 16);
        v18 = (const char *)(StatusReg + 2320);
        if ( (v17 & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = v18;
      }
      return cnss_debug_ipc_log_print(
               cnss_ipc_log_context,
               v14,
               "dms_del_server",
               6u,
               6u,
               "DMS server delete or cnss remove in progress, Ignore server delete: 0x%lx\n",
               v9,
               a8,
               v27);
    }
    else
    {
      __asm { PRFM            #0x11, [X9] }
      do
        v24 = __ldxr(_X9);
      while ( __stxr(v24 | 0x8000000, _X9) );
      __asm { PRFM            #0x11, [X9] }
      do
        v26 = __ldxr(_X9);
      while ( __stxr(v26 & 0xFFFFFFFFFFEFFFFFLL, _X9) );
      v10 = _ReadStatusReg(SP_EL0);
      v11 = result;
      if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
      {
        v12 = "irq";
      }
      else
      {
        v15 = *(_DWORD *)(v10 + 16);
        v16 = (const char *)(v10 + 2320);
        if ( (v15 & 0xFF00) != 0 )
          v12 = "soft_irq";
        else
          v12 = v16;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v12,
        "dms_del_server",
        6u,
        6u,
        "QMI DMS service disconnected, state: 0x%lx\n",
        *_X9,
        a8,
        v27);
      return queue_work_on(32, system_wq, v11 - 336);
    }
  }
  return result;
}
