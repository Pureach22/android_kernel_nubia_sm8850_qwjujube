__int64 sub_16F3E0()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x173F70);
  return osif_disconnect_handler();
}
