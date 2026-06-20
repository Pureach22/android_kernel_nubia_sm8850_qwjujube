__int64 __fastcall ml_nlink_clr_requested_emlsr_mode(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 result; // x0

  v2 = *(_QWORD *)(a2 + 1360);
  if ( v2 )
  {
    if ( *(_QWORD *)(v2 + 2224) )
    {
      qdf_mutex_acquire(v2 + 1656);
      mlo_sta_reset_requested_emlsr_mode(v2);
      return qdf_mutex_release(v2 + 1656);
    }
  }
  return result;
}
