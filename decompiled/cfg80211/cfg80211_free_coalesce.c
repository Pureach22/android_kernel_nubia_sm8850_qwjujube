int *__fastcall cfg80211_free_coalesce(int *result)
{
  int v1; // w8
  int *v2; // x19
  __int64 v3; // x20
  __int64 v4; // x23
  __int64 v5; // x24
  __int64 v6; // x25

  if ( result )
  {
    v1 = *result;
    v2 = result;
    if ( *result >= 1 )
    {
      v3 = 0;
      do
      {
        v4 = (__int64)&v2[6 * v3 + 2];
        if ( v4 )
        {
          if ( *(int *)(v4 + 16) >= 1 )
          {
            v5 = 0;
            v6 = 0;
            do
            {
              kfree(*(_QWORD *)(*(_QWORD *)(v4 + 8) + v5));
              ++v6;
              v5 += 24;
            }
            while ( v6 < *(int *)(v4 + 16) );
          }
          kfree(*(_QWORD *)(v4 + 8));
          v1 = *v2;
        }
        ++v3;
      }
      while ( v3 < v1 );
    }
    return (int *)kfree(v2);
  }
  return result;
}
