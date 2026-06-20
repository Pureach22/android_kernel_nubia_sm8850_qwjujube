__int64 __fastcall load_panel_info(__int64 a1)
{
  const char *v2; // x0

  printk(&unk_25CC85, *(_QWORD *)(a1 + 8));
  if ( !strcmp(*(const char **)(a1 + 8), "primary") )
    v2 = "driver/lcd_id";
  else
    v2 = "driver/sec_lcd_id";
  return proc_create_data(v2, 436, 0, &lcd_info_proc_fops, a1);
}
