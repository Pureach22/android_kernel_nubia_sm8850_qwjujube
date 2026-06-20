__int64 __fastcall tx_timer_delete(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 56) != 3735928559LL )
    return 21;
  qdf_mc_timer_destroy(a1 + 88);
  *(_QWORD *)(a1 + 56) = 0;
  return 0;
}
