__int64 sub_5D93A4()
{
  __int64 v0; // x27

  if ( (v0 & 0x8000000000LL) != 0 )
    JUMPOUT(0x5DE334);
  return wdi_event_handler();
}
