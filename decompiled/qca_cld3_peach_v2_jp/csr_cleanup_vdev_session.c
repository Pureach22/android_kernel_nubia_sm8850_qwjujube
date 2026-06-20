__int64 __fastcall csr_cleanup_vdev_session(__int64 result, unsigned __int8 a2)
{
  __int64 v2; // x8
  unsigned int v3; // w20
  __int64 v4; // x21
  __int64 v5; // x22
  _QWORD *vdev_by_id_from_pdev; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 rso_config_fl; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x23
  __int64 v27; // x19

  if ( result )
  {
    if ( a2 <= 5u )
    {
      v2 = *(_QWORD *)(result + 17224);
      if ( v2 )
      {
        v3 = a2;
        v4 = v2 + 96LL * a2;
        if ( *(_BYTE *)(v4 + 1) == 1 )
        {
          v5 = result;
          vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(result + 21560), a2, 0xBu);
          if ( vdev_by_id_from_pdev )
          {
            v15 = (__int64)vdev_by_id_from_pdev;
            rso_config_fl = wlan_cm_get_rso_config_fl(
                              (__int64)vdev_by_id_from_pdev,
                              (__int64)"csr_flush_roam_scan_chan_lists",
                              0x605u,
                              v7,
                              v8,
                              v9,
                              v10,
                              v11,
                              v12,
                              v13,
                              v14);
            if ( rso_config_fl )
            {
              v26 = rso_config_fl;
              cm_flush_roam_channel_list(rso_config_fl + 168);
              cm_flush_roam_channel_list(v26 + 112);
            }
            wlan_objmgr_vdev_release_ref(v15, 0xBu, v17, v18, v19, v20, v21, v22, v23, v24, v25);
          }
          result = *(_QWORD *)(v4 + 32);
          if ( result )
          {
            result = _qdf_mem_free(result);
            *(_QWORD *)(v4 + 32) = 0;
          }
          *(_DWORD *)(v4 + 24) = 0;
          *(_QWORD *)(v4 + 8) = 0;
          *(_QWORD *)(v4 + 16) = 0;
          v27 = *(_QWORD *)(v5 + 17224) + 96LL * v3;
          if ( v27 )
          {
            result = *(_QWORD *)(v27 + 32);
            *(_DWORD *)(v27 + 4) = 0;
            *(_WORD *)v27 = 255;
            if ( result )
            {
              result = _qdf_mem_free(result);
              *(_QWORD *)(v27 + 32) = 0;
            }
            *(_DWORD *)(v27 + 24) = 0;
            *(_QWORD *)(v27 + 8) = 0;
            *(_QWORD *)(v27 + 16) = 0;
          }
        }
      }
    }
  }
  return result;
}
