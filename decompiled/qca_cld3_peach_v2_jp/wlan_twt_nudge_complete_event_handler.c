__int64 __fastcall wlan_twt_nudge_complete_event_handler(__int64 a1, unsigned int *a2)
{
  unsigned int v4; // w23
  unsigned int v5; // w22
  int pdev_id_from_vdev_id; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 pdev_by_id; // x0
  __int64 v16; // x19
  unsigned int opmode_from_vdev_id; // w0
  unsigned int *v18; // x8
  unsigned int v19; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x4
  const char *v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v49; // [xsp+8h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a2;
  v5 = a2[4];
  v48 = 0;
  pdev_id_from_vdev_id = wlan_get_pdev_id_from_vdev_id(a1, v4, 0x5Eu);
  if ( pdev_id_from_vdev_id == -1 )
  {
    v28 = "%s: Invalid pdev id";
LABEL_8:
    qdf_trace_msg(0x96u, 2u, v28, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_twt_nudge_complete_event_handler");
    result = 4;
    goto LABEL_15;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, pdev_id_from_vdev_id, 0x5Eu);
  if ( !pdev_by_id )
  {
    v28 = "%s: Invalid pdev";
    goto LABEL_8;
  }
  v16 = pdev_by_id;
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(pdev_by_id, v4);
  if ( opmode_from_vdev_id )
  {
    if ( opmode_from_vdev_id == 1 )
    {
      v19 = mlme_twt_osif_nudge_complete_ind();
    }
    else
    {
      v39 = qdf_opmode_str(opmode_from_vdev_id);
      qdf_trace_msg(
        0x96u,
        8u,
        "%s: TWT nudge is not supported on %s",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "wlan_twt_nudge_complete_event_handler",
        v39);
      v19 = 16;
    }
  }
  else if ( (((__int64 (__fastcall *)(__int64, unsigned int *, _QWORD, __int64, unsigned int *))wlan_twt_is_command_in_progress)(
               a1,
               a2 + 1,
               a2[3],
               16,
               &v48)
           & 1) != 0
         || (v38 = a2[3], (_DWORD)v38 == 255) )
  {
    mlme_twt_osif_nudge_complete_ind();
    v19 = ((__int64 (__fastcall *)(__int64, unsigned int *, _QWORD, _QWORD))wlan_twt_set_command_in_progress)(
            a1,
            a2 + 1,
            a2[3],
            0);
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      8u,
      "%s: Drop TWT nudge dialog event for dialog_id:%d status:%d active_cmd:%d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_twt_nudge_complete_event_handler",
      v38,
      v5,
      v48);
    v19 = 4;
  }
  wlan_objmgr_pdev_release_ref(v16, 0x5Eu, v18, v20, v21, v22, v23, v24, v25, v26, v27);
  result = v19;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
