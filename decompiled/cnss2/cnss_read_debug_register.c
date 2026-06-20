__int64 __fastcall cnss_read_debug_register(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  char v8; // w29
  unsigned __int64 StatusReg; // x8
  const char *v10; // x1
  __int16 v11; // w9
  const char *v12; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else
  {
    v11 = *(_DWORD *)(StatusReg + 16);
    v12 = (const char *)(StatusReg + 2320);
    if ( (v11 & 0xFF00) != 0 )
      v10 = "soft_irq";
    else
      v10 = v12;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v10,
    "cnss_read_debug_register",
    6u,
    6u,
    "Entering negative cnss_read_debug_register function\n",
    a7,
    a8,
    v8);
  return 0;
}
