__int64 __fastcall cnss_get_platform_name(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 node_opts_by_path; // x0
  __int64 property; // x0
  __int64 v7; // x0
  unsigned __int64 StatusReg; // x9
  const char *v9; // x1
  __int16 v10; // w10
  const char *v11; // x9
  char v13; // [xsp+0h] [xbp+0h]

  v3 = 0;
  if ( a1 && a2 && a3 )
  {
    if ( of_find_property(*(_QWORD *)(*(_QWORD *)a1 + 760LL), "platform-name-required", 0)
      && (node_opts_by_path = of_find_node_opts_by_path("/", 0)) != 0
      && (property = of_get_property(node_opts_by_path, "model", 0)) != 0 )
    {
      v7 = sized_strscpy(a2, property);
      StatusReg = _ReadStatusReg(SP_EL0);
      v3 = v7;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v9 = "irq";
      }
      else
      {
        v10 = *(_DWORD *)(StatusReg + 16);
        v11 = (const char *)(StatusReg + 2320);
        if ( (v10 & 0xFF00) != 0 )
          v9 = "soft_irq";
        else
          v9 = v11;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v9,
        "cnss_get_platform_name",
        7u,
        7u,
        "Platform name: %s (%zu)\n",
        a2,
        v7,
        v13);
    }
    else
    {
      return 0;
    }
  }
  return v3;
}
