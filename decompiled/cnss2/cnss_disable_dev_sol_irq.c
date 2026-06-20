__int64 __fastcall cnss_disable_dev_sol_irq(__int64 a1)
{
  char v1; // w29
  __int64 result; // x0
  __int64 v3; // x7
  unsigned int v4; // w19
  unsigned __int64 StatusReg; // x9
  const char *v6; // x1
  __int16 v7; // w8
  const char *v8; // x9

  if ( (*(_DWORD *)(a1 + 136) & 0x80000000) != 0 || *(int *)(a1 + 140) < 1 )
    return 0;
  result = irq_set_irq_wake();
  if ( (_DWORD)result )
  {
    v4 = result;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v6 = "irq";
    }
    else
    {
      v7 = *(_DWORD *)(StatusReg + 16);
      v8 = (const char *)(StatusReg + 2320);
      if ( (v7 & 0xFF00) != 0 )
        v6 = "soft_irq";
      else
        v6 = v8;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v6,
      "cnss_disable_dev_sol_irq",
      3u,
      3u,
      "Failed to disable device SOL as wake IRQ, err = %d\n",
      (unsigned int)result,
      v3,
      v1);
    return v4;
  }
  return result;
}
