__int64 __fastcall qdf_dp_trace_apply_tput_policy(__int64 result)
{
  if ( (byte_7F7665 & 1) == 0 )
  {
    if ( (result & 1) == 0 )
    {
      byte_7F7656 = byte_7F7657;
      if ( !byte_7F7658 || !byte_7F7659 )
        return result;
      goto LABEL_12;
    }
    byte_7F7656 = 1;
    if ( !byte_7F7658 || !byte_7F7659 )
      return result;
LABEL_9:
    byte_7F765A = 0;
    qdf_dp_trace_throttle_live_mode_bw_interval_counter = 0;
    return result;
  }
  if ( !byte_7F7658 || !byte_7F7659 )
    return result;
  if ( (result & 1) != 0 )
    goto LABEL_9;
LABEL_12:
  if ( !(++qdf_dp_trace_throttle_live_mode_bw_interval_counter % (unsigned __int16)word_7F7668) )
  {
    raw_spin_lock_bh(&l_dp_trace_lock);
    if ( (unsigned __int8)byte_7F7666 <= (unsigned int)(unsigned __int8)byte_7F7667 )
      byte_7F765A = 1;
    byte_7F7666 = 0;
    return raw_spin_unlock_bh(&l_dp_trace_lock);
  }
  return result;
}
