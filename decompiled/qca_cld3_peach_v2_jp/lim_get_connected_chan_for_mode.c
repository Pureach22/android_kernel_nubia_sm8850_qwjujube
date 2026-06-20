unsigned __int16 *__fastcall lim_get_connected_chan_for_mode(__int64 a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v8; // w23
  unsigned int v9; // w25
  unsigned int v10; // w8
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int *is_vdev_connected; // x8
  __int64 v21; // x24
  unsigned __int16 *v22; // x24

  v8 = 0;
  v9 = a2 & 0xFFFFFFFD;
  do
  {
    v11 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v8, 7);
    if ( v11 )
    {
      is_vdev_connected = (unsigned int *)*(unsigned int *)(v11 + 16);
      if ( (_DWORD)is_vdev_connected == a2 )
      {
        if ( v9
          || (v21 = v11,
              is_vdev_connected = (unsigned int *)wlan_cm_is_vdev_connected(v11, v12, v13, v14, v15, v16, v17, v18, v19),
              v11 = v21,
              ((unsigned __int8)is_vdev_connected & 1) != 0) )
        {
          v22 = *(unsigned __int16 **)(v11 + 40);
          if ( v22 )
          {
            is_vdev_connected = (unsigned int *)*v22;
            if ( (unsigned int)is_vdev_connected >= a3 && (unsigned int)is_vdev_connected <= a4 )
            {
              wlan_objmgr_vdev_release_ref(v11, 7u, is_vdev_connected, v12, v13, v14, v15, v16, v17, v18, v19);
              return v22;
            }
          }
        }
      }
      wlan_objmgr_vdev_release_ref(v11, 7u, is_vdev_connected, v12, v13, v14, v15, v16, v17, v18, v19);
    }
    v10 = (unsigned __int8)v8++;
  }
  while ( v10 < 5 );
  return nullptr;
}
