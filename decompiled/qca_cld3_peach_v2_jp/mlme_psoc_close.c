__int64 __fastcall mlme_psoc_close(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: PSOC MLME component object is NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_psoc_mlme_get_cmpt_obj");
    if ( (qdf_is_recovering() & 1) == 0 )
      return 0;
    goto LABEL_3;
  }
  qdf_mutex_destroy(comp_private_obj + 688);
  if ( (qdf_is_recovering() & 1) != 0 )
LABEL_3:
    tgt_vdev_mgr_reset_response_timer_info(a1);
  return 0;
}
