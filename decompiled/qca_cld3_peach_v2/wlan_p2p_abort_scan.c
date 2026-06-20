__int64 __fastcall wlan_p2p_abort_scan(__int64 a1)
{
  return wlan_objmgr_pdev_iterate_obj_list(
           a1,
           2,
           (void (__fastcall *)(__int64, __int64, __int64))wlan_p2p_abort_vdev_scan,
           0,
           0,
           0xFu);
}
