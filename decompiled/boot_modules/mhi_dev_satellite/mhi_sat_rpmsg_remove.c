__int64 __fastcall mhi_sat_rpmsg_remove(__int64 a1)
{
  _QWORD *v1; // x23
  __int64 *i; // x25
  __int64 *j; // x20
  __int64 *v4; // x22
  __int64 *v5; // x20
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x0
  __int64 **v9; // x8
  __int64 *v10; // x9

  v1 = *(_QWORD **)(a1 + 152);
  if ( v1 )
    ipc_log_string(v1[11], "%s[I][%s] Enter\n", (const char *)&unk_8360, "mhi_sat_rpmsg_remove");
  mutex_lock(v1 + 4);
  for ( i = (__int64 *)v1[2]; i != v1 + 2; i = (__int64 *)*i )
  {
    flush_work(i + 25);
    raw_spin_lock_irq(i + 33);
    if ( *((_DWORD *)i + 65) >= 3u )
    {
      *((_DWORD *)i + 65) = 5;
      raw_spin_unlock_irq(i + 33);
    }
    else
    {
      *((_DWORD *)i + 65) = 2;
      raw_spin_unlock_irq(i + 33);
      flush_work(i + 17);
      flush_work(i + 21);
      mutex_lock(i + 8);
      for ( j = (__int64 *)i[4]; j != i + 4; j = (__int64 *)*j )
      {
        if ( *((_BYTE *)j + 32) == 1 )
        {
          mhi_unprepare_from_transfer(j[2]);
          *((_BYTE *)j + 32) = 0;
        }
      }
      v4 = (__int64 *)i[6];
      if ( v4 != i + 6 )
      {
        do
        {
          v5 = (__int64 *)*v4;
          v6 = v4[4];
          v7 = v4[6];
          v8 = *(_QWORD *)(*(_QWORD *)(i[2] + 16) + 136LL);
          if ( *((_BYTE *)v4 + 56) == 1 )
            dma_unmap_resource(v8, v6, v7, 0, 0);
          else
            dma_unmap_page_attrs(v8, v6, v7, 0, 32);
          v9 = (__int64 **)v4[1];
          if ( *v9 == v4 && (v10 = (__int64 *)*v4, *(__int64 **)(*v4 + 8) == v4) )
          {
            v10[1] = (__int64)v9;
            *v9 = v10;
          }
          else
          {
            _list_del_entry_valid_or_report(v4);
          }
          *v4 = 0xDEAD000000000100LL;
          v4[1] = 0xDEAD000000000122LL;
          kfree(v4);
          v4 = v5;
        }
        while ( v5 != i + 6 );
      }
      mutex_unlock(i + 8);
      if ( v1 && i )
        ipc_log_string(
          v1[11],
          "%s[I][%s][%x] Removed RPMSG link\n",
          (const char *)&unk_8360,
          "mhi_sat_rpmsg_remove",
          *((_DWORD *)i + 58));
    }
  }
  v1[1] = 0;
  return mutex_unlock(v1 + 4);
}
