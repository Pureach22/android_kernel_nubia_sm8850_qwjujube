bool __fastcall wlan_serialization_is_scan_pending_queue_empty(__int64 a1)
{
  __int64 pdev_from_cmd; // x0
  __int64 pdev_obj; // x0

  pdev_from_cmd = wlan_serialization_get_pdev_from_cmd(a1);
  pdev_obj = wlan_serialization_get_pdev_obj(pdev_from_cmd);
  return qdf_list_empty((_QWORD *)(pdev_obj + 24));
}
