__int64 __fastcall wlan_objmgr_free_all_objects_per_psoc(__int64 a1)
{
  unsigned __int8 v2; // w20
  unsigned int v3; // w8
  _QWORD *v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _QWORD *v13; // x21
  _QWORD *next_active_peer_of_psoc; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w22
  unsigned int v24; // w20
  __int64 v25; // x0
  __int64 v26; // x21
  __int64 pdev_by_id; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x19
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7

  v2 = 0;
  do
  {
    v4 = wlan_psoc_peer_list_peek_active_head(a1 + 128, v2, 0);
    if ( v4 )
    {
      v13 = v4;
      do
      {
        wlan_objmgr_peer_obj_delete((__int64)v13, v5, v6, v7, v8, v9, v10, v11, v12);
        next_active_peer_of_psoc = wlan_peer_get_next_active_peer_of_psoc(a1 + 128, v2, v13, 0);
        wlan_objmgr_peer_release_ref((__int64)v13, 0, v15, v16, v17, v18, v19, v20, v21, v22);
        v13 = next_active_peer_of_psoc;
      }
      while ( next_active_peer_of_psoc );
    }
    v3 = v2++;
  }
  while ( v3 < 0x3F );
  v23 = *(unsigned __int16 *)(a1 + 54);
  if ( *(_WORD *)(a1 + 54) )
  {
    v24 = 0;
    do
    {
      v25 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v24, 0);
      if ( v25 )
      {
        v26 = v25;
        wlan_objmgr_vdev_obj_delete();
        wlan_objmgr_vdev_release_ref(v26, 0);
      }
      ++v24;
    }
    while ( v23 > (unsigned __int16)v24 );
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 0);
  if ( pdev_by_id )
  {
    v36 = pdev_by_id;
    wlan_objmgr_pdev_obj_delete(pdev_by_id, v28, v29, v30, v31, v32, v33, v34, v35);
    wlan_objmgr_pdev_release_ref(v36, 0, v37, v38, v39, v40, v41, v42, v43, v44, v45);
  }
  return 0;
}
