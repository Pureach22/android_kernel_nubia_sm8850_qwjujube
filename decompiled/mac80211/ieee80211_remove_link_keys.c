__int64 __fastcall ieee80211_remove_link_keys(__int64 result, __int64 *a2)
{
  __int64 *v2; // x21
  __int64 v3; // x22
  __int64 v4; // x19
  __int64 *v6; // x23
  __int64 **v7; // x1

  v2 = *(__int64 **)(*(_QWORD *)result + 1512LL);
  v3 = *(_QWORD *)result + 1512LL;
  if ( v2 != (__int64 *)v3 )
  {
    v4 = result;
    do
    {
      v6 = (__int64 *)*v2;
      if ( *(_DWORD *)(v4 + 8) == *((char *)v2 + 530) )
      {
        result = ieee80211_key_replace(
                   *(v2 - 2),
                   (unsigned __int64 *)v4,
                   *(v2 - 1),
                   (v2[66] & 8) != 0,
                   (unsigned __int64)(v2 - 3),
                   0);
        v7 = (__int64 **)a2[1];
        if ( v2 == a2 || v7 == (__int64 **)v2 || *v7 != a2 )
        {
          result = _list_add_valid_or_report(v2, v7);
        }
        else
        {
          a2[1] = (__int64)v2;
          *v2 = (__int64)a2;
          v2[1] = (__int64)v7;
          *v7 = v2;
        }
      }
      v2 = v6;
    }
    while ( v6 != (__int64 *)v3 );
  }
  return result;
}
