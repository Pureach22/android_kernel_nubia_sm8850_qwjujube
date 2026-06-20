__int64 sub_646BAC()
{
  __int64 v0; // x27

  if ( (v0 & 0x8000000000LL) != 0 )
    JUMPOUT(0x64BB3C);
  return wdi_event_handler();
}
