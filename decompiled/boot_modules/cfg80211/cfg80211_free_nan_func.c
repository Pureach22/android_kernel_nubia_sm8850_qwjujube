__int64 __fastcall cfg80211_free_nan_func(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned __int64 v3; // x21
  __int64 v4; // x20
  unsigned __int64 v5; // x21

  if ( result )
  {
    v1 = result;
    kfree(*(_QWORD *)(result + 32));
    kfree(*(_QWORD *)(v1 + 48));
    kfree(*(_QWORD *)(v1 + 64));
    if ( *(_BYTE *)(v1 + 97) )
    {
      v2 = 0;
      v3 = 0;
      do
      {
        kfree(*(_QWORD *)(*(_QWORD *)(v1 + 80) + v2));
        ++v3;
        v2 += 16;
      }
      while ( v3 < *(unsigned __int8 *)(v1 + 97) );
    }
    if ( *(_BYTE *)(v1 + 96) )
    {
      v4 = 0;
      v5 = 0;
      do
      {
        kfree(*(_QWORD *)(*(_QWORD *)(v1 + 88) + v4));
        ++v5;
        v4 += 16;
      }
      while ( v5 < *(unsigned __int8 *)(v1 + 96) );
    }
    kfree(*(_QWORD *)(v1 + 80));
    kfree(*(_QWORD *)(v1 + 88));
    return kfree(v1);
  }
  return result;
}
