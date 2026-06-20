__int64 __fastcall gh_irq_lend(unsigned int a1, __int64 a2, __int64 a3, __int64 a4)
{
  bool v5; // cc
  __int64 result; // x0

  v5 = a1 > 5;
  result = 4294967274LL;
  if ( !v5 )
  {
    if ( a4 )
    {
      *(_QWORD *)&gh_irq_entries[20 * a1 + 8] = a4;
      return 0;
    }
  }
  return result;
}
