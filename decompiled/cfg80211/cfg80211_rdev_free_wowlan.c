__int64 __fastcall cfg80211_rdev_free_wowlan(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x21
  _QWORD *v5; // x0

  v1 = *(_QWORD *)(result + 1248);
  if ( v1 )
  {
    v2 = result;
    if ( *(int *)(v1 + 24) >= 1 )
    {
      v3 = 0;
      v4 = 0;
      do
      {
        kfree(*(_QWORD *)(*(_QWORD *)(v1 + 8) + v3));
        v1 = *(_QWORD *)(v2 + 1248);
        ++v4;
        v3 += 24;
      }
      while ( v4 < *(int *)(v1 + 24) );
    }
    kfree(*(_QWORD *)(v1 + 8));
    v5 = *(_QWORD **)(*(_QWORD *)(v2 + 1248) + 16LL);
    if ( v5 )
    {
      if ( *v5 )
      {
        sock_release(*v5);
        v5 = *(_QWORD **)(*(_QWORD *)(v2 + 1248) + 16LL);
      }
    }
    kfree(v5);
    kfree(*(_QWORD *)(*(_QWORD *)(v2 + 1248) + 32LL));
    return kfree(*(_QWORD *)(v2 + 1248));
  }
  return result;
}
