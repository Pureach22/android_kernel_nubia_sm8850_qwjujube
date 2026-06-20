__int64 __fastcall synx_test_release(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x8
  __int64 result; // x0

  v2 = *(_QWORD *)(a2 + 32);
  result = 4294967274LL;
  if ( v2 )
  {
    if ( v2 <= 0xFFFFFFFFFFFFF000LL )
    {
      kfree(v2);
      return 0;
    }
  }
  return result;
}
