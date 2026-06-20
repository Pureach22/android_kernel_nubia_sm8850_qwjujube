__int64 __fastcall qdf_dp_trace_apply_tput_policy(__int64 result)
{
  if ( (byte_73EC35 & 1) == 0 )
  {
    if ( (result & 1) == 0 )
    {
      byte_73EC26 = byte_73EC27;
      if ( !byte_73EC28 || !byte_73EC29 )
        return result;
      goto LABEL_12;
    }
    byte_73EC26 = 1;
    if ( !byte_73EC28 || !byte_73EC29 )
      return result;
LABEL_9:
    byte_73EC2A = 0;
    qdf_dp_trace_throttle_live_mode_bw_interval_counter = 0;
    return result;
  }
  if ( !byte_73EC28 || !byte_73EC29 )
    return result;
  if ( (result & 1) != 0 )
    goto LABEL_9;
LABEL_12:
  if ( !(++qdf_dp_trace_throttle_live_mode_bw_interval_counter % (unsigned __int16)word_73EC38) )
  {
    raw_spin_lock_bh(&l_dp_trace_lock);
    if ( (unsigned __int8)byte_73EC36 <= (unsigned int)(unsigned __int8)byte_73EC37 )
      byte_73EC2A = 1;
    byte_73EC36 = 0;
    return raw_spin_unlock_bh(&l_dp_trace_lock);
  }
  return result;
}
