__int64 __fastcall gdsc_genpd_debug_create_one(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x21
  unsigned __int64 v5; // x20
  void *v6; // x0
  unsigned __int64 file; // x8
  unsigned __int64 v8; // x8

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v4 = *(_QWORD *)(a1 + 16);
    v5 = debugfs_lookup(*(_QWORD *)(v4 + 1288), a2);
    v6 = &unk_28A1B;
    if ( v5
      && v5 <= 0xFFFFFFFFFFFFF000LL
      && (file = debugfs_create_file("enable", 420, v5, a1, &gdsc_genpd_debug_enable_fops), v6 = &unk_2924E, file)
      && file <= 0xFFFFFFFFFFFFF000LL
      && ((*(_WORD *)(v4 + 1602) & 4) == 0
       || (v8 = debugfs_create_file("hwctrl", 420, v5, a1, &gdsc_genpd_debug_hwctrl_fops), v6 = &unk_284DD, v8)
       && v8 < 0xFFFFFFFFFFFFF001LL) )
    {
      return 0;
    }
    else
    {
      printk(v6);
      return 4294967294LL;
    }
  }
  return result;
}
