__int64 __fastcall ieee80211_free_tid_rx(__int64 a1)
{
  unsigned int v1; // w8
  unsigned __int64 v3; // x20
  __int64 v4; // x22
  __int64 *v5; // x1
  __int64 v7; // x8
  _QWORD *v8; // x9

  v1 = *(unsigned __int16 *)(a1 + 150);
  if ( *(_WORD *)(a1 + 150) )
  {
    v3 = 0;
    do
    {
      v4 = *(_QWORD *)(a1 + 32) + 24 * v3;
      v5 = *(__int64 **)v4;
      if ( *(_QWORD *)v4 != v4 && v5 != nullptr )
      {
        do
        {
          --*(_DWORD *)(v4 + 16);
          v7 = *v5;
          v8 = (_QWORD *)v5[1];
          *v5 = 0;
          v5[1] = 0;
          *(_QWORD *)(v7 + 8) = v8;
          *v8 = v7;
          sk_skb_reason_drop(0);
          v5 = *(__int64 **)v4;
        }
        while ( *(_QWORD *)v4 != v4 && v5 );
        v1 = *(unsigned __int16 *)(a1 + 150);
      }
      ++v3;
    }
    while ( v3 < v1 );
  }
  kfree(*(_QWORD *)(a1 + 32));
  kfree(*(_QWORD *)(a1 + 40));
  return kfree(a1);
}
