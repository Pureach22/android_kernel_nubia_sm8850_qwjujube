void __fastcall lim_cleanup_mlm(__int64 a1)
{
  __int64 v2; // x20
  unsigned __int64 v3; // x21
  __int64 v4; // x20
  unsigned __int64 v5; // x21

  if ( *(_DWORD *)(a1 + 3984) == 1 )
  {
    lim_deactivate_timers(a1);
    tx_timer_delete(a1 + 1344);
    tx_timer_delete(a1 + 1072);
    tx_timer_delete(a1 + 2136);
    tx_timer_delete(a1 + 2928);
    tx_timer_delete(a1 + 280);
    tx_timer_delete(a1 + 808);
    v2 = 0;
    v3 = -1;
    do
    {
      tx_timer_delete(*(_QWORD *)(a1 + 1336) + v2);
      ++v3;
      v2 += 264;
    }
    while ( v3 < *(unsigned __int16 *)(a1 + 3990) );
    if ( *(_DWORD *)(a1 + 11408) )
    {
      v4 = *(_QWORD *)(a1 + 11416);
      v5 = 0;
      do
        tx_timer_delete(*(_QWORD *)(v4 + 8 * v5++) + 280LL);
      while ( v5 < *(unsigned int *)(a1 + 11408) );
    }
    tx_timer_delete(a1 + 1608);
    tx_timer_delete(a1 + 16);
    tx_timer_delete(a1 + 2400);
    tx_timer_delete(a1 + 2664);
    tx_timer_delete(a1 + 3192);
    tx_timer_delete(a1 + 3456);
    tx_timer_delete(a1 + 3720);
    *(_DWORD *)(a1 + 3984) = 0;
  }
}
