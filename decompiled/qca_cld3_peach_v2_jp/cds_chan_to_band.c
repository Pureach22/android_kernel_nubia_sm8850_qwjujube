__int64 __fastcall cds_chan_to_band(unsigned int a1)
{
  if ( a1 < 0xF )
    return 1;
  else
    return 2;
}
