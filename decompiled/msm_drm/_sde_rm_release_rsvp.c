__int64 __fastcall sde_rm_release_rsvp(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  _QWORD *v4; // x8
  _QWORD *v5; // x9
  _QWORD *v6; // x10
  __int64 i; // x25
  __int64 *v8; // x27
  __int64 j; // x23
  char v10; // w8
  char v11; // w8

  if ( a2 )
  {
    v3 = result;
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "rel rsvp %d enc %d\n", *(_DWORD *)(a2 + 16), *(_DWORD *)(a2 + 20));
    v4 = *(_QWORD **)(v3 + 8);
    while ( v4 != (_QWORD *)(v3 + 8) )
    {
      v5 = v4;
      v4 = (_QWORD *)*v4;
      if ( v5 == (_QWORD *)a2 )
      {
        v6 = (_QWORD *)v5[1];
        if ( *v6 == a2 && v4[1] == a2 )
        {
          v4[1] = v6;
          *v6 = v4;
        }
        else
        {
          _list_del_entry_valid_or_report(v5);
        }
        *v5 = 0xDEAD000000000100LL;
        v5[1] = 0xDEAD000000000122LL;
        break;
      }
    }
    for ( i = 0; i != 15; ++i )
    {
      v8 = (__int64 *)(v3 + 24 + 16 * i);
      for ( j = *v8; (__int64 *)j != v8; j = *(_QWORD *)j )
      {
        if ( *(_QWORD *)(j + 16) == a2 )
        {
          v10 = _drm_debug;
          *(_QWORD *)(j + 16) = 0;
          if ( (v10 & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "rel rsvp %d enc %d %d %d\n",
              *(_DWORD *)(a2 + 16),
              *(_DWORD *)(a2 + 20),
              *(_DWORD *)(j + 32),
              *(_DWORD *)(j + 36));
          sde_rm_inc_resource_info(v3, v3 + 336, j);
        }
        if ( *(_QWORD *)(j + 24) == a2 )
        {
          v11 = _drm_debug;
          *(_QWORD *)(j + 24) = 0;
          if ( (v11 & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "rel rsvp_nxt %d enc %d %d %d\n",
              *(_DWORD *)(a2 + 16),
              *(_DWORD *)(a2 + 20),
              *(_DWORD *)(j + 32),
              *(_DWORD *)(j + 36));
        }
      }
    }
    return kfree(a2);
  }
  return result;
}
