__int64 sub_64A338()
{
  __int64 v0; // x29

  if ( (v0 & 0x20000000000LL) == 0 )
    JUMPOUT(0x64CBD8);
  return wlan_twt_responder_disable();
}
