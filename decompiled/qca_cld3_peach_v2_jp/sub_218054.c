__int64 sub_218054()
{
  char v0; // w25

  if ( (v0 & 0x10) == 0 )
    JUMPOUT(0x216868);
  return wmi_extract_vdev_extd_stats();
}
