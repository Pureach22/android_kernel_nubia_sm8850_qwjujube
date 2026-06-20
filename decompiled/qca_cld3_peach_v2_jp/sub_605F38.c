__int64 sub_605F38()
{
  __int64 v0; // x30

  if ( (v0 & 0x2000000000000LL) != 0 )
    JUMPOUT(0x60656C);
  return send_peer_cfr_capture_cmd_tlv();
}
