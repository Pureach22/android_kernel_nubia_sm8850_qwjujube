__int64 sub_64A28C()
{
  __int64 v0; // x29

  if ( (v0 & 0x20000000000LL) == 0 )
    JUMPOUT(0x64CB2C);
  return wlan_twt_requestor_disable();
}
