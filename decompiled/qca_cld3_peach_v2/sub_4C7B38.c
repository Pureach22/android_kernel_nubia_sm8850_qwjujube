__int64 sub_4C7B38()
{
  int v0; // w17

  if ( (v0 & 0x40000) != 0 )
    JUMPOUT(0x4C07C8);
  return wma_get_bcn_rate_code();
}
