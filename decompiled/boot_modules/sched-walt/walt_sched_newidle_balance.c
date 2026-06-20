__int64 __fastcall walt_sched_newidle_balance(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4, _DWORD *a5)
{
  __int64 result; // x0

  if ( (walt_disabled & 1) == 0 && !*(_DWORD *)(a2 + 72) )
    return walt_newidle_balance(a2, a3, a4, a5, 0);
  return result;
}
