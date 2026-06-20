__int64 __fastcall coresight_add_sysfs_link(__int64 *a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 result; // x0
  __int64 v5; // x8
  unsigned int v6; // w19

  if ( !a1 )
    return 4294967274LL;
  v1 = *a1;
  if ( !*a1 )
    return 4294967274LL;
  v2 = a1[2];
  if ( !v2 || !a1[1] || !a1[3] )
    return 4294967274LL;
  if ( *(_BYTE *)(v1 + 1004) != 1 || *(_BYTE *)(v2 + 1004) != 1 )
    return 4294967274LL;
  result = sysfs_add_link_to_group(v1 + 56, coresight_conns_group, v2 + 56);
  if ( !(_DWORD)result )
  {
    result = sysfs_add_link_to_group(a1[2] + 56, coresight_conns_group, *a1 + 56);
    v5 = *a1;
    if ( (_DWORD)result )
    {
      v6 = result;
      sysfs_remove_link_from_group(v5 + 56, coresight_conns_group, a1[1]);
      return v6;
    }
    else
    {
      ++*(_DWORD *)(v5 + 1000);
      ++*(_DWORD *)(a1[2] + 1000);
    }
  }
  return result;
}
