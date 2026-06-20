bool __fastcall sap_is_csa_vdev_restart_state(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  int is_csa_restart; // w20
  int is_restart_progress; // w21
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  if ( !a1 || !a2 )
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid params", a3, a4, a5, a6, a7, a8, a9, a10, "sap_is_csa_vdev_restart_state");
    return 0;
  }
  v11 = ((__int64 (*)(void))wlan_objmgr_get_vdev_by_id_from_psoc)();
  if ( !v11 )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: vdev is NULL for vdev_id: %u",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "sap_is_csa_vdev_restart_state",
      *(unsigned __int8 *)(a2 + 12));
    return 0;
  }
  v20 = v11;
  is_csa_restart = wlan_vdev_mlme_is_csa_restart(v11);
  is_restart_progress = wlan_vdev_is_restart_progress(v20);
  wlan_objmgr_vdev_release_ref(v20, 0xEu, v23, v24, v25, v26, v27, v28, v29, v30, v31);
  return !is_csa_restart || is_restart_progress == 0;
}
