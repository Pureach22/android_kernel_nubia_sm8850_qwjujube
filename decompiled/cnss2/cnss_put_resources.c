__int64 __fastcall cnss_put_resources(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  const char *v10; // x1
  __int16 v11; // w9
  const char *v12; // x8
  char vars0; // [xsp+0h] [xbp+0h]

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
    "cnss_xo_trim_deinit",
    7u,
    7u,
    "XO trim de-initialized\n",
    a7,
    a8,
    vars0);
  if ( *(_BYTE *)(a1 + 7880) == 1 )
  {
    if ( *(_BYTE *)(a1 + 6513) )
    {
      cnss_fw_managed_power_gpio(a1, 0);
      cnss_fw_managed_power_regulator(a1, 0);
    }
    return cnss_fw_managed_domain_detach(a1);
  }
  else
  {
    cnss_put_clk(a1);
    return cnss_put_vreg_type(a1, 0);
  }
}
