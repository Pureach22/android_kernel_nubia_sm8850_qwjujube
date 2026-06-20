__int64 sub_214CA8()
{
  int v0; // w19

  if ( (v0 & 0x8000000) != 0 )
    JUMPOUT(0x21AACC);
  return wmi_unified_twt_vdev_config_send();
}
