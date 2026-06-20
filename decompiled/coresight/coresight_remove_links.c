__int64 __fastcall coresight_remove_links(__int64 result, __int64 a2)
{
  _QWORD *v2; // x20
  __int64 v3; // x19
  __int64 v4; // x2
  __int64 v5; // x21
  __int64 v6; // x8
  __int64 v7; // x20

  if ( result )
  {
    v2 = *(_QWORD **)(a2 + 24);
    if ( v2 )
    {
      v3 = result;
      if ( *v2 )
      {
        if ( v2[2] )
        {
          v4 = v2[1];
          if ( v4 )
          {
            if ( v2[3] )
            {
              v5 = a2;
              sysfs_remove_link_from_group(*v2 + 56LL, coresight_conns_group, v4);
              sysfs_remove_link_from_group(v2[2] + 56LL, coresight_conns_group, v2[3]);
              a2 = v5;
              --*(_DWORD *)(*v2 + 1000LL);
              --*(_DWORD *)(v2[2] + 1000LL);
              v2 = *(_QWORD **)(v5 + 24);
            }
          }
        }
      }
      v6 = v2[3];
      v7 = a2;
      devm_kfree(*(_QWORD *)(a2 + 16) + 56LL, v6);
      devm_kfree(v3 + 56, *(_QWORD *)(*(_QWORD *)(v7 + 24) + 8LL));
      result = devm_kfree(v3 + 56, *(_QWORD *)(v7 + 24));
      *(_QWORD *)(v7 + 24) = 0;
    }
  }
  return result;
}
