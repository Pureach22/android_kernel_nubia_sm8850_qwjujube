__int64 __fastcall t2lm_get_tids_mapped_link_id(unsigned int a1)
{
  unsigned int v1; // w8

  if ( (a1 & 4) != 0 )
    v1 = 2;
  else
    v1 = (a1 >> 1) & 1;
  if ( (a1 & 8) != 0 )
    v1 = 3;
  if ( (a1 & 0x10) != 0 )
    v1 = 4;
  if ( (a1 & 0x20) != 0 )
    v1 = 5;
  if ( (a1 & 0x40) != 0 )
    v1 = 6;
  if ( (a1 & 0x80) != 0 )
    return 7;
  else
    return v1;
}
