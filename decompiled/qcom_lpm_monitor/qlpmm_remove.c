__int64 qlpmm_remove()
{
  __int64 v0; // x8
  __int64 *v1; // x9
  unsigned __int64 v2; // x10
  __int64 **v3; // x8
  __int64 *v4; // x11

  debugfs_remove(*(_QWORD *)(qlpmm_pd + 8));
  v0 = qlpmm_pd;
  v1 = *(__int64 **)(qlpmm_pd + 400);
  if ( v1 != (__int64 *)(qlpmm_pd + 400) )
  {
    v2 = 0xDEAD000000000100LL;
    do
    {
      v4 = (__int64 *)*v1;
      v3 = (__int64 **)v1[1];
      *((_BYTE *)v1 + 28) = 0;
      if ( *v3 == v1 && (__int64 *)v4[1] == v1 )
      {
        v4[1] = (__int64)v3;
        *v3 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      *v1 = v2;
      v1[1] = v2 + 34;
      v1 = v4;
      v0 = qlpmm_pd;
    }
    while ( v4 != (__int64 *)(qlpmm_pd + 400) );
  }
  return qmi_handle_release(v0 + 48);
}
