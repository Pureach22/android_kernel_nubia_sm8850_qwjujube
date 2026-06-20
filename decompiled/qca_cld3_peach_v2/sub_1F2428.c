__int64 sub_1F2428()
{
  int v0; // w10

  if ( (v0 & 0x40000) != 0 )
    JUMPOUT(0x1F3D84);
  return wlan_vdev_mlme_set_ext_hdl();
}
