__int64 __fastcall nop_set_host(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = 4294967277LL;
  if ( a1 )
  {
    *(_QWORD *)(a1 + 24) = a2;
    if ( a2 )
      return 0;
    else
      return 4294967277LL;
  }
  return result;
}
