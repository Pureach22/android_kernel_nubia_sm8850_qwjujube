__int64 __fastcall qdf_nbuf_put_tail(_DWORD *a1, unsigned __int64 a2)
{
  unsigned int v2; // w19
  int v3; // w8
  int v4; // w8
  int v5; // w9
  _DWORD *v6; // x20
  int v7; // w8

  v2 = a2;
  if ( a1[29] )
  {
    if ( !a2 )
      return skb_put(a1, v2);
    v3 = 0;
  }
  else
  {
    v5 = a1[52];
    v4 = a1[53];
    if ( v4 - v5 >= a2 )
      return skb_put(a1, v2);
    v3 = v5 - v4;
  }
  v6 = a1;
  v7 = pskb_expand_head(a1, 0, (unsigned int)(v3 + a2), 2080);
  a1 = v6;
  if ( v7 )
    return dev_kfree_skb_any_reason(v6, 1);
  return skb_put(a1, v2);
}
