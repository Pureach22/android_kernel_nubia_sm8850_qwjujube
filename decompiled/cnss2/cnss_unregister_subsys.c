__int64 __fastcall cnss_unregister_subsys(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x6
  __int64 v3; // x7
  unsigned __int64 StatusReg; // x8
  const char *v5; // x1
  __int16 v6; // w9
  const char *v7; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  result = atomic_notifier_chain_unregister(&panic_notifier_list, a1 + 424);
  if ( (_DWORD)result )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v5 = "irq";
    }
    else
    {
      v6 = *(_DWORD *)(StatusReg + 16);
      v7 = (const char *)(StatusReg + 2320);
      if ( (v6 & 0xFF00) != 0 )
        v5 = "soft_irq";
      else
        v5 = v7;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v5,
             "cnss_unregister_subsys",
             3u,
             3u,
             "Failed to unregister panic handler\n",
             v2,
             v3,
             vars0);
  }
  return result;
}
