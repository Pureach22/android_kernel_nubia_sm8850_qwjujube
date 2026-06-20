__int64 sub_128CC()
{
  int v0; // w16

  if ( (v0 & 0x80000) != 0 )
    JUMPOUT(0xC5D8);
  return wcd9378_mbhc_debounce_time_set();
}
