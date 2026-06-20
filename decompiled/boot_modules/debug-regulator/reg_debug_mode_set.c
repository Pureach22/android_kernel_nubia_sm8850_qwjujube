__int64 __fastcall reg_debug_mode_set(__int64 a1, unsigned int a2)
{
  unsigned __int64 v3; // x0
  __int64 result; // x0
  unsigned int v6; // w19

  v3 = *(_QWORD *)(a1 + 16);
  if ( v3 || (v3 = regulator_get(0), v3 <= 0xFFFFFFFFFFFFF000LL) && (*(_QWORD *)(a1 + 16) = v3) != 0 )
  {
    result = regulator_set_mode(v3, a2);
    if ( (_DWORD)result )
    {
      v6 = result;
      printk(&unk_81C8, "reg_debug_mode_set");
      return v6;
    }
  }
  else
  {
    printk(&unk_818A, "reg_debug_mode_set");
    return 4294967277LL;
  }
  return result;
}
