__int64 __fastcall reg_debug_set_load(__int64 a1, unsigned int a2)
{
  unsigned __int64 v3; // x0
  __int64 result; // x0
  unsigned int v6; // w19

  v3 = *(_QWORD *)(a1 + 16);
  if ( v3 || (v3 = regulator_get(0), v3 <= 0xFFFFFFFFFFFFF000LL) && (*(_QWORD *)(a1 + 16) = v3) != 0 )
  {
    result = regulator_set_load(v3, a2);
    if ( (_DWORD)result )
    {
      v6 = result;
      printk(&unk_8038, "reg_debug_set_load");
      return v6;
    }
  }
  else
  {
    printk(&unk_818A, "reg_debug_set_load");
    return 4294967277LL;
  }
  return result;
}
