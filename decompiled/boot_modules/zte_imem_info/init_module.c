__int64 init_module()
{
  if ( proc_mkdir("vendor_imem", 0) )
  {
    if ( !proc_create("vendor_imem/ddr_id", 292, 0, &ddr_id_proc_fops) )
    {
LABEL_9:
      remove_proc_entry("vendor_imem", 0);
      return 0;
    }
    if ( !proc_create("vendor_imem/board_id", 292, 0, &board_id_proc_fops) )
    {
LABEL_8:
      remove_proc_entry("vendor_imem/ddr_id", 0);
      goto LABEL_9;
    }
    if ( !proc_create("driver/ddr_id", 292, 0, &ddr_id_proc_fops) )
    {
LABEL_7:
      remove_proc_entry("vendor_imem/board_id", 0);
      goto LABEL_8;
    }
    if ( !proc_create("driver/board_id", 292, 0, &board_id_proc_fops) )
    {
      remove_proc_entry("driver/ddr_id", 0);
      goto LABEL_7;
    }
  }
  return 0;
}
