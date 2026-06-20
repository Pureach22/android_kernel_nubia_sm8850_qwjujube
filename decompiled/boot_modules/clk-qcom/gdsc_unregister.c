__int64 __fastcall gdsc_unregister(__int64 *a1)
{
  unsigned __int64 v1; // x20
  __int64 v2; // x19
  __int64 v3; // x21
  unsigned __int64 v4; // x23
  int v5; // w22
  unsigned __int64 v6; // x8

  v1 = a1[2];
  v2 = *a1;
  if ( v1 )
  {
    v3 = a1[1];
    v4 = 0;
    v5 = 1;
    do
    {
      if ( *(_QWORD *)(v3 + 8 * v4) )
      {
        gdsc_genpd_debug_unregister();
        if ( *(_QWORD *)(*(_QWORD *)(v3 + 8 * v4) + 1536LL)
          || (v6 = *(_QWORD *)(v2 + 592)) != 0 && v6 <= 0xFFFFFFFFFFFFF000LL )
        {
          pm_genpd_remove_subdomain();
        }
      }
      v4 = v5++;
    }
    while ( v1 > v4 );
  }
  return of_genpd_del_provider(*(_QWORD *)(v2 + 744));
}
