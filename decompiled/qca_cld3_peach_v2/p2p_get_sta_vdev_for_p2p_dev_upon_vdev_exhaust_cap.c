__int64 __fastcall p2p_get_sta_vdev_for_p2p_dev_upon_vdev_exhaust_cap(__int64 a1, __int64 a2)
{
  if ( (*(_BYTE *)(a1 + 25) & 0x10) != 0 )
    return cfg_p2p_get_sta_vdev_for_p2p_dev_upon_vdev_exhaust_cap(a1, a2) & 1;
  else
    return 0;
}
