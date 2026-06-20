__int64 __fastcall hdd_update_acs_timer_reason(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int updated; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int64 v29; // x10

  _X9 = (unsigned __int64 *)(*(_QWORD *)(a1 + 52824) + 4416LL);
  __asm { PRFM            #0x11, [X9] }
  do
    v29 = __ldxr(_X9);
  while ( __stxr(v29 | 8, _X9) );
  v4 = *(_QWORD *)(a1 + 52824);
  if ( (unsigned int)qdf_mc_timer_get_current_state(v4 + 2168) == 21 )
    qdf_mc_timer_stop(v4 + 2168);
  **(_BYTE **)(v4 + 2240) = a2;
  if ( (unsigned int)qdf_mc_timer_start(v4 + 2168, 0x3E8u) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to start external acs timer",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "hdd_update_acs_timer_reason");
    return 4294967268LL;
  }
  else
  {
    updated = hdd_cfg80211_update_acs_config(a1, a2);
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: Updated ACS config to nl with reason %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_update_acs_timer_reason",
      a2);
    return updated;
  }
}
