__int64 __fastcall mlme_free_aid(
        __int64 result,
        __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v12; // x9
  __int64 v13; // x20
  unsigned __int8 link_vdev_ix; // w0
  __int64 v15; // x20
  int v16; // w21
  __int64 v17; // x21

  v10 = *(_QWORD *)(result + 1360);
  if ( v10 )
  {
    v12 = *(_QWORD *)(v10 + 2232);
    if ( v12 )
    {
      v13 = *(_QWORD *)(v12 + 8);
      if ( v13 )
      {
        link_vdev_ix = mlo_get_link_vdev_ix(*(_QWORD *)(result + 1360), result);
        return wlan_mlo_peer_free_aid(v13, link_vdev_ix, a2);
      }
    }
  }
  else
  {
    result = wlan_vdev_mlme_get_cmpt_obj(result, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( result )
    {
      v15 = *(_QWORD *)(result + 248);
      if ( v15 )
      {
        v16 = *(_DWORD *)(v15 + 260);
        result = wlan_objmgr_get_mlo_ctx();
        if ( result )
        {
          if ( v16 >= 2 )
          {
            v17 = result;
            qdf_mutex_acquire(result + 64);
            *(_QWORD *)(v15 + 8LL * (((a2 & 0x3FFFu) - 1) >> 6)) &= ~(1LL << ((unsigned __int8)a2 - 1));
            return qdf_mutex_release(v17 + 64);
          }
          else
          {
            *(_QWORD *)(v15 + 8LL * (((a2 & 0x3FFFu) - 1) >> 6)) &= ~(1LL << ((unsigned __int8)a2 - 1));
          }
        }
      }
    }
  }
  return result;
}
