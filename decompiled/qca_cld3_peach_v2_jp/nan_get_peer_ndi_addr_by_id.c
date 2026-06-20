__int64 __fastcall nan_get_peer_ndi_addr_by_id(__int64 a1, int a2, void *a3)
{
  _QWORD *v6; // x0
  __int64 v7; // x22
  __int64 next_active_peer_of_vdev; // x23
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _DWORD *comp_private_obj; // x0
  int v18; // w8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  v6 = wlan_vdev_peer_list_peek_active_head(a1, (_QWORD *)(a1 + 128), 0x14u);
  if ( !v6 )
    return 16;
  v7 = (__int64)v6;
  while ( 1 )
  {
    comp_private_obj = (_DWORD *)wlan_objmgr_peer_get_comp_private_obj(v7, 0xFu);
    if ( comp_private_obj )
    {
      v18 = comp_private_obj[4];
      if ( v18 )
      {
        if ( comp_private_obj[5] == a2 )
          goto LABEL_24;
        if ( v18 != 1 )
        {
          if ( comp_private_obj[6] == a2 )
            goto LABEL_24;
          if ( v18 != 2 )
          {
            if ( comp_private_obj[7] == a2 )
              goto LABEL_24;
            if ( v18 != 3 )
            {
              if ( comp_private_obj[8] == a2 )
                goto LABEL_24;
              if ( v18 != 4 )
              {
                if ( comp_private_obj[9] == a2 )
                  goto LABEL_24;
                if ( v18 != 5 )
                {
                  if ( comp_private_obj[10] == a2 )
                    goto LABEL_24;
                  if ( v18 != 6 )
                  {
                    if ( comp_private_obj[11] == a2 )
                      goto LABEL_24;
                    if ( v18 != 7 )
                      break;
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_3:
    next_active_peer_of_vdev = wlan_peer_get_next_active_peer_of_vdev(a1, (_QWORD *)(a1 + 128), v7, 0x14u);
    wlan_objmgr_peer_release_ref(v7, 0x14u, v9, v10, v11, v12, v13, v14, v15, v16);
    v7 = next_active_peer_of_vdev;
    if ( !next_active_peer_of_vdev )
      return 16;
  }
  if ( comp_private_obj[12] != a2 )
  {
    if ( v18 != 8 )
    {
      __break(0x5512u);
      return 16;
    }
    goto LABEL_3;
  }
LABEL_24:
  qdf_mem_copy(a3, (const void *)(v7 + 48), 6u);
  wlan_objmgr_peer_release_ref(v7, 0x14u, v20, v21, v22, v23, v24, v25, v26, v27);
  return 0;
}
