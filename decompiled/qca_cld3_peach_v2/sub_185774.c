__int64 sub_185774()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x18A304);
  return osif_cm_disconnect_complete_cb();
}
