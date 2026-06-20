__int64 __fastcall ucfg_is_sta_vdev_for_p2p_device_supported(__int64 a1, __int64 a2)
{
  return p2p_get_sta_vdev_for_p2p_dev_cap(a1, a2) & 1;
}
