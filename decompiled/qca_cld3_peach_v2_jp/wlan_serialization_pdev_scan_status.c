__int64 __fastcall wlan_serialization_pdev_scan_status(__int64 a1)
{
  _QWORD *pdev_obj; // x19
  bool v2; // w20
  bool v3; // w0
  unsigned int is_cmd_in_active_pending; // w20

  pdev_obj = (_QWORD *)wlan_serialization_get_pdev_obj(a1);
  wlan_serialization_acquire_lock(pdev_obj + 11);
  v2 = qdf_list_empty(pdev_obj);
  v3 = qdf_list_empty(pdev_obj + 3);
  is_cmd_in_active_pending = wlan_serialization_is_cmd_in_active_pending(!v2, !v3);
  wlan_serialization_release_lock(pdev_obj + 11);
  return is_cmd_in_active_pending;
}
