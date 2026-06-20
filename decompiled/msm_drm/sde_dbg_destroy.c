__int64 sde_dbg_destroy()
{
  __int64 *v0; // x19
  __int64 *v1; // x22
  __int64 **v2; // x0
  __int64 **v3; // x9
  __int64 **v4; // x8
  __int64 *v5; // x24
  __int64 **v6; // x8
  __int64 *v7; // x9
  _QWORD *v8; // x9
  _QWORD *v9; // x8
  _QWORD *v10; // x21

  vfree(qword_2945B0);
  qword_2945C8 = 0;
  qword_2945C0 = 0;
  qword_2945B8 = 0;
  qword_2945B0 = 0;
  sde_dbg_base_evtlog = 0;
  sde_evtlog_destroy(sde_dbg_base);
  sde_dbg_base = 0;
  sde_dbg_base_reglog = 0;
  sde_reglog_destroy(qword_2942A0);
  qword_2942A0 = 0;
  v0 = (__int64 *)qword_2942A8;
  if ( (__int64 *)qword_2942A8 != &qword_2942A8 )
  {
    do
    {
      v1 = (__int64 *)*v0;
      v2 = (__int64 **)v0[2];
      if ( v2 != (__int64 **)(v0 + 2) )
      {
        do
        {
          v5 = *v2;
          v4 = (__int64 **)v2[1];
          if ( *v4 == (__int64 *)v2 && (__int64 **)v5[1] == v2 )
          {
            v5[1] = (__int64)v4;
            *v4 = v5;
          }
          else
          {
            _list_del_entry_valid_or_report(v2);
            v2 = v3;
          }
          *v2 = (__int64 *)0xDEAD000000000100LL;
          v2[1] = (__int64 *)0xDEAD000000000122LL;
          kfree(v2);
          v2 = (__int64 **)v5;
        }
        while ( v5 != v0 + 2 );
      }
      v6 = (__int64 **)v0[1];
      if ( *v6 == v0 && (v7 = (__int64 *)*v0, *(__int64 **)(*v0 + 8) == v0) )
      {
        v7[1] = (__int64)v6;
        *v6 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v0);
      }
      *v0 = 0xDEAD000000000100LL;
      v0[1] = 0xDEAD000000000122LL;
      kfree(v0);
      v0 = v1;
    }
    while ( v1 != &qword_2942A8 );
  }
  vfree(qword_2942B8);
  mutex_lock(&sde_dbg_dsi_mutex);
  v8 = sde_dbg_dsi_list;
  if ( sde_dbg_dsi_list != (_UNKNOWN *)&sde_dbg_dsi_list )
  {
    do
    {
      v10 = (_QWORD *)*v8;
      v9 = (_QWORD *)v8[1];
      if ( (_QWORD *)*v9 == v8 && (_QWORD *)v10[1] == v8 )
      {
        v10[1] = v9;
        *v9 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v8);
      }
      *v8 = 0xDEAD000000000100LL;
      v8[1] = 0xDEAD000000000122LL;
      kfree(v8 - 2);
      v8 = v10;
    }
    while ( v10 != &sde_dbg_dsi_list );
  }
  mutex_unlock(&sde_dbg_dsi_mutex);
  vfree(qword_294398);
  vfree(qword_2943F0);
  vfree(qword_294448);
  vfree(qword_2944F8);
  vfree(qword_2944A0);
  return vfree(qword_294550);
}
