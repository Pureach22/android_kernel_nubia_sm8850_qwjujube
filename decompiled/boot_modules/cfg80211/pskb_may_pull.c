bool __fastcall pskb_may_pull(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w9
  unsigned int v3; // w8
  bool v4; // cf
  unsigned int v5; // w8

  v2 = *(_DWORD *)(a1 + 112);
  v3 = v2 - *(_DWORD *)(a1 + 116);
  v4 = a2 >= v3;
  v5 = a2 - v3;
  if ( v5 == 0 || !v4 )
    return 1;
  if ( v2 < a2 )
    return 0;
  return _pskb_pull_tail(a1, v5) != 0;
}
