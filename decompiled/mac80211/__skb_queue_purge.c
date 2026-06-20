__int64 **__fastcall _skb_queue_purge(__int64 **result)
{
  __int64 *v1; // x1
  __int64 **v2; // x19
  __int64 v3; // x8
  _QWORD *v4; // x9

  v1 = *result;
  if ( *result != (__int64 *)result && v1 )
  {
    v2 = result;
    do
    {
      --*((_DWORD *)v2 + 4);
      v3 = *v1;
      v4 = (_QWORD *)v1[1];
      *v1 = 0;
      v1[1] = 0;
      *(_QWORD *)(v3 + 8) = v4;
      *v4 = v3;
      result = (__int64 **)sk_skb_reason_drop(0);
      v1 = *v2;
    }
    while ( *v2 != (__int64 *)v2 && v1 );
  }
  return result;
}
