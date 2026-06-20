__int64 __fastcall ieee80211_roc_purge(__int64 result, __int64 a2)
{
  __int64 *v2; // x23
  __int64 v3; // x22
  __int64 v4; // x19
  char v6; // w24
  __int64 *v7; // x21

  v2 = *(__int64 **)(result + 5264);
  v3 = result + 5264;
  if ( v2 != (__int64 *)(result + 5264) )
  {
    v4 = result;
    v6 = 0;
LABEL_3:
    v7 = v2;
    do
    {
      v2 = (__int64 *)*v7;
      if ( !a2 || v7[2] == a2 )
      {
        if ( *((_BYTE *)v7 + 32) == 1 )
        {
          if ( !*(_QWORD *)(*(_QWORD *)(v4 + 464) + 472LL) )
          {
            v6 = 1;
            *((_BYTE *)v7 + 33) = 1;
            if ( v2 != (__int64 *)v3 )
              goto LABEL_3;
            return _ieee80211_roc_work(v4);
          }
          drv_cancel_remain_on_channel(v4, v7[2]);
        }
        result = ieee80211_roc_notify_destroy(v7);
      }
      v7 = v2;
    }
    while ( v2 != (__int64 *)v3 );
    if ( (v6 & 1) == 0 )
      return result;
    return _ieee80211_roc_work(v4);
  }
  return result;
}
