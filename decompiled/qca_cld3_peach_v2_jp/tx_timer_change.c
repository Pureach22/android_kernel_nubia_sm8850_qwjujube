__int64 __fastcall tx_timer_change(_QWORD *a1, __int64 a2, __int64 a3)
{
  if ( a1[7] != 3735928559LL )
    return 21;
  if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)(a1 + 11)) != 19 )
    return 21;
  a1[9] = 10 * a2;
  a1[10] = 10 * a3;
  return 0;
}
