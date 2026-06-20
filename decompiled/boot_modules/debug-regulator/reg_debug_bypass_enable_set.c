__int64 __fastcall reg_debug_bypass_enable_set(__int64 a1)
{
  unsigned __int64 v2; // x0

  if ( *(_QWORD *)(a1 + 16) )
    return regulator_allow_bypass();
  v2 = regulator_get(0);
  if ( v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    *(_QWORD *)(a1 + 16) = v2;
    if ( v2 )
      return regulator_allow_bypass();
  }
  printk(&unk_818A, "reg_debug_bypass_enable_set");
  return 4294967277LL;
}
