__int64 __fastcall _cnss_start_rddm_timer(__int64 a1, __int64 a2, unsigned int a3)
{
  char v5; // w0
  unsigned __int64 StatusReg; // x10
  const char *v7; // x1
  __int16 v8; // w11
  const char *v9; // x10

  v5 = mod_timer(a1 + 400, jiffies + 1250LL);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v7 = "irq";
  }
  else
  {
    v8 = *(_DWORD *)(StatusReg + 16);
    v9 = (const char *)(StatusReg + 2320);
    if ( (v8 & 0xFF00) != 0 )
      v7 = "soft_irq";
    else
      v7 = v9;
  }
  return cnss_debug_ipc_log_print(
           cnss_ipc_log_context,
           v7,
           "__cnss_start_rddm_timer",
           7u,
           7u,
           "Start RDDM timer @%s(%d), ret %d\n",
           a2,
           a3,
           v5);
}
