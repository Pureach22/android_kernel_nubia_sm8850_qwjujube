__int64 __fastcall ieee80211_hw_roc_start(__int64 a1, __int64 a2)
{
  __int64 *v2; // x20
  __int64 *v3; // x21
  __int64 result; // x0

  v3 = (__int64 *)(a2 - 16);
  v2 = *(__int64 **)(a2 - 16);
  if ( v2 != (__int64 *)(a2 - 16) )
  {
    do
    {
      if ( *((_BYTE *)v2 + 32) != 1 )
        break;
      *((_BYTE *)v2 + 34) = 1;
      result = ieee80211_handle_roc_started(v2, *(_QWORD *)(a2 + 48));
      v2 = (__int64 *)*v2;
    }
    while ( v2 != v3 );
  }
  return result;
}
