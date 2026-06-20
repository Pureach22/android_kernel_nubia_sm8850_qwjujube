__int64 __fastcall lcd_info_proc_open(__int64 a1, __int64 a2)
{
  return single_open(a2, lcd_info_proc_show, *(_QWORD *)(a1 + 696));
}
