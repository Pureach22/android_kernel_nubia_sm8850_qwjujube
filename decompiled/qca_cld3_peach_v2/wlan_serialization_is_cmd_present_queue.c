__int64 __fastcall wlan_serialization_is_cmd_present_queue(
        unsigned int *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w21
  __int64 pdev_from_cmd; // x0
  __int64 pdev_obj; // x0
  __int64 v15; // x22
  __int64 vdev_from_cmd; // x0
  __int64 vdev_obj; // x0
  __int64 list_from_vdev_queue; // x0
  __int64 v19; // x2
  const char *v20; // x2
  char is_cmd_present_in_given_queue; // w0

  if ( !a1 )
  {
    v20 = "%s: invalid cmd";
LABEL_9:
    qdf_trace_msg(0x4Cu, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_serialization_is_cmd_present_queue");
    is_cmd_present_in_given_queue = 0;
    return is_cmd_present_in_given_queue & 1;
  }
  v10 = *a1;
  pdev_from_cmd = wlan_serialization_get_pdev_from_cmd(a1);
  pdev_obj = wlan_serialization_get_pdev_obj(pdev_from_cmd);
  if ( !pdev_obj )
  {
    v20 = "%s: invalid ser vdev obj";
    goto LABEL_9;
  }
  v15 = pdev_obj;
  vdev_from_cmd = wlan_serialization_get_vdev_from_cmd(a1);
  vdev_obj = wlan_serialization_get_vdev_obj(vdev_from_cmd);
  if ( !vdev_obj )
  {
    v20 = "%s: invalid ser pdev obj";
    goto LABEL_9;
  }
  if ( v10 )
  {
    list_from_vdev_queue = wlan_serialization_get_list_from_vdev_queue(vdev_obj, v10, a2);
    v19 = 1;
  }
  else
  {
    list_from_vdev_queue = wlan_serialization_get_list_from_pdev_queue(v15, 0, a2);
    v19 = 0;
  }
  is_cmd_present_in_given_queue = wlan_serialization_is_cmd_present_in_given_queue(list_from_vdev_queue, a1, v19);
  return is_cmd_present_in_given_queue & 1;
}
