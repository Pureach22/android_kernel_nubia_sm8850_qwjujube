__int64 __fastcall wlan_objmgr_iterate_obj_list(
        __int64 a1,
        int a2,
        _DWORD *a3,
        __int64 a4,
        __int64 a5,
        unsigned int a6)
{
  __int64 pdev_by_id; // x0
  __int64 v11; // x23
  double v12; // d0
  unsigned int *v13; // x8
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w25
  unsigned int v22; // w23
  __int64 v23; // x0
  __int64 v24; // x24
  unsigned __int8 v25; // w23
  unsigned int v26; // w8
  _QWORD *v27; // x0
  _QWORD *v28; // x24
  _QWORD *next_active_peer_of_psoc; // x25
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  switch ( a2 )
  {
    case 3:
      v25 = 0;
      do
      {
        v27 = wlan_psoc_peer_list_peek_active_head(a1 + 128, v25, a6);
        if ( v27 )
        {
          v28 = v27;
          do
          {
            if ( *(a3 - 1) != -204971199 )
              __break(0x8234u);
            ((void (__fastcall *)(__int64, _QWORD *, __int64))a3)(a1, v28, a4);
            next_active_peer_of_psoc = wlan_peer_get_next_active_peer_of_psoc(a1 + 128, v25, v28, a6);
            wlan_objmgr_peer_release_ref((__int64)v28, a6, v30, v31, v32, v33, v34, v35, v36, v37);
            v28 = next_active_peer_of_psoc;
          }
          while ( next_active_peer_of_psoc );
        }
        v26 = v25++;
      }
      while ( v26 < 0x3F );
      break;
    case 2:
      v21 = *(unsigned __int16 *)(a1 + 54);
      if ( *(_WORD *)(a1 + 54) )
      {
        v22 = 0;
        do
        {
          v23 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v22, a6);
          if ( v23 )
          {
            v24 = v23;
            if ( *(a3 - 1) != -204971199 )
              __break(0x8234u);
            ((void (__fastcall *)(__int64, __int64, __int64))a3)(a1, v23, a4);
            wlan_objmgr_vdev_release_ref(v24, a6);
          }
          ++v22;
        }
        while ( v21 > (unsigned __int16)v22 );
      }
      break;
    case 1:
      pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, a6);
      if ( pdev_by_id )
      {
        v11 = pdev_by_id;
        if ( *(a3 - 1) != -204971199 )
          __break(0x8234u);
        v12 = ((double (__fastcall *)(__int64, __int64, __int64))a3)(a1, pdev_by_id, a4);
        wlan_objmgr_pdev_release_ref(v11, a6, v13, v12, v14, v15, v16, v17, v18, v19, v20);
      }
      break;
  }
  return 0;
}
