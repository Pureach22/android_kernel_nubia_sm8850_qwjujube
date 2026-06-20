__int64 __fastcall qdf_dp_trace_set_track(__int64 result, int a2)
{
  __int64 v2; // x19
  unsigned int v4; // w8
  __int64 v5; // x8

  if ( byte_73EC28 == 1 )
  {
    v2 = result;
    raw_spin_lock_bh(&l_dp_trace_lock);
    if ( a2 )
    {
      if ( a2 == 1 )
        v4 = ++dword_73EC40;
      else
        v4 = 0;
    }
    else
    {
      v4 = ++dword_73EC3C;
    }
    if ( !byte_73EC20 || v4 % (unsigned __int8)byte_73EC20 )
      return raw_spin_unlock_bh(&l_dp_trace_lock);
    if ( a2 )
    {
      if ( a2 != 1 )
        return raw_spin_unlock_bh(&l_dp_trace_lock);
      v5 = 85;
    }
    else
    {
      v5 = 71;
    }
    *(_BYTE *)(v2 + v5) |= 1u;
    return raw_spin_unlock_bh(&l_dp_trace_lock);
  }
  return result;
}
