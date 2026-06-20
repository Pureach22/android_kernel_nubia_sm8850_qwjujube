__int64 sub_1EAEE0()
{
  __int64 v0; // x22

  if ( (v0 & 0x8000000000000LL) == 0 )
    JUMPOUT(0x1ED1AC);
  return reg_get_min_max_bw_on_cur_chan_list();
}
