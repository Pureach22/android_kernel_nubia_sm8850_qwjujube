__int64 sub_6C1C4()
{
  __int64 v0; // x24

  if ( (v0 & 0x4000000000LL) == 0 )
    JUMPOUT(0x68980);
  return msm_v4l2_decoder_cmd();
}
