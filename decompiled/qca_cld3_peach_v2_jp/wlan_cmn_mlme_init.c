__int64 wlan_cmn_mlme_init()
{
  __int64 result; // x0
  __int64 (*v1)(void); // x8
  __int64 (*v2)(void); // x8
  __int64 (*v3)(void); // x8
  __int64 (*v4)(void); // x8

  result = wlan_psoc_mlme_init();
  if ( !(_DWORD)result )
  {
    result = wlan_pdev_mlme_init();
    if ( !(_DWORD)result )
    {
      result = wlan_vdev_mlme_init();
      if ( !(_DWORD)result )
      {
        v1 = (__int64 (*)(void))glbl_ops_cb;
        if ( glbl_ops_cb )
        {
          if ( *((_DWORD *)glbl_ops_cb - 1) != 1349256614 )
            __break(0x8228u);
          glbl_ops = v1();
        }
        v2 = (__int64 (*)(void))glbl_cm_ops_cb;
        if ( glbl_cm_ops_cb )
        {
          if ( *((_DWORD *)glbl_cm_ops_cb - 1) != 615260499 )
            __break(0x8228u);
          glbl_cm_ops = v2();
        }
        v3 = (__int64 (*)(void))glbl_vdev_mgr_ops_cb;
        if ( glbl_vdev_mgr_ops_cb )
        {
          if ( *((_DWORD *)glbl_vdev_mgr_ops_cb - 1) != 1041005046 )
            __break(0x8228u);
          glbl_vdev_mgr_ops = v3();
        }
        v4 = (__int64 (*)(void))glbl_twt_ops_cb;
        if ( glbl_twt_ops_cb )
        {
          if ( *((_DWORD *)glbl_twt_ops_cb - 1) != 1643633986 )
            __break(0x8228u);
          glbl_twt_ops = v4();
          return 0;
        }
        else
        {
          return 0;
        }
      }
    }
  }
  return result;
}
