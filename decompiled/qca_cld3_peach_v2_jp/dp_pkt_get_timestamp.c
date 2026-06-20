__int64 __fastcall dp_pkt_get_timestamp(_QWORD *a1)
{
  __int64 result; // x0

  result = qdf_is_dp_pkt_timestamp_enabled();
  if ( (result & 1) != 0 )
  {
    __isb(0xFu);
    *a1 = _ReadStatusReg(CNTVCT_EL0);
  }
  return result;
}
