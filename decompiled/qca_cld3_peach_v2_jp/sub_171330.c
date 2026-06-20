__int64 sub_171330()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x175EC0);
  return osif_cm_disconnect_complete_cb();
}
