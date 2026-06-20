__int64 __fastcall pre_cac_get_vdev_id(__int64 a1, __int64 a2)
{
  return wlan_objmgr_iterate_obj_list(a1, 2, pre_cac_get_vdev_id_handler, a2, 1, 0x60u);
}
