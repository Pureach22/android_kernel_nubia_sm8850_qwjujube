__int64 __fastcall wlan_objmgr_iterate_obj_list_all(
        __int64 a1,
        int a2,
        _DWORD *a3,
        __int64 a4,
        __int64 a5,
        unsigned int a6)
{
  __int64 pdev_by_id_no_state; // x0
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
  __int64 vdev_by_id_from_psoc_no_state; // x0
  __int64 v24; // x24
  unsigned __int8 v25; // w23
  unsigned int v26; // w8
  __int64 v27; // x0
  _QWORD *v28; // x24
  __int64 next_peer_of_psoc_ref; // x25
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
        v27 = wlan_psoc_peer_list_peek_head_ref(a1 + 128, v25);
        if ( v27 )
        {
          v28 = (_QWORD *)v27;
          do
          {
            if ( *(a3 - 1) != -204971199 )
              __break(0x8234u);
            ((void (__fastcall *)(__int64, _QWORD *, __int64))a3)(a1, v28, a4);
            next_peer_of_psoc_ref = wlan_peer_get_next_peer_of_psoc_ref(a1 + 128, v25, v28);
            wlan_objmgr_peer_release_ref((__int64)v28, a6, v30, v31, v32, v33, v34, v35, v36, v37);
            v28 = (_QWORD *)next_peer_of_psoc_ref;
          }
          while ( next_peer_of_psoc_ref );
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
          vdev_by_id_from_psoc_no_state = wlan_objmgr_get_vdev_by_id_from_psoc_no_state(a1, v22, a6);
          if ( vdev_by_id_from_psoc_no_state )
          {
            v24 = vdev_by_id_from_psoc_no_state;
            if ( *(a3 - 1) != -204971199 )
              __break(0x8234u);
            ((void (__fastcall *)(__int64, __int64, __int64))a3)(a1, vdev_by_id_from_psoc_no_state, a4);
            wlan_objmgr_vdev_release_ref(v24, a6);
          }
          ++v22;
        }
        while ( v21 > (unsigned __int16)v22 );
      }
      break;
    case 1:
      pdev_by_id_no_state = wlan_objmgr_get_pdev_by_id_no_state(a1, 0, a6);
      if ( pdev_by_id_no_state )
      {
        v11 = pdev_by_id_no_state;
        if ( *(a3 - 1) != -204971199 )
          __break(0x8234u);
        v12 = ((double (__fastcall *)(__int64, __int64, __int64))a3)(a1, pdev_by_id_no_state, a4);
        wlan_objmgr_pdev_release_ref(v11, a6, v13, v12, v14, v15, v16, v17, v18, v19, v20);
      }
      break;
  }
  return 0;
}
