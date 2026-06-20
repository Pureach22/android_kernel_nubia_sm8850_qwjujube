__int64 sub_700B14()
{
  __int64 v0; // x29

  if ( (v0 & 0x20000000000LL) == 0 )
    JUMPOUT(0x7033B4);
  return wlan_twt_requestor_disable();
}
