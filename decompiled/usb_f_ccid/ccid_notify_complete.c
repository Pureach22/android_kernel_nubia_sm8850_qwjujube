__int64 __fastcall ccid_notify_complete(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x1
  __int64 result; // x0

  v3 = *(unsigned int *)(a2 + 84);
  if ( (_DWORD)v3 != -108 && (_DWORD)v3 != -104 )
  {
    if ( (_DWORD)v3 )
      return printk(&unk_816C, v3, a3);
  }
  return result;
}
