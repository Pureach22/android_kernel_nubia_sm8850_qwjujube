__int64 sub_228240()
{
  int v0; // w19

  if ( (v0 & 0x8000000) != 0 )
    JUMPOUT(0x22E064);
  return send_twt_vdev_config_cmd_tlv();
}
