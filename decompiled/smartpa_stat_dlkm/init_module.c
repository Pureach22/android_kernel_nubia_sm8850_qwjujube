__int64 __fastcall init_module(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 data; // x0
  __int64 v5; // x2
  __int64 v6; // x3
  bool v7; // zf
  void *v8; // x0
  unsigned int v9; // w20

  printk(&unk_62E0, "smartpa_stat_t_init", a3, a4);
  data = proc_create_data("driver/smarttest", 292, 0, &smartpa_stat_fops, 0);
  v7 = data == 0;
  if ( data )
    v8 = &unk_6300;
  else
    v8 = &unk_6337;
  if ( v7 )
    v9 = -12;
  else
    v9 = 0;
  printk(v8, "smartpa_stat_t_init", v5, v6);
  return v9;
}
