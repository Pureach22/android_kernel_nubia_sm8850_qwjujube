__int64 sub_247A74()
{
  int v0; // w19

  if ( (v0 & 0x8000000) != 0 )
    JUMPOUT(0x24D898);
  return send_twt_vdev_config_cmd_tlv();
}
