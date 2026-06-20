__int64 __fastcall cm_neighbor_roam_update_config(__int64 a1, unsigned int a2, unsigned __int8 a3, unsigned int a4)
{
  __int64 v4; // x22
  _QWORD *vdev_by_id_from_pdev; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x23
  _BYTE *rso_config_fl; // x0
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w24
  const char *v29; // x25
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7

  v4 = *(_QWORD *)(a1 + 80);
  if ( v4 )
  {
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du);
    if ( vdev_by_id_from_pdev )
    {
      v17 = (__int64)vdev_by_id_from_pdev;
      rso_config_fl = (_BYTE *)wlan_cm_get_rso_config_fl(vdev_by_id_from_pdev, "cm_neighbor_roam_update_config", 5738);
      if ( rso_config_fl )
      {
        if ( (unsigned __int8)a4 <= 0x12u )
        {
          if ( (unsigned __int8)a4 == 3 )
          {
            v28 = (unsigned __int8)rso_config_fl[128];
            rso_config_fl[128] = a3;
            v29 = "REASON_LOOKUP_THRESH_CHANGED";
            rso_config_fl[129] = a3;
            goto LABEL_16;
          }
          if ( (unsigned __int8)a4 == 18 )
          {
            v28 = (unsigned __int8)rso_config_fl[148];
            rso_config_fl[148] = a3;
            v29 = "REASON_OPPORTUNISTIC_THRESH_DIFF_CHANGED";
            goto LABEL_16;
          }
        }
        else
        {
          switch ( (unsigned __int8)a4 )
          {
            case 0x13u:
              v28 = (unsigned __int8)rso_config_fl[149];
              rso_config_fl[149] = a3;
              v29 = "REASON_ROAM_RESCAN_RSSI_DIFF_CHANGED";
              rso_config_fl[93] = a3;
              goto LABEL_16;
            case 0x14u:
              v28 = (unsigned __int8)rso_config_fl[150];
              rso_config_fl[150] = a3;
              v29 = "REASON_ROAM_BMISS_FIRST_BCNT_CHANGED";
              goto LABEL_16;
            case 0x15u:
              v28 = (unsigned __int8)rso_config_fl[151];
              v29 = "REASON_ROAM_BMISS_FINAL_BCNT_CHANGED";
              rso_config_fl[151] = a3;
LABEL_16:
              wlan_objmgr_vdev_release_ref(
                v17,
                0x4Du,
                (unsigned int *)(unsigned __int8)a4,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27);
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: CONNECTED, send update cfg cmd",
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                "cm_neighbor_roam_update_config");
              wlan_roam_update_cfg(v4, a2, a4);
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: LFR config for %s changed from %d to %d",
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                "cm_neighbor_roam_update_config",
                v29,
                v28,
                a3);
              return 0;
          }
        }
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: Unknown update cfg reason",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "cm_neighbor_roam_update_config");
      }
      wlan_objmgr_vdev_release_ref(v17, 0x4Du, v19, v20, v21, v22, v23, v24, v25, v26, v27);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev object is NULL for vdev %d",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "cm_neighbor_roam_update_config",
        (unsigned __int8)a2);
    }
  }
  return 16;
}
