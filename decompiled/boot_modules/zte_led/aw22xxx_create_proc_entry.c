__int64 aw22xxx_create_proc_entry()
{
  __int64 v0; // x1

  if ( proc_create("driver/colorleds_id", 292, 0, &proc_ops_awid) )
    return printk(&unk_13D27, "aw22xxx_create_proc_entry");
  else
    return printk(&unk_1348E, v0);
}
