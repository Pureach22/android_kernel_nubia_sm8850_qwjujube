_QWORD *__fastcall coresight_remove_sysfs_link(_QWORD *result)
{
  __int64 v1; // x2
  _QWORD *v2; // x20

  if ( result )
  {
    if ( *result )
    {
      if ( result[2] )
      {
        v1 = result[1];
        if ( v1 )
        {
          if ( result[3] )
          {
            v2 = result;
            sysfs_remove_link_from_group(*result + 56LL, coresight_conns_group, v1);
            result = (_QWORD *)sysfs_remove_link_from_group(v2[2] + 56LL, coresight_conns_group, v2[3]);
            --*(_DWORD *)(*v2 + 1000LL);
            --*(_DWORD *)(v2[2] + 1000LL);
          }
        }
      }
    }
  }
  return result;
}
