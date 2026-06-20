__int64 __fastcall htc_system_resume(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    if ( *(_WORD *)(result + 12) )
      result = htc_try_send(result, (_DWORD *)(result + 8), 0);
    if ( *(_WORD *)(v1 + 340) )
      result = htc_try_send(v1, (_DWORD *)(v1 + 336), 0);
    if ( *(_WORD *)(v1 + 668) )
      result = htc_try_send(v1, (_DWORD *)(v1 + 664), 0);
    if ( *(_WORD *)(v1 + 996) )
      result = htc_try_send(v1, (_DWORD *)(v1 + 992), 0);
    if ( *(_WORD *)(v1 + 1324) )
      result = htc_try_send(v1, (_DWORD *)(v1 + 1320), 0);
    if ( *(_WORD *)(v1 + 1652) )
      result = htc_try_send(v1, (_DWORD *)(v1 + 1648), 0);
    if ( *(_WORD *)(v1 + 1980) )
      result = htc_try_send(v1, (_DWORD *)(v1 + 1976), 0);
    if ( *(_WORD *)(v1 + 2308) )
      result = htc_try_send(v1, (_DWORD *)(v1 + 2304), 0);
    if ( *(_WORD *)(v1 + 2636) )
      return htc_try_send(v1, (_DWORD *)(v1 + 2632), 0);
  }
  return result;
}
