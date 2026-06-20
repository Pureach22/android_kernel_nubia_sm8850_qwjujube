__int64 __fastcall rpmh_rsc_get_device(char *s1, unsigned int a2)
{
  const char *v4; // x22
  __int64 v6; // x8
  __int64 i; // x11
  __int64 v8; // x12

  v4 = (const char *)&rpmh_rsc_dev_list;
  do
  {
    v4 = *(const char **)v4;
    if ( v4 == (const char *)&rpmh_rsc_dev_list )
      return -19;
  }
  while ( strcmp(s1, v4 - 40) );
  if ( (unsigned __int64)(v4 - 40) > 0xFFFFFFFFFFFFF000LL )
    return -19;
  if ( strcmp(s1, "cam_rsc") )
    return -19;
  v6 = *((unsigned int *)v4 - 5);
  if ( (int)v6 < 1 )
    return -19;
  for ( i = a2; ; --i )
  {
    if ( !i )
    {
      v8 = *((_QWORD *)v4 - 2) + 1688LL * a2;
      if ( *(_BYTE *)(v8 + 61) == 1 )
        break;
    }
    if ( !--v6 )
      return -19;
  }
  return *(_QWORD *)(v8 + 1648);
}
