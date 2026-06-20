__int64 __fastcall wlan_objmgr_pdev_iterate_obj_list(
        __int64 a1,
        int a2,
        void (__fastcall *a3)(__int64, __int64, __int64),
        __int64 a4,
        __int64 a5,
        unsigned int a6)
{
  __int64 v10; // x0
  __int64 v11; // x23
  __int64 v12; // x24
  __int64 active; // x0
  __int64 v14; // x23
  __int64 next_active_vdev_of_pdev; // x24
  __int64 v16; // x0
  __int64 v17; // x24
  __int64 next_active_peer_of_vdev; // x25

  if ( a2 == 3 )
  {
    active = wlan_pdev_vdev_list_peek_active_head(a1, a1 + 48, a6);
    if ( active )
    {
      v14 = active;
      do
      {
        v16 = wlan_vdev_peer_list_peek_active_head(v14, v14 + 192, a6);
        if ( v16 )
        {
          v17 = v16;
          do
          {
            if ( *((_DWORD *)a3 - 1) != -1599250034 )
              __break(0x8235u);
            a3(a1, v17, a4);
            next_active_peer_of_vdev = wlan_peer_get_next_active_peer_of_vdev(v14, v14 + 192, v17, a6);
            wlan_objmgr_peer_release_ref(v17, a6);
            v17 = next_active_peer_of_vdev;
          }
          while ( next_active_peer_of_vdev );
        }
        next_active_vdev_of_pdev = wlan_vdev_get_next_active_vdev_of_pdev(a1, a1 + 48, v14, a6);
        wlan_objmgr_vdev_release_ref(v14, a6);
        v14 = next_active_vdev_of_pdev;
      }
      while ( next_active_vdev_of_pdev );
    }
  }
  else if ( a2 == 2 )
  {
    v10 = wlan_pdev_vdev_list_peek_active_head(a1, a1 + 48, a6);
    if ( v10 )
    {
      v11 = v10;
      do
      {
        if ( *((_DWORD *)a3 - 1) != -1599250034 )
          __break(0x8235u);
        a3(a1, v11, a4);
        v12 = wlan_vdev_get_next_active_vdev_of_pdev(a1, a1 + 48, v11, a6);
        wlan_objmgr_vdev_release_ref(v11, a6);
        v11 = v12;
      }
      while ( v12 );
    }
  }
  return 0;
}
