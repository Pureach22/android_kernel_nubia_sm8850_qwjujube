__int64 __fastcall coresight_release_platform_data(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  __int64 v7; // x23
  __int64 v8; // x8
  unsigned __int64 v9; // x0
  __int64 v10; // x9
  void (*v11)(void); // x9
  __int64 result; // x0

  v3 = *(_QWORD *)(a3 + 8);
  if ( *(int *)(a3 + 4) >= 1 )
  {
    v7 = 0;
    do
    {
      if ( a1 && *(_QWORD *)(*(_QWORD *)(v3 + 8 * v7) + 16LL) )
        coresight_remove_links(a1);
      v8 = *(_QWORD *)(v3 + 8 * v7);
      v9 = *(_QWORD *)(v8 + 8);
      if ( v9 )
      {
        if ( v9 <= 0xFFFFFFFFFFFFF000LL )
        {
          v10 = *(_QWORD *)(v9 + 8);
          if ( v10 )
          {
            v11 = *(void (**)(void))(v10 + 8);
            if ( v11 )
            {
              if ( *((_DWORD *)v11 - 1) != -643302289 )
                __break(0x8229u);
              v11();
              v8 = *(_QWORD *)(v3 + 8 * v7);
            }
          }
        }
      }
      *(_QWORD *)(v8 + 8) = 0;
      devm_kfree(a2, *(_QWORD *)(v3 + 8 * v7++));
    }
    while ( v7 < *(int *)(a3 + 4) );
    v3 = *(_QWORD *)(a3 + 8);
  }
  devm_kfree(a2, v3);
  devm_kfree(a2, *(_QWORD *)(a3 + 16));
  result = devm_kfree(a2, a3);
  if ( a1 )
    return coresight_remove_conns_sysfs_group(a1);
  return result;
}
