__int64 create_pump_proc_entry()
{
  __int64 v0; // x0
  __int64 v1; // x5
  __int64 v2; // x6
  __int64 v3; // x4
  __int64 v4; // x5
  __int64 v5; // x6
  __int64 v6; // x4
  __int64 v7; // x5
  __int64 v8; // x6
  __int64 v9; // x4
  __int64 v10; // x5
  __int64 v11; // x6
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 result; // x0
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6

  v0 = proc_mkdir("driver/micropump", 0);
  micro_pump_proc_entry = v0;
  if ( !v0 )
    return printk(&unk_992F, "aw86320", 1022, "create_pump_proc_entry", "create_pump_proc_entry", v1, v2);
  if ( !proc_create("icid", 436, v0, &proc_ops_icid) )
    printk(&unk_A3E7, "aw86320", 1029, "create_pump_proc_entry", v3, v4, v5);
  if ( !proc_create("enable", 436, micro_pump_proc_entry, &proc_ops_enable) )
    printk(&unk_9614, "aw86320", 1034, "create_pump_proc_entry", v6, v7, v8);
  if ( !proc_create("speed", 436, micro_pump_proc_entry, &proc_ops_speed) )
    printk(&unk_9641, "aw86320", 1039, "create_pump_proc_entry", v9, v10, v11);
  if ( !proc_create("freq", 436, micro_pump_proc_entry, &proc_ops_freq) )
    printk(&unk_9DCB, "aw86320", 1044, "create_pump_proc_entry", v12, v13, v14);
  if ( !proc_create("reg", 146, micro_pump_proc_entry, &proc_ops_reg) )
    printk(&unk_9844, "aw86320", 1049, "create_pump_proc_entry", v15, v16, v17);
  if ( !proc_create("update", 146, micro_pump_proc_entry, &proc_ops_update) )
    printk(&unk_986E, "aw86320", 1054, "create_pump_proc_entry", v18, v19, v20);
  result = proc_create("time", 146, micro_pump_proc_entry, &proc_ops_duration);
  if ( !result )
    return printk(&unk_A3E7, "aw86320", 1059, "create_pump_proc_entry", v22, v23, v24);
  return result;
}
