__int64 __fastcall lcd_info_proc_show(__int64 a1, __int64 a2)
{
  const char **v2; // x8

  v2 = *(const char ***)(a1 + 128);
  if ( v2 )
  {
    seq_printf(a1, "%s\n", *v2);
    return 0;
  }
  else
  {
    printk(&unk_275910, a2);
    return 4294967277LL;
  }
}
