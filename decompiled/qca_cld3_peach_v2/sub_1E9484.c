__int64 sub_1E9484()
{
  __int64 v0; // x18

  if ( (v0 & 0x100000000LL) == 0 )
    JUMPOUT(0x1E2D00);
  return ucfg_cm_get_connected_band();
}
