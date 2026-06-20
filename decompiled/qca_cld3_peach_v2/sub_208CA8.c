__int64 sub_208CA8()
{
  __int64 v0; // x22

  if ( (v0 & 0x8000000000000LL) == 0 )
    JUMPOUT(0x20AF74);
  return reg_get_min_max_bw_on_cur_chan_list();
}
