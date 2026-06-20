__int64 __fastcall wlan_serialization_is_cmd_present_in_active_queue(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int *a10)
{
  unsigned int *v10; // x19
  __int64 pdev_from_cmd; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 pdev_obj; // x0
  __int64 pdev_queue_obj; // x0
  __int64 v22; // x20
  const char *v23; // x2

  v10 = a10;
  if ( !a10 )
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid cmd",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wlan_serialization_is_cmd_present_in_active_queue");
    return (unsigned __int8)v10 & 1;
  }
  pdev_from_cmd = wlan_serialization_get_pdev_from_cmd(a10);
  if ( !pdev_from_cmd )
  {
    v23 = "%s: invalid pdev";
LABEL_10:
    qdf_trace_msg(
      0x4Cu,
      2u,
      v23,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_serialization_is_cmd_present_in_active_queue");
    LOBYTE(v10) = 0;
    return (unsigned __int8)v10 & 1;
  }
  pdev_obj = wlan_serialization_get_pdev_obj(pdev_from_cmd);
  if ( !pdev_obj )
  {
    v23 = "%s: invalid ser pdev obj";
    goto LABEL_10;
  }
  pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(pdev_obj, *v10);
  if ( !pdev_queue_obj )
  {
    v23 = "%s: pdev_queue is invalid";
    goto LABEL_10;
  }
  v22 = pdev_queue_obj;
  wlan_serialization_acquire_lock(pdev_queue_obj + 88);
  LOBYTE(v10) = wlan_serialization_is_cmd_present_queue(v10, 1);
  wlan_serialization_release_lock(v22 + 88);
  return (unsigned __int8)v10 & 1;
}
