__int64 __fastcall coresight_find_activated_sysfs_sink(__int64 result)
{
  __int64 v1; // x19
  __int64 i; // x20
  __int64 v3; // x0

  if ( (*(_DWORD *)(result + 8) | 2) != 2 || (*(_BYTE *)(result + 981) & 1) == 0 )
  {
    v1 = *(unsigned int *)(*(_QWORD *)result + 4LL);
    if ( (int)v1 < 1 )
    {
      return 0;
    }
    else
    {
      for ( i = *(_QWORD *)(*(_QWORD *)result + 8LL); ; i += 8 )
      {
        v3 = *(_QWORD *)(*(_QWORD *)i + 16LL);
        if ( v3 )
        {
          result = coresight_find_activated_sysfs_sink(v3);
          if ( result )
            break;
        }
        if ( !--v1 )
          return 0;
      }
    }
  }
  return result;
}
