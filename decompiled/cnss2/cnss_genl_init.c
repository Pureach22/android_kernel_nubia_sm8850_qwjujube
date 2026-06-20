__int64 cnss_genl_init()
{
  __int64 v0; // x7
  unsigned int v1; // w19
  unsigned __int64 StatusReg; // x8
  const char *v3; // x1
  __int16 v4; // w9
  const char *v5; // x8
  char v7; // [xsp+0h] [xbp+0h]

  v1 = genl_register_family(&cnss_genl_family);
  if ( v1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v3 = "irq";
    }
    else
    {
      v4 = *(_DWORD *)(StatusReg + 16);
      v5 = (const char *)(StatusReg + 2320);
      if ( (v4 & 0xFF00) != 0 )
        v3 = "soft_irq";
      else
        v3 = v5;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v3,
      "cnss_genl_init",
      3u,
      3u,
      "genl_register_family fail: %d\n",
      v1,
      v0,
      v7);
  }
  return v1;
}
