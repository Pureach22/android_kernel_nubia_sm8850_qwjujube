__int64 init_module()
{
  __int64 matching_node_and_match; // x0
  __int64 v1; // x20
  unsigned int v2; // w19
  __int64 v3; // x0
  __int64 v4; // x20

  matching_node_and_match = of_find_matching_node_and_match(0, &_mod_of__icnss_dt_match_device_table, 0);
  if ( matching_node_and_match )
  {
    v1 = matching_node_and_match;
    while ( (of_device_is_available(v1) & 1) == 0 )
    {
      v1 = of_find_matching_node_and_match(v1, &_mod_of__icnss_dt_match_device_table, 0);
      if ( !v1 )
        goto LABEL_5;
    }
    icnss_debug_init();
    v2 = _platform_driver_register(icnss_driver, &_this_module);
    if ( !v2 )
    {
      v3 = of_find_matching_node_and_match(0, &_mod_of__icnss_direct_link_dt_match_device_table, 0);
      if ( v3 )
      {
        v4 = v3;
        while ( (of_device_is_available(v4) & 1) == 0 )
        {
          v4 = of_find_matching_node_and_match(v4, &_mod_of__icnss_direct_link_dt_match_device_table, 0);
          if ( !v4 )
            goto LABEL_11;
        }
        v2 = _platform_driver_register(icnss_direct_link_driver, &_this_module);
        printk("%sicnss2: Direct link driver register status:%d", byte_13289B, v2);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2: Direct link driver register status:%d",
          (const char *)&unk_12DBF3,
          v2);
        if ( v2 )
        {
          platform_driver_unregister(icnss_driver);
          icnss_debug_deinit();
        }
      }
      else
      {
LABEL_11:
        ipc_log_string(icnss_ipc_log_context, "icnss2: No valid icnss2 direct link dtsi entry\n");
        return 0;
      }
    }
  }
  else
  {
LABEL_5:
    printk("%sicnss2: No valid icnss2 dtsi entry\n", byte_13289B);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: No valid icnss2 dtsi entry\n", (const char *)&unk_12DBF3);
    return (unsigned int)-19;
  }
  return v2;
}
