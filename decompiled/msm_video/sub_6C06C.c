__int64 sub_6C06C()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000LL) == 0 )
    JUMPOUT(0x68828);
  return msm_v4l2_try_decoder_cmd();
}
