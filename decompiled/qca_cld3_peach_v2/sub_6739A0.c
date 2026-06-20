__int64 sub_6739A0()
{
  __int64 v0; // x30

  if ( (v0 & 0x2000000000000LL) != 0 )
    JUMPOUT(0x673FD4);
  return send_peer_cfr_capture_cmd_tlv();
}
