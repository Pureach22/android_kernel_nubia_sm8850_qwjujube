__int64 __fastcall sde_wb_remove(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x20
  double v3; // d0
  _UNKNOWN **v4; // x9
  _QWORD *v5; // x8
  _QWORD *v6; // x0
  __int64 v7; // x9

  v1 = *(_QWORD **)(result + 168);
  if ( v1 )
  {
    v2 = result;
    if ( (_drm_debug & 4) != 0 )
    {
      v3 = _drm_dev_dbg(0, 0, 0, "\n");
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "\n", v3);
    }
    mutex_lock(&sde_wb_list_lock);
    v4 = &sde_wb_list;
    while ( 1 )
    {
      v4 = (_UNKNOWN **)*v4;
      if ( v4 == &sde_wb_list )
        break;
      if ( v4 - 4 == v1 )
      {
        v5 = (_QWORD *)v1[5];
        v6 = v1 + 4;
        if ( (_QWORD *)*v5 == v1 + 4 && (v7 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
        {
          *(_QWORD *)(v7 + 8) = v5;
          *v5 = v7;
        }
        else
        {
          _list_del_entry_valid_or_report(v6);
        }
        v1[4] = 0xDEAD000000000100LL;
        v1[5] = 0xDEAD000000000122LL;
        break;
      }
    }
    mutex_unlock(&sde_wb_list_lock);
    kfree(v1[16]);
    *(_QWORD *)(v2 + 168) = 0;
    return devm_kfree(v2 + 16);
  }
  return result;
}
