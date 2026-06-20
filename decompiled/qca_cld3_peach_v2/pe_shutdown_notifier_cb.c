__int64 __fastcall pe_shutdown_notifier_cb(__int64 a1)
{
  __int64 result; // x0
  unsigned __int8 v3; // w20
  __int64 v4; // x25

  result = lim_deactivate_timers();
  if ( *(_WORD *)(a1 + 3992) )
  {
    v3 = 0;
    do
    {
      v4 = *(_QWORD *)(a1 + 12264) + 14000LL * v3;
      if ( *(_BYTE *)(v4 + 70) == 1 )
      {
        if ( *(_DWORD *)(v4 + 88) == 1 )
          result = qdf_mc_timer_stop(v4 + 8064);
        if ( !*(_DWORD *)(v4 + 7036) )
        {
          result = qdf_mc_timer_stop(v4 + 7872);
          *(_BYTE *)(v4 + 8049) = 0;
        }
      }
      ++v3;
    }
    while ( *(unsigned __int16 *)(a1 + 3992) > (unsigned int)v3 );
  }
  return result;
}
