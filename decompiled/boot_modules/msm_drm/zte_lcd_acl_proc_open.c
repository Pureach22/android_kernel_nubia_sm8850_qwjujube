__int64 __fastcall zte_lcd_acl_proc_open(__int64 a1, __int64 a2)
{
  return single_open(a2, zte_lcd_acl_show, *(_QWORD *)(a1 + 696));
}
