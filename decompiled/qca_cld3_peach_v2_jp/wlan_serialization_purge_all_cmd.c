__int64 __fastcall wlan_serialization_purge_all_cmd(__int64 a1)
{
  return wlan_objmgr_iterate_obj_list(a1, 1, wlan_ser_purge_pdev_cmd_cb, 0, 1, 9u);
}
