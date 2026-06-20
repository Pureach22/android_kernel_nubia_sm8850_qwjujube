__int64 __fastcall sub_6B17DC(__int64 a1, __int64 a2)
{
  __int64 v2; // x20

  return wlan_mlo_vdev_init_mbss_aid_mgr(
           a1,
           a2,
           atomic_load_explicit((atomic_uint *volatile)(v2 + 232), memory_order_acquire));
}
