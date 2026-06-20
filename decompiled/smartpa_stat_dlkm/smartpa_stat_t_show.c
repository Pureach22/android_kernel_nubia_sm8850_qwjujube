__int64 __fastcall smartpa_stat_t_show(__int64 a1)
{
  bool v2; // zf
  __int64 v3; // x2

  printk(&unk_630A, "smartpa_stat_t_show", (unsigned int)smartpa_t_cnt, (unsigned int)smartpa_t_stat);
  if ( smartpa_t_cnt )
    v2 = smartpa_t_cnt == smartpa_t_stat;
  else
    v2 = 0;
  v3 = v2;
  seq_printf(a1, &unk_62EB, v3);
  return 0;
}
