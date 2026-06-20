__int64 __fastcall qdf_dp_trace_throttle_live_mode(__int64 result)
{
  if ( byte_7F7658 && byte_7F7659 )
  {
    if ( (result & 1) != 0 )
    {
      byte_7F765A = 0;
      qdf_dp_trace_throttle_live_mode_bw_interval_counter = 0;
    }
    else if ( !(++qdf_dp_trace_throttle_live_mode_bw_interval_counter % (unsigned __int16)word_7F7668) )
    {
      raw_spin_lock_bh(&l_dp_trace_lock);
      if ( (unsigned __int8)byte_7F7666 <= (unsigned int)(unsigned __int8)byte_7F7667 )
        byte_7F765A = 1;
      byte_7F7666 = 0;
      return raw_spin_unlock_bh(&l_dp_trace_lock);
    }
  }
  return result;
}
