__int64 sub_183084()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000000000LL) != 0 )
    JUMPOUT(0x187C14);
  return osif_disconnect_handler();
}
