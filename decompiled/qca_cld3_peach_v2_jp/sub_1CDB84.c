__int64 sub_1CDB84()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x1D2714);
  return wlan_cm_disconnect_rsp();
}
