__int64 __fastcall wlan_mlo_get_mlpeer_by_peer_mladdr(__int64 a1, _QWORD *a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v6; // x0
  _QWORD *next_mld_ctx; // x22
  __int64 mlpeer; // x0
  __int64 v9; // x21

  result = wlan_objmgr_get_mlo_ctx();
  if ( result )
  {
    v5 = result;
    qdf_mutex_acquire(result);
    v6 = wlan_mlo_list_peek_head((_QWORD *)(v5 + 192));
    if ( v6 )
    {
      next_mld_ctx = (_QWORD *)v6;
      while ( 1 )
      {
        mlpeer = mlo_get_mlpeer((__int64)next_mld_ctx, a1);
        if ( mlpeer )
          break;
        next_mld_ctx = (_QWORD *)wlan_mlo_get_next_mld_ctx((_QWORD *)(v5 + 192), next_mld_ctx);
        if ( !next_mld_ctx )
          goto LABEL_6;
      }
      v9 = mlpeer;
      *a2 = next_mld_ctx;
    }
    else
    {
LABEL_6:
      v9 = 0;
    }
    qdf_mutex_release(v5);
    return v9;
  }
  return result;
}
