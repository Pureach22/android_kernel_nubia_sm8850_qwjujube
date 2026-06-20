__int64 __fastcall purge_old_ps_buffers(__int64 result)
{
  __int64 *v1; // x21
  __int64 v2; // x19
  __int64 v3; // x22
  int v4; // w20
  __int64 *i; // x21
  __int64 v6; // x1
  __int64 v7; // x0

  v1 = *(__int64 **)(result + 4616);
  v2 = result;
  v3 = result + 4616;
  if ( v1 == (__int64 *)(result + 4616) )
  {
    v4 = 0;
  }
  else
  {
    v4 = 0;
    do
    {
      if ( *((_DWORD *)v1 + 1180) == 3 )
      {
        result = skb_dequeue(v1 + 317);
        if ( result )
          result = ieee80211_free_txskb(v2, result);
        v4 += *((_DWORD *)v1 + 638);
      }
      v1 = (__int64 *)*v1;
    }
    while ( v1 != (__int64 *)v3 );
  }
  for ( i = *(__int64 **)(v2 + 1616); i != (__int64 *)(v2 + 1616); i = (__int64 *)*i )
  {
    v7 = skb_dequeue(i + 38);
    v4 += *((_DWORD *)i + 80);
    if ( v7
      || (v7 = skb_dequeue(i + 35), v4 += *((_DWORD *)i + 74), v7)
      || (v7 = skb_dequeue(i + 32), v4 += *((_DWORD *)i + 68), v7) )
    {
      v6 = v7;
    }
    else
    {
      result = skb_dequeue(i + 29);
      v6 = result;
      v4 += *((_DWORD *)i + 62);
      if ( !result )
        continue;
    }
    result = ieee80211_free_txskb(v2, v6);
  }
  *(_DWORD *)(v2 + 5000) = v4;
  return result;
}
