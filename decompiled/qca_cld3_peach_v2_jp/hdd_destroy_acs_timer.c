__int64 __fastcall hdd_destroy_acs_timer(__int64 a1)
{
  __int64 v1; // x19
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x0
  unsigned __int64 v18; // x10

  v1 = *(_QWORD *)(a1 + 52824);
  if ( *(_BYTE *)(v1 + 2336) == 1 )
  {
    *(_BYTE *)(v1 + 2336) = 0;
    _X8 = (unsigned __int64 *)(*(_QWORD *)(a1 + 52824) + 4416LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v18 = __ldxr(_X8);
    while ( __stxr(v18 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
    if ( *(_DWORD *)(v1 + 2316) == 21 && (unsigned int)qdf_mc_timer_stop(v1 + 2168) )
      qdf_trace_msg(0x33u, 2u, "%s: Failed to stop ACS timer", v2, v3, v4, v5, v6, v7, v8, v9, "hdd_destroy_acs_timer");
    v10 = *(_QWORD *)(v1 + 2240);
    if ( v10 )
      _qdf_mem_free(v10);
    qdf_mc_timer_destroy(v1 + 2168);
  }
  return 0;
}
