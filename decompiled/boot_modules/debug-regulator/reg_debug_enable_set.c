__int64 __fastcall reg_debug_enable_set(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // w8
  void *v7; // x0
  unsigned int v8; // w19

  if ( !*(_QWORD *)(a1 + 16) )
  {
    v4 = regulator_get(0);
    if ( v4 > 0xFFFFFFFFFFFFF000LL || (*(_QWORD *)(a1 + 16) = v4) == 0 )
    {
      printk(&unk_818A, "reg_debug_enable_set");
      return 4294967277LL;
    }
  }
  if ( a2 )
  {
    result = regulator_enable();
    if ( (_DWORD)result )
    {
      v6 = result;
      v7 = &unk_822A;
LABEL_11:
      v8 = v6;
      printk(v7, "reg_debug_enable_set");
      return v8;
    }
  }
  else
  {
    result = regulator_disable();
    if ( (_DWORD)result )
    {
      v6 = result;
      v7 = &unk_7F36;
      goto LABEL_11;
    }
  }
  return result;
}
