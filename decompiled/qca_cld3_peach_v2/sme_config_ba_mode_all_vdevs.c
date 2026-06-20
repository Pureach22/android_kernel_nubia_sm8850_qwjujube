__int64 __fastcall sme_config_ba_mode_all_vdevs(__int64 a1, unsigned __int8 a2)
{
  unsigned int i; // w21
  __int64 result; // x0
  __int64 v6; // x25
  unsigned int v7; // w26
  unsigned int *v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  for ( i = 0; i != 6; ++i )
  {
    result = (__int64)wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(a1 + 21632), i, 0xBu);
    if ( result )
    {
      v6 = result;
      v7 = wma_cli_set_command(i, 126, a2, 1);
      wlan_objmgr_vdev_release_ref(v6, 0xBu, v8, v9, v10, v11, v12, v13, v14, v15, v16);
      if ( v7 )
        result = qdf_trace_msg(
                   0x34u,
                   2u,
                   "%s: BA mode set failed for vdev: %d, ret %d",
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   "sme_config_ba_mode_all_vdevs",
                   i,
                   v7);
      else
        result = qdf_trace_msg(
                   0x34u,
                   8u,
                   "%s: vdev: %d ba mode: %d param id %d",
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   v23,
                   v24,
                   "sme_config_ba_mode_all_vdevs",
                   i,
                   a2,
                   126);
    }
  }
  return result;
}
