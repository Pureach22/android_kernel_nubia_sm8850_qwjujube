__int64 socinfo_get_id_string()
{
  int v0; // w8
  __int64 v1; // x9

  v0 = socinfo;
  if ( socinfo )
    v0 = *(_DWORD *)(socinfo + 4);
  v1 = -4432;
  while ( *(_DWORD *)((char *)&soc_id + v1 + 4432) != v0 )
  {
    v1 += 16;
    if ( !v1 )
      return 0;
  }
  return *(__int64 *)((char *)&soc_id + v1 + 4440);
}
