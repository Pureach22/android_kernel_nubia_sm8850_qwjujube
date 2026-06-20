__int64 sub_2343DC()
{
  int v0; // w19

  if ( (v0 & 0x8000000) != 0 )
    JUMPOUT(0x23A200);
  return wmi_unified_twt_vdev_config_send();
}
