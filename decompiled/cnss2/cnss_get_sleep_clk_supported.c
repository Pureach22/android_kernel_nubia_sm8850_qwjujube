__int64 __fastcall cnss_get_sleep_clk_supported(_BYTE *a1)
{
  __int64 property; // x0
  __int64 v3; // x7
  unsigned __int64 StatusReg; // x9
  const char *v5; // x1
  __int16 v6; // w10
  const char *v7; // x9
  char v9; // [xsp+0h] [xbp+0h]

  property = of_find_property(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "qcom,sleep-clk-support", 0);
  a1[7841] = property != 0;
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
           "cnss_get_sleep_clk_supported",
           7u,
           7u,
           "qcom,sleep-clk-support is %d\n",
           property != 0,
           v3,
           v9);
}
