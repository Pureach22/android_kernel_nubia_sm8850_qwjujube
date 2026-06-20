__int64 init_module()
{
  __int64 matching_node_and_match; // x0
  __int64 v1; // x20
  unsigned int v2; // w19
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x7
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  __int16 v8; // w9
  const char *v9; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  matching_node_and_match = of_find_matching_node_and_match(0, &_mod_of__cnss_of_match_table_device_table, 0);
  if ( matching_node_and_match )
  {
    v1 = matching_node_and_match;
    while ( (of_device_is_available(v1) & 1) == 0 )
    {
      v1 = of_find_matching_node_and_match(v1, &_mod_of__cnss_of_match_table_device_table, 0);
      if ( !v1 )
        return (unsigned int)-19;
    }
    v3 = of_find_matching_node_and_match(0, &_mod_of__cnss_of_match_table_device_table, 0);
    if ( v3 )
    {
      v4 = v3;
      while ( (of_device_is_available(v4) & 1) == 0 )
      {
        v4 = of_find_matching_node_and_match(v4, &_mod_of__cnss_of_match_table_device_table, 0);
        if ( !v4 )
          return 0;
      }
      cnss_allow_driver_loading = 1;
      cnss_debug_init();
      if ( (unsigned int)_platform_driver_register(cnss_platform_driver, &_this_module) )
        cnss_debug_deinit();
      v2 = cnss_genl_init();
      if ( (v2 & 0x80000000) != 0 )
      {
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
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v7,
          "cnss_initialize",
          3u,
          3u,
          "CNSS genl init failed %d\n",
          v2,
          v5,
          vars0);
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return (unsigned int)-19;
  }
  return v2;
}
