__int64 __fastcall icnss_get_psf_info(_QWORD *a1)
{
  __int64 v2; // x0
  int v3; // w0
  __int64 result; // x0
  unsigned int v5; // w20

  v2 = alloc_workqueue("icnss_soc_update", 2, 1);
  a1[740] = v2;
  if ( v2 )
  {
    a1[731] = icnss_battery_supply_callback;
    v3 = power_supply_reg_notifier(a1 + 731);
    if ( v3 < 0 )
    {
      v5 = v3;
      printk("%sPower supply framework registration err: %d\n", byte_130B32, v3);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sPower supply framework registration err: %d\n",
        (const char *)&unk_12DBF3,
        v5);
      destroy_workqueue(a1[740]);
      return v5;
    }
    else
    {
      result = 0;
      a1[736] = 0xFFFFFFFE00000LL;
      a1[737] = a1 + 737;
      a1[738] = a1 + 737;
      a1[739] = icnss_update_soc_level;
    }
  }
  else
  {
    printk("%sWorkqueue creation failed for soc update\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sWorkqueue creation failed for soc update\n", (const char *)&unk_12DBF3);
    return 4294967282LL;
  }
  return result;
}
