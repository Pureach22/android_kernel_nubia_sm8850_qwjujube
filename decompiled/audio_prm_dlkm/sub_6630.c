__int64 sub_6630()
{
  __int64 v0; // x10

  if ( (v0 & 0x80000000000000LL) != 0 )
    JUMPOUT(0x4EBC);
  return audio_prm_set_lpass_clk_cfg();
}
