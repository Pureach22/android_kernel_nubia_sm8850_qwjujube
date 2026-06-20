__int64 qdf_dp_trace_deinit()
{
  __int64 result; // x0

  if ( byte_73EC28 == 1 )
  {
    raw_spin_lock_bh(&l_dp_trace_lock);
    byte_73EC28 = 0;
    byte_73EC20 = 0;
    return raw_spin_unlock_bh(&l_dp_trace_lock);
  }
  return result;
}
