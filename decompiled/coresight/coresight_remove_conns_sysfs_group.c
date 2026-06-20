__int64 __fastcall coresight_remove_conns_sysfs_group(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    if ( *(_BYTE *)(result + 1004) == 1 )
    {
      v1 = result;
      result = sysfs_remove_group(result + 56, &coresight_conns_group);
      *(_BYTE *)(v1 + 1004) = 0;
    }
  }
  return result;
}
