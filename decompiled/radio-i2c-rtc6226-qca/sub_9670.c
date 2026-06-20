__int64 sub_9670()
{
  int v0; // w13

  if ( (v0 & 0x1000000) != 0 )
    JUMPOUT(0xB3EC);
  return rtc6226_is_valid_srch_mode();
}
