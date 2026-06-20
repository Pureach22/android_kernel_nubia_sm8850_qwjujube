__int64 sub_7414()
{
  __int64 v0; // x22

  if ( (v0 & 0x80000000000LL) != 0 )
    JUMPOUT(0x2FAC);
  return determine_memmap_size();
}
