bool __fastcall tx_timer_running(__int64 a1)
{
  return *(_QWORD *)(a1 + 56) == 3735928559LL && (unsigned int)qdf_mc_timer_get_current_state(a1 + 88) == 21;
}
