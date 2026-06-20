__int64 qdf_dp_trace_deinit()
{
  __int64 result; // x0

  if ( byte_7F7658 == 1 )
  {
    raw_spin_lock_bh(&l_dp_trace_lock);
    byte_7F7658 = 0;
    byte_7F7650 = 0;
    return raw_spin_unlock_bh(&l_dp_trace_lock);
  }
  return result;
}
