__int64 __fastcall coresight_create_conns_sysfs_group(__int64 a1)
{
  __int64 result; // x0

  if ( !a1 )
    return 4294967274LL;
  result = sysfs_create_group(a1 + 56, &coresight_conns_group);
  if ( !(_DWORD)result )
    *(_BYTE *)(a1 + 1004) = 1;
  return result;
}
