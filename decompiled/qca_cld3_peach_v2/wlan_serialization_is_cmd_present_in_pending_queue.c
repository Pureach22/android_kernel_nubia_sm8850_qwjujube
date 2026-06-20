__int64 __fastcall wlan_serialization_is_cmd_present_in_pending_queue(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 pdev_obj; // x0
  __int64 pdev_queue_obj; // x0
  __int64 v21; // x20
  const char *v22; // x2

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
      "wlan_serialization_is_cmd_present_in_pending_queue");
    return (unsigned __int8)v10 & 1;
  }
  if ( !wlan_serialization_get_pdev_from_cmd(a10) )
  {
    v22 = "%s: invalid pdev";
LABEL_10:
    qdf_trace_msg(
      0x4Cu,
      2u,
      v22,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_serialization_is_cmd_present_in_pending_queue");
    LOBYTE(v10) = 0;
    return (unsigned __int8)v10 & 1;
  }
  pdev_obj = wlan_serialization_get_pdev_obj();
  if ( !pdev_obj )
  {
    v22 = "%s: invalid ser pdev obj";
    goto LABEL_10;
  }
  pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(pdev_obj, *v10);
  if ( !pdev_queue_obj )
  {
    v22 = "%s: pdev_queue is invalid";
    goto LABEL_10;
  }
  v21 = pdev_queue_obj;
  wlan_serialization_acquire_lock(pdev_queue_obj + 88);
  LOBYTE(v10) = wlan_serialization_is_cmd_present_queue(v10, 0);
  wlan_serialization_release_lock(v21 + 88);
  return (unsigned __int8)v10 & 1;
}
