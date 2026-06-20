__int64 __fastcall ucfg_cfr_get_capture_status(__int64 a1, _DWORD *a2)
{
  *a2 = 0;
  return wlan_objmgr_pdev_iterate_obj_list(
           a1,
           3,
           (void (__fastcall *)(__int64, __int64, __int64))cfr_iter_peer_handler,
           (__int64)a2,
           1,
           0x30u);
}
