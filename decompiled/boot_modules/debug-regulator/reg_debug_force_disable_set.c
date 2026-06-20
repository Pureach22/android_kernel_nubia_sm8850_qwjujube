__int64 __fastcall reg_debug_force_disable_set(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w19

  if ( *(_QWORD *)(a1 + 16) || (v4 = regulator_get(0), v4 <= 0xFFFFFFFFFFFFF000LL) && (*(_QWORD *)(a1 + 16) = v4) != 0 )
  {
    if ( a2 )
    {
      result = regulator_force_disable();
      if ( (_DWORD)result )
      {
        v6 = result;
        printk(&unk_7D62, "reg_debug_force_disable_set");
        return v6;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    printk(&unk_818A, "reg_debug_force_disable_set");
    return 4294967277LL;
  }
  return result;
}
