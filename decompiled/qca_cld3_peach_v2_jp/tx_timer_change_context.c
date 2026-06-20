__int64 __fastcall tx_timer_change_context(__int64 a1, int a2)
{
  if ( *(_QWORD *)(a1 + 56) != 3735928559LL )
    return 21;
  if ( (unsigned int)qdf_mc_timer_get_current_state(a1 + 88) != 19 )
    return 21;
  *(_DWORD *)(a1 + 52) = a2;
  return 0;
}
