__int64 __fastcall reg_debug_enable_get(__int64 a1, _QWORD *a2)
{
  unsigned __int64 v4; // x0
  int is_enabled; // w8

  if ( *(_QWORD *)(a1 + 16) || (v4 = regulator_get(0), v4 <= 0xFFFFFFFFFFFFF000LL) && (*(_QWORD *)(a1 + 16) = v4) != 0 )
  {
    is_enabled = regulator_is_enabled();
    *a2 = is_enabled;
    return 0;
  }
  else
  {
    printk(&unk_818A, "reg_debug_enable_get");
    return 4294967277LL;
  }
}
