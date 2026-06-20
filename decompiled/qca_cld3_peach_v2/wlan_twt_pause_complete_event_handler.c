__int64 __fastcall wlan_twt_pause_complete_event_handler(__int64 a1, unsigned int *a2)
{
  int v2; // w22
  int pdev_id_from_vdev_id; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 pdev_by_id; // x0
  __int64 v15; // x19
  unsigned int opmode_from_vdev_id; // w0
  unsigned int *v17; // x8
  unsigned int v18; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2
  const char *v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  v2 = *a2;
  pdev_id_from_vdev_id = wlan_get_pdev_id_from_vdev_id(a1, *a2, 0x5Eu);
  if ( pdev_id_from_vdev_id == -1 )
  {
    v27 = "%s: Invalid pdev id";
LABEL_8:
    qdf_trace_msg(0x96u, 2u, v27, v6, v7, v8, v9, v10, v11, v12, v13, "wlan_twt_pause_complete_event_handler");
    return 4;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, pdev_id_from_vdev_id, 0x5Eu);
  if ( !pdev_by_id )
  {
    v27 = "%s: Invalid pdev";
    goto LABEL_8;
  }
  v15 = pdev_by_id;
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(pdev_by_id, v2);
  if ( opmode_from_vdev_id )
  {
    if ( opmode_from_vdev_id == 1 )
    {
      v18 = mlme_twt_osif_pause_complete_ind();
    }
    else
    {
      v29 = qdf_opmode_str(opmode_from_vdev_id);
      qdf_trace_msg(
        0x96u,
        8u,
        "%s: TWT Pause is not supported on %s",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wlan_twt_pause_complete_event_handler",
        v29);
      v18 = 16;
    }
  }
  else
  {
    mlme_twt_osif_pause_complete_ind();
    wlan_twt_set_session_state(a1, a2 + 1, a2[3], 2);
    v18 = ((__int64 (__fastcall *)(__int64, unsigned int *, _QWORD, _QWORD))wlan_twt_set_command_in_progress)(
            a1,
            a2 + 1,
            a2[3],
            0);
  }
  wlan_objmgr_pdev_release_ref(v15, 0x5Eu, v17, v19, v20, v21, v22, v23, v24, v25, v26);
  return v18;
}
