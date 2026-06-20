__int64 __fastcall sde_recovery_regdump_open(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( a1 )
  {
    if ( a2 )
    {
      *(_DWORD *)(a2 + 12) &= 0xFFFFFFE3;
      *(_QWORD *)(a2 + 32) = *(_QWORD *)(a1 + 696);
      qword_2945C0 = 0;
      qword_2945C8 = 0;
      return 0;
    }
  }
  return result;
}
