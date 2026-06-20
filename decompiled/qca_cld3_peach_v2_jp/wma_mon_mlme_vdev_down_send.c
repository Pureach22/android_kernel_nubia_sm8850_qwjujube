__int64 __fastcall wma_mon_mlme_vdev_down_send(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w20
  __int64 v20; // x21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 cmpt_obj; // x0
  unsigned int v30; // w21
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  const char *v39; // x2

  context = _cds_get_context(54, (__int64)"wma_mon_mlme_vdev_down_send", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL);
    v20 = *(_QWORD *)(context[65] + 488LL * *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL));
    if ( (wma_is_vdev_valid(v19, v11, v12, v13, v14, v15, v16, v17, v18) & 1) != 0 )
    {
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v20, v21, v22, v23, v24, v25, v26, v27, v28);
      if ( cmpt_obj )
      {
        v30 = vdev_mgr_down_send(cmpt_obj, v21, v22, v23, v24, v25, v26, v27, v28);
        if ( !v30 )
          goto LABEL_11;
        goto LABEL_10;
      }
      v39 = "%s: Failed to get vdev mlme obj for vdev id %d";
    }
    else
    {
      v39 = "%s: Invalid vdev id:%d";
    }
    qdf_trace_msg(0x36u, 2u, v39, v21, v22, v23, v24, v25, v26, v27, v28, "wma_send_vdev_down_to_fw", v19);
    v30 = 16;
LABEL_10:
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to send vdev down cmd: vdev %d",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "wma_mon_mlme_vdev_down_send",
      v19);
LABEL_11:
    wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(a1 + 504), 0x1Bu, 0, 0, v31, v32, v33, v34, v35, v36, v37, v38);
    return v30;
  }
  return 4;
}
