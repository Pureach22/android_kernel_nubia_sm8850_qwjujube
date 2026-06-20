__int64 __fastcall p2p_is_p2p_go_noa_in_progress(__int64 a1, unsigned __int8 a2)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int *v21; // x8
  unsigned int v22; // w9
  unsigned int v23; // w20

  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0xFu);
  if ( !vdev_by_id_from_pdev )
  {
    qdf_trace_msg(0x4Eu, 8u, "%s: Invalid vdev", v3, v4, v5, v6, v7, v8, v9, v10, "p2p_is_p2p_go_noa_in_progress");
    return 0;
  }
  v11 = (__int64)vdev_by_id_from_pdev;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj((__int64)vdev_by_id_from_pdev, 5u);
  if ( !comp_private_obj || (v21 = *(unsigned int **)(comp_private_obj + 8)) == nullptr )
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: null noa info",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "p2p_is_p2p_go_noa_in_progress");
    goto LABEL_8;
  }
  v22 = v21[4];
  if ( !v22 )
  {
LABEL_8:
    v23 = 0;
    goto LABEL_9;
  }
  if ( v21[5] != 1 )
  {
    if ( v22 != 1 )
    {
      if ( v21[9] == 1 )
        goto LABEL_6;
      if ( v22 != 2 )
      {
        if ( v21[13] == 1 )
          goto LABEL_6;
        if ( v22 != 3 )
        {
          v21 = (unsigned int *)v21[17];
          if ( (_DWORD)v21 == 1 )
            goto LABEL_6;
          if ( v22 != 4 )
          {
            __break(0x5512u);
            JUMPOUT(0x53B5168);
          }
        }
      }
    }
    goto LABEL_8;
  }
LABEL_6:
  v23 = 1;
LABEL_9:
  wlan_objmgr_vdev_release_ref(v11, 0xFu, v21, v13, v14, v15, v16, v17, v18, v19, v20);
  return v23;
}
