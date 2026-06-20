_QWORD *__fastcall wlan_hdd_ml_sap_get_peer(_QWORD *result, _BYTE *a2)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x19
  unsigned __int8 v5; // w22
  _QWORD *v6; // x24
  __int64 mlpeer; // x0
  __int64 v9; // x21
  __int64 v10; // x8
  _QWORD *peer; // x20

  if ( result )
  {
    v2 = result[27];
    if ( v2 )
    {
      v3 = *(_QWORD *)(v2 + 80);
      if ( v3 )
      {
        v4 = result[170];
        v5 = *(_BYTE *)(v2 + 40);
        v6 = result;
        qdf_mutex_acquire(v4 + 1656);
        qdf_mutex_acquire(v4 + 1584);
        mlpeer = mlo_get_mlpeer(v4, a2);
        if ( mlpeer )
        {
          v9 = mlpeer;
          qdf_mutex_acquire(mlpeer + 120);
          v10 = *(_QWORD *)(v9 + 16);
          if ( v10 && *(_QWORD **)(v10 + 96) == v6 || (v10 = *(_QWORD *)(v9 + 56)) != 0 && *(_QWORD **)(v10 + 96) == v6 )
            peer = wlan_objmgr_get_peer(v3, v5, (_BYTE *)(v10 + 48), 6u);
          else
            peer = nullptr;
          qdf_mutex_release(v9 + 120);
        }
        else
        {
          peer = wlan_objmgr_get_peer(v3, v5, a2, 6u);
        }
        qdf_mutex_release(v4 + 1584);
        qdf_mutex_release(v4 + 1656);
        return peer;
      }
      else
      {
        return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}
