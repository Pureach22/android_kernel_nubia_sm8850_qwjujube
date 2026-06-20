__int64 sub_A3E0()
{
  int v0; // w13

  if ( (v0 & 0x1000000) != 0 )
    JUMPOUT(0xC15C);
  return drm_dp_link_rate_to_bw_code();
}
