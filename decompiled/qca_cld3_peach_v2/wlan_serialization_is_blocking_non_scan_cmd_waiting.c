__int64 __fastcall wlan_serialization_is_blocking_non_scan_cmd_waiting(__int64 a1)
{
  __int64 pdev_obj; // x0
  __int64 pdev_queue_obj; // x0

  pdev_obj = wlan_serialization_get_pdev_obj(a1);
  pdev_queue_obj = wlan_serialization_get_pdev_queue_obj(pdev_obj, 1);
  return *(_BYTE *)(pdev_queue_obj + 80) & 1 | (unsigned int)(*(_BYTE *)(pdev_queue_obj + 82) != 0);
}
