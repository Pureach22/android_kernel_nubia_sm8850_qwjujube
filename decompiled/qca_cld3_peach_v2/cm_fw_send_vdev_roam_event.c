__int64 __fastcall cm_fw_send_vdev_roam_event(
        __int64 *a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int *first_roam_command; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x9

  first_roam_command = (unsigned int *)cm_get_first_roam_command(*a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( first_roam_command )
  {
    v23 = *(_QWORD *)(*a1 + 216);
    if ( v23 && *(_QWORD *)(v23 + 80) )
      return wlan_vdev_mlme_sm_deliver_evt(*a1, 0x1Cu, a2, a3, v15, v16, v17, v18, v19, v20, v21, v22);
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: Failed to find psoc",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "cm_fw_send_vdev_roam_event",
      *((unsigned __int8 *)first_roam_command + 9),
      *first_roam_command);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to find roam req from list",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "cm_fw_send_vdev_roam_event");
  }
  return 16;
}
