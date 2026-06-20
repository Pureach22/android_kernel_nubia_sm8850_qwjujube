bool __fastcall pskb_may_pull(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w9

  v2 = *(_DWORD *)(a1 + 112);
  if ( a2 <= v2 - *(_DWORD *)(a1 + 116) )
    return 1;
  if ( v2 < a2 )
    return 0;
  return _pskb_pull_tail(a1) != 0;
}
