__int64 __fastcall hwmon_dev_release(__int64 a1)
{
  __int64 *v1; // x20
  __int64 v3; // x0
  int v4; // w21

  v1 = *(__int64 **)(a1 + 960);
  if ( v1 )
  {
    v3 = *v1;
    if ( *v1 )
    {
      v4 = 1;
      do
      {
        kfree(v3);
        v3 = v1[v4++];
      }
      while ( v3 );
    }
    kfree(v1);
  }
  kfree(*(_QWORD *)(a1 + 976));
  kfree(*(_QWORD *)(a1 - 8));
  return kfree(a1 - 16);
}
