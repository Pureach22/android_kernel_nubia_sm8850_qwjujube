__int64 sub_1CE270()
{
  __int64 v0; // x18

  if ( (v0 & 0x100000000LL) == 0 )
    JUMPOUT(0x1C7AEC);
  return ucfg_cm_get_connected_band();
}
