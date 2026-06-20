__int64 __fastcall drm_dp_bw_channel_coding_efficiency(char a1)
{
  if ( (a1 & 1) != 0 )
    return 967100;
  else
    return 800000;
}
