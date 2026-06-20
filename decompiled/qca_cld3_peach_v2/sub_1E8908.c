__int64 sub_1E8908()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x1ED498);
  return wlan_cm_disconnect_rsp();
}
