__int64 __fastcall qdf_nbuf_set_pktlen_0(_DWORD *a1, __int64 a2)
{
  unsigned int v2; // w9
  unsigned int v3; // w8
  int v5; // w20
  int v6; // w9
  int v7; // w9
  int v8; // w10
  _DWORD *v9; // x19
  int v10; // w8

  v2 = a1[28];
  v3 = a2 - v2;
  if ( (unsigned int)a2 < v2 )
    return skb_trim(a1, a2);
  if ( a1[29] )
  {
    v3 = a2 - v2;
    if ( (_DWORD)a2 != v2 )
    {
      v5 = a2;
      v6 = 0;
      goto LABEL_8;
    }
  }
  else
  {
    v8 = a1[52];
    v7 = a1[53];
    if ( v7 - v8 < v3 )
    {
      v5 = a2;
      v6 = v8 - v7;
LABEL_8:
      v9 = a1;
      v10 = pskb_expand_head(a1, 0, v6 + v3, 2080);
      a1 = v9;
      LODWORD(a2) = v5;
      if ( v10 )
      {
        dev_kfree_skb_any_reason(v9, 1);
        LODWORD(a2) = v5;
        a1 = v9;
      }
    }
  }
  return skb_put(a1, (unsigned int)(a2 - a1[28]));
}
