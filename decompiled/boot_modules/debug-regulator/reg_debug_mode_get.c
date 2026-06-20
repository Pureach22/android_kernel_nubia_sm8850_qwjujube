__int64 __fastcall reg_debug_mode_get(__int64 a1, _QWORD *a2)
{
  unsigned __int64 v4; // x0
  unsigned int mode; // w0
  __int64 v6; // x8
  __int64 result; // x0
  unsigned int v8; // w19

  if ( *(_QWORD *)(a1 + 16) || (v4 = regulator_get(0), v4 <= 0xFFFFFFFFFFFFF000LL) && (*(_QWORD *)(a1 + 16) = v4) != 0 )
  {
    mode = regulator_get_mode();
    if ( (mode & 0x80000000) != 0 )
    {
      v8 = mode;
      printk(&unk_7FF8, "reg_debug_mode_get");
      return v8;
    }
    else
    {
      v6 = mode;
      result = 0;
      *a2 = v6;
    }
  }
  else
  {
    printk(&unk_818A, "reg_debug_mode_get");
    return 4294967277LL;
  }
  return result;
}
